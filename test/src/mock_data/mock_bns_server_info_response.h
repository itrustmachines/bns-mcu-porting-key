#ifndef BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_BNS_SERVER_INFO_RESPONSE_H_
#define BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_BNS_SERVER_INFO_RESPONSE_H_

#include <string.h>

_CHECK_RESULT
char *mock_bns_server_info_response_ok() {
  char *string =
      "{\"serverWalletAddress\":"
      "\"0xA197013CA3978962B91f471C4e8C8b6DB42B14D5\",\"contractAddress\":"
      "\"0x1Bbe2D131a42DaEd0110fd2bE08AF56906A5a1Ce\"}";
  char *json = (char *)malloc(sizeof(char) * (strlen(string) + 1));
  strcpy(json, string);
  return json;
}

_CHECK_RESULT
char *mock_bns_server_info_response_server_wallet_address_parse_error() {
  char *string = "{\"status\":\"ok\",\"serverWalletAddress\":200}";
  char *json = (char *)malloc(sizeof(char) * (strlen(string) + 1));
  strcpy(json, string);
  return json;
}

_CHECK_RESULT
char *mock_bns_server_info_response_contract_address_parse_error() {
  char *string =
      "{\"status\":\"ok\",\"serverWalletAddress\":"
      "\"0xA197013CA3978962B91f471C4e8C8b6DB42B14D5\",\"contractAddress\":200}";
  char *json = (char *)malloc(sizeof(char) * (strlen(string) + 1));
  strcpy(json, string);
  return json;
}

#endif  // BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_BNS_SERVER_INFO_RESPONSE_H_
