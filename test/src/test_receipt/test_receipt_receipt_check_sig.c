#include <assert.h>
#include <bns-client/input/receipt.h>

#include "../mock_data/mock_receipt.h"

void test_ok() {
  // given
  receipt_t receipt = {0};
  mock_receipt_ok(&receipt);

  // then
  assert(receipt_check_sig(MOCK_SERVER_WALLET_ADDRESS_OK, &receipt) == BNS_OK);
}

void test_BNS_SERVER_WALLET_ADDRESS_NULL_ERROR() {
  // given
  receipt_t receipt = {0};
  mock_receipt_ok(&receipt);

  // then
  assert(receipt_check_sig(NULL, &receipt) ==
         BNS_SERVER_WALLET_ADDRESS_NULL_ERROR);
}

void test_BNS_RECEIPT_NULL_ERROR() {
  assert(receipt_check_sig(MOCK_SERVER_WALLET_ADDRESS_OK, NULL) ==
         BNS_RECEIPT_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_SERVER_WALLET_ADDRESS_NULL_ERROR();
  test_BNS_RECEIPT_NULL_ERROR();
  return 0;
}