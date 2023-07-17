target_sources(${PROJECT_NAME}
        PRIVATE
        EventListenerRegistration.cpp
        GlobalEvents.cpp
        PlatformEvent.cpp
        SubstrateEvents.cpp)

add_subdirectory(pusher)
