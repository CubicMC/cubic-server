#include "Chat.hpp"
#include "Server.hpp"
#include "Logger.hpp"
#include "nlohmann/json.hpp"

Chat::Chat()
{
    _log = logging::Logger::get_instance();
}

void Chat::sendPlayerMessage(const Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }
    const auto clients = Server::getInstance()->getClients();

    nlohmann::json response;
    response["translate"] = "chat.type.text";
    response["with"] = nlohmann::json::array();
    response["with"].push_back({"text", "PlayerName"});
    response["with"].push_back(message.toJson());

    // TODO: Filter clients by WorldGroup & chat visibility.
    for (const auto &cli : clients)
        cli->sendChatMessageResponse(
            "",
            true,
            response.dump(),
            (int32_t) MsgType::Chat,
            0, // sender->getUUID(),
            "{\"text\": \"PlayerName\"}", // sender->getName();
            false,
            "",
            std::time(nullptr),
            0,
            0,
            std::vector<uint8_t>()
        );
}

void Chat::sendSystemMessage(const Message &message)
{
    const auto clients = Server::getInstance()->getClients();

    // TODO: Filter clients by WorldGroup & chat visibility.
    for (const auto &cli : clients)
        cli->sendChatMessageResponse(
            "",
            true,
            message.serialize(),
            (int32_t) MsgType::System,
            0,
            "",
            false,
            "",
            std::time(nullptr),
            0,
            0,
            std::vector<uint8_t>()
        );
}

void Chat::sendSayMessage(const Message &message, const Player *sender)
{
    const auto clients = Server::getInstance()->getClients();

    // TODO: Filter clients by WorldGroup & chat visibility.
    for (const auto &cli : clients)
        cli->sendChatMessageResponse(
            "",
            true,
            message.serialize(),
            (int32_t) MsgType::Say,
            0,
            "",
            false,
            "",
            std::time(nullptr),
            0,
            0,
            std::vector<uint8_t>()
        );
}

void Chat::sendMsgMessage(const Message &message, Client *sender, Client *to)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    } else if (to == nullptr) {
        LERROR("to is null");
        return;
    }

    sender->sendChatMessageResponse(
        "",
        true,
        message.serialize(),
        (int32_t) MsgType::Whisper,
        0, // sender->getUUID(),
        "{\"text\": \"PlayerName\"}", // sender->getName();
        false,
        "",
        std::time(nullptr),
        0,
        0,
        std::vector<uint8_t>()
    );
    to->sendChatMessageResponse(
        "",
        true,
        message.serialize(),
        (int32_t) MsgType::Whisper,
        0, // sender->getUUID(),
        "{\"text\": \"PlayerName\"}", // sender->getName();
        false,
        "",
        std::time(nullptr),
        0,
        0,
        std::vector<uint8_t>()
    );
}

Chat::Message::Message(
    const std::string &message,
    Chat::Message::Options options,
    std::optional<Chat::Message::ClickEvent> clickEvent,
    std::optional<Chat::Message::HoverEvent> hoverEvent)
    : _message(message),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{}

std::string Chat::Message::serialize() const
{
    return toJson().dump();
}

nlohmann::json Chat::Message::toJson() const
{
    nlohmann::json response;

    if (_options.bold.has_value())
        response["bold"] = _options.bold.value();
    if (_options.italic.has_value())
        response["italic"] = _options.italic.value();
    if (_options.underlined.has_value())
        response["underlined"] = _options.underlined.value();
    if (_options.strikethrough.has_value())
        response["strikethrough"] = _options.strikethrough.value();
    if (_options.obfuscated.has_value())
        response["obfuscated"] = _options.obfuscated.value();

    if (_clickEvent.has_value())
        response["clickEvent"] = _clickEvent->toJson();

    if (_hoverEvent.has_value())
        response["hoverEvent"] = _hoverEvent->toJson();

    if (_extra.size() > 0) {
        response["extra"] = nlohmann::json::array();
        for (const auto &extra : _extra)
            response["extra"].push_back(extra.toJson());
    }

    return response;
}

nlohmann::json Chat::Message::ClickEvent::toJson() const
{
    nlohmann::json response;

    switch (action) {
        case Action::OpenURL:
            response["action"] = "open_url"; break;
        case Action::OpenFile:
            response["action"] = "open_file"; break;
        case Action::RunCommand:
            response["action"] = "run_command"; break;
        case Action::SuggestCommand:
            response["action"] = "suggest_command"; break;
        case Action::ChangePage:
            response["action"] = "change_page"; break;
        case Action::CopyToClipboard:
            response["action"] = "copy_to_clipboard"; break;
        default:
            LERROR("Unknown click event action: " + std::to_string((int32_t) action)); break;
    }

    response["value"] = value;

    return response;
}

nlohmann::json Chat::Message::HoverEvent::toJson() const
{
    nlohmann::json response;

    switch (action) {
        case Action::ShowText:
            response["action"] = "show_text"; break;
        case Action::ShowItem:
            response["action"] = "show_item"; break;
        case Action::ShowEntity:
            response["action"] = "show_entity"; break;
        default:
            LERROR("Unknown hover event action: " + std::to_string((int32_t) action)); break;
    }

    response["value"] = value;

    return response;
}

std::string_view Chat::Message::getMessage() const
{
    return _message;
}

Chat::Message::Options Chat::Message::getOptions() const
{
    return _options;
}

std::optional<Chat::Message::ClickEvent> Chat::Message::getClickEvent() const
{
    return _clickEvent;
}

std::optional<Chat::Message::HoverEvent> Chat::Message::getHoverEvent() const
{
    return _hoverEvent;
}

std::vector<Chat::Message> Chat::Message::getExtra() const
{
    return _extra;
}

std::string &Chat::Message::message()
{
    return _message;
}

Chat::Message::Options &Chat::Message::options()
{
    return _options;
}

std::optional<Chat::Message::ClickEvent> &Chat::Message::clickEvent()
{
    return _clickEvent;
}

std::optional<Chat::Message::HoverEvent> &Chat::Message::hoverEvent()
{
    return _hoverEvent;
}

std::vector<Chat::Message> &Chat::Message::extra()
{
    return _extra;
}
