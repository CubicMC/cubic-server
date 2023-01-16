#include "Chat.hpp"
#include "Server.hpp"
#include "logging/Logger.hpp"
#include "WorldGroup.hpp"
#include "nlohmann/json.hpp"

Chat::Chat()
{
    _log = logging::Logger::get_instance();
}

void Chat::sendPlayerMessage(const chat::Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    nlohmann::json response;
    response["translate"] = "chat.type.text";
    response["with"] = nlohmann::json::array();
    response["with"].push_back({"text", "PlayerName"});
    response["with"].push_back(message.toJson());

    // TODO: Filter client by chat visibility
    for (auto &world : sender->getDimension()->getWorld()->getWorldGroup()->getWorlds()) {
        for (auto &entity : world.second->getEntities()) {
            auto player = dynamic_cast<Player*>(entity);
            if (player == nullptr)
                continue;
            player->getClient()->sendChatMessageResponse({
                "",
                true,
                response.dump(),
                (int32_t) chat::message::Type::Chat,
                {0, 0}, // sender->getUUID(),
                "{\"text\": \"PlayerName\"}", // sender->getName();
                false,
                "",
                std::time(nullptr),
                0,
                std::vector<uint8_t>()
            });
        }
    }
}

void Chat::sendSystemMessage(const chat::Message &message, bool overlay, const WorldGroup *worldGroup)
{
    if (worldGroup == nullptr) {
        LERROR("worldGroup is null");
        return;
    }
    LDEBUG("send System Message: " + message.getMessage());

    // TODO: Filter client by chat visibility
    for (const auto &world : worldGroup->getWorlds()) {
        for (auto &entity : world.second->getEntities()) {
            auto player = dynamic_cast<Player*>(entity);
            if (player == nullptr)
                continue;
            player->getClient()->sendSystemChatMessage({
                message.serialize(),
                overlay
            });
        }
    }
}

void Chat::sendSayMessage(const chat::Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    // TODO: Filter client by chat visibility
    for (auto &world : sender->getDimension()->getWorld()->getWorldGroup()->getWorlds()) {
        for (auto &entity : world.second->getEntities()) {
            auto player = dynamic_cast<Player*>(entity);
            if (player == nullptr)
                continue;
            player->getClient()->sendChatMessageResponse({
                "",
                true,
                message.serialize(),
                (int32_t) chat::message::Type::Say,
                {0, 0},
                "",
                false,
                "",
                std::time(nullptr),
                0,
                std::vector<uint8_t>()
            });
        }
    }
}

void Chat::sendMsgMessage(const chat::Message &message, Client *sender, Client *to)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    } else if (to == nullptr) {
        LERROR("to is null");
        return;
    }

    sender->sendChatMessageResponse({
        "",
        true,
        message.serialize(),
        (int32_t) chat::message::Type::Whisper,
        {0, 0}, // sender->getUUID(),
        "{\"text\": \"PlayerName\"}", // sender->getName();
        false,
        "",
        std::time(nullptr),
        0,
        std::vector<uint8_t>()
    });
    to->sendChatMessageResponse({
        "",
        true,
        message.serialize(),
        (int32_t) chat::message::Type::Whisper,
        {0, 0}, // sender->getUUID(),
        "{\"text\": \"PlayerName\"}", // sender->getName();
        false,
        "",
        std::time(nullptr),
        0,
        std::vector<uint8_t>()
    });
}

chat::Message::Message(
    const std::string &message,
    chat::Message::Options options,
    std::optional<chat::message::ClickEvent> clickEvent,
    std::optional<chat::message::HoverEvent> hoverEvent)
    : _message(message),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{}

chat::Message::Message(
    const char message[],
    chat::Message::Options options,
    std::optional<chat::message::ClickEvent> clickEvent,
    std::optional<chat::message::HoverEvent> hoverEvent)
    : _message(message),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{}

std::string chat::Message::serialize() const
{
    std::cout << "in serialize: " + toJson().dump() << std::endl;
    return toJson().dump();
}

nlohmann::json chat::Message::toJson() const
{
    nlohmann::json response;

    if (_message.size() > 0)
        response["text"] = _message;

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
    if (_options.font.has_value())
        response["font"] = _options.font.value();
    if (_options.color.has_value())
        response["color"] = _options.color.value();
    if (_options.insertion.has_value())
        response["insertion"] = _options.insertion.value();
    if (_options.translate.has_value())
        response["translate"] = _options.translate.value();
    if (_options.with.has_value()) {
        response["with"] = nlohmann::json::array();
        for (auto &withMsg : _options.with.value())
            response["with"].push_back(withMsg.toJson());
    };

    if (_clickEvent.has_value())
        response["clickEvent"] = _clickEvent.value().toJson();

    if (_hoverEvent.has_value())
        response["hoverEvent"] = _hoverEvent.value().toJson();

    if (_extra.size() > 0) {
        response["extra"] = nlohmann::json::array();
        for (const auto &extra : _extra)
            response["extra"].push_back(extra.toJson());
    }

    return response;
}

nlohmann::json chat::message::ClickEvent::toJson() const
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

nlohmann::json chat::message::HoverEvent::toJson() const
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

chat::Message chat::Message::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::message::ClickEvent chat::message::ClickEvent::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::message::HoverEvent chat::message::HoverEvent::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::Message chat::Message::fromJson(const nlohmann::json &json)
{
    Message msg;
    msg._message = json["text"].get<std::string>();
    if (json.contains("bold"))
        msg._options.bold = json["bold"].get<bool>();
    if (json.contains("italic"))
        msg._options.italic = json["italic"].get<bool>();
    if (json.contains("underlined"))
        msg._options.underlined = json["underlined"].get<bool>();
    if (json.contains("strikethrough"))
        msg._options.strikethrough = json["strikethrough"].get<bool>();
    if (json.contains("obfuscated"))
        msg._options.obfuscated = json["obfuscated"].get<bool>();
    if (json.contains("clickEvent"))
        msg._clickEvent = message::ClickEvent::fromJson(json["clickEvent"]);
    if (json.contains("hoverEvent"))
        msg._hoverEvent = message::HoverEvent::fromJson(json["hoverEvent"]);
    if (json.contains("extra")) {
        for (const auto &extra : json["extra"])
            msg._extra.push_back(fromJson(extra));
    }
    return msg;
}

chat::message::ClickEvent chat::message::ClickEvent::fromJson(const nlohmann::json &json)
{
    ClickEvent event;
    std::string action = json["action"].get<std::string>();
    if (action == "open_url")
        event.action = Action::OpenURL;
    else if (action == "open_file")
        event.action = Action::OpenFile;
    else if (action == "run_command")
        event.action = Action::RunCommand;
    else if (action == "suggest_command")
        event.action = Action::SuggestCommand;
    else if (action == "change_page")
        event.action = Action::ChangePage;
    else if (action == "copy_to_clipboard")
        event.action = Action::CopyToClipboard;
    else
        throw std::runtime_error("Unknown click event action: " + action);
    event.value = json["value"].get<std::string>();
    return event;
}

chat::message::HoverEvent chat::message::HoverEvent::fromJson(const nlohmann::json &json)
{
    HoverEvent event;
    std::string action = json["action"].get<std::string>();
    if (action == "show_text")
        event.action = Action::ShowText;
    else if (action == "show_item")
        event.action = Action::ShowItem;
    else if (action == "show_entity")
        event.action = Action::ShowEntity;
    else
        throw std::runtime_error("Unknown hover event action: " + action);
    event.value = json["value"].get<std::string>();
    return event;
}

std::string chat::Message::getMessage() const
{
    return _message;
}

chat::Message::Options chat::Message::getOptions() const
{
    return _options;
}

std::optional<chat::message::ClickEvent> chat::Message::getClickEvent() const
{
    return _clickEvent;
}

std::optional<chat::message::HoverEvent> chat::Message::getHoverEvent() const
{
    return _hoverEvent;
}

std::vector<chat::Message> chat::Message::getExtra() const
{
    return _extra;
}

std::string &chat::Message::message()
{
    return _message;
}

chat::Message::Options &chat::Message::options()
{
    return _options;
}

std::optional<chat::message::ClickEvent> &chat::Message::clickEvent()
{
    return _clickEvent;
}

std::optional<chat::message::HoverEvent> &chat::Message::hoverEvent()
{
    return _hoverEvent;
}

std::vector<chat::Message> &chat::Message::extra()
{
    return _extra;
}
