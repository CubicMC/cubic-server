#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETNAME_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETNAME_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetName : public Function {
public:
    SetName(const nlohmann::json &function);
    ~SetName() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETNAME_HPP
