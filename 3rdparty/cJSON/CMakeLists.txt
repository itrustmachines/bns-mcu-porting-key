project(cJSON)

set(CJSON_INCLUDE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
        PARENT_SCOPE)


add_library(${PROJECT_NAME} cJSON_min.c)