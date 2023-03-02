message(STATUS "Enjin: Building SDK beam library")

include(GenerateExportHeader)

####################################################################################################################
### Create library and set properties

add_library(${BEAM_PROJECT_NAME} SHARED "")
add_library(${PROJECT_NAME}::Beam ALIAS ${BEAM_PROJECT_NAME})
generate_export_header(${BEAM_PROJECT_NAME})

# Set properties
set_property(TARGET ${BEAM_PROJECT_NAME} PROPERTY VERSION ${PROJECT_VERSION})
set_property(TARGET ${BEAM_PROJECT_NAME} PROPERTY SOVERSION 2)
set_property(TARGET ${BEAM_PROJECT_NAME} PROPERTY INTERFACE_${BEAM_PROJECT_NAME}_MAJOR_VERSION 2)
set_property(TARGET ${BEAM_PROJECT_NAME} APPEND PROPERTY COMPATIBLE_INTERFACE_STRING ${BEAM_PROJECT_NAME}_MAJOR_VERSION)

####################################################################################################################
### Setup dependencies

# SDK core
target_link_libraries(${BEAM_PROJECT_NAME} PUBLIC ${PROJECT_NAME})

####################################################################################################################
### Target sources

include(GNUInstallDirs)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/${BEAM_PROJECT_NAME}")

add_subdirectory(src)

####################################################################################################################
### Install library and export package

install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        FILES_MATCHING PATTERN "*.hpp")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/enjinplatformsdkbeam_export.h"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(TARGETS ${BEAM_PROJECT_NAME}
        EXPORT ${BEAM_PROJECT_NAME}
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# Generate package files
include(CMakePackageConfigHelpers)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/${BEAM_PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${BEAM_PROJECT_NAME}")

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/${BEAM_PROJECT_NAME}ConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${BEAM_PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${BEAM_PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${BEAM_PROJECT_NAME}")

install(EXPORT ${BEAM_PROJECT_NAME}
        FILE "${BEAM_PROJECT_NAME}Targets.cmake"
        NAMESPACE ${BEAM_PROJECT_NAME}::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${BEAM_PROJECT_NAME}")
