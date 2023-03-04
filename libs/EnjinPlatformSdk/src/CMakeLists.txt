target_include_directories(${PROJECT_NAME}
        PRIVATE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)

add_subdirectory(json)
