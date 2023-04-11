#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "HoverEvent.hpp"
#include "ClickEvent.hpp"

namespace chat {

namespace message {
enum class Type : int32_t {
    Chat = 0,
    System = 1,
    GameInfo = 2,
    Say = 3,
    Whisper = 4,
    Team = 5,
    Emote = 6, // Don't ask me...
    Tellraw = 7,
};
} // namespace message

enum TranslateKey : int32_t {
    multiplayer_player_left = 0,
    multiplayer_player_joined = 1,
};

class Message {
public:
    struct Options {
        // Options() = default;
        std::optional<bool> bold;
        std::optional<bool> italic;
        std::optional<bool> underlined;
        std::optional<bool> strikethrough;
        std::optional<bool> obfuscated;
        std::optional<std::string> font;
        std::optional<std::string> color;
        std::optional<std::string> insertion;
        std::optional<std::string> translate;
        std::optional<std::vector<Message>> with;
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

    std::string getMessage() const;
    Options getOptions() const;
    std::optional<chat::message::ClickEvent> getClickEvent() const;
    std::optional<chat::message::HoverEvent> getHoverEvent() const;
    std::vector<Message> getExtra() const;

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
    template<TranslateKey key, typename... Args>
    static Message fromTranslateKey(const Args&... args);

private:
    std::string _message;
    Options _options;
    std::optional<chat::message::ClickEvent> _clickEvent;
    std::optional<chat::message::HoverEvent> _hoverEvent;
    std::vector<Message> _extra;
};

// template<typename... Args>
// Message &Message::wrap(const std::string &translationKey, const Args&... args)
// {
//     _options.translate = translationKey;
//     _options.with = {args...};
//     return *this;
// }

template<>
Message Message::fromTranslateKey<TranslateKey::multiplayer_player_joined, std::string>(const std::string &playerName);
template<>
Message Message::fromTranslateKey<TranslateKey::multiplayer_player_left, std::string>(const std::string &playerName);

// template<TranslateKey::multiplayer_player_joined, typename... Args>
// Message Message::fromTranslateKey(const Args&... args)
// {
//     Message message;
//     message.wrap(args...);
//     return message;
// }

} // namespace chat

#endif // CHAT_MESSAGE_HPP
