#include <assert.h>
#include <bns-client/input/ledger_input_request.h>
#include <bns-client/input/receipt_locator.h>
#include <bns-client/util/time_util.h>
#include <cJSON.h>

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_receipt_locator.h"

void test_ok() {
  // given
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  receipt_locator_t receiptLocator = {0};
  mock_receipt_locator_ok(&receiptLocator);

  // then
  char* result = NULL;
  assert(build_ledger_input_request_json(&bnsClient, MOCK_CMD_OK,
                                         &receiptLocator, &result) == BNS_OK);
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
  bns_client_free(&bnsClient);
  receipt_locator_free(&receiptLocator);
  cJSON_Delete(root);
  if (result) { BNS_FREE(result); }
}

void test_BNS_CLIENT_NULL_ERROR() {
  receipt_locator_t receiptLocator = {0};
  char*             result         = NULL;
  assert(build_ledger_input_request_json(NULL, MOCK_CMD_OK, &receiptLocator,
                                         &result) == BNS_CLIENT_NULL_ERROR);
}

void test_BNS_CMD_JSON_NULL_ERROR() {
  bns_client_t      bnsClient      = {0};
  receipt_locator_t receiptLocator = {0};
  char*             result         = NULL;
  assert(build_ledger_input_request_json(&bnsClient, NULL, &receiptLocator,
                                         &result) == BNS_CMD_JSON_NULL_ERROR);
}

void test_BNS_RECEIPT_LOCATOR_NULL_ERROR() {
  bns_client_t bnsClient = {0};
  char*        result    = NULL;
  assert(build_ledger_input_request_json(&bnsClient, NULL, NULL, &result) ==
         BNS_CMD_JSON_NULL_ERROR);
}

void test_BNS_LEDGER_INPUT_REQUEST_JSON_NULL_ERROR() {
  bns_client_t      bnsClient      = {0};
  receipt_locator_t receiptLocator = {0};
  assert(build_ledger_input_request_json(&bnsClient, NULL, &receiptLocator,
                                         NULL) == BNS_CMD_JSON_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_CLIENT_NULL_ERROR();
  test_BNS_CMD_JSON_NULL_ERROR();
  test_BNS_RECEIPT_LOCATOR_NULL_ERROR();
  test_BNS_LEDGER_INPUT_REQUEST_JSON_NULL_ERROR();
  return 0;
}