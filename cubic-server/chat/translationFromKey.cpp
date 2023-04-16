#include "Message.hpp"
#include "Player.hpp"
#include "events.hpp"

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::multiplayer_player_joined, const Player *>(const Player *player)
{
    chat::Message message = chat::Message();
    chat::Message userName = chat::Message(player->getUsername());

    userName.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    userName.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    message.messageComponent().style().color = "yellow";
    message.messageComponent().options().translate = "multiplayer.player.joined";
    message.messageComponent().options().with = std::vector<chat::Message>({ userName });

    return message;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::multiplayer_player_left>(const Player *player)
{
    chat::Message message = chat::Message();
    chat::Message userName = chat::Message(player->getUsername());

    userName.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    userName.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    message.messageComponent().style().color = "yellow";
    message.messageComponent().options().translate = "multiplayer.player.left";
    message.messageComponent().options().with = std::vector<chat::Message>({ userName });

    return message;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::commands_message_display_incoming>(const Player *player, const std::string &message)
{
    auto response = chat::Message();
    auto sender = chat::Message(player->getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    response.messageComponent().options().translate = "commands.message.display.incoming";
    response.messageComponent().options().with = std::vector<chat::Message>({ sender, chat::Message(message) });

    return response;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::commands_message_display_outgoing>(const Player *player, const std::string &message)
{
    auto response = chat::Message();
    auto sender = chat::Message(player->getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    response.messageComponent().options().translate = "commands.message.display.outgoing";
    response.messageComponent().options().with = std::vector<chat::Message>({ sender, chat::Message(message) });

    return response;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::chat_type_announcement>(const Player *player, const std::string &message)
{
    auto response = chat::Message();
    auto sender = chat::Message(player->getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    response.messageComponent().options().translate = "chat.type.announcement";
    response.messageComponent().options().with = std::vector<chat::Message>({ sender, chat::Message(message) });

    return response;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::chat_type_team_text>(const Player *player, const std::string &message)
{
    auto response = chat::Message();
    auto team = chat::Message(/* player->getTeam() */ "TEAM CUCK");
    auto sender = chat::Message(player->getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    response.messageComponent().options().translate = "chat.type.team.text";
    response.messageComponent().options().with = std::vector<chat::Message>({ team, sender, chat::Message(message) });

    return response;
}

template<>
chat::Message chat::Message::fromTranslationKey<chat::message::TranslationKey::chat_type_team_sent>(const Player *player, const std::string &message)
{
    auto response = chat::Message();
    auto team = chat::Message(/* player->getTeam() */ "TEAM CUCK");
    auto sender = chat::Message(player->getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player->getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(
        //  "{\"type\": \"minecraft:player\", \"id\": \"" + player->getUuidString() + "\", \"name\": \"" + player->getUsername() + "\"}"
    );

    response.messageComponent().options().translate = "chat.type.team.sent";
    response.messageComponent().options().with = std::vector<chat::Message>({ team, sender, chat::Message(message) });

    return response;
}
