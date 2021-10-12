#include <assert.h>
#include <bns-client/verify/merkle_proof.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // then
  char *json = NULL;
  assert(build_merkle_proof_request(MOCK_CALLER_ADDRESS_OK, MOCK_PRIVATE_KEY_OK,
                                    MOCK_CLEARANCE_ORDER_OK,
                                    MOCK_INDEX_VALUE_OK, &json) == BNS_OK);
  assert(strcmp(json, MOCK_MERKLE_PROOF_REQUEST_JSON_OK) == 0);

  // clean
  BNS_FREE(json);
}

void test_BNS_ADDRESS_NULL_ERROR() {
  assert(build_merkle_proof_request(NULL, NULL, 0, NULL, NULL) ==
         BNS_ADDRESS_NULL_ERROR);
}

void test_BNS_PRIVATE_KEY_NULL_ERROR() {
  assert(build_merkle_proof_request(MOCK_CALLER_ADDRESS_OK, NULL, 0, NULL,
                                    NULL) == BNS_PRIVATE_KEY_NULL_ERROR);
}

void test_BNS_CLEARANCE_ORDER_LESS_THAN_OR_EQUAL_TO_ZERO_ERROR() {
  assert(build_merkle_proof_request(MOCK_CALLER_ADDRESS_OK, MOCK_PRIVATE_KEY_OK,
                                    0, NULL, NULL) ==
         BNS_CLEARANCE_ORDER_LESS_THAN_OR_EQUAL_TO_ZERO_ERROR);
}

void test_BNS_INDEX_VALUE_NULL_ERROR() {
  assert(build_merkle_proof_request(MOCK_CALLER_ADDRESS_OK, MOCK_PRIVATE_KEY_OK,
                                    MOCK_CLEARANCE_ORDER_OK, NULL,
                                    NULL) == BNS_INDEX_VALUE_NULL_ERROR);
}

void test_BNS_SERVER_INFO_REQUEST_JSON_NULL_ERROR() {
  assert(build_merkle_proof_request(MOCK_CALLER_ADDRESS_OK, MOCK_PRIVATE_KEY_OK,
                                    MOCK_CLEARANCE_ORDER_OK,
                                    MOCK_INDEX_VALUE_OK, NULL) ==
         BNS_SERVER_INFO_REQUEST_JSON_NULL_ERROR);
}

int main() {
  test_ok();
  test_BNS_ADDRESS_NULL_ERROR();
  test_BNS_PRIVATE_KEY_NULL_ERROR();
  test_BNS_CLEARANCE_ORDER_LESS_THAN_OR_EQUAL_TO_ZERO_ERROR();
  test_BNS_INDEX_VALUE_NULL_ERROR();
  test_BNS_SERVER_INFO_REQUEST_JSON_NULL_ERROR();
  return 0;
}