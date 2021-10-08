#include <assert.h>
#include <bns-client/register/register.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // when
  char *url1 = build_post_register_url(MOCK_SERVER_URL_OK);
  char *url2 =
      build_check_register_url(MOCK_SERVER_URL_OK, MOCK_CALLER_ADDRESS_OK);

  // then
  assert(strcmp(url1, MOCK_SERVER_URL_OK LEDGER_REGISTER) == 0);
  assert(strcmp(url2, MOCK_SERVER_URL_OK LEDGER_CHECK_REGISTER
                          MOCK_CALLER_ADDRESS_OK) == 0);

  // clean
  BNS_FREE(url1);
  BNS_FREE(url2);
}

void test_NULL() {
  assert(build_post_register_url(NULL) == NULL);
  assert(build_check_register_url(NULL, MOCK_CALLER_ADDRESS_OK) == NULL);
  assert(build_check_register_url(MOCK_SERVER_URL_OK, NULL) == NULL);
}

int main() {
  test_ok();
  test_NULL();
  return 0;
}