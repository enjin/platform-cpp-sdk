target_sources(${FUEL_TANKS_PROJECT_NAME}
        PRIVATE
        FuelTanksMutations.cpp
        FuelTanksQueries.cpp)

add_subdirectory(fragments)
add_subdirectory(mutations)
add_subdirectory(queries)
