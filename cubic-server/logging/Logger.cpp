#include "Logger.hpp"
#include "TimeFormatter.hpp"
#include <iostream>
#include <algorithm>

namespace logging
{

    LogMessage::LogMessage(LogLevel level, std::string message)
        : _level(level), _message(message), _time(std::time(nullptr)), _millis(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - (_time * 1000))
    {
    }

    const LogLevel& LogMessage::get_level() const
    {
        return _level;
    }

    const std::string& LogMessage::get_message() const
    {
        return _message;
    }

    const std::time_t& LogMessage::get_time() const
    {
        return _time;
    }

    const int LogMessage::get_millis() const
    {
        return _millis;
    }

    std::ostream& operator<<(std::ostream& os, const LogMessage& log)
    {
        os << TimeFormatter::get_time("[YYYY/MM/DD HH:mm:SS:sss] ", log.get_time(), log.get_millis()) << level_to_string(log.get_level()) << log.get_message();
        return os;
    }

    /**
     * @brief create an instance of the Logger class if it doesn't exist and return it
     *
     * @return Logger& the instance of the Logger class as a reference
     */
    Logger *Logger::get_instance()
    {
        static auto* instance = new Logger();
        return instance;
    }

    /**
     * @brief Construct a new Logger:: Logger object
     */
    Logger::Logger()
    {
        this->_file_and_folder_handler.create_folder("logs");
        std::string filename = TimeFormatter::get_time("YYYY-MM-DD-1.log");

        for (int i = 1; this->_file_and_folder_handler.file_exist("logs/" + filename); i++)
            filename = TimeFormatter::get_time("YYYY-MM-DD-" + std::to_string(i) + ".log");

        this->_file_and_folder_handler.create_file(filename);
        this->_file_stream.open(this->_file_and_folder_handler.get_file_path(), std::ios::app);

        this->_specification_level_in_file = {
                {LogLevel::DEBUG, "[DEBUG] "},
                {LogLevel::INFO, "[INFO] "},
                {LogLevel::WARNING, "[WARNING] "},
                {LogLevel::ERROR, "[ERROR] "},
                {LogLevel::FATAL, "[FATAL] "}
        };
        this->_specification_level_in_console = {
                {LogLevel::DEBUG, "[DEBUG] "},
                {LogLevel::INFO, "[INFO] "},
                {LogLevel::WARNING, "[WARNING] "},
                {LogLevel::ERROR, "[ERROR] "},
                {LogLevel::FATAL, "[FATAL] "}
        };
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
    void Logger::_log(LogLevel level, const std::string& message)
    {
        _loggerMutex.lock();
        LogMessage log(level, message);
        this->_log_buffer.push(log);
        if (this->_log_buffer.size() > this->_buffer_size)
            this->_log_buffer.pop();

        if (this->_specification_level_in_file.find(level) != this->_specification_level_in_file.end())
            this->_file_stream << log << std::endl;

        if (this->_specification_level_in_console.find(level) != this->_specification_level_in_console.end())
            std::cout << log << std::endl;
        _loggerMutex.unlock();
    }

    /**
     * @brief Write a debug message in the console and in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written with the current time
     */
    void Logger::debug(const std::string &message)
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
    void Logger::info(const std::string &message)
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
    void Logger::warn(const std::string &message)
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
    void Logger::error(const std::string &message)
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
    void Logger::fatal(const std::string &message)
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
        this->_specification_level_in_console.insert({level, level_to_string(level)});
    }

    /**
     * @brief Unset log levels to display in the console
     *
     * @param level LogLevel to not display in the console
     */
    void Logger::unset_display_specification_level_in_console(LogLevel level)
    {
        this->_specification_level_in_console.erase(level);
    }

    /**
     * @brief Get the log display settings of the console
     *
     * @return std::vector<LogLevel> Log levels that are displayed in the console
     */
    const std::unordered_map<LogLevel, std::string>& Logger::get_display_specification_level_in_console() const
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
        this->_specification_level_in_file.insert({level, level_to_string(level)});
    }

    /**
     * @brief Unset log levels to display in the log file
     *
     * @param level LogLevel to not display in the log file
     */
    void Logger::unset_display_specification_level_in_file(LogLevel level)
    {
        this->_specification_level_in_file.erase(level);
    }

    /**
     * @brief Get the log display settings of the log file
     *
     * @return std::vector<LogLevel> Log levels that are displayed in the log file
     */
    const std::unordered_map<LogLevel, std::string>& Logger::get_display_specification_level_in_file() const
    {
        return this->_specification_level_in_file;
    }

    std::string Logger::get_file_path() const
    {
        return this->_file_and_folder_handler.get_file_path();
    }

    const std::queue<LogMessage>& Logger::get_logs() const
    {
        return this->_log_buffer;
    }

    const int Logger::get_log_buffer_size() const
    {
        return this->_buffer_size;
    }

    void Logger::set_log_buffer_size(int size)
    {
        this->_buffer_size = size;
    }

    const char* level_to_string(const LogLevel& level)
    {
        switch (level) {
            case LogLevel::DEBUG:
                return "[DEBUG] ";
            case LogLevel::INFO:
                return "[INFO] ";
            case LogLevel::WARNING:
                return "[WARNING] ";
            case LogLevel::ERROR:
                return "[ERROR] ";
            case LogLevel::FATAL:
                return "[FATAL] ";
            default:
                return "[UNDEFINED] ";
        }
    }
}
