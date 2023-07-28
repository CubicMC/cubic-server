#ifndef CHAT_TRANSLATIONKEY_HPP
#define CHAT_TRANSLATIONKEY_HPP

#include <cstdint>
#include <memory>

class Player;
namespace chat {
class Message;
} // namespace chat

namespace chat::message {
enum TranslationKey : int32_t {
    ChatTypeText = 0,
    ChatTypeEmote,
    CommandsMessageDisplayIncoming,
    CommandsMessageDisplayOutgoing,
    ChatTypeAnnouncement,
    ChatTypeTeamText,
    ChatTypeTeamSent,
    MultiplayerPlayerLeft,
    MultiplayerPlayerJoined,
};

namespace _detail {
template<chat::message::TranslationKey key>
chat::Message fromTranslationKey(const Player &);
template<chat::message::TranslationKey key>
chat::Message fromTranslationKey(const Player &player, const chat::Message &message);

template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeText>(const Player &player, const chat::Message &message);
// template<>
// chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeEmote>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayIncoming>(const Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayOutgoing>(const Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeAnnouncement>(const Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(const Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamSent>(const Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(const Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerJoined>(const Player &player);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerLeft>(const Player &player);
} // namespace message::_detail
} // namespace chat::message

#endif // CHAT_TRANSLATIONKEY_HPP
