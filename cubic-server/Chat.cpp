#include "Chat.hpp"
#include "Server.hpp"
#include "Logger.hpp"
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
            try {
                auto player = dynamic_cast<Player*>(entity);
                player->getClient()->sendChatMessageResponse({
                    "",
                    true,
                    response.dump(),
                    (int32_t) chat::message::Type::Chat,
                    0, // sender->getUUID(),
                    "{\"text\": \"PlayerName\"}", // sender->getName();
                    false,
                    "",
                    std::time(nullptr),
                    0,
                    0,
                    std::vector<uint8_t>()
            });
            } catch (std::bad_cast) {}
        }
    }
}

void Chat::sendSystemMessage(const chat::Message &message, const WorldGroup *worldGroup)
{
    if (worldGroup == nullptr) {
        LERROR("worldGroup is null");
        return;
    }

    // TODO: Filter client by chat visibility
    for (const auto &world : worldGroup->getWorlds()) {
        for (auto &entity : world.second->getEntities()) {
            try {
                auto player = dynamic_cast<Player*>(entity);
                player->getClient()->sendChatMessageResponse({
                    "",
                    true,
                    message.serialize(),
                    (int32_t) chat::message::Type::System,
                    0,
                    "",
                    false,
                    "",
                    std::time(nullptr),
                    0,
                    0,
                    std::vector<uint8_t>()
                });
            } catch (std::bad_cast) {}
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
            try {
                auto player = dynamic_cast<Player*>(entity);
                player->getClient()->sendChatMessageResponse({
                    "",
                    true,
                    message.serialize(),
                    (int32_t) chat::message::Type::Say,
                    0,
                    "",
                    false,
                    "",
                    std::time(nullptr),
                    0,
                    0,
                    std::vector<uint8_t>()
                });
            } catch (std::bad_cast) {}
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
        0, // sender->getUUID(),
        "{\"text\": \"PlayerName\"}", // sender->getName();
        false,
        "",
        std::time(nullptr),
        0,
        0,
        std::vector<uint8_t>()
    });
    to->sendChatMessageResponse({
        "",
        true,
        message.serialize(),
        (int32_t) chat::message::Type::Whisper,
        0, // sender->getUUID(),
        "{\"text\": \"PlayerName\"}", // sender->getName();
        false,
        "",
        std::time(nullptr),
        0,
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

std::string chat::Message::serialize() const
{
    return toJson().dump();
}

nlohmann::json chat::Message::toJson() const
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

std::string_view chat::Message::getMessage() const
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
