#ifndef LOGGER_SINKS_HPP
#define LOGGER_SINKS_HPP

#include <queue>

#include "Registry.hpp"
#include "formating.hpp"
#include <spdlog/common.h>
#include <spdlog/sinks/base_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace logging {

class StoreLogMessage : public spdlog::sinks::base_sink<std::mutex> {
public:
    using level_enum = Registry::LogLevel;

public:
    NODISCARD constexpr inline const std::queue<Registry::Message> &messages() const noexcept { return _messages; }

protected:
    void sink_it_(const spdlog::details::log_msg &msg) override;
    void flush_() override;

private:
    std::queue<Registry::Message> _messages;
};

} // namespace logging

#endif // LOGGER_SINKS_HPP
