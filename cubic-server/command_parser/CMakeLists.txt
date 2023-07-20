target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    CommandParser.hpp
    CommandParser.cpp
)

add_subdirectory (commands)
add_subdirectory (selectors)
