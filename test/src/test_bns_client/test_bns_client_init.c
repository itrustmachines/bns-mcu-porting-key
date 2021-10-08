#include <assert.h>
#include <bns-client/bns_client.h>
#include <bns-client/util/log.h>

#include "../mock_data/mock_bns_client.h"

void test_ok() {
  LOG_DEBUG("test_ok() begin");
  // given
  receipt_dao_t receiptDao = mock_receipt_dao_empty();
  http_client_t httpClient = {.get = mock_check_register_response_true,
                              .post = mock_register_response_ok,
                              .eth_post = mock_response_null};
  bns_client_callback_t callback = {0};
  bns_client_t bnsClient = {0};
  strcpy(bnsClient.bnsServerInfo.contractAddress, MOCK_CONTRACT_ADDRESS_OK);
  strcpy(bnsClient.bnsServerInfo.serverWalletAddress,
         MOCK_SERVER_WALLET_ADDRESS_OK);

  // when
  int res =
      bns_client_init(&bnsClient, MOCK_PRIVATE_KEY_OK, MOCK_INDEX_VALUE_KEY_OK,
                      MOCK_EMAIL_OK, MOCK_SERVER_URL_OK, MOCK_NODE_URL_OK,
                      &receiptDao, &httpClient, &callback);

  // then
  assert(res == BNS_OK);
  assert(strcmp(bnsClient.config.privateKey, MOCK_PRIVATE_KEY_OK) == 0);
  assert(strcmp(bnsClient.config.indexValueKey, MOCK_INDEX_VALUE_KEY_OK) == 0);
  assert(strcmp(bnsClient.config.serverUrl, MOCK_SERVER_URL_OK) == 0);
  assert(strcmp(bnsClient.config.nodeUrl, MOCK_NODE_URL_OK) == 0);
  assert(strcmp(bnsClient.walletAddress, MOCK_CALLER_ADDRESS_OK) == 0);
  assert(bnsClient.receiptDao.save == receiptDao.save);
  assert(bnsClient.receiptDao.findPageByClearanceOrderEqualOrLessThan ==
         receiptDao.findPageByClearanceOrderEqualOrLessThan);
  assert(bnsClient.receiptDao.delete == receiptDao.delete);
  assert(bnsClient.httpClient.get == httpClient.get);
  assert(bnsClient.httpClient.post == httpClient.post);
  assert(bnsClient.httpClient.eth_post == httpClient.eth_post);
  assert(bnsClient.callback.obtain_ledger_input_response ==
         callback.obtain_ledger_input_response);

  // clean
  bns_client_free(&bnsClient);
  LOG_DEBUG("test_ok() end");
}

void test_bns_client_null_error() {
  LOG_DEBUG("test_bns_client_null_error() begin");
  int res;

  // given
  bns_client_t *bnsClient = NULL;

  // when
  res = bns_client_init(bnsClient, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                        NULL);

  // then
  assert(res == BNS_CLIENT_NULL_ERROR);

  LOG_DEBUG("test_bns_client_null_error() end");
}

void test_private_key_null_error() {
  LOG_DEBUG("test_private_key_null_error() begin");
  int res;

  // given
  bns_client_t bnsClient = {0};

  // when
  res = bns_client_init(&bnsClient, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                        NULL);

  // then
  assert(res == BNS_PRIVATE_KEY_NULL_ERROR);

  LOG_DEBUG("test_private_key_null_error() end");
}

void test_index_value_key_null_error() {
  LOG_DEBUG("test_index_value_key_null_error() begin");
  int res;

  // given
  bns_client_t bnsClient = {0};

  // when
  res = bns_client_init(&bnsClient, MOCK_PRIVATE_KEY_OK, NULL, NULL, NULL, NULL,
                        NULL, NULL, NULL);

  // then
  assert(res == BNS_INDEX_VALUE_KEY_NULL_ERROR);

  LOG_DEBUG("test_index_value_key_null_error() end");
}

void test_email_null_error() {
  LOG_DEBUG("test_email_null_error() begin");
  int res;

  // given
  bns_client_t bnsClient = {0};

  // when
  res =
      bns_client_init(&bnsClient, MOCK_PRIVATE_KEY_OK, MOCK_INDEX_VALUE_KEY_OK,
                      NULL, NULL, NULL, NULL, NULL, NULL);

  // then
  assert(res == BNS_EMAIL_NULL_ERROR);

  LOG_DEBUG("test_email_null_error() end");
}

void test_server_url_null_error() {
  LOG_DEBUG("test_server_url_null_error() begin");
  int res;

  // given
  bns_client_t bnsClient = {0};

  // when
  res =
      bns_client_init(&bnsClient, MOCK_PRIVATE_KEY_OK, MOCK_INDEX_VALUE_KEY_OK,
                      MOCK_EMAIL_OK, NULL, NULL, NULL, NULL, NULL);

  // then
  assert(res == BNS_SERVER_URL_NULL_ERROR);

  LOG_DEBUG("test_server_url_null_error() end");
}

void test_node_url_null_error() {
  LOG_DEBUG("test_node_url_null_error() begin");
  int res;

  // given
  bns_client_t bnsClient = {0};

  // when
  res = bns_client_init(&bnsClient, MOCK_PRIVATE_KEY_OK,
                        MOCK_INDEX_VALUE_KEY_OK, MOCK_EMAIL_OK,
                        MOCK_SERVER_URL_OK, NULL, NULL, NULL, NULL);

  // then
  assert(res == BNS_NODE_URL_NULL_ERROR);

  LOG_DEBUG("test_node_url_null_error() end");
}

void test_receipt_dao_null_error() {
  LOG_DEBUG("test_receipt_dao_null_error() begin");
  int res;

  // given
  bns_client_t bnsClient = {0};

  // when
  res = bns_client_init(&bnsClient, MOCK_PRIVATE_KEY_OK,
                        MOCK_INDEX_VALUE_KEY_OK, MOCK_EMAIL_OK,
                        MOCK_SERVER_URL_OK, MOCK_NODE_URL_OK, NULL, NULL, NULL);

  // then
  assert(res == BNS_RECEIPT_DAO_NULL_ERROR);

  LOG_DEBUG("test_receipt_dao_null_error() end");
}

void test_http_client_null_error() {
  LOG_DEBUG("test_http_client_null_error() begin");
  int res;

  // given
  receipt_dao_t receiptDao = mock_receipt_dao_empty();
  bns_client_t bnsClient = {0};

  // when
  res = bns_client_init(
      &bnsClient, MOCK_PRIVATE_KEY_OK, MOCK_INDEX_VALUE_KEY_OK, MOCK_EMAIL_OK,
      MOCK_SERVER_URL_OK, MOCK_NODE_URL_OK, &receiptDao, NULL, NULL);

  // then
  assert(res == BNS_CLIENT_HTTP_CLIENT_NULL_ERROR);

  LOG_DEBUG("test_http_client_null_error() end");
}

void test_bns_client_callback_null_ok() {
  LOG_DEBUG("test_bns_client_callback_null_ok() begin");
  int res;

  // given
  receipt_dao_t receiptDao = mock_receipt_dao_empty();
  http_client_t httpClient = {.get = mock_check_register_response_true,
                              .post = mock_register_response_ok,
                              .eth_post = mock_response_null};
  bns_client_t bnsClient = {0};
  strcpy(bnsClient.bnsServerInfo.contractAddress, MOCK_CONTRACT_ADDRESS_OK);
  strcpy(bnsClient.bnsServerInfo.serverWalletAddress,
         MOCK_SERVER_WALLET_ADDRESS_OK);

  // when
  res = bns_client_init(
      &bnsClient, MOCK_PRIVATE_KEY_OK, MOCK_INDEX_VALUE_KEY_OK, MOCK_EMAIL_OK,
      MOCK_SERVER_URL_OK, MOCK_NODE_URL_OK, &receiptDao, &httpClient, NULL);

  // then
  assert(res == BNS_OK);

  // clean
  bns_client_free(&bnsClient);
  LOG_DEBUG("test_bns_client_callback_null_ok() end");
}

int main(void) {
  test_ok();
  test_bns_client_null_error();
  test_private_key_null_error();
  test_index_value_key_null_error();
  test_email_null_error();
  test_server_url_null_error();
  test_node_url_null_error();
  test_receipt_dao_null_error();
  test_http_client_null_error();
  test_bns_client_callback_null_ok();
  return 0;
}
