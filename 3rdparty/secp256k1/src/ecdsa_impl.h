/***********************************************************************
 * Copyright (c) 2013-2015 Pieter Wuille                               *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/


#ifndef SECP256K1_ECDSA_IMPL_H
#define SECP256K1_ECDSA_IMPL_H

#include "scalar.h"
#include "field.h"
#include "group.h"
#include "ecmult.h"
#include "ecmult_gen.h"
#include "ecdsa.h"

/** Group order for secp256k1 defined as 'n' in "Standards for Efficient Cryptography" (SEC2) 2.7.1
 *  sage: for t in xrange(1023, -1, -1):
 *     ..   p = 2**256 - 2**32 - t
 *     ..   if p.is_prime():
 *     ..     print '%x'%p
 *     ..     break
 *   'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'
 *  sage: a = 0
 *  sage: b = 7
 *  sage: F = FiniteField (p)
 *  sage: '%x' % (EllipticCurve ([F (a), F (b)]).order())
 *   'fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141'
 */
static const secp256k1_fe secp256k1_ecdsa_const_order_as_fe = SECP256K1_FE_CONST(
    0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFEUL,
    0xBAAEDCE6UL, 0xAF48A03BUL, 0xBFD25E8CUL, 0xD0364141UL
);

/** Difference between field and order, values 'p' and 'n' values defined in
 *  "Standards for Efficient Cryptography" (SEC2) 2.7.1.
 *  sage: p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F
 *  sage: a = 0
 *  sage: b = 7
 *  sage: F = FiniteField (p)
 *  sage: '%x' % (p - EllipticCurve ([F (a), F (b)]).order())
 *   '14551231950b75fc4402da1722fc9baee'
 */
static const secp256k1_fe secp256k1_ecdsa_const_p_minus_order = SECP256K1_FE_CONST(
    0, 0, 0, 1, 0x45512319UL, 0x50B75FC4UL, 0x402DA172UL, 0x2FC9BAEEUL
);

static int secp256k1_ecdsa_sig_sign(
    const secp256k1_ecmult_gen_context *ctx,
    secp256k1_scalar *sigr,
    secp256k1_scalar *sigs,
    const secp256k1_scalar *seckey,
    const secp256k1_scalar *message,
    const secp256k1_scalar *nonce,
    int *recid) {
  unsigned char b[32];
  secp256k1_gej rp;
  secp256k1_ge r;
  secp256k1_scalar n;
  int overflow = 0;
  int high;

  secp256k1_ecmult_gen(ctx, &rp, nonce);
  secp256k1_ge_set_gej(&r, &rp);
  secp256k1_fe_normalize(&r.x);
  secp256k1_fe_normalize(&r.y);
  secp256k1_fe_get_b32(b, &r.x);
  secp256k1_scalar_set_b32(sigr, b, &overflow);
  if (recid) {
    /* The overflow condition is cryptographically unreachable as hitting it requires finding the discrete log
     * of some P where P.x >= order, and only 1 in about 2^127 points meet this criteria.
     */
    *recid = (overflow << 1) | secp256k1_fe_is_odd(&r.y);
  }
  secp256k1_scalar_mul(&n, sigr, seckey);
  secp256k1_scalar_add(&n, &n, message);
  secp256k1_scalar_inverse(sigs, nonce);
  secp256k1_scalar_mul(sigs, sigs, &n);
  secp256k1_scalar_clear(&n);
  secp256k1_gej_clear(&rp);
  secp256k1_ge_clear(&r);
  high = secp256k1_scalar_is_high(sigs);
  secp256k1_scalar_cond_negate(sigs, high);
  if (recid) {
    *recid ^= high;
  }
  /* P.x = order is on the curve, so technically sig->r could end up being zero, which would be an invalid signature.
   * This is cryptographically unreachable as hitting it requires finding the discrete log of P.x = N.
   */
  return !secp256k1_scalar_is_zero(sigr) & !secp256k1_scalar_is_zero(sigs);
}

#endif /* SECP256K1_ECDSA_IMPL_H */
