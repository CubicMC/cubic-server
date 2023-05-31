#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETCONTENTS_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETCONTENTS_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetContents : public Function {
public:
    SetContents(const nlohmann::json &function);
    ~SetContents() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETCONTENTS_HPP
