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
    "${CMAKE_BINARY_DIR}/loot_tables.tar.gz"
    ${CMAKE_BINARY_DIR}
)

execute_process(
    COMMAND tar xzf ${CMAKE_BINARY_DIR}/loot_tables.tar.gz
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND_ERROR_IS_FATAL ANY
)

execute_process(
    COMMAND mkdir -p assets
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND_ERROR_IS_FATAL ANY
)

execute_process(
    COMMAND mv -n ${CMAKE_BINARY_DIR}/loot_tables ${CMAKE_BINARY_DIR}/assets/loot_tables
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

execute_process(
    COMMAND rm -r ${CMAKE_BINARY_DIR}/loot_tables
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_subdirectory(conditions)
add_subdirectory(context)
add_subdirectory(entries)
add_subdirectory(functions)
add_subdirectory(rolls)
