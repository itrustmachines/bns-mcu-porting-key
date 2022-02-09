#include <assert.h>
#include <bns-client/util/string_util.h>

void test_ok() {
  // given
  char* hex1 = "0x123456789abcdefABCDEF";
  char* hex2 = "0x123456789ABCDEFabcdef";

  // when
  bool result = bns_equals_ignore_case(hex1, hex2);

  // then
  assert(result == true);
}

void test_first_NULL() {
  // given
  char* hex2 = "0x123456789ABCDEFabcdef";

  // when
  bool result = bns_equals_ignore_case(NULL, hex2);

  // then
  assert(result == false);
}

void test_second_NULL() {
  // given
  char* hex1 = "0x123456789abcdefABCDEF";

  // when
  bool result = bns_equals_ignore_case(hex1, NULL);

  // then
  assert(result == false);
}

void test_diff_size() {
  // given
  char* hex1 = "0x123456789abcdefABCDEF";
  char* hex2 = "0x123456789ABCDEFabcdefABCDEF";

  // when
  bool result = bns_equals_ignore_case(hex1, hex2);

  // then
  assert(result == false);
}

void test_contain_non_letter_or_number() {
  // given
  char* hex1 = "~!@#$%^&*()_+";
  char* hex2 = "~!@#$%^&*()_+";

  // when
  bool result = bns_equals_ignore_case(hex1, hex2);

  // then
  assert(result == true);
}

int main() {
  test_ok();
  test_first_NULL();
  test_second_NULL();
  test_diff_size();
  test_contain_non_letter_or_number();
  return 0;
}