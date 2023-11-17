#ifndef LOGGING_MAIN_HPP
#define LOGGING_MAIN_HPP

#include "Registry.hpp"
#include "formating.hpp"

namespace logging {

constexpr spdlog::string_view_t LEVEL_NAMES[] = SPDLOG_LEVEL_NAMES;

#define LTRACE(...)                                                                        \
    do {                                                                                   \
        logging::instance().threadDefaultLogger()->log(spdlog::level::trace, __VA_ARGS__); \
    } while (false)
#define LDEBUG(...)                                                                        \
    do {                                                                                   \
        logging::instance().threadDefaultLogger()->log(spdlog::level::debug, __VA_ARGS__); \
    } while (false)
#define LINFO(...)                                                                        \
    do {                                                                                  \
        logging::instance().threadDefaultLogger()->log(spdlog::level::info, __VA_ARGS__); \
    } while (false)
#define LWARN(...)                                                                        \
    do {                                                                                  \
        logging::instance().threadDefaultLogger()->log(spdlog::level::warn, __VA_ARGS__); \
    } while (false)
#define LERROR(...)                                                                      \
    do {                                                                                 \
        logging::instance().threadDefaultLogger()->log(spdlog::level::err, __VA_ARGS__); \
    } while (false)
#define LFATAL(...)                                                                           \
    do {                                                                                      \
        logging::instance().threadDefaultLogger()->log(spdlog::level::critical, __VA_ARGS__); \
    } while (false)

#ifdef DEBUG_NETWORK

#define N_LTRACE(...)                                                               \
    do {                                                                            \
        logging::instance().get("network")->log(spdlog::level::trace, __VA_ARGS__); \
    } while (false)
#define N_LDEBUG(...)                                                               \
    do {                                                                            \
        logging::instance().get("network")->log(spdlog::level::debug, __VA_ARGS__); \
    } while (false)
#define N_LINFO(...)                                                               \
    do {                                                                           \
        logging::instance().get("network")->log(spdlog::level::info, __VA_ARGS__); \
    } while (false)
#define N_LWARN(...)                                                               \
    do {                                                                           \
        logging::instance().get("network")->log(spdlog::level::warn, __VA_ARGS__); \
    } while (false)
#define N_LERROR(...)                                                             \
    do {                                                                          \
        logging::instance().get("network")->log(spdlog::level::err, __VA_ARGS__); \
    } while (false)
#define N_LFATAL(...)                                                                  \
    do {                                                                               \
        logging::instance().get("network")->log(spdlog::level::critical, __VA_ARGS__); \
    } while (false)

#else

#define N_LTRACE(...)
#define N_LDEBUG(...)
#define N_LINFO(...)
#define N_LWARN(...)
#define N_LERROR(...)
#define N_LFATAL(...)

#endif

inline Registry &instance() noexcept { return Registry::instance(); }

/**
 * @brief Convert string to a LogLevel @see Registry::LogLevel
 *
 * @param str
 * @return Registry::LogLevel
 */
inline Registry::LogLevel stringToLevel(const std::string_view &str) noexcept { return static_cast<Registry::LogLevel>(spdlog::level::from_str(str.data())); }

/**
 * @brief Register a logger
 *
 * @param logger
 * @return std::shared_ptr<Registry::Logger>
 */
inline std::shared_ptr<Registry::Logger> registerLogger(std::shared_ptr<Registry::Logger> logger) { return instance().registerLogger(logger); }

/**
 * @brief Get the default logger
 *
 * @return std::shared_ptr<Registry::Logger>
 */
inline std::shared_ptr<Registry::Logger> defaultLogger() { return instance().defaultLogger(); }

/**
 * @brief Get the thread default logger, if no logger is set, return the default logger
 *
 * @return std::shared_ptr<Registry::Logger>
 */
inline std::shared_ptr<Registry::Logger> threadDefaultLogger() { return instance().threadDefaultLogger(); }

/**
 * @brief Get the logger with the given name
 *
 * @param name
 * @return std::shared_ptr<Registry::Logger>
 */
inline std::shared_ptr<Registry::Logger> get(const std::string &name) { return instance().get(name); }

/**
 * @brief Remove the logger with the given name
 *
 * @param name
 */
inline void unregisterLogger(const std::string &name) { instance().unregisterLogger(name); }

/**
 * @brief Set all loggers to the given level
 *
 * @param level
 */
inline void setLevel(Registry::LogLevel level) { instance().setLevel(level); }

/**
 * @brief Register a logger with the given name
 *
 * @tparam L
 * @param name
 * @return std::shared_ptr<Registry::Logger>
 */
template<isBaseOf<Registry::Logger> L = Registry::Logger>
inline std::shared_ptr<Registry::Logger> registerLogger(const std::string_view &name)
{
    return instance().registerLogger<L>(std::string(name));
}

/**
 * @brief Get a string representation of the given LogLevel @see Registry::LogLevel
 *
 * @param l
 * @return std::string_view
 */
inline std::string_view levelToString(spdlog::level::level_enum l) noexcept
{
    auto &str = spdlog::level::to_string_view(l);
    return std::string_view(str.begin(), str.end());
}

} // namespace logging

#endif // LOGGING_MAIN_HPP
