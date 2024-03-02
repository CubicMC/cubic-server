#include "Registry.hpp"

#include <algorithm>
#include <iostream>

#include <memory>
#include <mutex>
#include <shared_mutex>
#include <spdlog/spdlog.h>
#include <string>

#include <spdlog/cfg/env.h>
#include <spdlog/common.h>
#include <spdlog/details/registry.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Sinks.hpp"

namespace logging {

Registry::Registry()
{
    spdlog::file_event_handlers handlers;
    handlers.before_close = [](UNUSED const spdlog::filename_t &filename, UNUSED std::FILE *file_stream) {
        // TODO: compress file
    };

    _sinks.emplace_back(std::make_shared<StoreLogMessage>());
    _sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    _sinks.emplace_back(std::make_shared<spdlog::sinks::daily_file_format_sink_mt>("logs/cubic-server.log", 0, 0, false, 0, handlers));
    _sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/latest.log", true));

    auto console = this->registerLogger("main");

#ifdef DEBUG_NETWORK
    auto network = this->registerLogger("network");
#endif

    spdlog::set_default_logger(console);

#ifdef NDEBUG
    spdlog::set_level(spdlog::level::info);
#else
    spdlog::set_level(spdlog::level::debug);
#endif
    spdlog::cfg::load_env_levels();
}

Registry &Registry::instance()
{
    static Registry instance;
    return instance;
}

const std::queue<Registry::Message> &Registry::getMessages()
{
    if (auto sink = dynamic_pointer_cast<StoreLogMessage>(defaultLogger()->sinks().at(0)))
        return sink->messages();
    throw std::runtime_error("Logger not initialized");
}

std::shared_ptr<Registry::Logger> Registry::registerLogger(std::shared_ptr<Logger> logger)
{
    std::unique_lock lock(_loggersMutex);
    if (_loggers.contains(logger->name()))
        throw std::runtime_error("Logger already registered");

    _loggers.emplace(logger->name(), logger);

    logger->set_error_handler([](const std::string_view &msg) {
        spdlog::error("*** LOGGER ERROR ***: {}", msg);
    });

    spdlog::details::registry::instance().initialize_logger(logger);
    return logger;
}

void Registry::unregisterLogger(const std::string_view &name)
{
    {
        std::shared_lock _(_loggersMutex);
        if (!_loggers.contains(std::string(name)))
            return;
    }
    std::unique_lock lock1(_loggersMutex, std::defer_lock);
    std::unique_lock lock2(_threadsMutex, std::defer_lock);

    std::lock(lock1, lock2);

    _loggers.erase(std::string(name));

    std::erase_if(_threadLoggers, [&name](const auto &pair) {
        return pair.second == name;
    });
    spdlog::details::registry::instance().drop(std::string(name));
}

std::shared_ptr<Registry::Logger> Registry::defaultLogger() { return spdlog::default_logger(); }

std::shared_ptr<Registry::Logger> Registry::threadDefaultLogger()
{
    std::shared_lock _(_threadsMutex);
    if (!_threadLoggers.contains(std::this_thread::get_id()))
        return defaultLogger();
    return get(_threadLoggers.at(std::this_thread::get_id()));
}

std::shared_ptr<Registry::Logger> Registry::get(const std::string_view &name)
{
    std::shared_lock _(_loggersMutex);
    if (!_loggers.contains(std::string(name)))
        return nullptr;

    return _loggers.at(std::string(name));
}

void Registry::setThreadDefaultLogger(const std::string_view &name)
{
    std::unique_lock lock(_threadsMutex);
    if (_threadLoggers.contains(std::this_thread::get_id()))
        _threadLoggers.erase(std::this_thread::get_id());
    _threadLoggers.emplace(std::this_thread::get_id(), name);
}

void Registry::removeThreadDefaultLogger()
{
    std::unique_lock lock(_threadsMutex);
    if (_threadLoggers.contains(std::this_thread::get_id()))
        _threadLoggers.erase(std::this_thread::get_id());
}

void Registry::setLevel(LogLevel level) { spdlog::set_level(static_cast<spdlog::level::level_enum>(level)); }

} // namespace logging
