#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETPOTION_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETPOTION_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetPotion : public Function {
public:
    SetPotion(const nlohmann::json &function);
    ~SetPotion() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETPOTION_HPP
