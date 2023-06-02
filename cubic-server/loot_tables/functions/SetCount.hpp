#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETCOUNT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETCOUNT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetCount : public Function {
public:
    SetCount(const nlohmann::json &function);
    ~SetCount() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETCOUNT_HPP
