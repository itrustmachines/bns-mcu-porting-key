## CMD 設計說明

### 關於 CMD 設計說明文件

- CMD 為 BNS Client 傳送至 BNS Server 存證的資料。開發者必須要將上鏈存證的資訊放在 CMD 中，才能使用我們 BNS 服務。在[快速開始](./quick_start_zh.md)文件中，您已經了解如何從 BNS 查看 CMD 內容。現在我們將透過這份文件引導您設計 CMD 的內容。

- CMD 可依照下列兩種情境進行設計
  - [在 BNS 顯示](#在-itm-BNS-顯示) : 引導您設計可在 BNS 上呈現 的 CMD 內容，**實作時必須包含 `deviceId` 與 `timestamp` 兩欄位**
  - [使用 Verification Server 進行檔案驗證](#使用-verification-server-進行檔案驗證) : 引導您將檔案轉換成 CMD 並使用我們提供的公開驗證服務 [Verification Server](https://verification.itrustmachines.com/) 中的原始檔案驗證功能

- CMD 設計規範
  - 建議使用 JSON 資料型別且**最多為 1000 字元**

### 在 BNS 顯示

- 假設今天我們想將太陽能發電版的資訊 (裝置編號、時間戳記、電壓、電流、瓦數) 傳送至 BNS Server 存證上鏈，我們必須把這些太陽能電板的資訊放在 CMD 的欄位，如下方範例程式所示。並透過 `sprintf` 函示將資訊依照 JSON 格式儲存在 `cmdJSON` 中。

- 此段程式在 [bns_client_example.c](../example/bns-client-example/bns_client_example.c) 中，開發者可嘗試自行設計 CMD 內容，然後依照快速入門文件中的步驟執行程式，並確認 CMD 內容可以在 [Blockchain Notary Service](https://bns.itrustmachines.com/) 中顯示。

```c
/** 太陽能板發電資料存證範例 */
char cmdJson[CMD_LEN] = {0};
char *timestamp = get_timestamp_string();
float voltage = 1.0;
float current = 1.0;
float power = 1.0;

sprintf(cmdJson, "{\"deviceId\":\"%s\", \"timestamp\":%s, \"voltage\":%.6f, \"current\":%.6f, \"power\":%.6f}",
                      INDEX_VALUE_KEY, timestamp, voltage, current, power);
```

您現在已經了解如何設計 CMD 內容，下一部分，我們將會引導您將 BNS Client 程式執行中發生的事件串接至 [Blockchain Notary Service](https://bns.itrustmachines.com/) 顯示或是您的系統中

----

- [下一頁 : Callback 服務串接說明](./callback_zh.md)
- [上一頁 : 快速開始](./quick_start_zh.md)
