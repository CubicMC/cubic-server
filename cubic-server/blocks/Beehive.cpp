#include "Beehive.hpp"
namespace Blocks {
namespace Beehive {
BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (honey_level) {
        case Properties::Honey_level::ZERO:
            return 18793;
        case Properties::Honey_level::ONE:
            return 18794;
        case Properties::Honey_level::TWO:
            return 18795;
        case Properties::Honey_level::THREE:
            return 18796;
        case Properties::Honey_level::FOUR:
            return 18797;
        case Properties::Honey_level::FIVE:
            return 18798;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (honey_level) {
        case Properties::Honey_level::ZERO:
            return 18799;
        case Properties::Honey_level::ONE:
            return 18800;
        case Properties::Honey_level::TWO:
            return 18801;
        case Properties::Honey_level::THREE:
            return 18802;
        case Properties::Honey_level::FOUR:
            return 18803;
        case Properties::Honey_level::FIVE:
            return 18804;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (honey_level) {
        case Properties::Honey_level::ZERO:
            return 18805;
        case Properties::Honey_level::ONE:
            return 18806;
        case Properties::Honey_level::TWO:
            return 18807;
        case Properties::Honey_level::THREE:
            return 18808;
        case Properties::Honey_level::FOUR:
            return 18809;
        case Properties::Honey_level::FIVE:
            return 18810;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (honey_level) {
        case Properties::Honey_level::ZERO:
            return 18811;
        case Properties::Honey_level::ONE:
            return 18812;
        case Properties::Honey_level::TWO:
            return 18813;
        case Properties::Honey_level::THREE:
            return 18814;
        case Properties::Honey_level::FOUR:
            return 18815;
        case Properties::Honey_level::FIVE:
            return 18816;
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
