#include <assert.h>
#include <bns-client/input/ledger_input_request.h>
#include <bns-client/input/receipt_locator.h>
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
#include <bns-client/util/time_util.h>
#endif

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_receipt_locator.h"

void test_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_request_t ledgerInputRequest = {0};
  assert(build_ledger_input_request(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                                    &ledgerInputRequest) == BNS_OK);
  assert(strcmp(ledgerInputRequest.callerAddress, MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputRequest.timestamp <= get_timestamp());
#else
  assert(strlen(ledgerInputRequest.timestamp) > 0);
#endif
  assert(strcmp(ledgerInputRequest.cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(ledgerInputRequest.indexValue, MOCK_INDEX_VALUE_OK) == 0);
  assert(strcmp(ledgerInputRequest.metadata, MOCK_METADATA_OK) == 0);
  assert(ledgerInputRequest.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(strlen(ledgerInputRequest.sigClient.r) == 0);
  assert(strlen(ledgerInputRequest.sigClient.s) == 0);
  assert(strlen(ledgerInputRequest.sigClient.v) == 0);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_CLIENT_NULL_ERROR() {
  receipt_locator_t receiptLocator = {0};
  ledger_input_request_t ledgerInputRequest = {0};
  assert(build_ledger_input_request(NULL, MOCK_CMD_OK, &receiptLocator,
                                    &ledgerInputRequest) ==
         BNS_CLIENT_NULL_ERROR);
}

void test_BNS_CMD_JSON_NULL_ERROR() {
  bns_client_t bnsClient = {0};
  receipt_locator_t receiptLocator = {0};
  ledger_input_request_t ledgerInputRequest = {0};
  assert(build_ledger_input_request(&bnsClient, NULL, &receiptLocator,
                                    &ledgerInputRequest) ==
         BNS_CMD_JSON_NULL_ERROR);
}

void test_BNS_RECEIPT_LOCATOR_NULL_ERROR() {
  bns_client_t bnsClient = {0};
  ledger_input_request_t ledgerInputRequest = {0};
  assert(build_ledger_input_request(&bnsClient, MOCK_CMD_OK, NULL,
                                    &ledgerInputRequest) ==
         BNS_RECEIPT_LOCATOR_NULL_ERROR);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR() {
  bns_client_t bnsClient = {0};
  receipt_locator_t receiptLocator = {0};
  assert(build_ledger_input_request(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                                    NULL) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_CLIENT_NULL_ERROR();
  test_BNS_CMD_JSON_NULL_ERROR();
  test_BNS_RECEIPT_LOCATOR_NULL_ERROR();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR();
  return 0;
}