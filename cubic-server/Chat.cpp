#include "Chat.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "nlohmann/json.hpp"
#include "chat/Message.hpp"

Chat::Chat() { }

void Chat::sendPlayerMessage(const chat::Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    this->_sendMessage(message, sender, chat::message::Type::Chat);
}

void Chat::sendSystemMessage(const chat::Message &message, bool overlay, const WorldGroup *worldGroup)
{
    if (worldGroup == nullptr) {
        LERROR("worldGroup is null");
        return;
    }
    LDEBUG("send System Message: ", message.getMessageComponent().getMessage());

    // TODO: Filter client by chat visibility
    for (const auto &[_, world] : worldGroup->getWorlds()) {
        for (auto &player : world->getPlayers())
            player->sendSystemChatMessage({message.serialize(), overlay});
    }
}

void Chat::sendSayMessage(const chat::Message &raw, const Player *from)
{
    if (from == nullptr) {
        LERROR("from is null");
        return;
    }

    auto message = chat::Message::fromTranslationKey<chat::message::TranslationKey::chat_type_announcement>(from, raw);

    this->_sendMessage(message, from, chat::message::Type::Announce);
}

void Chat::sendWhisperMessage(const chat::Message &message, Player *sender, Player *to)
{
    if (to == nullptr) {
        LERROR("to is null");
        return;
    }
    chat::Message out = chat::Message::fromTranslationKey<chat::message::TranslationKey::commands_message_display_outgoing>(message, sender, to);
    chat::Message in = chat::Message::fromTranslationKey<chat::message::TranslationKey::commands_message_display_incoming>(message, sender, to);

    this->_sendMessage(out, sender, chat::message::Type::WhisperOut);
    this->_sendMessage(in, to, chat::message::Type::WhisperIn);
}

void Chat::sendTellrawMessage(const chat::Message &message, const Player *from, const std::string &selector)
{
    this->_sendSystem(message, Server::getInstance()->getWorldGroup("default"));
}

void Chat::_sendMessage(const chat::Message &message, const Player *from, const chat::message::Type &type)
{
    protocol::PlayerChatMessage pck = {
        from->getUuid(),
        (int32_t) this->_messagesLog.size(),
        // TODO: Message signature
        false,
        {},
        "",
        std::time(nullptr),
        0,
        // TODO: Previous message signature
        {},
        true,
        message.serialize(),
        0,
        {},
        static_cast<int32_t>(type),
        chat::Message(from->getUsername()).serialize(),
        false,
    };

    // TODO: Change this to push_back the message signature when it's implemented
    this->_messagesLog.push_back(message);

    // TODO: Filter client by chat visibility
    for (auto &[_, world] : from->getDimension()->getWorld()->getWorldGroup()->getWorlds()) {
        for (auto &player : world->getPlayers())
            player->sendChatMessageResponse(pck);
    }
}

void Chat::_sendSystem(const chat::Message &message, const WorldGroup *worldGroup, bool overlay)
{
    for (const auto &[_, world] : worldGroup->getWorlds()) {
        for (auto &player : world->getPlayers())
            player->sendSystemChatMessage({message.serialize(), overlay});
    }
}

void Chat::_sendSystem(const chat::Message &message, Player *player, bool overlay)
{
    player->sendSystemChatMessage({message.serialize(), overlay});
}

void Chat::_sendSystem(const chat::Message &message, const std::vector<Player *> &players, bool overlay)
{
    for (auto &player : players)
        player->sendSystemChatMessage({message.serialize(), overlay});
}
