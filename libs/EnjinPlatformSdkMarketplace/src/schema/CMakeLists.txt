target_sources(${MARKETPLACE_PROJECT_NAME}
        PRIVATE
        MarketplaceMutations.cpp
        MarketplaceQueries.cpp)

add_subdirectory(fragments)
add_subdirectory(mutations)
add_subdirectory(queries)
