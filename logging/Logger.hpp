#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
#include <unordered_map>
#include "FileAndFolderHandler.hpp"

#define LDEBUG(msg) _log->debug(msg)
#define LINFO(msg) _log->info(msg)
#define LWARNING(msg) _log->warning(msg)
#define LERROR(msg) _log->error(msg)
#define LFATAL(msg) _log->fatal(msg)

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
    const char *level_to_string(LogLevel &level);

    /**
     * @brief Handles logging in a file.
     */
    class Logger
    {
    public:
        static Logger *get_instance();

        ~Logger();;

        void debug(const std::string &msg);

        void info(const std::string &msg);

        void warn(const std::string &msg);

        void error(const std::string &msg);

        void fatal(const std::string &msg);

        void set_display_specification_level_in_file(LogLevel level);

        void unset_display_specification_level_in_file(LogLevel level);

        const std::unordered_map<LogLevel, std::string> &get_display_specification_level_in_file() const;

        void set_display_specification_level_in_console(LogLevel level);

        void unset_display_specification_level_in_console(LogLevel level);

        const std::unordered_map<LogLevel, std::string> &get_display_specification_level_in_console() const;

        std::string get_file_path() const;

        Logger(const Logger &) = delete;
        Logger(Logger &&) = delete;
        Logger &operator=(const Logger &) = delete;
        Logger &operator=(Logger &&) = delete;
    private:
        Logger();                                                                   /// Private constructor to prevent multiple instances

        std::fstream _file_stream;                                                  /// Stream to the current log file
        FileAndFolderHandler _file_and_folder_handler;                              /// Handler for files and folders

        std::unordered_map<LogLevel, std::string> _specification_level_in_file;     /// Map of LogLevel and his associated string to display in the log file
        std::unordered_map<LogLevel, std::string> _specification_level_in_console;  /// Map of LogLevel and his associated string to display in the console

        void _log(LogLevel level, const std::string &message);
    };
}

#endif /* !LOGGER_HPP_ */