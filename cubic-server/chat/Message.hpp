#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdint>
#include <memory>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <vector>

#include "SimpleMessage.hpp"
#include "events/Click.hpp"
#include "events/Hover.hpp"
#include "translationFromKey.hpp"

#include "concept.hpp"

class Player;

namespace chat {

/**
 * @brief A message that can be sent to a player
 */
class Message {
private:
    Message(const SimpleMessage &messageComponent);

public:
    Message(
        const std::string &message = "", const chat::message::Style &style = {}, const chat::message::Options &options = {},
        const std::shared_ptr<chat::message::event::OnClick> &clickEvent = nullptr, const std::shared_ptr<chat::message::event::OnHover> &hoverEvent = nullptr
    );

    Message(
        const char message[], const chat::message::Style &style = {}, const chat::message::Options &options = {},
        const std::shared_ptr<chat::message::event::OnClick> &clickEvent = nullptr, const std::shared_ptr<chat::message::event::OnHover> &hoverEvent = nullptr
    );
    ~Message() = default;

    const std::shared_ptr<chat::message::event::OnHover> &getHoverEvent() const;
    const std::shared_ptr<chat::message::event::OnClick> &getClickEvent() const;
    const SimpleMessage &getMessageComponent() const;

    // clang-format off
    /**
     * @brief Build and set a new hover event
     *
     * @tparam Event The event type to build
     * @tparam Args
     * @param args
     */
    template<IsBaseOf<chat::message::event::OnHover> Event, typename... Args>
    void makeHoverEvent(Args... args)
    { this->_hoverEvent = std::make_shared<Event>(std::forward<Args>(args)...); }

    /**
     * @brief Build and set a new click event
     *
     * @tparam Event The event type to build
     * @tparam Args
     * @param args
     */
    template<IsBaseOf<chat::message::event::OnClick> Event, typename... Args>
    void makeClickEvent(Args... args)
    { this->_clickEvent = std::make_shared<Event>(std::forward<Args>(args)...); }
    // clang-format on

    /**
     * @brief Set a new hover event
     *
     * @param event
     */
    void hoverEvent(const std::shared_ptr<chat::message::event::OnHover> &event);

    /**
     * @brief Set a new click event
     *
     * @param event
     */
    void clickEvent(const std::shared_ptr<chat::message::event::OnClick> &event);
    SimpleMessage &messageComponent();

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
    static Message fromTranslationKey(const Player *player)
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
    static Message fromTranslationKey(const Player *player, const Message &message)
    {
        return message::_detail::fromTranslationKey<key>(player, message);
    }

private:
    SimpleMessage _messageComponent;
    std::shared_ptr<chat::message::event::OnClick> _clickEvent;
    std::shared_ptr<chat::message::event::OnHover> _hoverEvent;
};
} // namespace chat

#endif // CHAT_MESSAGE_HPP
