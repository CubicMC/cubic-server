#include "KilledByPlayer.hpp"

namespace LootTable {
    namespace Condition {
        KilledByPlayer::KilledByPlayer(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool KilledByPlayer::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> KilledByPlayer::create(const nlohmann::json &condition)
        {
            return (std::make_unique<KilledByPlayer>(condition));
        }
    };
};