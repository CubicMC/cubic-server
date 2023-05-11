#include "SetContents.hpp"

namespace LootTable {
    namespace Function {
        SetContents::SetContents(const nlohmann::json &function) : Function(function)
        {}

        void SetContents::apply(void)
        {}

        std::unique_ptr<Function> SetContents::create(const nlohmann::json &function)
        {
            return (std::make_unique<SetContents>(function));
        }
    };
};