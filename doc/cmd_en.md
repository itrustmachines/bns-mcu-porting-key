## Build the CMD

### About the CMD

CMD is the data you want to clear to the blockchain via the BNS Server. CMD is also part of ledgerinput. The BNS Client sends the ledgerinput to the BNS Server and the BNS Server will automatically upload the fingerprint of the ledgerinput to blockchain. Developers should build their own CMD so that their can use our BNS service. There are two scenarios to build the CMD:

1. Display on BNS : Learn how to build CMD in JSON data type and display it on BNS.

2. Use verification server to audit the file : Go through the steps to convert the file to CMD and use our verification server to audit the file.

### Prerequisites

- Complete the quickstarts document

### Some suggestions

- We highly recommand that you build the CMD in JSON data type
- If you want to display on BNS, `timestamp` and `indexVaue` must be included in CMD
- The maximum length of CMD is 1000 characters

### Display on BNS

- If we want to clearance solar panel data, we need to add the solar panel's data in CMD and use the `sprintf` function to covert the string into JSON data type. Please check the following code in [bns_client_example.c](../example/bns-client-example/bns_client_example.c).

  ```c
  char cmdJson[CMD_LEN] = {0};
  char *timestamp = get_timestamp_string();
  float voltage = 1.0;
  float current = 1.0;
  float power = 1.0;

  sprintf(cmdJson, "{\"deviceId\":\"%s\", \"timestamp\":%s, \"voltage\":%.6f, \"current\":%.6f, \"power\":%.6f}", INDEX_VALUE_KEY, timestamp, voltage, current, power);
  ```

- Now, you can implement your own CMD in [bns_client_example.c](../example/bns-client-example/bns_client_example.c) and follow the instructions in the quickstart document to execute the program. We highly recommend that you keep checking the ledgerinput result on [Blockchain Notary Service](https://bns.itrustmachines.com/) until CMD is successfully on-chain.

----
Build the CMD document is now complete. Next, learn how to build the Callback Applications.

## Next Steps

[Build the Callback Applications](./callback_en.md)
