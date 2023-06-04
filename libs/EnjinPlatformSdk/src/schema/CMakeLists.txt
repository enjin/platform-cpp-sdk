target_sources(${PROJECT_NAME}
        PRIVATE
        CoreMutations.cpp
        CoreQueries.cpp)

add_subdirectory(fragments)
add_subdirectory(mutations)
add_subdirectory(queries)
