#include <assert.h>
#include <bns-client/register/register.h>

#include "../mock_data/mock_register_response.h"

void test_ok() {
  assert(check_and_parse_register_response(MOCK_REGISTER_RESPONSE_OK) ==
         BNS_OK);
}

void test_error() {
  assert(check_and_parse_register_response(MOCK_REGISTER_RESPONSE_ERROR) ==
         BNS_REGISTER_ERROR);
}

int main() {
  test_ok();
  test_error();
  return 0;
}