#ifndef BNS_C_CLIENT_TEST_SRC_RECEIPT_LOCATOR_MOCK_RECEIPT_LOCATOR_RESPONSE_H_
#define BNS_C_CLIENT_TEST_SRC_RECEIPT_LOCATOR_MOCK_RECEIPT_LOCATOR_RESPONSE_H_

#include <bns-client/core/bns_definitions.h>
#include <bns-client/util/string_util.h>
#include <cJSON.h>

#include "mock_ok_data.h"

#define MOCK_RECEIPT_LOCATOR_RESPONSE_OK                                \
  ("{\"status\":\"" BNS_STATUS_OK "\",\"description\":\"" BNS_STATUS_OK \
   "\",\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR                 \
   ",\"sn\":" MOCK_SN_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_PARSE_ERROR_1 NULL
#define MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_PARSE_ERROR_2 \
  ("{\"description\":\"" BNS_STATUS_OK                     \
   "\",\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR    \
   ",\"sn\":" MOCK_SN_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_PARSE_ERROR_3 \
  ("{\"status\":200,\"description\":\"" BNS_STATUS_OK      \
   "\",\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR    \
   ",\"sn\":" MOCK_SN_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_ERROR_1                           \
  ("{\"status\":\"" BNS_STATUS_ERROR                                           \
   "\",\"description\":\"ok\",\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR \
   ",\"sn\":" MOCK_SN_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_ERROR_2                           \
  ("{\"status\":\"aaa\",\"description\":\"ok\","                               \
   "\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR ",\"sn\":" MOCK_SN_OK_STR \
   "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_CO_PARSE_ERROR_1 \
  ("{\"status\":\"" BNS_STATUS_OK                      \
   "\",\"description\":\"ok\",\"sn\":" MOCK_SN_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_CO_PARSE_ERROR_2                  \
  ("{\"status\":\"" BNS_STATUS_OK "\",\"description\":\"" BNS_STATUS_OK \
   "\",\"clearanceOrder\":\"" MOCK_CLEARANCE_ORDER_OK_STR               \
   "\",\"sn\":" MOCK_SN_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_SN_PARSE_ERROR_1                  \
  ("{\"status\":\"" BNS_STATUS_OK "\",\"description\":\"" BNS_STATUS_OK \
   "\",\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR "}")
#define MOCK_RECEIPT_LOCATOR_RESPONSE_SN_PARSE_ERROR_2                  \
  ("{\"status\":\"" BNS_STATUS_OK "\",\"description\":\"" BNS_STATUS_OK \
   "\",\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR                 \
   ",\"sn\":\"" MOCK_SN_OK_STR "\"}")

_CHECK_RESULT
char* mock_receipt_locator_response_ok();

char* mock_receipt_locator_response_ok() {
  char* res = NULL;
  bns_strdup(&res, MOCK_RECEIPT_LOCATOR_RESPONSE_OK);
  return res;
}

#endif  // BNS_C_CLIENT_TEST_SRC_RECEIPT_LOCATOR_MOCK_RECEIPT_LOCATOR_RESPONSE_H_
