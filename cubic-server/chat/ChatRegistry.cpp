#include "ChatRegistry.hpp"

nbt::Compound *chat::_details::ChatType::toNBT() const
{
    auto chatParameters = new nbt::List("parameters");
    auto narrateParameters = new nbt::List("parameters");

    for (const auto &arg : this->_chat.args)
        chatParameters->push_back(new nbt::String("", arg));

    for (const auto &arg : this->_narrate.args)
        narrateParameters->push_back(new nbt::String("", arg));

    auto style = new nbt::Compound("style", {});

    if (_style.bold.has_value())
        style->addValue(new nbt::Byte("bold", _style.bold.value()));
    if (_style.italic.has_value())
        style->addValue(new nbt::Byte("italic", _style.italic.value()));
    if (_style.underlined.has_value())
        style->addValue(new nbt::Byte("underlined", _style.underlined.value()));
    if (_style.strikethrough.has_value())
        style->addValue(new nbt::Byte("strikethrough", _style.strikethrough.value()));
    if (_style.obfuscated.has_value())
        style->addValue(new nbt::Byte("obfuscated", _style.obfuscated.value()));
    if (_style.font.has_value())
        style->addValue(new nbt::String("font", _style.font.value()));
    if (_style.color.has_value())
        style->addValue(new nbt::String("color", _style.color.value()));

    auto chat = new nbt::Compound("chat", {
        new nbt::String("translation_key", this->_chat.key),
        chatParameters
    });

    if (style->size() <= 0) {
        delete style;
        style = nullptr;
    } else
        chat->addValue(style);

    return new nbt::Compound("", {
        new nbt::Int("id", this->_id),
        new nbt::String("name", this->_name),
        new nbt::Compound("element", {
            chat,
            new nbt::Compound("narration", {
                new nbt::String("translation_key",  this->_narrate.key),
                narrateParameters
            }),
        }),
    });
}

nbt::Compound *chat::_details::Registry::toNBT() const
{
    auto values = new nbt::List("values");

    for (const auto &chatType : _chatTypes)
        values->push_back(chatType.toNBT());

    return new nbt::Compound("minecraft:chat_type", {
        new nbt::String("type", "minecraft:chat_type"),
        values
    });
}
