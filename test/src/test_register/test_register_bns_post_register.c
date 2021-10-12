#include <assert.h>
#include <bns-client/register/register.h>

#include "../mock_data/mock_bns_client.h"

void test_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);

  // then
  assert(bns_post_register(&bnsClient) == BNS_OK);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_CLIENT_NULL_ERROR() {
  assert(bns_post_register(NULL) == BNS_CLIENT_NULL_ERROR);
}

void test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  BNS_FREE(bnsClient.config.serverUrl);

  // then
  assert(bns_post_register(&bnsClient) ==
         BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = NULL;

  // then
  assert(bns_post_register(&bnsClient) ==
         BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

void test_BNS_POST_REGISTER_RESPONSE_NULL_ERROR() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_response_null;

  // then
  assert(bns_post_register(&bnsClient) ==
         BNS_POST_REGISTER_RESPONSE_NULL_ERROR);

  // clean
  bns_client_free(&bnsClient);
}

int main() {
  test_ok();
  test_BNS_CLIENT_NULL_ERROR();
  test_BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR();
  test_BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR();
  test_BNS_POST_REGISTER_RESPONSE_NULL_ERROR();
  return 0;
}