#ifndef CUBICSERVER_LOGGING_LOGGER_HPP
#define CUBICSERVER_LOGGING_LOGGER_HPP

#include <mutex>
#include <unordered_map>
#include <queue>

#ifndef TESTING
    #include <spdlog/spdlog.h>
    #include <spdlog/common.h>
    #include <spdlog/sinks/stdout_color_sinks.h>
    #include <spdlog/sinks/base_sink.h>
    #include "formating.hpp"
#endif

namespace logging {
#ifndef TESTING

using LogLevel = spdlog::level::level_enum;

class Logger {
public:
    Logger();

private:
    static Logger *instance();

    void initLogger();
    NODISCARD const std::queue<std::pair<LogLevel, std::string>> &getMessages();
    void toggle(LogLevel level);
    void enable(LogLevel level);
    void disable(LogLevel level);
    void registerLogger(const std::string &name);
    void unregisterLogger(const std::string &name);

private:
    std::mutex _mutex;
    std::unordered_map<std::thread::id, std::shared_ptr<spdlog::logger>> _loggers;
};

template<typename Mutex>
class StoreLogMessage : public spdlog::sinks::base_sink<Mutex> {
public:
    using level_enum = LogLevel;

public:
    NODISCARD constexpr inline const std::queue<std::pair<level_enum, std::string>> &messages() const noexcept { return _messages; }

protected:
    void sink_it_(const spdlog::details::log_msg &msg) override
    {
        spdlog::memory_buf_t formatted;
        spdlog::sinks::base_sink<Mutex>::formatter_->format(msg, formatted);
        _messages.emplace(msg.level, fmt::to_string(formatted));
    }

    void flush_() override {}

private:
    std::queue<std::pair<level_enum, std::string>> _messages;
};

class EnablingLogLevelSink : public spdlog::sinks::stdout_color_sink_mt {
public:
    using level_enum = LogLevel;

public:
    EnablingLogLevelSink(spdlog::color_mode mode = spdlog::color_mode::automatic):
        spdlog::sinks::stdout_color_sink_mt(mode)
    {
        for (int level = level_enum::trace; level < level_enum::off; level += 1)
            _enabled.emplace(static_cast<level_enum>(level), true);
    }

    void log(const spdlog::details::log_msg &msg) override
    {
        if (_enabled[msg.level])
            spdlog::sinks::stdout_color_sink_mt::log(msg);
    }

    void toggle(level_enum level) { _enabled[level] = !_enabled[level]; }
    void enable(level_enum level) { _enabled[level] = true; }
    void disable(level_enum level) { _enabled[level] = false; }

private:
    std::unordered_map<level_enum, bool> _enabled;
};

using StoreLogMessage_mt = StoreLogMessage<std::mutex>;
using StoreLogMessage_st = StoreLogMessage<spdlog::details::null_mutex>;

inline std::string levelToString(spdlog::level::level_enum l) noexcept
{
    auto &&str = spdlog::level::to_string_view(l);
    return std::string(str.begin(), str.end());
}

void initLogger();
NODISCARD const std::queue<std::pair<LogLevel, std::string>> &getMessages();
void toggle(LogLevel level);
void enable(LogLevel level);
void disable(LogLevel level);
void registerLogger(const std::string &name);
void unregisterLogger(const std::string &name);

#endif

} // namespace logging

#define LTRACE(...) spdlog::default_logger()->log(spdlog::level::trace, __VA_ARGS__)
#define LDEBUG(...) spdlog::default_logger()->log(spdlog::level::debug, __VA_ARGS__)
#define LINFO(...) spdlog::default_logger()->log(spdlog::level::info, __VA_ARGS__)
#define LWARN(...) spdlog::default_logger()->log(spdlog::level::warn, __VA_ARGS__)
#define LERROR(...) spdlog::default_logger()->log(spdlog::level::err, __VA_ARGS__)
#define LFATAL(...) spdlog::default_logger()->log(spdlog::level::critical, __VA_ARGS__)

#ifdef DEBUG_NETWORK
#define N_LTRACE(...) spdlog::get("network")->log(spdlog::level::trace, __VA_ARGS__)
#define N_LDEBUG(...) spdlog::get("network")->log(spdlog::level::debug, __VA_ARGS__)
#define N_LINFO(...) spdlog::get("network")->log(spdlog::level::info, __VA_ARGS__)
#define N_LWARN(...) spdlog::get("network")->log(spdlog::level::warn, __VA_ARGS__)
#define N_LERROR(...) spdlog::get("network")->log(spdlog::level::err, __VA_ARGS__)
#define N_LFATAL(...) spdlog::get("network")->log(spdlog::level::critical, __VA_ARGS__)
#else
#define N_LTRACE(...)
#define N_LDEBUG(...)
#define N_LINFO(...)
#define N_LWARN(...)
#define N_LERROR(...)
#define N_LFATAL(...)
#endif

#endif // CUBICSERVER_LOGGING_LOGGER_HPP
