#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_ENCHANTRANDOMLYWITHLEVELS_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_ENCHANTRANDOMLYWITHLEVELS_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class EnchantWithLevels : public Function {
public:
    EnchantWithLevels(const nlohmann::json &function);
    ~EnchantWithLevels() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_ENCHANTRANDOMLYWITHLEVELS_HPP
