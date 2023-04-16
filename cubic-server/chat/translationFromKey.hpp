#ifndef CHAT_TRANSLATIONKEY_HPP
#define CHAT_TRANSLATIONKEY_HPP

#include <cstdint>

class Player;
namespace chat {
class Message;
} // namespace chat

namespace chat::message {
enum TranslationKey : int32_t {
    chat_type_text = 0,
    chat_type_emote,
    commands_message_display_incoming,
    commands_message_display_outgoing,
    chat_type_announcement,
    chat_type_team_text,
    chat_type_team_sent,
    multiplayer_player_left,
    multiplayer_player_joined,
};

namespace _detail {
template<chat::message::TranslationKey key>
chat::Message fromTranslationKey(const Player *);
template<chat::message::TranslationKey key>
chat::Message fromTranslationKey(const Player *player, const chat::Message &message);

template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::chat_type_text>(const Player *player, const chat::Message &message);
// template<>
// chat::Message fromTranslationKey<chat::message::TranslationKey::chat_type_emote>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::commands_message_display_incoming>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::commands_message_display_outgoing>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::chat_type_announcement>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::chat_type_team_text>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::chat_type_team_sent>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::chat_type_team_text>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::multiplayer_player_joined>(const Player *player);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::multiplayer_player_left>(const Player *player);
} // namespace message::_detail
} // namespace chat::message

#endif // CHAT_TRANSLATIONKEY_HPP
