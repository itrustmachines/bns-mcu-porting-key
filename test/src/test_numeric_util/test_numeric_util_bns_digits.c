#include <assert.h>
#include <bns-client/util/numeric_util.h>

void test_positive_int() {
  // given
  int num = 1234567890;

  // when
  size_t digits = bns_digits(num);

  // then
  assert(digits == 10);
}

void test_negative_int() {
  // given
  int num = -1234567890;

  // when
  size_t digits = bns_digits(num);

  // then
  assert(digits == 10);
}

void test_positive_long_long() {
  // given
  long long int num = 1234567890123456789L;

  // when
  size_t digits = bns_digits(num);

  // then
  assert(digits == 19);
}

void test_negative_long_long() {
  // given
  long long int num = -1234567890123456789L;

  // when
  size_t digits = bns_digits(num);

  // then
  assert(digits == 19);
}

int main() {
  test_positive_int();
  test_negative_int();
  test_positive_long_long();
  test_negative_long_long();
  return 0;
}