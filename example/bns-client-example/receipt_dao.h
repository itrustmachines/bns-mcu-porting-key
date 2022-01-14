#ifndef BNS_C_CLIENT_EXAMPLE_SRC_RECEIPT_DAO_H_
#define BNS_C_CLIENT_EXAMPLE_SRC_RECEIPT_DAO_H_

/* Change the maximum storage quantity here */
#define RECEIPT_CACHE_SIZE 1000

#include <bns-client/core/bns_types.h>

/**
 * store receipt in memory
 */
void receipt_cache_save(const receipt_t* receipt);

/**
 * use clearanceOrder to find out which receipts to be verified
 */
void receipt_cache_findPageByClearanceOrderEqualOrLessThan(
    clearance_order_t clearanceOrder,
    size_t            page,
    size_t            pageSize,
    receipt_t*        outputReceipt,
    size_t*           outputSize);

/**
 * delete the verified receipts
 */
void receipt_cache_delete(const receipt_t* receipt);

/* Get the number of receipt */
int receipt_cache_count();

#endif  // BNS_C_CLIENT_EXAMPLE_SRC_RECEIPT_DAO_H_
