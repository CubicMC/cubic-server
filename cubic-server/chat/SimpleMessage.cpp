#include "SimpleMessage.hpp"
#include "Message.hpp"

chat::SimpleMessage::SimpleMessage(const std::string &message, const chat::message::Style &style, const chat::message::Options &options):
    _message(message),
    _style(style),
    _options(options)
{
}

chat::SimpleMessage::SimpleMessage(const char message[], const chat::message::Style &style, const chat::message::Options &options):
    _message(message),
    _style(style),
    _options(options)
{
}

const std::string &chat::SimpleMessage::getMessage() const
{
    return this->_message;
}

const chat::message::Style &chat::SimpleMessage::getStyle() const
{
    return this->_style;
}

const chat::message::Options &chat::SimpleMessage::getOptions() const
{
    return this->_options;
}

std::string &chat::SimpleMessage::message()
{
    return this->_message;
}

chat::message::Style &chat::SimpleMessage::style()
{
    return this->_style;
}

chat::message::Options &chat::SimpleMessage::options()
{
    return this->_options;
}

nlohmann::json chat::SimpleMessage::toJson() const
{
    nlohmann::json response;

    if (_message.size() > 0)
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

    return response;
}

std::string chat::SimpleMessage::serialize() const { return this->toJson().dump(); }

chat::SimpleMessage chat::SimpleMessage::deserialize(const std::string &message)
{
    try {
        return chat::SimpleMessage::fromJson(nlohmann::json::parse(message));
    } catch (const nlohmann::json::exception &e) {
        throw std::invalid_argument(e.what());
    }
}

chat::SimpleMessage chat::SimpleMessage::fromJson(const nlohmann::json &json)
{
    try {
        SimpleMessage message = SimpleMessage(json["text"].get<std::string>());

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

        return message;
    } catch (const nlohmann::json::exception &e) {
        throw std::runtime_error(e.what());
    }
}
