#include "SetEnchantments.hpp"

namespace LootTable {
    namespace Function {
        SetEnchantments::SetEnchantments(const nlohmann::json &function) : Function(function)
        {}

        void SetEnchantments::apply(void)
        {}

        std::unique_ptr<Function> SetEnchantments::create(const nlohmann::json &function)
        {
            return (std::make_unique<SetEnchantments>(function));
        }
    };
};