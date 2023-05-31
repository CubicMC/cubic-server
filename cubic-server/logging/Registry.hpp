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
    using Message = struct {
        LogLevel level;
        std::string message;
    };

public:
    static Registry &instance();

public:
    Registry();

    /**
     * @brief Get the all messages object
     *
     * @return NODISCARD const&
     */
    NODISCARD const std::queue<Message> &getMessages();

    /**
     * @brief Get the default logger
     *
     * @return std::shared_ptr<Logger>
     */
    std::shared_ptr<Logger> defaultLogger();

    /**
     * @brief Get the thread default logger, if no logger is set, return the default logger
     *
     * @return std::shared_ptr<Logger>
     */
    std::shared_ptr<Logger> threadDefaultLogger();

    /**
     * @brief Get the logger with the given name
     *
     * @param name
     * @return std::shared_ptr<Logger>
     */
    std::shared_ptr<Logger> get(const std::string_view &name);

    /**
     * @brief Register a logger with the given name
     *
     * @tparam L
     * @param name
     * @return std::shared_ptr<Logger>
     */
    template<isBaseOf<Logger> L = Logger>
    std::shared_ptr<Logger> registerLogger(const std::string_view &name);

    /**
     * @brief Register a logger
     *
     * @param logger
     * @return std::shared_ptr<Logger>
     */
    std::shared_ptr<Logger> registerLogger(std::shared_ptr<Logger> logger);

    /**
     * @brief Remove the logger with the given name
     *
     * @param name
     */
    void unregisterLogger(const std::string_view &name);

    /**
     * @brief Set the Thread Default Logger by name
     *
     * @param name
     */
    void setThreadDefaultLogger(const std::string_view &name);

    /**
     * @brief Remove the Thread Default Logger
     */
    void removeThreadDefaultLogger();

    /**
     * @brief Set all loggers to the given level
     *
     * @param level
     */
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
