#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_UNIFORM_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_UNIFORM_HPP

#include "Roll.hpp"

namespace LootTable {
class LootContext;

namespace Roll {
class Uniform : public Roll {
public:
    Uniform(const nlohmann::json &roll);
    ~Uniform() = default;

    const RollResult poll(LootContext *context) const override;

    static std::unique_ptr<Roll> creator(const nlohmann::json &roll);
    static bool isOfType(const nlohmann::json &roll);

private:
    int64_t _min;
    int64_t _max;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_UNIFORM_HPP
