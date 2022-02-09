#include <bns-client/util/log.h>

#if defined(LOG_DETAIL)
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define __FILENAME__(filename) \
  (strrchr(filename, '\\') ? strrchr(filename, '\\') + 1 : filename)
#else
#define __FILENAME__(filename) \
  (strrchr(filename, '/') ? strrchr(filename, '/') + 1 : filename)
#endif  // defined(_WIN32) || defined(_WIN64)

#if defined(_WIN32) || defined(_WIN64)

#include <winsock2.h>

#elif defined(_AZS_)
#include <sys/time.h>
#include <unistd.h>
#else  // defined(_WIN32) || defined(_WIN64)

#include <sys/syscall.h>
#include <sys/time.h>
#include <unistd.h>

#endif  // defined(_WIN32) || defined(_WIN64)

long getCurrentThreadID(void) {
#if defined(_WIN32) || defined(_WIN64)
  return GetCurrentThreadId();
#elif defined(_AZS_)
#elif __linux__
  return syscall(SYS_gettid);
#elif defined(__APPLE__) && defined(__MACH__)
  return syscall(SYS_thread_selfid);
#else
  return (long)pthread_self();
#endif  // defined(_WIN32) || defined(_WIN64)
}

#if defined(LOG_LINE_NUM)

void log_prefix(const char* tag, const char* file_name, const int line_num) {
#if defined(_WIN32) || defined(_WIN64)
  LOG_BACKEND("[%s][%ld][%s:%d] ", tag, getCurrentThreadID(),
              __FILENAME__(file_name), line_num);
#elif defined(_AZS_)
  char           date[21];
  struct timeval tv;
  gettimeofday(&tv, NULL);
  strftime(date, sizeof(date) / sizeof(*date), DATE_TIME_FORMAT,
           gmtime(&tv.tv_sec));
  LOG_BACKEND("[%s,%03ld][%s][%s:%d] ", date, tv.tv_usec / 1000, tag,
              __FILENAME__(file_name), line_num);
#else   // defined(_WIN32) || defined(_WIN64)
  char           date[21];
  struct timeval tv;
  gettimeofday(&tv, NULL);
  strftime(date, sizeof(date) / sizeof(*date), DATE_TIME_FORMAT,
           gmtime(&tv.tv_sec));
  LOG_BACKEND("[%s,%03ld][%s][%ld][%s:%d] ", date, tv.tv_usec / 1000, tag,
              getCurrentThreadID(), __FILENAME__(file_name), line_num);
#endif  // defined(_WIN32) || defined(_WIN64)
}
#if LOG_LEVEL >= LOG_LEVEL_ERROR
void log_error(const char* file_name, const int line_num) {
  log_prefix("ERROR", file_name, line_num);
}
#endif  // LOG_LEVEL >= LOG_LEVEL_ERROR
#if LOG_LEVEL >= LOG_LEVEL_WARN
void log_warn(const char* file_name, const int line_num) {
  log_prefix("WARN", file_name, line_num);
}
#endif  // LOG_LEVEL >= LOG_LEVEL_WARN
#if LOG_LEVEL >= LOG_LEVEL_INFO
void log_info(const char* file_name, const int line_num) {
  log_prefix("INFO", file_name, line_num);
}
#endif  // LOG_LEVEL >= LOG_LEVEL_INFO
#if LOG_LEVEL >= LOG_LEVEL_DEBUG
void log_debug(const char* file_name, const int line_num) {
  log_prefix("DEBUG", file_name, line_num);
}
#endif  // LOG_LEVEL >= LOG_LEVEL_DEBUG

#else  // defined(LOG_LINE_NUM)

void log_prefix(const char* tag, const char* file_name) {
#if defined(_WIN32) || defined(_WIN64)
  LOG_BACKEND("[%s][%ld][%s] ", tag, getCurrentThreadID(), file_name);
#elif defined(_AZS_)
  char           date[21];
  struct timeval tv;
  gettimeofday(&tv, NULL);
  strftime(date, sizeof(date) / sizeof(*date), DATE_TIME_FORMAT,
           gmtime(&tv.tv_sec));
  LOG_BACKEND("[%s,%03ld][%s][%s] ", date, tv.tv_usec / 1000, tag, file_name);
#else   // defined(_WIN32) || defined(_WIN64)
  char           date[21];
  struct timeval tv;
  gettimeofday(&tv, NULL);
  strftime(date, sizeof(date) / sizeof(*date), DATE_TIME_FORMAT,
           gmtime(&tv.tv_sec));
  LOG_BACKEND("[%s,%03ld][%s][%ld][%s] ", date, tv.tv_usec / 1000, tag,
              getCurrentThreadID(), file_name);
#endif  // defined(_WIN32) || defined(_WIN64)
}

#if LOG_LEVEL >= LOG_LEVEL_ERROR
void log_error(const char* file_name) { log_prefix("ERROR", file_name); }
#endif  // LOG_LEVEL >= LOG_LEVEL_ERROR
#if LOG_LEVEL >= LOG_LEVEL_WARN
void log_warn(const char* file_name) { log_prefix("WARN", file_name); }
#endif  // LOG_LEVEL >= LOG_LEVEL_WARN
#if LOG_LEVEL >= LOG_LEVEL_INFO
void log_info(const char* file_name) { log_prefix("INFO", file_name); }
#endif  // LOG_LEVEL >= LOG_LEVEL_INFO
#if LOG_LEVEL >= LOG_LEVEL_DEBUG
void log_debug(const char* file_name) { log_prefix("DEBUG", file_name); }
#endif  // LOG_LEVEL >= LOG_LEVEL_DEBUG

#endif  // defined(LOG_LINE_NUM)
#endif  // defined(LOG_DETAIL)