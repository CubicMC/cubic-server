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

    // TODO: Filter client by chat visibility
    for (auto &[_, world] : sender->getDimension()->getWorld()->getWorldGroup()->getWorlds()) {
        for (auto &player : world->getPlayers()) {
            // if (player == sender)
            //     continue;
            player->sendChatMessageResponse({
                sender->getUuid(),
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
                0, // TODO: ???
                ::chat::Message(sender->getUsername()).serialize(),
                false,
            });
        }
    }
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

void Chat::sendSayMessage(const chat::Message &message, const Player *sender)
{
    if (sender == nullptr) {
        LERROR("sender is null");
        return;
    }

    // TODO: Filter client by chat visibility
    for (auto &[_, world] : sender->getDimension()->getWorld()->getWorldGroup()->getWorlds()) {
        for (auto &player : world->getPlayers()) {
            player->sendChatMessageResponse({
                sender->getUuid(),
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
                0, // TODO: ???
                "Network Name",
                false,
            });
        }
    }
}

void Chat::sendMsgMessage(const chat::Message &message, Player *sender, Player *to)
{
    if (to == nullptr) {
        LERROR("to is null");
        return;
    }
    chat::Message msg = "[" + sender->getUsername() + "]";
    msg.extra().push_back(message);

    to->sendSystemChatMessage({
        msg.serialize(),
        false,
    });
}
