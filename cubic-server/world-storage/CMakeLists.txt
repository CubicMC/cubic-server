target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        ChunkColumn.cpp
        ChunkColumn.hpp
        Level.cpp
        Level.hpp
        LevelData.cpp
        LevelData.hpp
        WorldStorage.cpp
        WorldStorage.hpp
)

if (GTEST)
  # Do not forget to add enable_testing() if you want to test your library !
  enable_testing()

  # Now simply add a new executable with the test file
  add_executable(
    world_test
    WorldStorage.cpp
    LevelData.cpp
    Level.cpp
    ChunkColumn.cpp
    tests/WorldStorage_unittest.cpp
  )

  # Link the GoogleTest library to the executable
  target_link_libraries(
    world_test
    GTest::gtest_main
  )

  add_executable(
    levelData_test
    LevelData.cpp
    tests/LevelData_unittest.cpp
  )

  target_link_libraries(
    levelData_test
    GTest::gtest_main
  )

  add_executable(
    level_test
    Level.cpp
    ChunkColumn.cpp
    tests/Level_unittest.cpp
  )

  target_link_libraries(
    level_test
    GTest::gtest_main
  )

  add_executable(
    chunkColumn_test
    ChunkColumn.cpp
    tests/ChunkColumn_unittest.cpp
  )

  target_link_libraries(
    chunkColumn_test
    GTest::gtest_main
  )

  # Enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module.
  include(GoogleTest)
  gtest_discover_tests(world_test)
  gtest_discover_tests(levelData_test)

endif()