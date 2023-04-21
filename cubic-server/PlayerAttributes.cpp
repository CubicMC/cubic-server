#include "PlayerAttributes.hpp"

namespace player_attributes {
std::ostream &operator<<(std::ostream &os, const Gamemode &gamemode)
{
    switch (gamemode) {
    case Gamemode::Survival:
        os << "SURVIVAL";
        break;
    case Gamemode::Creative:
        os << "CREATIVE";
        break;
    case Gamemode::Adventure:
        os << "ADVENTURE";
        break;
    case Gamemode::Spectator:
        os << "SPECTATOR";
        break;
    default:
        os << "UNKNOWN";
        break;
    }
    return os;
}
}
