#ifndef CUBICSERVER_CHAT_HPP
#define CUBICSERVER_CHAT_HPP

#include <stdint.h>
#include <string>
#include "Logger.hpp"
#include "nlohmann/json.hpp"

enum class MsgType : int32_t {
    Chat = 0,
    System = 1,
    GameInfo = 2,
    Say = 3,
    Whisper = 4,
    Team = 5,
    Emote = 6, // Don't ask me...
    Tellraw = 7,
};

#include "Player.hpp"

class Chat
{
public:
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

    public:
        Message(
            const std::string &message,
            Options options = {},
            std::optional<ClickEvent> clickEvent = std::nullopt,
            std::optional<HoverEvent> hoverEvent = std::nullopt);

        std::string_view getMessage() const;
        Options getOptions() const;
        std::optional<ClickEvent> getClickEvent() const;
        std::optional<HoverEvent> getHoverEvent() const;
        std::vector<Message> getExtra() const;

        std::string &message();
        Options &options();
        std::optional<ClickEvent> &clickEvent();
        std::optional<HoverEvent> &hoverEvent();
        std::vector<Message> &extra();

        std::string serialize() const;
        nlohmann::json toJson() const;

    private:
        std::string _message;
        Options _options;
        std::optional<ClickEvent> _clickEvent;
        std::optional<HoverEvent> _hoverEvent;
        std::vector<Message> _extra;
    };

public:
    Chat();
    ~Chat();

    void sendPlayerMessage(const Message &message, const Player *sender);
    void sendSystemMessage(const Message &message);
    void sendSayMessage(const Message &message, const Player *sender);
    void sendMsgMessage(const Message &message, const Player *sender, const Player *to);
    // void sendTeamMessage(const Message &message, const Player *sender, const std::string &team);
    // void sendEmoteMessage(const Message &message, const Player &sender);
    // TODO: Maybe more complicated than that, because of the selector.
    // void sendTellrawMessage(const Message &message, const Player &sender);

private:
    std::unordered_map<MsgType, Message> _messagesLog;
    logging::Logger *_log;

};

#endif //CUBICSERVER_CHAT_HPP
