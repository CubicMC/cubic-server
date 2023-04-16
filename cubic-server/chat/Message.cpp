#include "Message.hpp"
#include "SimpleMessage.hpp"
#include "ChatRegistry.hpp"
#include <optional>
#include <nlohmann/json.hpp>

chat::Message::Message(const SimpleMessage &messageComponent):
    _messageComponent(messageComponent)
{
}

chat::Message::Message(
    const std::string &message, const chat::message::Style &style, const chat::message::Options &options, const std::shared_ptr<chat::message::event::OnClick> &clickEvent, const std::shared_ptr<chat::message::event::OnHover> &hoverEvent
):
    _messageComponent(message, style, options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{
}

chat::Message::Message(
    const char message[], const chat::message::Style &style, const chat::message::Options &options, const std::shared_ptr<chat::message::event::OnClick> &clickEvent, const std::shared_ptr<chat::message::event::OnHover> &hoverEvent
):
    _messageComponent(message, style, options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{
}

std::string chat::Message::serialize() const { return this->toJson().dump(); }

nlohmann::json chat::Message::toJson() const
{
    nlohmann::json response = this->_messageComponent.toJson();

    if (_clickEvent)
        response["clickEvent"] = _clickEvent->toJson();

    if (_hoverEvent)
        response["hoverEvent"] = _hoverEvent->toJson();

    return response;
}

chat::Message chat::Message::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::Message chat::Message::fromJson(const nlohmann::json &json)
{
    Message msg = Message(SimpleMessage::fromJson(json));

    if (json.contains("clickEvent"))
        msg.clickEvent(message::event::OnClick::fromJson(json["clickEvent"]));
    if (json.contains("hoverEvent"))
        msg.hoverEvent(message::event::OnHover::fromJson(json["hoverEvent"]));
    if (json.contains("extra")) {
        for (const auto &extra : json["extra"])
            msg._extra.push_back(fromJson(extra));
    }
    return msg;
}

// Getters
const std::shared_ptr<chat::message::event::OnClick> &chat::Message::getClickEvent() const { return _clickEvent; }
const std::shared_ptr<chat::message::event::OnHover> &chat::Message::getHoverEvent() const { return _hoverEvent; }
const chat::SimpleMessage &chat::Message::getMessageComponent() const { return _messageComponent; }
const std::vector<chat::Message> &chat::Message::getExtra() const { return _extra; }

// Getters (mutable)
void chat::Message::clickEvent(const std::shared_ptr<chat::message::event::OnClick> &event) { _clickEvent = event; }
void chat::Message::hoverEvent(const std::shared_ptr<chat::message::event::OnHover> &event) { _hoverEvent = event; }
chat::SimpleMessage &chat::Message::messageComponent() { return _messageComponent; }
std::vector<chat::Message> &chat::Message::extra() { return _extra; }
