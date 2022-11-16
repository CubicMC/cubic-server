#ifndef CUBICSERVER_CHAT_HPP
#define CUBICSERVER_CHAT_HPP

#include <stdint.h>
#include <string>
#include "Logger.hpp"
#include "nlohmann/json.hpp"

class Player;
class Client;

namespace chat::message {
    enum class Type : int32_t {
        Chat = 0,
        System = 1,
        GameInfo = 2,
        Say = 3,
        Whisper = 4,
        Team = 5,
        Emote = 6, // Don't ask me...
        Tellraw = 7,
    };
    class ClickEvent {
    public:
        enum class Action : int32_t {
            OpenURL = 0,
            OpenFile = 1,
            RunCommand = 2,
            SuggestCommand = 3,
            ChangePage = 4,
            CopyToClipboard = 5,
        };

        ClickEvent(Action action, std::string_view value)
            : action(action), value(value), _log(logging::Logger::get_instance())
        {}
        nlohmann::json toJson() const;

    private:
        Action action;
        std::string_view value;
        logging::Logger *_log;
    };

    class HoverEvent {
    public:
        enum class Action : int32_t {
            ShowText = 0,
            ShowItem = 1,
            ShowEntity = 2,
        };

        HoverEvent(Action action, std::string_view value)
            : action(action), value(value), _log(logging::Logger::get_instance())
        {};
        nlohmann::json toJson() const;

    private:
        Action action;
        std::string_view value;
        logging::Logger *_log;
    };
}

namespace chat {
    class Message {
    public:
        struct Options {
            Options() = default;
            std::optional<bool> bold;
            std::optional<bool> italic;
            std::optional<bool> underlined;
            std::optional<bool> strikethrough;
            std::optional<bool> obfuscated;
            std::optional<std::string_view> font;
            std::optional<std::string_view> color;
            std::optional<std::string_view> insertion;
        };

    public:
        Message(
            const std::string &message,
            Options options = {},
            std::optional<chat::message::ClickEvent> clickEvent = std::nullopt,
            std::optional<chat::message::HoverEvent> hoverEvent = std::nullopt);

        std::string_view getMessage() const;
        Options getOptions() const;
        std::optional<chat::message::ClickEvent> getClickEvent() const;
        std::optional<chat::message::HoverEvent> getHoverEvent() const;
        std::vector<Message> getExtra() const;

        std::string &message();
        Options &options();
        std::optional<chat::message::ClickEvent> &clickEvent();
        std::optional<chat::message::HoverEvent> &hoverEvent();
        std::vector<Message> &extra();

        std::string serialize() const;
        nlohmann::json toJson() const;

    private:
        std::string _message;
        Options _options;
        std::optional<chat::message::ClickEvent> _clickEvent;
        std::optional<chat::message::HoverEvent> _hoverEvent;
        std::vector<Message> _extra;
    };

};

class Chat
{
public:
    Chat();

    void sendPlayerMessage(const chat::Message &message, const Player *sender);
    void sendSystemMessage(const chat::Message &message);
    void sendSayMessage(const chat::Message &message, const Player *sender);
    // Either keep client or change to Player but I need to get the client to send the message
    void sendMsgMessage(const chat::Message &message, Client *sender, Client *to);
    // void sendTeamMessage(const Message &message, const Player *sender, const std::string &team);
    // void sendEmoteMessage(const Message &message, const Player &sender);
    // TODO: Maybe more complicated than that, because of the selector (@a, @p, @r, @e, @s)
    // void sendTellrawMessage(const Message &message, const Player &sender);

private:
    std::unordered_map<chat::message::Type, chat::Message> _messagesLog;
    logging::Logger *_log;
};

#endif //CUBICSERVER_CHAT_HPP
