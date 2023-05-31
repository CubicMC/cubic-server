#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYNAME_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYNAME_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class CopyName : public Function {
public:
    CopyName(const nlohmann::json &function);
    ~CopyName() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_COPYNAME_HPP
