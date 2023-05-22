#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_EXPLORATIONMAPPROPERTIES_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_EXPLORATIONMAPPROPERTIES_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class ExplorationMapProperties : public Function {
public:
    ExplorationMapProperties(const nlohmann::json &function);
    ~ExplorationMapProperties() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_EXPLORATIONMAPPROPERTIES_HPP
