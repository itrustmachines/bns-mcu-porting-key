#ifndef BNS_CLIENT_SRC_BNS_CLIENT_CONTRACT_CLEARANCE_RECORD_CACHE_H_
#define BNS_CLIENT_SRC_BNS_CLIENT_CONTRACT_CLEARANCE_RECORD_CACHE_H_

#include <bns-client/core/bns_types.h>

#if !defined(CLEARANCE_RECORD_CACHE_SIZE)
#define CLEARANCE_RECORD_CACHE_SIZE 5
#endif  // !defined(CLEARANCE_RECORD_CACHE_SIZE)

typedef struct clearance_record_cache_t {
  bns_long_t         timestamp;
  clearance_record_t clearanceRecord;
} clearance_record_cache_t;

void get_clearance_record_cache(clearance_order_t   clearanceOrder,
                                clearance_record_t* clearanceRecord);

void set_clearance_record_cache(const clearance_record_t* clearanceRecord);

void reset_clearance_record_cache();

#endif  // BNS_CLIENT_SRC_BNS_CLIENT_CONTRACT_CLEARANCE_RECORD_CACHE_H_
