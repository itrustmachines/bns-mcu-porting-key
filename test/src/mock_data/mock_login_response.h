#ifndef BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_LOGIN_RESPONSE_H_
#define BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_LOGIN_RESPONSE_H_

#include <bns-client/util/string_util.h>

#define MOCK_LOGIN_RESPONSE_OK "{\"address\":\"" MOCK_CALLER_ADDRESS_OK "\"}"

char* mock_login_response_ok() {
  char* res = NULL;
  bns_strdup(&res, MOCK_LOGIN_RESPONSE_OK);
  return res;
}

#endif  // BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_LOGIN_RESPONSE_H_
