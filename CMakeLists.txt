cmake_minimum_required(VERSION 3.16)

include("cmake/EnjinPlatformSdkMacros.cmake")

####################################################################################################################
### Define project and set properties

project(EnjinPlatformSdk
        LANGUAGES CXX
        VERSION 0.1.0)

# Setup output directories before creating any targets
setup_output_directories()

set(BEAM_PROJECT_NAME ${PROJECT_NAME}Beam)
set(TESTS_NAME ${PROJECT_NAME}Tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

option(ENJINSDK_INCLUDE_BEAM "ENJINSDK_INCLUDE_BEAM" OFF)
option(ENJINSDK_BUILD_TESTS "ENJINSDK_BUILD_TESTS" OFF)

# Sets compiler specific flags
if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
    elseif (${CMAKE_CXX_COMPILER_ID} MATCHES "MSVC")
        target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c /wd4996)
        target_compile_definitions(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_EXPORTS)
    endif ()
endif ()

add_subdirectory(libs)

####################################################################################################################
### Setup tests

include(CTest)

if (ENJINSDK_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()

####################################################################################################################
### Unset variables

unset(BEAM_PROJECT_NAME)
unset(TESTS_NAME)
unset(ENJINSDK_INCLUDE_BEAM CACHE)
unset(ENJINSDK_BUILD_TESTS CACHE)
