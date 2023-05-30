target_sources (${CMAKE_PROJECT_NAME} PRIVATE 
    LootTable.cpp 
    LootTable.hpp 
    LootTables.cpp 
    LootTables.hpp 
    Pool.cpp 
    Pool.hpp
)

add_subdirectory(conditions)
add_subdirectory(context)
add_subdirectory(entries)
add_subdirectory(functions)
add_subdirectory(rolls)
