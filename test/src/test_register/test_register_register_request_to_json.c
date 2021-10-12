#include <assert.h>
#include <bns-client/register/register.h>
#include <string.h>

#include "../mock_data/mock_bns_client.h"

void test_ok() {
  // given
  register_request_t registerRequest = {0};
  assert(build_register_request(MOCK_CALLER_ADDRESS_OK, MOCK_EMAIL_OK,
                                &registerRequest) == BNS_OK);
  assert(register_request_sign(&registerRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_OK);

  // then
  char *json = NULL;
  assert(register_request_to_json(&registerRequest, &json) == BNS_OK);
  assert(strcmp(json, MOCK_REGISTER_REQUEST_JSON_OK) == 0);

  // clean
  register_request_free(&registerRequest);
  BNS_FREE(json);
}

void test_BNS_REGISTER_REQUEST_NULL_ERROR() {
  assert(register_request_to_json(NULL, NULL) ==
         BNS_REGISTER_REQUEST_NULL_ERROR);
}

void test_BNS_REGISTER_REQUEST_JSON_NULL_ERROR() {
  // given
  register_request_t registerRequest = {0};
  assert(build_register_request(MOCK_CALLER_ADDRESS_OK, MOCK_EMAIL_OK,
                                &registerRequest) == BNS_OK);
  assert(register_request_sign(&registerRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_OK);

  // then
  assert(register_request_to_json(&registerRequest, NULL) ==
         BNS_REGISTER_REQUEST_JSON_NULL_ERROR);

  // clean
  register_request_free(&registerRequest);
}

int main() {
  test_ok();
  test_BNS_REGISTER_REQUEST_NULL_ERROR();
  test_BNS_REGISTER_REQUEST_JSON_NULL_ERROR();
  return 0;
}