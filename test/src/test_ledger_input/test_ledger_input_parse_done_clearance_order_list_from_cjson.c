#include <assert.h>
#include <bns-client/input/ledger_input.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // given
  cJSON *root = cJSON_CreateObject();
  cJSON_AddItemToArray(root, cJSON_CreateNumber(MOCK_CLEARANCE_ORDER_OK,
                                                MOCK_CLEARANCE_ORDER_OK));

  // then
  clearance_order_t result;
  assert(parse_done_clearance_order_list_from_cjson(root, &result) == BNS_OK);
  assert(result == MOCK_CLEARANCE_ORDER_OK);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_DONE_CO_PARSE_ERROR_1() {
  clearance_order_t result;
  assert(parse_done_clearance_order_list_from_cjson(NULL, &result) ==
         BNS_RESPONSE_DONE_CO_PARSE_ERROR);
}

void test_BNS_RESPONSE_DONE_CO_PARSE_ERROR_2() {
  // given
  cJSON *root = cJSON_CreateObject();

  // then
  clearance_order_t result;
  assert(parse_done_clearance_order_list_from_cjson(root, &result) ==
         BNS_RESPONSE_DONE_CO_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

void test_BNS_RESPONSE_DONE_CO_PARSE_ERROR_3() {
  // given
  cJSON *root = cJSON_CreateObject();
  cJSON_AddItemToArray(root, cJSON_CreateString(MOCK_CLEARANCE_ORDER_OK_STR));

  // then
  clearance_order_t result;
  assert(parse_done_clearance_order_list_from_cjson(root, &result) ==
         BNS_RESPONSE_DONE_CO_PARSE_ERROR);

  // clean
  cJSON_Delete(root);
}

int main() {
  test_ok();
  test_BNS_RESPONSE_DONE_CO_PARSE_ERROR_1();
  test_BNS_RESPONSE_DONE_CO_PARSE_ERROR_2();
  test_BNS_RESPONSE_DONE_CO_PARSE_ERROR_3();
  return 0;
}