## Build the CMD

### About the CMD

CMD is a data you want to clearance to blockchain by BNS Server. CMD is also part of ledgerinput. BNS Client send the ledgerinput to BNS Server and BNS Server will automatically upload the fingerprint of ledgerinput to blockchain. The developers should build your own CMD so that you can use our BNS service. There are two scenarios to build the CMD:

1. Display on BNS : Learn how to build CMD in JSON data type and display on BNS.

2. Use verification server to audit the file : Guide you through the steps to convert the file to CMD and use our verification server to audit the file.

### Prerequisites

- Complete the quickstarts document

### Some suggestions

- We highly recommand that you build the CMD in JSON data type
- If you want to display on BNS, `timestamp` and `indexVaue` must be included in CMD
- The maximum length of CMD is 1000 characters

### Display on BNS

- If we want to clearance the solar panel data, we need to add the solar panel's data in CMD and use `sprintf` function to covert the string into JSON data type. Please check the following code in [bns_client_example.c](../example/bns-client-example/bns_client_example.c).

  ```c
  char cmdJson[CMD_LEN] = {0};
  char *timestamp = get_timestamp_string();
  float voltage = 1.0;
  float current = 1.0;
  float power = 1.0;

  sprintf(cmdJson, "{\"deviceId\":\"%s\", \"timestamp\":%s, \"voltage\":%.6f, \"current\":%.6f, \"power\":%.6f}", INDEX_VALUE_KEY, timestamp, voltage, current, power);
  ```

- Now, you can implement your own CMD in [bns_client_example.c](../example/bns-client-example/spo_client_example.c) and follow the instructions in quickstarts document to execute the program. We highly recommend that you keep checking the ledgerinput result on [Blockchain Notary Service](https://bns.itrustmachines.com/) until CMD is successfully On-chain.

----
Build the CMD document is now complete. Next, learn how to build the Callback Applications

## Next Steps

[Build the Callback Applications](./callback_en.md)
