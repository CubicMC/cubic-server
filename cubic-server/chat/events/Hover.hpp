#ifndef CHAT_EVENT_HOVER_HPP
#define CHAT_EVENT_HOVER_HPP

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

namespace chat::message::event {
class OnHover {
public:
    OnHover() = default;
    virtual ~OnHover() = default;

    virtual nlohmann::json toJson() const = 0;

    static std::shared_ptr<OnHover> deserialize(const std::string &json);
    static std::shared_ptr<OnHover> fromJson(const nlohmann::json &json);
};
} // namespace chat::message::event

#endif // CHAT_EVENT_HOVER_HPP
