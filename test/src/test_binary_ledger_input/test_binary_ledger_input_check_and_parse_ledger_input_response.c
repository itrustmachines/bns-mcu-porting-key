#include <assert.h>
#include <bns-client/input/binary_ledger_input.h>
#include <string.h>

#include "../mock_data/mock_binary_ledger_input_response.h"

void test_string_timestamp_ok() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_STRING_TIMESTAMP_OK,
             &binaryLedgerInputResult) == BNS_OK);
  assert(strcmp(binaryLedgerInputResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.description, BNS_STATUS_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->callerAddress,
                MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(binaryLedgerInputResult.receipt->timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(binaryLedgerInputResult.receipt->timestamp,
                MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(binaryLedgerInputResult.receipt->cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->indexValue,
                MOCK_INDEX_VALUE_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->metadata, MOCK_METADATA_OK) ==
         0);
  assert(binaryLedgerInputResult.receipt->clearanceOrder ==
         MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(binaryLedgerInputResult.receipt->timestampSPO ==
         MOCK_TIMESTAMP_BNS_OK);
#else
  assert(strcmp(binaryLedgerInputResult.receipt->timestampSPO,
                MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(binaryLedgerInputResult.receipt->result, MOCK_RESULT_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigClient.r,
                MOCK_SIG_CLIENT_R_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigClient.s,
                MOCK_SIG_CLIENT_S_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigClient.v,
                MOCK_SIG_CLIENT_V_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigServer.r,
                MOCK_SIG_SERVER_R_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigServer.s,
                MOCK_SIG_SERVER_S_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigServer.v,
                MOCK_SIG_SERVER_V_OK) == 0);
  assert(binaryLedgerInputResult.doneClearanceOrder == MOCK_CLEARANCE_ORDER_OK);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_long_timestamp_ok() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_LONG_TIMESTAMP_OK,
             &binaryLedgerInputResult) == BNS_OK);
  assert(strcmp(binaryLedgerInputResult.status, BNS_STATUS_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.description, BNS_STATUS_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->callerAddress,
                MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(binaryLedgerInputResult.receipt->timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(binaryLedgerInputResult.receipt->timestamp,
                MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(binaryLedgerInputResult.receipt->cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->indexValue,
                MOCK_INDEX_VALUE_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->metadata, MOCK_METADATA_OK) ==
         0);
  assert(binaryLedgerInputResult.receipt->clearanceOrder ==
         MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(binaryLedgerInputResult.receipt->timestampSPO ==
         MOCK_TIMESTAMP_BNS_OK);
#else
  assert(strcmp(binaryLedgerInputResult.receipt->timestampSPO,
                MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(binaryLedgerInputResult.receipt->result, MOCK_RESULT_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigClient.r,
                MOCK_SIG_CLIENT_R_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigClient.s,
                MOCK_SIG_CLIENT_S_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigClient.v,
                MOCK_SIG_CLIENT_V_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigServer.r,
                MOCK_SIG_SERVER_R_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigServer.s,
                MOCK_SIG_SERVER_S_OK) == 0);
  assert(strcmp(binaryLedgerInputResult.receipt->sigServer.v,
                MOCK_SIG_SERVER_V_OK) == 0);
  assert(binaryLedgerInputResult.doneClearanceOrder == MOCK_CLEARANCE_ORDER_OK);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_1() {
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_1,
             &binaryLedgerInputResult) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_2() {
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_2,
             &binaryLedgerInputResult) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_STATUS_PARSE_ERROR_3() {
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_STATUS_PARSE_ERROR_3,
             &binaryLedgerInputResult) == BNS_RESPONSE_STATUS_PARSE_ERROR);
}

void test_BNS_RESPONSE_DESCRIPTION_PARSE_ERROR_1() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_PARSE_ERROR_1,
             &binaryLedgerInputResult) == BNS_RESPONSE_DESCRIPTION_PARSE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_RESPONSE_DESCRIPTION_PARSE_ERROR_2() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_PARSE_ERROR_2,
             &binaryLedgerInputResult) == BNS_RESPONSE_DESCRIPTION_PARSE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_LEDGER_INPUT_CLEARANCE_ORDER_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(
      check_and_parse_binary_ledger_input_response(
          MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_CLEARANCE_ORDER_ERROR,
          &binaryLedgerInputResult) == BNS_LEDGER_INPUT_CLEARANCE_ORDER_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_LEDGER_INPUT_INDEX_VALUE_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_INDEX_VALUE_ERROR,
             &binaryLedgerInputResult) == BNS_LEDGER_INPUT_INDEX_VALUE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_LEDGER_INPUT_CLIENT_SIGNATURE_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(
      check_and_parse_binary_ledger_input_response(
          MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_CLIENT_SIGNATURE_ERROR,
          &binaryLedgerInputResult) == BNS_LEDGER_INPUT_CLIENT_SIGNATURE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_LEDGER_INPUT_AUTHENTICATION_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_AUTHENTICATION_ERROR,
             &binaryLedgerInputResult) ==
         BNS_LEDGER_INPUT_AUTHENTICATION_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_LEDGER_INPUT_INPUT_CMD_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_CMD_ERROR,
             &binaryLedgerInputResult) == BNS_LEDGER_INPUT_CMD_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_LEDGER_INPUT_INPUT_TX_COUNT_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_DESCRIPTION_TX_COUNT_ERROR,
             &binaryLedgerInputResult) == BNS_LEDGER_INPUT_TX_COUNT_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_RESPONSE_STATUS_ERROR() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_STATUS_ERROR,
             &binaryLedgerInputResult) == BNS_RESPONSE_STATUS_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_1() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_1,
             &binaryLedgerInputResult) ==
         BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_2() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_2,
             &binaryLedgerInputResult) ==
         BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
}

void test_BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_3() {
  // then
  binary_ledger_input_result_t binaryLedgerInputResult = {0};
  assert(check_and_parse_binary_ledger_input_response(
             MOCK_BINARY_LEDGER_INPUT_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_3,
             &binaryLedgerInputResult) ==
         BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR);

  // clean
  binary_ledger_input_result_free(&binaryLedgerInputResult);
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
  test_BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_1();
  test_BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_2();
  test_BNS_RESPONSE_BINARY_FILE_URL_PARSE_ERROR_3();
  return 0;
}