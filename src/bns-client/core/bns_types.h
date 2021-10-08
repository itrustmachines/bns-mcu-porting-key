#ifndef BNS_C_CLIENT_BNS_TYPES_H
#define BNS_C_CLIENT_BNS_TYPES_H

#include <bns-client/core/bns_definitions.h>
#include <stdbool.h>
#include <stddef.h>

typedef long long int bns_long_t;

typedef bns_long_t clearance_order_t;

typedef bns_long_t sn_t;

typedef struct bns_client_config_t {
  char privateKey[PRIVATE_KEY_STR_LEN];
  char *indexValueKey;
  char *email;
  char *serverUrl;
  char *nodeUrl;
} bns_client_config_t;

typedef struct sig_t {
  char r[SIG_R_STR_LEN];
  char s[SIG_S_STR_LEN];
  char v[SIG_V_STR_LEN];
} sig_t;

typedef struct receipt_t {
  char callerAddress[ADDRESS_0X_STR_LEN];
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  bns_long_t timestamp;
#else
  char timestamp[TIMESTAMP_STR_LEN];
#endif
  char cmd[CMD_LEN];
  char indexValue[INDEX_VALUE_LEN];
  char metadata[METADATA_LEN];
  clearance_order_t clearanceOrder;
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  bns_long_t timestampSPO;
#else
  char timestampSPO[TIMESTAMP_STR_LEN];
#endif
  char result[RESULT_LEN];
  sig_t sigClient;
  sig_t sigServer;
} receipt_t;

typedef struct pb_pair_value_t {
  bns_long_t index;
  char keyHash[PB_PAIR_KEY_STR_LEN];
  char value[PB_PAIR_VALUE_STR_LEN];
} pb_pair_value_t;

typedef struct pb_pair_t {
  size_t size;
  pb_pair_value_t *pbPairValue;
} pb_pair_t;

typedef struct ledger_input_response_t {
  char *status;
  char *description;
  receipt_t *receipt;
  clearance_order_t doneClearanceOrder;
} ledger_input_result_t;

typedef struct binary_ledger_input_response_t {
  char *status;
  char *description;
  receipt_t *receipt;
  clearance_order_t doneClearanceOrder;
  char *binaryFileUrl;
} binary_ledger_input_result_t;

typedef struct slice_t {
  bns_long_t index;
  char *hashString;
  size_t size;
  char **hashStringList;
} slice_t;

typedef struct merkle_proof_t {
  slice_t slice;
  pb_pair_t pbPair;
  clearance_order_t clearanceOrder;
  sig_t sigServer;
} merkle_proof_t;

typedef struct receipt_locator_t {
  clearance_order_t clearanceOrder;
  char *indexValue;
} receipt_locator_t;

typedef struct verify_receipt_result_t {
  clearance_order_t clearanceOrder;
  char *indexValue;
  bool pass;
  char *status;
  char *timestamp;
  char *description;
  bool receiptSignatureOk;
  bool merkleproofSignatureOk;
  bool clearanceOrderOk;
  bool pbPairOk;
  bool sliceOk;
  bool clearanceRecordRootHashOk;
} verify_receipt_result_t;

typedef struct register_request_t {
  char address[ADDRESS_0X_STR_LEN];
  char *email;
  char *toSignMessage;
  sig_t sig;
} register_request_t;

typedef struct ledger_input_request_t {
  char callerAddress[ADDRESS_0X_STR_LEN];
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  bns_long_t timestamp;
#else
  char *timestamp;
#endif
  char *cmd;
  char *indexValue;
  char *metadata;
  clearance_order_t clearanceOrder;
  sig_t sigClient;
} ledger_input_request_t;

typedef struct clearance_record_t {
  clearance_order_t clearanceOrder;
  char rootHash[HASH_STR_LEN];
  char chainHash[HASH_STR_LEN];
} clearance_record_t;

typedef struct receipt_dao_t {
  void (*save)(const receipt_t *receipt);
  void (*findPageByClearanceOrderEqualOrLessThan)(
      const clearance_order_t clearanceOrder, const size_t page,
      const size_t pageSize, receipt_t *outputReceipt, size_t *outputSize);
  void (*delete)(const receipt_t *receipt);
} receipt_dao_t;

typedef struct binary_info_t {
  char *filename;
  char *data;
  size_t len;
} binary_info_t;

typedef struct bns_form_t {
  char *key;
  char *contentType;
  char *filename;
  char *value;
  size_t valueLen;
} bns_form_t;

typedef struct http_client_t {
  _CHECK_RESULT
  char *(*get)(const char *url);
  _CHECK_RESULT
  char *(*post)(const char *url, const char *postData);
  _CHECK_RESULT
  char *(*post_multi)(const char *url, const bns_form_t *form1,
                      const bns_form_t *form2);
  _CHECK_RESULT
  char *(*eth_post)(const char *url, const char *postData);
} http_client_t;

typedef struct bns_client_callback_t {
  void (*register_callback)(const register_request_t *registerRequest,
                            const bool result);
  void (*create_ledger_input_by_cmd)(
      const receipt_locator_t *receiptLocator,
      const ledger_input_request_t *ledgerInputRequest);
  void (*obtain_ledger_input_response)(
      const receipt_locator_t *receiptLocator, const char *cmdJson,
      const ledger_input_result_t *ledgerInputResult);
  void (*obtain_binary_ledger_input_response)(
      const receipt_locator_t *receiptLocator, const char *cmdJson,
      const binary_info_t *binaryInfo,
      const binary_ledger_input_result_t *binaryLedgerInputResult);
  void (*obtain_receipt_event)(const receipt_t *receipt);
  void (*obtain_done_clearance_order_event)(clearance_order_t doneCO);
  void (*obtain_merkle_proof)(const receipt_locator_t *receiptLocator,
                              const merkle_proof_t *merkleProof);
  void (*get_verify_receipt_result)(
      const receipt_t *receipt, const merkle_proof_t *merkleProof,
      const verify_receipt_result_t *verifyReceiptResult);
} bns_client_callback_t;

typedef struct bns_server_info_t {
  char contractAddress[ADDRESS_0X_STR_LEN];
  char serverWalletAddress[ADDRESS_0X_STR_LEN];
  bool registerAuthConfig;
} bns_server_info_t;

typedef struct bns_client_t {
  bns_client_config_t config;
  char publicKey[PUBLIC_KEY_STR_LEN];
  char walletAddress[ADDRESS_0X_STR_LEN];
  size_t *verifyAfterLedgerInputCount;
  size_t *maxRetryCount;
  size_t *retryDelaySec;
  bns_server_info_t bnsServerInfo;
  receipt_dao_t receiptDao;
  http_client_t httpClient;
  bns_client_callback_t callback;
} bns_client_t;

#endif  // BNS_C_CLIENT_BNS_TYPES_H
