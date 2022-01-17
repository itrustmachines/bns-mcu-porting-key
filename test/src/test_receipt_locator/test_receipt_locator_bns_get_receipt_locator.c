#include <assert.h>
#include <bns-client/input/receipt_locator.h>

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_receipt_locator_response.h"

void test_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = mock_receipt_locator_response_ok;

  // then
  receipt_locator_t receiptLocator = {0};
  assert(bns_get_receipt_locator(&bnsClient, &receiptLocator) == BNS_OK);
  assert(receiptLocator.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(strcmp(receiptLocator.indexValue, MOCK_INDEX_VALUE_OK) == 0);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

void test_BNS_CLIENT_NULL_ERROR() {
  receipt_locator_t receiptLocator = {0};
  assert(bns_get_receipt_locator(NULL, &receiptLocator) ==
         BNS_CLIENT_NULL_ERROR);
}

void test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  BNS_FREE(bnsClient.config.serverUrl);

  // then
  receipt_locator_t receiptLocator = {0};
  assert(bns_get_receipt_locator(&bnsClient, &receiptLocator) ==
         BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_CLIENT_CONFIG_INDEX_VALUE_KEY_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  BNS_FREE(bnsClient.config.indexValueKey);

  // then
  receipt_locator_t receiptLocator = {0};
  assert(bns_get_receipt_locator(&bnsClient, &receiptLocator) ==
         BNS_CLIENT_CONFIG_INDEX_VALUE_KEY_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_CLIENT_HTTP_CLIENT_BNS_GET_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = NULL;

  // then
  receipt_locator_t receiptLocator = {0};
  assert(bns_get_receipt_locator(&bnsClient, &receiptLocator) ==
         BNS_CLIENT_HTTP_CLIENT_BNS_GET_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_RECEIPT_LOCATOR_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);

  // then
  assert(bns_get_receipt_locator(&bnsClient, NULL) ==
         BNS_RECEIPT_LOCATOR_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_GET_RECEIPT_LOCATOR_RESPONSE_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = mock_response_null;

  // then
  receipt_locator_t receiptLocator = {0};
  assert(bns_get_receipt_locator(&bnsClient, &receiptLocator) ==
         BNS_GET_RECEIPT_LOCATOR_RESPONSE_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

int main() {
  test_ok();
  test_BNS_CLIENT_NULL_ERROR();
  test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR();
  test_BNS_CLIENT_CONFIG_INDEX_VALUE_KEY_NULL_ERROR();
  test_BNS_CLIENT_HTTP_CLIENT_BNS_GET_NULL_ERROR();
  test_BNS_RECEIPT_LOCATOR_NULL_ERROR();
  test_BNS_GET_RECEIPT_LOCATOR_RESPONSE_NULL_ERROR();
  return 0;
}