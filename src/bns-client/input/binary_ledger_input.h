#ifndef BNS_CLIENT_SRC_BNS_CLIENT_INPUT_BINARY_LEDGER_INPUT_H_
#define BNS_CLIENT_SRC_BNS_CLIENT_INPUT_BINARY_LEDGER_INPUT_H_

#include <bns-client/input/ledger_input.h>

#define BINARY_LEDGER_INPUT_PATH "/ledger/binaryInput"
#define MULTI_PART_LEDGER_INPUT_KEY "ledgerInput"
#define MULTI_PART_BINARY_KEY "binary"

#define BNS_APPLICATION_JSON "application/json"
#define BNS_APPLICATION_OCTET_STREAM "application/octet-stream"

void build_post_binary_ledger_input_url(char** url, const char* serverUrl);

_CHECK_RESULT
bns_exit_code_t bns_post_binary_ledger_input(
    const bns_client_t*           bnsClient,
    const char*                   cmdJson,
    const receipt_locator_t*      receiptLocator,
    const binary_info_t*          binaryInfo,
    binary_ledger_input_result_t* binaryLedgerInputResult);

_CHECK_RESULT
bns_exit_code_t check_and_parse_binary_ledger_input_response(
    const char* res, binary_ledger_input_result_t* binaryLedgerInputResult);

void binary_ledger_input_result_free(
    binary_ledger_input_result_t* binaryLedgerInputResult);

#endif  // BNS_CLIENT_SRC_BNS_CLIENT_INPUT_BINARY_LEDGER_INPUT_H_
