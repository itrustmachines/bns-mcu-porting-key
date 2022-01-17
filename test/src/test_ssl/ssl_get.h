#ifndef SSL_GET_H
#define SSL_GET_H

#include <stddef.h>

typedef struct {
  char*  data;
  size_t size;
} MemoryBlock;

static const char* const APPLICATION_JSON = "Content-Type: application/json";

int ssl_init();

void ssl_clean();

char* ssl_post(char* url, char* postData);

char* ssl_put(char* url, char* postData);

char* ssl_get(char* url);

#endif /* SSL_GET_H */
