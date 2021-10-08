#ifndef BNS_C_CLIENT_LOG_H
#define BNS_C_CLIENT_LOG_H

#include <stdarg.h>

#define LOG_LEVEL_OFF 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_DEBUG 4

#if !defined(LOG_LEVEL)
#define LOG_LEVEL LOG_LEVEL_INFO
#endif  // !defined(LOG_LEVEL)

#if !defined(LOG_BACKEND)
#if defined(_AZS_)
#include <applibs/log.h>
#define LOG_BACKEND Log_Debug
#else
#include <stdio.h>
#define LOG_BACKEND printf
#endif  // defined(_AZS_)
#endif  // !defined(LOG_BACKEND)

#if LOG_LEVEL > LOG_LEVEL_OFF

#if !defined(LOG_DETAIL)
#if LOG_LEVEL >= LOG_LEVEL_ERROR && !defined(LOG_ERROR)
#define LOG_ERROR(M, ...) LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_ERROR && !defined(LOG_ERROR)
#if LOG_LEVEL >= LOG_LEVEL_WARN && !defined(LOG_WARN)
#define LOG_WARN(M, ...) LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_WARN && !defined(LOG_WARN)
#if LOG_LEVEL >= LOG_LEVEL_INFO && !defined(LOG_INFO)
#define LOG_INFO(M, ...) LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_INFO && !defined(LOG_INFO)
#if LOG_LEVEL >= LOG_LEVEL_DEBUG && !defined(LOG_DEBUG)
#define LOG_DEBUG(M, ...) LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_DEBUG && !defined(LOG_DEBUG)
#else   // !defined(LOG_DETAIL)

#define DATE_TIME_FORMAT "%Y-%m-%d %H:%M:%S"
long getCurrentThreadID(void);

#if defined(LOG_LINE_NUM)
#if LOG_LEVEL >= LOG_LEVEL_ERROR && !defined(LOG_ERROR)
void log_error(const char *file_name, int line_num);
#define LOG_ERROR(M, ...)        \
  log_error(__FILE__, __LINE__); \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_ERROR && !defined(LOG_ERROR)
#if LOG_LEVEL >= LOG_LEVEL_WARN && !defined(LOG_WARN)
void log_warn(const char *file_name, int line_num);
#define LOG_WARN(M, ...)        \
  log_warn(__FILE__, __LINE__); \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_WARN && !defined(LOG_WARN)
#if LOG_LEVEL >= LOG_LEVEL_INFO && !defined(LOG_INFO)
void log_info(const char *file_name, int line_num);
#define LOG_INFO(M, ...)        \
  log_info(__FILE__, __LINE__); \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_INFO && !defined(LOG_INFO)
#if LOG_LEVEL >= LOG_LEVEL_DEBUG && !defined(LOG_DEBUG)
void log_debug(const char *file_name, int line_num);
#define LOG_DEBUG(M, ...)        \
  log_debug(__FILE__, __LINE__); \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_DEBUG && !defined(LOG_DEBUG)
#else   // defined(LOG_LINE_NUM)
#if LOG_LEVEL >= LOG_LEVEL_ERROR && !defined(LOG_ERROR)
void log_error(const char *file_name);
#define LOG_ERROR(M, ...) \
  log_error(__FILE__);    \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_ERROR && !defined(LOG_ERROR)
#if LOG_LEVEL >= LOG_LEVEL_WARN && !defined(LOG_WARN)
void log_warn(const char *file_name);
#define LOG_WARN(M, ...) \
  log_warn(__FILE__);    \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_WARN
#if LOG_LEVEL >= LOG_LEVEL_INFO && !defined(LOG_INFO)
void log_info(const char *file_name);
#define LOG_INFO(M, ...) \
  log_info(__FILE__);    \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_INFO
#if LOG_LEVEL >= LOG_LEVEL_DEBUG && !defined(LOG_DEBUG)
void log_debug(const char *file_name);
#define LOG_DEBUG(M, ...) \
  log_debug(__FILE__);    \
  LOG_BACKEND(M "\n", ##__VA_ARGS__)
#endif  // LOG_LEVEL >= LOG_LEVEL_DEBUG
#endif  // defined(LOG_LINE_NUM)
#endif  // defined(LOG_DETAIL)
#endif  // LOG_LEVEL > LOG_LEVEL_OFF

#if !defined(LOG_ERROR)
#define LOG_ERROR(M, ...)
#endif  // !defined(LOG_ERROR)
#if !defined(LOG_WARN)
#define LOG_WARN(M, ...)
#endif  // !defined(LOG_WARN)
#if !defined(LOG_INFO)
#define LOG_INFO(M, ...)
#endif  // !defined(LOG_INFO)
#if !defined(LOG_DEBUG)
#define LOG_DEBUG(M, ...)
#endif  // !defined(LOG_DEBUG)

#endif  // BNS_C_CLIENT_LOG_H
