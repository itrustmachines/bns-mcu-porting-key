#ifndef BNS_CLIENT_TEST_SRC_BNS_CLIENT_MOCK_BNS_CLIENT_H_
#define BNS_CLIENT_TEST_SRC_BNS_CLIENT_MOCK_BNS_CLIENT_H_

#include <bns-client/bns_client.h>
#include <string.h>

#include "mock_ok_data.h"
#include "mock_register_response.h"

_CHECK_RESULT
char *mock_response_null() { return NULL; }

void mock_save_empty(_UNUSED const receipt_t *receipt) {}

void mock_findPageByClearanceOrderEqualOrLessThan_empty(
    _UNUSED const clearance_order_t clearanceOrder, _UNUSED const size_t page,
    _UNUSED const size_t pageSize, _UNUSED receipt_t *outputReceipt,
    _UNUSED size_t *outputSize) {}

void mock_delete_empty(_UNUSED const receipt_t *receipt) {}

_CHECK_RESULT
receipt_dao_t mock_receipt_dao_empty() {
  receipt_dao_t receiptDao = {
      .save = mock_save_empty,
      .findPageByClearanceOrderEqualOrLessThan =
          mock_findPageByClearanceOrderEqualOrLessThan_empty,
      .delete = mock_delete_empty};
  return receiptDao;
}

void mock_bns_client_ok(bns_client_t *bnsClient) {
  receipt_dao_t receiptDao = mock_receipt_dao_empty();
  http_client_t httpClient = {.get = mock_check_register_response_true,
                              .post = mock_register_response_ok,
                              .eth_post = mock_response_null};
  bns_client_callback_t callback = {0};
  strcpy(bnsClient->bnsServerInfo.contractAddress, MOCK_CONTRACT_ADDRESS_OK);
  strcpy(bnsClient->bnsServerInfo.serverWalletAddress,
         MOCK_SERVER_WALLET_ADDRESS_OK);

  // when
  assert(bns_client_set_retry_delay_sec(bnsClient, 0) == BNS_OK);
  assert(bns_client_set_retry_count(bnsClient, 0) == BNS_OK);
  assert(bns_client_init(bnsClient, MOCK_PRIVATE_KEY_OK,
                         MOCK_INDEX_VALUE_KEY_OK, MOCK_EMAIL_OK,
                         MOCK_SERVER_URL_OK, MOCK_NODE_URL_OK, &receiptDao,
                         &httpClient, &callback) == BNS_OK);
  assert(strcmp(bnsClient->config.privateKey, MOCK_PRIVATE_KEY_OK) == 0);
  assert(strcmp(bnsClient->config.indexValueKey, MOCK_INDEX_VALUE_KEY_OK) == 0);
  assert(strcmp(bnsClient->config.email, MOCK_EMAIL_OK) == 0);
  assert(strcmp(bnsClient->config.serverUrl, MOCK_SERVER_URL_OK) == 0);
  assert(strcmp(bnsClient->config.nodeUrl, MOCK_NODE_URL_OK) == 0);
  assert(strcmp(bnsClient->walletAddress, MOCK_CALLER_ADDRESS_OK) == 0);
  assert(bnsClient->receiptDao.save == receiptDao.save);
  assert(bnsClient->receiptDao.findPageByClearanceOrderEqualOrLessThan ==
         receiptDao.findPageByClearanceOrderEqualOrLessThan);
  assert(bnsClient->receiptDao.delete == receiptDao.delete);
  assert(bnsClient->httpClient.get == httpClient.get);
  assert(bnsClient->httpClient.post == httpClient.post);
  assert(bnsClient->httpClient.eth_post == httpClient.eth_post);
  assert(bnsClient->callback.obtain_ledger_input_response ==
         callback.obtain_ledger_input_response);
}

#endif  // BNS_CLIENT_TEST_SRC_BNS_CLIENT_MOCK_BNS_CLIENT_H_
