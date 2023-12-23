#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_SCORE_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_SCORE_HPP

#include "Roll.hpp"

namespace LootTable {
class LootContext;

namespace Roll {
class Score : public Roll {
public:
    Score(const nlohmann::json &roll);
    ~Score() = default;

    const RollResult poll(LootContext *context) const override;

    static std::unique_ptr<Roll> creator(const nlohmann::json &roll);
    static bool isOfType(const nlohmann::json &roll);

    enum Target {
        Fixed = 0,
        This,
        Killer,
        DirectKiller,
        KillerPlayer
    };

private:
    Target _target;
    bool _isTargetFixed;
    std::string _fixedTarget;
    std::string _objective;
    double _scale;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_SCORE_HPP
