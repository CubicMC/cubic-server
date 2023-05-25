#ifndef LOGGING_REGISTRY_HPP
#define LOGGING_REGISTRY_HPP

#include "concept.hpp"
#include "options.hpp"
#include <queue>
#include <shared_mutex>
#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <thread>

namespace logging {
class Registry {
public:
    using LogLevel = spdlog::level::level_enum;
    using Logger = spdlog::logger;

public:
    static Registry &instance();

public:
    Registry();

    NODISCARD const std::queue<std::pair<LogLevel, std::string>> &getMessages();

    std::shared_ptr<Logger> defaultLogger();
    std::shared_ptr<Logger> threadDefaultLogger();
    std::shared_ptr<Logger> get(const std::string_view &name);

    template<isBaseOf<Logger> L = Logger>
    std::shared_ptr<Logger> registerLogger(const std::string_view &name);
    std::shared_ptr<Logger> registerLogger(std::shared_ptr<Logger> logger);

    void unregisterLogger(const std::string_view &name);

    // Threaded loggers
    void setThreadDefaultLogger(const std::string_view &name);
    void removeThreadDefaultLogger();

    void setLevel(LogLevel level);

private:
    std::shared_mutex _loggersMutex;
    std::shared_mutex _threadsMutex;

    std::vector<std::shared_ptr<spdlog::sinks::sink>> _sinks;

    std::unordered_map<std::string, std::shared_ptr<Logger>> _loggers;
    std::unordered_map<std::thread::id, std::string> _threadLoggers;
};

template<isBaseOf<Registry::Logger> L>
std::shared_ptr<Registry::Logger> Registry::registerLogger(const std::string_view &name)
{
    return registerLogger(std::make_shared<L>(std::string(name), _sinks.begin(), _sinks.end()));
}

} // namespace logging

#endif // LOGGING_REGISTRY_HPP
