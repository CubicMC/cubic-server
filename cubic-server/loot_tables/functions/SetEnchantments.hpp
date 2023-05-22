#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETENCHANTMENTS_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETENCHANTMENTS_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetEnchantments : public Function {
public:
    SetEnchantments(const nlohmann::json &function);
    ~SetEnchantments() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETENCHANTMENTS_HPP
