#include <assert.h>
#include <bns-client/util/string_util.h>
#include <string.h>

void test_ok() {
  // given
  char *string = "hello";

  // when
  char *result = NULL;
  bns_strdup(&result, string);

  // then
  assert(strcmp(result, string) == 0);

  // clean
  BNS_FREE(result);
}

void test_dest_NULL() {
  // given
  char *string = "hello";

  // when
  bns_strdup(NULL, string);
}

void test_src_NULL() {
  // when
  char *result = NULL;
  bns_strdup(&result, NULL);
}

int main() {
  test_ok();
  test_dest_NULL();
  test_src_NULL();
  return 0;
}