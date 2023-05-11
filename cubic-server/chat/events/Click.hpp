#ifndef CHAT_CLICKEVENT_HPP
#define CHAT_CLICKEVENT_HPP

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

namespace chat::message::event {
class OnClick {
public:
    OnClick() = default;
    virtual ~OnClick() = default;

    virtual nlohmann::json toJson() const = 0;

    static std::shared_ptr<OnClick> deserialize(const std::string &json);
    static std::shared_ptr<OnClick> fromJson(const nlohmann::json &json);
};
} // namespace chat::message::event

#endif // CHAT_CLICKEVENT_HPP
