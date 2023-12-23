#include "LootContext.hpp"

namespace LootTable {
namespace Context {
LootContext::LootContext(const std::string &type):
    _type(type)
{
}

const std::string &LootContext::getType() const noexcept { return (this->_type); }
}
}
