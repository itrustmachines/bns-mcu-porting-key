#include <assert.h>
#include <bns-client/util/string_util.h>
#include <string.h>

void test_end_with_slash() {
  // given
  char* string = NULL;
  bns_strdup(&string, "a/b/c/");

  // when
  remove_end_slash(string);

  // then
  assert(strcmp(string, "a/b/c") == 0);

  // clean
  BNS_FREE(string);
}

void test_end_without_slash() {
  // given
  char* string = NULL;
  bns_strdup(&string, "a/b/c");

  // when
  remove_end_slash(string);

  // then
  assert(strcmp(string, "a/b/c") == 0);

  // clean
  BNS_FREE(string);
}

void test_NULL() { remove_end_slash(NULL); }

int main() {
  test_end_with_slash();
  test_end_without_slash();
  return 0;
}