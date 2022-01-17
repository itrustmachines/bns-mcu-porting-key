#include <assert.h>
#include <bns-client/core/core.h>
#include <bns-client/util/log.h>

#include "mock_data/mock_bns_client_util.h"
#include "mock_data/mock_merkle_proof_response.h"
#include "mock_data/mock_receipt_util.h"

static int retryCount = 5;

char* mock_response_retry(_UNUSED const char* const url) {
  if (--retryCount > 0) {
    return NULL;
  } else {
    return mock_merkle_proof_response_ok();
  }
}

void test_bns_get_merkle_proof_ok() {
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  assert(merkleProof.slice.index != 0);
  assert(merkleProof.pbPair.size != 0);
  assert(merkleProof.pbPair.pbPairValue != NULL);
  assert(merkleProof.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(merkleProof.sigServer.r != NULL);
  assert(merkleProof.sigServer.s != NULL);
  assert(merkleProof.sigServer.v != NULL);
  merkle_proof_free(&merkleProof);
}

void test_check_merkle_proof_response_ok() {
  char*          response    = mock_merkle_proof_response_ok();
  merkle_proof_t merkleProof = {0};
  assert(check_and_parse_merkle_proof_response(response, &merkleProof) ==
         BNS_OK);
  free(response);
  merkle_proof_free(&merkleProof);
}

void test_check_merkle_proof_response_error() {
  char*          response    = mock_merkle_proof_response_status_error();
  merkle_proof_t merkleProof = {0};
  assert(check_and_parse_merkle_proof_response(response, &merkleProof) ==
         BNS_RESPONSE_STATUS_ERROR);
  free(response);
}

void test_check_merkle_proof_response_format_error() {
  char*          response    = mock_merkle_proof_response_format_error();
  merkle_proof_t merkleProof = {0};
  assert(check_and_parse_merkle_proof_response(response, &merkleProof) ==
         BNS_RESPONSE_STATUS_PARSE_ERROR);
  free(response);
}

void test_parse_merkle_proof_ok() {
  merkle_proof_t merkleProof = {0};
  char*          response    = mock_merkle_proof_response_ok();
  assert(check_and_parse_merkle_proof_response(response, &merkleProof) ==
         BNS_OK);
  free(response);
  assert(merkleProof.slice.index != 0);
  assert(merkleProof.pbPair.size != 0);
  assert(merkleProof.pbPair.pbPairValue != NULL);
  assert(merkleProof.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(merkleProof.sigServer.r != NULL);
  assert(merkleProof.sigServer.s != NULL);
  assert(merkleProof.sigServer.v != NULL);
  merkle_proof_print(&merkleProof);
  merkle_proof_free(&merkleProof);
}

void test_parse_merkle_proof_data_error() {
  merkle_proof_t merkleProof = {0};
  char*          response    = mock_merkle_proof_response_format_error();
  assert(check_and_parse_merkle_proof_response(response, &merkleProof) ==
         BNS_RESPONSE_STATUS_PARSE_ERROR);
  free(response);

  merkle_proof_free(&merkleProof);
}

void test_merkle_proof_to_sign_data() {
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  char* signData = NULL;
  assert(merkle_proof_to_sign_data(&merkleProof, &signData) == BNS_OK);
  assert(signData != NULL);
  free(signData);
  merkle_proof_free(&merkleProof);
}

void test_check_string_timestamp_receipt_in_pbpair() {
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  receipt_t receipt = {0};
  assert(mock_get_string_timestamp_receipt(&receipt) == BNS_OK);
  assert(check_receipt_in_pbpair(&receipt, &merkleProof.pbPair) == BNS_OK);
  merkle_proof_free(&merkleProof);
}

#if defined(RECEIPT_TIMESTAMP_IS_LONG)
void test_check_long_timestamp_receipt_in_pbpair() {
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  receipt_t receipt = {0};
  assert(mock_get_long_timestamp_receipt(&receipt) == BNS_OK);
  assert(check_receipt_in_pbpair(&receipt, &merkleProof.pbPair) == BNS_OK);
  merkle_proof_free(&merkleProof);
}
#endif

void test_retry() {
  merkle_proof_t merkleProof = {0};

  bns_client_t bnsClient = {0};
  assert(mock_get_bns_client_(&bnsClient, mock_response_retry) == BNS_OK);
  assert(bns_client_set_retry_count(&bnsClient, retryCount) == BNS_OK);
  receipt_locator_t receiptLocator = {204, "NUVOTON_Demo_R7"};
  assert(bns_get_merkle_proof(&bnsClient, &receiptLocator, &merkleProof) ==
         BNS_OK);
  assert(retryCount == 0);
  assert(merkleProof.slice.index != 0);
  assert(merkleProof.pbPair.size != 0);
  assert(merkleProof.pbPair.pbPairValue != NULL);
  assert(merkleProof.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
  assert(merkleProof.sigServer.r != NULL);
  assert(merkleProof.sigServer.s != NULL);
  assert(merkleProof.sigServer.v != NULL);
  merkle_proof_free(&merkleProof);
  bns_client_free(&bnsClient);
}

int main() {
  test_bns_get_merkle_proof_ok();
  LOG_DEBUG("test_bns_get_merkle_proof_ok() done");
  test_check_merkle_proof_response_ok();
  LOG_DEBUG("test_check_merkle_proof_response_ok() done");
  test_check_merkle_proof_response_error();
  LOG_DEBUG("test_check_merkle_proof_response_error() done");
  test_check_merkle_proof_response_format_error();
  LOG_DEBUG("test_check_merkle_proof_response_format_error() done");
  test_parse_merkle_proof_ok();
  LOG_DEBUG("test_parse_merkle_proof_ok() done");
  test_parse_merkle_proof_data_error();
  LOG_DEBUG("test_parse_merkle_proof_data_error() done");
  test_merkle_proof_to_sign_data();
  LOG_DEBUG("test_merkle_proof_to_sign_data() done");
  test_check_string_timestamp_receipt_in_pbpair();
  LOG_DEBUG("test_check_string_timestamp_receipt_in_pbpair() done");
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  test_check_long_timestamp_receipt_in_pbpair();
  LOG_DEBUG("test_check_long_timestamp_receipt_in_pbpair() done");
#endif
  LOG_DEBUG("test_check_pbpair_in_leaf_node() done");
  test_retry();
}
