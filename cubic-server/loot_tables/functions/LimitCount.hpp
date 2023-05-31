#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_LIMITCOUNT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_LIMITCOUNT_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class LimitCount : public Function {
public:
    LimitCount(const nlohmann::json &function);
    ~LimitCount() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_LIMITCOUNT_HPP
