#include <assert.h>
#include <bns-client/input/receipt_locator.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // then
  receipt_locator_t receiptLocator = {0};
  assert(build_receipt_locator(MOCK_INDEX_VALUE_KEY_OK, MOCK_CLEARANCE_ORDER_OK,
                               MOCK_SN_OK, &receiptLocator) == BNS_OK);
  assert(receiptLocator.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(strcmp(receiptLocator.indexValue, MOCK_INDEX_VALUE_OK) == 0);

  // clean
  receipt_locator_free(&receiptLocator);
}

void test_BNS_INDEX_VALUE_KEY_NULL_ERROR() {
  receipt_locator_t receiptLocator = {0};
  assert(build_receipt_locator(NULL, MOCK_CLEARANCE_ORDER_OK, MOCK_SN_OK,
                               &receiptLocator) ==
         BNS_INDEX_VALUE_KEY_NULL_ERROR);
}

void test_BNS_CLEARANCE_ORDER_ZERO_ERROR() {
  receipt_locator_t receiptLocator = {0};
  assert(build_receipt_locator(MOCK_INDEX_VALUE_KEY_OK, 0, MOCK_SN_OK,
                               &receiptLocator) ==
         BNS_CLEARANCE_ORDER_LESS_THAN_OR_EQUAL_TO_ZERO_ERROR);
}

void test_BNS_SN_NEGATIVE_ERROR() {
  receipt_locator_t receiptLocator = {0};
  assert(build_receipt_locator(MOCK_INDEX_VALUE_KEY_OK, MOCK_CLEARANCE_ORDER_OK,
                               -1, &receiptLocator) == BNS_SN_NEGATIVE_ERROR);
}

void test_BNS_RECEIPT_LOCATOR_NULL_ERROR() {
  assert(build_receipt_locator(MOCK_INDEX_VALUE_KEY_OK, MOCK_CLEARANCE_ORDER_OK,
                               MOCK_SN_OK,
                               NULL) == BNS_RECEIPT_LOCATOR_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_INDEX_VALUE_KEY_NULL_ERROR();
  test_BNS_CLEARANCE_ORDER_ZERO_ERROR();
  test_BNS_SN_NEGATIVE_ERROR();
  test_BNS_RECEIPT_LOCATOR_NULL_ERROR();
  return 0;
}