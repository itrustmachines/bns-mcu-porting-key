#include <bns-client/util/log.h>
#include <bns-client/util/numeric_util.h>
#include <bns-client/util/string_util.h>
#include <bns-client/verify/slice.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bns_exit_code_t slice_to_string(const slice_t* const slice,
                                char** const         outputString) {
  bns_exit_code_t exitCode = BNS_OK;
  if (!slice) {
    exitCode = BNS_SLICE_NULL_ERROR;
    goto slice_to_string_fail;
  }
  if (!outputString) {
    exitCode = BNS_SLICE_STRING_NULL_ERROR;
    goto slice_to_string_fail;
  }
  size_t size = 0;
  size += bns_digits(slice->index);
  size += 1;
  size += strlen(slice->hashString);
  if (*outputString) {
    *outputString = (char*)realloc(*outputString, sizeof(char) * (size + 1));
  } else {
    *outputString = (char*)malloc(sizeof(char) * (size + 1));
  }
  sprintf(*outputString, "%lld.%s", slice->index, slice->hashString);
  return exitCode;
slice_to_string_fail:
  LOG_ERROR("slice_to_string() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

bns_exit_code_t parse_slice(const char* const sliceString,
                            slice_t* const    slice) {
  LOG_DEBUG("parse_slice() begin, sliceString=%s", sliceString);
  bns_exit_code_t exitCode        = BNS_OK;
  char*           hashStringBegin = NULL;
  if (!sliceString) {
    exitCode = BNS_SLICE_STRING_NULL_ERROR;
    goto parse_slice_fail;
  }
  if (!slice) {
    exitCode = BNS_SLICE_NULL_ERROR;
    goto parse_slice_fail;
  }
  slice->index = (int)strtol(sliceString, &hashStringBegin, 10);
  hashStringBegin++;
  slice->size = (strlen(hashStringBegin) + 1) / HASH_STR_LEN;
  bns_strdup(&slice->hashString, hashStringBegin);
  slice->hashStringList = (char**)malloc(sizeof(char*) * slice->size);
  for (size_t i = 0; i < slice->size; i++) {
    slice->hashStringList[i] = slice->hashString + i * HASH_STR_LEN;
  }
  LOG_DEBUG("parse_slice() end");
  return exitCode;

parse_slice_fail:
  LOG_ERROR("parse_slice() error, " BNS_EXIT_CODE_PRINT_FORMAT,
            bns_strerror(exitCode));
  return exitCode;
}

void slice_free(slice_t* const slice) {
  if (slice) {
    if (slice->hashString) { BNS_FREE(slice->hashString); }
    if (slice->hashStringList) { BNS_FREE(slice->hashStringList); }
  }
}
