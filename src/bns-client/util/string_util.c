#include <bns-client/util/string_util.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool bns_equals_ignore_case(const char* const a, const char* const b) {
  if (!a || !b) { return false; }
  if (a == b) { return true; }
  size_t size = strlen(a);
  if (strlen(b) != size) { return false; }
  for (size_t i = 0; i < size; i++) {
    if (tolower(a[i]) != tolower(b[i])) { return false; }
  }
  return true;
}

bool bns_equals_n_ignore_case(const char* const a,
                              const char* const b,
                              const size_t      n) {
  if (!a || !b) { return false; }
  if (a == b) { return true; }
  size_t size = strlen(a);
  if (size < n) { return false; }
  if (strlen(b) < n) { return false; }
  for (size_t i = 0; i < n; i++) {
    if (tolower(a[i]) != tolower(b[i])) { return false; }
  }
  return true;
}

void bns_strdup(char** const dest, const char* src) {
  if (!dest || !src) { return; }
  size_t len = strlen(src) + 1;
  if (*dest) {
    *dest = (char*)realloc(*dest, sizeof(char) * len);
  } else {
    *dest = (char*)malloc(sizeof(char) * len);
  }
  memcpy(*dest, src, len);
}

void remove_end_slash(char* string) {
  if (!string) { return; }
  size_t len = strlen(string);
  if (string[len - 1] == '/') { string[len - 1] = '\0'; }
}
