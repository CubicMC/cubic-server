#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <chrono>

#include "FileAndFolderHandler.hpp"

namespace logging
{
    enum class LogLevel
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    class LogMessage
    {
    public:
            LogMessage(LogLevel level, std::string message);

            const LogLevel& get_level() const;
            const std::string& get_message() const;
            const std::time_t& get_time() const;
            const int get_millis() const;

    private:
        const LogLevel _level;
        const std::string _message;
        const std::time_t _time;
        const int _millis;
    };
    std::ostream& operator<<(std::ostream& os, const LogMessage& log);

    /**
     * @brief function to transform a LogLevel to a string
     *
     * @param level LogLevel to transform
     *
     * @return std::string the string corresponding to the LogLevel
     */
    const char* level_to_string(const LogLevel& level);

    /**
     * @brief Handles logging in a file.
     */
    class Logger
    {
        public:
            static Logger *get_instance();
            ~Logger();

            void debug(std::string message);
            void debug(std::string& message);

            void info(std::string message);
            void info(std::string& message);

            void warn(std::string message);
            void warn(std::string& message);

            void error(std::string message);
            void error(std::string& message);

            void fatal(std::string message);
            void fatal(std::string& message);

            void set_display_specification_level_in_file(LogLevel level);
            void unset_display_specification_level_in_file(LogLevel level);
            const std::unordered_map<LogLevel, std::string>& get_display_specification_level_in_file() const;

            void set_display_specification_level_in_console(LogLevel level);
            void unset_display_specification_level_in_console(LogLevel level);
            const std::unordered_map<LogLevel, std::string>& get_display_specification_level_in_console() const;

            std::string get_file_path() const;

            const std::queue<LogMessage>& get_logs() const;
            const int get_log_buffer_size() const;
            void set_log_buffer_size(int size);

        private:
            Logger();                                                                   /// Private constructor to prevent multiple instances
            Logger(const Logger&) = delete;
            Logger& operator=(const Logger&) = delete;
            Logger(Logger&&) = delete;
            Logger& operator=(Logger&&) = delete;


            std::fstream _file_stream;                                                  /// Stream to the current log file
            FileAndFolderHandler _file_and_folder_handler;                              /// Handler for files and folders

            std::unordered_map<LogLevel, std::string> _specification_level_in_file;     /// Map of LogLevel and his associated string to display in the log file
            std::unordered_map<LogLevel, std::string> _specification_level_in_console;  /// Map of LogLevel and his associated string to display in the console

            void _log(LogLevel level, std::string& message);

            std::queue<LogMessage> _log_buffer;                                         /// Buffer to store logs before the file is opened
            int _buffer_size;                                                           /// Size of the buffer
    };
}

#endif /* !LOGGER_HPP_ */