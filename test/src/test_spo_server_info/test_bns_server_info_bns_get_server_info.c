#include <assert.h>
#include <bns-client/register/bns_server_info.h>

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_bns_server_info_response.h"

void test_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = mock_bns_server_info_response_ok;

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(bns_get_server_info(&bnsClient, &bnsServerInfo) == BNS_OK);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_CLIENT_NULL_ERROR() {
  assert(bns_get_server_info(NULL, NULL) == BNS_CLIENT_NULL_ERROR);
}

void test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  BNS_FREE(bnsClient.config.serverUrl);

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(bns_get_server_info(&bnsClient, &bnsServerInfo) ==
         BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_CLIENT_HTTP_CLIENT_BNS_GET_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = NULL;

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(bns_get_server_info(&bnsClient, &bnsServerInfo) ==
         BNS_CLIENT_HTTP_CLIENT_BNS_GET_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_SERVER_INFO_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);

  // then
  assert(bns_get_server_info(&bnsClient, NULL) == BNS_SERVER_INFO_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_GET_SERVER_INFO_RESPONSE_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = mock_response_null;

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(bns_get_server_info(&bnsClient, &bnsServerInfo) ==
         BNS_GET_SERVER_INFO_RESPONSE_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

int main() {
  test_ok();
  test_BNS_CLIENT_NULL_ERROR();
  test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR();
  test_BNS_SERVER_INFO_NULL_ERROR();
  test_BNS_GET_SERVER_INFO_RESPONSE_NULL_ERROR();
  return 0;
}