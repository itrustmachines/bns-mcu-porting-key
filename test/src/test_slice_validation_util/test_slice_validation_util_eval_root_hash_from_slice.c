#include <assert.h>
#include <bns-client/util/slice_validation_util.h>
#include <bns-client/verify/merkle_proof.h>
#include <bns-client/verify/slice.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);

  // then
  bool result = false;
  assert(eval_root_hash_from_slice(&slice, &result) == BNS_OK);

  // clean
  slice_free(&slice);
}

void test_BNS_SLICE_NULL_ERROR() {
  assert(eval_root_hash_from_slice(NULL, NULL) == BNS_SLICE_NULL_ERROR);
}

void test_BNS_OUTPUT_NULL_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);

  // then
  assert(eval_root_hash_from_slice(&slice, NULL) == BNS_OUTPUT_NULL_ERROR);

  // clean
  slice_free(&slice);
}

void test_BNS_CHECK_SLICE_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_ROOT_HASH_ERROR, &slice) == BNS_OK);

  // then
  bool result = false;
  assert(eval_root_hash_from_slice(&slice, &result) == BNS_CHECK_SLICE_ERROR);

  // clean
  slice_free(&slice);
}

int main() {
  test_ok();
  test_BNS_SLICE_NULL_ERROR();
  test_BNS_OUTPUT_NULL_ERROR();
  test_BNS_CHECK_SLICE_ERROR();
  return 0;
}