#ifndef CLIENT_BNS_C_CLIENT_TEST_SRC_MOCK_DATA_MOCK_OK_DATA_H_
#define CLIENT_BNS_C_CLIENT_TEST_SRC_MOCK_DATA_MOCK_OK_DATA_H_

#include <bns-client/core/bns_types.h>

#define MOCK_INDEX_VALUE_KEY_OK "SolarPanel"
#define MOCK_EMAIL_OK "admin@itrustmachines.com"
#define MOCK_TO_SIGN_MESSAGE_OK MOCK_CALLER_ADDRESS_OK
#define MOCK_PRIVATE_KEY_OK \
  "b8059c31844941a8b37d4cac37b331d7b8059c31344941a8b37d4cac37b331d7"
#define MOCK_SERVER_URL_OK "https://azure-dev-rinkeby.itm.monster:4430"
#define MOCK_NODE_URL_OK \
  "https://rinkeby.infura.io/v3/be24c2d510194112af26339c777c46d1"
#define MOCK_PUBLIC_KEY_OK                                                     \
  "fcd72cad76e01b1dff7151844a5a96abde55bd536e05841b2157694211f0c4d3ccf54de5a4" \
  "1f31edccdddef5f6fcff43778db54cd57162c74972ba6a9aa37102"

#define MOCK_BNS_SERVER_INFO_RESPONSE_OK                                    \
  "{\"status\":\"ok\",\"description\":\"\",\"activeProfile\":\"[azure-dev-" \
  "rinkeby]\",\"version\":\"1.2.0.RC6\",\"buildTime\":\"2020-05-20 "        \
  "03:44\",\"serverWalletAddress\":"                                        \
  "\"0xA197013CA3978962B91f471C4e8C8b6DB42B14D5\",\"contractAddress\":"     \
  "\"0x1Bbe2D131a42DaEd0110fd2bE08AF56906A5a1Ce\",\"ethereumEnv\":"         \
  "\"RINKEBY\",\"clearanceCron\":\"0 0 21 * * "                             \
  "?\",\"clearanceMaxCount\":200,\"clearanceMinCount\":100}"

#define MOCK_CONTRACT_ADDRESS_OK "0x1Bbe2D131a42DaEd0110fd2bE08AF56906A5a1Ce"
#define MOCK_SERVER_WALLET_ADDRESS_OK \
  "0xA197013CA3978962B91f471C4e8C8b6DB42B14D5"

#define MOCK_SIG_REGISTER_R_OK \
  "8eb918c0093836ef1f30e7ee189466dc01896eb8ac23a10499aca8f23d4f64ee"
#define MOCK_SIG_REGISTER_S_OK \
  "004be09f8700e2052dfd664d6655fa932035440981ee28faab690bdbceab8e05"
#define MOCK_SIG_REGISTER_V_OK "1b"

#define MOCK_SERVER_INFO_REQUEST_SIG_R_OK \
  "f74737a67cfbbbe2a51fcaf24a53cdc2b8aebb832f7a829e590e054bec6ace82"
#define MOCK_SERVER_INFO_REQUEST_SIG_S_OK \
  "48d64958907fecf7390b39dae90458a0296a6317da3c03f2aa075529dfd596a1"
#define MOCK_SERVER_INFO_REQUEST_SIG_V_OK "1c"
#define MOCK_SERVER_INFO_REQUEST_JSON_OK                \
  "{\"address\":\"" MOCK_CALLER_ADDRESS_OK              \
  "\",\"toSignMessage\":\"serverInfo\",\"sig\":{\"r\":" \
  "\"" MOCK_SERVER_INFO_REQUEST_SIG_R_OK                \
  "\",\"s\":\"" MOCK_SERVER_INFO_REQUEST_SIG_S_OK       \
  "\",\"v\":\"" MOCK_SERVER_INFO_REQUEST_SIG_V_OK "\"}}"

#define MOCK_RECEIPT_LOCATOR_REQUEST_SIG_R_OK \
  "1e17b78f5c7095688402c78fd64acc5560684a82ce9360b20123d07003c63929"
#define MOCK_RECEIPT_LOCATOR_REQUEST_SIG_S_OK \
  "20442fa11e6151ae3e14f11868894be973e35adc03d6fdcba61bfaa7a6ffdcaa"
#define MOCK_RECEIPT_LOCATOR_REQUEST_SIG_V_OK "1b"
#define MOCK_RECEIPT_LOCATOR_REQUEST_JSON_OK                     \
  "{\"address\":\"" MOCK_CALLER_ADDRESS_OK                       \
  "\",\"toSignMessage\":\"clearanceOrderAndSn\",\"sig\":{\"r\":" \
  "\"" MOCK_RECEIPT_LOCATOR_REQUEST_SIG_R_OK                     \
  "\",\"s\":\"" MOCK_RECEIPT_LOCATOR_REQUEST_SIG_S_OK            \
  "\",\"v\":\"" MOCK_RECEIPT_LOCATOR_REQUEST_SIG_V_OK            \
  "\"},\"indexValueKey\":\"" MOCK_INDEX_VALUE_KEY_OK "\"}"

#define MOCK_CALLER_ADDRESS_OK "0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe"
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
#define MOCK_TIMESTAMP_OK 1595485720220
#else
#define MOCK_TIMESTAMP_OK "1595485720220"
#endif
#define MOCK_CMD_OK                                                      \
  "{\"deviceId\":\"SolarPanel\",\"timestamp\":1595485720006,\"watt\":1." \
  "420710197710718,\"voltage\":2.3838709677419354,\"current\":0."        \
  "5959677419354839,\"solarUtilizationRate\":0.11839251647589316}"
#define MOCK_INDEX_VALUE_OK "SolarPanel_R134"
#define MOCK_SN_OK 134
#define MOCK_SN_OK_STR "134"
#define MOCK_METADATA_OK ""
#define MOCK_CLEARANCE_ORDER_OK 23825
#define MOCK_CLEARANCE_ORDER_OK_STR "23825"
#define MOCK_SIG_CLIENT_R_OK \
  "73775359a2ddaeefeacee4fb1de6a2ae784f7c2664f6ea206bb4fe58b28c5cf9"
#define MOCK_SIG_CLIENT_S_OK \
  "00ab1b4fa1454b9b0211e7c819be779787ac75b15e48ef7b21d656e040a9f2ca"
#define MOCK_SIG_CLIENT_V_OK "1b"
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
#define MOCK_TIMESTAMP_BNS_OK 1595485720362
#else
#define MOCK_TIMESTAMP_BNS_OK "1595485720362"
#endif
#define MOCK_RESULT_OK "ok"
#define MOCK_SIG_SERVER_R_OK \
  "c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60"
#define MOCK_SIG_SERVER_S_OK \
  "5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57"
#define MOCK_SIG_SERVER_V_OK "1c"

#define MOCK_RECEIPT_SECOND_PART_HASH_OK \
  "b3553ea99fddb5749284759bc59d71ee74e798152037c682cd578cd63f9987b2"
#define MOCK_RECEIPT_DIGEST_VALUE_OK \
  "856f0c0accb09feb67757e1156d369ad38c473f38637d33d90b601c3e89c8820"

#define MOCK_RECEIPT_JSON_STRING_TIMESTAMP_OK                               \
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
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"

#define MOCK_MERKLE_PROOF_REQUEST_SIG_R_OK \
  "8a0357455c8492c590812ae076e104cb322eb812e9c0e63b559c47788e64a633"
#define MOCK_MERKLE_PROOF_REQUEST_SIG_S_OK \
  "6d9e68f774f4b574b1118e80caf75bac901a5a1692fecfcbd9c179d044184713"
#define MOCK_MERKLE_PROOF_REQUEST_SIG_V_OK "1b"
#define MOCK_MERKLE_PROOF_REQUEST_JSON_OK                \
  "{\"address\":\"" MOCK_CALLER_ADDRESS_OK               \
  "\",\"toSignMessage\":\"merkleProof\",\"sig\":{\"r\":" \
  "\"" MOCK_MERKLE_PROOF_REQUEST_SIG_R_OK                \
  "\",\"s\":\"" MOCK_MERKLE_PROOF_REQUEST_SIG_S_OK       \
  "\",\"v\":\"" MOCK_MERKLE_PROOF_REQUEST_SIG_V_OK       \
  "\"},\"clearanceOrder\":" MOCK_CLEARANCE_ORDER_OK_STR  \
  ",\"indexValue\":\"" MOCK_INDEX_VALUE_OK "\"}"

#define MOCK_RECEIPT_JSON_LONG_TIMESTAMP_OK                                 \
  "{\n"                                                                     \
  "        \"callerAddress\": "                                             \
  "\"0x281d8fbe2e0d83db1231b6b29c351553d4eb3afe\",\n"                       \
  "        \"timestamp\": 1595485720220,\n"                                 \
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
  "        \"timestampSPO\": 1595485720362,\n"                              \
  "        \"result\": \"ok\",\n"                                           \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"c0bafb26dda3c4e16bbd32ea1e6d85498766601eee23b8baeb4f2374143a7f60\",\n" \
  "          \"s\": "                                                       \
  "\"5046c6e590983cad539fb29e8dd81c12587b4e5b9b68ae00328cfc6c4efffa57\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"

#define MOCK_SLICE_LEAF_NODE_HASH_OK \
  "b713e40dc2ca01c3abe96a01ff5548eb03c74ec0d759571d56c2276e40baa053"
#define MOCK_SLICE_LEAF_ROOT_HASH_OK \
  "3fca75604cca1e0c5f7935de58daa49aa2d399733bb4985c72f27530bfb80c15"
#define MOCK_SLICE_OK                                                     \
  "178.b713e40dc2ca01c3abe96a01ff5548eb03c74ec0d759571d56c2276e40baa053." \
  "e6f5e0bf4bfd3f77861b147011d5a499eac5bea06ae4d1f2657dcc6b7f192438."     \
  "f038dd8c11792f8c17d1e3acec57881fd9f07edc514d65d65fa056527f7e6dae."     \
  "bda5dfad3a20b7bd0e7e5f287728bf4a7a305c63de7a23f10eb2c574ffe33dac."     \
  "f1a0bbd14523d80691cdb228271d1cdcb8e893041475ed9a75c0a07f597b761b."     \
  "1998e8b6344657e170de6c1a7fd9f44ca25cea8ab5ba2b99d30ade538d4ac25f."     \
  "49a09529f337ed622d90de288b53611ee40993f4e253a9bdd4f1700e45da925d."     \
  "e13104c77872c7b41698e25ca321628e95bde74edbf0bc426572e4391be6576e."     \
  "518cbf3db6c50324412722bccb76459ba5e4be8ffa4ef9ea2d0e4c4b39cec6e5."     \
  "52e9ce8ea43c6cfadd061590999aafbe5a5cfb6fcbe2d1dc9713c7b93cc86a2a."     \
  "2e56251c407a9f7284c706290247849482742871c18ec0c7d10be86d9cfb1a93."     \
  "ca67124e21768e1436714bbe536e97aaeb0014d4dd7201ec738fd76011ab9556."     \
  "08da4e8bdbb9e97f9b26f41daf102d3634de3bd61046f32c1980c71f5f41c35c."     \
  "b9bd7fb34a3ff3bc553af8205d6caf9cc338fd0e5bcdeee254fc1e5b11b70100."     \
  "3fca75604cca1e0c5f7935de58daa49aa2d399733bb4985c72f27530bfb80c15"
#define MOCK_SLICE_ROOT_HASH_ERROR                                        \
  "178.b713e40dc2ca01c3abe96a01ff5548eb03c74ec0d759571d56c2276e40baa053." \
  "e6f5e0bf4bfd3f77861b147011d5a499eac5bea06ae4d1f2657dcc6b7f192438."     \
  "f038dd8c11792f8c17d1e3acec57881fd9f07edc514d65d65fa056527f7e6dae."     \
  "bda5dfad3a20b7bd0e7e5f287728bf4a7a305c63de7a23f10eb2c574ffe33dac."     \
  "f1a0bbd14523d80691cdb228271d1cdcb8e893041475ed9a75c0a07f597b761b."     \
  "1998e8b6344657e170de6c1a7fd9f44ca25cea8ab5ba2b99d30ade538d4ac25f."     \
  "49a09529f337ed622d90de288b53611ee40993f4e253a9bdd4f1700e45da925d."     \
  "e13104c77872c7b41698e25ca321628e95bde74edbf0bc426572e4391be6576e."     \
  "518cbf3db6c50324412722bccb76459ba5e4be8ffa4ef9ea2d0e4c4b39cec6e5."     \
  "52e9ce8ea43c6cfadd061590999aafbe5a5cfb6fcbe2d1dc9713c7b93cc86a2a."     \
  "2e56251c407a9f7284c706290247849482742871c18ec0c7d10be86d9cfb1a93."     \
  "ca67124e21768e1436714bbe536e97aaeb0014d4dd7201ec738fd76011ab9556."     \
  "08da4e8bdbb9e97f9b26f41daf102d3634de3bd61046f32c1980c71f5f41c35c."     \
  "b9bd7fb34a3ff3bc553af8205d6caf9cc338fd0e5bcdeee254fc1e5b11b70100."     \
  "0000000000000000000000000000000000000000000000000000000000000000"
#define MOCK_PBPAIR_OK                                                      \
  "[\n"                                                                     \
  "          {\n"                                                           \
  "            \"index\": 1,\n"                                             \
  "            \"keyHash\": "                                               \
  "\"c134b572bf1130cf4fb775c06ed6b84dd2c5f6c1bfbe4c6203ed13ca126edc54\",\n" \
  "            \"value\": "                                                 \
  "\"3ff3b07dda69d0b5ba3d9819c3a164eb59ff2033b32e3ede5437ef1a1b2395be\"\n"  \
  "          },\n"                                                          \
  "          {\n"                                                           \
  "            \"index\": 2,\n"                                             \
  "            \"keyHash\": "                                               \
  "\"09f165e0403e4ed038e64423ff92733832ac3b5da3b99b82b83a0cad98623bfb\",\n" \
  "            \"value\": "                                                 \
  "\"856f0c0accb09feb67757e1156d369ad38c473f38637d33d90b601c3e89c8820\"\n"  \
  "          }\n"                                                           \
  "        ]"
#define MOCK_PBPAIR_ERROR                                                   \
  "[\n"                                                                     \
  "          {\n"                                                           \
  "            \"index\": 1,\n"                                             \
  "            \"keyHash\": "                                               \
  "\"0000000000000000000000000000000000000000000000000000000000000000\",\n" \
  "            \"value\": "                                                 \
  "\"0000000000000000000000000000000000000000000000000000000000000000\"\n"  \
  "          },\n"                                                          \
  "          {\n"                                                           \
  "            \"index\": 2,\n"                                             \
  "            \"keyHash\": "                                               \
  "\"0000000000000000000000000000000000000000000000000000000000000000\",\n" \
  "            \"value\": "                                                 \
  "\"0000000000000000000000000000000000000000000000000000000000000000\"\n"  \
  "          }\n"                                                           \
  "        ]"
#define MOCK_MERKLE_PROOF_JSON_OK                                           \
  "{\n"                                                                     \
  "        \"slice\": "                                                     \
  "\"178.b713e40dc2ca01c3abe96a01ff5548eb03c74ec0d759571d56c2276e40baa053." \
  "e6f5e0bf4bfd3f77861b147011d5a499eac5bea06ae4d1f2657dcc6b7f192438."       \
  "f038dd8c11792f8c17d1e3acec57881fd9f07edc514d65d65fa056527f7e6dae."       \
  "bda5dfad3a20b7bd0e7e5f287728bf4a7a305c63de7a23f10eb2c574ffe33dac."       \
  "f1a0bbd14523d80691cdb228271d1cdcb8e893041475ed9a75c0a07f597b761b."       \
  "1998e8b6344657e170de6c1a7fd9f44ca25cea8ab5ba2b99d30ade538d4ac25f."       \
  "49a09529f337ed622d90de288b53611ee40993f4e253a9bdd4f1700e45da925d."       \
  "e13104c77872c7b41698e25ca321628e95bde74edbf0bc426572e4391be6576e."       \
  "518cbf3db6c50324412722bccb76459ba5e4be8ffa4ef9ea2d0e4c4b39cec6e5."       \
  "52e9ce8ea43c6cfadd061590999aafbe5a5cfb6fcbe2d1dc9713c7b93cc86a2a."       \
  "2e56251c407a9f7284c706290247849482742871c18ec0c7d10be86d9cfb1a93."       \
  "ca67124e21768e1436714bbe536e97aaeb0014d4dd7201ec738fd76011ab9556."       \
  "08da4e8bdbb9e97f9b26f41daf102d3634de3bd61046f32c1980c71f5f41c35c."       \
  "b9bd7fb34a3ff3bc553af8205d6caf9cc338fd0e5bcdeee254fc1e5b11b70100."       \
  "3fca75604cca1e0c5f7935de58daa49aa2d399733bb4985c72f27530bfb80c15\",\n"   \
  "        \"pbPair\": [\n"                                                 \
  "          {\n"                                                           \
  "            \"index\": 1,\n"                                             \
  "            \"keyHash\": "                                               \
  "\"c134b572bf1130cf4fb775c06ed6b84dd2c5f6c1bfbe4c6203ed13ca126edc54\",\n" \
  "            \"value\": "                                                 \
  "\"3ff3b07dda69d0b5ba3d9819c3a164eb59ff2033b32e3ede5437ef1a1b2395be\"\n"  \
  "          },\n"                                                          \
  "          {\n"                                                           \
  "            \"index\": 2,\n"                                             \
  "            \"keyHash\": "                                               \
  "\"09f165e0403e4ed038e64423ff92733832ac3b5da3b99b82b83a0cad98623bfb\",\n" \
  "            \"value\": "                                                 \
  "\"856f0c0accb09feb67757e1156d369ad38c473f38637d33d90b601c3e89c8820\"\n"  \
  "          }\n"                                                           \
  "        ],\n"                                                            \
  "        \"clearanceOrder\": 23825,\n"                                    \
  "        \"sigServer\": {\n"                                              \
  "          \"r\": "                                                       \
  "\"e5cea4797b938b528d6ef7cd7e53c7b236f2f7c066b51003dcd21993f477c809\",\n" \
  "          \"s\": "                                                       \
  "\"5ec8c721d763accd56bcac94f5f31c3700459b1ed5a31f058aa6d9caa3716410\",\n" \
  "          \"v\": \"1c\"\n"                                               \
  "        }\n"                                                             \
  "      }"
#define MOCK_CLEARANCE_RECORD_RESPONSE_OK                                      \
  "{\"jsonrpc\":\"2.0\",\"id\":1,\"result\":"                                  \
  "\"0x0000000000000000000000000000000000000000000000000000000000005d113fca75" \
  "604cca1e0c5f7935de58daa49aa2d399733bb4985c72f27530bfb80c150000000000000000" \
  "00000000000000000000000000000000000001737a5cfc08d3f177609f132e8ef57e61975d" \
  "654619431b1685270aca81814f4ade7ceec6e9000000000000000000000000000000000000" \
  "00000000000000000000000000a00000000000000000000000000000000000000000000000" \
  "0000000000000000640a5b49544d2c52483a33666361373536303463636131653063356637" \
  "39333564653538646161343961613264333939373333626234393835633732663237353330" \
  "62666238306331352c54533a313539353438353737323235332c434f3a32333832355d0000" \
  "0000000000000000000000000000000000000000000000000000\"}"

#define MOCK_REGISTER_REQUEST_SIG_REGISTER_R_OK \
  "7e46ccc50c8e78cb667e3a5511c43e07d7d6ac400f6371809e2f114cd5128445"
#define MOCK_REGISTER_REQUEST_SIG_REGISTER_S_OK \
  "54f927a3b2f0b9fd2ceddb02dd8b8d64d8182b46d37b1083f93ee43cd9fd6fd5"
#define MOCK_REGISTER_REQUEST_SIG_REGISTER_V_OK "1b"
#define MOCK_REGISTER_REQUEST_JSON_OK                                      \
  "{\"address\":\"" MOCK_CALLER_ADDRESS_OK "\",\"email\":\"" MOCK_EMAIL_OK \
  "\",\"toSignMessage\":\"" MOCK_TO_SIGN_MESSAGE_OK                        \
  "\",\"sig\":{\"r\":\"" MOCK_REGISTER_REQUEST_SIG_REGISTER_R_OK           \
  "\",\"s\":\"" MOCK_REGISTER_REQUEST_SIG_REGISTER_S_OK                    \
  "\",\"v\":\"" MOCK_REGISTER_REQUEST_SIG_REGISTER_V_OK "\"}}"

#endif  // CLIENT_BNS_C_CLIENT_TEST_SRC_MOCK_DATA_MOCK_OK_DATA_H_
