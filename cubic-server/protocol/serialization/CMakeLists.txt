target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    add.hpp
    add.cpp
    addPrimaryType.hpp
    pop.hpp
    popPrimaryType.hpp
)

if (GTEST)
    enable_testing()

    add_executable(
        serialization_test
        typeSerialization_unittest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../nbt.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../nbt.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../nbt.c
    )

    target_link_libraries(
        serialization_test
        Blocks
        GTest::gtest_main
        rapidcheck
        rapidcheck_gtest
        z
    )

    target_include_directories(
        serialization_test
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../
        ${nbt_SOURCE_DIR}
        ${Blocks_SOURCE_DIR}
        ${noise_SOURCE_DIR}
    )

    include(GoogleTest)
    gtest_discover_tests(serialization_test)
endif()
