#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_ENTITYSCORES_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_ENTITYSCORES_HPP

#include <list>

#include "Condition.hpp"

namespace LootTable {
namespace Condition {
class EntityScores : public Condition {
public:
    EntityScores(const nlohmann::json &condition);
    ~EntityScores() = default;

    bool verify(const LootContext *context) const override;

    static std::unique_ptr<Condition> create(const nlohmann::json &condition);

private:
    std::list<std::unique_ptr<Condition>> _conditions;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONDITIONS_ENTITYSCORES_HPP
