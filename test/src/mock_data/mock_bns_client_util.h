#ifndef BNS_C_CLIENT_TEST_SRC_MOCK_DATA_UTIL_MOCK_BNS_CLIENT_UTIL_H_
#define BNS_C_CLIENT_TEST_SRC_MOCK_DATA_UTIL_MOCK_BNS_CLIENT_UTIL_H_

#include <bns-client/bns_client.h>
#include <bns-client/util/string_util.h>
#include <string.h>

#include "mock_ok_data.h"

_CHECK_RESULT
int mock_get_bns_client_(bns_client_t* bnsClient,
                         char* (*httpGetMethod)(const char* const)) {
  http_client_t httpClient = {.get = httpGetMethod};
  bnsClient->httpClient    = httpClient;
  bns_strdup(&bnsClient->config.serverUrl, MOCK_SERVER_URL_OK);
  bns_strdup(&bnsClient->config.nodeUrl, MOCK_NODE_URL_OK);
  strcpy(bnsClient->config.privateKey, MOCK_PRIVATE_KEY_OK);
  bns_strdup(&bnsClient->config.indexValueKey, MOCK_INDEX_VALUE_KEY_OK);
  strcpy(bnsClient->bnsServerInfo.serverWalletAddress,
         MOCK_SERVER_WALLET_ADDRESS_OK);
  strcpy(bnsClient->bnsServerInfo.contractAddress, MOCK_CONTRACT_ADDRESS_OK);
  return BNS_OK;
}

_CHECK_RESULT
int mock_post_bns_client(bns_client_t* bnsClient,
                         char* (*httpPostMethod)(const char* const,
                                                 const char* const)) {
  http_client_t httpClient = {.post     = httpPostMethod,
                              .eth_post = httpPostMethod};
  bnsClient->httpClient    = httpClient;
  bns_strdup(&bnsClient->config.serverUrl,
             "https://azure-rc-rinkeby.itm.monster:4430/");
  bns_strdup(&bnsClient->config.nodeUrl,
             "https://rinkeby.infura.io/v3/be24c2d510194112af26339c777c46d1");
  strcpy(bnsClient->config.privateKey,
         "5a5a735424663f0ae086debe6c12b10893952f272bd0c1793bf8b5372a18a913");
  bns_strdup(&bnsClient->config.indexValueKey, "NUVOTON_Demo");
  strcpy(bnsClient->bnsServerInfo.serverWalletAddress,
         "0x6ceE2EF1264d99cf09ce692d0b4d03d7bD76f9f9");
  strcpy(bnsClient->bnsServerInfo.contractAddress,
         "0x99c2a52d230074984b148995A89Fa9BF1dD0aab8");
  return BNS_OK;
}

#endif  // BNS_C_CLIENT_TEST_SRC_MOCK_DATA_UTIL_MOCK_BNS_CLIENT_UTIL_H_
