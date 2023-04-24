#ifndef CHAT_EVENTS_HOVER_TEXT_HPP
#define CHAT_EVENTS_HOVER_TEXT_HPP

#include "chat/SimpleMessage.hpp"
#include "chat/events/Hover.hpp"

namespace chat::message::event {
/**
 * @brief Show text in the hover event
 *
 * This is a @see `SimpleMessage` because there can't be events on an event message
 *
 */
class TextHover : public OnHover {
public:
    TextHover(const chat::SimpleMessage &message = "");
    TextHover(const std::vector<chat::SimpleMessage> &messages);
    TextHover(const std::initializer_list<chat::SimpleMessage> &messages);
    template<typename... Args>
    TextHover(const chat::SimpleMessage &message, const Args &...args)
    {
        messages.push_back(message);
        addMessage(std::forward<Args>(args)...);
    }

public:
    TextHover &addMessage(const chat::SimpleMessage &message);

    template<typename... Args>
    TextHover &addMessage(const chat::SimpleMessage &message, const Args &...args)
    {
        messages.push_back(message);
        return addMessage(std::forward<Args>(args)...);
    }

    nlohmann::json toJson() const override;

    static std::shared_ptr<TextHover> fromJson(const nlohmann::json &json);

private:
    std::vector<chat::SimpleMessage> messages;
};
} // namespace chat::message

#endif // CHAT_EVENTS_HOVER_SHOWTEXT_HPP
