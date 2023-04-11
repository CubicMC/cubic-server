#ifndef CHAT_HOVEREVENT_HPP
#define CHAT_HOVEREVENT_HPP

#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

namespace chat::message {
class HoverEvent {
public:
    enum class Action : int32_t {
        ShowText = 0,
        ShowItem = 1,
        ShowEntity = 2,
    };

private:
    HoverEvent() = default;

public:
    HoverEvent(Action action, const std::string &value):
        action(action),
        value(value) {};
    nlohmann::json toJson() const;

    static HoverEvent deserialize(const std::string &json);
    static HoverEvent fromJson(const nlohmann::json &json);

private:
    Action action;
    std::string value;
};

} // namespace chat::message

#endif // CHAT_HOVEREVENT_HPP
