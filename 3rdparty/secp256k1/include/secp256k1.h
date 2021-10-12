#ifndef SECP256K1_H
#define SECP256K1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/* These rules specify the order of arguments in API calls:
 *
 * 1. Context pointers go first, followed by output arguments, combined
 *    output/input arguments, and finally input-only arguments.
 * 2. Array lengths always immediately follow the argument whose length
 *    they describe, even if this violates rule 1.
 * 3. Within the OUT/OUTIN/IN groups, pointers to data that is typically generated
 *    later go first. This means: signatures, public nonces, secret nonces,
 *    messages, public keys, secret keys, tweaks.
 * 4. Arguments that are not data pointers go last, from more complex to less
 *    complex: function pointers, algorithm names, messages, void pointers,
 *    counts, flags, booleans.
 * 5. Opaque data pointers follow the function pointer they are to be passed to.
 */

/** Opaque data structure that holds context information (precomputed tables etc.).
 *
 *  The purpose of context structures is to cache large precomputed data tables
 *  that are expensive to construct, and also to maintain the randomization data
 *  for blinding.
 *
 *  Do not create a new context object for each operation, as construction is
 *  far slower than all other API calls (~100 times slower than an ECDSA
 *  verification).
 *
 *  A constructed context can safely be used from multiple threads
 *  simultaneously, but API calls that take a non-const pointer to a context
 *  need exclusive access to it. In particular this is the case for
 *  secp256k1_context_destroy, secp256k1_context_preallocated_destroy,
 *  and secp256k1_context_randomize.
 *
 *  Regarding randomization, either do it once at creation time (in which case
 *  you do not need any locking for the other calls), or use a read-write lock.
 */
typedef struct secp256k1_context_struct secp256k1_context;

/** Opaque data structure that holds a parsed and valid public key.
 *
 *  The exact representation of data inside is implementation defined and not
 *  guaranteed to be portable between different platforms or versions. It is
 *  however guaranteed to be 64 bytes in size, and can be safely copied/moved.
 *  If you need to convert to a format suitable for storage, transmission, or
 *  comparison, use secp256k1_ec_pubkey_serialize and secp256k1_ec_pubkey_parse.
 */
typedef struct {
  unsigned char data[64];
} secp256k1_pubkey;

/** A pointer to a function to deterministically generate a nonce.
 *
 * Returns: 1 if a nonce was successfully generated. 0 will cause signing to fail.
 * Out:     nonce32:   pointer to a 32-byte array to be filled by the function.
 * In:      msg32:     the 32-byte message hash being verified (will not be NULL)
 *          key32:     pointer to a 32-byte secret key (will not be NULL)
 *          algo16:    pointer to a 16-byte array describing the signature
 *                     algorithm (will be NULL for ECDSA for compatibility).
 *          data:      Arbitrary data pointer that is passed through.
 *          attempt:   how many iterations we have tried to find a nonce.
 *                     This will almost always be 0, but different attempt values
 *                     are required to result in a different nonce.
 *
 * Except for test cases, this function should compute some cryptographic hash of
 * the message, the algorithm, the key and the attempt.
 */
typedef int (*secp256k1_nonce_function)(
    unsigned char *nonce32,
    const unsigned char *msg32,
    const unsigned char *key32,
    const unsigned char *algo16,
    void *data,
    unsigned int attempt
);

# if !defined(SECP256K1_GNUC_PREREQ)
#  if defined(__GNUC__) && defined(__GNUC_MINOR__)
#   define SECP256K1_GNUC_PREREQ(_maj, _min) \
 ((__GNUC__<<16)+__GNUC_MINOR__>=((_maj)<<16)+(_min))
#  else
#   define SECP256K1_GNUC_PREREQ(_maj,_min) 0
#  endif
# endif

# if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L))
#  if SECP256K1_GNUC_PREREQ(2,7)
#   define SECP256K1_INLINE __inline__
#  elif (defined(_MSC_VER))
#   define SECP256K1_INLINE __inline
#  else
#   define SECP256K1_INLINE
#  endif
# else
#  define SECP256K1_INLINE inline
# endif

#ifndef SECP256K1_API
# if defined(_WIN32)
#  ifdef SECP256K1_BUILD
#   define SECP256K1_API __declspec(dllexport)
#  else
#   define SECP256K1_API
#  endif
# elif defined(__GNUC__) && (__GNUC__ >= 4) && defined(SECP256K1_BUILD)
#  define SECP256K1_API __attribute__ ((visibility ("default")))
# else
#  define SECP256K1_API
# endif
#endif

/**Warning attributes
  * NONNULL is not used if SECP256K1_BUILD is set to avoid the compiler optimizing out
  * some paranoid null checks. */
# if defined(__GNUC__) && SECP256K1_GNUC_PREREQ(3, 4)
#  define SECP256K1_WARN_UNUSED_RESULT __attribute__ ((__warn_unused_result__))
# else
#  define SECP256K1_WARN_UNUSED_RESULT
# endif
# if !defined(SECP256K1_BUILD) && defined(__GNUC__) && SECP256K1_GNUC_PREREQ(3, 4)
#  define SECP256K1_ARG_NONNULL(_x)  __attribute__ ((__nonnull__(_x)))
# else
#  define SECP256K1_ARG_NONNULL(_x)
# endif

/** All flags' lower 8 bits indicate what they're for. Do not use directly. */
#define SECP256K1_FLAGS_TYPE_MASK ((1 << 8) - 1)
#define SECP256K1_FLAGS_TYPE_CONTEXT (1 << 0)
#define SECP256K1_FLAGS_TYPE_COMPRESSION (1 << 1)
/** The higher bits contain the actual data. Do not use directly. */
#define SECP256K1_FLAGS_BIT_CONTEXT_VERIFY (1 << 8)
#define SECP256K1_FLAGS_BIT_CONTEXT_SIGN (1 << 9)
#define SECP256K1_FLAGS_BIT_CONTEXT_DECLASSIFY (1 << 10)
#define SECP256K1_FLAGS_BIT_COMPRESSION (1 << 8)

/** Flags to pass to secp256k1_context_create, secp256k1_context_preallocated_size, and
 *  secp256k1_context_preallocated_create. */
#define SECP256K1_CONTEXT_VERIFY (SECP256K1_FLAGS_TYPE_CONTEXT | SECP256K1_FLAGS_BIT_CONTEXT_VERIFY)
#define SECP256K1_CONTEXT_SIGN (SECP256K1_FLAGS_TYPE_CONTEXT | SECP256K1_FLAGS_BIT_CONTEXT_SIGN)

/** Flag to pass to secp256k1_ec_pubkey_serialize. */
#define SECP256K1_EC_UNCOMPRESSED (SECP256K1_FLAGS_TYPE_COMPRESSION)

/** Prefix byte used to tag various encoded curvepoints for specific purposes */
#define SECP256K1_TAG_PUBKEY_EVEN 0x02
#define SECP256K1_TAG_PUBKEY_ODD 0x03
#define SECP256K1_TAG_PUBKEY_UNCOMPRESSED 0x04

/** A simple secp256k1 context object with no precomputed tables. These are useful for
 *  type serialization/parsing functions which require a context object to maintain
 *  API consistency, but currently do not require expensive precomputations or dynamic
 *  allocations.
 */
SECP256K1_API extern const secp256k1_context *secp256k1_context_no_precomp;

/** Create a secp256k1 context object (in dynamically allocated memory).
 *
 *  This function uses malloc to allocate memory. It is guaranteed that malloc is
 *  called at most once for every call of this function. If you need to avoid dynamic
 *  memory allocation entirely, see the functions in secp256k1_preallocated.h.
 *
 *  Returns: a newly created context object.
 *  In:      flags: which parts of the context to initialize.
 *
 *  See also secp256k1_context_randomize.
 */
SECP256K1_API secp256k1_context *secp256k1_context_create(
    unsigned int flags
) SECP256K1_WARN_UNUSED_RESULT;

/** Destroy a secp256k1 context object (created in dynamically allocated memory).
 *
 *  The context pointer may not be used afterwards.
 *
 *  The context to destroy must have been created using secp256k1_context_create
 *  or secp256k1_context_clone. If the context has instead been created using
 *  secp256k1_context_preallocated_create or secp256k1_context_preallocated_clone, the
 *  behaviour is undefined. In that case, secp256k1_context_preallocated_destroy must
 *  be used instead.
 *
 *  Args:   ctx: an existing context to destroy, constructed using
 *               secp256k1_context_create or secp256k1_context_clone
 */
SECP256K1_API void secp256k1_context_destroy(
    secp256k1_context *ctx
);

/** Serialize a pubkey object into a serialized byte sequence.
 *
 *  Returns: 1 always.
 *  Args:   ctx:        a secp256k1 context object.
 *  Out:    output:     a pointer to a 65-byte (if compressed==0) or 33-byte (if
 *                      compressed==1) byte array to place the serialized key
 *                      in.
 *  In/Out: outputlen:  a pointer to an integer which is initially set to the
 *                      size of output, and is overwritten with the written
 *                      size.
 *  In:     pubkey:     a pointer to a secp256k1_pubkey containing an
 *                      initialized public key.
 *          flags:      SECP256K1_EC_COMPRESSED if serialization should be in
 *                      compressed format, otherwise SECP256K1_EC_UNCOMPRESSED.
 */
SECP256K1_API int secp256k1_ec_pubkey_serialize(
    const secp256k1_context *ctx,
    unsigned char *output,
    size_t *outputlen,
    const secp256k1_pubkey *pubkey,
    unsigned int flags
) SECP256K1_ARG_NONNULL(1) SECP256K1_ARG_NONNULL(2) SECP256K1_ARG_NONNULL(3) SECP256K1_ARG_NONNULL(4);

/** A default safe nonce generation function (currently equal to secp256k1_nonce_function_rfc6979). */
SECP256K1_API extern const secp256k1_nonce_function secp256k1_nonce_function_default;

#ifdef __cplusplus
}
#endif

#endif /* SECP256K1_H */
