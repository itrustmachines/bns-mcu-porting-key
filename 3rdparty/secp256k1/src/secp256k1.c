/***********************************************************************
 * Copyright (c) 2013-2015 Pieter Wuille                               *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#include "include/secp256k1.h"
#include "include/secp256k1_preallocated.h"

#include "assumptions.h"
#include "field_impl.h"
#include "scalar_impl.h"
#include "group_impl.h"
#include "ecmult_impl.h"
#include "ecmult_gen_impl.h"
#include "ecdsa_impl.h"
#include "eckey_impl.h"
#include "selftest.h"

#define ARG_CHECK(cond) do { \
    if (EXPECT(!(cond), 0)) { \
        secp256k1_callback_call(&ctx->illegal_callback, #cond); \
        return 0; \
    } \
} while(0)

#define ARG_CHECK_NO_RETURN(cond) do { \
    if (EXPECT(!(cond), 0)) { \
        secp256k1_callback_call(&ctx->illegal_callback, #cond); \
    } \
} while(0)

#ifndef USE_EXTERNAL_DEFAULT_CALLBACKS
#include <stdlib.h>
#include <stdio.h>
static void secp256k1_default_illegal_callback_fn(const char *str, void *data) {
  (void) data;
  fprintf(stderr, "[libsecp256k1] illegal argument: %s\n", str);
  abort();
}
static void secp256k1_default_error_callback_fn(const char *str, void *data) {
  (void) data;
  fprintf(stderr, "[libsecp256k1] internal consistency check failed: %s\n", str);
  abort();
}
#else
void secp256k1_default_illegal_callback_fn(const char* str, void* data);
void secp256k1_default_error_callback_fn(const char* str, void* data);
#endif

static const secp256k1_callback default_illegal_callback = {
    secp256k1_default_illegal_callback_fn,
    NULL
};

static const secp256k1_callback default_error_callback = {
    secp256k1_default_error_callback_fn,
    NULL
};

struct secp256k1_context_struct {
  secp256k1_ecmult_context ecmult_ctx;
  secp256k1_ecmult_gen_context ecmult_gen_ctx;
  secp256k1_callback illegal_callback;
  secp256k1_callback error_callback;
  int declassify;
};

static const secp256k1_context secp256k1_context_no_precomp_ = {
    {0},
    {0},
    {secp256k1_default_illegal_callback_fn, 0},
    {secp256k1_default_error_callback_fn, 0},
    0
};
const secp256k1_context *secp256k1_context_no_precomp = &secp256k1_context_no_precomp_;

size_t secp256k1_context_preallocated_size(unsigned int flags) {
  size_t ret = ROUND_TO_ALIGN(sizeof(secp256k1_context));
  /* A return value of 0 is reserved as an indicator for errors when we call this function internally. */
  VERIFY_CHECK(ret != 0);

  if (EXPECT((flags & SECP256K1_FLAGS_TYPE_MASK) != SECP256K1_FLAGS_TYPE_CONTEXT, 0)) {
    secp256k1_callback_call(&default_illegal_callback,
        "Invalid flags");
    return 0;
  }

  if (flags & SECP256K1_FLAGS_BIT_CONTEXT_SIGN) {
    ret += SECP256K1_ECMULT_GEN_CONTEXT_PREALLOCATED_SIZE;
  }
  if (flags & SECP256K1_FLAGS_BIT_CONTEXT_VERIFY) {
    ret += SECP256K1_ECMULT_CONTEXT_PREALLOCATED_SIZE;
  }
  return ret;
}

secp256k1_context *secp256k1_context_preallocated_create(void *prealloc, unsigned int flags) {
  void *const base = prealloc;
  size_t prealloc_size;
  secp256k1_context *ret;

  if (!secp256k1_selftest()) {
    secp256k1_callback_call(&default_error_callback, "self test failed");
  }

  prealloc_size = secp256k1_context_preallocated_size(flags);
  if (prealloc_size == 0) {
    return NULL;
  }
  VERIFY_CHECK(prealloc != NULL);
  ret = (secp256k1_context *) manual_alloc(&prealloc, sizeof(secp256k1_context), base, prealloc_size);
  ret->illegal_callback = default_illegal_callback;
  ret->error_callback = default_error_callback;

  secp256k1_ecmult_context_init(&ret->ecmult_ctx);
  secp256k1_ecmult_gen_context_init(&ret->ecmult_gen_ctx);

  /* Flags have been checked by secp256k1_context_preallocated_size. */
  VERIFY_CHECK((flags & SECP256K1_FLAGS_TYPE_MASK) == SECP256K1_FLAGS_TYPE_CONTEXT);
  if (flags & SECP256K1_FLAGS_BIT_CONTEXT_SIGN) {
    secp256k1_ecmult_gen_context_build(&ret->ecmult_gen_ctx, &prealloc);
  }
  if (flags & SECP256K1_FLAGS_BIT_CONTEXT_VERIFY) {
    secp256k1_ecmult_context_build(&ret->ecmult_ctx, &prealloc);
  }
  ret->declassify = !!(flags & SECP256K1_FLAGS_BIT_CONTEXT_DECLASSIFY);

  return (secp256k1_context *) ret;
}

secp256k1_context *secp256k1_context_create(unsigned int flags) {
  size_t const prealloc_size = secp256k1_context_preallocated_size(flags);
  secp256k1_context *ctx = (secp256k1_context *) checked_malloc(&default_error_callback, prealloc_size);
  if (EXPECT(secp256k1_context_preallocated_create(ctx, flags) == NULL, 0)) {
    free(ctx);
    return NULL;
  }

  return ctx;
}

void secp256k1_context_preallocated_destroy(secp256k1_context *ctx) {
  ARG_CHECK_NO_RETURN(ctx != secp256k1_context_no_precomp);
  if (ctx != NULL) {
    secp256k1_ecmult_context_clear(&ctx->ecmult_ctx);
    secp256k1_ecmult_gen_context_clear(&ctx->ecmult_gen_ctx);
  }
}

void secp256k1_context_destroy(secp256k1_context *ctx) {
  if (ctx != NULL) {
    secp256k1_context_preallocated_destroy(ctx);
    free(ctx);
  }
}

static int secp256k1_pubkey_load(const secp256k1_context *ctx, secp256k1_ge *ge, const secp256k1_pubkey *pubkey) {
  /* When the secp256k1_ge_storage type is exactly 64 byte, use its
   * representation inside secp256k1_pubkey, as conversion is very fast.
   * Note that secp256k1_pubkey_save must use the same representation. */
  secp256k1_ge_storage s;
  memcpy(&s, &pubkey->data[0], sizeof(s));
  secp256k1_ge_from_storage(ge, &s);
  ARG_CHECK(!secp256k1_fe_is_zero(&ge->x));
  return 1;
}

static void secp256k1_pubkey_save(secp256k1_pubkey *pubkey, secp256k1_ge *ge) {
  secp256k1_ge_storage s;
  secp256k1_ge_to_storage(&s, ge);
  memcpy(&pubkey->data[0], &s, sizeof(s));
}

int secp256k1_ec_pubkey_serialize(
    const secp256k1_context *ctx,
    unsigned char *output,
    size_t *outputlen,
    const secp256k1_pubkey *pubkey,
    unsigned int flags) {
  secp256k1_ge Q;
  size_t len;
  int ret = 0;

  ARG_CHECK(*outputlen >= ((flags & SECP256K1_FLAGS_BIT_COMPRESSION) ? 33u : 65u));
  len = *outputlen;
  *outputlen = 0;
  memset(output, 0, len);
  ARG_CHECK((flags & SECP256K1_FLAGS_TYPE_MASK) == SECP256K1_FLAGS_TYPE_COMPRESSION);
  if (secp256k1_pubkey_load(ctx, &Q, pubkey)) {
    ret = secp256k1_eckey_pubkey_serialize(&Q, output, &len, flags & SECP256K1_FLAGS_BIT_COMPRESSION);
    if (ret) {
      *outputlen = len;
    }
  }
  return ret;
}

static SECP256K1_INLINE void buffer_append(
    unsigned char *buf,
    unsigned int *offset,
    const void *data,
    unsigned int len) {
  memcpy(buf + *offset, data, len);
  *offset += len;
}

static int nonce_function_rfc6979(
    unsigned char *nonce32,
    const unsigned char *msg32,
    const unsigned char *key32,
    const unsigned char *algo16,
    void *data,
    unsigned int counter) {
  unsigned char keydata[112];
  unsigned int offset = 0;
  secp256k1_rfc6979_hmac_sha256 rng;
  unsigned int i;
  /* We feed a byte array to the PRNG as input, consisting of:
   * - the private key (32 bytes) and message (32 bytes), see RFC 6979 3.2d.
   * - optionally 32 extra bytes of data, see RFC 6979 3.6 Additional Data.
   * - optionally 16 extra bytes with the algorithm name.
   * Because the arguments have distinct fixed lengths it is not possible for
   *  different argument mixtures to emulate each other and result in the same
   *  nonces.
   */
  buffer_append(keydata, &offset, key32, 32);
  buffer_append(keydata, &offset, msg32, 32);
  if (data != NULL) {
    buffer_append(keydata, &offset, data, 32);
  }
  if (algo16 != NULL) {
    buffer_append(keydata, &offset, algo16, 16);
  }
  secp256k1_rfc6979_hmac_sha256_initialize(&rng, keydata, offset);
  memset(keydata, 0, sizeof(keydata));
  for (i = 0; i <= counter; i++) {
    secp256k1_rfc6979_hmac_sha256_generate(&rng, nonce32, 32);
  }
  secp256k1_rfc6979_hmac_sha256_finalize(&rng);
  return 1;
}

const secp256k1_nonce_function secp256k1_nonce_function_default = nonce_function_rfc6979;

static int secp256k1_ecdsa_sign_inner(
    const secp256k1_context *ctx,
    secp256k1_scalar *r,
    secp256k1_scalar *s,
    int *recid,
    const unsigned char *msg32,
    const unsigned char *seckey,
    secp256k1_nonce_function noncefp,
    const void *noncedata) {
  secp256k1_scalar sec, non, msg;
  int ret;
  int is_sec_valid;
  unsigned char nonce32[32];
  unsigned int count = 0;
  /* Default initialization here is important so we won't pass uninit values to the cmov in the end */
  *r = secp256k1_scalar_zero;
  *s = secp256k1_scalar_zero;
  if (recid) {
    *recid = 0;
  }
  if (noncefp == NULL) {
    noncefp = secp256k1_nonce_function_default;
  }

  /* Fail if the secret key is invalid. */
  is_sec_valid = secp256k1_scalar_set_b32_seckey(&sec, seckey);
  secp256k1_scalar_cmov(&sec, &secp256k1_scalar_one, !is_sec_valid);
  secp256k1_scalar_set_b32(&msg, msg32, NULL);
  while (1) {
    int is_nonce_valid;
    ret = !!noncefp(nonce32, msg32, seckey, NULL, (void *) noncedata, count);
    if (!ret) {
      break;
    }
    is_nonce_valid = secp256k1_scalar_set_b32_seckey(&non, nonce32);
    /* The nonce is still secret here, but it being invalid is is less likely than 1:2^255. */
    if (is_nonce_valid) {
      ret = secp256k1_ecdsa_sig_sign(&ctx->ecmult_gen_ctx, r, s, &sec, &msg, &non, recid);
      /* The final signature is no longer a secret, nor is the fact that we were successful or not. */
      if (ret) {
        break;
      }
    }
    count++;
  }
  /* We don't want to declassify is_sec_valid and therefore the range of
   * seckey. As a result is_sec_valid is included in ret only after ret was
   * used as a branching variable. */
  ret &= is_sec_valid;
  memset(nonce32, 0, 32);
  secp256k1_scalar_clear(&msg);
  secp256k1_scalar_clear(&non);
  secp256k1_scalar_clear(&sec);
  secp256k1_scalar_cmov(r, &secp256k1_scalar_zero, !ret);
  secp256k1_scalar_cmov(s, &secp256k1_scalar_zero, !ret);
  if (recid) {
    const int zero = 0;
    secp256k1_int_cmov(recid, &zero, !ret);
  }
  return ret;
}

#ifdef ENABLE_MODULE_ECDH
# include "modules/ecdh/main_impl.h"
#endif

#ifdef ENABLE_MODULE_RECOVERY
# include "modules/recovery/main_impl.h"
#endif

#ifdef ENABLE_MODULE_EXTRAKEYS
# include "modules/extrakeys/main_impl.h"
#endif

#ifdef ENABLE_MODULE_SCHNORRSIG
# include "modules/schnorrsig/main_impl.h"
#endif
