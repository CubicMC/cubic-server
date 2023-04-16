#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <memory>

#include "SimpleMessage.hpp"
#include "events/Hover.hpp"
#include "events/Click.hpp"

#include "concept.hpp"

class Player;

namespace chat {

class Message {
private:
    Message(const SimpleMessage &messageComponent);

public:
    Message(
        const std::string &message = "", const chat::message::Style &style = {}, const chat::message::Options &options = {}, const std::optional<std::shared_ptr<chat::message::event::OnClick>> &clickEvent = std::nullopt,
        const std::optional<std::shared_ptr<chat::message::event::OnHover>> &hoverEvent = std::nullopt
    );

    Message(
        const char message[], const chat::message::Style &style = {}, const chat::message::Options &options = {}, const std::optional<std::shared_ptr<chat::message::event::OnClick>> &clickEvent = std::nullopt,
        const std::optional<std::shared_ptr<chat::message::event::OnHover>> &hoverEvent = std::nullopt
    );
    ~Message() = default;

    const std::optional<std::shared_ptr<chat::message::event::OnHover>> &getHoverEvent() const;
    const std::optional<std::shared_ptr<chat::message::event::OnClick>> &getClickEvent() const;
    const SimpleMessage &getMessageComponent() const;
    const std::vector<chat::Message> &getExtra() const;

    template<is_base_of<chat::message::event::OnHover> Event, typename... Args>
    void makeHoverEvent(Args... args) { this->_hoverEvent = std::make_shared<Event>(std::forward<Args>(args)...); }
    template<is_base_of<chat::message::event::OnClick> Event, typename... Args>
    void makeClickEvent(Args... args) { this->_clickEvent = std::make_shared<Event>(std::forward<Args>(args)...); }

    void hoverEvent(const std::optional<std::shared_ptr<chat::message::event::OnHover>> &event);
    void clickEvent(const std::optional<std::shared_ptr<chat::message::event::OnClick>> &event);
    SimpleMessage &messageComponent();
    std::vector<chat::Message> &extra();

    nlohmann::json toJson() const;
    std::string serialize() const;

    static Message deserialize(const std::string &message);
    static Message fromJson(const nlohmann::json &json);
    template<chat::message::TranslationKey key, typename... Args>
    static Message fromTranslationKey(Args... args);

private:
    SimpleMessage _messageComponent;
    std::optional<std::shared_ptr<chat::message::event::OnClick>> _clickEvent;
    std::optional<std::shared_ptr<chat::message::event::OnHover>> _hoverEvent;
    std::vector<Message> _extra;
};

template<>
Message Message::fromTranslationKey<message::TranslationKey::chat_type_text>(const Player *player, const std::string &message);
// template<>
// Message Message::fromTranslationKey<message::TranslationKey::chat_type_emote>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::commands_message_display_incoming>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::commands_message_display_outgoing>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::chat_type_announcement>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::chat_type_team_text>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::chat_type_team_sent>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::chat_type_team_text>(const Player *player, const std::string &message);
template<>
Message Message::fromTranslationKey<message::TranslationKey::multiplayer_player_joined>(const Player *player);
template<>
Message Message::fromTranslationKey<message::TranslationKey::multiplayer_player_left>(const Player *player);
} // namespace chat

#endif // CHAT_MESSAGE_HPP
