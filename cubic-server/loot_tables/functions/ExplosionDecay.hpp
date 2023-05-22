#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_EXPLORATIONDECAY_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_EXPLORATIONDECAY_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class ExplosionDecay : public Function {
public:
    ExplosionDecay(const nlohmann::json &function);
    ~ExplosionDecay() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_EXPLORATIONDECAY_HPP
