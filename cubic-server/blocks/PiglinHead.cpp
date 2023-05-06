#include "PiglinHead.hpp"
namespace Blocks {
namespace PiglinHead {
BlockId toProtocol(Properties::Rotation rotation) {
    switch (rotation) {
    case Properties::Rotation::ZERO:
        return 8691;
    case Properties::Rotation::ONE:
        return 8692;
    case Properties::Rotation::TWO:
        return 8693;
    case Properties::Rotation::THREE:
        return 8694;
    case Properties::Rotation::FOUR:
        return 8695;
    case Properties::Rotation::FIVE:
        return 8696;
    case Properties::Rotation::SIX:
        return 8697;
    case Properties::Rotation::SEVEN:
        return 8698;
    case Properties::Rotation::EIGHT:
        return 8699;
    case Properties::Rotation::NINE:
        return 8700;
    case Properties::Rotation::TEN:
        return 8701;
    case Properties::Rotation::ELEVEN:
        return 8702;
    case Properties::Rotation::TWELVE:
        return 8703;
    case Properties::Rotation::THIRTEEN:
        return 8704;
    case Properties::Rotation::FOURTEEN:
        return 8705;
    case Properties::Rotation::FIFTEEN:
        return 8706;
    default:
        return 0;
    }
    return 0;
}
}

}
