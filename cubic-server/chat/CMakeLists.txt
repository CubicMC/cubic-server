target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    Message.cpp
    Message.hpp
    ChatRegistry.cpp
    ChatRegistry.hpp
    translationFromKey.cpp
    translationFromKey.hpp
)

add_subdirectory(events)
