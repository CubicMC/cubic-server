#include "Logger.hpp"
#include "TimeFormatter.hpp"
#include <iostream>
#include <array>

namespace logging
{
    /**
     * @brief Construct a new Logger:: Logger object
     */
    Logger::Logger()
    {
        this->_file_and_folder_handler.create_folder("logs");
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");
        for (int i = 1; this->_file_and_folder_handler.file_exist(filename); i++)
        {
            filename = TimeFormatter::get_time("YYYY-MM-DD-" + std::to_string(i) + ".log");
        }
        this->_file_and_folder_handler.create_file(filename);
        this->_file_stream.open(this->_file_and_folder_handler.get_file_path(), std::ios::app);
    }

    /**
     * @brief Destroy the Logger:: Logger object
     *
     * @note The file stream will be closed
     */
    Logger::~Logger()
    {
        this->_file_stream.close();
    }

    /**
     * @brief Write a message in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written in the log file with the current time
     */

    void Logger::log(LogLevel level, std::string message)
    {
        this->_file_stream << TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS.sss] ") << level_to_string(level) << message << std::endl;
        std::cout << TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS.sss] ") << level_to_string(level) << message << std::endl;
    }

    std::string level_to_string(LogLevel level)
    {
        switch (level) {
            case LogLevel::DEBUG:
                return "[DEBUG] ";
                break;
            case LogLevel::INFO:
                return "[INFO] ";
                break;
            case LogLevel::WARNING:
                return "[WARNING] ";
                break;
            case LogLevel::ERROR:
                return "[ERROR] ";
                break;
            case LogLevel::FATAL:
                return "[FATAL] ";
                break;
            default:
                return "[UNDEFINED] ";
                break;
        }
    }
}