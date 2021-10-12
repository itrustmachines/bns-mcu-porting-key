#ifndef BNS_C_CLIENT_SRC_SHA256_SHA256_H_
#define BNS_C_CLIENT_SRC_SHA256_SHA256_H_

#define SHA256_BLOCK_SIZE 32

#include <stddef.h>

// data structure
typedef unsigned char BYTE;
typedef unsigned int WORD;

typedef struct {
  BYTE data[64];
  WORD dataLen;
  unsigned long long bitLen;
  WORD state[8];
} SHA256_CTX;

// function
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);
void sha256(const BYTE *data, size_t len, char *hash);
#endif  // BNS_C_CLIENT_SRC_SHA256_SHA256_H_
