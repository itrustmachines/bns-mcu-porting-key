# Blockchain Notary Service(BNS) MCU SDK 使用手冊中文版

## 簡介

此使用手冊內將使用 bns_client_example 作為範例引導您了解並整合此 SDK。手冊中包含 SDK 基本設定、SDK 各功能整合實作說明以及主程式運作流程。前往快速開始文件安裝並執行 SDK 範例程式

## 開始使用 MCU SDK

### 快速開始

- 在[快速開始](./doc/quick_start_zh.md)文件中我們將透過數個步驟引導您使用我們的 SDK
  - [安裝所需套件](./doc/quick_start_zh.md#1-安裝所需套件)
  - [下載 SDK](./doc/quick_start_zh.md#2-下載-sdk)
  - [修改 SDK 的設定檔](./doc/quick_start_zh.md#3-修改-sdk-設定檔)
  - [執行範例程式](./doc/quick_start_zh.md#4-執行範例程式)
  - [確認執行結果](./doc/quick_start_zh.md#5-確認執行結果)

- **若您已經完成快速開始文件中的每個步驟，您可以參考教學文件中的範例整合及開發我們的 SDK。**

### 教學

- 在教學文件中，我們將引導您了解並實作 BNS Client 中的設定以及服務
  - [存證內容 CMD 設計教學](./doc/cmd_zh.md)
  - [Callback 串接實作教學](./doc/callback_zh.md)
  - [ReceiptDao 功能教學](./doc/receiptDao_zh.md)
  - [BNS Client 其他設定教學](./doc/other_setting_zh.md)

- **若您已經完成教學文件中的每個步驟，您可以參考前往主程式流程說明，了解程式詳細的運作流程。**

## 主程式流程說明

- 若您想對我們 SDK 的運作流程有更清楚的了解或是想更改 SDK 其他程式，我們建議您可以閱讀此份文件。在這份文件中，我們將依照 BNS Client 主程式的運作流程整合前面的教學內容及設定。閱讀此文件前，我們希望您已經了解所有 SDK 的設定、Callback、ReceiptDao 的實作方式。
- [主程式流程說明](./doc/summary_zh.md)
