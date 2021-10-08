#include <assert.h>
#include <bns-client/util/byte_util.h>
#include <bns-client/util/log.h>
#include <bns-client/util/string_util.h>

void test_hexTransform() {
  LOG_DEBUG("test_hexToByte() start");

  // given
  char input[109] =
      "1A2B3C4D5E6F1A2B3C4D5E6F1A2B3C4D5E6F1A2B3C4D5E6F1A2B3C4D5E6000003C4D5E6F"
      "1A2B3C4D5E6F1A2B3C4D5E6F1A2B3C4D5E6F";

  // when
  unsigned char output[54] = {0};
  char transBack[109] = {0};
  bns_hex_to_byte(input, 108, output);
  bns_byte_to_hex(output, 54, transBack);

  // then
  assert(bns_equals_ignore_case(input, transBack) == true);
  LOG_DEBUG("test_hexToByte() done");
}

int main() {
  test_hexTransform();
  LOG_DEBUG("test_hexTransform() done\n\n");
}
