#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYNBT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYNBT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class CopyNBT : public Function {
public:
    CopyNBT(const nlohmann::json &function);
    ~CopyNBT() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYNBT_HPP
