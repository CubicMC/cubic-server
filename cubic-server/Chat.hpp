#ifndef CUBICSERVER_CHAT_HPP
#define CUBICSERVER_CHAT_HPP

#include <stdint.h>
#include <string>
#include "logging/Logger.hpp"
#include "nlohmann/json.hpp"

class Player;
class Client;
class WorldGroup;

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

    private:
        ClickEvent() = default;

    public:
        ClickEvent(Action action, const std::string &value)
            : action(action), value(value)
        {}
        nlohmann::json toJson() const;

        static ClickEvent deserialize(const std::string &json);
        static ClickEvent fromJson(const nlohmann::json &json);

    private:
        Action action;
        std::string value;
    };

    class HoverEvent {
    public:
        enum class Action : int32_t {
            ShowText = 0,
            ShowItem = 1,
            ShowEntity = 2,
        };

    private:
        HoverEvent() = default;

    public:
        HoverEvent(Action action, const std::string &value)
            : action(action), value(value)
        {};
        nlohmann::json toJson() const;

        static HoverEvent deserialize(const std::string &json);
        static HoverEvent fromJson(const nlohmann::json &json);

    private:
        Action action;
        std::string value;
    };
}

namespace chat {
    class Message {
    public:
        struct Options {
            // Options() = default;
            std::optional<bool> bold;
            std::optional<bool> italic;
            std::optional<bool> underlined;
            std::optional<bool> strikethrough;
            std::optional<bool> obfuscated;
            std::optional<std::string> font;
            std::optional<std::string> color;
            std::optional<std::string> insertion;
            std::optional<std::string> translate;
            std::optional<std::vector<Message>> with;
        };

    private:
        Message() = default;

    public:
        Message(
            const std::string &message,
            Options options = {},
            std::optional<chat::message::ClickEvent> clickEvent = std::nullopt,
            std::optional<chat::message::HoverEvent> hoverEvent = std::nullopt);

        Message(
            const char message[],
            Options options = {},
            std::optional<chat::message::ClickEvent> clickEvent = std::nullopt,
            std::optional<chat::message::HoverEvent> hoverEvent = std::nullopt);

        std::string getMessage() const;
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

        static Message deserialize(const std::string &message);
        static Message fromJson(const nlohmann::json &json);

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

#endif //CUBICSERVER_CHAT_HPP
