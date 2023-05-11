#include "EnchantRandomly.hpp"

namespace LootTable {
    namespace Function {
        EnchantRandomly::EnchantRandomly(const nlohmann::json &function) : Function(function)
        {}

        void EnchantRandomly::apply(void)
        {}

        std::unique_ptr<Function> EnchantRandomly::create(const nlohmann::json &function)
        {
            return (std::make_unique<EnchantRandomly>(function));
        }
    };
};