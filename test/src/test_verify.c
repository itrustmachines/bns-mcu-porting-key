#include <assert.h>
#include <bns-client/core/core.h>
#include <bns-client/verify/merkle_proof.h>
#include <bns-client/verify/verify.h>

#include "mock_data/mock_bns_client_util.h"
#include "mock_data/mock_clearance_record_response.h"
#include "mock_data/mock_merkle_proof_response.h"
#include "mock_data/mock_receipt_util.h"

void test_verify_clearanceOrder_ok() {
  long long int co = 87;
  merkle_proof_t merkleProof = {.clearanceOrder = co};
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  receipt_t receipt = {"", 0L, "", "", "", co};
#else
  receipt_t receipt = {"", "", "", "",           "",
                       co, "", "", {"", "", ""}, {"", "", ""}};
#endif
  clearance_record_t clearanceRecord = {co, "", ""};
  bool result;
  assert(verify_clearance_order(&receipt, &merkleProof, &clearanceRecord,
                                &result) == BNS_OK);
  assert(result == true);
}

void test_verify_clearanceOrder_not_ok() {
  long long int co = 87;
  merkle_proof_t merkleProof = {.clearanceOrder = co};
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  receipt_t receipt = {"", 0L, "", "", "", co + 2};
#else
  receipt_t receipt = {"",     "", "", "",           "",
                       co + 2, "", "", {"", "", ""}, {"", "", ""}};
#endif
  clearance_record_t clearanceRecord = {co + 4, "", ""};
  bool result;
  assert(verify_clearance_order(&receipt, &merkleProof, &clearanceRecord,
                                &result) == BNS_VERIFY_CLEARANCE_ORDER_ERROR);
  assert(result == false);
}

void test_verify_merkle_proof_signature_ok() {
  bns_client_t bnsClient = {0};
  assert(mock_post_bns_client_(&bnsClient, NULL) == BNS_OK);
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  bool result = false;
  assert(
      verify_merkle_proof_signature(bnsClient.bnsServerInfo.serverWalletAddress,
                                    &merkleProof, &result) == BNS_OK);
  merkle_proof_free(&merkleProof);
  bns_client_free(&bnsClient);
}

void test_verify_merkle_proof_signature_error() {
  bns_client_t bnsClient = {0};
  assert(mock_post_bns_client_(&bnsClient, NULL) == BNS_OK);
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_error(&merkleProof);
  bool result = false;
  assert(verify_merkle_proof_signature(
             bnsClient.bnsServerInfo.serverWalletAddress, &merkleProof,
             &result) == BNS_VERIFY_SIGNATURE_ERROR);
  merkle_proof_free(&merkleProof);
  bns_client_free(&bnsClient);
}

void test_verify_pbPairOk_string_timestamp() {
  receipt_t receipt = {0};
  assert(mock_get_string_timestamp_receipt(&receipt) == BNS_OK);
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  bool pass = false;
  assert(verify_pb_pair(&receipt, &merkleProof, &pass) == BNS_OK);
  assert(pass == true);
  merkle_proof_free(&merkleProof);
}

#if defined(RECEIPT_TIMESTAMP_IS_LONG)
void test_verify_pbPairOk_long_timestamp() {
  receipt_t receipt = {0};
  assert(mock_get_long_timestamp_receipt(&receipt) == BNS_OK);
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  bool pass = false;
  assert(verify_pb_pair(&receipt, &merkleProof, &pass) == BNS_OK);
  assert(pass == true);
  merkle_proof_free(&merkleProof);
}
#endif

void test_verify_sliceOk() {
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  bool result;
  assert(verify_merkle_proof_slice(&merkleProof.slice, &result) == BNS_OK);
  assert(result == true);
  merkle_proof_free(&merkleProof);
}

void test_verify_clearanceRecordRootHashOk() {
  merkle_proof_t merkleProof = {0};
  mock_merkleProof_ok(&merkleProof);
  clearance_record_t clearanceRecord = {0};
  assert(mock_clearance_record_ok(&clearanceRecord) == BNS_OK);
  bool result;
  assert(verify_root_hash(&merkleProof, &clearanceRecord, &result) == BNS_OK);
  assert(result == true);
  merkle_proof_free(&merkleProof);
}

int main() {
  test_verify_clearanceOrder_ok();
  test_verify_clearanceOrder_not_ok();
  test_verify_merkle_proof_signature_ok();
  test_verify_merkle_proof_signature_error();
  test_verify_pbPairOk_string_timestamp();
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  test_verify_pbPairOk_long_timestamp();
#endif
  test_verify_sliceOk();
  test_verify_clearanceRecordRootHashOk();
}
