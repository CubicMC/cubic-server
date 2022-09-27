#include "Logger.hpp"
#include "TimeFormatter.hpp"
#include <iostream>
#include <algorithm>

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

        this->_specification_level_in_file = {LogLevel::DEBUG, LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR, LogLevel::FATAL};
        this->_specification_level_in_console = {LogLevel::DEBUG, LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR, LogLevel::FATAL};
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
    void Logger::_log(LogLevel level, std::string message)
    {
        if (std::find(this->_specification_level_in_file.begin(), this->_specification_level_in_file.end(), level) != this->_specification_level_in_file.end())
            this->_file_stream << TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS.sss] ") << level_to_string(level) << message << std::endl;

        if (std::find(this->_specification_level_in_console.begin(), this->_specification_level_in_console.end(), level) != this->_specification_level_in_console.end())
            std::cout << TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS.sss] ") << level_to_string(level) << message << std::endl;
    }

    /**
     * @brief Write a debug message in the console and in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written with the current time
     */
    void Logger::debug(std::string message)
    {
        this->_log(LogLevel::DEBUG, message);
    }

    /**
     * @brief Write an info message in the console and in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written with the current time
     */
    void Logger::info(std::string message)
    {
        this->_log(LogLevel::INFO, message);
    }

    /**
     * @brief Write a warning message in the console and in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written with the current time
     */
    void Logger::warn(std::string message)
    {
        this->_log(LogLevel::WARNING, message);
    }

    /**
     * @brief Write an error message in the console and in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written with the current time
     */
    void Logger::error(std::string message)
    {
        this->_log(LogLevel::ERROR, message);
    }

    /**
     * @brief Write a fatal message in the console and in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written with the current time
     */
    void Logger::fatal(std::string message)
    {
        this->_log(LogLevel::FATAL, message);
    }

    /**
     * @brief Set log levels to display in the console
     *
     * @param level LogLevel to display in the console
     */
    void Logger::set_display_specification_level_in_console(LogLevel level)
    {
        this->_specification_level_in_console.push_back(level);
    }

    /**
     * @brief Unset log levels to display in the console
     *
     * @param level LogLevel to not display in the console
     */
    void Logger::unset_display_specification_level_in_console(LogLevel level)
    {
        for (auto it = this->_specification_level_in_console.begin(); it != this->_specification_level_in_console.end(); it++)
        {
            if (*it == level)
            {
                this->_specification_level_in_console.erase(it);
            }
        }
    }

    /**
     * @brief Get the log display settings of the console
     *
     * @return std::vector<LogLevel> Log levels that are displayed in the console
     */
    std::vector<LogLevel> Logger::get_display_specification_level_in_console() const
    {
        return this->_specification_level_in_console;
    }

    /**
     * @brief Set log levels to display in the log file
     *
     * @param level LogLevel to display in the log file
     */
    void Logger::set_display_specification_level_in_file(LogLevel level)
    {
        this->_specification_level_in_file.push_back(level);
    }

    /**
     * @brief Unset log levels to display in the log file
     *
     * @param level LogLevel to not display in the log file
     */
    void Logger::unset_display_specification_level_in_file(LogLevel level)
    {
        for (auto it = this->_specification_level_in_file.begin(); it != this->_specification_level_in_file.end(); it++)
        {
            if (*it == level)
            {
                this->_specification_level_in_file.erase(it);
            }
        }
    }

    /**
     * @brief Get the log display settings of the log file
     *
     * @return std::vector<LogLevel> Log levels that are displayed in the log file
     */
    std::vector<LogLevel> Logger::get_display_specification_level_in_file() const
    {
        return this->_specification_level_in_file;
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