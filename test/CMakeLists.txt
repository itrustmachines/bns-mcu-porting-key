file(GLOB TEST_SOURCES LIST_DIRECTORIES false src/*.c)
file(GLOB_RECURSE TEST_DIRS LIST_DIRECTORIES true src/*.c)

set(CMAKE_BUILD_TYPE Debug)
set(TEST_SOURCES ${TEST_SOURCES})

foreach (TEST_DIR ${TEST_DIRS})
    if (IS_DIRECTORY "${TEST_DIR}")
        add_subdirectory("${TEST_DIR}")
    endif ()
endforeach ()

include_directories(${BNS_CLIENT_INCLUDE_DIRS})

foreach (SRC ${TEST_SOURCES})
    if (NOT IS_DIRECTORY ${SRC})
        get_filename_component(SRC_NAME "${SRC}" NAME_WE)
        set(SRC_NAME "bns_client_${SRC_NAME}")
        add_executable(${SRC_NAME} ${SRC})
        target_link_libraries(${SRC_NAME} PRIVATE bns-client-lib)
        add_test(NAME ${SRC_NAME} COMMAND ${SRC_NAME})
    endif ()
endforeach ()