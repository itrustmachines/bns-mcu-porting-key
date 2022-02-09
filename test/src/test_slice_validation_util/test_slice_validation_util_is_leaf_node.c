#include <assert.h>
#include <bns-client/util/slice_validation_util.h>
#include <bns-client/verify/merkle_proof.h>
#include <bns-client/verify/slice.h>

#include "../mock_data/mock_ok_data.h"

void test_ok() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);
  pb_pair_t pbPair = {0};
  cJSON*    root   = cJSON_Parse(MOCK_PBPAIR_OK);
  assert(parse_pb_pair(root, &pbPair) == BNS_OK);

  // then
  assert(is_leaf_node(&slice, &pbPair) == BNS_OK);

  // clean
  slice_free(&slice);
  pb_pair_free(&pbPair);
  cJSON_Delete(root);
}

void test_BNS_SLICE_NULL_ERROR() {
  assert(is_leaf_node(NULL, NULL) == BNS_SLICE_NULL_ERROR);
}

void test_BNS_PB_PAIR_NULL_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);

  // then
  assert(is_leaf_node(&slice, NULL) == BNS_PB_PAIR_NULL_ERROR);

  // clean
  slice_free(&slice);
}

void test_BNS_PB_PAIR_IN_LEAF_NODE_ERROR() {
  // given
  slice_t slice = {0};
  assert(parse_slice(MOCK_SLICE_OK, &slice) == BNS_OK);
  pb_pair_t pbPair = {0};
  cJSON*    root   = cJSON_Parse(MOCK_PBPAIR_ERROR);
  assert(parse_pb_pair(root, &pbPair) == BNS_OK);

  // then
  assert(is_leaf_node(&slice, &pbPair) == BNS_PB_PAIR_IN_LEAF_NODE_ERROR);

  // clean
  slice_free(&slice);
  pb_pair_free(&pbPair);
  cJSON_Delete(root);
}

int main() {
  test_ok();
  test_BNS_SLICE_NULL_ERROR();
  test_BNS_PB_PAIR_NULL_ERROR();
  test_BNS_PB_PAIR_IN_LEAF_NODE_ERROR();
  return 0;
}