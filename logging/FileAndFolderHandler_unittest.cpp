#include <gtest/gtest.h>
#include "FileAndFolderHandler.hpp"

#include <cstdio>
#include <unistd.h>

namespace logging
{
    TEST(FileAndFolderHandlerClass, folder_exist)
    {
        FileAndFolderHandler ff_handler;

        EXPECT_TRUE(ff_handler.folder_exist("CMakeFiles"));
        EXPECT_FALSE(ff_handler.folder_exist("logging"));
    }

    TEST(FileAndFolderHandlerClass, file_exist)
    {
        FileAndFolderHandler ff_handler;

        EXPECT_TRUE(ff_handler.file_exist("Makefile"));
        EXPECT_FALSE(ff_handler.file_exist("log"));
    }

    TEST(FileAndFolderHandlerClass, create_folder)
    {
        FileAndFolderHandler ff_handler;

        ff_handler.create_folder("logs");

        EXPECT_EQ(ff_handler.get_folder_path(), "logs");

        rmdir("logs");
    }

    TEST(FileAndFolderHandlerClass, create_folder_already_existing)
    {
        FileAndFolderHandler ff_handler;

        ff_handler.create_folder("logs");

        EXPECT_EQ(ff_handler.get_folder_path(), "logs");

        testing::internal::CaptureStdout();
        ff_handler.create_folder("logs");

        EXPECT_EQ(ff_handler.get_folder_path(), "logs");
        EXPECT_EQ("Folder 'logs' already exist. Setting it as folder_path\n", testing::internal::GetCapturedStdout());

        rmdir("logs");
    }

    TEST(FileAndFolderHandlerClass, create_file)
    {
        FileAndFolderHandler ff_handler;

        ff_handler.create_file("test.txt");

        EXPECT_TRUE(ff_handler.file_exist("test.txt"));
        EXPECT_EQ(ff_handler.get_file_path(), "test.txt");

        std::remove("test.txt");
    }

    TEST(FileAndFolderHandlerClass, create_file_inside_of_folder)
    {
        FileAndFolderHandler ff_handler;

        ff_handler.create_folder("logs");
        ff_handler.create_file("test.txt");

        EXPECT_EQ(ff_handler.get_folder_path(), "logs");
        EXPECT_EQ(ff_handler.get_file_path(), "logs/test.txt");
        EXPECT_TRUE(ff_handler.file_exist("logs/test.txt"));

        std::remove("logs/test.txt");
        rmdir("logs");
    }
}