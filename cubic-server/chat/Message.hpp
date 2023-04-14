#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "HoverEvent.hpp"
#include "ClickEvent.hpp"

#include "nbt.hpp"

class Player;

namespace chat {

// Should be in the same order as in the login play packet
enum TranslationKey : int32_t {
    chat_type_text = 0,
    chat_type_emote,
    commands_message_display_incoming,
    commands_message_display_outgoing,
    chat_type_announcement,
    chat_type_team_text,
    chat_type_team_sent,
    multiplayer_player_left = 500,
    multiplayer_player_joined,
};

namespace message {
enum Type : int32_t {
    Chat = 0,
    Emote,
    WhisperInc,
    WhisperOut,
    Announce,
    TeamText,
    TeamSent,
};
} // namespace message

class Message {
public:
    struct Style {
        std::optional<bool> bold;
        std::optional<bool> italic;
        std::optional<bool> underlined;
        std::optional<bool> strikethrough;
        std::optional<bool> obfuscated;
        std::optional<std::string> font;
        std::optional<std::string> color;
    };
    struct Options : public Style {
        std::optional<std::string> insertion;
        std::optional<std::string> translate;
        std::vector<Message> with;
    };

private:
    Message() = default;

public:
    Message(
        const std::string &message, Options options = {}, std::optional<chat::message::ClickEvent> clickEvent = std::nullopt,
        std::optional<chat::message::HoverEvent> hoverEvent = std::nullopt
    );

    Message(
        const char message[], Options options = {}, std::optional<chat::message::ClickEvent> clickEvent = std::nullopt,
        std::optional<chat::message::HoverEvent> hoverEvent = std::nullopt
    );

    const std::string &getMessage() const;
    const Options &getOptions() const;
    const std::optional<chat::message::ClickEvent> &getClickEvent() const;
    const std::optional<chat::message::HoverEvent> &getHoverEvent() const;
    const std::vector<Message> &getExtra() const;

    std::string &message();
    Options &options();
    std::optional<chat::message::ClickEvent> &clickEvent();
    std::optional<chat::message::HoverEvent> &hoverEvent();
    std::vector<Message> &extra();

    std::string serialize() const;
    nlohmann::json toJson() const;

    // template<typename... Args>
    // Message &wrap(const std::string &translationKey, const Args&... args);

    static Message deserialize(const std::string &message);
    static Message fromJson(const nlohmann::json &json);
    template<TranslationKey key, typename... Args>
    static Message fromTranslationKey(Args... args);

private:
    std::string _message;
    Options _options;
    std::optional<chat::message::ClickEvent> _clickEvent;
    std::optional<chat::message::HoverEvent> _hoverEvent;
    std::vector<Message> _extra;
};

template<>
Message Message::fromTranslationKey<TranslationKey::chat_type_text>(const Player *player, const std::string &message);
// template<>
// Message Message::fromTranslationKey<TranslationKey::chat_type_emote>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::commands_message_display_incoming>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::commands_message_display_outgoing>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::chat_type_announcement>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::chat_type_team_text>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::chat_type_team_sent>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::chat_type_team_text>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<TranslationKey::multiplayer_player_joined>(const Player *player);
template<>
Message Message::fromTranslationKey<TranslationKey::multiplayer_player_left>(const Player *player);

} // namespace chat

#endif // CHAT_MESSAGE_HPP
