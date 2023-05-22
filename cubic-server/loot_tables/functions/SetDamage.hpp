#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETDAMAGE_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETDAMAGE_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetDamage : public Function {
public:
    SetDamage(const nlohmann::json &function);
    ~SetDamage() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETDAMAGE_HPP
