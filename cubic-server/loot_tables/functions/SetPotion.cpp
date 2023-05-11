#include "SetPotion.hpp"

namespace LootTable {
    namespace Function {
        SetPotion::SetPotion(const nlohmann::json &function) : Function(function)
        {}

        void SetPotion::apply(void)
        {}

        std::unique_ptr<Function> SetPotion::create(const nlohmann::json &function)
        {
            return (std::make_unique<SetPotion>(function));
        }
    };
};