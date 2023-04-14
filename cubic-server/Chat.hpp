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

    // TODO: Maybe more complicated than that, because of the selector (@a, @p, @r, @e, @s)
    void sendPlayerMessage(const chat::Message &message, const Player *from);
    void sendSystemMessage(const chat::Message &message, bool overlay, const WorldGroup *worldGroup);
    // void sendGameInfoMessage(const chat::Message &message, const Player *from);
    void sendSayMessage(const chat::Message &message, const Player *from);
    void sendWhisperMessage(const chat::Message &message, Player *from, Player *to);
    // void sendTeamMessage(const chat::Message &message, const Player *sender);
    // void sendEmoteMessage(const chat::Message &message, const Player *from);
    void sendTellrawMessage(const chat::Message &message, const std::string &selector);

private:
    void _sendMessage(const chat::Message &message, const Player *from, const chat::message::Type &type);
    void _sendSystem(const chat::Message &message, const WorldGroup *worldGroup, bool overlay);
    void _sendSystem(const chat::Message &message, const Player *player, bool overlay);
    void _sendSystem(const chat::Message &message, const std::vector<Player *> &players, bool overlay);

private:
    std::vector<chat::Message> _messagesLog;
};

#endif // CUBICSERVER_CHAT_HPP
