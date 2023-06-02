#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETINSTRUMENT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETINSTRUMENT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class SetInstrument : public Function {
public:
    SetInstrument(const nlohmann::json &function);
    ~SetInstrument() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETINSTRUMENT_HPP
