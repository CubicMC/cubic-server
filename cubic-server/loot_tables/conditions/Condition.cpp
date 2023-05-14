#include "Condition.hpp"

namespace LootTable {
    namespace Condition {
        NoConditionContructor::NoConditionContructor(const nlohmann::json &condition) : _message("No constructor fitting the entry: " + condition.dump())
        {}

        const char *NoConditionContructor::what() const noexcept
        {
            return (this->_message.c_str());
        }

        bool Condition::verify(void) const
        {
            return (true);
        }
    };
};