message(STATUS "Enjin: Building tests")

add_executable(${TESTS_NAME} "")

####################################################################################################################
### Setup dependencies

if (${ENJINSDK_USING_CONAN})
    target_link_libraries(${TESTS_NAME} PRIVATE ${CONAN_LIBS})
else ()
    include(CheckIncludeFiles)
    include(GNUInstallDirs)

    ################################################################################################################
    ### Setup GoogleTest

    # Download and unpack GoogleTest at configure time
    configure_file(CMakeLists.txt.in "${CMAKE_CURRENT_BINARY_DIR}/googletest-download/CMakeLists.txt")
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            RESULT_VARIABLE result
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googletest-download")
    if (result)
        message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif ()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE result
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googletest-download")
    if (result)
        message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif ()

    # Prevent overriding the parent project's compiler/linker settings on Windows
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Add GoogleTest directly to the build
    add_subdirectory("${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
            "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
            EXCLUDE_FROM_ALL)

    target_link_libraries(${TESTS_NAME}
            PRIVATE
            gtest
            gmock
            gtest_main
            gmock_main)

    ################################################################################################################
    ### Setup other third-party dependencies

    # RapidJSON
    target_include_directories(${TESTS_NAME} PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

    # cpp-httplib
    target_link_libraries(${TESTS_NAME} PRIVATE httplib::httplib)

    # IXWebSocket
    target_link_libraries(${TESTS_NAME}
            PRIVATE
            ixwebsocket::ixwebsocket)
endif ()

####################################################################################################################
### Link SDK libraries

# Core library
target_include_directories(${TESTS_NAME}
        PRIVATE
        "$<INSTALL_INTERFACE:include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include"
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/libs/${PROJECT_NAME}/src/include")
target_link_libraries(${TESTS_NAME} PRIVATE ${PROJECT_NAME})

# Beam library
if (${ENJINSDK_INCLUDE_BEAM})
    target_include_directories(${TESTS_NAME}
            PRIVATE
            "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/libs/${BEAM_PROJECT_NAME}/src/include")
    target_link_libraries(${TESTS_NAME} PRIVATE ${BEAM_PROJECT_NAME})
endif ()

# Marketplace library
if (${ENJINSDK_INCLUDE_MARKETPLACE})
    target_include_directories(${TESTS_NAME}
            PRIVATE
            "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/libs/${MARKETPLACE_PROJECT_NAME}/src/include")
    target_link_libraries(${TESTS_NAME} PRIVATE ${MARKETPLACE_PROJECT_NAME})
endif ()

####################################################################################################################
### Add test files

target_include_directories(${TESTS_NAME}
        PRIVATE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)

add_subdirectory("Test Data") # Include test data
add_subdirectory(fake)
add_subdirectory(mock)
add_subdirectory(suite)
add_subdirectory(unit)

add_test(NAME ${TESTS_NAME} COMMAND ${TESTS_NAME})
