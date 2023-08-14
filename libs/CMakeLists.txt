add_subdirectory(EnjinPlatformSdk)

if (${ENJINSDK_INCLUDE_BEAM})
    add_subdirectory(EnjinPlatformSdkBeam)
endif ()

if (${ENJINSDK_INCLUDE_FUEL_TANKS})
    add_subdirectory(EnjinPlatformSdkFuelTanks)
endif ()

if (${ENJINSDK_INCLUDE_MARKETPLACE})
    add_subdirectory(EnjinPlatformSdkMarketplace)
endif ()
