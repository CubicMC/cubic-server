#include "Chat.hpp"

std::shared_ptr<nbt::Base> registry::ChatElement::toNBT() const
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
                }))}
            )),
        }
    ));
    // clang-format on
}

bool registry::ChatElement::operator==(const std::string &name) const
{
    return name == _name;
}
