target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    ChunkColumn.cpp
    ChunkColumn.hpp
    Level.cpp
    Level.hpp
    LevelData.cpp
    LevelData.hpp
    Block.hpp
    Block.cpp
    Palette.hpp
    globalPalette_TEMP.hpp
    globalPalette_TEMP.cpp
)

if (GTEST)
    # Do not forget to add enable_testing() if you want to test your library !
    enable_testing()

    add_executable(
        levelData_test
        LevelData.cpp
        tests/LevelData_unittest.cpp
    )

    target_link_libraries(
        levelData_test
        GTest::gtest_main
    )

    # Enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module.
    include(GoogleTest)
    gtest_discover_tests(levelData_test)

endif()
