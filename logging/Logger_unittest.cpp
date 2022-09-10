#include <gtest/gtest.h>
#include "Logger.hpp"

#include <dirent.h>
#include <cstdio>
#include <unistd.h>

namespace logging
{

    TEST(Logging, file_exist)
    {
        Logger logger(false);
        EXPECT_TRUE(logger.file_exist("Logger_unittest.cpp"));
        EXPECT_FALSE(logger.file_exist("Logger_unittest.cpp2"));
    }

    TEST(Logging, get_time)
    {
        Logger logger(false);
        EXPECT_EQ(logger.get_time().size(), std::to_string("YYYY/MM/DD HH:MM:SS.sss").size());
        EXPECT_EQ(logger.get_time("YYYY/MM/DD HH:MM:SS.sss").size(), std::to_string("YYYY/MM/DD HH:MM:SS.sss").size());
        EXPECT_EQ(logger.get_time("YYYY").size(), 4);
        EXPECT_EQ(logger.get_time("MM").size(), std::to_string("MM").size());
        EXPECT_EQ(logger.get_time("DD").size(), std::to_string("DD").size());
        EXPECT_EQ(logger.get_time("HH").size(), std::to_string("HH").size());
        EXPECT_EQ(logger.get_time("MM").size(), std::to_string("MM").size());
        EXPECT_EQ(logger.get_time("SS").size(), std::to_string("SS").size());
        EXPECT_EQ(logger.get_time("sss").size(), std::to_string("sss").size());
        EXPECT_EQ(logger.get_time("YYY").size(), std::to_string("YYY").size());
        EXPECT_EQ(logger.get_time("The month is MM").size(), std::to_string("The month is MM").size());
    }

    TEST(Logging, create_folder_if_nessessary)
    {
        Logger logger(false);
        logger.create_folder_if_nessessary("logs");
        EXPECT_EQ(logger._folder_path, "logs");
        logger.create_folder_if_nessessary("logs");
        EXPECT_EQ(logger._folder_path, "logs");
        EXPECT_EQ("Folder already exist. Passing...\n", testing::internal::GetCapturedStdout());
        rmdir("logs");
    }

    TEST(Logging, create_file)
    {
        Logger logger(false);
        logger.create_file("test.txt");
        EXPECT_TRUE(logger.file_exist("test.txt"));
        EXPECT_EQ(logger._file_path, "test.txt");
        logger.create_file("test.txt");
        EXPECT_FALSE(logger.file_exist("test.txt"));
        EXPECT_TRUE(logger.file_exist(logger.get_time("YYYY-MM-DD-") + "1.txt"));
        EXPECT_EQ(logger._file_path, logger.get_time("YYYY-MM-DD-") + "1.txt");
        std::remove("test.txt");
        std::remove(logger._file_path.c_str());
    }

    TEST(Logging, log)
    {
        Logger logger;
        logger.log("test");
        std::fstream file(logger._file_path, std::ios::in);
        char line[29];
        file.getline(line, 29);
        std::string line_str(line);
        line_str.find("test");
        EXPECT_NE(line_str.find("test"), std::string::npos);
        file.close();
        std::remove(logger._file_path.c_str());
        rmdir("logs");
    }

    TEST(Logging, default_behavior)
    {
        Logger logger;
        EXPECT_EQ(logger._folder_path, "logs");
        EXPECT_EQ(logger._file_path, logger.get_time("YYYY-MM-DD-") + "1.txt");
        EXPECT_TRUE(logger.file_exist(logger._file_path));
        logger.log("test");
        std::fstream file(logger._file_path, std::ios::in);
        char line[29];
        file.getline(line, 29);
        std::string line_str(line);
        line_str.find("test");
        EXPECT_NE(line_str.find("test"), std::string::npos);
        file.close();
        std::remove(logger._file_path.c_str());
        rmdir("logs");
    }
}