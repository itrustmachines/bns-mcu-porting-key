## 快速開始

### 關於快速開始

使用我們的 MCU SDK 需要:

- BNS MCU SDK
- 執行 Ubuntu 18.04 LTS / Ubuntu 20.04 LTS / Centos 7 / Centos 8 環境的機器
- MacOS 和 Windows 用戶可透過 Docker, VM ,遠端連線 ... 等其他方式在符合條件的 Linux 環境中使用我們的 SDK

根據您的作業系統，MCU SDK 支援下列數種開發環境

- Visual Studio Code (VScode)。但您需要安裝 VScode [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) 延伸套件，才能讓您在 VScode 上執行並開發我們的 SDK
- Command Line Interface (CLI)。

此份快速開始文件將透過下列 5 個步驟引導您開始使用我們的 SDK

<!-- no toc -->
1. [安裝所需套件](#1-安裝所需套件)
2. [下載 SDK](#2-下載-sdk)
3. [修改 SDK 設定檔](#3-修改-sdk-設定檔)
4. [執行範例程式](#4-執行範例程式)
   - [CLI](#cli)
   - [VScode](#visual-studio-code)
5. [確認執行結果](#5-確認執行結果)

完成上述步驟後，您就可以參考教學文件中的範例整合及開發我們的 SDK。

### 1. 安裝所需套件

- 執行此 SDK 前，需先安裝數個 SDK 所需要的套件
- SDK 所需的套件有 : `gcc`, `g++`, `gdb`, `git`, `make`, `cmake`, `libcurl4-openssl-dev`
- 若機器已經安裝上述套件，**請透過 `gcc --version` 確認 `gcc` 版本為 7.5 以上**
  
    ```shell
    # 確認 gcc 版本
    > gcc --version

    gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
    Copyright (C) 2019 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```

- 若無請用戶依照您的 Linux distribution 參考下方指令進行安裝
  
  - 在 Ubuntu 環境安裝指令如下 :

      ```shell
      > sudo apt install gcc g++ gdb git make cmake libcurl4-openssl-dev
      ```

  - 在 Centos 7 環境安裝指令如下 :

      ```shell
      > sudo yum install centos-release-scl
      > sudo yum install devtoolset-9
      > sudo yum install gcc-c++ gdb git cmake libcurl-devel
      > scl enable devtoolset-9 bash
      ```

  - 在 Centos 8 環境安裝指令如下 :

      ```shell
      > sudo yum install gcc gcc-c++ gdb git make cmake libcurl-devel
      ```

### 2. 下載 SDK

- 下載 BNS MCU SDK

  ```shell
  git clone https://github.com/itrustmachines/bns-mcu-porting-kit.git
  ```

### 3. 修改 SDK 設定檔

- 範例主程式 [bns-client-example.c](../example/bns-client-example/bns_client_example.c) 中會使用此設定檔進行私鑰、區塊鏈位址、伺服器 ... 等設定，**本設定檔內容十分重要，請依照下方說明實作，再執行範例程式**

- 在修改設定檔前，請先依照下方兩點說明先取得私鑰以及區塊鏈位址
  
  1. 為了確保每個資料來源的可信度，所以需要一組專屬私鑰進行數位簽章，避免他人冒用，**每個資料來源的私鑰必須唯一**。而私鑰的產生方式可使用線上開源工具 [VANITY-ETH](https://vanity-eth.tk/) 產生
  
  2. 我們使用以太坊公有區塊鏈作為測試環境。為了向 以太坊公有區塊鏈取得鏈上證據，所以需要 以太坊公有區塊鏈節點位址。以太坊公有區塊鏈位址可透過 Infura 取得，請參考下方 Infura 教學連結
     - [Infura 教學](./infura_zh.md)

- 取得私鑰及以太坊公有區塊鏈位址後，我們可以開始修改設定檔 [config.h](../example/bns-client-example/config.h)。修改方式請參考下方說明 :

    ```C
    /**
     * 請按照描述依序填入，詳細資訊請參考下方說明
     * 填入由 VANITY-ETH 使用橢圓曲線 secp256k1 演算法所產生的 32 Bytes (128 bits) Hex 編碼專屬私鑰
     * 私鑰取得方式請見上方說明
     */ 
    #define PRIVATE_KEY "" 

    /** 
     * 填入資料來源上鏈的索引值，需為唯一 
     * 若實作於裝置上可使用 deviceId 作為 INDEX_VALUE_KEY
     */
    #define INDEX_VALUE_KEY "" 
    
    /**
     * 填入於BNS註冊之Email帳戶
     */
    #define EMAIL ""

    /** 填入 BNS Server 的 URL */
    #define SERVER_URL "https://bns.itrustmachines.com/" 
    
    /** 
     * 我們提供的測試環境使用以太坊公有區塊鏈
     * 請確認此節點位址屬於以太坊公有區塊鏈的節點位址，再填入 
     * 節點位址取得方式，請見上方說明
     */
    #define NODE_URL "https://mainnet.infura.io/v3/{InfuraProjectId}" 
    ```

### 4. 執行範例程式

#### CLI

##### make ( Only for Linux + GNU )
**目前沒有測試功能，如需執行測試，請參考[cmake](#cmake)**
```shell
  # 切換至 bns-mcu-porting-kit 資料夾
  $ cd bns-mcu-porting-kit

  # 編譯主程式及主程式需要的檔案
  # 可使用 make help 查看功能
  $ make cleam 
  $ make all

  # 切換至執行檔所在的資料夾
  $ cd bin

  # 執行主程式，將存證內容 LedgerInput 傳送至 BNS Server
  $ ./bns-client-example
```

##### cmake

```shell
  # 切換至 bns-mcu-porting-kit 資料夾
  $ cd bns-mcu-porting-kit

  # 建立名稱為build 的資料夾
  $ mkdir build

  # 切換至 build 資料夾
  $ cd build

  # 產生主程式所需要的檔案
  $ cmake ..

  # 編譯主程式及主程式需要的檔案
  $ make

  # 切換至執行檔所在的資料夾
  $ cd example/bns-client-example

  # 執行主程式，將存證內容 LedgerInput 傳送至 BNS Server
  $ ./bns-client-example
```

**如果在 `make` 時碰到 implicit declaration of function 問題，建議使用 `make C_FLAGS=-std=gnu99` 編譯 SDK**

- 若要執行測試程式可參考下方說明
  
  ```shell
    $ cd build
    $ make test
    running test
    ...
    ...
    100% tests passed, 0 tests failed out of 50
  ```

#### Visual Studio Code

1. 選擇 GCC for Linux 7.5 以上版本的編譯器
2. build
3. 選擇 bns-client-example，執行程式
![vscode](../image/vscode.png)

- 選擇 Run CTest，可執行測試

### 5. 確認執行結果

執行範例程式後，可透過登入 [Blockchain Notary Service](https://bns.itrustmachines.com/) 確認範例程式能否將資料傳送至 BNS Server 進行存證上鏈。BNS 相關操作可參考 [Blockchain Notary Service 操作手冊](https://drive.google.com/file/d/1s1hDdHplzrEmnAIaja-rXJpPPq7eGlC5/view?usp=sharing) 或前往 YouTube 觀看教學影片 [Blockchain Notary Service Playlist](https://youtube.com/playlist?list=PL9mBKnNjNC1K0XiH9EL65QljN6Agf4k42)。

您已完成快速開始文件中所有教學步驟，並且已經成功將此 SDK 整合至您的裝置，接下來我們會引導你如何將想存證的資料設計成 CMD 傳送至 BNS Server

----

- [下一頁 : 設計存證內容 CMD](./cmd_zh.md)
- [上一頁 : ITM BNS MCU SDK 使用手冊](../README_ZH.md)
