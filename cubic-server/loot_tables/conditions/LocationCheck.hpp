#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_LOCATIONCHECK_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_LOCATIONCHECK_HPP

#include <list>

#include "Condition.hpp"

namespace LootTable {
namespace Condition {
class LocationCheck : public Condition {
public:
    LocationCheck(const nlohmann::json &condition);
    ~LocationCheck() = default;

    bool verify(const LootContext *context) const override;

    static std::unique_ptr<Condition> create(const nlohmann::json &condition);

private:
    std::list<std::unique_ptr<Condition>> _conditions;
};
}; // namespace Condition
}; // namespace LootTable

#endif // CUBIC_SERVER_LOOT_TABLES_CONDITIONS_LOCATIONCHECK_HPP
