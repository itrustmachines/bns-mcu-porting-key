#include <assert.h>
#include <bns-client/core/core.h>
#include <bns-client/util/log.h>
#include <bns-client/verify/verify.h>
#include <bns-client/verify/verify_receipt_result.h>

#include "../mock_data/mock_bns_client.h"
#include "../mock_data/mock_clearance_record_response.h"
#include "../mock_data/mock_merkle_proof_response.h"
#include "../mock_data/mock_receipt.h"

void test_ok() {
  LOG_DEBUG("test_ok() begin");
  int res;

  // given
  receipt_t receipt = {0};
  mock_receipt_ok(&receipt);
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_merkle_proof_response_ok;
  bnsClient.httpClient.eth_post = mock_clearance_record_response_ok;

  // when
  merkle_proof_t merkleProof = {0};
  verify_receipt_result_t verifyReceiptResult = {0};
  res = verify(&bnsClient, &receipt, &merkleProof, &verifyReceiptResult);

  // then
  assert(res == BNS_OK);
  assert(verifyReceiptResult.clearanceOrder == receipt.clearanceOrder);
  assert(strcmp(verifyReceiptResult.indexValue, receipt.indexValue) == 0);
  assert(verifyReceiptResult.pass == true);
  assert(strcmp(verifyReceiptResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(verifyReceiptResult.timestamp, "") != 0);
  assert(strcmp(verifyReceiptResult.description, BNS_STATUS_OK) == 0);
  assert(verifyReceiptResult.receiptSignatureOk == true);
  assert(verifyReceiptResult.merkleproofSignatureOk == true);
  assert(verifyReceiptResult.clearanceOrderOk == true);
  assert(verifyReceiptResult.pbPairOk == true);
  assert(verifyReceiptResult.sliceOk == true);
  assert(verifyReceiptResult.clearanceRecordRootHashOk == true);

  // clean
  verify_receipt_result_free(&verifyReceiptResult);
  merkle_proof_free(&merkleProof);
  bns_client_free(&bnsClient);
  LOG_DEBUG("test_ok() end");
}

void test_error() {
  LOG_DEBUG("test_ok() begin");
  int res;

  // given
  receipt_t receipt = {0};
  mock_receipt_ok(&receipt);
  bns_client_t bnsClient = {0};
  mock_bns_client_ok(&bnsClient);
  bnsClient.httpClient.post = mock_merkle_proof_response_status_error;
  bnsClient.httpClient.eth_post = mock_clearance_record_response_ok;

  // when
  merkle_proof_t merkleProof = {0};
  verify_receipt_result_t verifyReceiptResult = {0};
  res = verify(&bnsClient, &receipt, &merkleProof, &verifyReceiptResult);

  // then
  assert(res == BNS_RESPONSE_STATUS_ERROR);
  assert(verifyReceiptResult.clearanceOrder == receipt.clearanceOrder);
  assert(strcmp(verifyReceiptResult.indexValue, receipt.indexValue) == 0);
  assert(verifyReceiptResult.pass == false);
  assert(strcmp(verifyReceiptResult.status, BNS_STATUS_ERROR) == 0);
  assert(strcmp(verifyReceiptResult.timestamp, "") != 0);
  assert(strcmp(verifyReceiptResult.description, VERIFY_FAIL_DESCRIPTION) == 0);
  assert(verifyReceiptResult.receiptSignatureOk == false);
  assert(verifyReceiptResult.merkleproofSignatureOk == false);
  assert(verifyReceiptResult.clearanceOrderOk == false);
  assert(verifyReceiptResult.pbPairOk == false);
  assert(verifyReceiptResult.sliceOk == false);
  assert(verifyReceiptResult.clearanceRecordRootHashOk == false);

  // clean
  verify_receipt_result_free(&verifyReceiptResult);
  merkle_proof_free(&merkleProof);
  bns_client_free(&bnsClient);
  LOG_DEBUG("test_ok() end");
}

int main() {
  test_ok();
  test_error();
  return 0;
}
