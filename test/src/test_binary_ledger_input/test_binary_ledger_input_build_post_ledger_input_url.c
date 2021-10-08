#include <assert.h>
#include <bns-client/input/binary_ledger_input.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // then
  char *result = build_post_binary_ledger_input_url(MOCK_SERVER_URL_OK);
  assert(strcmp(result, MOCK_SERVER_URL_OK BINARY_LEDGER_INPUT_PATH) == 0);

  // clean
  BNS_FREE(result);
}

void test_NULL() {
  char *result = build_post_binary_ledger_input_url(NULL);
  assert(!result);
}

int main() {
  test_ok();
  return 0;
}