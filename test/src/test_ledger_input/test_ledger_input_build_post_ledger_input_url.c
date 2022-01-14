#include <assert.h>
#include <bns-client/input/ledger_input.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // then
  char* result = NULL;
  build_post_ledger_input_url(&result, MOCK_SERVER_URL_OK);
  assert(strcmp(result, MOCK_SERVER_URL_OK LEDGER_INPUT_PATH) == 0);

  // clean
  BNS_FREE(result);
}

void test_NULL() {
  char* result = NULL;
  build_post_ledger_input_url(&result, NULL);
  assert(!result);
}

int main() {
  test_ok();
  return 0;
}