#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_LOOTINGENCHANT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_LOOTINGENCHANT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class LootingEnchant : public Function {
public:
    LootingEnchant(const nlohmann::json &function);
    ~LootingEnchant() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_LOOTINGENCHANT_HPP
