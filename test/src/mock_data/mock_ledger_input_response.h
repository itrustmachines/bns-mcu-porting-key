#ifndef BNS_C_CLIENT_TEST_SRC_LEDGER_INPUT_MOCK_LEDGER_INPUT_RESPONSE_H_
#define BNS_C_CLIENT_TEST_SRC_LEDGER_INPUT_MOCK_LEDGER_INPUT_RESPONSE_H_

#include <bns-client/core/bns_definitions.h>
#include <bns-client/util/string_util.h>
#include <cJSON.h>

#include "mock_ok_data.h"

#define MOCK_LEDGER_INPUT_RESPONSE_STRING_TIMESTAMP_OK                 \
  "{\"status\":\"" BNS_STATUS_OK "\",\"description\":\"" BNS_STATUS_OK \
  "\",\"receipt\":" MOCK_RECEIPT_JSON_STRING_TIMESTAMP_OK              \
  ",\"doneClearanceOrderList\":[" MOCK_CLEARANCE_ORDER_OK_STR "]}"
#define MOCK_LEDGER_INPUT_RESPONSE_LONG_TIMESTAMP_OK                   \
  "{\"status\":\"" BNS_STATUS_OK "\",\"description\":\"" BNS_STATUS_OK \
  "\",\"receipt\":" MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK                \
  ",\"doneClearanceOrderList\":[" MOCK_CLEARANCE_ORDER_OK_STR "]}"
#define MOCK_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_1 NULL
#define MOCK_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_2 \
  "{\"description\":\"" BNS_STATUS_OK                   \
  "\",\"receipt\":" MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK \
  ",\"doneClearanceOrderList\":[" MOCK_CLEARANCE_ORDER_OK_STR "]}"
#define MOCK_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_3 \
  "{\"status\":200,\"description\":\"" BNS_STATUS_OK    \
  "\",\"receipt\":" MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK \
  ",\"doneClearanceOrderList\":[" MOCK_CLEARANCE_ORDER_OK_STR "]}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_PARSE_ERROR_1 \
  "{\"status\":\"" BNS_STATUS_OK                             \
  "\",\"receipt\":" MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK      \
  ",\"doneClearanceOrderList\":[" MOCK_CLEARANCE_ORDER_OK_STR "]}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_PARSE_ERROR_2                \
  "{\"status\":\"" BNS_STATUS_OK                                            \
  "\",\"description\":200,\"receipt\":" MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK \
  ",\"doneClearanceOrderList\":[" MOCK_CLEARANCE_ORDER_OK_STR "]}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_CLEARANCE_ORDER_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR                                  \
  "\",\"description\":\"" CLEARANCE_ORDER_ERROR "\"}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_INDEX_VALUE_ERROR              \
  "{\"status\":\"" BNS_STATUS_ERROR "\",\"description\":\"" INDEX_VALUE_ERROR \
  "\"}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_CLIENT_SIGNATURE_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR                                   \
  "\",\"description\":\"" CLIENT_SIGNATURE_ERROR "\"}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_AUTHENTICATION_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR                                 \
  "\",\"description\":\"" AUTHENTICATION_ERROR "\"}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_CMD_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR "\",\"description\":\"" CMD_ERROR "\"}"
#define MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_TX_COUNT_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR "\",\"description\":\"" TX_COUNT_ERROR "\"}"
#define MOCK_LEDGER_INPUT_RESPONSE_STATUS_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR "\",\"description\":\"Dont Care\"}"

_CHECK_RESULT
char *mock_ledger_input_response_string_timestamp_ok() {
  char *json = NULL;
  bns_strdup(&json, MOCK_LEDGER_INPUT_RESPONSE_STRING_TIMESTAMP_OK);
  return json;
}

_CHECK_RESULT
char *mock_ledger_input_response_long_timestamp_ok() {
  char *json = NULL;
  bns_strdup(&json, MOCK_LEDGER_INPUT_RESPONSE_LONG_TIMESTAMP_OK);
  return json;
}

#endif  // BNS_C_CLIENT_TEST_SRC_LEDGER_INPUT_MOCK_LEDGER_INPUT_RESPONSE_H_
