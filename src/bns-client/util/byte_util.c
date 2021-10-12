#include <bns-client/util/byte_util.h>
#include <ctype.h>
#include <stdio.h>

void bns_hex_to_byte(const char *hex, size_t size, unsigned char *byte) {
  if (!hex || (size == 0) || !byte) {
    return;
  }
  for (int i = (size % 2 == 0 ? 0 : -1), j = 0; i < (int)size; i += 2, j++) {
    byte[j] = 0;
    if (i >= 0) {
      if (isdigit(hex[i])) {
        byte[j] += (hex[i] - '0') * 16;
      } else {
        byte[j] += (tolower(hex[i]) - 'a' + 10) * 16;
      }
    }
    if (i >= -1) {
      if (isdigit(hex[i + 1])) {
        byte[j] += (hex[i + 1] - '0');
      } else {
        byte[j] += (tolower(hex[i + 1]) - 'a' + 10);
      }
    }
  }
}

void bns_byte_to_hex(const unsigned char *byte, size_t size, char *hex) {
  if (!byte || (size == 0) || !hex) {
    return;
  }
  size_t index = 0;
  unsigned char h;
  unsigned char l;
  for (size_t i = 0; i < size; i++) {
    h = byte[i] / 16;
    l = byte[i] % 16;
    if (h <= 0x09) {
      hex[index++] = (char)(h + '0');
    } else {
      hex[index++] = (char)(h - 10 + 'a');
    }
    if (l <= 0x09) {
      hex[index++] = (char)(l + '0');
    } else {
      hex[index++] = (char)(l - 10 + 'a');
    }
  }
}
