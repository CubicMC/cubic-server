#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETNBT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETNBT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetNBT : public Function {
public:
    SetNBT(const nlohmann::json &function);
    ~SetNBT() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETNBT_HPP
