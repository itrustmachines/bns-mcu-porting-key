#ifndef BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_RECEIPT_RESPONSE_H_
#define BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_RECEIPT_RESPONSE_H_

#define MOCK_RECEIPT_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_1                  \
  "{\n"                                                                     \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_CALLER_ADDRESS_PARSE_ERROR_2                  \
  "{\n"                                                                     \
  "        \"callerAddress\": 200,\n"                                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_CALLER_ADDRESS_FILED_EXCEED_DEFINED_SIZE_ERROR   \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe000000000000000000000000000\"," \
  "\n"                                                                         \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": "                                                          \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006,"    \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"         \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."         \
  "11839251647589316}\",\n"                                                    \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                             \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n"    \
  "          \"s\": "                                                          \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n"    \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n"    \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n"    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_TIMESTAMP_PARSE_ERROR_1                       \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_TIMESTAMP_PARSE_ERROR_2                       \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": false,\n"                                         \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#if !defined(RECEIPT_TIMESTAMP_IS_LONG)
#define MOCK_RECEIPT_RESPONSE_TIMESTAMP_FILED_EXCEED_DEFINED_SIZE_ERROR     \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"159548572022000000000\",\n"                     \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#endif
#define MOCK_RECEIPT_RESPONSE_CMD_PARSE_ERROR_1                             \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_CMD_PARSE_ERROR_2                             \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": 200,"                                                   \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_CMD_FILED_EXCEED_DEFINED_SIZE_ERROR              \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                          \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": \"{exceed 1000 len string "                                \
  "00000000000000000000000000000000000000000000000000000000000000000000000000" \
  "000"                                                                        \
  "                    "                                                       \
  "11111111111111111111111111111111111111111111111111111111111111111111111111" \
  "11111111111111111111111111"                                                 \
  "                    "                                                       \
  "22222222222222222222222222222222222222222222222222222222222222222222222222" \
  "22222222222222222222222222"                                                 \
  "                    "                                                       \
  "33333333333333333333333333333333333333333333333333333333333333333333333333" \
  "33333333333333333333333333"                                                 \
  "                    "                                                       \
  "44444444444444444444444444444444444444444444444444444444444444444444444444" \
  "44444444444444444444444444"                                                 \
  "                    "                                                       \
  "55555555555555555555555555555555555555555555555555555555555555555555555555" \
  "55555555555555555555555555"                                                 \
  "                    "                                                       \
  "66666666666666666666666666666666666666666666666666666666666666666666666666" \
  "66666666666666666666666666"                                                 \
  "                    "                                                       \
  "77777777777777777777777777777777777777777777777777777777777777777777777777" \
  "77777777777777777777777777"                                                 \
  "                    "                                                       \
  "88888888888888888888888888888888888888888888888888888888888888888888888888" \
  "88888888888888888888888888"                                                 \
  "                    "                                                       \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999"                                                 \
  "                    "                                                       \
  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
  "aaaaaaaaaaaaaaaaaaaaaaaaaa"                                                 \
  "                   }\",\n"                                                  \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                             \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n"    \
  "          \"s\": "                                                          \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n"    \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n"    \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n"    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_INDEX_VALUE_PARSE_ERROR_1                     \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_INDEX_VALUE_PARSE_ERROR_2                     \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": 200,\n"                                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_INDEX_VALUE_FILED_EXCEED_DEFINED_SIZE_ERROR      \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                          \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": "                                                          \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006,"    \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"         \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."         \
  "11839251647589316}\",\n"                                                    \
  "        \"indexValue\": "                                                   \
  "\"SolarPanel00000000000000000000000000000000000000000000000000000000000000" \
  "0000000000000000000000000000000000_R134\",\n"                               \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n"    \
  "          \"s\": "                                                          \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n"    \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n"    \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n"    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_METADATA_PARSE_ERROR_1                        \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_METADATA_PARSE_ERROR_2                        \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": 200,\n"                                            \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_METADATA_FILED_EXCEED_DEFINED_SIZE_ERROR      \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": "                                                  \
  "\"0000000000000000000000000000000000000000000000000000\",\n"             \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_1                 \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_CLEARANCE_ORDER_PARSE_ERROR_2                 \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": false,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_1                   \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR_2                   \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\":false,\n"                                       \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_RESULT_PARSE_ERROR_1                          \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_RESULT_PARSE_ERROR_2                          \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": 200,\n"                                              \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_RESULT_FILED_EXCEED_DEFINED_SIZE_ERROR        \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": "                                                    \
  "\"0000000000000000000000000000000000000000000000000\",\n"                \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_1                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_R_PARSE_ERROR_2                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": 200,\n"                                                 \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_R_FILED_EXCEED_DEFINED_SIZE_ERROR     \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                          \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": "                                                          \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006,"    \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"         \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."         \
  "11839251647589316}\",\n"                                                    \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                             \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"00000000000000000073775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe" \
  "58b28c5cf9\",\n"                                                            \
  "          \"s\": "                                                          \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n"    \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n"    \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n"    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_1                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_S_PARSE_ERROR_2                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": 200,\n"                                                 \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_S_FILED_EXCEED_DEFINED_SIZE_ERROR     \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                          \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": "                                                          \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006,"    \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"         \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."         \
  "11839251647589316}\",\n"                                                    \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                             \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n"    \
  "          \"s\": "                                                          \
  "\"0000000000000000000000000000000000ab1b4fa1454b9b0211e7c819be779787ac75b1" \
  "5e48ef7b21d656e040a9f2ca\",\n"                                              \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n"    \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n"    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_1                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\"\n"  \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_V_PARSE_ERROR_2                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": 200\n"                                                  \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_CLIENT_V_FILED_EXCEED_DEFINED_SIZE_ERROR  \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b0000000000000000000000000\"\n"                      \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_R_PARSE_ERROR_1                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_R_PARSE_ERROR_2                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": 200,\n"                                                 \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_R_FILED_EXCEED_DEFINED_SIZE_ERROR     \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                          \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": "                                                          \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006,"    \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"         \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."         \
  "11839251647589316}\",\n"                                                    \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                             \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n"    \
  "          \"s\": "                                                          \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n"    \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f6000000000" \
  "000000000000000000000000000000\",\n"                                        \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n"    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_S_PARSE_ERROR_1                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_S_PARSE_ERROR_2                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": 200,\n"                                                 \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_S_FILED_EXCEED_DEFINED_SIZE_ERROR     \
  "{\n"                                                                        \
  "        \"callerAddress\": "                                                \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                          \
  "        \"timestamp\": \"1595485720220\",\n"                                \
  "        \"cmd\": "                                                          \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006,"    \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"         \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."         \
  "11839251647589316}\",\n"                                                    \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                             \
  "        \"metadata\": \"\",\n"                                              \
  "        \"clearanceOrder\": 23825,\n"                                       \
  "        \"sigClient\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n"    \
  "          \"s\": "                                                          \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n"    \
  "          \"v\": \"1b\"\n"                                                  \
  "        },\n"                                                               \
  "        \"timestampSPO\": \"1595485720362\",\n"                             \
  "        \"result\": \"ok\",\n"                                              \
  "        \"sigServer\": {\n"                                                 \
  "          \"r\": "                                                          \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n"    \
  "          \"s\": "                                                          \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa5700000000" \
  "0000000000000000000000000000000000\",\n"                                    \
  "          \"v\": \"1c\"\n"                                                  \
  "        }\n"                                                                \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_V_PARSE_ERROR_1                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\"\n"  \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_V_PARSE_ERROR_2                    \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": 200\n"                                                  \
  "        }\n"                                                             \
  "      }"
#define MOCK_RECEIPT_RESPONSE_SIG_SERVER_V_FILED_EXCEED_DEFINED_SIZE_ERROR  \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": \"1595485720220\",\n"                             \
  "        \"cmd\": "                                                       \
  "\"{\\\"deviceId\\\":\\\"SolarPanel\\\",\\\"timestamp\\\":1595485720006," \
  "\\\"watt\\\":1.420710197710718,\\\"voltage\\\":2.3838709677419354,"      \
  "\\\"current\\\":0.5959677419354839,\\\"solarUtilizationRate\\\":0."      \
  "11839251647589316}\",\n"                                                 \
  "        \"indexValue\": \"SolarPanel_R134\",\n"                          \
  "        \"metadata\": \"\",\n"                                           \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigClient\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9\",\n" \
  "          \"s\": "                                                       \
  "\"00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca\",\n" \
  "          \"v\": \"1b\"\n"                                               \
  "        },\n"                                                            \
  "        \"timestampSPO\": \"1595485720362\",\n"                          \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c0000000000000000000000000000000000000000\"\n"       \
  "        }\n"                                                             \
  "      }"
#endif  // BNS_CLIENT_TEST_SRC_MOCK_DATA_MOCK_RECEIPT_RESPONSE_H_
