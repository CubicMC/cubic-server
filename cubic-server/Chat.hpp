#ifndef CUBICSERVER_CHAT_HPP
#define CUBICSERVER_CHAT_HPP

#include <functional>
#include <memory>
#include <nlohmann/json.hpp>

#include "chat/Message.hpp"

class Player;
class WorldGroup;

class Chat {
public:
    Chat();
    // TODO: Maybe more complicated than that, because of the selector (@a, @p, @r, @e, @s)

    /**
     * @brief Used to send a message to a player from the chat
     *
     * @param message
     * @param from
     */
    void sendPlayerMessage(const chat::Message &message, Player &from);

    /**
     * @brief Used to send a system message to a player from the server
     *
     * @param message
     * @param to
     * @param overlay A normal message will be displayed in the chat, an overlay message will be displayed in the middle of the screen
     */
    void sendSystemMessage(const chat::Message &message, Player &to, bool overlay = false);

    /**
     * @brief Used to send a system message to all players in a worldgroup
     *
     * @param message
     * @param worldGroup
     * @param overlay A normal message will be displayed in the chat, an overlay message will be displayed in the middle of the screen
     */
    void sendSystemMessage(const chat::Message &message, const WorldGroup &worldGroup, bool overlay = false);

    /**
     * @brief Used to send a system message to a list of players
     *
     * @param message
     * @param to
     * @param overlay A normal message will be displayed in the chat, an overlay message will be displayed in the middle of the screen
     */
    void sendSystemMessage(const chat::Message &message, const std::vector<std::reference_wrapper<Player>> &to, bool overlay = false);

    /**
     * @brief What is this?
     */
    // void sendGameInfoMessage(const chat::Message &message, const Player *from);

    /**
     * @brief Used by the /say command
     *
     * @param message
     * @param from
     */
    void sendSayMessage(const chat::Message &message, Player &from);

    /**
     * @brief Used to send a whisper message to a player
     *
     * @param message
     * @param from
     * @param to
     */
    void sendWhisperMessage(const chat::Message &message, Player &from, Player &to);

    /**
     * @brief Used to send a message to the player team
     *
     * @param message
     * @param sender
     */
    void sendTeamMessage(const chat::Message &message, Player &sender);

    /**
     * @brief What is this? ²
     *
     */
    // void sendEmoteMessage(const chat::Message &message, const Player *from);

    /**
     * @brief Used by the /tellraw command
     *
     * @param message
     * @param from
     * @param selector
     */
    void sendTellrawMessage(const chat::Message &message, Player &from, const std::string &selector);

private:
    void _sendMessage(const chat::Message &message, Player &from, Player &to, const chat::message::Type &type);
    void _sendMessage(const chat::Message &message, Player &from, const WorldGroup &, const chat::message::Type &type);
    void _sendMessage(const chat::Message &message, Player &from, const std::vector<std::reference_wrapper<Player>> &, const chat::message::Type &type);

    //! I am using the packet System Chat Message, but to send a system message the wiki says to use the packet Disguised Chat Message
    void _sendSystem(const chat::Message &message, const WorldGroup &worldGroup, bool overlay = false);
    void _sendSystem(const chat::Message &message, const std::vector<std::reference_wrapper<Player>> &players, bool overlay = false);
    void _sendSystem(const chat::Message &message, Player &player, bool overlay = false);

private:
    std::vector<chat::Message> _messagesLog;
};

#endif // CUBICSERVER_CHAT_HPP
