#ifndef CUBICSERVER_REGISTRY_CHAT_HPP
#define CUBICSERVER_REGISTRY_CHAT_HPP

#include "Registry.hpp"
#include "chat/Message.hpp"
#include <cstdint>

namespace registry {

class ChatElement : public Entry {
public:
    struct Parameters {
        std::vector<std::string> args;
        std::string key;
    };

public:
    inline ChatElement() = default;

    inline ChatElement &id(int32_t id);
    inline ChatElement &name(const std::string &name);
    inline ChatElement &addStyle(chat::message::Style style);

    inline ChatElement &addChatParameter(const std::string &name);
    inline ChatElement &addNarrateParameter(const std::string &name);

    inline ChatElement &chatKey(const std::string &key);
    inline ChatElement &narrateKey(const std::string &key);

    std::shared_ptr<nbt::Base> toNBT() const override;
    inline bool operator==(const std::string &name) const override { return name == _name; }

private:
    int32_t _id;
    std::string _name;
    Parameters _chat;
    chat::message::Style _style;
    Parameters _narrate;
};

DEFINE_REGISTRY_CLASS(Chat, "minecraft:chat_type");

inline void setupDefaultsChat(Chat &registry);

} // namespace registry

inline registry::ChatElement &registry::ChatElement::id(int32_t id)
{
    _id = id;
    return *this;
}

inline registry::ChatElement &registry::ChatElement::name(const std::string &name)
{
    _name = name;
    return *this;
}

inline registry::ChatElement &registry::ChatElement::addStyle(chat::message::Style style)
{
    this->_style = style;
    return *this;
}

inline registry::ChatElement &registry::ChatElement::addChatParameter(const std::string &name)
{
    _chat.args.push_back(name);
    return *this;
}
inline registry::ChatElement &registry::ChatElement::addNarrateParameter(const std::string &name)
{
    _narrate.args.push_back(name);
    return *this;
}

inline registry::ChatElement &registry::ChatElement::chatKey(const std::string &key)
{
    _chat.key = key;
    return *this;
}
inline registry::ChatElement &registry::ChatElement::narrateKey(const std::string &key)
{
    _narrate.key = key;
    return *this;
}

inline void registry::setupDefaultsChat(registry::Chat &registry)
{
    // clang-format off

    // Chat message
    registry.addEntry()
        .id(chat::message::Type::Chat)
        .name("minecraft:chat")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.text")
        .narrateKey("chat.type.text.narrate");

    // Emote message (lol)
    registry.addEntry()
        .id(chat::message::Type::Emote)
        .name("minecraft:emote_command")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.emote")
        .narrateKey("chat.type.emote");

    // Whisper message incoming
    registry.addEntry()
        .id(chat::message::Type::WhisperIn)
        .name("minecraft:msg_command_incoming")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("commands.message.display.incoming")
        .narrateKey("chat.type.text.narrate")
        .addStyle({
            .italic = true,
            .color = "gray",
        });

    // Whisper message outgoing
    registry.addEntry()
        .id(chat::message::Type::WhisperOut)
        .name("minecraft:msg_command_outgoing")
        .addChatParameter("target")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("commands.message.display.outgoing")
        .narrateKey("chat.type.text.narrate")
        .addStyle({
            .italic = true,
            .color = "gray",
        });

    // say message
    registry.addEntry()
        .id(chat::message::Type::Announce)
        .name("minecraft:say_command")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.announcement")
        .narrateKey("chat.type.text.narrate");

    // Chat team message incoming
    registry.addEntry()
        .id(chat::message::Type::TeamText)
        .name("minecraft:team_msg_command_incoming")
        .addChatParameter("target")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.team.text")
        .narrateKey("chat.type.text.narrate");

    // Chat team message outgoing
    registry.addEntry()
        .id(chat::message::Type::TeamSent)
        .name("minecraft:team_msg_command_outgoing")
        .addChatParameter("target")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.team.sent")
        .narrateKey("chat.type.text.narrate");

    // clang-format on
}

#endif // CUBICSERVER_REGISTRY_CHAT_HPP
