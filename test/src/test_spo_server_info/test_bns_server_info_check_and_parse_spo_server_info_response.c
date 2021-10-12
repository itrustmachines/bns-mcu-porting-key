#include <assert.h>
#include <bns-client/register/bns_server_info.h>

#include "../mock_data/mock_bns_server_info_response.h"

void test_ok() {
  // given
  char *res = mock_bns_server_info_response_ok();

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(check_and_parse_bns_server_info_response(res, &bnsServerInfo) ==
         BNS_OK);

  // clean
  BNS_FREE(res);
}

void test_BNS_SERVER_INFO_NULL_ERROR() {
  // then
  assert(check_and_parse_bns_server_info_response("", NULL) ==
         BNS_SERVER_INFO_NULL_ERROR);
}

void test_BNS_RESPONSE_SERVER_WALLET_ADDRESS_PARSE_ERROR() {
  // given
  char *res = mock_bns_server_info_response_server_wallet_address_parse_error();

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(check_and_parse_bns_server_info_response(res, &bnsServerInfo) ==
         BNS_RESPONSE_SERVER_WALLET_ADDRESS_PARSE_ERROR);

  // clean
  BNS_FREE(res);
}

void test_BNS_RESPONSE_CONTRACT_ADDRESS_PARSE_ERROR() {
  // given
  char *res = mock_bns_server_info_response_contract_address_parse_error();

  // then
  bns_server_info_t bnsServerInfo = {0};
  assert(check_and_parse_bns_server_info_response(res, &bnsServerInfo) ==
         BNS_RESPONSE_CONTRACT_ADDRESS_PARSE_ERROR);

  // clean
  BNS_FREE(res);
}

int main() {
  test_ok();
  test_BNS_SERVER_INFO_NULL_ERROR();
  test_BNS_RESPONSE_SERVER_WALLET_ADDRESS_PARSE_ERROR();
  test_BNS_RESPONSE_CONTRACT_ADDRESS_PARSE_ERROR();
  return 0;
}