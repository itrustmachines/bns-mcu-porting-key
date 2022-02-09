#ifndef BNS_C_CLIENT_TEST_SRC_MERKLE_PROOF_MOCK_MERKLE_PROOF_RESPONSE_H_
#define BNS_C_CLIENT_TEST_SRC_MERKLE_PROOF_MOCK_MERKLE_PROOF_RESPONSE_H_

#include <bns-client/core/bns_definitions.h>
#include <bns-client/util/string_util.h>
#include <bns-client/verify/merkle_proof.h>
#include <bns-client/verify/slice.h>
#include <cJSON.h>

#include "mock_ok_data.h"

#define MOCK_MERKLE_PROOF_RESPONSE_OK        \
  "{\"status\":\"ok\",\"description\":\"\"," \
  "\"merkleProof\":" MOCK_MERKLE_PROOF_JSON_OK "}"
#define MOCK_MERKLE_PROOF_RESPONSE_FORMAT_ERROR \
  "\"status\":\"ok\",\"description\":\"\","     \
  "\"merkleProof\":" MOCK_MERKLE_PROOF_JSON_OK "}"
#define MOCK_MERKLE_PROOF_RESPONSE_STATUS_ERROR \
  "{\"status\":\"" BNS_STATUS_ERROR             \
  "\",\"description\":\"\",\"merkleProof\":" MOCK_MERKLE_PROOF_JSON_OK "}"

_CHECK_RESULT
char* mock_merkle_proof_response_ok() {
  char* response = NULL;
  bns_strdup(&response, MOCK_MERKLE_PROOF_RESPONSE_OK);
  return response;
}

_CHECK_RESULT
char* mock_merkle_proof_response_format_error() {
  char* response = NULL;
  bns_strdup(&response, MOCK_MERKLE_PROOF_RESPONSE_FORMAT_ERROR);
  return response;
}

_CHECK_RESULT
char* mock_merkle_proof_response_status_error() {
  char* response = NULL;
  bns_strdup(&response, MOCK_MERKLE_PROOF_RESPONSE_STATUS_ERROR);
  return response;
}

void mock_merkleProof_ok(merkle_proof_t* merkleProof) {
  assert(check_and_parse_merkle_proof_response(MOCK_MERKLE_PROOF_RESPONSE_OK,
                                               merkleProof) == BNS_OK);
}

void mock_merkleProof_error(merkle_proof_t* merkleProof) {
  assert(check_and_parse_merkle_proof_response(MOCK_MERKLE_PROOF_RESPONSE_OK,
                                               merkleProof) == BNS_OK);
  merkleProof->slice.index = merkleProof->slice.index + 1;
}

#endif  // BNS_C_CLIENT_TEST_SRC_MERKLE_PROOF_MOCK_MERKLE_PROOF_RESPONSE_H_
