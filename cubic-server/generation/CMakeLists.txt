target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    generator.hpp
    generator.cpp
    nether.cpp
    nether.hpp
    overworld.cpp
    overworld.hpp
)

add_subdirectory (features)
add_subdirectory (player_constructions)
