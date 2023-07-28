#include "KilledByPlayer.hpp"

namespace LootTable {
namespace Condition {
KilledByPlayer::KilledByPlayer(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool KilledByPlayer::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> KilledByPlayer::create(const nlohmann::json &condition) { return (std::make_unique<KilledByPlayer>(condition)); }
};
};
