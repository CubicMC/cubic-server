# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
# add_library (TimeFormatter TimeFormatter.cpp)
# add_library (FileAndFolderHandler FileAndFolderHandler.cpp)
add_library (World ChunkColumn.cpp Level.cpp LevelData.cpp World.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
# target_include_directories (TimeFormatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories (FileAndFolderHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (World PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (GTEST)
  # Do not forget to add enable_testing() if you want to test your library !
  enable_testing()

  # Now simply add a new executable with the test file
  add_executable(
    world_test
    World.cpp
    LevelData.cpp
    Level.cpp
    ChunkColumn.cpp
    tests/World_unittest.cpp
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

  # Enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module.
  include(GoogleTest)
  gtest_discover_tests(world_test)
  gtest_discover_tests(levelData_test)

endif()