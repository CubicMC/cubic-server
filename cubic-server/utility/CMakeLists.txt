target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    PseudoRandomGenerator.cpp
    PseudoRandomGenerator.hpp
    SharedFromThis.hpp
)

add_subdirectory(random_tick_block_functions)
