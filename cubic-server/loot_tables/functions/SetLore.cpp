#include "SetLore.hpp"

namespace LootTable {
    namespace Function {
        SetLore::SetLore(const nlohmann::json &function) : Function(function)
        {}

        void SetLore::apply(void)
        {}

        std::unique_ptr<Function> SetLore::create(const nlohmann::json &function)
        {
            return (std::make_unique<SetLore>(function));
        }
    };
};