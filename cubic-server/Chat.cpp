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
    LDEBUG("send System Message: ", message.getMessage()); // FUCKING CRASHES THE SERVER BECAUSE I DON'T FUCKING KNOW

    // TODO: Filter client by chat visibility
    for (const auto &[_, world] : worldGroup->getWorlds()) {
        for (auto &player : world->getPlayers())
            player->sendSystemChatMessage({message.serialize(), overlay});
    }
}

void Chat::sendWhisperMessage(const chat::Message &message, Player *sender, Player *to)
{
    if (to == nullptr) {
        LERROR("to is null");
        return;
    }
    // chat::Message out = chat::Message::fromTranslationKey<chat::TranslationKey::commands_message_display_outgoing>(message, sender, to);
    // chat::Message in = chat::Message::fromTranslationKey<chat::TranslationKey::commands_message_display_incoming>(message, sender, to);

    // this->_sendMessage(message, sender, chat::message::Type::Chat);
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
        // TODO: Previous message
        {},
        true,
        message.serialize(),
        0,
        {},
        static_cast<int32_t>(type),
        chat::Message(from->getUsername()).serialize(),
        false,
    };

    this->_messagesLog.push_back(message);

    // TODO: Filter client by chat visibility
    for (auto &[_, world] : from->getDimension()->getWorld()->getWorldGroup()->getWorlds()) {
        for (auto &player : world->getPlayers())
            player->sendChatMessageResponse(pck);
    }
}
