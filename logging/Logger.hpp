#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
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

        private:
            std::fstream _file_stream;                      /// Stream to the current log file
            FileAndFolderHandler _file_and_folder_handler;  /// Handler for files and folders
    };
}

#endif /* !LOGGER_HPP_ */