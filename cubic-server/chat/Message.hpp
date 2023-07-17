#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdint>
#include <memory>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <vector>

#include "events/Click.hpp"
#include "events/Hover.hpp"
#include "translationFromKey.hpp"

#include "concept.hpp"

class Player;

namespace chat {

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
 * @brief A message that can be sent to a player
 */
class Message {
public:
    Message(
        const std::string &message = "", const chat::message::Style &style = {}, const chat::message::Options &options = {},
        const std::shared_ptr<const chat::message::event::OnClick> &clickEvent = nullptr, const std::shared_ptr<const chat::message::event::OnHover> &hoverEvent = nullptr
    );

    Message(
        const char message[], const chat::message::Style &style = {}, const chat::message::Options &options = {},
        const std::shared_ptr<const chat::message::event::OnClick> &clickEvent = nullptr, const std::shared_ptr<const chat::message::event::OnHover> &hoverEvent = nullptr
    );
    ~Message() = default;

    const std::shared_ptr<const chat::message::event::OnClick> &getClickEvent() const;
    const std::shared_ptr<const chat::message::event::OnHover> &getHoverEvent() const;

    const std::string &getMessage() const;
    const chat::message::Style &getStyle() const;
    const chat::message::Options &getOptions() const;
    const std::vector<chat::Message> &getExtra() const;

    std::string &message();
    chat::message::Style &style();
    chat::message::Options &options();
    std::vector<chat::Message> &extra();

    // clang-format off
    /**
     * @brief Build and set a new hover event
     *
     * @tparam Event The event type to build
     * @tparam Args
     * @param args
     */
    template<isBaseOf<chat::message::event::OnHover> Event, typename... Args>
    void makeHoverEvent(Args&&... args)
    { this->_hoverEvent = std::make_shared<Event>(std::forward<Args>(args)...); }

    /**
     * @brief Build and set a new click event
     *
     * @tparam Event The event type to build
     * @tparam Args
     * @param args
     */
    template<isBaseOf<chat::message::event::OnClick> Event, typename... Args>
    void makeClickEvent(Args&&... args)
    { this->_clickEvent = std::make_shared<Event>(std::forward<Args>(args)...); }
    // clang-format on

    /**
     * @brief Set a new hover event
     *
     * @param event
     */
    void hoverEvent(const std::shared_ptr<const chat::message::event::OnHover> &event);

    /**
     * @brief Set a new click event
     *
     * @param event
     */
    void clickEvent(const std::shared_ptr<const chat::message::event::OnClick> &event);

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
    nlohmann::json toJson() const;

    /**
     * @brief Deserialize a message from a string
     *
     * @throw std::invalid_argument if the message is not a valid json string
     * @throw std::runtime_error if the parsing failed
     *
     * @param message
     * @return Message
     */
    static Message deserialize(const std::string &message);

    /**
     * @brief Deserialize a message from a json object
     *
     * @throw std::runtime_error if the parsing failed
     *
     * @param json
     * @return Message
     */
    static Message fromJson(const nlohmann::json &json);

    /**
     * @brief Create a message from a translation key
     *
     * @tparam key The translation key
     * @param player
     * @return Message
     */
    template<chat::message::TranslationKey key>
    static Message fromTranslationKey(Player &player)
    {
        return message::_detail::fromTranslationKey<key>(player);
    }

    /**
     * @brief Create a message from a translation key
     *
     * @tparam key The translation key
     * @param player
     * @param message
     * @return Message
     */
    template<chat::message::TranslationKey key>
    static Message fromTranslationKey(Player &player, const Message &message)
    {
        return message::_detail::fromTranslationKey<key>(player, message);
    }

private:
    std::string _message;
    chat::message::Style _style;
    chat::message::Options _options;
    std::vector<Message> _extra;
    std::shared_ptr<const chat::message::event::OnClick> _clickEvent;
    std::shared_ptr<const chat::message::event::OnHover> _hoverEvent;
};
} // namespace chat

#endif // CHAT_MESSAGE_HPP
