#ifndef CHAT_EVENTS_HOVER_TEXT_HPP
#define CHAT_EVENTS_HOVER_TEXT_HPP

#include "chat/Message.hpp"
#include "chat/events/Hover.hpp"

namespace chat::message::event {
/**
 * @brief Show text in the hover event
 */
class TextHover : public OnHover {
public:
    TextHover(const chat::Message &message = "");
    TextHover(const std::vector<chat::Message> &messages);
    TextHover(const std::initializer_list<chat::Message> &messages);
    template<typename... Args>
    TextHover(const chat::Message &message, const Args &...args)
    {
        messages.push_back(message);
        addMessage(std::forward<Args>(args)...);
    }

    ~TextHover() override = default;

public:
    TextHover &addMessage(const chat::Message &message);

    template<typename... Args>
    TextHover &addMessage(const chat::Message &message, const Args &...args)
    {
        messages.push_back(message);
        return addMessage(std::forward<Args>(args)...);
    }

    nlohmann::json toJson() const override;

    static std::shared_ptr<TextHover> fromJson(const nlohmann::json &json);

private:
    std::vector<chat::Message> messages;
};
} // namespace chat::message

#endif // CHAT_EVENTS_HOVER_SHOWTEXT_HPP
