#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETATTRIBUTES_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETATTRIBUTES_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetAttributes : public Function {
public:
    SetAttributes(const nlohmann::json &function);
    ~SetAttributes() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETATTRIBUTES_HPP
