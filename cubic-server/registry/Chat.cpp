#include "Chat.hpp"
#include "nbt.hpp"

std::shared_ptr<nbt::Base> registry::ChatElement::toNBT() const
{
    auto chatParameters = NBT_MAKE_AS(nbt::List, "parameters");
    auto narrateParameters = NBT_MAKE_AS(nbt::List, "parameters");

    for (const auto &arg : this->_chat.args)
        chatParameters->push_back(NBT_MAKE(nbt::String, "", arg));

    for (const auto &arg : this->_narrate.args)
        narrateParameters->push_back(NBT_MAKE(nbt::String, "", arg));

    auto style = NBT_MAKE_AS(nbt::Compound, "style", {})->as<nbt::Compound>();

    if (_style.bold.has_value())
        style->addValue(NBT_MAKE(nbt::Byte, "bold", _style.bold.value()));
    if (_style.italic.has_value())
        style->addValue(NBT_MAKE(nbt::Byte, "italic", _style.italic.value()));
    if (_style.underlined.has_value())
        style->addValue(NBT_MAKE(nbt::Byte, "underlined", _style.underlined.value()));
    if (_style.strikethrough.has_value())
        style->addValue(NBT_MAKE(nbt::Byte, "strikethrough", _style.strikethrough.value()));
    if (_style.obfuscated.has_value())
        style->addValue(NBT_MAKE(nbt::Byte, "obfuscated", _style.obfuscated.value()));
    if (_style.font.has_value())
        style->addValue(NBT_MAKE(nbt::String, "font", _style.font.value()));
    if (_style.color.has_value())
        style->addValue(NBT_MAKE(nbt::String, "color", _style.color.value()));

    auto chat = NBT_MAKE_AS(nbt::Compound, "chat", {NBT_MAKE(nbt::String, "translation_key", this->_chat.key), chatParameters});

    if (style->size() <= 0) {
        style = nullptr;
    } else
        chat->addValue(style);

    // clang-format off
    return NBT_MAKE(nbt::Compound, "", {
        NBT_MAKE(nbt::Int, "id", this->_id),
        NBT_MAKE(nbt::String, "name", this->_name),
        NBT_MAKE(nbt::Compound, "element", {
            chat,
            NBT_MAKE(nbt::Compound, "narration", {
                NBT_MAKE(nbt::String, "translation_key", this->_narrate.key),
                narrateParameters
            }),
        }),
    });
    // clang-format on
}
