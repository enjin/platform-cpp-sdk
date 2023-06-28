target_sources(${PROJECT_NAME}
        PRIVATE
        EventListenerRegistration.cpp
        PlatformEvent.cpp)

add_subdirectory(pusher)
