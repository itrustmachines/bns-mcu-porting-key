## BNS Client 其他設定說明

### 關於 BNS Client 其他設定說明文件

- 在此份文件，我們將引導您了解 BNS Client 其他設定，讓 BNS Client 能夠符合您的需求運作。
- BNS Client 中，我們提供 4 個設定讓開發者進行調整，分別為 :
  - `bns_client_set_verify_after_ledger_input_count` : 設定每次 ledgerInput 後驗證幾筆回條
  - `bns_client_set_retry_count` : 設定最大 `ledgerInput` 重試次數
  - `bns_client_set_retry_delay_sec` : 設定每次重試 `ledgerInput` 時的延遲秒數
  - `bns_client_verify_now` : 當 BNS Client 符合特定條件時，最多可驗證幾筆回條
  
  我們會在下方詳細說明每個設定的用途，建議開發者閱讀各設定說明時可一併參考說明下方的程式以方便理解每個設定的運作流程

- 您已經完成 BNS Client 中最主要的三個實作教學，[CMD](./cmd_zh.md)，[Callback](./callback_zh.md)，[ReceiptDao](./receiptDao_zh.md)。閱讀完此文件您基本上已經可以完整地整合我們的 SDK。

### 各 BNS Client 其他設定説明

#### bns_client_set_verify_after_ledger_input_count 說明

##### 為了避免過多的待驗證回條而影響效能，您可以閱讀下方說明及程式設定每次 ledgerInput 後驗證回條的數量

- BNS Client 會在初始化時呼叫 `bns_client_set_verify_after_ledger_input_count` 函式設定每次 `ledgerInput` 後驗證幾筆回條，預設為 2 筆，( 預設設定值位於 [bns_client.h](../src/bns-client/bns_client.h) 中的 `DEFAULT_VERIFY_AFTER_LEDGER_INPUT_COUNT` )

- 開發者可更改 [bns_client_example.c](../example/bns-client-example/bns_client_example.c) 中的 `bns_client_set_verify_after_ledger_input_count` 的數值進行設定

- 開發者可參考硬體效能進行更改，若記憶體有限，可增加每次 ledgerInput 後驗證數量，但會影響 ledgerInput 的效率。
- 若想增加 ledgerInput 效率，可將此數值調低，但會增加記憶體使用量

- 開發者可查看下方 [bns_client.c](../src/bns-client/bns_client.c) 的程式。每次 BNS Client 呼叫 `bns_client_ledger_input` 時，會進行確認，若 `bns_client_set_verify_after_ledger_input_count` 設定大於 0，BNS Client 會呼叫 `bns_client_verify_by_done_co` 驗證相對應的數量的回條

- [bns_client_example.c](../example/bns-client-example/bns_client_example.c)

  ```C
  int bns_client_example() {
    ...
    ...
    if ((bnsExitCode = bns_client_set_verify_after_ledger_input_count( &bnsClient, 2)) != BNS_OK) {
      goto bns_client_example_fail;
    }
    ...
    ...
  }
  ```

- [bns_client.c](../src/bns-client/bns_client.c)

  ```C
  bns_exit_code_t bns_client_set_verify_after_ledger_input_count( bns_client_t *const bnsClient, const size_t count) {
    if (!bnsClient) {
      return BNS_CLIENT_NULL_ERROR;
    }
    if (!bnsClient->verifyAfterLedgerInputCount) {
      bnsClient->verifyAfterLedgerInputCount = (size_t *)malloc(sizeof(size_t));
    }
    *bnsClient->verifyAfterLedgerInputCount = count;
    return BNS_OK;
  }

  bns_exit_code_t bns_client_init(
    bns_client_t *const bnsClient, const char *const privateKey,
    const char *const indexValueKey, const char *const serverUrl,
    const char *const nodeUrl, const receipt_dao_t *const receiptDao,
    const http_client_t *const httpClient,
    const bns_client_callback_t *const bnsClientCallback) {
      ...
      ...
      if (!bnsClient->verifyAfterLedgerInputCount) {
        if ((exitCode = bns_client_set_verify_after_ledger_input_count( bnsClient,DEFAULT_VERIFY_AFTER_LEDGER_INPUT_COUNT)) != BNS_OK) {
          goto bns_client_init_fail;
        }
      }
      ...
      ...
  }

  bns_exit_code_t bns_client_ledger_input(
    const bns_client_t *const bnsClient,
    const char *const cmdJson) {
      ...
      ...
      bool verifyAfterLedgerInput = bnsClient->verifyAfterLedgerInputCount ? *bnsClient->verifyAfterLedgerInputCount > 0 : false;
    
      if (verifyAfterLedgerInput) {
        exitCode = bns_client_verify_by_done_co( bnsClient, *bnsClient->verifyAfterLedgerInputCount, ledgerInputResult.doneClearanceOrder);
      }
      ...
      ...
  }
  
  bns_exit_code_t bns_client_verify_by_done_co(
    const bns_client_t *const bnsClient, const size_t verifyCount,
    const clearance_order_t doneCO) {
      
      size_t toVerifyCount = verifyCount;
      size_t receiptCount = 0;
      do {
        size_t count = toVerifyCount <= VERIFY_BATCH_SIZE ? toVerifyCount : VERIFY_BATCH_SIZE;
        ...
        ...
        bnsClient->receiptDao.findPageByClearanceOrderEqualOrLessThan(doneCO, 0, count, receipt, &receiptCount);
        ...
        ...
        for (size_t i = 0; i < receiptCount; i++) {
          erkle_proof_t merkleProof = {0};
          verify_receipt_result_t verifyReceiptResult = {0};
          exitCode = verify(bnsClient, &receipt[i], &merkleProof, &verifyReceiptResult);
          
          if (bnsClient->bnsClientCallback.get_verify_receipt_result) { 
            bnsClient->bnsClientCallback.get_verify_receipt_result( &receipt[i], &merkleProof, &verifyReceiptResult);
          }
          ...
          ...
        }
        toVerifyCount -= receiptCount;
      } while (toVerifyCount > 0 && receiptCount != 0);
    }
  ```

#### bns_client_set_retry_count 說明

##### 為了避免 ledgerInput 失敗時影響其他筆 ledgerInput 傳送，您可以閱讀下方說明及程式設定每筆 ledgerInput 重新嘗試連線的次數

- BNS Client 會在初始化時呼叫 `bns_client_set_retry_count` 函式設定最大重新 `ledgerInput` 次數，預設為 5 ( 預設設定值位於 [bns_client.h](../src/bns-client/bns_client.h) 中的 `DEFAULT_MAX_RETRY_COUNT` )

- 開發者可更改 [bns_client_example.c](../example/bns-client-example/bns_client_example.c) 中的 `bns_client_set_retry_count` 的數值進行設定

- [bns_client_example.c](../example/bns-client-example/bns_client_example.c)

  ```C
  int bns_client_example() {
    ...
    ...
    if ((bnsExitCode = bns_client_set_retry_count(&bnsClient, 5)) != BNS_OK) { 
      goto bns_client_example_fail;
    }
    ...
    ...
  }
  ```

- [bns_client.c](../src/bns-client/bns_client.c)

  ```C
  bns_exit_code_t bns_client_set_retry_count(bns_client_t *const bnsClient, const size_t count) {
    if (!bnsClient) {
      return BNS_CLIENT_NULL_ERROR;
    }
    if (!bnsClient->maxRetryCount) {
      bnsClient->maxRetryCount = (size_t *)malloc(sizeof(size_t));
    }
    *bnsClient->maxRetryCount = count;
    return BNS_OK;
  }

  bns_exit_code_t bns_client_init(
    bns_client_t *const bnsClient, const char *const privateKey,
    const char *const indexValueKey, const char *const serverUrl,
    const char *const nodeUrl, const receipt_dao_t *const receiptDao,
    const http_client_t *const httpClient,
    const bns_client_callback_t *const bnsClientCallback) {
      ...
      ...
      if (!bnsClient->maxRetryCount) {
        if ((exitCode = bns_client_set_retry_count(bnsClient, DEFAULT_MAX_RETRY_COUNT)) != BNS_OK) {
          goto bns_client_init_fail;
        }
      }
      ...
      ...
  }

  bns_exit_code_t bns_client_ledger_input(
    const bns_client_t *const bnsClient,
    const char *const cmdJson) {
      ...
      ...
      size_t retryCount = bnsClient->maxRetryCount ? *bnsClient->maxRetryCount : 0;
      do {
        if (retryCount > 0) {
          retryCount--;
        }
        ...
        ...
        // ledgerInput 成功，離開此迴圈
        exitCode = bns_post_ledger_input(bnsClient, cmdJson, &receiptLocator, &ledgerInputResult);
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

#### bns_client_set_retry_delay_sec 說明

##### 為了避免 ledgerInput 失敗時不斷進行重新連線，您可以閱讀下方說明及程式設定每次重新嘗試連線的延遲秒數

- BNS Client 會在初始化時呼叫 `bns_client_set_retry_delay_sec` 函式設定重新 `ledgerInput` 的延遲時間，預設為 5 ( 預設設定值位於 [bns_client.h](../src/bns-client/bns_client.h) 中的 `DEFAULT_RETRY_DELAY_SEC` )

- 開發者可更改 [bns_client_example.c](../example/bns-client-example/bns_client_example.c) 中的 `bns_client_set_retry_delay_sec` 的數值進行設定

- [bns_client_example.c](../example/bns-client-example/bns_client_example.c)

  ```C
  int bns_client_example() {
    ...
    ...
    if ((bnsExitCode = bns_client_set_retry_delay_sec(&bnsClient, 5)) != BNS_OK) {
      goto bns_client_example_fail;
    }
    ...
    ...
  }
  ```

- [bns_client.c](../src/bns-client/bns_client.c)

  ```C
  bns_exit_code_t bns_client_set_retry_delay_sec(bns_client_t *const bnsClient, const size_t sec) {
    if (!bnsClient) {
      return BNS_CLIENT_NULL_ERROR;
    }
    if (!bnsClient->retryDelaySec) {
      bnsClient->retryDelaySec = (size_t *)malloc(sizeof(size_t));
    }
    *bnsClient->retryDelaySec = sec;
    return BNS_OK;
  }

  bns_exit_code_t bns_client_init(
    bns_client_t *const bnsClient, const char *const privateKey,
    const char *const indexValueKey, const char *const serverUrl,
    const char *const nodeUrl, const receipt_dao_t *const receiptDao,
    const http_client_t *const httpClient,
    const bns_client_callback_t *const bnsClientCallback) {
      ...
      ...
      if (!bnsClient->retryDelaySec) {
        if ((exitCode = bns_client_set_retry_delay_sec( bnsClient, DEFAULT_RETRY_DELAY_SEC)) != BNS_OK) {
          goto bns_client_init_fail;
        }
      }
      ...
      ...
  }

  bns_exit_code_t bns_client_ledger_input(
    const bns_client_t *const bnsClient,
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
        exitCode = bns_post_ledger_input(bnsClient, cmdJson, &receiptLocator, &ledgerInputResult);
        if (exitCode == BNS_OK) {
          break;
        }
        
        if (is_ledger_input_resend_error(exitCode)) {
          LOG_WARN("bns_client_ledger_input() resend, " BNS_EXIT_CODE_PRINT_FORMAT, bns_strerror(exitCode));
            
          if (bnsClient->retryDelaySec) {
            sleep(*bnsClient->retryDelaySec);
          }
        
          continue;
        }
        ...
        ...
      } while (retryCount > 0);
    }
    ```

#### bns_client_verify_now 說明

##### 除了每次 ledgerInput 後驗證回條外，BNS Client 符合特定條件也會驗證回條，您可以閱讀下方說明及程式，設定每次驗證幾筆回條

- 除了 `ledgerInput` 後驗證回條外，BNS Client 滿足下列兩種情形之一，BNS Client 也會驗證回條，

  1. 當回條筆數累積到上限，BNS Client 就會開始驗證回條，開發者可參考 [ReceiptDao 功能說明文件](./receiptDao_zh.md) 更改回條儲存筆數
  2. 當 BNS Client `ledgerInput` 達到 `BNS_CLIENT_EXAMPLE_LEDGER_INPUT_COUNT` 設定的次數，BNS Client 會將記憶體內剩餘的回條驗證完

- 滿足條件時，BNS Client 會呼叫 `bns_client_verify_now` 函式後，BNS Client 會向 BNS Server 拿取最新的 `doneClearanceOrder`，並透過 receiptDao 中的 `receipt_cache_findPageByClearanceOrderEqualOrLessThan` 函式找出待驗證回條並進行驗證

- 開發者可更改 [bns_client_example.c](../example/bns-client-example/bns_client_example.c) 中的 `bns_client_verify_now` 的數值進行設定

- [bns_client_example.c](../example/bns-client-example/bns_client_example.c)

  ```C
  int bns_client_example() {
    ...
    ...
    while (count < BNS_CLIENT_EXAMPLE_LEDGER_INPUT_COUNT) {
      if (receipt_cache_count() < RECEIPT_CACHE_SIZE) {
        ...
        ...
      } else {
        if ((bnsExitCode = bns_client_verify_now(&bnsClient, 5)) != BNS_OK) {
          goto bns_client_example_fail;
        }
            
        nanosleep((const struct timespec[]){{1L, 0L}}, NULL);
      }
    }

    while (receipt_cache_count() != 0) {
      if ((bnsExitCode = bns_client_verify_now(&bnsClient, 5)) != BNS_OK) {
        goto bns_client_example_fail;
      }
      LOG_INFO("bns_client_example() wait");
      nanosleep((const struct timespec[]){{1L, 0L}}, NULL);
    }
    ...
    ...
  }
  ```

- [bns_client.c](../src/bns-client/bns_client.c)
  
  ```C
  bns_exit_code_t bns_client_verify_now(const bns_client_t *const bnsClient, const size_t verifyCount) {
    ...
    ...
    LOG_INFO("bns_client_verify_now() begin");
    ...
    ...
    if ((exitCode = bns_get_done_clearance_order( bnsClient, &doneClearanceOrder)) != BNS_OK) {
        goto bns_client_verify_now_fail;
    }
  
    if ((exitCode = bns_client_verify_by_done_co(bnsClient, verifyCount, doneClearanceOrder)) != BNS_OK) {
        goto bns_client_verify_now_fail;
    }
    LOG_INFO("bns_client_verify_now() end");
    ...
    ...
    return exitCode;
  }
  ```

您現在已經了解如何調整 BNS Client 其他設定，接下來們將引導您了解 BNS Client 完整的運作流程

----

- [下一頁 : 主程式概觀](./summary_zh.md)
