#include "Logger.hpp"

#include <algorithm>
#include <iostream>

#include <memory>
#include <spdlog/spdlog.h>

#include "spdlog/common.h"
#include "spdlog/details/registry.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace logging {

const std::queue<std::pair<LogLevel, std::string>> &getMessages()
{
    if (auto sink = dynamic_pointer_cast<StoreLogMessage_mt>(spdlog::default_logger()->sinks()[0]))
        return sink->messages();
    throw std::runtime_error("Logger not initialized");
}

void toggle(LogLevel level)
{
    if (auto sink = dynamic_pointer_cast<EnablingLogLevelSink>(spdlog::default_logger()->sinks()[1]))
        sink->toggle(level);
}

void enable(LogLevel level)
{
    if (auto sink = dynamic_pointer_cast<EnablingLogLevelSink>(spdlog::default_logger()->sinks()[1]))
        sink->enable(level);
}

void disable(LogLevel level)
{
    if (auto sink = dynamic_pointer_cast<EnablingLogLevelSink>(spdlog::default_logger()->sinks()[1]))
        sink->disable(level);
}

void registerLogger(const std::string &name)
{
    const auto &sinks = spdlog::default_logger()->sinks();
    auto logger = std::make_shared<spdlog::logger>(name, sinks.begin(), sinks.end());

    spdlog::details::registry::instance().initialize_logger(logger);
}

void unregisterLogger(const std::string &name)
{
    spdlog::details::registry::instance().drop(name);
}

void initLogger()
{
    std::vector<std::shared_ptr<spdlog::sinks::sink>> sinks;
    sinks.emplace_back(std::make_shared<StoreLogMessage_mt>());
    sinks.emplace_back(std::make_shared<EnablingLogLevelSink>());
    sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/cubic-server.log"));
    sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/latest.log", true));

    auto console = std::make_shared<spdlog::logger>("main", sinks.begin(), sinks.end());
    spdlog::details::registry::instance().initialize_logger(console);

#ifdef DEBUG_NETWORK
    auto network = std::make_shared<spdlog::logger>("network", sinks.begin(), sinks.end());
    spdlog::details::registry::instance().initialize_logger(network);
#endif

    spdlog::set_error_handler([](const std::string &msg) {
        spdlog::error("*** LOGGER ERROR ***: {}", msg);
    });

    spdlog::set_default_logger(console);

#ifdef NDEBUG
    spdlog::set_level(spdlog::level::info);
#else
    spdlog::set_level(spdlog::level::trace);
#endif
}
}
