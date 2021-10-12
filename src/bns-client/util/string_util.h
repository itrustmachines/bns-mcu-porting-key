#ifndef BNS_C_CLIENT_SRC_STRING_UTIL_H_
#define BNS_C_CLIENT_SRC_STRING_UTIL_H_

#include <bns-client/core/bns_definitions.h>
#include <stdbool.h>

_CHECK_RESULT
bool bns_equals_ignore_case(const char *a, const char *b);

_CHECK_RESULT
bool bns_equals_n_ignore_case(const char *a, const char *b, size_t n);

void bns_strdup(char **dest, const char *src);

void remove_end_slash(char *string);

#endif  // BNS_C_CLIENT_SRC_STRING_UTIL_H_
