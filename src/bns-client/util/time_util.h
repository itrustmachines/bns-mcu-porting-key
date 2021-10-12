#ifndef BNS_C_CLIENT_SRC_TIME_UTIL_H_
#define BNS_C_CLIENT_SRC_TIME_UTIL_H_

#include <bns-client/core/core.h>

_CHECK_RESULT
char *get_timestamp_string();

_CHECK_RESULT
bns_long_t get_timestamp();

#endif  // BNS_C_CLIENT_SRC_TIME_UTIL_H_
