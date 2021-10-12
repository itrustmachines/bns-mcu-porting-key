/***********************************************************************
 * Copyright (c) 2013, 2014 Pieter Wuille                              *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_ECKEY_IMPL_H
#define SECP256K1_ECKEY_IMPL_H

#include "eckey.h"

#include "scalar.h"
#include "field.h"
#include "group.h"
#include "ecmult_gen.h"

static int secp256k1_eckey_pubkey_serialize(secp256k1_ge *elem, unsigned char *pub, size_t *size, int compressed) {
  if (secp256k1_ge_is_infinity(elem)) {
    return 0;
  }
  secp256k1_fe_normalize_var(&elem->x);
  secp256k1_fe_normalize_var(&elem->y);
  secp256k1_fe_get_b32(&pub[1], &elem->x);
  if (compressed) {
    *size = 33;
    pub[0] = secp256k1_fe_is_odd(&elem->y) ? SECP256K1_TAG_PUBKEY_ODD : SECP256K1_TAG_PUBKEY_EVEN;
  } else {
    *size = 65;
    pub[0] = SECP256K1_TAG_PUBKEY_UNCOMPRESSED;
    secp256k1_fe_get_b32(&pub[33], &elem->y);
  }
  return 1;
}

#endif /* SECP256K1_ECKEY_IMPL_H */
