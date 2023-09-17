#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_BINOMIAL_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_BINOMIAL_HPP

#include "Roll.hpp"

namespace LootTable {
class LootContext;

namespace Roll {
class Binomial : public Roll {
public:
    Binomial(const nlohmann::json &roll);
    ~Binomial() = default;

    const RollResult poll(LootContext *context) const override;

    static std::unique_ptr<Roll> creator(const nlohmann::json &roll);
    static bool isOfType(const nlohmann::json &roll);

private:
    int64_t _n;
    double _p;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_BINOMIAL_HPP
