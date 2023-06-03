target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    LootTable.cpp
    LootTable.hpp
    LootTables.cpp
    LootTables.hpp
    Pool.cpp
    Pool.hpp
)

download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/loot_tables.tar.gz"
    loot_tables.tar.gz
    ${CMAKE_BINARY_DIR}
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
file(ARCHIVE_EXTRACT INPUT ${CMAKE_BINARY_DIR}/loot_tables.tar.gz DESTINATION ${CMAKE_BINARY_DIR}/assets)

add_subdirectory(conditions)
add_subdirectory(context)
add_subdirectory(entries)
add_subdirectory(functions)
add_subdirectory(rolls)
