#include <gtest/gtest.h>

#include "Logger.hpp"
#include "FileAndFolderHandler.hpp"
#include "TimeFormatter.hpp"

namespace logging
{
    TEST(Logging, log)
    {
        Logger logger;
        FileAndFolderHandler ff_handler;
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");

        EXPECT_TRUE(ff_handler.folder_exist("logs"));
        EXPECT_TRUE(ff_handler.file_exist("logs/" + filename));

        logger.log(LogLevel::DEBUG, "test");
        std::fstream file("logs/" + filename, std::ios::in);
        std::string line;
        std::getline(file, line);

        EXPECT_NE(line.find(TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS")), std::string::npos);
        EXPECT_NE(line.find("[DEBUG]"), std::string::npos);
        EXPECT_NE(line.find("test"), std::string::npos);

        file.close();
        filename = "logs/" + filename;
        std::remove(filename.c_str());
        rmdir("logs");
    }
}