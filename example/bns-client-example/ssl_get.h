#ifndef SSL_GET_H
#define SSL_GET_H

#include <stddef.h>

typedef struct {
  char *data;
  size_t size;
} MemoryBlock;

static const char *const APPLICATION_JSON = "Content-Type: application/json";

int ssl_init();

void ssl_clean();

// Get information form SPO Server
char *bns_get(const char *url);

// POST information to SPO Server
char *bns_post(const char *url, const char *postData);

// Get information form Blockchain
char *eth_post(const char *url, const char *postData);

#endif /* SSL_GET_H */