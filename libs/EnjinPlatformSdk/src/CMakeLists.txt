target_include_directories(${PROJECT_NAME}
        PRIVATE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)

target_sources(${PROJECT_NAME}
        PRIVATE
        JsonDeserializableBase.cpp
        JsonUtil.cpp
        JsonValue.cpp)

add_subdirectory(graphql)
