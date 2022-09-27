#include <gtest/gtest.h>

#include "Logger.hpp"
#include "FileAndFolderHandler.hpp"
#include "TimeFormatter.hpp"

namespace logging
{
    TEST(Logging, default_behavior)
    {
        Logger logger;
        FileAndFolderHandler ff_handler;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");

        EXPECT_TRUE(ff_handler.folder_exist("logs"));
        EXPECT_TRUE(ff_handler.file_exist("logs/" + filename));

        testing::internal::CaptureStdout();
        logger.debug("test");
        std::string output = testing::internal::GetCapturedStdout();

        std::fstream file("logs/" + filename, std::ios::in);
        std::string line;
        std::getline(file, line);

        EXPECT_NE(line.find(TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS")), std::string::npos);
        EXPECT_NE(output.find(TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS")), std::string::npos);
        EXPECT_NE(line.find("[DEBUG]"), std::string::npos);
        EXPECT_NE(output.find("[DEBUG]"), std::string::npos);
        EXPECT_NE(line.find("test"), std::string::npos);
        EXPECT_NE(output.find("test"), std::string::npos);

        file.close();
        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }

    TEST(Logging, vector_specification_level_in_file)
    {
        Logger logger;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");
        std::vector<LogLevel> levels = {LogLevel::DEBUG, LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR, LogLevel::FATAL};

        EXPECT_EQ(logger.get_display_specification_level_in_file(), levels);
        logger.set_display_specification_level_in_file(LogLevel::DEBUG);
        levels.push_back(LogLevel::DEBUG);
        EXPECT_EQ(logger.get_display_specification_level_in_file(), levels);
        logger.unset_display_specification_level_in_file(LogLevel::FATAL);
        levels.erase(levels.end() - 2);
        EXPECT_EQ(logger.get_display_specification_level_in_file(), levels);

        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }

    TEST(Logging, vector_specification_level_in_console)
    {
        Logger logger;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");
        std::vector<LogLevel> levels = {LogLevel::DEBUG, LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR, LogLevel::FATAL};

        EXPECT_EQ(logger.get_display_specification_level_in_console(), levels);
        logger.set_display_specification_level_in_console(LogLevel::DEBUG);
        levels.push_back(LogLevel::DEBUG);
        EXPECT_EQ(logger.get_display_specification_level_in_console(), levels);
        logger.unset_display_specification_level_in_console(LogLevel::FATAL);
        levels.erase(levels.end() - 2);
        EXPECT_EQ(logger.get_display_specification_level_in_console(), levels);

        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }

    TEST(Logging, display_specification_level_in_file)
    {
        Logger logger;
        FileAndFolderHandler ff_handler;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");

        testing::internal::CaptureStdout();
        logger.debug("test");
        std::string output = testing::internal::GetCapturedStdout();

        std::fstream file("logs/" + filename, std::ios::in);
        std::string line;
        std::getline(file, line);

        EXPECT_NE(line.find("test"), std::string::npos);
        EXPECT_NE(output.find("test"), std::string::npos);

        logger.unset_display_specification_level_in_file(LogLevel::DEBUG);

        testing::internal::CaptureStdout();
        logger.debug("not_a_test");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_EQ(line.find("not_a_test"), std::string::npos);
        EXPECT_NE(output.find("not_a_test"), std::string::npos);

        // file.seekg(0, std::ios::beg);
        file.close();
        file.open("logs/" + filename, std::ios::in);
        std::getline(file, line);

        testing::internal::CaptureStdout();
        logger.fatal("fatal_test");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);
        std::cout << "line = " << line << std::endl;

        EXPECT_NE(line.find("fatal_test"), std::string::npos);
        EXPECT_NE(output.find("fatal_test"), std::string::npos);

        file.close();
        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }

    TEST(Logging, display_specification_level_in_console)
    {
        Logger logger;
        FileAndFolderHandler ff_handler;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");

        testing::internal::CaptureStdout();
        logger.debug("test");
        std::string output = testing::internal::GetCapturedStdout();

        std::fstream file("logs/" + filename, std::ios::in);
        std::string line;
        std::getline(file, line);

        EXPECT_NE(line.find("test"), std::string::npos);
        EXPECT_NE(output.find("test"), std::string::npos);

        logger.unset_display_specification_level_in_console(LogLevel::DEBUG);

        testing::internal::CaptureStdout();
        logger.debug("not_a_test");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_NE(line.find("not_a_test"), std::string::npos);
        EXPECT_EQ(output.find("not_a_test"), std::string::npos);

        testing::internal::CaptureStdout();
        logger.fatal("fatal_test");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_NE(line.find("fatal_test"), std::string::npos);
        EXPECT_NE(output.find("fatal_test"), std::string::npos);

        file.close();
        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }
    TEST(Logging, test_each_log_function)
    {
        Logger logger;
        FileAndFolderHandler ff_handler;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");

        testing::internal::CaptureStdout();
        logger.debug("This is a debug message");
        std::string output = testing::internal::GetCapturedStdout();

        std::fstream file("logs/" + filename, std::ios::in);
        std::string line;
        std::getline(file, line);

        EXPECT_NE(line.find("[DEBUG]"), std::string::npos);
        EXPECT_NE(output.find("[DEBUG]"), std::string::npos);

        testing::internal::CaptureStdout();
        logger.info("This is an info message");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_NE(line.find("[INFO]"), std::string::npos);
        EXPECT_NE(output.find("[INFO]"), std::string::npos);

        testing::internal::CaptureStdout();
        logger.warn("This is a warning message");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_NE(line.find("[WARNING]"), std::string::npos);
        EXPECT_NE(output.find("[WARNING]"), std::string::npos);

        testing::internal::CaptureStdout();
        logger.error("This is an error message");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_NE(line.find("[ERROR]"), std::string::npos);
        EXPECT_NE(output.find("[ERROR]"), std::string::npos);

        testing::internal::CaptureStdout();
        logger.fatal("This is a fatal message");
        output = testing::internal::GetCapturedStdout();
        std::getline(file, line);

        EXPECT_NE(line.find("[FATAL]"), std::string::npos);
        EXPECT_NE(output.find("[FATAL]"), std::string::npos);

        file.close();
        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }
}