target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        main.cpp
        Server.cpp
        Server.hpp
        Client.cpp
        Client.hpp
        Player.cpp
        Player.hpp
        Entity.cpp
        Entity.hpp
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
        allCommands.hpp
)

if (GTEST)
    enable_testing()

    add_executable(
            nbt_test
            nbt.hpp
            nbt_unittest.cpp
    )

    target_link_libraries(
            nbt_test
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(nbt_test)
endif()

add_subdirectory (protocol)
add_subdirectory (default)
add_subdirectory (math)
add_subdirectory (configuration)
add_subdirectory (logging)
add_subdirectory (interface)
add_subdirectory (world_storage)
add_subdirectory (command_parser)
