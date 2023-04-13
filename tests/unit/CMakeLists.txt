target_sources(${TESTS_NAME}
        PRIVATE
        JsonDeserializableBaseTest.cpp
        JsonUtilTest.cpp
        JsonValueTest.cpp)

add_subdirectory(graphql)
