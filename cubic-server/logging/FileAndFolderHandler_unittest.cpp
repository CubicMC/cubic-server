#include "FileAndFolderHandler.hpp"
#include <gtest/gtest.h>

#include <cstdio>
#include <unistd.h>

namespace logging {
TEST(FileAndFolderHandlerClass, folderExist)
{
    FileAndFolderHandler ffHandler;

    EXPECT_TRUE(ffHandler.folderExist("CMakeFiles"));
    EXPECT_FALSE(ffHandler.folderExist("logging"));
}

TEST(FileAndFolderHandlerClass, fileExist)
{
    FileAndFolderHandler ffHandler;

    EXPECT_TRUE(ffHandler.fileExist("Makefile"));
    EXPECT_FALSE(ffHandler.fileExist("log"));
}

TEST(FileAndFolderHandlerClass, createFolder)
{
    FileAndFolderHandler ffHandler;

    ffHandler.createFolder("logs");

    EXPECT_EQ(ffHandler.getFolderPath(), "logs");

    rmdir("logs");
}

TEST(FileAndFolderHandlerClass, createFolder_already_existing)
{
    FileAndFolderHandler ffHandler;

    ffHandler.createFolder("logs");

    EXPECT_EQ(ffHandler.getFolderPath(), "logs");

    ffHandler.createFolder("logs");

    EXPECT_EQ(ffHandler.getFolderPath(), "logs");

    rmdir("logs");
}

TEST(FileAndFolderHandlerClass, createFile)
{
    FileAndFolderHandler ffHandler;

    ffHandler.createFile("test.txt");

    EXPECT_TRUE(ffHandler.fileExist("test.txt"));
    EXPECT_EQ(ffHandler.getFilePath(), "test.txt");

    std::remove("test.txt");
}

TEST(FileAndFolderHandlerClass, create_file_inside_of_folder)
{
    FileAndFolderHandler ffHandler;

    ffHandler.createFolder("logs");
    ffHandler.createFile("test.txt");

    EXPECT_EQ(ffHandler.getFolderPath(), "logs");
    EXPECT_EQ(ffHandler.getFilePath(), "logs/test.txt");
    EXPECT_TRUE(ffHandler.fileExist("logs/test.txt"));

    std::remove("logs/test.txt");
    rmdir("logs");
}
}
