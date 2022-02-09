#ifndef BNS_C_CLIENT_CONTRACT_H
#define BNS_C_CLIENT_CONTRACT_H

#include <bns-client/core/core.h>

#define INSTRUCTION_STR_LEN 75

#define INSTRUCTION_PREFIX "0x6b30ad23"

#define CLEARANCE_RECORD_PRINT_FORMAT                                     \
  "clearanceRecord=clearance_record_t(clearanceOrder=%lld, rootHash=%s, " \
  "chainHash=%s)"
#define CLEARANCE_RECORD_TO_PRINT_ARGS(clearanceRecord)         \
  clearanceRecord->clearanceOrder, (clearanceRecord)->rootHash, \
      (clearanceRecord)->chainHash

_CHECK_RESULT
bns_exit_code_t build_clearance_record_contract_instruction(
    clearance_order_t clearanceOrder, char** instruction);

_CHECK_RESULT
bns_exit_code_t build_contract_request_json(const char* contractAddress,
                                            const char* instruction,
                                            char**      requestJson);

_CHECK_RESULT
bns_exit_code_t contract_post_clearance_record(
    const bns_client_t* bnsClient,
    clearance_order_t   clearanceOrder,
    clearance_record_t* clearanceRecord);

_CHECK_RESULT
bns_exit_code_t check_and_parse_contract_clearance_record_response(
    const char* res, clearance_record_t* clearanceRecord);

#endif  // BNS_C_CLIENT_CONTRACT_H
