#ifndef BNS_C_CLIENT_TEST_SRC_RECEIPT_LOCATOR_MOCK_RECEIPT_LOCATOR_H_
#define BNS_C_CLIENT_TEST_SRC_RECEIPT_LOCATOR_MOCK_RECEIPT_LOCATOR_H_

#include <bns-client/core/bns_types.h>
#include <bns-client/util/string_util.h>

#include "mock_ok_data.h"

void mock_receipt_locator_ok(receipt_locator_t* receiptLocator) {
  int clearanceOrder             = MOCK_CLEARANCE_ORDER_OK;
  receiptLocator->clearanceOrder = clearanceOrder;
  bns_strdup(&receiptLocator->indexValue, MOCK_INDEX_VALUE_OK);
  assert(MOCK_CLEARANCE_ORDER_OK == receiptLocator->clearanceOrder);
  assert(strcmp(MOCK_INDEX_VALUE_OK, receiptLocator->indexValue) == 0);
}

#endif  // BNS_C_CLIENT_TEST_SRC_RECEIPT_LOCATOR_MOCK_RECEIPT_LOCATOR_H_
