## Configure the Setting of BNS Client

### About the Setting of BNS Client

To let the BNS Client operations more flexible, we allow developers to configure some settings in BNS Client. In this document, We are going to guide you to all the setting of BNS Client and help you to configure the setting to meet your demands.

### Prerequisites

- Complete the quickstarts document
- Complete the CMD document
- Complete the Callback document
- Complete the ReceiptDao document

### Settings

We define 4 settings in BNS Client, which are

- `bns_client_set_verify_after_ledger_input_count` : set the number of receipts to be verified after doing ledgerInput
- `bns_client_set_retry_count` : set the maximum retry count of failed ledgerInput
- `bns_client_set_retry_delay_sec` : set the delay time for each retry
- `bns_client_verify_now` : set the numbers of receipt to be verified, if `receipt_cache_size` is full

### bns_client_set_verify_after_ledger_input_count

**BNS Client will verify receipts after each ledgerInput in case excessive receipt reduce the system performance**

- The `bns_client_set_verify_after_ledger_input_count` will be configured when we initialize the BNS Client, the default is 2

- The default setting, `DEFAULT_VERIFY_AFTER_LEDGER_INPUT_COUNT`, is defined in [bns_client.h](../src/bns-client/spo_client.h)

- Developer can change the number in `spo_client_set_verify_after_ledger_input_count` to configure the setting. Please check [spo_client_example.c](../example/bns-client-example/spo_client_example.c)

- If `spo_client_set_verify_after_ledger_input_count` is greater than 0 ，the BNS Client will call `spo_client_verify_by_done_co` to verify the receipt, otherwise, the BNS Client will keep ledgerInput until the the number of receipts meet the `receipt_cache_size`.

- If the memory limited is too little, you can set the number higher, but the performance of ledgerInput will decrease.

- If you want to make the ledgerInput more efficient, you can set the number smaller but the usage of the memory will increase.

- [spo_client_example.c](../example/bns-client-example/spo_client_example.c)

  ```C
  int spo_client_example() {
    ...
    ...
    if ((spoExitCode = spo_client_set_verify_after_ledger_input_count( &spoClient, 2)) != BNS_OK) {
      goto spo_client_example_fail;
    }
    ...
    ...
  }
  ...
  ...
  while (true) {
    if (receipt_cache_count() < RECEIPT_CACHE_SIZE) {

      char cmdJson[CMD_LEN] = {0};
      char *timestamp = get_timestamp_string();

      sprintf(cmdJson, "{\"deviceId\":\"%s\",\"timestamp\":%s}",
              INDEX_VALUE_KEY, timestamp);
      BNS_FREE(timestamp);

      if ((spoExitCode = spo_client_ledger_input(&spoClient, cmdJson)) !=
          BNS_OK) {
        goto spo_client_example_fail;
      }

    } else {

      if ((spoExitCode = spo_client_verify_now(&spoClient, 5)) != BNS_OK) {
        goto spo_client_example_fail;
      }
      nanosleep((const struct timespec[]){{1L, 0L}}, NULL);
    }
    ...
    ...
  }
  ```

- [spo_client.c](../src/bns-client/spo_client.c)

  ```C
  spo_exit_code_t spo_client_set_verify_after_ledger_input_count( spo_client_t *const spoClient, const size_t count) {
    if (!spoClient) {
      return BNS_CLIENT_NULL_ERROR;
    }
    if (!spoClient->verifyAfterLedgerInputCount) {
      spoClient->verifyAfterLedgerInputCount = (size_t *)malloc(sizeof(size_t));
    }
    *spoClient->verifyAfterLedgerInputCount = count;
    return BNS_OK;
  }

  spo_exit_code_t spo_client_init(
    spo_client_t *const spoClient, const char *const privateKey,
    const char *const indexValueKey, const char *const serverUrl,
    const char *const nodeUrl, const receipt_dao_t *const receiptDao,
    const http_client_t *const httpClient,
    const spo_client_callback_t *const spoClientCallback) {
      ...
      ...
      if (!spoClient->verifyAfterLedgerInputCount) {
        if ((exitCode = spo_client_set_verify_after_ledger_input_count( spoClient,DEFAULT_VERIFY_AFTER_LEDGER_INPUT_COUNT)) != BNS_OK) {
          goto spo_client_init_fail;
        }
      }
      ...
      ...
  }

  spo_exit_code_t spo_client_ledger_input(
    const spo_client_t *const spoClient,
    const char *const cmdJson) {
      ...
      ...
      bool verifyAfterLedgerInput = spoClient->verifyAfterLedgerInputCount ? *spoClient->verifyAfterLedgerInputCount > 0 : false;
    
      if (verifyAfterLedgerInput) {
        exitCode = spo_client_verify_by_done_co( spoClient, *spoClient->verifyAfterLedgerInputCount, ledgerInputResult.doneClearanceOrder);
      }
      ...
      ...
  }
  
  spo_exit_code_t spo_client_verify_by_done_co(
    const spo_client_t *const spoClient, const size_t verifyCount,
    const clearance_order_t doneCO) {
      
      size_t toVerifyCount = verifyCount;
      size_t receiptCount = 0;
      do {
        size_t count = toVerifyCount <= VERIFY_BATCH_SIZE ? toVerifyCount : VERIFY_BATCH_SIZE;
        ...
        ...
        spoClient->receiptDao.findPageByClearanceOrderEqualOrLessThan(doneCO, 0, count, receipt, &receiptCount);
        ...
        ...
        for (size_t i = 0; i < receiptCount; i++) {
          erkle_proof_t merkleProof = {0};
          verify_receipt_result_t verifyReceiptResult = {0};
          exitCode = verify(spoClient, &receipt[i], &merkleProof, &verifyReceiptResult);
          
          if (spoClient->spoClientCallback.get_verify_receipt_result) { 
            spoClient->spoClientCallback.get_verify_receipt_result( &receipt[i], &merkleProof, &verifyReceiptResult);
          }
          ...
          ...
        }
        toVerifyCount -= receiptCount;
      } while (toVerifyCount > 0 && receiptCount != 0);
    }
  ```

### spo_client_set_retry_count

**In case the failed ledgerInput affect other ledgerInput, developer can set the maximum retry count here**

- The `spo_client_set_retry_count` will be configured when we initialize the BNS Client, the default is 5.
- The default setting, `DEFAULT_MAX_RETRY_COUNT`, is defined in [spo_client.h](../src/bns-client/spo_client.h)
- Developer can change the number in `spo_client_set_retry_count` to configure the setting. Please check [spo_client_example.c](../example/bns-client-example/spo_client_example.c)

- [spo_client_example.c](../example/bns-client-example/spo_client_example.c)

  ```C
  int spo_client_example() {
    ...
    ...
    if ((spoExitCode = spo_client_set_retry_count(&spoClient, 5)) != BNS_OK) { 
      goto spo_client_example_fail;
    }
    ...
    ...
  }
  ```

- [spo_client.c](../src/bns-client/spo_client.c)

  ```C
  spo_exit_code_t spo_client_set_retry_count(spo_client_t *const spoClient, const size_t count) {
    if (!spoClient) {
      return BNS_CLIENT_NULL_ERROR;
    }
    if (!spoClient->maxRetryCount) {
      spoClient->maxRetryCount = (size_t *)malloc(sizeof(size_t));
    }
    *spoClient->maxRetryCount = count;
    return BNS_OK;
  }

  spo_exit_code_t spo_client_init(
    spo_client_t *const spoClient, const char *const privateKey,
    const char *const indexValueKey, const char *const serverUrl,
    const char *const nodeUrl, const receipt_dao_t *const receiptDao,
    const http_client_t *const httpClient,
    const spo_client_callback_t *const spoClientCallback) {
      ...
      ...
      if (!spoClient->maxRetryCount) {
        if ((exitCode = spo_client_set_retry_count(spoClient, DEFAULT_MAX_RETRY_COUNT)) != BNS_OK) {
          goto spo_client_init_fail;
        }
      }
      ...
      ...
  }

  spo_exit_code_t spo_client_ledger_input(
    const spo_client_t *const spoClient,
    const char *const cmdJson) {
      ...
      ...
      size_t retryCount = spoClient->maxRetryCount ? *spoClient->maxRetryCount : 0;
      do {
        if (retryCount > 0) {
          retryCount--;
        }
        ...
        ...
        // ledgerInput 成功，離開此迴圈
        exitCode = spo_post_ledger_input(spoClient, cmdJson, &receiptLocator, &ledgerInputResult);
        if (exitCode == BNS_OK) {
          break;
        }
        ...
        ...
      } while (retryCount > 0);
      ...
      ...
    }
  ```

### spo_client_set_retry_delay_sec

**In case the failed ledgerInput keep retrying and it affect performance, developers can set the maximum retry delay seconds here**

- The `spo_client_set_retry_delay_sec` will be configured to initialize the BNS Client, the default is 5.
- The default setting, `DEFAULT_RETRY_DELAY_SEC`, is defined in [spo_client.h](../src/bns-client/spo_client.h).
- Developer can change the number in `spo_client_set_retry_delay_sec` to configure the setting. Please check [spo_client_example.c](../example/bns-client-example/spo_client_example.c).

- [spo_client_example.c](../example/bns-client-example/spo_client_example.c)

  ```C
  int spo_client_example() {
    ...
    ...
    if ((spoExitCode = spo_client_set_retry_delay_sec(&spoClient, 5)) != BNS_OK) {
      goto spo_client_example_fail;
    }
    ...
    ...
  }
  ```

- [spo_client.c](../src/bns-client/spo_client.c)

  ```C
  spo_exit_code_t spo_client_set_retry_delay_sec(spo_client_t *const spoClient, const size_t sec) {
    if (!spoClient) {
      return BNS_CLIENT_NULL_ERROR;
    }
    if (!spoClient->retryDelaySec) {
      spoClient->retryDelaySec = (size_t *)malloc(sizeof(size_t));
    }
    *spoClient->retryDelaySec = sec;
    return BNS_OK;
  }

  spo_exit_code_t spo_client_init(
    spo_client_t *const spoClient, const char *const privateKey,
    const char *const indexValueKey, const char *const serverUrl,
    const char *const nodeUrl, const receipt_dao_t *const receiptDao,
    const http_client_t *const httpClient,
    const spo_client_callback_t *const spoClientCallback) {
      ...
      ...
      if (!spoClient->retryDelaySec) {
        if ((exitCode = spo_client_set_retry_delay_sec( spoClient, DEFAULT_RETRY_DELAY_SEC)) != BNS_OK) {
          goto spo_client_init_fail;
        }
      }
      ...
      ...
  }

  spo_exit_code_t spo_client_ledger_input(
    const spo_client_t *const spoClient,
    const char *const cmdJson) {

      ...
      ...
      do {
        if (retryCount > 0) {
          retryCount--;
        }
        ...
        ...
        // ledgerInput 成功，離開此迴圈
        exitCode = spo_post_ledger_input(spoClient, cmdJson, &receiptLocator, &ledgerInputResult);
        if (exitCode == BNS_OK) {
          break;
        }
        
        if (is_ledger_input_resend_error(exitCode)) {
          LOG_WARN("spo_client_ledger_input() resend, " BNS_EXIT_CODE_PRINT_FORMAT, spo_strerror(exitCode));
            
          if (spoClient->retryDelaySec) {
            sleep(*spoClient->retryDelaySec);
          }
        
          continue;
        }
        ...
        ...
      } while (retryCount > 0);
    }
    ```

### spo_client_verify_now

**The BNS Client verifies the receipt after ledgerInput. In addition, the BNS Client also verifies the receipt when the number of receipt reaches the `receipt_cache_size`**

- When the BNS Client calls `spo_client_verify_now`, the BNS Client will request the latest `doneClearanceOrder` from the BNS Server and call `receipt_cache_findPageByClearanceOrderEqualOrLessThan` to find out which receipts need to be verified.
- Developer can change the number in `spo_client_verify_now` to configure the setting. Please check [spo_client_example.c](../example/bns-client-example/spo_client_example.c).

- [spo_client_example.c](../example/bns-client-example/spo_client_example.c)

  ```C
  int spo_client_example() {
    ...
    ...
    while (count < BNS_CLIENT_EXAMPLE_LEDGER_INPUT_COUNT) {
      if (receipt_cache_count() < RECEIPT_CACHE_SIZE) {
        ...
        ...
      } else {
        if ((spoExitCode = spo_client_verify_now(&spoClient, 5)) != BNS_OK) {
          goto spo_client_example_fail;
        }
            
        nanosleep((const struct timespec[]){{1L, 0L}}, NULL);
      }
    }

    while (receipt_cache_count() != 0) {
      if ((spoExitCode = spo_client_verify_now(&spoClient, 5)) != BNS_OK) {
        goto spo_client_example_fail;
      }
      LOG_INFO("spo_client_example() wait");
      nanosleep((const struct timespec[]){{1L, 0L}}, NULL);
    }
    ...
    ...
  }
  ```

- [spo_client.c](../src/bns-client/spo_client.c)
  
  ```C
  spo_exit_code_t spo_client_verify_now(const spo_client_t *const spoClient, const size_t verifyCount) {
    ...
    ...
    LOG_INFO("spo_client_verify_now() begin");
    ...
    ...
    if ((exitCode = spo_get_done_clearance_order( spoClient, &doneClearanceOrder)) != BNS_OK) {
        goto spo_client_verify_now_fail;
    }
  
    if ((exitCode = spo_client_verify_by_done_co(spoClient, verifyCount, doneClearanceOrder)) != BNS_OK) {
        goto spo_client_verify_now_fail;
    }
    LOG_INFO("spo_client_verify_now() end");
    ...
    ...
    return exitCode;
  }
  ```

----
Tutorials are now complete. Next, you can explore the overview of BNS Client.

## Next Steps

[Overview of BNS Client](./summary_en.md)
