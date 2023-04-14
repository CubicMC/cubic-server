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
             "{\"text\":\"}" + player->getUsername() + "AZETAZEFA\"}",
             {
                 .insertion = "{\"text\":\"}" + player->getUsername() + "INSERTION\"}",
             },
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


nbt::Compound *chat::message::getChatRegistry()
{
    chat::_details::Registry registry;

    // Chat message
    chat::_details::ChatType chatType;
    chatType
        .id(chat::TranslationKey::chat_type_text)
        .name("minecraft:chat")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.text")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(chatType);

    // Emote message (lol)
    chat::_details::ChatType emoteType;
    emoteType
        .id(chat::TranslationKey::chat_type_emote)
        .name("minecraft:emote_command")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.emote")
        .narrateKey("chat.type.emote");

    registry.addChatType(emoteType);

    // Whisper message incoming
    chat::_details::ChatType whisperIncomingType;
    whisperIncomingType
        .id(chat::TranslationKey::commands_message_display_incoming)
        .name("minecraft:msg_command_incoming")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("commands.message.display.incoming")
        .narrateKey("chat.type.text.narrate")
        .addStyle({
            .italic = true,
            .color = "gray",
        });

    registry.addChatType(whisperIncomingType);

    // Whisper message outgoing
    chat::_details::ChatType whisperOutgoingType;
    whisperOutgoingType
        .id(chat::TranslationKey::commands_message_display_outgoing)
        .name("minecraft:msg_command_outgoing")
        .addChatParameter("target")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("commands.message.display.outgoing")
        .narrateKey("chat.type.text.narrate")
        .addStyle({
            .italic = true,
            .color = "gray",
        });

    registry.addChatType(whisperOutgoingType);

    // say message
    chat::_details::ChatType sayType;
    sayType
        .id(chat::TranslationKey::chat_type_announcement)
        .name("minecraft:say_command")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.announcement")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(sayType);

    // Chat team message incoming
    chat::_details::ChatType teamIncomingType;
    teamIncomingType
        .id(chat::TranslationKey::chat_type_team_text)
        .name("minecraft:team_msg_command_incoming")
        .addChatParameter("target")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.team.text")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(teamIncomingType);

    // Chat team message outgoing
    chat::_details::ChatType teamOutgoingType;
    teamOutgoingType
        .id(chat::TranslationKey::chat_type_team_sent)
        .name("minecraft:team_msg_command_outgoing")
        .addChatParameter("target")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.team.sent")
        .narrateKey("chat.type.text.narrate");

    return registry.toNBT();

    // return new nbt::Compound("minecraft:chat_type", {
    //     new nbt::String("type", "minecraft:chat_type"),
    //     new nbt::List("value", {
    //         new nbt::Compound("chat message", {
    //             new nbt::Int("id", chat::TranslationKey::chat_type_text),
    //             new nbt::String("name", "minecraft:chat"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "chat.type.text"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.text.narrate"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //         new nbt::Compound("chat emote wtf", {
    //             new nbt::Int("id", chat::TranslationKey::chat_type_emote),
    //             new nbt::String("name", "minecraft:emote_command"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "chat.type.emote"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.emote"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //         new nbt::Compound("chat whisper incoming", {
    //             new nbt::Int("id", chat::TranslationKey::commands_message_display_incoming),
    //             new nbt::String("name", "minecraft:msg_command_incoming"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "commands.message.display.incoming"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     }),
    //                     new nbt::Compound("style", {
    //                         new nbt::String("color", "gray"),
    //                         new nbt::Byte("italic", 1),
    //                     }),
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.text.narrate"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //         new nbt::Compound("chat whisper outgoing", {
    //             new nbt::Int("id", chat::TranslationKey::commands_message_display_outgoing),
    //             new nbt::String("name", "minecraft:msg_command_outgoing"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "commands.message.display.outgoing"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     }),
    //                     new nbt::Compound("style", {
    //                         new nbt::String("color", "gray"),
    //                         new nbt::Byte("italic", 1),
    //                     }),
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.text.narrate"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //         new nbt::Compound("chat announcement (say cmd)", {
    //             new nbt::Int("id", chat::TranslationKey::chat_type_announcement),
    //             new nbt::String("name", "minecraft:say_command"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "chat.type.announcement"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.text.narrate"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //         new nbt::Compound("chat team incoming", {
    //             new nbt::Int("id", chat::TranslationKey::chat_type_team_text),
    //             new nbt::String("name", "minecraft:team_msg_command_incoming"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "chat.type.team.text"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "target"),
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.text.narrate"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //         new nbt::Compound("chat team outgoing", {
    //             new nbt::Int("id", chat::TranslationKey::chat_type_team_send),
    //             new nbt::String("name", "minecraft:team_msg_command_outgoing"),
    //             new nbt::Compound("element", {
    //                 new nbt::Compound("chat", {
    //                     new nbt::String("translation_key", "chat.type.team.sent"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("", "target"),
    //                         new nbt::String("", "sender"),
    //                         new nbt::String("", "content")
    //                     })
    //                 }),
    //                 new nbt::Compound("narration", {
    //                     new nbt::String("translation_key", "chat.type.text.narrate"),
    //                     new nbt::List("parameters", {
    //                         new nbt::String("sender"),
    //                         new nbt::String("content")
    //                     })
    //                 }),
    //             }),
    //         }),
    //     }),
    // });
}
