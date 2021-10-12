#ifndef BNS_C_CLIENT_BNS_SERVER_INFO_H
#define BNS_C_CLIENT_BNS_SERVER_INFO_H

#include <bns-client/core/core.h>

#define LEDGER_BNS_SERVER_INFO_PATH "/ledger/serverInfo"

#define BNS_SERVER_INFO_PRINT_FORMAT                     \
  "bnsServerInfo=bns_server_info_t(contractAddress=%s, " \
  "serverWalletAddress=%s)"
#define BNS_SERVER_INFO_TO_PRINT_ARGS(bnsServerInfo) \
  bnsServerInfo->contractAddress, (bnsServerInfo)->serverWalletAddress

_CHECK_RESULT
char *build_get_bns_server_info_url(char *serverUrl);

_CHECK_RESULT
bns_exit_code_t bns_post_server_info(const bns_client_t *bnsClient,
                                     bns_server_info_t *bnsServerInfo);

_CHECK_RESULT
bns_exit_code_t build_server_info_request(const char *address,
                                          const char *privateKey, char **json);
_CHECK_RESULT
bns_exit_code_t check_and_parse_bns_server_info_response(
    const char *res, bns_server_info_t *bnsServerInfo);

#endif  // BNS_C_CLIENT_BNS_SERVER_INFO_H
