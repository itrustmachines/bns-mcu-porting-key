#include <assert.h>
#include <bns-client/bns_client.h>
#include <bns-client/register/bns_server_info.h>
#include <bns-client/util/log.h>
#include <bns-client/util/string_util.h>
#include <string.h>

#include "mock_data/mock_bns_client.h"

static int retryCount = 5;

char *mock_http_get_ok() {
  char *json = NULL;
  bns_strdup(&json, MOCK_BNS_SERVER_INFO_RESPONSE_OK);
  return json;
}

char *mock_response_retry() {
  if (--retryCount > 0) {
    return NULL;
  } else {
    return mock_http_get_ok();
  }
}

void test_ok() {
  LOG_DEBUG("test_ok() begin");
  int res;
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bns_server_info_t outputSpoServerInfo = {0};
  bnsClient.httpClient.post = mock_http_get_ok;

  res = bns_post_server_info(&bnsClient, &outputSpoServerInfo);
  assert(res == BNS_OK);
  assert(strcmp(MOCK_CONTRACT_ADDRESS_OK,
                outputSpoServerInfo.contractAddress) == 0);
  assert(strcmp(MOCK_SERVER_WALLET_ADDRESS_OK,
                outputSpoServerInfo.serverWalletAddress) == 0);

  bns_client_free(&bnsClient);
  LOG_DEBUG("test_ok() end");
}

void test_retry() {
  LOG_DEBUG("test_retry() begin");

  // given
  int res;
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_response_retry;
  assert(bns_client_set_retry_count(&bnsClient, retryCount) == BNS_OK);

  // when
  bns_server_info_t bnsServerInfo = {0};
  res = bns_post_server_info(&bnsClient, &bnsServerInfo);

  // then
  if (res != BNS_OK) {
    LOG_ERROR("test_retry() error, " BNS_EXIT_CODE_PRINT_FORMAT,
              bns_strerror(res));
  }
  assert(retryCount == 0);
  assert(res == BNS_OK);
  assert(strcmp(MOCK_CONTRACT_ADDRESS_OK, bnsServerInfo.contractAddress) == 0);
  assert(strcmp(MOCK_SERVER_WALLET_ADDRESS_OK,
                bnsServerInfo.serverWalletAddress) == 0);

  // clean
  bns_client_free(&bnsClient);
  LOG_DEBUG("test_retry() end");
}

int main() {
  test_ok();
  test_retry();
  return 0;
}
