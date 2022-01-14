#include <assert.h>
#include <bns-client/input/receipt_locator.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // when
  char* url = NULL;
  build_get_receipt_locator_url(&url, MOCK_SERVER_URL_OK,
                                MOCK_INDEX_VALUE_KEY_OK);

  // then
  assert(url);
  assert(strcmp(url, MOCK_SERVER_URL_OK LEDGER_RECEIPT_LOCATOR_PATH
                         MOCK_INDEX_VALUE_KEY_OK) == 0);

  // clean
  BNS_FREE(url);
}

int main() {
  test_ok();
  return 0;
}