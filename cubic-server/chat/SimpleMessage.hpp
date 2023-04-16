#ifndef CHAT_SIMPLEMESSAGE_HPP
#define CHAT_SIMPLEMESSAGE_HPP

#include <cstdint>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>

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

/**
 * @brief A simple message that can be sent to a player, without any events
 *
 * @note This class is used to build a Message and should not be used directly
 *     It was created to avoid receiving events when not needed, but the official
 *     Minecraft client does not care about the events, so it is not really useful
 *
 * @see Message
 */
class SimpleMessage {
public:
    SimpleMessage(const std::string &message, const chat::message::Style &style = {}, const chat::message::Options &options = {});
    SimpleMessage(const char message[], const chat::message::Style &style = {}, const chat::message::Options &options = {});
    ~SimpleMessage() = default;

    const std::string &getMessage() const;
    const chat::message::Style &getStyle() const;
    const chat::message::Options &getOptions() const;
    const std::vector<chat::Message> &getExtra() const;

    std::string &message();
    chat::message::Style &style();
    chat::message::Options &options();
    std::vector<chat::Message> &extra();

    /**
     * @brief Serialize the message to a json string
     *
     * @return std::string
     */
    std::string serialize() const;

    /**
     * @brief Serialize the message to a json object
     *
     * @return nlohmann::json
     */
    virtual nlohmann::json toJson() const;

    /**
     * @brief Deserialize a message from a string
     *
     * @throw std::invalid_argument if the message is not a valid json string
     * @throw std::runtime_error if the parsing failed
     *
     * @param message
     * @return SimpleMessage
     */
    static SimpleMessage deserialize(const std::string &message);

    /**
     * @brief Deserialize a message from a json object
     *
     * @throw std::runtime_error if the parsing failed
     *
     * @param json
     * @return SimpleMessage
     */
    static SimpleMessage fromJson(const nlohmann::json &json);

protected:
    std::string _message;
    chat::message::Style _style;
    chat::message::Options _options;
    std::vector<Message> _extra;
};

} // namespace chat

#include "Message.hpp"

#endif // CHAT_SIMPLEMESSAGE_HPP
