#include "SetName.hpp"

namespace LootTable {
    namespace Function {
        SetName::SetName(const nlohmann::json &function) : Function(function)
        {}

        void SetName::apply(void)
        {}

        std::unique_ptr<Function> SetName::create(const nlohmann::json &function)
        {
            return (std::make_unique<SetName>(function));
        }
    };
};