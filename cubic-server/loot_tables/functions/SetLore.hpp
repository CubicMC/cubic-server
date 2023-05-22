#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETLORE_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETLORE_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetLore : public Function {
public:
    SetLore(const nlohmann::json &function);
    ~SetLore() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETLORE_HPP
