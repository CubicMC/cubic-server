#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETSTEWEFFECT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETSTEWEFFECT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetStewEffect : public Function {
public:
    SetStewEffect(const nlohmann::json &function);
    ~SetStewEffect() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETSTEWEFFECT_HPP
