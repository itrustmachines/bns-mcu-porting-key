#include <assert.h>
#include <bns-client/contract/clearance_record_cache.h>
#include <bns-client/contract/contract.h>
#include <bns-client/core/core.h>

#include "mock_data/mock_bns_client_util.h"
#include "mock_data/mock_clearance_record_response.h"

static int retryCount = 5;

char *mock_response_retry(_UNUSED const char *const s1,
                          _UNUSED const char *const s2) {
  if (--retryCount > 0) {
    return NULL;
  } else {
    return mock_clearance_record_response_ok(s1, s2);
  }
}

void test_create_clearance_record_function_instruction() {
  long long int co = 2147483648L;
  char *solution =
      "0x6b30ad2300000000000000000000000000000000000000000000000000000000800000"
      "00";
  char *instruction = NULL;
  assert(build_clearance_record_contract_instruction(co, &instruction) ==
         BNS_OK);
  assert(strcmp(solution, instruction) == 0);
  BNS_FREE(instruction);
}

void test_create_contract_request_message() {
  char *instruction =
      "0x6b30ad230000000000000000000000000000000000000000000000000000000000005d"
      "11";
  char *contractAddress = "1Bbe2D131a42DaEd0110fd2bE08AF56906A5a1Ce";

  char *request = NULL;
  assert(build_contract_request_json(contractAddress, instruction, &request) ==
         BNS_OK);
  assert(strlen(request) != 0);
  BNS_FREE(request);
}

void test_contract_post_clearance_record() {
  bns_client_t bnsClient = {0};
  clearance_record_t clearanceRecord = {0};
  assert(mock_post_bns_client(&bnsClient, mock_clearance_record_response_ok) ==
         BNS_OK);
  assert(contract_post_clearance_record(&bnsClient, MOCK_CLEARANCE_ORDER_OK,
                                        &clearanceRecord) == BNS_OK);
  assert(clearanceRecord.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(strlen(clearanceRecord.rootHash) != 0);
  bns_client_free(&bnsClient);
}

void test_parse_response_to_clearance_record() {
  char *json = mock_clearance_record_response_ok("", "");
  clearance_record_t clearanceRecord = {0};
  assert(check_and_parse_contract_clearance_record_response(
             json, &clearanceRecord) == BNS_OK);
  free(json);
  assert(strlen(clearanceRecord.chainHash) == HASH_STR_LEN - 1);
  assert(strlen(clearanceRecord.rootHash) == HASH_STR_LEN - 1);
}

void test_check_response_ok() {
  char *json = mock_clearance_record_response_ok("", "");
  clearance_record_t clearanceRecord = {0};
  assert(check_and_parse_contract_clearance_record_response(
             json, &clearanceRecord) == BNS_OK);
  free(json);
}

void test_check_response_error() {
  char *json = mock_clearance_record_response_error("", "");
  clearance_record_t clearanceRecord = {0};
  assert(check_and_parse_contract_clearance_record_response(
             json, &clearanceRecord) != BNS_OK);
  free(json);
}

void test_retry() {
  bns_client_t bnsClient = {0};
  clearance_record_t clearanceRecord = {0};
  reset_clearance_record_cache();
  assert(mock_post_bns_client(&bnsClient, mock_response_retry) == BNS_OK);
  assert(bns_client_set_retry_count(&bnsClient, retryCount) == BNS_OK);
  assert(contract_post_clearance_record(&bnsClient, MOCK_CLEARANCE_ORDER_OK,
                                        &clearanceRecord) == BNS_OK);
  assert(retryCount == 0);
  assert(clearanceRecord.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(strlen(clearanceRecord.rootHash) != 0);
  bns_client_free(&bnsClient);
}

int main() {
  test_create_clearance_record_function_instruction();
  test_create_contract_request_message();
  test_contract_post_clearance_record();
  test_parse_response_to_clearance_record();
  test_check_response_ok();
  test_check_response_error();
  test_retry();
  return 0;
}
