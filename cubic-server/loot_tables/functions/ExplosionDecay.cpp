#include "ExplosionDecay.hpp"

namespace LootTable {
    namespace Function {
        ExplosionDecay::ExplosionDecay(const nlohmann::json &function) : Function(function)
        {}

        void ExplosionDecay::apply(void)
        {}

        std::unique_ptr<Function> ExplosionDecay::create(const nlohmann::json &function)
        {
            return (std::make_unique<ExplosionDecay>(function));
        }
    };
};