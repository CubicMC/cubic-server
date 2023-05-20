target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    TimeFormatter.cpp
    TimeFormatter.hpp
    FileAndFolderHandler.cpp
    FileAndFolderHandler.hpp
    Logger.cpp
    Logger.hpp
    formating.hpp
)

if(GTEST)
    enable_testing()

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

    target_link_libraries(
        Logger_test
        GTest::gtest_main
        spdlog::spdlog
        $<$<BOOL:${MINGW}>:ws2_32>
    )

    target_link_libraries(
        TimeFormatter_test
        GTest::gtest_main
    )

    target_link_libraries(
        FileAndFolderHandler_test
        GTest::gtest_main
    )

    target_compile_options(
        Logger_test
        PRIVATE
        -DTESTING
    )

    include(GoogleTest)
    gtest_discover_tests(Logger_test)
    gtest_discover_tests(TimeFormatter_test)
    gtest_discover_tests(FileAndFolderHandler_test)
endif()
