#include <assert.h>
#include <bns-client/input/ledger_input.h>
#include <bns-client/input/receipt_locator.h>

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_ledger_input_response.h"
#include "../mock_data/mock_receipt_locator.h"

void test_string_timestamp_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_ledger_input_response_string_timestamp_ok;
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) == BNS_OK);
  assert(strcmp(ledgerInputResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.description, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->callerAddress,
                MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestamp, MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->indexValue, MOCK_INDEX_VALUE_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->metadata, MOCK_METADATA_OK) == 0);
  assert(ledgerInputResult.receipt->clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestampSPO == MOCK_TIMESTAMP_BNS_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestampSPO,
                MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->result, MOCK_RESULT_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.r, MOCK_SIG_CLIENT_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.s, MOCK_SIG_CLIENT_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.v, MOCK_SIG_CLIENT_V_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.r, MOCK_SIG_SERVER_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.s, MOCK_SIG_SERVER_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.v, MOCK_SIG_SERVER_V_OK) ==
         0);
  assert(ledgerInputResult.doneClearanceOrder == MOCK_CLEARANCE_ORDER_OK);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
  ledger_input_result_free(&ledgerInputResult);
}

void test_long_timestamp_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_ledger_input_response_long_timestamp_ok;
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) == BNS_OK);
  assert(strcmp(ledgerInputResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.description, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->callerAddress,
                MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestamp, MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->indexValue, MOCK_INDEX_VALUE_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->metadata, MOCK_METADATA_OK) == 0);
  assert(ledgerInputResult.receipt->clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestampSPO == MOCK_TIMESTAMP_BNS_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestampSPO,
                MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->result, MOCK_RESULT_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.r, MOCK_SIG_CLIENT_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.s, MOCK_SIG_CLIENT_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.v, MOCK_SIG_CLIENT_V_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.r, MOCK_SIG_SERVER_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.s, MOCK_SIG_SERVER_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.v, MOCK_SIG_SERVER_V_OK) ==
         0);
  assert(ledgerInputResult.doneClearanceOrder == MOCK_CLEARANCE_ORDER_OK);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_CLIENT_NULL_ERROR() {
  // given
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(NULL, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) == BNS_CLIENT_NULL_ERROR);

  // clean
  receipt_locator_free(&receiptLocator);
}

void test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  BNS_FREE(bnsClient.config.serverUrl);
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) ==
         BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

void test_BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = NULL;
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) ==
         BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

void test_BNS_CLIENT_RECEIPT_DAO_SAVE_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.receiptDao.save = NULL;
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) ==
         BNS_CLIENT_RECEIPT_DAO_SAVE_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

void test_BNS_CMD_JSON_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, NULL, &receiptLocator,
                               &ledgerInputResult) == BNS_CMD_JSON_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

void test_BNS_RECEIPT_LOCATOR_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, NULL,
                               &ledgerInputResult) ==
         BNS_RECEIPT_LOCATOR_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_LEDGER_INPUT_RESULT_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               NULL) == BNS_LEDGER_INPUT_RESULT_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

void test_BNS_POST_LEDGER_INPUT_RESPONSE_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_response_null;
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(bns_post_ledger_input(&bnsClient, MOCK_CMD_OK, &receiptLocator,
                               &ledgerInputResult) ==
         BNS_POST_LEDGER_INPUT_RESPONSE_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
}

int main() {
  test_string_timestamp_ok();
  test_long_timestamp_ok();
  test_BNS_CLIENT_NULL_ERROR();
  test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR();
  test_BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR();
  test_BNS_CLIENT_RECEIPT_DAO_SAVE_NULL_ERROR();
  test_BNS_CMD_JSON_NULL_ERROR();
  test_BNS_RECEIPT_LOCATOR_NULL_ERROR();
  test_BNS_LEDGER_INPUT_RESULT_NULL_ERROR();
  test_BNS_POST_LEDGER_INPUT_RESPONSE_NULL_ERROR();
  return 0;
}