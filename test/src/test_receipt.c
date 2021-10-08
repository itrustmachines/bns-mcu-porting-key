#include <assert.h>
#include <bns-client/core/core.h>
#include <bns-client/input/receipt.h>
#include <bns-client/util/log.h>
#include <string.h>

void test_string_timestamp_ok() {
  LOG_DEBUG("test_ok() begin");
  int res;

  // given
  char *json =
      "{\"id\": 118893,"
      "\"callerAddress\": \"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\","
      "\"timestamp\": \"1589872935222\","
      "\"cmd\": "
      "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1589872935015,"
      "\\\"watt\\\":1.2601873048907384,\\\"voltage\\\":2.24516129032258,"
      "\\\"current\\\":0.561290322580645,\\\"solarUtilizationRate\\\":0."
      "10501560874089487}\","
      "\"indexValue\": \"SolarPanel_R169\","
      "\"metadata\": \"\","
      "\"clearanceOrder\": 2879,"
      "\"timestampSPO\": \"1589872935339\","
      "\"result\": \"ok\","
      "\"sigClient\": {\"r\": "
      "\"1af410dd7d4917ebd6fe0d42d7c676c79192a2886b3a36e36fdcdb2207b08a70\","
      "\"s\": "
      "\"364a1768ac261919775fc70f545bc901c2affba591a3b838403b2e6cc69d2b0e\","
      "\"v\": \"1c\"},"
      "\"sigServer\": {\"r\": "
      "\"5cabe66487e02f877621906a8484791bf059fd00867c532e368bcc91a3a78855\","
      "\"s\": "
      "\"73791d6b41ac00a91bd003d336ff2d19b16002eea53ff9a7450bb13a6e2cca66\","
      "\"v\": \"1b\"}}";
  cJSON *root = cJSON_Parse(json);

  // when
  receipt_t receipt = {0};
  res = parse_receipt_from_cjson(root, &receipt);

  // then
  if (res != BNS_OK) {
    LOG_ERROR("test_ok(), " BNS_EXIT_CODE_PRINT_FORMAT, bns_strerror(res));
  }
  assert(res == BNS_OK);
  assert(strcmp(receipt.callerAddress,
                "0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe") == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(receipt.timestamp == 1589872935222);
#else
  assert(strcmp(receipt.timestamp, "1589872935222") == 0);
#endif
  assert(
      strcmp(
          receipt.cmd,
          "{\"deviceId\":\"SolarPanel\",\"timestamp\":1589872935015,\"watt\":1."
          "2601873048907384,\"voltage\":2.24516129032258,\"current\":0."
          "561290322580645,\"solarUtilizationRate\":0.10501560874089487}") ==
      0);
  assert(strcmp(receipt.indexValue, "SolarPanel_R169") == 0);
  assert(strcmp(receipt.metadata, "") == 0);
  assert(receipt.clearanceOrder == 2879);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(receipt.timestampSPO == 1589872935339);
#else
  assert(strcmp(receipt.timestampSPO, "1589872935339") == 0);
#endif
  assert(strcmp(receipt.result, "ok") == 0);
  assert(
      strcmp(
          receipt.sigClient.r,
          "1af410dd7d4917ebd6fe0d42d7c676c79192a2886b3a36e36fdcdb2207b08a70") ==
      0);
  assert(
      strcmp(
          receipt.sigClient.s,
          "364a1768ac261919775fc70f545bc901c2affba591a3b838403b2e6cc69d2b0e") ==
      0);
  assert(strcmp(receipt.sigClient.v, "1c") == 0);
  assert(
      strcmp(
          receipt.sigServer.r,
          "5cabe66487e02f877621906a8484791bf059fd00867c532e368bcc91a3a78855") ==
      0);
  assert(
      strcmp(
          receipt.sigServer.s,
          "73791d6b41ac00a91bd003d336ff2d19b16002eea53ff9a7450bb13a6e2cca66") ==
      0);
  assert(strcmp(receipt.sigServer.v, "1b") == 0);

  // clean
  cJSON_Delete(root);
  LOG_DEBUG("test_ok() end");
}

void test_long_timestamp_ok() {
  LOG_DEBUG("test_ok() begin");
  int res;

  // given
  char *json =
      "{\"id\": 118893,"
      "\"callerAddress\": \"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\","
      "\"timestamp\": 1589872935222,"
      "\"cmd\": "
      "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1589872935015,"
      "\\\"watt\\\":1.2601873048907384,\\\"voltage\\\":2.24516129032258,"
      "\\\"current\\\":0.561290322580645,\\\"solarUtilizationRate\\\":0."
      "10501560874089487}\","
      "\"indexValue\": \"SolarPanel_R169\","
      "\"metadata\": \"\","
      "\"clearanceOrder\": 2879,"
      "\"timestampSPO\": 1589872935339,"
      "\"result\": \"ok\","
      "\"sigClient\": {\"r\": "
      "\"1af410dd7d4917ebd6fe0d42d7c676c79192a2886b3a36e36fdcdb2207b08a70\","
      "\"s\": "
      "\"364a1768ac261919775fc70f545bc901c2affba591a3b838403b2e6cc69d2b0e\","
      "\"v\": \"1c\"},"
      "\"sigServer\": {\"r\": "
      "\"5cabe66487e02f877621906a8484791bf059fd00867c532e368bcc91a3a78855\","
      "\"s\": "
      "\"73791d6b41ac00a91bd003d336ff2d19b16002eea53ff9a7450bb13a6e2cca66\","
      "\"v\": \"1b\"}}";
  cJSON *root = cJSON_Parse(json);

  // when
  receipt_t receipt = {0};
  res = parse_receipt_from_cjson(root, &receipt);

  // then
  if (res != BNS_OK) {
    LOG_ERROR("test_ok(), " BNS_EXIT_CODE_PRINT_FORMAT, bns_strerror(res));
  }
  assert(res == BNS_OK);
  assert(strcmp(receipt.callerAddress,
                "0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe") == 0);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(receipt.timestamp == 1589872935222);
#else
  assert(strcmp(receipt.timestamp, "1589872935222") == 0);
#endif
  assert(
      strcmp(
          receipt.cmd,
          "{\"deviceId\":\"SolarPanel\",\"timestamp\":1589872935015,\"watt\":1."
          "2601873048907384,\"voltage\":2.24516129032258,\"current\":0."
          "561290322580645,\"solarUtilizationRate\":0.10501560874089487}") ==
      0);
  assert(strcmp(receipt.indexValue, "SolarPanel_R169") == 0);
  assert(strcmp(receipt.metadata, "") == 0);
  assert(receipt.clearanceOrder == 2879);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  assert(receipt.timestampSPO == 1589872935339);
#else
  assert(strcmp(receipt.timestampSPO, "1589872935339") == 0);
#endif
  assert(strcmp(receipt.result, "ok") == 0);
  assert(
      strcmp(
          receipt.sigClient.r,
          "1af410dd7d4917ebd6fe0d42d7c676c79192a2886b3a36e36fdcdb2207b08a70") ==
      0);
  assert(
      strcmp(
          receipt.sigClient.s,
          "364a1768ac261919775fc70f545bc901c2affba591a3b838403b2e6cc69d2b0e") ==
      0);
  assert(strcmp(receipt.sigClient.v, "1c") == 0);
  assert(
      strcmp(
          receipt.sigServer.r,
          "5cabe66487e02f877621906a8484791bf059fd00867c532e368bcc91a3a78855") ==
      0);
  assert(
      strcmp(
          receipt.sigServer.s,
          "73791d6b41ac00a91bd003d336ff2d19b16002eea53ff9a7450bb13a6e2cca66") ==
      0);
  assert(strcmp(receipt.sigServer.v, "1b") == 0);

  // clean
  cJSON_Delete(root);
  LOG_DEBUG("test_ok() end");
}

int main() {
  test_string_timestamp_ok();
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  test_long_timestamp_ok();
#endif
  return 0;
}
