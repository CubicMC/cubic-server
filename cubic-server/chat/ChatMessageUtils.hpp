#ifndef CHAT_MESSAGEUTILS_HPP
#define CHAT_MESSAGEUTILS_HPP

#include <optional>
#include <vector>

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
} // namespace chat

#endif /* CHAT_MESSAGEUTILS_HPP */