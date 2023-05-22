#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYBLOCKSTATES_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYBLOCKSTATES_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class CopyBlockStates : public Function {
public:
    CopyBlockStates(const nlohmann::json &function);
    ~CopyBlockStates() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYBLOCKSTATES_HPP
