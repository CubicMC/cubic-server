#include "EnchantWithLevels.hpp"

namespace LootTable {
    namespace Function {
        EnchantWithLevels::EnchantWithLevels(const nlohmann::json &function) : Function(function)
        {}

        void EnchantWithLevels::apply(void)
        {}

        std::unique_ptr<Function> EnchantWithLevels::create(const nlohmann::json &function)
        {
            return (std::make_unique<EnchantWithLevels>(function));
        }
    };
};