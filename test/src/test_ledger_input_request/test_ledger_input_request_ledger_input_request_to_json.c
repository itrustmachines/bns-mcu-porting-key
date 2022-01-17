#include <assert.h>
#include <bns-client/input/ledger_input_request.h>
#include <bns-client/util/time_util.h>
#include <cJSON.h>

#include "../mock_data/mock_ledger_input_request.h"

void test_ok() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);

  // then
  char* result = NULL;
  assert(ledger_input_request_to_json(&ledgerInputRequest, &result) == BNS_OK);
  cJSON* temp;
  cJSON* root = cJSON_Parse(result);
  assert(root);
  temp = cJSON_GetObjectItem(root, "callerAddress");
  assert(temp);
  assert(strcmp(temp->valuestring, MOCK_CALLER_ADDRESS_OK) == 0);
  temp = cJSON_GetObjectItem(root, "timestamp");
  assert(temp->valueint <= get_timestamp());
  temp = cJSON_GetObjectItem(root, "cmd");
  assert(strcmp(temp->valuestring, MOCK_CMD_OK) == 0);
  temp = cJSON_GetObjectItem(root, "indexValue");
  assert(strcmp(temp->valuestring, MOCK_INDEX_VALUE_OK) == 0);
  temp = cJSON_GetObjectItem(root, "metadata");
  assert(strcmp(temp->valuestring, MOCK_METADATA_OK) == 0);
  temp = cJSON_GetObjectItem(root, "clearanceOrder");
  assert(temp->valueint == MOCK_CLEARANCE_ORDER_OK);
  cJSON* sigClient = cJSON_GetObjectItem(root, "sigClient");
  temp             = cJSON_GetObjectItem(sigClient, "r");
  assert(strlen(temp->valuestring) > 0);
  temp = cJSON_GetObjectItem(sigClient, "s");
  assert(strlen(temp->valuestring) > 0);
  temp = cJSON_GetObjectItem(sigClient, "v");
  assert(strlen(temp->valuestring) > 0);

  // clean
  cJSON_Delete(root);
  ledger_input_request_free(&ledgerInputRequest);
  if (result) { BNS_FREE(result); }
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_1() {
  char* result = NULL;
  assert(ledger_input_request_to_json(NULL, &result) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_2() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);
  BNS_FREE(ledgerInputRequest.cmd);

  // then
  char* result = NULL;
  assert(ledger_input_request_to_json(&ledgerInputRequest, &result) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_3() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);
  BNS_FREE(ledgerInputRequest.indexValue);

  // then
  char* result = NULL;
  assert(ledger_input_request_to_json(&ledgerInputRequest, &result) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_4() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);
  BNS_FREE(ledgerInputRequest.metadata);

  // then
  char* result = NULL;
  assert(ledger_input_request_to_json(&ledgerInputRequest, &result) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_LEDGER_INPUT_REQUEST_JSON_NULL_ERROR() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);

  // then
  assert(ledger_input_request_to_json(&ledgerInputRequest, NULL) ==
         BNS_LEDGER_INPUT_REQUEST_JSON_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

int main() {
  test_ok();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_1();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_2();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_3();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_4();
  test_BNS_LEDGER_INPUT_REQUEST_JSON_NULL_ERROR();
  return 0;
}