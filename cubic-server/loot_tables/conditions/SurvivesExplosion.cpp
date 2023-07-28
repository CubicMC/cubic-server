#include "SurvivesExplosion.hpp"

namespace LootTable {
namespace Condition {
SurvivesExplosion::SurvivesExplosion(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool SurvivesExplosion::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> SurvivesExplosion::create(const nlohmann::json &condition) { return (std::make_unique<SurvivesExplosion>(condition)); }
};
};
