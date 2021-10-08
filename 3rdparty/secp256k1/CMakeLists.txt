project(secp256k1)

include_directories(./)
include_directories(include)

set(SECP256K1_INCLUDE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        PARENT_SCOPE)

add_library(${PROJECT_NAME} src/secp256k1.c)
