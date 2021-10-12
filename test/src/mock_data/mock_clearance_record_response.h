#ifndef BNS_C_CLIENT_TEST_SRC_VERIFY_MOCK_CLEARANCE_RECORD_H_
#define BNS_C_CLIENT_TEST_SRC_VERIFY_MOCK_CLEARANCE_RECORD_H_

#define MOCK_ERROR_CLEARANCE_RECORD_RESPONSE                               \
  "{\"jsonrpc\":\"2.0\",\"id\":1,\"error\":{\"code\":-32602,\"message\":"  \
  "\"invalid argument 0: json: cannot unmarshal hex string of odd length " \
  "into Go struct field CallArgs.data of type hexutil.Bytes\"}}"

#include <bns-client/contract/contract.h>
#include <bns-client/core/bns_definitions.h>
#include <bns-client/util/string_util.h>

#include "mock_ok_data.h"

_CHECK_RESULT
char *mock_clearance_record_response_ok() {
  char *json = NULL;
  bns_strdup(&json, MOCK_CLEARANCE_RECORD_RESPONSE_OK);
  return json;
}

_CHECK_RESULT
char *mock_clearance_record_response_error() {
  char *json = NULL;
  bns_strdup(&json, MOCK_ERROR_CLEARANCE_RECORD_RESPONSE);
  return json;
}

_CHECK_RESULT
int mock_clearance_record_ok(clearance_record_t *clearanceRecord) {
  char *response = mock_clearance_record_response_ok();
  int res = check_and_parse_contract_clearance_record_response(response,
                                                               clearanceRecord);
  free(response);
  return res;
}

#endif  // BNS_C_CLIENT_TEST_SRC_VERIFY_MOCK_CLEARANCE_RECORD_H_
