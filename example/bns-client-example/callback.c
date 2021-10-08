#include "callback.h"

#include <bns-client/input/ledger_input.h>
#include <bns-client/input/receipt_locator.h>
#include <bns-client/util/log.h>
#include <bns-client/util/string_util.h>
#include <bns-client/verify/verify.h>
#include <string.h>

/** 1.
 * When initialize the BNS Client
 * BNS Client will send registerRequest to SPO Server
 * and receive registerResult from SPO Server
 * Developers can implement the code in register_callback function
 * to callback the informations in registerRequest and registerResult
 */
void register_callback(_UNUSED const register_request_t *registerRequest,
                       _UNUSED bool result) {
  LOG_DEBUG("register_callback begin()");
  LOG_DEBUG("register_callback end()");
}

/** 2.
 * After successfully initializing the BNS Client
 * BNS Client will store CMD and other data in
 * ledgerInputRequest and do ledgerInput
 * to send ledgerInputRequest to the SPO Server
 * Developers can implement the code in create_ledger_input_by_cmd_callback
 * function to callback the information in ledgerInputRequest
 */
void create_ledger_input_by_cmd_callback(
    _UNUSED const receipt_locator_t *receiptLocator,
    _UNUSED const ledger_input_request_t *ledgerInputRequest) {
  LOG_DEBUG("create_ledger_input_by_cmd_callback begin()");
  LOG_DEBUG("create_ledger_input_by_cmd_callback end()");
}

/** 3.
 * BNS Client will receive ledgerInputResult from SPO Server
 * after sending ledgerInputRequest
 * Developers can implement the code in ledger_input_response_callback function
 * to callback the informations in ledgerInputResult
 */
void ledger_input_response_callback(
    _UNUSED const receipt_locator_t *receiptLocator,
    _UNUSED const char *cmdJson,
    const ledger_input_result_t *ledgerInputResult) {
  LOG_DEBUG(
      "ledger_input_response_callback "
      "begin() " LEDGER_INPUT_RESULT_PRINT_FORMAT,
      LEDGER_INPUT_RESULT_TO_PRINT_ARGS(ledgerInputResult));
  LOG_DEBUG("ledger_input_response_callback end()");
}

/** 4.
 * BNS Client will receive binaryLedgerInputResult from SPO Server
 * after sending ledgerInputRequest
 * Developers can implement the code in binary_ledger_input_response_callback
 * function to callback the informations in binaryLedgerInputResult
 */
void binary_ledger_input_response_callback(
    _UNUSED const receipt_locator_t *receiptLocator,
    _UNUSED const char *cmdJson, _UNUSED const binary_info_t *binaryInfo,
    _UNUSED const binary_ledger_input_result_t *binaryLedgerInputResult) {
  LOG_DEBUG("binary_ledger_input_response_callback begin()");
  LOG_DEBUG("binary_ledger_input_response_callback end()");
}

/** 5.
 * The receipt is contained in ledgerInputResult / binaryLedgerInputResult
 * Developers can implement the code in receipt_event_callback function
 * to callback the informations in receipt
 */
void receipt_event_callback(_UNUSED const receipt_t *receipt) {
  LOG_DEBUG("receipt_event_callback begin()");
  LOG_DEBUG("receipt_event_callback end()");
}

/** 6.
 * The doneClearanceOrder is contained in ledgerInputResult /
 * binaryLedgerInputResult BNS Client will use doneClearanceOrder to find out
 * which receipts need to be verified Developers can implement the code in
 * done_clearance_order_event_callback function to callback the informations in
 * doneClearanceOrder
 */
void done_clearance_order_event_callback(_UNUSED clearance_order_t doneCO) {
  LOG_DEBUG("done_clearance_order_event_callback begin()");
  LOG_DEBUG("done_clearance_order_event_callback end()");
}

/** 7.
 * Before verifying the receipt
 * BNS Client will request the merkleProof of the receipts to be verified from
 * the Server The Merkle Proof is evidence of receipt verification BNS Client
 * will use Merkle proof to verify the receipt whether receipt is in the
 * TP-merkle tree. Developers can implement the code in merkle_proof_callback
 * function to callback the informations in merkleProof
 */
void merkle_proof_callback(_UNUSED const receipt_locator_t *receiptLocator,
                           _UNUSED const merkle_proof_t *merkleProof) {
  LOG_DEBUG("merkle_proof_callback begin()");
  LOG_DEBUG("merkle_proof_callback end()");
}

/** 8.
 * After receiving the Merkle Proof
 * BNS Client will start to verify the receipt and store the result in
 * verifyReceiptResult Developers can implement the code in
 * verify_receipt_result_callback function to callback the informations in
 * verifyReceiptResult
 */
void verify_receipt_result_callback(
    _UNUSED const receipt_t *receipt, _UNUSED const merkle_proof_t *merkleProof,
    const verify_receipt_result_t *verifyReceiptResult) {
  LOG_DEBUG(
      "verify_receipt_result_callback "
      "begin() " VERIFY_RECEIPT_RESULT_PRINT_FORMAT,
      VERIFY_RECEIPT_RESULT_TO_PRINT_ARGS(verifyReceiptResult));
  LOG_DEBUG("verify_receipt_result_callback end()");
}