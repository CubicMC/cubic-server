#include "LootingEnchant.hpp"

namespace LootTable {
    namespace Function {
        LootingEnchant::LootingEnchant(const nlohmann::json &function) : Function(function)
        {}

        void LootingEnchant::apply(void)
        {}

        std::unique_ptr<Function> LootingEnchant::create(const nlohmann::json &function)
        {
            return (std::make_unique<LootingEnchant>(function));
        }
    };
};