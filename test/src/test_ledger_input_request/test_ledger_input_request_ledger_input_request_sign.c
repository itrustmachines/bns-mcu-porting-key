#include <assert.h>
#include <bns-client/input/ledger_input_request.h>

#include "../mock_data/mock_ledger_input_request.h"

void test_ok() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);

  // then
  assert(ledger_input_request_sign(&ledgerInputRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_OK);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_1() {
  assert(ledger_input_request_sign(NULL, MOCK_PRIVATE_KEY_OK) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_2() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);
  BNS_FREE(ledgerInputRequest.cmd);

  // then
  assert(ledger_input_request_sign(&ledgerInputRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_3() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);
  BNS_FREE(ledgerInputRequest.indexValue);

  // then
  assert(ledger_input_request_sign(&ledgerInputRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_4() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);
  BNS_FREE(ledgerInputRequest.metadata);

  // then
  assert(ledger_input_request_sign(&ledgerInputRequest, MOCK_PRIVATE_KEY_OK) ==
         BNS_LEDGER_INPUT_REQUEST_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

void test_BNS_PRIVATE_KEY_NULL_ERROR() {
  // given
  ledger_input_request_t ledgerInputRequest = {0};
  mock_ledger_input_request_ok(&ledgerInputRequest);

  // then
  assert(ledger_input_request_sign(&ledgerInputRequest, NULL) ==
         BNS_PRIVATE_KEY_NULL_ERROR);

  // clean
  ledger_input_request_free(&ledgerInputRequest);
}

int main() {
  test_ok();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_1();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_2();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_3();
  test_BNS_LEDGER_INPUT_REQUEST_NULL_ERROR_4();
  test_BNS_PRIVATE_KEY_NULL_ERROR();
  return 0;
}