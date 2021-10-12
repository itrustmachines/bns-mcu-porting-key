#ifndef CALLBACK_H_
#define CALLBACK_H_

#include <bns-client/core/bns_types.h>

/** 1.
 * When initialize the BNS Client
 * BNS Client will send registerRequest to SPO Server
 * and receive registerResult from SPO Server
 * Developers can implement the code in register_callback function
 * to callback the informations in registerRequest and registerResult
 */
void register_callback(const register_request_t *registerRequest, bool result);

/** 1.
 * When initialize the BNS Client
 * BNS Client will send registerRequest to SPO Server
 * and receive registerResult from SPO Server
 * Developers can implement the code in register_callback function
 * to callback the informations in registerRequest and registerResult
 */
void create_ledger_input_by_cmd_callback(
    const receipt_locator_t *receiptLocator,
    const ledger_input_request_t *ledgerInputRequest);

/** 3.
 * BNS Client will receive ledgerInputResult from SPO Server
 * after sending ledgerInputRequest
 * Developers can implement the code in ledger_input_response_callback function
 * to callback the informations in ledgerInputResult
 */
void ledger_input_response_callback(
    const receipt_locator_t *receiptLocator, const char *cmdJson,
    const ledger_input_result_t *ledgerInputResult);

/** 4.
 * BNS Client will receive binaryLedgerInputResult from SPO Server
 * after sending ledgerInputRequest
 * Developers can implement the code in binary_ledger_input_response_callback
 * function to callback the informations in binaryLedgerInputResult
 */
void binary_ledger_input_response_callback(
    const receipt_locator_t *receiptLocator, const char *cmdJson,
    const binary_info_t *binaryInfo,
    const binary_ledger_input_result_t *binaryLedgerInputResult);

/** 5.
 * The receipt is contained in ledgerInputResult / binaryLedgerInputResult
 * Developers can implement the code in receipt_event_callback function
 * to callback the informations in receipt
 */
void receipt_event_callback(const receipt_t *receipt);

/** 6.
 * The doneClearanceOrder is contained in ledgerInputResult /
 * binaryLedgerInputResult BNS Client will use doneClearanceOrder to find out
 * which receipts need to be verified Developers can implement the code in
 * done_clearance_order_event_callback function to callback the informations in
 * doneClearanceOrder
 */
void done_clearance_order_event_callback(clearance_order_t doneCO);

/** 7.
 * Before verifying the receipt
 * BNS Client will request the merkleProof of the receipts to be verified from
 * the Server The Merkle Proof is evidence of receipt verification BNS Client
 * will use Merkle proof to verify the receipt whether receipt is in the
 * TP-merkle tree Developers can implement the code in merkle_proof_callback
 * function to callback the informations in merkleProof
 */
void merkle_proof_callback(const receipt_locator_t *receiptLocator,
                           const merkle_proof_t *merkleProof);

/** 8.
 * After receiving the Merkle Proof
 * BNS Client will start to verify the receipt and store the result in
 * verifyReceiptResult Developers can implement the code in
 * verify_receipt_result_callback function to callback the informations in
 * verifyReceiptResult
 */
void verify_receipt_result_callback(
    const receipt_t *receipt, const merkle_proof_t *merkleProof,
    const verify_receipt_result_t *verifyReceiptResult);

#endif