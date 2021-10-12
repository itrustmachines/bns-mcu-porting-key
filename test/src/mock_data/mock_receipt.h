#ifndef BNS_C_CLIENT_TEST_SRC_RECEIPT_MOCK_RECEIPT_H_
#define BNS_C_CLIENT_TEST_SRC_RECEIPT_MOCK_RECEIPT_H_

#include <bns-client/core/bns_types.h>
#include <string.h>

#include "mock_ok_data.h"

void mock_receipt_ok(receipt_t *receipt) {
  strcpy(receipt->callerAddress, MOCK_CALLER_ADDRESS_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  receipt->timestamp = MOCK_TIMESTAMP_OK;
#else
  strcpy(receipt->timestamp, MOCK_TIMESTAMP_OK);
#endif
  strcpy(receipt->cmd, MOCK_CMD_OK);
  strcpy(receipt->indexValue, MOCK_INDEX_VALUE_OK);
  strcpy(receipt->metadata, MOCK_METADATA_OK);
  receipt->clearanceOrder = MOCK_CLEARANCE_ORDER_OK;
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  receipt->timestampSPO = MOCK_TIMESTAMP_BNS_OK;
#else
  strcpy(receipt->timestampSPO, MOCK_TIMESTAMP_BNS_OK);
#endif
  strcpy(receipt->result, MOCK_RESULT_OK);
  strcpy(receipt->sigClient.r, MOCK_SIG_CLIENT_R_OK);
  strcpy(receipt->sigClient.s, MOCK_SIG_CLIENT_S_OK);
  strcpy(receipt->sigClient.v, MOCK_SIG_CLIENT_V_OK);
  strcpy(receipt->sigServer.r, MOCK_SIG_SERVER_R_OK);
  strcpy(receipt->sigServer.s, MOCK_SIG_SERVER_S_OK);
  strcpy(receipt->sigServer.v, MOCK_SIG_SERVER_V_OK);
}

#endif  // BNS_C_CLIENT_TEST_SRC_RECEIPT_MOCK_RECEIPT_H_
