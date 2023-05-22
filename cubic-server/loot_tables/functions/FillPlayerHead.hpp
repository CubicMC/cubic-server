#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FILLPLAYERHEAD_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FILLPLAYERHEAD_HPP

#include "Function.hpp"

namespace LootTable {
namespace Function {
class FillPlayerHead : public Function {
public:
    FillPlayerHead(const nlohmann::json &function);
    ~FillPlayerHead() = default;

    void apply(const LootContext &context) override;

    static std::unique_ptr<Function> create(const nlohmann::json &function);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FILLPLAYERHEAD_HPP
