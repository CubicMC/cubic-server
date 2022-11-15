target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        Math.cpp
)

if (GTEST)
  enable_testing()

  add_executable(
    math_test
    Math.cpp
    Math_unittest.cpp
  )

  target_link_libraries(
    math_test
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(math_test)
endif()