#include <assert.h>
#include <bns-client/input/ledger_input.h>
#include <string.h>

#include "../mock_data/mock_ledger_input_response.h"

void test_string_timestamp_ok() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_STRING_TIMESTAMP_OK,
             &ledgerInputResult) == BNS_OK);
  assert(strcmp(ledgerInputResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.description, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->callerAddress,
                MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestamp, MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->indexValue, MOCK_INDEX_VALUE_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->metadata, MOCK_METADATA_OK) == 0);
  assert(ledgerInputResult.receipt->clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestampSPO == MOCK_TIMESTAMP_BNS_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestampSPO,
                MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->result, MOCK_RESULT_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.r, MOCK_SIG_CLIENT_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.s, MOCK_SIG_CLIENT_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.v, MOCK_SIG_CLIENT_V_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.r, MOCK_SIG_SERVER_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.s, MOCK_SIG_SERVER_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.v, MOCK_SIG_SERVER_V_OK) ==
         0);
  assert(ledgerInputResult.doneClearanceOrder == MOCK_CLEARANCE_ORDER_OK);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_long_timestamp_ok() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_LONG_TIMESTAMP_OK,
             &ledgerInputResult) == BNS_OK);
  assert(strcmp(ledgerInputResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.description, BNS_STATUS_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->callerAddress,
                MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestamp, MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->indexValue, MOCK_INDEX_VALUE_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->metadata, MOCK_METADATA_OK) == 0);
  assert(ledgerInputResult.receipt->clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(ledgerInputResult.receipt->timestampSPO == MOCK_TIMESTAMP_BNS_OK);
#else
  assert(strcmp(ledgerInputResult.receipt->timestampSPO,
                MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(ledgerInputResult.receipt->result, MOCK_RESULT_OK) == 0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.r, MOCK_SIG_CLIENT_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.s, MOCK_SIG_CLIENT_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigClient.v, MOCK_SIG_CLIENT_V_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.r, MOCK_SIG_SERVER_R_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.s, MOCK_SIG_SERVER_S_OK) ==
         0);
  assert(strcmp(ledgerInputResult.receipt->sigServer.v, MOCK_SIG_SERVER_V_OK) ==
         0);
  assert(ledgerInputResult.doneClearanceOrder == MOCK_CLEARANCE_ORDER_OK);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_1() {
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_1,
             &ledgerInputResult) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_2() {
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_2,
             &ledgerInputResult) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_3() {
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_3,
             &ledgerInputResult) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_DESCRIPTION_PARSE_ERROR_1() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_PARSE_ERROR_1,
             &ledgerInputResult) == BNS_RESPONSE_DESCRIPTION_PARSE_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_RESPONSE_DESCRIPTION_PARSE_ERROR_2() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_PARSE_ERROR_2,
             &ledgerInputResult) == BNS_RESPONSE_DESCRIPTION_PARSE_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_LEDGER_INPUT_CLEARANCE_ORDER_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_CLEARANCE_ORDER_ERROR,
             &ledgerInputResult) == BNS_LEDGER_INPUT_CLEARANCE_ORDER_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_LEDGER_INPUT_INDEX_VALUE_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_INDEX_VALUE_ERROR,
             &ledgerInputResult) == BNS_LEDGER_INPUT_INDEX_VALUE_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_LEDGER_INPUT_CLIENT_SIGNATURE_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_CLIENT_SIGNATURE_ERROR,
             &ledgerInputResult) == BNS_LEDGER_INPUT_CLIENT_SIGNATURE_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_LEDGER_INPUT_AUTHENTICATION_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_AUTHENTICATION_ERROR,
             &ledgerInputResult) == BNS_LEDGER_INPUT_AUTHENTICATION_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_LEDGER_INPUT_INPUT_CMD_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_CMD_ERROR,
             &ledgerInputResult) == BNS_LEDGER_INPUT_CMD_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_LEDGER_INPUT_INPUT_TX_COUNT_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_DESCRIPTION_TX_COUNT_ERROR,
             &ledgerInputResult) == BNS_LEDGER_INPUT_TX_COUNT_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

void test_BNS_RESPONSE_STATUS_ERROR() {
  // then
  ledger_input_result_t ledgerInputResult = {0};
  assert(check_and_parse_ledger_input_response(
             MOCK_LEDGER_INPUT_RESPONSE_STATUS_ERROR, &ledgerInputResult) ==
         BNS_RESPONSE_STATUS_ERROR);

  // clean
  ledger_input_result_free(&ledgerInputResult);
}

int main() {
  test_string_timestamp_ok();
  test_long_timestamp_ok();
  test_BNS_RESPONSE_STATUS_PARSE_ERROR_1();
  test_BNS_RESPONSE_STATUS_PARSE_ERROR_2();
  test_BNS_RESPONSE_STATUS_PARSE_ERROR_3();
  test_BNS_RESPONSE_DESCRIPTION_PARSE_ERROR_1();
  test_BNS_RESPONSE_DESCRIPTION_PARSE_ERROR_2();
  test_BNS_LEDGER_INPUT_CLEARANCE_ORDER_ERROR();
  test_BNS_LEDGER_INPUT_INDEX_VALUE_ERROR();
  test_BNS_LEDGER_INPUT_CLIENT_SIGNATURE_ERROR();
  test_BNS_LEDGER_INPUT_AUTHENTICATION_ERROR();
  test_BNS_LEDGER_INPUT_INPUT_CMD_ERROR();
  test_BNS_LEDGER_INPUT_INPUT_TX_COUNT_ERROR();
  test_BNS_RESPONSE_STATUS_ERROR();
  return 0;
}