#include <assert.h>
#include <bns-client/util/slice_validation_util.h>
#include <bns-client/verify/merkle_proof.h>
#include <bns-client/verify/slice.h>
#include <string.h>

#include "../mock_data/mock_ok_data.h"

void test_ok()
{
  // given
  slice_t slice = {0};
  bns_exit_code_t exitCode = parse_slice(MOCK_SLICE_OK, &slice);
  assert(exitCode == BNS_OK);

  // then
  char *rootHash = slice_get_root_hash(&slice);
  assert(strcmp(rootHash, MOCK_SLICE_LEAF_ROOT_HASH_OK) == 0);

  // clean
  slice_free(&slice);
}

void test_NULL() { assert(slice_get_root_hash(NULL) == NULL); }

int main()
{
  test_ok();
  test_NULL();
  return 0;
}