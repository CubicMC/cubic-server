target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    Click.hpp
    Click.cpp
    Hover.hpp
    Hover.cpp
)

add_subdirectory(clicks)
add_subdirectory(hovers)
