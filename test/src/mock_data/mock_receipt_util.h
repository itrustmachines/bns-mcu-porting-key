#ifndef BNS_C_CLIENT_TEST_SRC_MOCK_DATA_UTIL_MOCK_RECEIPT_UTIL_H_
#define BNS_C_CLIENT_TEST_SRC_MOCK_DATA_UTIL_MOCK_RECEIPT_UTIL_H_

#include <bns-client/core/bns_types.h>
#include <bns-client/input/receipt.h>
#include <bns-client/util/log.h>

#include "mock_ok_data.h"

bns_exit_code_t parse_receipt(const char* const res, receipt_t* const receipt) {
  bns_exit_code_t exitCode;
  cJSON*          root = cJSON_Parse(res);
  exitCode             = parse_receipt_from_cjson(root, receipt);
  cJSON_Delete(root);
  return exitCode;
}

_CHECK_RESULT
int mock_get_string_timestamp_receipt(receipt_t* receipt) {
  int result = parse_receipt(MOCK_RECEIPT_JSON_STRING_TIMESTAMP_OK, receipt);
  LOG_DEBUG("mock_get_receipt() " RECEIPT_PRINT_FORMAT,
            RECEIPT_TO_PRINT_ARGS(receipt));
  return result;
}

_CHECK_RESULT
int mock_get_long_timestamp_receipt(receipt_t* receipt) {
  int result = parse_receipt(MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK, receipt);
  LOG_DEBUG("mock_get_receipt() " RECEIPT_PRINT_FORMAT,
            RECEIPT_TO_PRINT_ARGS(receipt));
  return result;
}

#endif  // BNS_C_CLIENT_TEST_SRC_MOCK_DATA_UTIL_MOCK_RECEIPT_UTIL_H_
