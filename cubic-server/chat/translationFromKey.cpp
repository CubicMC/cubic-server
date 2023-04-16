#include "Message.hpp"
#include "Player.hpp"


// template<>
// chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::multiplayer_player_joined, const Player *>(const Player *player)
// {
//     chat::Message message = chat::Message(
//         "",
//          { .color = "yellow" },
//         {
//          .insertion = "multiplayer.player.joined",
//          .with = std::vector<chat::Message>({chat::Message(
//              player->getUsername(),
//              {},
//              {},
//              chat::message::ClickEvent(chat::message::ClickEvent::Action::SuggestCommand, "/tell " + player->getUsername() + " "),
//              chat::message::HoverEvent(
//                  chat::message::HoverEvent::Action::ShowEntity,
//                  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
//              )
//          )})}
//     );
//     return message;
// }

// template<>
// chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::multiplayer_player_left>(const Player *player)
// {
//     Message message = chat::Message(
//         "",
//         {
//          { .color = "yellow" },
//          "",
//          "multiplayer.player.left",
//          std::vector<chat::Message>({chat::Message(
//              player->getUsername(),
//              {
//                  .insertion = player->getUsername(),
//              },
//              chat::message::ClickEvent(chat::message::ClickEvent::Action::SuggestCommand, "/tell " + player->getUsername()),
//              chat::message::HoverEvent(
//                  chat::message::HoverEvent::Action::ShowEntity,
//                  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
//              )
//          )})}
//     );
//     return message;
// }
