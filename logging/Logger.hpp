#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
#include <unordered_map>
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

    /**
     * @brief function to transform a LogLevel to a string
     *
     * @param level LogLevel to transform
     *
     * @return std::string the string corresponding to the LogLevel
     */
    const char* level_to_string(LogLevel& level);

    /**
     * @brief Handles logging in a file.
     */
    class Logger
    {
        public:
            Logger();
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

        private:
            std::fstream _file_stream;                              /// Stream to the current log file
            FileAndFolderHandler _file_and_folder_handler;          /// Handler for files and folders

            std::unordered_map<LogLevel, std::string> _specification_level_in_file;     /// Map of LogLevel and his associated string to display in the log file
            std::unordered_map<LogLevel, std::string> _specification_level_in_console;  /// Map of LogLevel and his associated string to display in the console

            void _log(LogLevel level, std::string& message);
    };
}

#endif /* !LOGGER_HPP_ */