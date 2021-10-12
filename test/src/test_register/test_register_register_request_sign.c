#include <assert.h>
#include <bns-client/register/register.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // given
  register_request_t registerRequest = {
      .address = MOCK_CALLER_ADDRESS_OK,
      .email = MOCK_EMAIL_OK,
      .toSignMessage = MOCK_TO_SIGN_MESSAGE_OK};

  // then
  assert(register_request_sign(&registerRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_OK);
  assert(strcmp(registerRequest.sig.r,
                MOCK_REGISTER_REQUEST_SIG_REGISTER_R_OK) == 0);
  assert(strcmp(registerRequest.sig.s,
                MOCK_REGISTER_REQUEST_SIG_REGISTER_S_OK) == 0);
  assert(strcmp(registerRequest.sig.v,
                MOCK_REGISTER_REQUEST_SIG_REGISTER_V_OK) == 0);
}

void test_BNS_REGISTER_REQUEST_NULL_ERROR() {
  assert(register_request_sign(NULL, NULL) == BNS_REGISTER_REQUEST_NULL_ERROR);
}

void test_BNS_PRIVATE_KEY_NULL_ERROR() {
  register_request_t registerRequest = {
      .address = MOCK_CALLER_ADDRESS_OK,
      .email = MOCK_EMAIL_OK,
      .toSignMessage = MOCK_TO_SIGN_MESSAGE_OK};
  assert(register_request_sign(&registerRequest, NULL) ==
         BNS_PRIVATE_KEY_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_REGISTER_REQUEST_NULL_ERROR();
  test_BNS_PRIVATE_KEY_NULL_ERROR();
  return 0;
}