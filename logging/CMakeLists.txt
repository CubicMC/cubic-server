# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
# add_library (TimeFormatter TimeFormatter.cpp)
# add_library (FileAndFolderHandler FileAndFolderHandler.cpp)
add_library (Logging TimeFormatter.cpp FileAndFolderHandler.cpp Logger.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
# target_include_directories (TimeFormatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories (FileAndFolderHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (Logging PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(GTEST)
  # Do not forget to add enable_testing() if you want to test your library !
  enable_testing()

  # Now simply add a new executable with the test file
  add_executable(
    Logger_test
    TimeFormatter.cpp
    FileAndFolderHandler.cpp
    Logger.cpp
    Logger_unittest.cpp
  )

  add_executable(
      TimeFormatter_test
      TimeFormatter.cpp
      TimeFormatter_unittest.cpp
  )

  add_executable(
      FileAndFolderHandler_test
      FileAndFolderHandler.cpp
      FileAndFolderHandler_unittest.cpp
  )

  # Link the GoogleTest library to the executable
  target_link_libraries(
    Logger_test
    GTest::gtest_main
  )

  target_link_libraries(
      TimeFormatter_test
      GTest::gtest_main
  )

  target_link_libraries(
      FileAndFolderHandler_test
      GTest::gtest_main
  )

  # Enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module.
  include(GoogleTest)
  gtest_discover_tests(Logger_test)
  gtest_discover_tests(TimeFormatter_test)
  gtest_discover_tests(FileAndFolderHandler_test)
endif()