#ifndef CHAT_REGISTRY_HPP
#define CHAT_REGISTRY_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "chat/Message.hpp"
#include "nbt.hpp"

namespace chat::_details {

std::shared_ptr<nbt::Compound> getChatRegistry();

class ChatType {
public:
    typedef struct {
        std::vector<std::string> args;
        std::string key;
    } parameters_t;

public:
    constexpr ChatType() = default;

    constexpr ChatType &id(int32_t id);
    constexpr ChatType &name(const std::string &name);
    constexpr ChatType &addStyle(chat::message::Style style);

    constexpr ChatType &addChatParameter(const std::string &name);
    constexpr ChatType &addNarrateParameter(const std::string &name);

    constexpr ChatType &chatKey(const std::string &key);
    constexpr ChatType &narrateKey(const std::string &key);

    std::shared_ptr<nbt::Compound> toNBT() const;

private:
    int32_t _id;
    std::string _name;
    parameters_t _chat;
    chat::message::Style _style;
    parameters_t _narrate;
};

class Registry {
public:
    constexpr Registry() = default;

    constexpr Registry &addChatType(const ChatType &chatType);

    std::shared_ptr<nbt::Compound> toNBT() const;

private:
    std::vector<ChatType> _chatTypes;
};

constexpr ChatType &ChatType::id(int32_t id)
{
    _id = id;
    return *this;
}

constexpr ChatType &ChatType::name(const std::string &name)
{
    _name = name;
    return *this;
}

constexpr ChatType &ChatType::addStyle(chat::message::Style style)
{
    this->_style = style;
    return *this;
}

constexpr ChatType &ChatType::addChatParameter(const std::string &name)
{
    _chat.args.push_back(name);
    return *this;
}
constexpr ChatType &ChatType::addNarrateParameter(const std::string &name)
{
    _narrate.args.push_back(name);
    return *this;
}

constexpr ChatType &ChatType::chatKey(const std::string &key)
{
    _chat.key = key;
    return *this;
}
constexpr ChatType &ChatType::narrateKey(const std::string &key)
{
    _narrate.key = key;
    return *this;
}

constexpr Registry &Registry::addChatType(const ChatType &chatType)
{
    _chatTypes.push_back(chatType);
    return *this;
}

} // namespace chat::_details

#endif // CHAT_REGISTRY_HPP
