#include <assert.h>
#include <malloc.h>

#include "ssl_get.h"

void ssl_get_test() {
  char* url =
      "https://azure-demo-rinkeby.itm.monster:4430/ledger/clearanceOrder";
  char* result = ssl_get(url);
  assert(result != NULL);
  free(result);
}

void ssl_post_test() {
  char* url = "https://azure-demo-rinkeby.itm.monster:4430/ledger/receipts";
  char* postData =
      "{\n"
      "  \"reqPairList\": [\n"
      "    {\n"
      "      \"clearanceOrder\": 0,\n"
      "      \"indexValue\": \"string\"\n"
      "    }\n"
      "  ]\n"
      "}";
  char* result = ssl_post(url, postData);
  assert(result != NULL);
  free(result);
}

int main() {
  ssl_get_test();
  ssl_post_test();
  return 0;
}
