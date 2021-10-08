file(GLOB TEST_SOURCES LIST_DIRECTORIES false *.c)

set(TEST_SOURCES ${TEST_SOURCES})

include_directories(${BNS_CLIENT_INCLUDE_DIRS})

foreach (SRC ${TEST_SOURCES})
    if (NOT IS_DIRECTORY ${SRC})
        get_filename_component(SRC_NAME "${SRC}" NAME_WE)
        set(SRC_NAME "bns_client_${SRC_NAME}")
        add_executable(${SRC_NAME} ${SRC})
        add_test(NAME ${SRC_NAME} COMMAND ${SRC_NAME})
        target_link_libraries(${SRC_NAME} PRIVATE bns-client-lib)
    endif ()
endforeach ()
