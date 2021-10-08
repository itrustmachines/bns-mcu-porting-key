#include <assert.h>
#include <bns-client/core/core.h>
#include <bns-client/util/byte_util.h>
#include <bns-client/util/log.h>
#include <bns-client/util/signature_util.h>
#include <bns-client/util/string_util.h>
#include <string.h>

void test_sign_recover() {
  bns_client_config_t config;
  char *addressAnswer = "7C1a74de63E97104b8229F8a0792c1949c7D93c7";
  strcpy(config.privateKey,
         "7c5b4955b1ee23e6ae75f98391c72807de01e5ed54ad33332a1e0600b5a81ee6");
  char *message =
      "hellohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
      "llohellohellohellohellohellohellohellohellohellohellohellohellohellohell"
      "ohellohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
      "ellohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
      "lohellohellohellohellohellohellohellohellohellohellohellohellohellohello"
      "hellohellohellohello";
  sig_t sig = {0};

  unsigned char shaResult[SHA3_BYTE_LEN] = {0};
  bns_sha3((unsigned char *)message, strlen(message), shaResult);

  char shaString[SHA3_STR_LEN] = {0};
  bns_byte_to_hex(shaResult, SHA3_BYTE_LEN - 1, shaString);
  LOG_DEBUG("shaResult={%s}", shaString);

  assert(bns_sign(shaResult, config.privateKey, &sig) == BNS_OK);
  char publicKey[PUBLIC_KEY_STR_LEN] = {0};

  assert(recover_public_key(shaResult, &sig, publicKey) == BNS_OK);
  LOG_DEBUG("publicKey={%s}", publicKey);

  char address[ADDRESS_STR_LEN] = {0};
  recover_address(publicKey, address);

  assert(bns_equals_ignore_case(addressAnswer, address) == true);
}

void test_verify_signature() {
  bns_client_config_t config;
  char *addressAnswer = "7C1a74de63E97104b8229F8a0792c1949c7D93c7";
  strcpy(config.privateKey,
         "7c5b4955b1ee23e6ae75f98391c72807de01e5ed54ad33332a1e0600b5a81ee6");
  char *toSignData =
      "hellohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
      "llohellohellohellohellohellohellohellohellohellohellohellohellohellohell"
      "ohellohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
      "ellohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
      "lohellohellohellohellohellohellohellohellohellohellohellohellohellohello"
      "hellohellohellohello";
  sig_t sig = {0};

  unsigned char shaResult[SHA3_BYTE_LEN] = {0};
  bns_sha3((unsigned char *)toSignData, strlen(toSignData), shaResult);

  assert(bns_sign(shaResult, config.privateKey, &sig) == BNS_OK);

  assert(verify_signature(addressAnswer, toSignData, &sig) == BNS_OK);
}

void test_recovery() {
  LOG_DEBUG("test_recovery() begin");

  char *privateKey =
      "a31590108f18895b55582fcbfbbeabb2e7419367b7845c52d3500261cd1e0539";
  char *publicKey =
      "776bc2c86767121a69c83f213fa44bb2debd381cef58ec726059850641084af96bab3711"
      "c786a33b77659666f19033d3c1bcf5af5802e543ac09bdde707f0cb0";
  char *address = "d78bce48a4f8d2d301da40ac8c7c308f7053aa94";

  char *text = " ";

  unsigned char shaResult[HASH_BYTES];
  char recoverPublicKey[PUBLIC_KEY_STR_LEN] = {0};
  char recoverAddress[ADDRESS_STR_LEN] = {0};
  sig_t sig = {0};
  bns_sha3((unsigned char *)text, 1, shaResult);
  assert(bns_sign(shaResult, privateKey, &sig) == BNS_OK);
  assert(recover_public_key(shaResult, &sig, recoverPublicKey) == BNS_OK);
  recover_address(publicKey, recoverAddress);
  assert(bns_equals_ignore_case(publicKey, recoverPublicKey) == true);
  assert(bns_equals_ignore_case(address, recoverAddress) == true);

  LOG_DEBUG("test_recovery() end");
}

void test_recovery_private_key_without_leading_zero() {
  LOG_DEBUG("test_recovery() begin");

  char *privateKey1 =
      "c3860e6169207f9b5525a1550242009b2393582453cc8cd797720f3c4f2157c";
  char *privateKey2 =
      "0c3860e6169207f9b5525a1550242009b2393582453cc8cd797720f3c4f2157c";
  char *publicKey =
      "4cf2e891be0d78d6a04601192c097f77b259dc923dfcb5203571d5b33291d7aac17ec47e"
      "4238ecd8969b85b084c323d491cc52c08a43dbefe7917634df3fdd93";
  char *address = "915dc2ce1298f6d8b6d05d796bc300e82aec8d91";

  char *text = " ";

  unsigned char shaResult1[HASH_BYTES];
  unsigned char shaResult2[HASH_BYTES];
  char recoverPublicKey1[PUBLIC_KEY_STR_LEN] = {0};
  char recoverPublicKey2[PUBLIC_KEY_STR_LEN] = {0};
  char recoverAddress1[ADDRESS_STR_LEN] = {0};
  char recoverAddress2[ADDRESS_STR_LEN] = {0};
  sig_t sig1 = {0};
  sig_t sig2 = {0};
  bns_sha3((unsigned char *)text, 1, shaResult1);
  bns_sha3((unsigned char *)text, 1, shaResult2);
  assert(bns_sign(shaResult1, privateKey1, &sig1) == BNS_OK);
  assert(bns_sign(shaResult2, privateKey2, &sig2) == BNS_OK);
  assert(recover_public_key(shaResult1, &sig1, recoverPublicKey1) == BNS_OK);
  assert(recover_public_key(shaResult2, &sig2, recoverPublicKey2) == BNS_OK);
  recover_address(recoverPublicKey1, recoverAddress1);
  recover_address(recoverPublicKey2, recoverAddress2);
  assert(bns_equals_ignore_case(publicKey, recoverPublicKey1) == true);
  assert(bns_equals_ignore_case(publicKey, recoverPublicKey2) == true);
  assert(bns_equals_ignore_case(address, recoverAddress1) == true);
  assert(bns_equals_ignore_case(address, recoverAddress2) == true);

  LOG_DEBUG("test_recovery() end");
}

void test_recovery_public_key_without_leading_zero() {
  LOG_DEBUG("test_recovery() begin");

  char *privateKey =
      "4f7178e92e1ee2da3c7f37ae2a197197988e4acc743f05d19605be4236c37a5d";
  char *publicKey =
      "82859ed3eeb890e6b119d91091e993a8740e3d95ee5d4e95c5c4c532bf16ff81a3888ade"
      "1630844c5589d896a99ce613590dd9d69f74c470d95cd5267d57923";
  char *publicKey2 =
      "082859ed3eeb890e6b119d91091e993a8740e3d95ee5d4e95c5c4c532bf16ff81a3888ad"
      "e1630844c5589d896a99ce613590dd9d69f74c470d95cd5267d57923";
  char *address = "dc19bcaba90a9a07d2cca02315c5038a833ea6f2";

  char *text = " ";

  unsigned char shaResult[HASH_BYTES];
  char recoverPublicKey[PUBLIC_KEY_STR_LEN] = {0};
  char recoverAddress[ADDRESS_STR_LEN] = {0};
  sig_t sig = {0};
  bns_sha3((unsigned char *)text, 1, shaResult);
  assert(bns_sign(shaResult, privateKey, &sig) == BNS_OK);
  assert(recover_public_key(shaResult, &sig, recoverPublicKey) == BNS_OK);
  recover_address(recoverPublicKey, recoverAddress);
  assert((bns_equals_ignore_case(publicKey, recoverPublicKey) == true) ||
         (bns_equals_ignore_case(publicKey2, recoverPublicKey) == true));
  assert(bns_equals_ignore_case(address, recoverAddress) == true);

  LOG_DEBUG("test_recovery() end");
}

void test_recovery_address_without_leading_zero() {
  LOG_DEBUG("test_recovery() begin");

  char *privateKey =
      "fbda55c1d6a81c7fbaec35d006c9120b5f44073dcc79b43f0bc8aaef18b42a9c";
  char *publicKey =
      "73924cc02291afc388eaf8acca46dedaa0f692185d8f78568c1cf742905f65f0f1ec8284"
      "d67df8db9a5ef85383b5b29d49b2f19831e733858526f96840023eb7";
  char *address = "4ecc82419a168cecf441decdb4868a32a7dd1ca";
  char *address2 = "04ecc82419a168cecf441decdb4868a32a7dd1ca";

  char *text = " ";

  unsigned char shaResult[HASH_BYTES];
  char recoverPublicKey[PUBLIC_KEY_STR_LEN] = {0};
  char recoverAddress[ADDRESS_STR_LEN] = {0};
  sig_t sig = {0};
  bns_sha3((unsigned char *)text, 1, shaResult);
  assert(bns_sign(shaResult, privateKey, &sig) == BNS_OK);
  assert(recover_public_key(shaResult, &sig, recoverPublicKey) == BNS_OK);
  recover_address(publicKey, recoverAddress);
  assert(bns_equals_ignore_case(publicKey, recoverPublicKey) == true);
  assert((bns_equals_ignore_case(address, recoverAddress) == true) ||
         (bns_equals_ignore_case(address2, recoverAddress) == true));

  LOG_DEBUG("test_recovery() end");
}

int main() {
  test_recovery();
  test_recovery_private_key_without_leading_zero();
  test_recovery_public_key_without_leading_zero();
  test_recovery_address_without_leading_zero();
  test_sign_recover();
  test_verify_signature();
  return 0;
}
