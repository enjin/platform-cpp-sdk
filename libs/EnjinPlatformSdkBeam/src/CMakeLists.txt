target_include_directories(${BEAM_PROJECT_NAME}
        PRIVATE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)

target_sources(${BEAM_PROJECT_NAME}
        PRIVATE
        Class.cpp)
