#ifndef BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_REGISTER_RESPONSE_H_
#define BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_REGISTER_RESPONSE_H_

#include <bns-client/register/register.h>
#include <bns-client/util/string_util.h>

#include "mock_ok_data.h"

#define MOCK_REGISTER_RESPONSE_OK "OK"
#define MOCK_REGISTER_RESPONSE_ERROR "{\"error\":\"cognito register erroe\"}"
#define MOCK_CHECK_REGISTER_RESPONSE_TRUE "true"
#define MOCK_CHECK_REGISTER_RESPONSE_FALSE "false"

_CHECK_RESULT
char *mock_register_response_ok() {
  char *json = NULL;
  bns_strdup(&json, MOCK_REGISTER_RESPONSE_OK);
  return json;
}

_CHECK_RESULT
char *mock_register_response_error() {
  char *json = NULL;
  bns_strdup(&json, MOCK_REGISTER_RESPONSE_ERROR);
  return json;
}

_CHECK_RESULT
char *mock_check_register_response_true() {
  char *json = NULL;
  char *string = MOCK_CHECK_REGISTER_RESPONSE_TRUE;
  bns_strdup(&json, string);
  return json;
}

_CHECK_RESULT
char *mock_check_register_response_false() {
  char *json = NULL;
  bns_strdup(&json, MOCK_CHECK_REGISTER_RESPONSE_FALSE);
  return json;
}

#endif  // BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_REGISTER_RESPONSE_H_
