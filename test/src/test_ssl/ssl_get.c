#include "ssl_get.h"

#include <curl/curl.h>
#include <errno.h>
#include <pthread.h>
#include <bns-client/util/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static pthread_mutex_t mutex_get  = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex_post = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex_put  = PTHREAD_MUTEX_INITIALIZER;

#define BUFFER_SIZE 4096

int ssl_init() { return curl_global_init(CURL_GLOBAL_ALL); }

void ssl_clean() { curl_global_cleanup(); }

static size_t storeDownloadedDataCallback(void*  chunks,
                                          size_t chunkSize,
                                          size_t chunksCount,
                                          void*  memoryBlock) {
  MemoryBlock* block = (MemoryBlock*)memoryBlock;

  size_t additionalDataSize = chunkSize * chunksCount;
  block->data = realloc(block->data, block->size + additionalDataSize + 1);
  if (block->data == NULL) {
    LOG_ERROR(
        "storeDownloadedDataCallback() Out of memory, realloc returned "
        "NULL: errno=%d (%s)'n",
        errno, strerror(errno));
    abort();
  }

  memcpy(block->data + block->size, chunks, additionalDataSize);
  block->size += additionalDataSize;
  block->data[block->size] =
      0;  // Ensure the block of memory is null terminated.

  return additionalDataSize;
}

static void logCurlError(const char* message, int curlErrCode) {
  LOG_ERROR("curl err=%d, '%s', %s", curlErrCode,
            curl_easy_strerror(curlErrCode), message);
}

char* ssl_post(char* url, char* postData) {
  pthread_mutex_lock(&mutex_post);
  LOG_DEBUG("ssl_post() begin() url=%s, postData=%s", url, postData);
  CURL*       curlHandle    = NULL;
  CURLcode    res           = 0;
  MemoryBlock block         = {.data = NULL, .size = 0};
  char*       return_string = malloc(sizeof(char) * BUFFER_SIZE);

  // Init the cURL library.
  if ((res = curl_global_init(CURL_GLOBAL_ALL)) != CURLE_OK) {
    logCurlError("curl_global_init", res);
    goto exitLabel;
  }

  if ((curlHandle = curl_easy_init()) == NULL) {
    LOG_DEBUG("curl_easy_init() failed");
    goto cleanupLabel;
  }
  curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYHOST, 0L);

  curl_easy_setopt(curlHandle, CURLOPT_POST, 1L);
  curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDSIZE, (long)strlen(postData));
  curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, postData);

  struct curl_slist* hs = NULL;
  hs                    = curl_slist_append(hs, APPLICATION_JSON);
  curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, hs);

  // Specify URL to download.
  // Important: any change in the domain name must be reflected in the
  // AllowedConnections capability in app_manifest.json.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_URL, url)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_URL", res);
    goto cleanupLabel;
  }

  // Set output level to verbose.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_VERBOSE, 1L)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_VERBOSE", res);
    goto cleanupLabel;
  }

  // Let cURL follow any HTTP 3xx redirects.
  // Important: any redirection to different domain names requires that domain
  // name to be added to app_manifest.json.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, 1L)) !=
      CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_FOLLOWLOCATION", res);
    goto cleanupLabel;
  }

  // Set up callback for cURL to use when downloading data.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION,
                              storeDownloadedDataCallback)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_FOLLOWLOCATION", res);
    goto cleanupLabel;
  }

  // Set the custom parameter of the callback to the memory block.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, (void*)&block)) !=
      CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_WRITEDATA", res);
    goto cleanupLabel;
  }

  /*// Specify a user agent.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_USERAGENT,
  "libcurl-agent/1.0")) != CURLE_OK) { logCurlError("curl_easy_setopt
  CURLOPT_USERAGENT", res); goto cleanupLabel;
  }*/

  // Perform the download of the web page.
  while ((res = curl_easy_perform(curlHandle)) != CURLE_OK) {
    logCurlError("curl_easy_perform", res);
  }

  if (block.size != 0) {
    memcpy(return_string, block.data, block.size);
    return_string[block.size] = '\0';
  }

  LOG_DEBUG("ssl_post() content-length=%zu bytes", block.size);
  LOG_DEBUG("ssl_post() content=%s", block.data);

cleanupLabel:
  // Clean up allocated memory.
  free(block.data);
  // Clean up sample's cURL resources.
  curl_easy_cleanup(curlHandle);
  curl_slist_free_all(hs);

  // Clean up cURL library's resources.
  curl_global_cleanup();

exitLabel:
  LOG_DEBUG("ssl_post() end");
  pthread_mutex_unlock(&mutex_post);
  return return_string;
}

char* ssl_put(char* url, char* postData) {
  pthread_mutex_lock(&mutex_put);
  LOG_DEBUG("ssl_put() begin() url=%s, postData=%s", url, postData);
  CURL*       curlHandle    = NULL;
  CURLcode    res           = 0;
  MemoryBlock block         = {.data = NULL, .size = 0};
  char*       return_string = malloc(sizeof(char) * BUFFER_SIZE);

  // Init the cURL library.
  if ((res = curl_global_init(CURL_GLOBAL_ALL)) != CURLE_OK) {
    logCurlError("curl_global_init", res);
    goto exitLabel;
  }

  if ((curlHandle = curl_easy_init()) == NULL) {
    LOG_DEBUG("curl_easy_init() failed");
    goto cleanupLabel;
  }
  curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYHOST, 0L);

  curl_easy_setopt(curlHandle, CURLOPT_CUSTOMREQUEST, "PUT");
  curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDSIZE, (long)strlen(postData));
  curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, postData);

  struct curl_slist* hs = NULL;
  hs                    = curl_slist_append(hs, APPLICATION_JSON);
  curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, hs);

  // Specify URL to download.
  // Important: any change in the domain name must be reflected in the
  // AllowedConnections capability in app_manifest.json.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_URL, url)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_URL", res);
    goto cleanupLabel;
  }

  // Set output level to verbose.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_VERBOSE, 1L)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_VERBOSE", res);
    goto cleanupLabel;
  }

  // Let cURL follow any HTTP 3xx redirects.
  // Important: any redirection to different domain names requires that domain
  // name to be added to app_manifest.json.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, 1L)) !=
      CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_FOLLOWLOCATION", res);
    goto cleanupLabel;
  }

  // Set up callback for cURL to use when downloading data.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION,
                              storeDownloadedDataCallback)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_FOLLOWLOCATION", res);
    goto cleanupLabel;
  }

  // Set the custom parameter of the callback to the memory block.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, (void*)&block)) !=
      CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_WRITEDATA", res);
    goto cleanupLabel;
  }

  /*// Specify a user agent.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_USERAGENT,
  "libcurl-agent/1.0")) != CURLE_OK) { logCurlError("curl_easy_setopt
  CURLOPT_USERAGENT", res); goto cleanupLabel;
  }*/

  // Perform the download of the web page.
  while ((res = curl_easy_perform(curlHandle)) != CURLE_OK) {
    logCurlError("curl_easy_perform", res);
  }

  if (block.size != 0) {
    memcpy(return_string, block.data, block.size);
    return_string[block.size] = '\0';
  }

  LOG_DEBUG("ssl_post() content-length=%zu bytes", block.size);
  LOG_DEBUG("ssl_post() content=%s", block.data);

cleanupLabel:
  // Clean up allocated memory.
  free(block.data);
  // Clean up sample's cURL resources.
  curl_easy_cleanup(curlHandle);
  curl_slist_free_all(hs);
  // Clean up cURL library's resources.
  curl_global_cleanup();

exitLabel:
  LOG_DEBUG("ssl_post() end");
  pthread_mutex_unlock(&mutex_put);
  return return_string;
}

char* ssl_get(char* url) {
  pthread_mutex_lock(&mutex_get);
  LOG_DEBUG("ssl_get() begin() url=%s", url);
  CURL*       curlHandle    = NULL;
  CURLcode    res           = 0;
  MemoryBlock block         = {.data = NULL, .size = 0};
  char*       return_string = malloc(sizeof(char) * BUFFER_SIZE);

  // Init the cURL library.
  if ((res = curl_global_init(CURL_GLOBAL_ALL)) != CURLE_OK) {
    logCurlError("curl_global_init", res);
    goto exitLabel;
  }

  if ((curlHandle = curl_easy_init()) == NULL) {
    logCurlError("curl_easy_init failed", 0);
    goto cleanupLabel;
  }
  curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYHOST, 0L);

  struct curl_slist* hs = NULL;
  hs                    = curl_slist_append(hs, APPLICATION_JSON);
  curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, hs);

  // Specify URL to download.
  // Important: any change in the domain name must be reflected in the
  // AllowedConnections capability in app_manifest.json.
  if ((res = curl_easy_setopt(curlHandle, CURLOPT_URL, url)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_URL", res);
    goto cleanupLabel;
  }

  if ((res = curl_easy_setopt(curlHandle, CURLOPT_VERBOSE, 1L)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_VERBOSE", res);
    goto cleanupLabel;
  }

  if ((res = curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, 1L)) !=
      CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_FOLLOWLOCATION", res);
    goto cleanupLabel;
  }

  if ((res = curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION,
                              storeDownloadedDataCallback)) != CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_FOLLOWLOCATION", res);
    goto cleanupLabel;
  }

  if ((res = curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, (void*)&block)) !=
      CURLE_OK) {
    logCurlError("curl_easy_setopt CURLOPT_WRITEDATA", res);
    goto cleanupLabel;
  }

  while ((res = curl_easy_perform(curlHandle)) != CURLE_OK) {
    logCurlError("curl_easy_perform", res);
  }

  if (block.size != 0) {
    memcpy(return_string, block.data, block.size);
    return_string[block.size] = '\0';
  }

  LOG_DEBUG("ssl_get() content-length=%zu bytes", block.size);
  LOG_DEBUG("ssl_get() content=%s", block.data);

cleanupLabel:
  // Clean up allocated memory.
  free(block.data);
  // Clean up sample's cURL resources.
  curl_easy_cleanup(curlHandle);
  curl_slist_free_all(hs);
  // Clean up cURL library's resources.
  curl_global_cleanup();

exitLabel:
  LOG_DEBUG("ssl_get() end");
  pthread_mutex_unlock(&mutex_get);
  return return_string;
}
