#ifndef LOGGING_FORMATING_HPP
#define LOGGING_FORMATING_HPP

#include "concept.hpp"
#include "configuration/Value.hpp"
#include "types.hpp"
#include <spdlog/fmt/fmt.h>
#include <type_traits>

template<isEnum T>
struct fmt::formatter<T> : fmt::formatter<std::string> {
    auto format(T e, format_context &ctx) -> decltype(ctx.out()) { return fmt::format_to(ctx.out(), "{}", (std::underlying_type_t<T>) e); }
};

template<>
struct fmt::formatter<configuration::Value> : fmt::formatter<std::string> {
    auto format(const configuration::Value &conf, format_context &ctx) -> decltype(ctx.out())
    {
        if (conf.isArray())
            return fmt::format_to(ctx.out(), "[{}]", fmt::join(conf.values(), ", "));
        return fmt::format_to(ctx.out(), "{}", conf.value());
    }
};

template<>
struct fmt::formatter<Position> : fmt::formatter<std::string> {
    auto format(const Position &conf, format_context &ctx) -> decltype(ctx.out()) { return fmt::format_to(ctx.out(), "({}, {}, {})", conf.x, conf.y, conf.z); }
};

template<>
struct fmt::formatter<Position2D> : fmt::formatter<std::string> {
    auto format(const Position2D &conf, format_context &ctx) -> decltype(ctx.out()) { return fmt::format_to(ctx.out(), "({}, {})", conf.x, conf.z); }
};

#endif // LOGGING_FORMATING_HPP
