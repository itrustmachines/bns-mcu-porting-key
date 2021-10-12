#ifndef BNS_CLIENT_SRC_BNS_DEFINITIONS_H_
#define BNS_CLIENT_SRC_BNS_DEFINITIONS_H_

#include <malloc.h>
#include <stddef.h>

#if defined(__GNUC__) && (__GNUC__ >= 4)
#define _CHECK_RESULT __attribute__((warn_unused_result))
#define _UNUSED __attribute__((unused))
#define _DEPRECATED __attribute__((deprecated))
#else
#define _CHECK_RESULT
#define _UNUSED
#define _DEPRECATED
#endif

#ifndef _CRT_STRINGIZE
#define _CRT_STRINGIZE_(x) #x
#define _CRT_STRINGIZE(x) _CRT_STRINGIZE_(x)
#endif

#ifndef BNS_FREE
#define BNS_FREE(ptr) \
  free(ptr);          \
  (ptr) = NULL
#endif

#define BNS_STATUS_OK "ok"
#define BNS_STATUS_WARN "warn"
#define BNS_STATUS_ERROR "error"

#define BYTES_32 32
#define BYTES_64 64
#define HASH_BYTES BYTES_32
#define HASH_STR_LEN 65
#define PRIVATE_KEY_BYTES HASH_BYTES
#define PRIVATE_KEY_STR_LEN HASH_STR_LEN
#define PUBLIC_KEY_BYTES BYTES_64
#define PUBLIC_KEY_STR_LEN 129
#define ADDRESS_BYTES 20
#define ADDRESS_STR_LEN 41
#define ADDRESS_0X_STR_LEN (ADDRESS_STR_LEN + 2)
#if !defined(RECEIPT_TIMESTAMP_IS_LONG)
#define TIMESTAMP_STR_LEN 20
#endif
#if !defined(CMD_LEN)
#define CMD_LEN 1001
#endif  // !defined(CMD_LEN)
//#pragma message("CMD_LEN=" _CRT_STRINGIZE(CMD_LEN))
#if !defined(INDEX_VALUE_KEY_LEN)
#define INDEX_VALUE_KEY_LEN 51
#endif                                 // !defined(INDEX_VALUE_KEY_LEN)
#define MAX_CLEARANCE_COUNT_STR_LEN 3  // 3 : 0~999, 4 : 0~9999
#if !defined(INDEX_VALUE_LEN)
#define INDEX_VALUE_LEN (INDEX_VALUE_KEY_LEN + 2 + MAX_CLEARANCE_COUNT_STR_LEN)
#endif  // !defined(INDEX_VALUE_LEN)
#define METADATA_LEN 3
#define RESULT_LEN 6
#define SIG_R_STR_LEN HASH_STR_LEN
#define SIG_S_STR_LEN HASH_STR_LEN
#define SIG_V_STR_LEN 3
#define PB_PAIR_KEY_STR_LEN HASH_STR_LEN
#define PB_PAIR_VALUE_STR_LEN HASH_STR_LEN
#define SHA3_BYTE_LEN 33
#define SHA3_STR_LEN ((SHA3_BYTE_LEN * 2) - 1)

#endif  // BNS_CLIENT_SRC_BNS_DEFINITIONS_H_
