#include "Message.hpp"

// #include "ChatRegistry.hpp"
#include <nlohmann/json.hpp>
#include <optional>

chat::Message::Message(
    const std::string &message, const chat::message::Style &style, const chat::message::Options &options, const std::shared_ptr<const chat::message::event::OnClick> &clickEvent,
    const std::shared_ptr<const chat::message::event::OnHover> &hoverEvent
):
    _message(message),
    _style(style),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{
}

chat::Message::Message(
    const char message[], const chat::message::Style &style, const chat::message::Options &options, const std::shared_ptr<const chat::message::event::OnClick> &clickEvent,
    const std::shared_ptr<const chat::message::event::OnHover> &hoverEvent
):
    _message(message),
    _style(style),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{
}

std::string chat::Message::serialize() const { return this->toJson().dump(); }

nlohmann::json chat::Message::toJson() const
{
    nlohmann::json response;

    if (!_message.empty())
        response["text"] = _message;

    if (_style.bold.has_value())
        response["bold"] = _style.bold.value();
    if (_style.italic.has_value())
        response["italic"] = _style.italic.value();
    if (_style.underlined.has_value())
        response["underlined"] = _style.underlined.value();
    if (_style.strikethrough.has_value())
        response["strikethrough"] = _style.strikethrough.value();
    if (_style.obfuscated.has_value())
        response["obfuscated"] = _style.obfuscated.value();
    if (_style.font.has_value())
        response["font"] = _style.font.value();
    if (_style.color.has_value())
        response["color"] = _style.color.value();
    if (_options.insertion.has_value())
        response["insertion"] = _options.insertion.value();
    if (_options.translate.has_value())
        response["translate"] = _options.translate.value();
    if (_options.with.size() > 0) {
        response["with"] = nlohmann::json::array();
        for (auto &withMsg : _options.with)
            response["with"].push_back(withMsg.toJson());
    };

    if (_extra.size() > 0) {
        response["extra"] = nlohmann::json::array();
        for (const auto &extra : _extra)
            response["extra"].push_back(extra.toJson());
    }

    if (_clickEvent)
        response["clickEvent"] = _clickEvent->toJson();

    if (_hoverEvent)
        response["hoverEvent"] = _hoverEvent->toJson();

    if (response.empty())
        response["text"] = "";

    return response;
}

chat::Message chat::Message::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::Message chat::Message::fromJson(const nlohmann::json &json)
{
    try {
        Message message = Message(json["text"].get<std::string>());

        if (json.contains("bold"))
            message._style.bold = json["bold"].get<bool>();
        if (json.contains("italic"))
            message._style.italic = json["italic"].get<bool>();
        if (json.contains("underlined"))
            message._style.underlined = json["underlined"].get<bool>();
        if (json.contains("strikethrough"))
            message._style.strikethrough = json["strikethrough"].get<bool>();
        if (json.contains("obfuscated"))
            message._style.obfuscated = json["obfuscated"].get<bool>();
        if (json.contains("font"))
            message._style.font = json["font"].get<std::string>();
        if (json.contains("color"))
            message._style.color = json["color"].get<std::string>();
        if (json.contains("insertion"))
            message._options.insertion = json["insertion"].get<std::string>();
        if (json.contains("translate"))
            message._options.translate = json["translate"].get<std::string>();
        if (json.contains("with")) {
            for (const auto &with : json["with"])
                message._options.with.push_back(Message::fromJson(with));
        }

        if (json.contains("extra")) {
            for (const auto &extra : json["extra"])
                message._extra.push_back(Message::fromJson(extra));
        }

        if (json.contains("clickEvent"))
            message.clickEvent(message::event::OnClick::fromJson(json["clickEvent"]));
        if (json.contains("hoverEvent"))
            message.hoverEvent(message::event::OnHover::fromJson(json["hoverEvent"]));

        return message;
    } catch (const nlohmann::json::exception &e) {
        throw std::runtime_error(e.what());
    }
}

// Getters
const std::shared_ptr<const chat::message::event::OnClick> &chat::Message::getClickEvent() const { return _clickEvent; }
const std::shared_ptr<const chat::message::event::OnHover> &chat::Message::getHoverEvent() const { return _hoverEvent; }
const std::string &chat::Message::getMessage() const { return this->_message; }
const chat::message::Style &chat::Message::getStyle() const { return this->_style; }
const chat::message::Options &chat::Message::getOptions() const { return this->_options; }
const std::vector<chat::Message> &chat::Message::getExtra() const { return _extra; }

// Getters (mutable)
void chat::Message::clickEvent(const std::shared_ptr<const chat::message::event::OnClick> &event) { _clickEvent = event; }
void chat::Message::hoverEvent(const std::shared_ptr<const chat::message::event::OnHover> &event) { _hoverEvent = event; }
std::string &chat::Message::message() { return this->_message; }
chat::message::Style &chat::Message::style() { return this->_style; }
chat::message::Options &chat::Message::options() { return this->_options; }
std::vector<chat::Message> &chat::Message::extra() { return _extra; }
