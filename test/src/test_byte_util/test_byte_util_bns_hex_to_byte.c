#include <assert.h>
#include <bns-client/util/byte_util.h>
#include <string.h>

void test_ok() {
  // given
  char hex[43] = "0102030405060708090a0b0c0d0e0f0A0B0C0D0E0F";
  unsigned char byte[21] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
                            0x0f, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

  // when
  unsigned char result[21] = {0};
  bns_hex_to_byte(hex, strlen(hex), result);

  // then
  for (size_t i = 0; i < 21; i++) {
    assert(byte[i] == result[i]);
  }
}

void test_odd_size_ok() {
  // given
  char hex[43] = "102030405060708090a0b0c0d0e0f0A0B0C0D0E0F";
  unsigned char byte[21] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
                            0x0f, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

  // when
  unsigned char result[21] = {0};
  bns_hex_to_byte(hex, strlen(hex), result);

  // then
  for (size_t i = 0; i < 21; i++) {
    assert(byte[i] == result[i]);
  }
}

void test_byte_NULL() {
  unsigned char result[21] = {0};
  bns_hex_to_byte(NULL, 0, result);
}

void test_size_zero() {
  // given
  char hex[43] = "0102030405060708090a0b0c0d0e0f0A0B0C0D0E0F";

  // when
  unsigned char result[21] = {0};
  bns_hex_to_byte(hex, 0, result);
}

void test_hex_NULL() {
  // given
  char hex[43] = "0102030405060708090a0b0c0d0e0f0A0B0C0D0E0F";

  // when
  bns_hex_to_byte(hex, 0, NULL);
}

int main() {
  test_ok();
  test_odd_size_ok();
  test_byte_NULL();
  test_size_zero();
  test_hex_NULL();
  return 0;
}