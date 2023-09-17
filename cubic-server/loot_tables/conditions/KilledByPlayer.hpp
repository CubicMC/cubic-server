#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_KILLEDBYPLAYER_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_KILLEDBYPLAYER_HPP

#include <list>

#include "Condition.hpp"

namespace LootTable {
namespace Condition {
class KilledByPlayer : public Condition {
public:
    KilledByPlayer(const nlohmann::json &condition);
    ~KilledByPlayer() = default;

    bool verify(const LootContext *context) const override;

    static std::unique_ptr<Condition> create(const nlohmann::json &condition);

private:
    std::list<std::unique_ptr<Condition>> _conditions;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONDITIONS_KILLEDBYPLAYER_HPP
