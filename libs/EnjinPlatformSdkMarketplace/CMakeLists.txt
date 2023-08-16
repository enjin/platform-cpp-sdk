message(STATUS "Enjin: Making SDK marketplace library")

include(GenerateExportHeader)

####################################################################################################################
### Create library and set properties

add_library(${MARKETPLACE_PROJECT_NAME} SHARED "")
add_library(${PROJECT_NAME}::Marketplace ALIAS ${MARKETPLACE_PROJECT_NAME})
generate_export_header(${MARKETPLACE_PROJECT_NAME})

# Set properties
set_property(TARGET ${MARKETPLACE_PROJECT_NAME} PROPERTY VERSION ${PROJECT_VERSION})
set_property(TARGET ${MARKETPLACE_PROJECT_NAME} PROPERTY SOVERSION 2)
set_property(TARGET ${MARKETPLACE_PROJECT_NAME} PROPERTY INTERFACE_${MARKETPLACE_PROJECT_NAME}_MAJOR_VERSION 2)
set_property(TARGET ${MARKETPLACE_PROJECT_NAME} APPEND PROPERTY COMPATIBLE_INTERFACE_STRING ${MARKETPLACE_PROJECT_NAME}_MAJOR_VERSION)

# Sets compiler specific flags
if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
        target_compile_options(${MARKETPLACE_PROJECT_NAME} PRIVATE -Wall -Wextra)
    elseif (${CMAKE_CXX_COMPILER_ID} MATCHES "MSVC")
        target_compile_options(${MARKETPLACE_PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c /wd4996)
        target_compile_definitions(${MARKETPLACE_PROJECT_NAME} PRIVATE ${MARKETPLACE_PROJECT_NAME}_EXPORTS)
    endif ()
endif ()

####################################################################################################################
### Setup dependencies

# SDK core
target_link_libraries(${MARKETPLACE_PROJECT_NAME} PUBLIC ${PROJECT_NAME})

####################################################################################################################
### Target sources

include(GNUInstallDirs)

target_include_directories(${MARKETPLACE_PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/${MARKETPLACE_PROJECT_NAME}")

add_subdirectory(src)

####################################################################################################################
### Install library and export package

install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        FILES_MATCHING PATTERN "*.hpp")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/enjinplatformsdkmarketplace_export.h"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(TARGETS ${MARKETPLACE_PROJECT_NAME}
        EXPORT ${MARKETPLACE_PROJECT_NAME}
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# Generate package files
include(CMakePackageConfigHelpers)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/${MARKETPLACE_PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${MARKETPLACE_PROJECT_NAME}")

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/${MARKETPLACE_PROJECT_NAME}ConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${MARKETPLACE_PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${MARKETPLACE_PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${MARKETPLACE_PROJECT_NAME}")

install(EXPORT ${MARKETPLACE_PROJECT_NAME}
        FILE "${MARKETPLACE_PROJECT_NAME}Targets.cmake"
        NAMESPACE ${MARKETPLACE_PROJECT_NAME}::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${MARKETPLACE_PROJECT_NAME}")
