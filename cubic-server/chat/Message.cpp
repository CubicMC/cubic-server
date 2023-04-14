#include "Message.hpp"
#include "Player.hpp"
#include "ChatRegistry.hpp"

chat::Message::Message(
    const std::string &message, chat::Message::Options options, std::optional<chat::message::ClickEvent> clickEvent, std::optional<chat::message::HoverEvent> hoverEvent
):
    _message(message),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{
}

chat::Message::Message(
    const char message[], chat::Message::Options options, std::optional<chat::message::ClickEvent> clickEvent, std::optional<chat::message::HoverEvent> hoverEvent
):
    _message(message),
    _options(options),
    _clickEvent(clickEvent),
    _hoverEvent(hoverEvent)
{
}

std::string chat::Message::serialize() const { return toJson().dump(); }

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
    if (_options.with.size() > 0) {
        response["with"] = nlohmann::json::array();
        for (auto &withMsg : _options.with)
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

chat::Message chat::Message::deserialize(const std::string &message)
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

// Getters
const std::string &chat::Message::getMessage() const { return _message; }
const chat::Message::Options &chat::Message::getOptions() const { return _options; }
const std::optional<chat::message::ClickEvent> &chat::Message::getClickEvent() const { return _clickEvent; }
const std::optional<chat::message::HoverEvent> &chat::Message::getHoverEvent() const { return _hoverEvent; }
const std::vector<chat::Message> &chat::Message::getExtra() const { return _extra; }

// Getters (mutable)
std::string &chat::Message::message() { return _message; }
chat::Message::Options &chat::Message::options() { return _options; }
std::optional<chat::message::ClickEvent> &chat::Message::clickEvent() { return _clickEvent; }
std::optional<chat::message::HoverEvent> &chat::Message::hoverEvent() { return _hoverEvent; }
std::vector<chat::Message> &chat::Message::extra() { return _extra; }

#pragma region Translation Keys

template<>
chat::Message chat::Message::fromTranslationKey<chat::TranslationKey::multiplayer_player_joined, const Player *>(const Player *player)
{
    chat::Message message = chat::Message(
        "",
        {
         { .color = "yellow" },
         "",
         "multiplayer.player.joined",
         std::vector<chat::Message>({chat::Message(
             player->getUsername(),
             {},
             chat::message::ClickEvent(chat::message::ClickEvent::Action::SuggestCommand, "/tell " + player->getUsername() + " "),
             chat::message::HoverEvent(
                 chat::message::HoverEvent::Action::ShowEntity,
                 "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
             )
         )})}
    );
    return message;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::TranslationKey::multiplayer_player_left>(const Player *player)
{
    Message message = chat::Message(
        "",
        {
         { .color = "yellow" },
         "",
         "multiplayer.player.left",
         std::vector<chat::Message>({chat::Message(
             player->getUsername(),
             {
                 .insertion = player->getUsername(),
             },
             chat::message::ClickEvent(chat::message::ClickEvent::Action::SuggestCommand, "/tell " + player->getUsername()),
             chat::message::HoverEvent(
                 chat::message::HoverEvent::Action::ShowEntity,
                 "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
             )
         )})}
    );
    return message;
}

#pragma endregion
