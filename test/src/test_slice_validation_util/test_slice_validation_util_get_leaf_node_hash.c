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
  char leafNodeHash[HASH_STR_LEN] = {0};
  assert(get_leaf_node_hash(&slice, leafNodeHash) == BNS_OK);
  assert(strcmp(leafNodeHash, MOCK_SLICE_LEAF_NODE_HASH_OK) == 0);

  // clean
  slice_free(&slice);
}

void test_BNS_SLICE_NULL_ERROR() {
  assert(get_leaf_node_hash(NULL, NULL) == BNS_SLICE_NULL_ERROR);
}

void test_BNS_SLICE_INDEX_NEGATIVE_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);
  slice.index = -1;

  // then
  char leafNodeHash[HASH_STR_LEN] = {0};
  assert(get_leaf_node_hash(&slice, leafNodeHash) ==
         BNS_SLICE_INDEX_NEGATIVE_ERROR);

  // clean
  slice_free(&slice);
}

void test_BNS_LEAF_NODE_HASH_NULL_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);

  // then
  assert(get_leaf_node_hash(&slice, NULL) == BNS_LEAF_NODE_HASH_NULL_ERROR);

  // clean
  slice_free(&slice);
}

void test_BNS_GET_LEAF_NODE_HASH_OUT_OF_RANGE_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);
  slice.size = 0;

  // then
  char leafNodeHash[HASH_STR_LEN] = {0};
  assert(get_leaf_node_hash(&slice, leafNodeHash) ==
         BNS_GET_LEAF_NODE_HASH_OUT_OF_RANGE_ERROR);

  // clean
  slice_free(&slice);
}

int main() {
  test_ok();
  test_BNS_SLICE_NULL_ERROR();
  test_BNS_SLICE_INDEX_NEGATIVE_ERROR();
  test_BNS_LEAF_NODE_HASH_NULL_ERROR();
  test_BNS_GET_LEAF_NODE_HASH_OUT_OF_RANGE_ERROR();
  return 0;
}