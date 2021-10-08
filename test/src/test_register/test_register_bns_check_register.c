#include <assert.h>
#include <bns-client/register/register.h>

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_register_response.h"

void test_true() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = mock_check_register_response_true;

  // then
  bool result = false;
  assert(bns_check_register(&bnsClient, &result) == BNS_OK);
  assert(result == true);

  // clean
  bns_client_free(&bnsClient);
}

void test_false() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.get = mock_check_register_response_false;

  // then
  bool result = false;
  assert(bns_check_register(&bnsClient, &result) == BNS_OK);
  assert(result == false);

  // clean
  bns_client_free(&bnsClient);
}

int main() {
  test_true();
  test_false();
  return 0;
}