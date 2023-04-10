target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    add.hpp
    addPrimaryType.hpp
    pop.hpp
    popPrimaryType.hpp
)

if (GTEST)
    enable_testing()

    add_executable(
        serialization_test
        typeSerialization_unittest.cpp
    )

    target_link_libraries(
        serialization_test
        GTest::gtest_main
        rapidcheck
        rapidcheck_gtest
    )

    target_include_directories(
        serialization_test
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../
    )

    include(GoogleTest)
    gtest_discover_tests(serialization_test)
endif()
