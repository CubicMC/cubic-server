#include "Text.hpp"

chat::message::event::TextHover::TextHover(const chat::Message &message):
    messages({message})
{
}

chat::message::event::TextHover::TextHover(const std::vector<chat::Message> &messages):
    messages(messages)
{
}

chat::message::event::TextHover::TextHover(const std::initializer_list<chat::Message> &messages)
{
    for (auto &message : messages)
        this->messages.push_back(message);
}

std::shared_ptr<chat::message::event::TextHover> chat::message::event::TextHover::fromJson(const nlohmann::json &json)
{
    std::shared_ptr<TextHover> event = std::make_shared<TextHover>();

    if (json["contents"].is_array()) {
        for (auto &message : json["contents"])
            event->addMessage(chat::Message::fromJson(message));
    } else
        event->addMessage(chat::Message::fromJson(json["contents"]));

    return event;
}

nlohmann::json chat::message::event::TextHover::toJson() const
{
    nlohmann::json response;

    response["action"] = "show_text";
    response["contents"] = nlohmann::json::array();

    for (auto &message : messages)
        response["contents"].push_back(message.toJson());

    return response;
}

chat::message::event::TextHover &chat::message::event::TextHover::addMessage(const chat::Message &message)
{
    messages.push_back(message);
    return *this;
}
