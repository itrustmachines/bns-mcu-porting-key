#ifndef BNS_C_CLIENT_MERKLE_PROOF_H
#define BNS_C_CLIENT_MERKLE_PROOF_H

#include <bns-client/core/core.h>
#include <cJSON.h>

#define LEDGER_VERIFY_MERKLE_PROOF "/verify/merkleProof/"

void build_get_merkle_proof_url(char**                   url,
                                const char*              serverUrl,
                                const receipt_locator_t* receiptLocator);

_CHECK_RESULT
bns_exit_code_t bns_get_merkle_proof(const bns_client_t*      bnsClient,
                                     const receipt_locator_t* receiptLocator,
                                     merkle_proof_t*          merkleProof);

_CHECK_RESULT
bns_exit_code_t parse_pb_pair(cJSON* root, pb_pair_t* pbPair);

_CHECK_RESULT
bns_exit_code_t check_and_parse_merkle_proof_response(
    const char* res, merkle_proof_t* merkleProof);

void pb_pair_free(pb_pair_t* pbPair);

void merkle_proof_free(merkle_proof_t* merkleProof);

void merkle_proof_print(const merkle_proof_t* merkleProof);

_CHECK_RESULT
bns_exit_code_t merkle_proof_to_sign_data(const merkle_proof_t* merkleProof,
                                          char**                toSignData);

_CHECK_RESULT
bns_exit_code_t check_receipt_in_pbpair(const receipt_t* receipt,
                                        const pb_pair_t* pbPair);

#endif  // BNS_C_CLIENT_MERKLE_PROOF_H
