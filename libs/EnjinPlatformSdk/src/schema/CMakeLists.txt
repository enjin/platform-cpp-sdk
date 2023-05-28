target_sources(${PROJECT_NAME}
        PRIVATE
        CoreSchema.cpp)

add_subdirectory(fragments)
add_subdirectory(mutations)
add_subdirectory(queries)
