#include "ChatRegistry.hpp"

std::shared_ptr<nbt::Compound> chat::_details::ChatType::toNBT() const
{
    auto chatParameters = std::make_shared<nbt::List>("parameters");
    auto narrateParameters = std::make_shared<nbt::List>("parameters");

    for (const auto &arg : this->_chat.args)
        chatParameters->push_back(std::make_shared<nbt::String>("", arg));

    for (const auto &arg : this->_narrate.args)
        narrateParameters->push_back(std::make_shared<nbt::String>("", arg));

    auto style = std::shared_ptr<nbt::Compound>(new nbt::Compound("style", {}));

    if (_style.bold.has_value())
        style->addValue(std::make_shared<nbt::Byte>("bold", _style.bold.value()));
    if (_style.italic.has_value())
        style->addValue(std::make_shared<nbt::Byte>("italic", _style.italic.value()));
    if (_style.underlined.has_value())
        style->addValue(std::make_shared<nbt::Byte>("underlined", _style.underlined.value()));
    if (_style.strikethrough.has_value())
        style->addValue(std::make_shared<nbt::Byte>("strikethrough", _style.strikethrough.value()));
    if (_style.obfuscated.has_value())
        style->addValue(std::make_shared<nbt::Byte>("obfuscated", _style.obfuscated.value()));
    if (_style.font.has_value())
        style->addValue(std::make_shared<nbt::String>("font", _style.font.value()));
    if (_style.color.has_value())
        style->addValue(std::make_shared<nbt::String>("color", _style.color.value()));

    auto chat = std::shared_ptr<nbt::Compound>(new nbt::Compound("chat", {std::make_shared<nbt::String>("translation_key", this->_chat.key), chatParameters}));

    if (style->size() <= 0) {
        style = nullptr;
    } else
        chat->addValue(style);
    // clang-format off
    return std::shared_ptr<nbt::Compound>(new nbt::Compound("", {
            std::make_shared<nbt::Int>("id", this->_id),
            std::make_shared<nbt::String>("name", this->_name),
            std::shared_ptr<nbt::Compound>(new nbt::Compound("element", {
                    chat,
                    std::shared_ptr<nbt::Compound>(new nbt::Compound("narration", {
                        std::make_shared<nbt::String>("translation_key", this->_narrate.key),
                        narrateParameters
                    })),
                }
            )),
        }
    ));
    // clang-format on
}

std::shared_ptr<nbt::Compound> chat::_details::Registry::toNBT() const
{
    auto values = std::make_shared<nbt::List>("value");

    for (const auto &chatType : _chatTypes)
        values->push_back(chatType.toNBT());

    return std::shared_ptr<nbt::Compound>(new nbt::Compound("minecraft:chat_type", {std::make_shared<nbt::String>("type", "minecraft:chat_type"), values}));
}

/**
 * @brief Generate the chat registry
 *
 * @return nbt::Compound*
 */
std::shared_ptr<nbt::Compound> chat::_details::getChatRegistry()
{
    chat::_details::Registry registry;

    // Chat message
    chat::_details::ChatType chatType;
    // clang-format off
    chatType
        .id(chat::message::Type::Chat)
        .name("minecraft:chat")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.text")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(chatType);

    // Emote message (lol)
    chat::_details::ChatType emoteType;
    emoteType
        .id(chat::message::Type::Emote)
        .name("minecraft:emote_command")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.emote")
        .narrateKey("chat.type.emote");

    registry.addChatType(emoteType);

    // Whisper message incoming
    chat::_details::ChatType whisperIncomingType;
    whisperIncomingType
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

    registry.addChatType(whisperIncomingType);

    // Whisper message outgoing
    chat::_details::ChatType whisperOutgoingType;
    whisperOutgoingType
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

    registry.addChatType(whisperOutgoingType);

    // say message
    chat::_details::ChatType sayType;
    sayType
        .id(chat::message::Type::Announce)
        .name("minecraft:say_command")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.announcement")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(sayType);

    // Chat team message incoming
    chat::_details::ChatType teamIncomingType;
    teamIncomingType
        .id(chat::message::Type::TeamText)
        .name("minecraft:team_msg_command_incoming")
        .addChatParameter("target")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.team.text")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(teamIncomingType);

    // Chat team message outgoing
    chat::_details::ChatType teamOutgoingType;
    teamOutgoingType
        .id(chat::message::Type::TeamSent)
        .name("minecraft:team_msg_command_outgoing")
        .addChatParameter("target")
        .addChatParameter("sender")
        .addChatParameter("content")
        .addNarrateParameter("sender")
        .addNarrateParameter("content")
        .chatKey("chat.type.team.sent")
        .narrateKey("chat.type.text.narrate");

    registry.addChatType(teamOutgoingType);
    // clang-format on
    return registry.toNBT();
}
