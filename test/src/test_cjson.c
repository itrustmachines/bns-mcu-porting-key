#include <assert.h>
#include <cJSON.h>
#include <malloc.h>
#include <bns-client/util/log.h>
#include <time.h>

void test_curl_parse_long_int(char *json, long long int mock_time)
{
  cJSON *root, *temp;
  root = cJSON_Parse(json);
  temp = cJSON_GetObjectItem(root, "long");
  LOG_DEBUG("time={%lld}", mock_time);
  long long int parseResult = (long long int)temp->valueint;
  assert(mock_time == parseResult);
  cJSON_Delete(root);
}

char *test_curl_build_long_int(long long int mock_time)
{
  cJSON *root;
  root = cJSON_CreateObject();
  cJSON_AddNumberToObject(root, "long", (double)mock_time, mock_time);
  cJSON_AddStringToObject(root, "description", "string");
  char *string = cJSON_PrintUnformatted(root);
  assert(string != NULL);
  cJSON_Delete(root);
  return string;
}

int main()
{
  long long int t = (long int)time(NULL);
  long long int mock_time = (t * 1000);
  char *buildString = test_curl_build_long_int(mock_time);
  test_curl_parse_long_int(buildString, mock_time);
  free(buildString);
}
