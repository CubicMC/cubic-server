#include "translationFromKey.hpp"

#include "Message.hpp"
#include "Player.hpp"
#include "events.hpp"
#include "logging/logging.hpp"

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerJoined>(const Player &player)
{
    chat::Message message = chat::Message();
    chat::Message userName = chat::Message(player.getUsername());

    // TODO: Change this to check for the team color
    if (player.getUsername() == "STMiki")
        userName.style().color = "gold";

    userName.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    userName.makeHoverEvent<chat::message::event::EntityHover>(player);

    message.style().color = "yellow";
    message.options().translate = "multiplayer.player.joined";
    message.options().with = std::vector<chat::Message>({userName});

    return message;
}

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerLeft>(const Player &player)
{
    chat::Message message = chat::Message();
    chat::Message userName = chat::Message(player.getUsername());

    // TODO: Change this to check for the team color
    if (player.getUsername() == "STMiki")
        userName.style().color = "gold";

    userName.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    userName.makeHoverEvent<chat::message::event::EntityHover>(player);

    message.style().color = "yellow";
    message.options().translate = "multiplayer.player.left";
    message.options().with = std::vector<chat::Message>({userName});

    return message;
}

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayIncoming>(const Player &player, const chat::Message &message)
{
    auto response = chat::Message();
    auto sender = chat::Message(player.getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(player);

    response.options().translate = "commands.message.display.incoming";
    response.options().with = std::vector<chat::Message>({sender, message});

    return response;
}

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::CommandsMessageDisplayOutgoing>(const Player &player, const chat::Message &message)
{
    auto response = chat::Message();
    auto sender = chat::Message(player.getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    //  "{\"type\": \"minecraft:player\", \"id\": \"" + player.getUuidString() + "\", \"name\": \"" + player.getUsername() + "\"}"
    sender.makeHoverEvent<chat::message::event::EntityHover>(player);

    response.options().translate = "commands.message.display.outgoing";
    response.options().with = std::vector<chat::Message>({sender, message});

    return response;
}

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::ChatTypeAnnouncement>(const Player &player, const chat::Message &message)
{
    auto response = chat::Message();
    auto sender = chat::Message(player.getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(player);

    response.options().translate = "chat.type.announcement";
    response.options().with = std::vector<chat::Message>({sender, message});

    return response;
}

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamText>(const Player &player, const chat::Message &message)
{
    auto response = chat::Message();
    auto team = chat::Message(/* player.getTeam() */ "TEAM CUCK");
    auto sender = chat::Message(player.getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(player);

    response.options().translate = "chat.type.team.text";
    response.options().with = std::vector<chat::Message>({team, sender, message});

    return response;
}

template<>
chat::Message chat::message::_detail::fromTranslationKey<chat::message::TranslationKey::ChatTypeTeamSent>(const Player &player, const chat::Message &message)
{
    auto response = chat::Message();
    auto team = chat::Message(/* player.getTeam() */ "TEAM CUCK");
    auto sender = chat::Message(player.getUsername());

    sender.makeClickEvent<chat::message::event::SuggestCommandClick>("/tell " + player.getUsername() + " ");
    sender.makeHoverEvent<chat::message::event::EntityHover>(player);

    response.options().translate = "chat.type.team.sent";
    response.options().with = std::vector<chat::Message>({team, sender, message});

    return response;
}
