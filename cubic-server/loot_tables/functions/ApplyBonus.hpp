#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_APPLYBONUS_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_APPLYBONUS_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class ApplyBonus : public Function {
public:
    ApplyBonus(const nlohmann::json &function);
    ~ApplyBonus() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_APPLYBONUS_HPP
