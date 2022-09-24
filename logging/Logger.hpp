#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
#include <vector>
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
    std::string level_to_string(LogLevel level);

    /**
     * @brief Handles logging in a file.
     */
    class Logger
    {
        public:
            Logger();
            ~Logger();

            void log(LogLevel level, std::string message);

            void set_display_specification_level_in_file(LogLevel level);
            void unset_display_specification_level_in_file(LogLevel level);
            std::vector<LogLevel> get_display_specification_level_in_file() const;

            void set_display_specification_level_in_console(LogLevel level);
            void unset_display_specification_level_in_console(LogLevel level);
            std::vector<LogLevel> get_display_specification_level_in_console() const;

        private:
            std::fstream _file_stream;                              /// Stream to the current log file
            FileAndFolderHandler _file_and_folder_handler;          /// Handler for files and folders

            std::vector<LogLevel> _specification_level_in_file;     /// Vector of LogLevel to display in the log file
            std::vector<LogLevel> _specification_level_in_console;  /// Vector of LogLevel to display in the console
    };
}

#endif /* !LOGGER_HPP_ */