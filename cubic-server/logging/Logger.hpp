#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <mutex>
#include <chrono>

#include "FileAndFolderHandler.hpp"

#define _GET_NTH_ARG(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, N, ...) N

#define _LOG0() __FILE__ << ":" << __LINE__ << " Log called without arguments !"
#define _LOG1(msg) msg
#define _LOG2(msg, ...) msg << _LOG1(__VA_ARGS__)
#define _LOG3(msg, ...) msg << _LOG2(__VA_ARGS__)
#define _LOG4(msg, ...) msg << _LOG3(__VA_ARGS__)
#define _LOG5(msg, ...) msg << _LOG4(__VA_ARGS__)
#define _LOG6(msg, ...) msg << _LOG5(__VA_ARGS__)
#define _LOG7(msg, ...) msg << _LOG6(__VA_ARGS__)
#define _LOG8(msg, ...) msg << _LOG7(__VA_ARGS__)
#define _LOG9(msg, ...) msg << _LOG8(__VA_ARGS__)

#define _LOGN(...) \
_GET_NTH_ARG( \
    ,##__VA_ARGS__, \
    _LOG9(__VA_ARGS__), \
    _LOG8(__VA_ARGS__), \
    _LOG7(__VA_ARGS__), \
    _LOG6(__VA_ARGS__), \
    _LOG5(__VA_ARGS__), \
    _LOG4(__VA_ARGS__), \
    _LOG3(__VA_ARGS__), \
    _LOG2(__VA_ARGS__), \
    _LOG1(__VA_ARGS__), \
    _LOG0(__VA_ARGS__), \
)

#define _LOG(type, ...) do { \
    std::stringstream __ss; \
    __ss << _LOGN(__VA_ARGS__); \
    ::logging::Logger::get_instance()->type(__ss.str()); \
} while (0)

#define LDEBUG(...) _LOG(debug, __VA_ARGS__)
#define LINFO(...) _LOG(info, __VA_ARGS__)
#define LWARN(...) _LOG(warn, __VA_ARGS__)
#define LERROR(...) _LOG(error, __VA_ARGS__)
#define LFATAL(...) _LOG(fatal, __VA_ARGS__)

namespace logging
{
    enum class LogLevel
    {
        NONE,
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
        std::time_t _time;
        int _millis;
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
        const std::unordered_map<LogLevel, std::string>& get_display_specification_level_in_console() const;

        const std::queue<LogMessage>& get_logs() const;
        const int get_log_buffer_size() const;
        void set_log_buffer_size(int size);

    private:
        // Private constructor to prevent multiple instances
        Logger();
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) = delete;

        std::string get_file_path() const;

        // Stream to the current log file
        std::fstream _file_stream;

        // Handler for files and folders
        FileAndFolderHandler _file_and_folder_handler;

        // Map of LogLevel and his associated string to display in the log file
        std::unordered_map<LogLevel, std::string> _specification_level_in_file;

        // Map of LogLevel and his associated string to display in the console
        std::unordered_map<LogLevel, std::string> _specification_level_in_console;

        void _log(LogLevel level, const std::string &message);

        // Buffer to store logs before the file is opened
        std::queue<LogMessage> _log_buffer;
        int _buffer_size;

        std::mutex _loggerMutex;
    };
}

#endif /* !LOGGER_HPP_ */
