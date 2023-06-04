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
chat::Message fromTranslationKey(std::shared_ptr<Player> );
template<chat::message::TranslationKey key>
chat::Message fromTranslationKey(std::shared_ptr<Player> player, const chat::Message &message);

template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeText>(std::shared_ptr<Player> player, const chat::Message &message);
// template<>
// chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeEmote>(const Player *player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayIncoming>(std::shared_ptr<Player> player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayOutgoing>(std::shared_ptr<Player> player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeAnnouncement>(std::shared_ptr<Player> player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(std::shared_ptr<Player> player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamSent>(std::shared_ptr<Player> player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(std::shared_ptr<Player> player, const chat::Message &message);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerJoined>(std::shared_ptr<Player> player);
template<>
chat::Message fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerLeft>(std::shared_ptr<Player> player);
} // namespace message::_detail
} // namespace chat::message

#endif // CHAT_TRANSLATIONKEY_HPP
