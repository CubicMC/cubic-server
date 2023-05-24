target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    ChunkColumn.cpp
    ChunkColumn.hpp
    Level.cpp
    Level.hpp
    LevelData.cpp
    LevelData.hpp
    Palette.hpp
    Palette.cpp
    Section.cpp
    Section.hpp
)

if (GTEST)
    # Do not forget to add enable_testing() if you want to test your library !
    enable_testing()

    add_executable(
        levelData_test
        LevelData.cpp
        tests/LevelData_unittest.cpp
        tests/DynamicStorage_test.cpp
    )

    target_compile_definitions(
        levelData_test
        PRIVATE
        -DTESTING
    )

    target_include_directories(
        levelData_test
        PRIVATE
        ${CMAKE_SOURCE_DIR}/cubic-server
    )

    target_link_libraries(
        levelData_test
        GTest::gtest_main
    )

    # Enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module.
    include(GoogleTest)
    gtest_discover_tests(levelData_test)

endif()
