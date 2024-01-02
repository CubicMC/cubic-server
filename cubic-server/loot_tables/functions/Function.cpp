#include "Server.hpp"

#include "Function.hpp"

namespace LootTable {
namespace Function {
Function::Function(const nlohmann::json &function):
    _validity(false)
{
    // get conditions
    if (function.contains("conditions") && function["conditions"].is_array()) {
        for (const auto &condition : function["conditions"]) {
            std::unique_ptr<Condition::Condition> newCondition = Server::getInstance()->getLootTableSystem().createCondition(condition);

            const auto &it = this->_conditions.insert(this->_conditions.end(), nullptr);
            it->swap(newCondition);
        }
    }
};

bool Function::isValid(void) const noexcept { return (this->_validity); }

void Function::setValidity(bool validity) noexcept
{
    if (validity == false) {
        this->_validity = false;
        return;
    }
    for (const auto &condition : this->_conditions) {
        if (!condition->isValid()) {
            this->_validity = false;
            return;
        }
    }
    this->_validity = true;
}
};
};
