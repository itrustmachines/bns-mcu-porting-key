// header
#include <bns-client/sha256/sha256.h>
#include <stdio.h>
#include <string.h>

// macro
#define ROTLEFT(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
#define ROTRIGHT(a, b) (((a) >> (b)) | ((a) << (32 - (b))))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x, 2) ^ ROTRIGHT(x, 13) ^ ROTRIGHT(x, 22))
#define EP1(x) (ROTRIGHT(x, 6) ^ ROTRIGHT(x, 11) ^ ROTRIGHT(x, 25))
#define SIG0(x) (ROTRIGHT(x, 7) ^ ROTRIGHT(x, 18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x, 17) ^ ROTRIGHT(x, 19) ^ ((x) >> 10))

// variables
const WORD k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
    0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
    0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
    0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
    0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
enum
{
  a,
  b,
  c,
  d,
  e,
  f,
  g,
  h
};

// function
void sha256_transform(SHA256_CTX *ctx, const BYTE data[])
{
  WORD arr[8], t[2], m[64], i, j;
  for (i = 0, j = 0; i < 16; ++i, j += 4)
  {
    m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) |
           (data[j + 3]);
  }
  for (; i < 64; ++i)
  {
    m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
  }
  for (i = 0; i < 8; i++)
  {
    arr[i] = ctx->state[i];
  }
  for (i = 0; i < 64; ++i)
  {
    t[0] = arr[h] + EP1(arr[e]) + CH(arr[e], arr[f], arr[g]) + k[i] + m[i];
    t[1] = EP0(arr[a]) + MAJ(arr[a], arr[b], arr[c]);
    arr[h] = arr[g];
    arr[g] = arr[f];
    arr[f] = arr[e];
    arr[e] = arr[d] + t[0];
    arr[d] = arr[c];
    arr[c] = arr[b];
    arr[b] = arr[a];
    arr[a] = t[0] + t[1];
  }
  for (i = 0; i < 8; i++)
  {
    ctx->state[i] += arr[i];
  }
}

void sha256_init(SHA256_CTX *ctx)
{
  ctx->dataLen = 0;
  ctx->bitLen = 0;
  ctx->state[0] = 0x6a09e667;
  ctx->state[1] = 0xbb67ae85;
  ctx->state[2] = 0x3c6ef372;
  ctx->state[3] = 0xa54ff53a;
  ctx->state[4] = 0x510e527f;
  ctx->state[5] = 0x9b05688c;
  ctx->state[6] = 0x1f83d9ab;
  ctx->state[7] = 0x5be0cd19;
}

void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len)
{
  WORD i;
  for (i = 0; i < len; ++i)
  {
    ctx->data[ctx->dataLen] = data[i];
    ctx->dataLen++;
    if (ctx->dataLen == 64)
    {
      sha256_transform(ctx, ctx->data);
      ctx->bitLen += 512;
      ctx->dataLen = 0;
    }
  }
}

void sha256_final(SHA256_CTX *ctx, BYTE hash[])
{
  WORD i, j;
  i = ctx->dataLen;
  if (ctx->dataLen < 56)
  {
    ctx->data[i++] = 0x80;
    while (i < 56)
    {
      ctx->data[i++] = 0x00;
    }
  }
  else
  {
    ctx->data[i++] = 0x80;
    while (i < 64)
    {
      ctx->data[i++] = 0x00;
    }
    sha256_transform(ctx, ctx->data);
    memset(ctx->data, 0, 56);
  }
  ctx->bitLen += ctx->dataLen * 8;

  for (j = 63; j > 55; j--)
  {
    ctx->data[j] = ctx->bitLen >> (63 - j) * 8;
  }
  sha256_transform(ctx, ctx->data);

  for (i = 0; i < 4; ++i)
  {
    hash[i] = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 4] = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 8] = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
  }
}

void sha256(const BYTE *data, size_t len, char *hash)
{
  SHA256_CTX ctx;
  int i;
  BYTE byteHash[SHA256_BLOCK_SIZE];

  sha256_init(&ctx);
  sha256_update(&ctx, data, len);
  sha256_final(&ctx, byteHash);

  char temp[4] = {0};
  for (i = 0; i < SHA256_BLOCK_SIZE; i++)
  {
    sprintf(temp, "%.2x", byteHash[i]);
    strcat(hash, temp);
    temp[0] = '\0';
  }
}
