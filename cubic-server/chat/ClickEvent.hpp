#ifndef CHAT_CLICKEVENT_HPP
#define CHAT_CLICKEVENT_HPP

#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

namespace chat::message {
class ClickEvent {
public:
    enum class Action : int32_t {
        OpenURL = 0,
        OpenFile = 1,
        RunCommand = 2,
        SuggestCommand = 3,
        ChangePage = 4,
        CopyToClipboard = 5,
    };

private:
    ClickEvent() = default;

public:
    ClickEvent(Action action, const std::string &value):
        action(action),
        value(value)
    {
    }
    nlohmann::json toJson() const;

    static ClickEvent deserialize(const std::string &json);
    static ClickEvent fromJson(const nlohmann::json &json);

private:
    Action action;
    std::string value;
};

} // namespace chat::message

#endif // CHAT_CLICKEVENT_HPP
