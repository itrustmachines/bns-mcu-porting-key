#include <bns-client/contract/clearance_record_cache.h>
#include <string.h>
#include <time.h>

static clearance_record_cache_t
    clearanceRecordCache[CLEARANCE_RECORD_CACHE_SIZE] = {0};

void get_clearance_record_cache(const clearance_order_t clearanceOrder,
                                clearance_record_t *const clearanceRecord) {
  if (clearanceOrder == 0) {
    return;
  }
  if (!clearanceRecord) {
    return;
  }
  for (size_t i = 0; i < CLEARANCE_RECORD_CACHE_SIZE; i++) {
    if (clearanceRecordCache[i].clearanceRecord.clearanceOrder ==
        clearanceOrder) {
      memcpy(clearanceRecord, &clearanceRecordCache[i].clearanceRecord,
             sizeof(clearance_record_t));
      clearanceRecordCache[i].timestamp = time(NULL);
    }
  }
}

void set_clearance_record_cache(
    const clearance_record_t *const clearanceRecord) {
  if (!clearanceRecord) {
    return;
  }
  if (clearanceRecord->clearanceOrder == 0) {
    return;
  }
  bool placed = false;
  for (size_t i = 0; i < CLEARANCE_RECORD_CACHE_SIZE; i++) {
    if (clearanceRecordCache[i].clearanceRecord.clearanceOrder == 0) {
      memcpy(&clearanceRecordCache[i].clearanceRecord, clearanceRecord,
             sizeof(clearance_record_t));
      clearanceRecordCache[i].timestamp = time(NULL);
      placed = true;
      break;
    }
  }
  if (!placed) {
    size_t minIndex = 0;
    bns_long_t minTimestamp = clearanceRecordCache[0].timestamp;
    for (size_t i = 1; i < CLEARANCE_RECORD_CACHE_SIZE; i++) {
      if (clearanceRecordCache[i].timestamp < minTimestamp) {
        minIndex = i;
        minTimestamp = clearanceRecordCache[i].timestamp;
      }
    }
    memcpy(&clearanceRecordCache[minIndex].clearanceRecord, clearanceRecord,
           sizeof(clearance_record_t));
    clearanceRecordCache[minIndex].timestamp = time(NULL);
  }
}

void reset_clearance_record_cache() {
  memset(&clearanceRecordCache, 0, sizeof(clearanceRecordCache));
}
