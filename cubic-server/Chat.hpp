#ifndef CUBICSERVER_CHAT_HPP
#define CUBICSERVER_CHAT_HPP

#include "logging/Logger.hpp"
#include "nlohmann/json.hpp"
#include <stdint.h>
#include <string>
#include <optional>
#include "chat/Message.hpp"

class Player;
class Client;
class WorldGroup;

class Chat {
public:
    Chat();

    void sendPlayerMessage(const chat::Message &message, const Player *sender);
    void sendSystemMessage(const chat::Message &message, bool overlay, const WorldGroup *worldGroup);
    void sendSayMessage(const chat::Message &message, const Player *sender);
    // Either keep client or change to Player but I need to get the client to send the message
    void sendMsgMessage(const chat::Message &message, Player *sender, Player *to);
    // void sendTeamMessage(const Message &message, const Player *sender, const std::string &team);
    // void sendEmoteMessage(const Message &message, const Player &sender);
    // TODO: Maybe more complicated than that, because of the selector (@a, @p, @r, @e, @s)
    // void sendTellrawMessage(const Message &message, const Player &sender);

private:
    std::unordered_map<chat::message::Type, chat::Message> _messagesLog;
};

#endif // CUBICSERVER_CHAT_HPP
