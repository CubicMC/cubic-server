# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (Math Math.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (Math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (GTEST)
  # Do not forget to add enable_testing() if you want to test your library !
  enable_testing()

  # Now simply add a new executable with the test file
  add_executable(
    math_test
    Math.cpp
    Math_unittest.cpp
  )

  # Link the GoogleTest library to the executable
  target_link_libraries(
    math_test
    GTest::gtest_main
  )

  # Enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module.
  include(GoogleTest)
  gtest_discover_tests(math_test)

endif()