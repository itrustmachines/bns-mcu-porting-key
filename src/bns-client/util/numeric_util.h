#ifndef BNS_C_CLIENT_SRC_NUMERIC_UTIL_H_
#define BNS_C_CLIENT_SRC_NUMERIC_UTIL_H_

#include <bns-client/core/bns_definitions.h>

_CHECK_RESULT
size_t bns_digits(long long int num);

_CHECK_RESULT
char *bns_lltos(long long int num);

#endif  // BNS_C_CLIENT_SRC_NUMERIC_UTIL_H_
