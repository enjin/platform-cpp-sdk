cmake_minimum_required(VERSION 3.16)

include("cmake/EnjinPlatformSdkMacros.cmake")

####################################################################################################################
### Define project and set properties

project(EnjinPlatformSdk
        LANGUAGES CXX
        VERSION 0.1.0)

# Setup variables
set(BEAM_PROJECT_NAME ${PROJECT_NAME}Beam)
set(TESTS_NAME ${PROJECT_NAME}Tests)
set(ENJINSDK_USING_CONAN 0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

option(ENJINSDK_INCLUDE_BEAM "ENJINSDK_INCLUDE_BEAM" OFF)
option(ENJINSDK_BUILD_TESTS "ENJINSDK_BUILD_TESTS" OFF)

# Setup Conan if available or else include dependencies
if (EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    conan_basic_setup()

    set(ENJINSDK_USING_CONAN 1)
else ()
    include("cmake/FindRapidJSON.cmake")
    include("cmake/FindCppHttpLib.cmake")
    include("cmake/FindOpenSSL.cmake")
    include("cmake/FindIXWebSocket.cmake")

    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        include("cmake/FindDate.cmake")
    endif ()
endif ()

# Setup output directories before creating any targets
setup_output_directories()

####################################################################################################################
### Build SDK libraries

add_subdirectory(libs)

####################################################################################################################
### Setup tests

include(CTest)

if (${ENJINSDK_BUILD_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif ()

####################################################################################################################
### Unset variables

unset(BEAM_PROJECT_NAME)
unset(TESTS_NAME)
unset(ENJINSDK_USING_CONAN)
unset(ENJINSDK_INCLUDE_BEAM CACHE)
unset(ENJINSDK_BUILD_TESTS CACHE)
