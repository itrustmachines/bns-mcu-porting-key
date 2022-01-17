#ifndef BNS_C_CLIENT_SIGNATURE_UTIL_H
#define BNS_C_CLIENT_SIGNATURE_UTIL_H

#include <bns-client/core/core.h>

void bns_sha3(const unsigned char* toSignData,
              size_t               size,
              unsigned char*       sha3Result);

void bns_sha3_prefix(const unsigned char* toSignData,
                     size_t               size,
                     unsigned char*       sha3Result);

_CHECK_RESULT
bns_exit_code_t bns_sign(const unsigned char* sha3Result,
                         const char*          privateKey,
                         sig_t*               sig);

_CHECK_RESULT
bns_exit_code_t verify_signature(const char*  address,
                                 const char*  toSignData,
                                 const sig_t* sig);

_CHECK_RESULT
bns_exit_code_t recover_public_key(const unsigned char* shaResult,
                                   const sig_t*         sig,
                                   char*                publicKey);

void recover_address(const char* publicKey, char* address);

#endif  // BNS_C_CLIENT_SIGNATURE_UTIL_H
