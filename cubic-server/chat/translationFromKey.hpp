#ifndef CHAT_TRANSLATIONKEY_HPP
#define CHAT_TRANSLATIONKEY_HPP

#include <cstdint>

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
} // namespace chat::message

#endif // CHAT_TRANSLATIONKEY_HPP
