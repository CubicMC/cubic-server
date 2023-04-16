#ifndef CHAT_SIMPLEMESSAGE_HPP
#define CHAT_SIMPLEMESSAGE_HPP

#include <cstdint>
#include <optional>
#include <string>
#include <nlohmann/json.hpp>

#include "translationFromKey.hpp"

namespace chat {
class Message;

namespace message {
enum Type : int32_t {
    Chat = 0,
    Emote,
    WhisperIn,
    WhisperOut,
    Announce,
    TeamText,
    TeamSent,
};

struct Style {
    std::optional<bool> bold;
    std::optional<bool> italic;
    std::optional<bool> underlined;
    std::optional<bool> strikethrough;
    std::optional<bool> obfuscated;
    std::optional<std::string> font;
    std::optional<std::string> color;
};

struct Options {
    std::optional<std::string> insertion;
    std::optional<std::string> translate;
    std::vector<Message> with;
};
} // namespace message

class SimpleMessage {
public:
    SimpleMessage(const std::string &message, const chat::message::Style &style = {}, const chat::message::Options &options = {});
    SimpleMessage(const char message[], const chat::message::Style &style = {}, const chat::message::Options &options = {});
    ~SimpleMessage() = default;

    const std::string &getMessage() const;
    const chat::message::Style &getStyle() const;
    const chat::message::Options &getOptions() const;

    std::string &message();
    chat::message::Style &style();
    chat::message::Options &options();

    std::string serialize() const;
    virtual nlohmann::json toJson() const;

    static SimpleMessage deserialize(const std::string &message);
    static SimpleMessage fromJson(const nlohmann::json &json);

    template<chat::message::TranslationKey key, typename... Args>
    static SimpleMessage fromTranslationKey(Args... args);

protected:
    std::string _message;
    chat::message::Style _style;
    chat::message::Options _options;
    std::vector<Message> _extra;
};

} // namespace chat

#include "Message.hpp"

#endif // CHAT_SIMPLEMESSAGE_HPP
