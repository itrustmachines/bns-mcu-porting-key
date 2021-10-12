#include <assert.h>
#include <bns-client/input/receipt_locator.h>
#include <string.h>

#include "../mock_data/mock_receipt_locator_response.h"

void test_ok() {
  // then
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_OK, MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_OK);
  assert(receiptLocator.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(strcmp(receiptLocator.indexValue, MOCK_INDEX_VALUE_OK) == 0);

  // clean
  receipt_locator_free(&receiptLocator);
}

void test_BNS_INDEX_VALUE_KEY_NULL_ERROR() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_OK, NULL, &receiptLocator) ==
         BNS_INDEX_VALUE_KEY_NULL_ERROR);
}

void test_BNS_RECEIPT_LOCATOR_NULL_ERROR() {
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_OK, MOCK_INDEX_VALUE_KEY_OK, NULL) ==
         BNS_RECEIPT_LOCATOR_NULL_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_1() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_PARSE_ERROR_1,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_2() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_PARSE_ERROR_2,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_3() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_PARSE_ERROR_3,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_ERROR_1() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_ERROR_1,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_STATUS_ERROR);
}

void test_BNS_RESPONSE_STATUS_ERROR_2() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_STATUS_ERROR_2,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_STATUS_ERROR);
}

void test_BNS_RESPONSE_CO_PARSE_ERROR_1() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_CO_PARSE_ERROR_1,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_CO_PARSE_ERROR);
}

void test_BNS_RESPONSE_CO_PARSE_ERROR_2() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_CO_PARSE_ERROR_2,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_CO_PARSE_ERROR);
}

void test_BNS_RESPONSE_SN_PARSE_ERROR_1() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_SN_PARSE_ERROR_1,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_SN_PARSE_ERROR);
}

void test_BNS_RESPONSE_SN_PARSE_ERROR_2() {
  receipt_locator_t receiptLocator = {0};
  assert(check_and_parse_receipt_locator_response(
             MOCK_RECEIPT_LOCATOR_RESPONSE_SN_PARSE_ERROR_2,
             MOCK_INDEX_VALUE_KEY_OK,
             &receiptLocator) == BNS_RESPONSE_SN_PARSE_ERROR);
}

int main() {
  test_ok();
  test_BNS_INDEX_VALUE_KEY_NULL_ERROR();
  test_BNS_RECEIPT_LOCATOR_NULL_ERROR();
  test_BNS_RESPONSE_STATUS_PARSE_ERROR_1();
  test_BNS_RESPONSE_STATUS_PARSE_ERROR_2();
  test_BNS_RESPONSE_STATUS_PARSE_ERROR_3();
  test_BNS_RESPONSE_STATUS_ERROR_1();
  test_BNS_RESPONSE_STATUS_ERROR_2();
  test_BNS_RESPONSE_CO_PARSE_ERROR_1();
  test_BNS_RESPONSE_CO_PARSE_ERROR_2();
  test_BNS_RESPONSE_SN_PARSE_ERROR_1();
  test_BNS_RESPONSE_SN_PARSE_ERROR_2();
  return 0;
}