#include <assert.h>
#include <bns-client/input/receipt.h>

#include "../mock_data/mock_receipt.h"

void test_ok() {
  // given
  receipt_t receipt = {0};
  mock_receipt_ok(&receipt);

  // then
  char *result = NULL;
  assert(receipt_to_digest_value(&receipt, &result) == BNS_OK);
  assert(strcmp(result, MOCK_RECEIPT_DIGEST_VALUE_OK) == 0);

  // clean
  if (result) {
    BNS_FREE(result);
  }
}

void test_BNS_RECEIPT_NULL_ERROR() {
  char *result = NULL;
  assert(receipt_to_digest_value(NULL, &result) == BNS_RECEIPT_NULL_ERROR);
}

void test_BNS_RECEIPT_DIGEST_NULL_ERROR() {
  // given
  receipt_t receipt = {0};
  mock_receipt_ok(&receipt);

  // then
  assert(receipt_to_digest_value(&receipt, NULL) ==
         BNS_RECEIPT_DIGEST_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_RECEIPT_NULL_ERROR();
  test_BNS_RECEIPT_DIGEST_NULL_ERROR();
  return 0;
}