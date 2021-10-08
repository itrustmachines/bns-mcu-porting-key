#include <assert.h>
#include <bns-client/input/receipt_locator.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // when
  char *url = build_post_receipt_locator_url(MOCK_SERVER_URL_OK);

  // then
  assert(url);
  assert(strcmp(url, MOCK_SERVER_URL_OK LEDGER_RECEIPT_LOCATOR_PATH) == 0);

  // clean
  BNS_FREE(url);
}

void test_server_url_NULL() {
  assert(build_post_receipt_locator_url(NULL) == NULL);
}

int main() {
  test_ok();
  test_server_url_NULL();
  return 0;
}