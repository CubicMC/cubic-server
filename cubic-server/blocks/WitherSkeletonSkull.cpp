#include "WitherSkeletonSkull.hpp"
namespace Blocks {
namespace WitherSkeletonSkull {
BlockId toProtocol(Properties::Rotation rotation)
{
    switch (rotation) {
    case Properties::Rotation::ZERO:
        return 8591;
    case Properties::Rotation::ONE:
        return 8592;
    case Properties::Rotation::TWO:
        return 8593;
    case Properties::Rotation::THREE:
        return 8594;
    case Properties::Rotation::FOUR:
        return 8595;
    case Properties::Rotation::FIVE:
        return 8596;
    case Properties::Rotation::SIX:
        return 8597;
    case Properties::Rotation::SEVEN:
        return 8598;
    case Properties::Rotation::EIGHT:
        return 8599;
    case Properties::Rotation::NINE:
        return 8600;
    case Properties::Rotation::TEN:
        return 8601;
    case Properties::Rotation::ELEVEN:
        return 8602;
    case Properties::Rotation::TWELVE:
        return 8603;
    case Properties::Rotation::THIRTEEN:
        return 8604;
    case Properties::Rotation::FOURTEEN:
        return 8605;
    case Properties::Rotation::FIFTEEN:
        return 8606;
    default:
        return 0;
    }
    return 0;
}
}

}
