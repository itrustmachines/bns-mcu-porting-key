#include <assert.h>
#include <bns-client/register/bns_server_info.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // when
  char* url = NULL;
  build_get_bns_server_info_url(&url, MOCK_SERVER_URL_OK);

  // then
  assert(strcmp(url, MOCK_SERVER_URL_OK LEDGER_BNS_SERVER_INFO_PATH) == 0);

  // clean
  BNS_FREE(url);
}

int main() {
  test_ok();
  return 0;
}