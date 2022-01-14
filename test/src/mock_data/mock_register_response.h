#ifndef BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_REGISTER_RESPONSE_H_
#define BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_REGISTER_RESPONSE_H_

#include <bns-client/register/register.h>
#include <bns-client/util/string_util.h>

#include "mock_ok_data.h"

#define MOCK_CHECK_REGISTER_RESPONSE_TRUE "true"

_CHECK_RESULT
char* mock_check_register_response_true() {
  char* json   = NULL;
  char* string = MOCK_CHECK_REGISTER_RESPONSE_TRUE;
  bns_strdup(&json, string);
  return json;
}

#endif  // BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_REGISTER_RESPONSE_H_
