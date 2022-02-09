#ifndef BNS_C_CLIENT_RECEIPT_LOCATOR_H
#define BNS_C_CLIENT_RECEIPT_LOCATOR_H

#include <bns-client/core/core.h>

#define LEDGER_RECEIPT_LOCATOR_PATH "/clearanceOrderAndSn/"

#define RECEIPT_LOCATOR_PRINT_FORMAT \
  "receiptLocator=receipt_locator_t(clearanceOrder=%lld, indexValue=%s)"
#define RECEIPT_LOCATOR_TO_PRINT_ARGS(receiptLocator) \
  receiptLocator->clearanceOrder, (receiptLocator)->indexValue

void build_get_receipt_locator_url(char**      url,
                                   const char* serverUrl,
                                   const char* indexValueKey);

_CHECK_RESULT
bns_exit_code_t bns_get_receipt_locator(const bns_client_t* bnsClient,
                                        receipt_locator_t*  receiptLocator);

_CHECK_RESULT
bns_exit_code_t check_and_parse_receipt_locator_response(
    const char*        res,
    const char*        indexValueKey,
    receipt_locator_t* receiptLocator);

_CHECK_RESULT
bns_exit_code_t build_receipt_locator(const char*        indexValueKey,
                                      clearance_order_t  clearanceOrder,
                                      sn_t               sn,
                                      receipt_locator_t* receiptLocator);

void receipt_locator_free(receipt_locator_t* receiptLocator);

#endif  // BNS_C_CLIENT_RECEIPT_LOCATOR_H
