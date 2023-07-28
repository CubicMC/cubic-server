#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_CONSTANT_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_CONSTANT_HPP

#include "Roll.hpp"

namespace LootTable {
class LootContext;

namespace Roll {
class Constant : public Roll {
public:
    Constant(const nlohmann::json &roll);
    ~Constant() = default;

    const RollResult poll(LootContext *context) const override;

    static std::unique_ptr<Roll> creator(const nlohmann::json &roll);
    static bool isOfType(const nlohmann::json &roll);

private:
    std::uint64_t _rolls;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_CONSTANT_HPP
