#include <bns-client/register/bns_server_info.h>
#include <bns-client/util/log.h>
#include <bns-client/util/signature_util.h>
#include <cJSON.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *build_get_bns_server_info_url(char *serverUrl) {
  if (!serverUrl) {
    return NULL;
  }
  const size_t size = strlen(serverUrl) + strlen(LEDGER_BNS_SERVER_INFO_PATH);
  char *url = (char *)malloc(sizeof(char) * (size + 1));
  if (url) {
    sprintf(url, "%s%s", serverUrl, LEDGER_BNS_SERVER_INFO_PATH);
  }
  return url;
}

bns_exit_code_t bns_post_server_info(const bns_client_t *const bnsClient,
                                     bns_server_info_t *const bnsServerInfo) {
  size_t count = 0;
bns_get_server_info_beg:
  LOG_INFO("bns_post_server_info() begin");
  bns_exit_code_t exitCode;
  char *reqJson = NULL;
  char *url = NULL;
  char *res = NULL;

  if (!bnsClient) {
    exitCode = BNS_CLIENT_NULL_ERROR;
    goto bns_get_server_info_fail;
  }
  if (!bnsClient->config.serverUrl) {
    exitCode = BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR;
    goto bns_get_server_info_fail;
  }
  if (!bnsClient->httpClient.post) {
    exitCode = BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR;
    goto bns_get_server_info_fail;
  }
  if (!bnsServerInfo) {
    exitCode = BNS_SERVER_INFO_NULL_ERROR;
    goto bns_get_server_info_fail;
  }

  url = build_get_bns_server_info_url(bnsClient->config.serverUrl);
  if (!url) {
    exitCode = BNS_GET_SERVER_INFO_URL_NULL_ERROR;
    goto bns_get_server_info_fail;
  }

  if ((exitCode = build_server_info_request(
           bnsClient->walletAddress, bnsClient->config.privateKey, &reqJson)) !=
      BNS_OK) {
    goto bns_get_server_info_fail;
  }

  res = bnsClient->httpClient.post(url, reqJson);
  if (!res) {
    exitCode = BNS_GET_SERVER_INFO_RESPONSE_NULL_ERROR;
    goto bns_get_server_info_fail;
  }
  BNS_FREE(url);
  BNS_FREE(reqJson);

  exitCode = check_and_parse_bns_server_info_response(res, bnsServerInfo);
  if (exitCode != BNS_OK) {
    goto bns_get_server_info_fail;
  }

  BNS_FREE(res);

  LOG_INFO("bns_post_server_info() end, " BNS_SERVER_INFO_PRINT_FORMAT,
           BNS_SERVER_INFO_TO_PRINT_ARGS(bnsServerInfo));
  return exitCode;

bns_get_server_info_fail:
  if (url) {
    BNS_FREE(url);
  }
  if (res) {
    BNS_FREE(res);
  }
  if (reqJson) {
    BNS_FREE(reqJson);
  }
  LOG_ERROR("bns_post_server_info() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  if (bnsClient && bnsClient->maxRetryCount) {
    if (count++ < *bnsClient->maxRetryCount) {
      LOG_DEBUG("bns_post_server_info() retry, count=%ld", count);
      if (bnsClient->retryDelaySec) {
        sleep(*bnsClient->retryDelaySec);
      }
      goto bns_get_server_info_beg;
    }
  }
  return exitCode;
}

bns_exit_code_t build_server_info_request(const char *const address,
                                          const char *const privateKey,
                                          char **const json) {
  LOG_DEBUG("build_server_info_request() begin");
  bns_exit_code_t exitCode = BNS_OK;
  cJSON *root = NULL;

  if (!address) {
    exitCode = BNS_ADDRESS_NULL_ERROR;
    goto build_server_info_request_fail;
  }
  if (!privateKey) {
    exitCode = BNS_PRIVATE_KEY_NULL_ERROR;
    goto build_server_info_request_fail;
  }
  if (!json) {
    exitCode = BNS_SERVER_INFO_REQUEST_JSON_NULL_ERROR;
    goto build_server_info_request_fail;
  }

  char *toSignMessage = "serverInfo";

  unsigned char shaResult[SHA3_BYTE_LEN] = {0};
  bns_sha3((unsigned char *)toSignMessage, strlen(toSignMessage), shaResult);
  sig_t sig = {0};
  exitCode = bns_sign(shaResult, privateKey, &sig);
  if (exitCode != BNS_OK) {
    goto build_server_info_request_fail;
  }

  root = cJSON_CreateObject();
  cJSON *sig_item = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "address", cJSON_CreateString(address));
  cJSON_AddItemToObject(root, "toSignMessage",
                        cJSON_CreateString(toSignMessage));
  cJSON_AddItemToObject(root, "sig", sig_item);
  cJSON_AddItemToObject(sig_item, "r", cJSON_CreateString(sig.r));
  cJSON_AddItemToObject(sig_item, "s", cJSON_CreateString(sig.s));
  cJSON_AddItemToObject(sig_item, "v", cJSON_CreateString(sig.v));
  *json = cJSON_PrintUnformatted(root);
  cJSON_Delete(root);

  LOG_DEBUG("build_server_info_request() end");
  return exitCode;

build_server_info_request_fail:
  cJSON_Delete(root);
  LOG_ERROR(
      "build_server_info_request() "
      "error, " BNS_EXIT_CODE_PRINT_FORMAT,
      bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t check_and_parse_bns_server_info_response(
    const char *const res, bns_server_info_t *const bnsServerInfo) {
  LOG_DEBUG("check_and_parse_bns_server_info_response() begin");
  bns_exit_code_t exitCode = BNS_OK;
  cJSON *root = NULL;
  cJSON *temp = NULL;

  if (!bnsServerInfo) {
    exitCode = BNS_SERVER_INFO_NULL_ERROR;
    goto check_bns_server_info_response_fail;
  }

  root = cJSON_Parse(res);
  temp = cJSON_GetObjectItem(root, "serverWalletAddress");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_SERVER_WALLET_ADDRESS_PARSE_ERROR;
    goto check_bns_server_info_response_fail;
  }
  strncpy(bnsServerInfo->serverWalletAddress, temp->valuestring,
          ADDRESS_0X_STR_LEN - 1);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "contractAddress");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_CONTRACT_ADDRESS_PARSE_ERROR;
    goto check_bns_server_info_response_fail;
  }
  strncpy(bnsServerInfo->contractAddress, temp->valuestring,
          ADDRESS_0X_STR_LEN - 1);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);
  cJSON_Delete(root);
  LOG_DEBUG(
      "check_and_parse_bns_server_info_response() "
      "end, " BNS_SERVER_INFO_PRINT_FORMAT,
      BNS_SERVER_INFO_TO_PRINT_ARGS(bnsServerInfo));
  return exitCode;

check_bns_server_info_response_fail:
  cJSON_Delete(root);
  LOG_ERROR(
      "check_and_parse_bns_server_info_response() "
      "error, " BNS_EXIT_CODE_PRINT_FORMAT,
      bns_strerror(exitCode));
  return exitCode;
}
