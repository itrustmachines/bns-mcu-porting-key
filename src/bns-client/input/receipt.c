#include <bns-client/input/receipt.h>
#include <bns-client/sha256/sha256.h>
#include <bns-client/util/log.h>
#include <bns-client/util/numeric_util.h>
#include <bns-client/util/signature_util.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bns_exit_code_t receipt_first_part_to_sign_data(const receipt_t* receipt,
                                                char**           firstPart) {
  LOG_DEBUG("receipt_first_part_to_sign_data() begin");
  bns_exit_code_t exitCode = BNS_OK;
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto receipt_first_part_sign_data_fail;
  }
  if (!firstPart) {
    exitCode = BNS_RECEIPT_FIRST_PART_TO_SIGN_DATA_NULL_ERROR;
    goto receipt_first_part_sign_data_fail;
  }
  size_t firstPartSize = 0;
  firstPartSize += strlen(receipt->indexValue);
  firstPartSize += bns_digits(receipt->clearanceOrder);

  if (*firstPart) {
    *firstPart = (char*)realloc(*firstPart, sizeof(char) * (firstPartSize + 1));
  } else {
    *firstPart = (char*)malloc(sizeof(char) * (firstPartSize + 1));
  }
  sprintf(*firstPart, "%s%lld", receipt->indexValue, receipt->clearanceOrder);

  LOG_DEBUG("receipt_first_part_to_sign_data() end, firstPart=%s", *firstPart);
  return exitCode;

receipt_first_part_sign_data_fail:
  LOG_ERROR(
      "receipt_first_part_to_sign_data() error, " BNS_EXIT_CODE_PRINT_FORMAT,
      bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t receipt_second_part_hash_to_sign_data(const receipt_t* receipt,
                                                      char** secondPartHash) {
  LOG_DEBUG("receipt_second_part_hash_to_sign_data() begin");
  bns_exit_code_t exitCode   = BNS_OK;
  char*           secondPart = NULL;
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto receipt_second_part_hash_sign_data_fail;
  }
  if (!secondPartHash) {
    exitCode = BNS_RECEIPT_SECOND_PART_TO_SIGN_DATA_NULL_ERROR;
    goto receipt_second_part_hash_sign_data_fail;
  }
  size_t secondPartSize = 0;
  secondPartSize += strlen(receipt->callerAddress);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  secondPartSize += bns_digits(receipt->timestamp);
#else
  secondPartSize += strlen(receipt->timestamp);
#endif
  secondPartSize += strlen(receipt->cmd);
  secondPartSize += strlen(receipt->metadata);
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  secondPartSize += bns_digits(receipt->timestampSPO);
#else
  secondPartSize += strlen(receipt->timestampSPO);
#endif
  secondPartSize += strlen(receipt->result);
  secondPartSize += strlen(receipt->sigClient.r);
  secondPartSize += strlen(receipt->sigClient.s);
  secondPartSize += strlen(receipt->sigClient.v);

  secondPart = (char*)malloc(sizeof(char) * (secondPartSize + 1));

#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  sprintf(secondPart, "%s%lld%s%s%lld%s%s%s%s", receipt->callerAddress,
          receipt->timestamp, receipt->cmd, receipt->metadata,
          receipt->timestampSPO, receipt->result, receipt->sigClient.r,
          receipt->sigClient.s, receipt->sigClient.v);
#else
  sprintf(secondPart, "%s%s%s%s%s%s%s%s%s", receipt->callerAddress,
          receipt->timestamp, receipt->cmd, receipt->metadata,
          receipt->timestampSPO, receipt->result, receipt->sigClient.r,
          receipt->sigClient.s, receipt->sigClient.v);
#endif

  if (*secondPartHash) {
    *secondPartHash =
        (char*)realloc(*secondPartHash, sizeof(char) * HASH_STR_LEN);
  } else {
    *secondPartHash = (char*)malloc(sizeof(char) * HASH_STR_LEN);
  }
  memset(*secondPartHash, 0, HASH_STR_LEN);
  sha256((unsigned char*)secondPart, secondPartSize, *secondPartHash);
  BNS_FREE(secondPart);

  LOG_DEBUG("receipt_second_part_hash_to_sign_data() end, secondPartHash=%s",
            *secondPartHash);
  return exitCode;

receipt_second_part_hash_sign_data_fail:
  LOG_ERROR(
      "receipt_second_part_hash_to_sign_data() "
      "error, " BNS_EXIT_CODE_PRINT_FORMAT,
      bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t receipt_to_sign_data(const receipt_t* receipt,
                                     char**           toSignData) {
  LOG_DEBUG("receipt_to_sign_data() begin");
  bns_exit_code_t exitCode;
  char*           firstPart  = NULL;
  char*           secondPart = NULL;
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto receipt_sign_data_fail;
  }
  if (!toSignData) {
    exitCode = BNS_RECEIPT_TO_SIGN_DATA_NULL_ERROR;
    goto receipt_sign_data_fail;
  }
  if ((exitCode = receipt_first_part_to_sign_data(receipt, &firstPart)) !=
      BNS_OK) {
    goto receipt_sign_data_fail;
  }
  if ((exitCode = receipt_second_part_hash_to_sign_data(
           receipt, &secondPart)) != BNS_OK) {
    goto receipt_sign_data_fail;
  }
  if (*toSignData) {
    *toSignData = (char*)realloc(
        *toSignData,
        sizeof(char) * (strlen(firstPart) + strlen(secondPart) + 1));
  } else {
    *toSignData = (char*)malloc(sizeof(char) *
                                (strlen(firstPart) + strlen(secondPart) + 1));
  }
  sprintf(*toSignData, "%s%s", firstPart, secondPart);
  BNS_FREE(firstPart);
  BNS_FREE(secondPart);
  LOG_DEBUG("receipt_to_sign_data() begin, toSignData=%s", *toSignData);
  return BNS_OK;

receipt_sign_data_fail:
  if (firstPart) { BNS_FREE(firstPart); }
  if (secondPart) { BNS_FREE(secondPart); }
  LOG_ERROR("receipt_to_sign_data() " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t parse_receipt_from_cjson(cJSON* const     root,
                                         receipt_t* const receipt) {
  LOG_DEBUG("parse_receipt_from_cjson() begin");
  bns_exit_code_t exitCode = BNS_OK;
  size_t          size;
  cJSON *         temp, *sig;
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }

  temp = cJSON_GetObjectItem(root, "callerAddress");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_CALLER_ADDRESS_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= ADDRESS_0X_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->callerAddress, temp->valuestring);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "timestamp");
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  if (!cJSON_IsNumber(temp) && !cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_TIMESTAMP_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  receipt->timestamp = temp->valueint;
#else
  if (!cJSON_IsNumber(temp) && !cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_TIMESTAMP_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  if (cJSON_IsString(temp)) {
    size = strlen(temp->valuestring);
    if (size >= TIMESTAMP_STR_LEN) {
      exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
      goto parse_receipt_from_cJSON_fail;
    }
    strcpy(receipt->timestamp, temp->valuestring);
  } else {
    size_t digits = bns_digits(temp->valueint);
    if (digits >= TIMESTAMP_STR_LEN) {
      exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
      goto parse_receipt_from_cJSON_fail;
    }
    sprintf(receipt->timestamp, "%lld", temp->valueint);
  }
#endif
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "cmd");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_CMD_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= CMD_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->cmd, temp->valuestring);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "indexValue");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_INDEX_VALUE_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= INDEX_VALUE_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->indexValue, temp->valuestring);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "metadata");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_METADATA_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size > METADATA_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->metadata, temp->valuestring);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "clearanceOrder");
  if (!cJSON_IsNumber(temp)) {
    exitCode = BNS_RESPONSE_CO_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  receipt->clearanceOrder = (long long int)temp->valueint;
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "timestampSPO");
#if defined(RECEIPT_TIMESTAMP_IS_LONG)
  if (!cJSON_IsNumber(temp) && !cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  receipt->timestampSPO = temp->valueint;
#else
  if (!cJSON_IsNumber(temp) && !cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_TIMESTAMP_BNS_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  if (cJSON_IsString(temp)) {
    size = strlen(temp->valuestring);
    if (size >= TIMESTAMP_STR_LEN) {
      exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
      goto parse_receipt_from_cJSON_fail;
    }
    strcpy(receipt->timestampSPO, temp->valuestring);
  } else {
    size_t digits = bns_digits(temp->valueint);
    if (digits >= TIMESTAMP_STR_LEN) {
      exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
      goto parse_receipt_from_cJSON_fail;
    }
    sprintf(receipt->timestampSPO, "%lld", temp->valueint);
  }
#endif
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(root, "result");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_RESULT_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= RESULT_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->result, temp->valuestring);
  cJSON_DetachItemViaPointer(root, temp);
  cJSON_Delete(temp);

  sig  = cJSON_GetObjectItem(root, "sigClient");
  temp = cJSON_GetObjectItem(sig, "r");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_R_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= SIG_R_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->sigClient.r, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(sig, "s");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_S_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= SIG_S_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->sigClient.s, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(sig, "v");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_V_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= SIG_V_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->sigClient.v, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);
  cJSON_DetachItemViaPointer(root, sig);
  cJSON_Delete(sig);

  sig  = cJSON_GetObjectItem(root, "sigServer");
  temp = cJSON_GetObjectItem(sig, "r");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_R_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= SIG_R_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->sigServer.r, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(sig, "s");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_S_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= SIG_S_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->sigServer.s, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);

  temp = cJSON_GetObjectItem(sig, "v");
  if (!cJSON_IsString(temp)) {
    exitCode = BNS_RESPONSE_V_PARSE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  size = strlen(temp->valuestring);
  if (size >= SIG_V_STR_LEN) {
    exitCode = BNS_RECEIPT_FILED_EXCEED_DEFINED_SIZE_ERROR;
    goto parse_receipt_from_cJSON_fail;
  }
  strcpy(receipt->sigServer.v, temp->valuestring);
  cJSON_DetachItemViaPointer(sig, temp);
  cJSON_Delete(temp);
  cJSON_DetachItemViaPointer(root, sig);
  cJSON_Delete(sig);
  LOG_DEBUG("parse_receipt_from_cjson() end");
  return exitCode;

parse_receipt_from_cJSON_fail:
  LOG_ERROR("parse_receipt_from_cjson() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t receipt_check_sig(const char* const      serverWalletAddress,
                                  const receipt_t* const receipt) {
  bns_exit_code_t exitCode;
  char*           toSignData = NULL;
  if (!serverWalletAddress) {
    exitCode = BNS_SERVER_WALLET_ADDRESS_NULL_ERROR;
    goto receipt_check_sig_fail;
  }
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto receipt_check_sig_fail;
  }
  LOG_DEBUG(
      "receipt_check_sig() begin, "
      "serverWalletAddress=%s, " RECEIPT_PRINT_FORMAT,
      serverWalletAddress, RECEIPT_TO_PRINT_ARGS(receipt));

  if ((exitCode = receipt_to_sign_data(receipt, &toSignData)) != BNS_OK) {
    goto receipt_check_sig_fail;
  }
  if ((exitCode = verify_signature(serverWalletAddress, toSignData,
                                   &receipt->sigServer)) != BNS_OK) {
    goto receipt_check_sig_fail;
  }
  BNS_FREE(toSignData);
  return exitCode;

receipt_check_sig_fail:
  if (toSignData) { BNS_FREE(toSignData); }
  LOG_ERROR("receipt_check_sig() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t receipt_to_digest_value(const receipt_t* const receipt,
                                        char** const           digestValue) {
  LOG_DEBUG("receipt_to_digest_value() start");
  bns_exit_code_t exitCode;
  char*           signData = NULL;
  char*           buffer   = NULL;
  if (!receipt) {
    exitCode = BNS_RECEIPT_NULL_ERROR;
    goto receipt_to_digest_value_fail;
  }
  if (!digestValue) {
    exitCode = BNS_RECEIPT_DIGEST_NULL_ERROR;
    goto receipt_to_digest_value_fail;
  }
  if ((exitCode = receipt_to_sign_data(receipt, &signData)) != BNS_OK) {
    goto receipt_to_digest_value_fail;
  }
  size_t size = 0;
  size += strlen(signData);
  size += strlen(receipt->sigServer.r);
  size += strlen(receipt->sigServer.s);
  size += strlen(receipt->sigServer.v);
  buffer = (char*)malloc(sizeof(char) * (size + 1));
  sprintf(buffer, "%s%s%s%s", signData, receipt->sigServer.r,
          receipt->sigServer.s, receipt->sigServer.v);

  BNS_FREE(signData);
  if (*digestValue) {
    *digestValue = (char*)realloc(*digestValue, sizeof(char) * HASH_STR_LEN);
  } else {
    *digestValue = (char*)malloc(sizeof(char) * HASH_STR_LEN);
  }
  memset(*digestValue, 0, HASH_STR_LEN);
  sha256((unsigned char*)buffer, strlen(buffer), *digestValue);
  BNS_FREE(buffer);

  LOG_DEBUG("receipt_to_digest_value() end");
  return exitCode;

receipt_to_digest_value_fail:
  if (signData) { BNS_FREE(signData); }
  LOG_ERROR("receipt_to_digest_value() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}
