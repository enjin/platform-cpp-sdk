target_sources(${BEAM_PROJECT_NAME}
        PRIVATE
        BeamQueries.cpp)

add_subdirectory(fragments)
add_subdirectory(mutations)
add_subdirectory(queries)
