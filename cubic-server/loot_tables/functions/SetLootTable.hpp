#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETLOOTTABLE_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETLOOTTABLE_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetLootTable : public Function {
public:
    SetLootTable(const nlohmann::json &function);
    ~SetLootTable() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETLOOTTABLE_HPP
