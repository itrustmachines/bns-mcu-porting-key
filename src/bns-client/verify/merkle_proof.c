#include <bns-client/input/receipt.h>
#include <bns-client/input/receipt_locator.h>
#include <bns-client/sha256/sha256.h>
#include <bns-client/util/log.h>
#include <bns-client/util/numeric_util.h>
#include <bns-client/util/string_util.h>
#include <bns-client/verify/merkle_proof.h>
#include <bns-client/verify/slice.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void build_get_merkle_proof_url(char**                         url,
                                const char* const              serverUrl,
                                const receipt_locator_t* const receiptLocator) {
  if (!url) { return; }
  size_t size = strlen(serverUrl) + strlen(LEDGER_VERIFY_MERKLE_PROOF) +
                bns_digits(receiptLocator->clearanceOrder) + 1 +
                strlen(receiptLocator->indexValue);
  *url = (char*)malloc(sizeof(char) * (size + 1));
  if (*url) {
    sprintf(*url, "%s%s%lld/%s", serverUrl, LEDGER_VERIFY_MERKLE_PROOF,
            receiptLocator->clearanceOrder, receiptLocator->indexValue);
  }
}

bns_exit_code_t bns_get_merkle_proof(
    const bns_client_t* const      bnsClient,
    const receipt_locator_t* const receiptLocator,
    merkle_proof_t* const          merkleProof) {
  size_t          count = 0;
  bns_exit_code_t exitCode;
  char*           url = NULL;
  char*           res = NULL;
bns_get_merkle_proof_beg:
  if (!bnsClient) {
    exitCode = BNS_CLIENT_NULL_ERROR;
    goto bns_get_merkle_proof_fail;
  }
  if (!bnsClient->config.serverUrl) {
    exitCode = BNS_CLIENT_CONFIG_SERVER_URL_NULL_ERROR;
    goto bns_get_merkle_proof_fail;
  }
  if (!bnsClient->httpClient.get) {
    exitCode = BNS_CLIENT_HTTP_CLIENT_BNS_POST_NULL_ERROR;
    goto bns_get_merkle_proof_fail;
  }
  if (!receiptLocator) {
    exitCode = BNS_RECEIPT_LOCATOR_NULL_ERROR;
    goto bns_get_merkle_proof_fail;
  }
  if (!merkleProof) {
    exitCode = BNS_MERKLE_PROOF_NULL_ERROR;
    goto bns_get_merkle_proof_fail;
  }
  LOG_INFO("bns_get_merkle_proof() begin, " RECEIPT_LOCATOR_PRINT_FORMAT,
           RECEIPT_LOCATOR_TO_PRINT_ARGS(receiptLocator));
  build_get_merkle_proof_url(&url, bnsClient->config.serverUrl, receiptLocator);

  res = bnsClient->httpClient.get(url);
  BNS_FREE(url);
  if (!res) {
    exitCode = BNS_GET_MERKLE_PROOF_RESPONSE_NULL_ERROR;
    goto bns_get_merkle_proof_fail;
  }
  exitCode = check_and_parse_merkle_proof_response(res, merkleProof);
  if (exitCode != BNS_OK) { goto bns_get_merkle_proof_fail; }
  BNS_FREE(res);
  if (bnsClient->callback.obtain_merkle_proof) {
    bnsClient->callback.obtain_merkle_proof(receiptLocator, merkleProof);
  }
  LOG_INFO("bns_get_merkle_proof() end");
#if LOG_LEVEL >= LOG_LEVEL_INFO
  merkle_proof_print(merkleProof);
#endif
  return exitCode;

bns_get_merkle_proof_fail:
  if (url) { BNS_FREE(url); }
  if (res) { BNS_FREE(res); }
  LOG_ERROR("bns_get_merkle_proof() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  if (bnsClient && bnsClient->maxRetryCount) {
    if (count++ < *bnsClient->maxRetryCount) {
      LOG_DEBUG("bns_get_merkle_proof() retry, count=%ld", count);
      if (bnsClient->retryDelaySec) { sleep(*bnsClient->retryDelaySec); }
      goto bns_get_merkle_proof_beg;
    }
  }
  return exitCode;
}

bns_exit_code_t parse_pb_pair(cJSON* const root, pb_pair_t* const pbPair) {
  bns_exit_code_t exitCode = BNS_OK;
  cJSON*          temp     = NULL;
  pbPair->size             = cJSON_GetArraySize(root);
  pb_pair_value_t* pbPairValue =
      (pb_pair_value_t*)malloc(sizeof(pb_pair_value_t) * pbPair->size);
  for (size_t i = 0; i < pbPair->size; i++) {
    cJSON* pbpContent;
    pbpContent = cJSON_GetArrayItem(root, (int)i);
    temp       = cJSON_GetObjectItem(pbpContent, "index");
    if (!cJSON_IsNumber(temp)) {
      exitCode = BNS_RESPONSE_PBPAIR_PARSE_ERROR;
      goto parse_pb_pair_fail;
    }
    pbPairValue[i].index = (int)temp->valueint;
    cJSON_DetachItemViaPointer(pbpContent, temp);
    cJSON_Delete(temp);

    temp = cJSON_GetObjectItem(pbpContent, "keyHash");
    if (!temp) {
      exitCode = BNS_RESPONSE_PBPAIR_PARSE_ERROR;
      goto parse_pb_pair_fail;
    }
    strcpy(pbPairValue[i].keyHash, temp->valuestring);
    cJSON_DetachItemViaPointer(pbpContent, temp);
    cJSON_Delete(temp);

    temp = cJSON_GetObjectItem(pbpContent, "value");
    if (!cJSON_IsString(temp)) {
      exitCode = BNS_RESPONSE_PBPAIR_PARSE_ERROR;
      goto parse_pb_pair_fail;
    }
    strcpy(pbPairValue[i].value, temp->valuestring);
    cJSON_DetachItemViaPointer(pbpContent, temp);
    cJSON_Delete(temp);
  }
  pbPair->pbPairValue = pbPairValue;
  return exitCode;

parse_pb_pair_fail:
  LOG_ERROR("parse_pb_pair() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t check_and_parse_merkle_proof_response(
    const char* const res, merkle_proof_t* const merkleProof) {
  LOG_DEBUG("check_and_parse_merkle_proof_response() begin");
  bns_exit_code_t exitCode;
  cJSON*          root = NULL;
  if (!merkleProof) {
    exitCode = BNS_MERKLE_PROOF_NULL_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  root          = cJSON_Parse(res);
  cJSON* status = cJSON_GetObjectItem(root, "status");
  if (!cJSON_IsString(status)) {
    exitCode = BNS_RESPONSE_STATUS_PARSE_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  if (strcmp(BNS_STATUS_OK, status->valuestring) != 0) {
    exitCode = BNS_RESPONSE_STATUS_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  cJSON_DetachItemViaPointer(root, status);
  cJSON_Delete(status);

  cJSON* merkleProofCJSON = cJSON_GetObjectItem(root, "merkleProof");
  cJSON* temp;
  cJSON* pbPair;
  temp = cJSON_GetObjectItem(merkleProofCJSON, "slice");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_SLICE_PARSE_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  if ((exitCode = parse_slice(temp->valuestring, &merkleProof->slice)) !=
      BNS_OK) {
    goto check_and_parse_merkle_proof_response_fail;
  }
  cJSON_DetachItemViaPointer(merkleProofCJSON, temp);
  cJSON_Delete(temp);

  pbPair = cJSON_GetObjectItem(merkleProofCJSON, "pbPair");
  if ((exitCode = parse_pb_pair(pbPair, &merkleProof->pbPair)) != BNS_OK) {
    goto check_and_parse_merkle_proof_response_fail;
  }
  cJSON_DetachItemViaPointer(merkleProofCJSON, pbPair);
  cJSON_Delete(pbPair);

  temp = cJSON_GetObjectItem(merkleProofCJSON, "clearanceOrder");
  if (!cJSON_IsNumber(temp)) {
    exitCode = BNS_JSON_PARSE_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  merkleProof->clearanceOrder = (long int)temp->valuedouble;
  cJSON_DetachItemViaPointer(merkleProofCJSON, temp);
  cJSON_Delete(temp);

  cJSON* sig;
  sig  = cJSON_GetObjectItem(merkleProofCJSON, "sigServer");
  temp = cJSON_GetObjectItem(sig, "r");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_SIG_SERVER_PARSE_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  strcpy(merkleProof->sigServer.r, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(sig, "s");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_SIG_SERVER_PARSE_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  strcpy(merkleProof->sigServer.s, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(sig, "v");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_SIG_SERVER_PARSE_ERROR;
    goto check_and_parse_merkle_proof_response_fail;
  }
  strcpy(merkleProof->sigServer.v, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);
  cJSON_DetachItemViaPointer(root, merkleProofCJSON);
  cJSON_Delete(merkleProofCJSON);

  cJSON_Delete(root);
  LOG_DEBUG("check_and_parse_merkle_proof_response() end");
  return exitCode;

check_and_parse_merkle_proof_response_fail:
  cJSON_Delete(root);
  LOG_ERROR("check_merkle_proof_response() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

void pb_pair_free(pb_pair_t* const pbPair) {
  if (pbPair) {
    if (pbPair->pbPairValue) { BNS_FREE(pbPair->pbPairValue); }
  }
}

void merkle_proof_free(merkle_proof_t* const merkleProof) {
  if (merkleProof) {
    pb_pair_free(&merkleProof->pbPair);
    slice_free(&merkleProof->slice);
  }
}

void merkle_proof_print(const merkle_proof_t* const merkleProof) {
  if (!merkleProof) { return; }
  LOG_BACKEND("merkleProof=merkle_proof_t(slice=%lld.%s",
              merkleProof->slice.index, merkleProof->slice.hashString);
  LOG_BACKEND(", pbPair=[");
  for (size_t i = 0; i < merkleProof->pbPair.size; i++) {
    if (i != 0) { LOG_BACKEND(", "); }
    LOG_BACKEND("pb_pair_t(index=%lld, keyHash=%s, value=%s)",
                merkleProof->pbPair.pbPairValue[i].index,
                merkleProof->pbPair.pbPairValue[i].keyHash,
                merkleProof->pbPair.pbPairValue[i].value);
  }
  LOG_BACKEND("]");
  LOG_BACKEND(", clearanceOrder=%lld", merkleProof->clearanceOrder);
  LOG_BACKEND(", sigServer=sig_t(r=%s, s=%s, v=%s)", merkleProof->sigServer.r,
              merkleProof->sigServer.s, merkleProof->sigServer.v);
  LOG_BACKEND(")\n");
}

bns_exit_code_t merkle_proof_to_sign_data(
    const merkle_proof_t* const merkleProof, char** const toSignData) {
  LOG_DEBUG("merkle_proof_to_sign_data() begin");
  bns_exit_code_t exitCode    = BNS_OK;
  char*           sliceString = NULL;
  if (!merkleProof) {
    exitCode = BNS_MERKLE_PROOF_NULL_ERROR;
    goto merkle_proof_to_sign_data_fail;
  }
  if (!toSignData) {
    exitCode = BNS_MERKLE_PROOF_TO_SIGN_DATA_NULL_ERROR;
    goto merkle_proof_to_sign_data_fail;
  }
  size_t size = 0;
  slice_to_string(&merkleProof->slice, &sliceString);
  size_t sliceStringLen = strlen(sliceString);
  size += sliceStringLen;
  for (size_t i = 0; i < merkleProof->pbPair.size; i++) {
    size += bns_digits(merkleProof->pbPair.pbPairValue[i].index);
    size += strlen(merkleProof->pbPair.pbPairValue[i].keyHash);
    size += strlen(merkleProof->pbPair.pbPairValue[i].value);
  }
  size += bns_digits(merkleProof->clearanceOrder);
  if (*toSignData) {
    *toSignData = (char*)realloc(*toSignData, sizeof(char) * (size + 1));
  } else {
    *toSignData = (char*)malloc(sizeof(char) * (size + 1));
  }
  strcpy(*toSignData, sliceString);
  for (size_t i = 0; i < merkleProof->pbPair.size; i++) {
    sprintf((*toSignData) + strlen(*toSignData), "%lld%s%s",
            merkleProof->pbPair.pbPairValue[i].index,
            merkleProof->pbPair.pbPairValue[i].keyHash,
            merkleProof->pbPair.pbPairValue[i].value);
  }
  sprintf((*toSignData) + strlen(*toSignData), "%lld",
          merkleProof->clearanceOrder);
  BNS_FREE(sliceString);
  LOG_DEBUG("merkle_proof_to_sign_data() end");
  return exitCode;

merkle_proof_to_sign_data_fail:
  LOG_ERROR("merkle_proof_to_sign_data() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t check_receipt_in_pbpair(const receipt_t* const receipt,
                                        const pb_pair_t* const pbPair) {
  bns_exit_code_t exitCode;
  char*           digestValue = NULL;
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto check_receipt_in_pbpair_fail;
  }
  if (!pbPair) {
    exitCode = BNS_PB_PAIR_NULL_ERROR;
    goto check_receipt_in_pbpair_fail;
  }
  LOG_DEBUG("check_receipt_in_pbpair() begin, " RECEIPT_PRINT_FORMAT,
            RECEIPT_TO_PRINT_ARGS(receipt));
  for (size_t position = 0; position < pbPair->size; position++) {
    char indexValueHash[HASH_STR_LEN] = {0};
    sha256((unsigned char*)receipt->indexValue, strlen(receipt->indexValue),
           indexValueHash);
    if (bns_equals_ignore_case(indexValueHash,
                               pbPair->pbPairValue[position].keyHash) == true) {
      if ((exitCode = receipt_to_digest_value(receipt, &digestValue)) !=
          BNS_OK) {
        goto check_receipt_in_pbpair_fail;
      }
      if (bns_equals_ignore_case(digestValue,
                                 pbPair->pbPairValue[position].value) == true) {
        BNS_FREE(digestValue);
        LOG_DEBUG("check_receipt_in_pbpair() end");
        return exitCode;
      }
      exitCode = BNS_CHECK_RECEIPT_IN_PBPAIR_ERROR;
      goto check_receipt_in_pbpair_fail;
    }
  }
  exitCode = BNS_CHECK_RECEIPT_IN_PBPAIR_ERROR;

check_receipt_in_pbpair_fail:
  if (digestValue) { BNS_FREE(digestValue); }
  LOG_ERROR("check_receipt_in_pbpair() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}
