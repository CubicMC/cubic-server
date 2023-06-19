target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    main.cpp
    Server.cpp
    Server.hpp
    Client.cpp
    Client.hpp
    Player.cpp
    Player.hpp
    PlayerAttributes.cpp
    PlayerAttributes.hpp
    Entity.cpp
    Entity.hpp
    Item.cpp
    Item.hpp
    LivingEntity.cpp
    LivingEntity.hpp
    Chat.cpp
    Chat.hpp
    WorldGroup.cpp
    WorldGroup.hpp
    World.cpp
    World.hpp
    Dimension.cpp
    Dimension.hpp
    SoundList.hpp
    nbt.hpp
    nbt.cpp
    SoundSystem.hpp
    SoundSystem.cpp
    concept.hpp
    TickClock.hpp
    TickClock.cpp
    CommandLine.hpp
    CommandLine.cpp
    allCommands.hpp
    Permissions.hpp
    Permissions.cpp
    types.hpp
    types.cpp
    PluginInterface.hpp
    PluginManager.hpp
    PluginManager.cpp
    exceptions.hpp
    nbt.c
    EASEncryptionHandler.cpp
    EASEncryptionHandler.hpp
    RSAEncryptionHandler.cpp
    RSAEncryptionHandler.hpp
    Checksum.cpp
    Checksum.hpp
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)

if (GTEST)
    enable_testing()

    add_executable(
        nbt_test
        nbt.hpp
        nbt.cpp
        nbt_unittest.cpp
    )

    target_link_libraries(
        nbt_test
        GTest::gtest_main
        rapidcheck
        rapidcheck_gtest
    )

    # file(DOWNLOAD https://cdn.cubic-mc.com/tests/hello_world.nbt, ${CMAKE_CURRENT_BINARY_DIR}/hello_world.nbt SHOW_PROGRESS TLS_VERIFY ON)
    # file(DOWNLOAD https://cdn.cubic-mc.com/tests/bigtest.nbt, ${CMAKE_CURRENT_BINARY_DIR}/bigtest.nbt SHOW_PROGRESS TLS_VERIFY ON)

    download_and_check_file(
        https://cdn.cubic-mc.com/tests/hello_world.nbt
        hello_world.nbt
        ${CMAKE_CURRENT_BINARY_DIR}
    )

    download_and_check_file(
        https://cdn.cubic-mc.com/tests/bigtest.nbt
        bigtest.nbt
        ${CMAKE_CURRENT_BINARY_DIR}
    )

    # execute_process(COMMAND wget -q https://cdn.cubic-mc.com/tests/hello_world.nbt -O ${CMAKE_CURRENT_BINARY_DIR}/hello_world.nbt)
    # execute_process(COMMAND wget -q https://cdn.cubic-mc.com/tests/bigtest.nbt -O ${CMAKE_CURRENT_BINARY_DIR}/bigtest.nbt)

    include(GoogleTest)
    gtest_discover_tests(nbt_test)
endif()

add_subdirectory (protocol_id_converter)
add_subdirectory (protocol)
add_subdirectory (default)
add_subdirectory (math)
add_subdirectory (configuration)
add_subdirectory (logging)
add_subdirectory (interface)
add_subdirectory (world_storage)
add_subdirectory (command_parser)
add_subdirectory (whitelist)
add_subdirectory (generation)
add_subdirectory (thread_pool)
add_subdirectory (items)
add_subdirectory (chat)
add_subdirectory (loot_tables)
add_subdirectory (recipes)
add_subdirectory (events)
add_subdirectory (utility)
add_subdirectory (scoreboard)
add_subdirectory (registry)
