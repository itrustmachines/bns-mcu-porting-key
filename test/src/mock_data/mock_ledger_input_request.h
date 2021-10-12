#ifndef BNS_C_CLIENT_TEST_SRC_LEDGER_INPUT_MOCK_LEDGER_INPUT_REQUEST_H_
#define BNS_C_CLIENT_TEST_SRC_LEDGER_INPUT_MOCK_LEDGER_INPUT_REQUEST_H_

#include <bns-client/core/bns_types.h>
#include <bns-client/util/numeric_util.h>
#include <bns-client/util/string_util.h>
#include <string.h>

#include "mock_ok_data.h"

void mock_ledger_input_request_ok(ledger_input_request_t *ledgerInputRequest) {
  strcpy(ledgerInputRequest->callerAddress, MOCK_CALLER_ADDRESS_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  ledgerInputRequest->timestamp = MOCK_TIMESTAMP_OK;
#else
  bns_strdup(&ledgerInputRequest->timestamp, MOCK_TIMESTAMP_OK);
#endif
  bns_strdup(&ledgerInputRequest->cmd, MOCK_CMD_OK);
  bns_strdup(&ledgerInputRequest->indexValue, MOCK_INDEX_VALUE_OK);
  bns_strdup(&ledgerInputRequest->metadata, MOCK_METADATA_OK);
  ledgerInputRequest->clearanceOrder = MOCK_CLEARANCE_ORDER_OK;
  strcpy(ledgerInputRequest->sigClient.r, MOCK_SIG_CLIENT_R_OK);
  strcpy(ledgerInputRequest->sigClient.s, MOCK_SIG_CLIENT_S_OK);
  strcpy(ledgerInputRequest->sigClient.v, MOCK_SIG_CLIENT_V_OK);
}

#endif  // BNS_C_CLIENT_TEST_SRC_LEDGER_INPUT_MOCK_LEDGER_INPUT_REQUEST_H_
