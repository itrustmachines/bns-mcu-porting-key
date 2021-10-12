#include <assert.h>
#include <bns-client/register/bns_server_info.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // when
  char *url = build_get_bns_server_info_url(MOCK_SERVER_URL_OK);

  // then
  assert(strcmp(url, MOCK_SERVER_URL_OK LEDGER_BNS_SERVER_INFO_PATH) == 0);

  // clean
  BNS_FREE(url);
}

void test_NULL() { assert(build_get_bns_server_info_url(NULL) == NULL); }

int main() {
  test_ok();
  test_NULL();
  return 0;
}