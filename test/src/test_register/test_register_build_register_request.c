#include <assert.h>
#include <bns-client/register/register.h>

#include "../mock_data/mock_bns_client.h"

void test_ok() {
  register_request_t registerRequest = {0};
  assert(build_register_request(MOCK_CALLER_ADDRESS_OK, MOCK_EMAIL_OK,
                                &registerRequest) == BNS_OK);
  // clean
  register_request_free(&registerRequest);
}

void test_BNS_ADDRESS_NULL_ERROR() {
  assert(build_register_request(NULL, NULL, NULL) ==
         BNS_CALLER_ADDRESS_NULL_ERROR);
}

void test_BNS_EMAIL_NULL_ERROR() {
  assert(build_register_request(MOCK_CALLER_ADDRESS_OK, NULL, NULL) ==
         BNS_EMAIL_NULL_ERROR);
}

void test_BNS_REGISTER_REQUEST_NULL_ERROR() {
  assert(build_register_request(MOCK_CALLER_ADDRESS_OK, MOCK_EMAIL_OK, NULL) ==
         BNS_REGISTER_REQUEST_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_ADDRESS_NULL_ERROR();
  test_BNS_EMAIL_NULL_ERROR();
  test_BNS_REGISTER_REQUEST_NULL_ERROR();
  return 0;
}