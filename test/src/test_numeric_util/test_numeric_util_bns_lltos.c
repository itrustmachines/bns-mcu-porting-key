#include <assert.h>
#include <bns-client/util/numeric_util.h>
#include <string.h>

void test_positive_int() {
  // given
  int   num       = 1234567890;
  char* numString = "1234567890";

  // when
  char* result = bns_lltos(num);

  // then
  assert(strcmp(result, numString) == 0);

  // clean
  BNS_FREE(result);
}

void test_negative_int() {
  // given
  int   num       = -1234567890;
  char* numString = "-1234567890";

  // when
  char* result = bns_lltos(num);

  // then
  assert(strcmp(result, numString) == 0);

  // clean
  BNS_FREE(result);
}

void test_positive_long_long() {
  // given
  long long int num       = 1234567890123456789L;
  char*         numString = "1234567890123456789";

  // when
  char* result = bns_lltos(num);

  // then
  assert(strcmp(result, numString) == 0);

  // clean
  BNS_FREE(result);
}

void test_negative_long_long() {
  // given
  long long int num       = -1234567890123456789L;
  char*         numString = "-1234567890123456789";

  // when
  char* result = bns_lltos(num);

  // then
  assert(strcmp(result, numString) == 0);

  // clean
  BNS_FREE(result);
}

int main() {
  test_positive_int();
  test_negative_int();
  test_positive_long_long();
  test_negative_long_long();
  return 0;
}