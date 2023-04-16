#include "Chat.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "nlohmann/json.hpp"
#include "chat/Message.hpp"

static protocol::PlayerChatMessage buildPacket(const Player *from, size_t messageLogSize, const chat::Message &message, const chat::message::Type &type)
{
    return protocol::PlayerChatMessage {
        from->getUuid(),
        (int32_t) messageLogSize,
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
}

Chat::Chat() { }

void Chat::sendPlayerMessage(const chat::Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    this->_sendMessage(message, sender, sender->getWorldGroup(), chat::message::Type::Chat);
}

void Chat::sendSystemMessage(const chat::Message &message, const Player *from, bool overlay)
{
    if (from == nullptr) {
        LERROR("from is null");
        return;
    }

    this->_sendSystem(message, from->getWorldGroup(), overlay);
}

void Chat::sendSayMessage(const chat::Message &raw, const Player *from)
{
    if (from == nullptr) {
        LERROR("from is null");
        return;
    }

    auto message = chat::Message::fromTranslationKey<chat::message::TranslationKey::chat_type_announcement>(from, raw);

    this->_sendMessage(message, from, from->getWorldGroup(), chat::message::Type::Announce);
}

void Chat::sendWhisperMessage(const chat::Message &message, Player *sender, Player *to)
{
    if (to == nullptr) {
        LERROR("to is null");
        return;
    } else if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    chat::Message in = chat::Message::fromTranslationKey<chat::message::TranslationKey::commands_message_display_incoming>(sender, message);
    chat::Message out = chat::Message::fromTranslationKey<chat::message::TranslationKey::commands_message_display_outgoing>(to, message);

    this->_sendMessage(out, sender, sender, chat::message::Type::WhisperOut);
    this->_sendMessage(in, sender, to, chat::message::Type::WhisperIn);
}

void Chat::sendTeamMessage(const chat::Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    // TODO: Change this when team chat is implemented
    this->_sendMessage(message, sender, sender->getWorldGroup(), chat::message::Type::TeamSent);
}

void Chat::sendTellrawMessage(const chat::Message &message, const Player *from, const std::string &selector)
{
    this->_sendSystem(message, from->getWorldGroup());
}

void Chat::_sendMessage(const chat::Message &message, const Player *from, Player *to, const chat::message::Type &type)
{
    protocol::PlayerChatMessage pck = buildPacket(from, this->_messagesLog.size(), message, type);

    // TODO: Change this to push_back the message signature when it's implemented
    this->_messagesLog.push_back(message);

    to->sendChatMessageResponse(pck);
}

void Chat::_sendMessage(const chat::Message &message, const Player *from, const WorldGroup *worldGroup, const chat::message::Type &type)
{
    protocol::PlayerChatMessage pck = buildPacket(from, this->_messagesLog.size(), message, type);

    // TODO: Change this to push_back the message signature when it's implemented
    this->_messagesLog.push_back(message);

    // TODO: Filter client by chat visibility
    for (auto &[_, world] : worldGroup->getWorlds()) {
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
