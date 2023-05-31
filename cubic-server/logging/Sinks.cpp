#include "Sinks.hpp"

void logging::StoreLogMessage::sink_it_(const spdlog::details::log_msg &msg)
{
    spdlog::memory_buf_t formatted;
    spdlog::sinks::base_sink<std::mutex>::formatter_->format(msg, formatted);
    _messages.emplace(Registry::Message {msg.level, fmt::to_string(formatted)});
}

void logging::StoreLogMessage::flush_() { }
