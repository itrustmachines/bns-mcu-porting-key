#include <assert.h>
#include <bns-client/input/receipt.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"
#include "../mock_data/mock_receipt_response.h"

void test_string_timestamp_ok() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_JSON_STRING_TIMESTAMP_OK);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) == BNS_OK);
  assert(strcmp(receipt.callerAddress, MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  bns_long_t timestamp;
  assert(receipt.timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(receipt.timestamp, MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(receipt.cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(receipt.indexValue, MOCK_INDEX_VALUE_OK) == 0);
  assert(strcmp(receipt.metadata, MOCK_METADATA_OK) == 0);
  assert(receipt.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(receipt.timestampSPO == MOCK_TIMESTAMP_BNS_OK);
  bns_long_t timestampSPO;
#else
  assert(strcmp(receipt.timestampSPO, MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(receipt.result, MOCK_RESULT_OK) == 0);
  assert(strcmp(receipt.sigClient.r, MOCK_SIG_CLIENT_R_OK) == 0);
  assert(strcmp(receipt.sigClient.s, MOCK_SIG_CLIENT_S_OK) == 0);
  assert(strcmp(receipt.sigClient.v, MOCK_SIG_CLIENT_V_OK) == 0);
  assert(strcmp(receipt.sigServer.r, MOCK_SIG_SERVER_R_OK) == 0);
  assert(strcmp(receipt.sigServer.s, MOCK_SIG_SERVER_S_OK) == 0);
  assert(strcmp(receipt.sigServer.v, MOCK_SIG_SERVER_V_OK) == 0);

  // clean
  cJSON_Delete(root);
}

void test_long_timestamp_ok() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) == BNS_OK);
  assert(strcmp(receipt.callerAddress, MOCK_CALLER_ADDRESS_OK) == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  bns_long_t timestamp;
  assert(receipt.timestamp == MOCK_TIMESTAMP_OK);
#else
  assert(strcmp(receipt.timestamp, MOCK_TIMESTAMP_OK) == 0);
#endif
  assert(strcmp(receipt.cmd, MOCK_CMD_OK) == 0);
  assert(strcmp(receipt.indexValue, MOCK_INDEX_VALUE_OK) == 0);
  assert(strcmp(receipt.metadata, MOCK_METADATA_OK) == 0);
  assert(receipt.clearanceOrder == MOCK_CLEARANCE_ORDER_OK);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(receipt.timestampSPO == MOCK_TIMESTAMP_BNS_OK);
  bns_long_t timestampSPO;
#else
  assert(strcmp(receipt.timestampSPO, MOCK_TIMESTAMP_BNS_OK) == 0);
#endif
  assert(strcmp(receipt.result, MOCK_RESULT_OK) == 0);
  assert(strcmp(receipt.sigClient.r, MOCK_SIG_CLIENT_R_OK) == 0);
  assert(strcmp(receipt.sigClient.s, MOCK_SIG_CLIENT_S_OK) == 0);
  assert(strcmp(receipt.sigClient.v, MOCK_SIG_CLIENT_V_OK) == 0);
  assert(strcmp(receipt.sigServer.r, MOCK_SIG_SERVER_R_OK) == 0);
  assert(strcmp(receipt.sigServer.s, MOCK_SIG_SERVER_S_OK) == 0);
  assert(strcmp(receipt.sigServer.v, MOCK_SIG_SERVER_V_OK) == 0);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_NULL_ERROR() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_JSON_STRING_TIMESTAMP_OK);

  // then
  assert(parse_receipt_from_cjson(root, NULL) == BNS_RECEIPT_NULL_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_CALLER_ADDRESS_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_CALLER_ADDRESS_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_TIMESTAMP_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_TIMESTAMP_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_TIMESTAMP_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_TIMESTAMP_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_TIMESTAMP_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_TIMESTAMP_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

#if !defined(RECEIPT_TIMESTAMP_IS_LONG)
void test_BNS_RECEIPT_TIMESTAMP_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_TIMESTAMP_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}
#endif

void test_BNS_RESPONSE_CMD_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_CMD_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_CMD_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_CMD_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_CMD_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_CMD_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_CMD_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root =
      cJSON_Parse(MOCK_RECEIPT_RESPONSE_CMD_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_INDEX_VALUE_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_INDEX_VALUE_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_INDEX_VALUE_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_INDEX_VALUE_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_METADATA_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_METADATA_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_METADATA_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_METADATA_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_METADATA_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_METADATA_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_METADATA_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_METADATA_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_1() {
  // given
  cJSON* root =
      cJSON_Parse(MOCK_RECEIPT_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_CO_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_2() {
  // given
  cJSON* root =
      cJSON_Parse(MOCK_RECEIPT_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_CO_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

#if !defined(RECEIPT_TIMESTAMP_IS_LONG)
void test_BNS_RECEIPT_TIMESTAMP_BNS_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_TIMESTAMP_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}
#endif

void test_BNS_RESPONSE_RESULT_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_RESULT_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_RESULT_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_RESULT_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_RESULT_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_RESULT_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_RESULT_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root =
      cJSON_Parse(MOCK_RECEIPT_RESPONSE_RESULT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_R_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_R_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_SIG_CLIENT_R_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_SIG_CLIENT_R_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_S_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_S_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_SIG_CLIENT_S_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_SIG_CLIENT_S_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_V_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_V_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_SIG_CLIENT_V_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_SIG_CLIENT_V_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_SERVER_R_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_SERVER_R_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_R_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_SERVER_R_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_SERVER_R_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_R_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_SIG_SERVER_R_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_SIG_SERVER_R_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_SERVER_S_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_SERVER_S_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_S_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_SERVER_S_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_SERVER_S_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_S_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_SIG_SERVER_S_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_SIG_SERVER_S_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_SERVER_V_PARSE_ERROR_1() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_SERVER_V_PARSE_ERROR_1);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_V_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_SIG_SERVER_V_PARSE_ERROR_2() {
  // given
  cJSON* root = cJSON_Parse(MOCK_RECEIPT_RESPONSE_SIG_SERVER_V_PARSE_ERROR_2);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RESPONSE_V_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RECEIPT_SIG_SERVER_V_FILED_EXCEED_DEFINED_SIZE_ERROR() {
  // given
  cJSON* root = cJSON_Parse(
      MOCK_RECEIPT_RESPONSE_SIG_SERVER_V_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // then
  receipt_t receipt = {0};
  assert(parse_receipt_from_cjson(root, &receipt) ==
         BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR);

  // clean
  cJSON_Delete(root);
}

int main() {
  test_string_timestamp_ok();
  test_long_timestamp_ok();
  test_BNS_RECEIPT_NULL_ERROR();
  test_BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_1();
  test_BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_2();
  test_BNS_RECEIPT_CALLER_ADDRESS_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_TIMESTAMP_PARSE_ERROR_1();
  test_BNS_RESPONSE_TIMESTAMP_PARSE_ERROR_2();
#if !defined(RECEIPT_TIMESTAMP_IS_LONG)
  test_BNS_RECEIPT_TIMESTAMP_FILED_EXCEED_DEFINED_SIZE_ERROR();
#endif
  test_BNS_RESPONSE_CMD_PARSE_ERROR_1();
  test_BNS_RESPONSE_CMD_PARSE_ERROR_2();
  test_BNS_RECEIPT_CMD_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR_1();
  test_BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR_2();
  test_BNS_RECEIPT_INDEX_VALUE_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_METADATA_PARSE_ERROR_1();
  test_BNS_RESPONSE_METADATA_PARSE_ERROR_2();
  test_BNS_RECEIPT_METADATA_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_1();
  test_BNS_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_2();
  test_BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_1();
  test_BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_2();
#if !defined(RECEIPT_TIMESTAMP_IS_LONG)
  test_BNS_RECEIPT_TIMESTAMP_BNS_FILED_EXCEED_DEFINED_SIZE_ERROR();
#endif
  test_BNS_RESPONSE_RESULT_PARSE_ERROR_1();
  test_BNS_RESPONSE_RESULT_PARSE_ERROR_2();
  test_BNS_RECEIPT_RESULT_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_1();
  test_BNS_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_2();
  test_BNS_RECEIPT_SIG_CLIENT_R_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_1();
  test_BNS_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_2();
  test_BNS_RECEIPT_SIG_CLIENT_S_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_1();
  test_BNS_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_2();
  test_BNS_RECEIPT_SIG_CLIENT_V_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_SIG_SERVER_R_PARSE_ERROR_1();
  test_BNS_RESPONSE_SIG_SERVER_R_PARSE_ERROR_2();
  test_BNS_RECEIPT_SIG_SERVER_R_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_SIG_SERVER_S_PARSE_ERROR_1();
  test_BNS_RESPONSE_SIG_SERVER_S_PARSE_ERROR_2();
  test_BNS_RECEIPT_SIG_SERVER_S_FILED_EXCEED_DEFINED_SIZE_ERROR();
  test_BNS_RESPONSE_SIG_SERVER_V_PARSE_ERROR_1();
  test_BNS_RESPONSE_SIG_SERVER_V_PARSE_ERROR_2();
  test_BNS_RECEIPT_SIG_SERVER_V_FILED_EXCEED_DEFINED_SIZE_ERROR();
  return 0;
}