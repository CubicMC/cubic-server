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
chat::Message fromTranslationKey(Player &);
template<chat::message::TranslationKey key>
chat::Message fromTranslationKey(Player &player, const chat::Message &message);

template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeText>(Player &player, const chat::Message &message);
// template<>
// chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeEmote>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayIncoming>(Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayOutgoing>(Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeAnnouncement>(Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamSent>(Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(Player &player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerJoined>(Player &player);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerLeft>(Player &player);
} // namespace message::_detail
} // namespace chat::message

#endif // CHAT_TRANSLATIONKEY_HPP
