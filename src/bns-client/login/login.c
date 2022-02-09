#include <bns-client/login/login.h>
#include <bns-client/util/log.h>
#include <bns-client/util/signature_util.h>
#include <bns-client/util/string_util.h>
#include <bns-client/util/time_util.h>
#include <cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_post_login_url(char** url, const char* const serverUrl) {
  if (!url) { return; }
  size_t size = strlen(serverUrl) + strlen(LEDGER_LOGIN_PATH);
  *url        = (char*)malloc(sizeof(char) * (size + 1));
  if (*url) { sprintf(*url, "%s%s", serverUrl, LEDGER_LOGIN_PATH); }
}

bns_exit_code_t bns_login(const bns_client_t* const bnsClient) {
  bns_exit_code_t exitCode;
  char*           url = NULL;
  char*           res = NULL;
  char*           req = NULL;
  LOG_DEBUG("bns_login() start");

  if (!bnsClient) {
    exitCode = BNS_CLIENT_NULL_ERROR;
    goto bns_login_fail;
  }
  build_post_login_url(&url, bnsClient->config.serverUrl);
  if (!url) {
    exitCode = BNS_LOGIN_URL_NULL_ERROR;
    goto bns_login_fail;
  }

  if ((exitCode = build_login_request_json(bnsClient, &req)) != BNS_OK) {
    goto bns_login_fail;
  }

  res = bnsClient->httpClient.post(url, req);
  if (!res) {
    exitCode = BNS_LOGIN_RESPONSE_NULL_ERROR;
    goto bns_login_fail;
  }

  if ((exitCode = check_login_response(res, bnsClient->walletAddress)) !=
      BNS_OK) {
    goto bns_login_fail;
  }
  BNS_FREE(url);
  BNS_FREE(req);
  BNS_FREE(res);

  LOG_DEBUG("bns_login() end");
  return exitCode;

bns_login_fail:
  if (url) { BNS_FREE(url); }
  if (res) { BNS_FREE(res); }
  if (req) { BNS_FREE(req); }

  LOG_ERROR("bns_login() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t build_login_request_json(const bns_client_t* bnsClient,
                                         char**              reqJson) {
  LOG_DEBUG("build_login_request_json() start");
  login_request_t req = {0};
  bns_exit_code_t exitCode;
  if (!bnsClient) {
    exitCode = BNS_CLIENT_NULL_ERROR;
    goto build_login_request_json_fail;
  }
  if ((exitCode = build_login_request(bnsClient, &req)) != BNS_OK) {
    goto build_login_request_json_fail;
  }
  if ((exitCode = login_request_sign(&req, bnsClient->config.privateKey)) !=
      BNS_OK) {
    goto build_login_request_json_fail;
  }
  if ((exitCode = login_request_to_json(&req, reqJson)) != BNS_OK) {
    goto build_login_request_json_fail;
  }
  login_request_free(&req);
  return exitCode;
build_login_request_json_fail:
  login_request_free(&req);
  LOG_ERROR("build_login_request_json() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t build_login_request(const bns_client_t* const bnsClient,
                                    login_request_t* const    req) {
  bns_exit_code_t exitCode = BNS_OK;
  if (!bnsClient) {
    exitCode = BNS_CLIENT_NULL_ERROR;
    goto build_login_request_fail;
  }
  if (!req) {
    exitCode = BNS_LOGIN_REQUEST_NULL_ERROR;
    goto build_login_request_fail;
  }
  LOG_DEBUG("build_LOGIN_request() begin");

  strcpy(req->callerAddress, bnsClient->walletAddress);
  size_t size = strlen(LOGIN_MESSAGE_STR_PART1);
  size += strlen(LOGIN_MESSAGE_STR_PART2);
  req->toSignMessage =
      (char*)malloc(sizeof(char) * (size + ADDRESS_0X_STR_LEN + 16));

  char* timestamp = get_timestamp_string();
  sprintf(req->toSignMessage, "%s%s%s%s.", LOGIN_MESSAGE_STR_PART1,
          bnsClient->walletAddress, LOGIN_MESSAGE_STR_PART2, timestamp);
  BNS_FREE(timestamp);
  LOG_DEBUG("build_LOGIN_request() end, " LOGIN_REQUEST_PRINT_FORMAT,
            LOGIN_REQUEST_TO_PRINT_ARGS(req));
  return exitCode;

build_login_request_fail:
  login_request_free(req);
  LOG_ERROR("build_LOGIN_request() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t login_request_sign(login_request_t* const req,
                                   const char* const      privateKey) {
  bns_exit_code_t exitCode;
  char*           buffer = NULL;
  if (!req || !req->toSignMessage || strlen(req->callerAddress) == 0) {
    exitCode = BNS_LOGIN_REQUEST_NULL_ERROR;
    goto login_request_sign_fail;
  }
  if (!privateKey) {
    exitCode = BNS_PRIVATE_KEY_NULL_ERROR;
    goto login_request_sign_fail;
  }
  LOG_DEBUG("login_request_sign() begin, " LOGIN_REQUEST_PRINT_FORMAT,
            LOGIN_REQUEST_TO_PRINT_ARGS(req));
  size_t size = 0;
  size += strlen(req->toSignMessage);
  buffer = (char*)malloc(sizeof(char) * (size + 1));
  strcpy(buffer, req->toSignMessage);

  unsigned char shaResult[SHA3_BYTE_LEN] = {0};
  bns_sha3_prefix((unsigned char*)buffer, size, shaResult);
  BNS_FREE(buffer);
  if ((exitCode = bns_sign(shaResult, privateKey, &req->sig)) != BNS_OK) {
    goto login_request_sign_fail;
  }
  LOG_DEBUG("login_request_sign() end, " LOGIN_REQUEST_PRINT_FORMAT,
            LOGIN_REQUEST_TO_PRINT_ARGS(req));
  return exitCode;

login_request_sign_fail:
  LOG_ERROR("login_request_sign() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t login_request_to_json(const login_request_t* const loginRequest,
                                      char** const                 json) {
  LOG_DEBUG("login_request_to_json() begin");
  bns_exit_code_t exitCode = BNS_OK;
  cJSON*          root     = NULL;
  if (!loginRequest || strlen(loginRequest->callerAddress) == 0 ||
      !loginRequest->toSignMessage) {
    exitCode = BNS_LOGIN_REQUEST_NULL_ERROR;
    goto login_request_to_json_fail;
  }
  if (!json) {
    exitCode = BNS_LOGIN_REQUEST_JSON_NULL_ERROR;
    goto login_request_to_json_fail;
  }
  root       = cJSON_CreateObject();
  cJSON* sig = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "address",
                        cJSON_CreateString(loginRequest->callerAddress));
  cJSON_AddItemToObject(root, "toSignMessage",
                        cJSON_CreateString(loginRequest->toSignMessage));
  cJSON_AddItemToObject(root, "sig", sig);
  cJSON_AddItemToObject(sig, "r", cJSON_CreateString(loginRequest->sig.r));
  cJSON_AddItemToObject(sig, "s", cJSON_CreateString(loginRequest->sig.s));
  cJSON_AddItemToObject(sig, "v", cJSON_CreateString(loginRequest->sig.v));
  if (*json) { BNS_FREE(*json); }
  *json = cJSON_PrintUnformatted(root);
  cJSON_Delete(root);
  LOG_DEBUG("login_request_to_json() end, json=%s", *json);
  return exitCode;

login_request_to_json_fail:
  cJSON_Delete(root);
  LOG_ERROR("login_request_to_json() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

void login_request_free(login_request_t* const loginRequest) {
  if (loginRequest) {
    if (loginRequest->toSignMessage) { BNS_FREE(loginRequest->toSignMessage); }
    if (loginRequest->toSignMessage) { BNS_FREE(loginRequest->toSignMessage); }
  }
}

bns_exit_code_t check_login_response(const char* const res,
                                     const char* const walletAddress) {
  LOG_DEBUG("check_login_response() begin");
  bns_exit_code_t exitCode = BNS_OK;
  cJSON*          root     = cJSON_Parse(res);
  cJSON*          address;
  address = cJSON_GetObjectItem(root, "address");
  if (!cJSON_IsString(address)) {
    exitCode = BNS_RESPONSE_STATUS_PARSE_ERROR;
    goto check_login_response_fail;
  }

  if (bns_equals_ignore_case(walletAddress, address->valuestring) == false) {
    exitCode = BNS_LOGIN_WARN;
    LOG_WARN(
        "check_login_response() "
        "warn, " BNS_EXIT_CODE_PRINT_FORMAT,
        bns_strerror(exitCode));

    goto check_login_response_fail;
  }
  cJSON_Delete(root);
  LOG_DEBUG("check_login_response() end");
  return exitCode;

check_login_response_fail:
  cJSON_Delete(root);
  LOG_ERROR(
      "check_login_response() "
      "error, " BNS_EXIT_CODE_PRINT_FORMAT,
      bns_strerror(exitCode));
  return exitCode;
}
