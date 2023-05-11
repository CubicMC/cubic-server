#include "FillPlayerHead.hpp"

namespace LootTable {
    namespace Function {
        FillPlayerHead::FillPlayerHead(const nlohmann::json &function) : Function(function)
        {}

        void FillPlayerHead::apply(void)
        {}

        std::unique_ptr<Function> FillPlayerHead::create(const nlohmann::json &function)
        {
            return (std::make_unique<FillPlayerHead>(function));
        }
    };
};