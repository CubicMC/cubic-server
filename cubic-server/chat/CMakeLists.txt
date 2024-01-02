target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    Message.cpp
    Message.hpp
    translationFromKey.cpp
    translationFromKey.hpp
)

add_subdirectory(events)
