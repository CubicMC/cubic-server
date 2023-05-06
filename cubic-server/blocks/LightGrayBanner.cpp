#include "LightGrayBanner.hpp"
namespace Blocks {
namespace LightGrayBanner {
BlockId toProtocol(Properties::Rotation rotation)
{
    switch (rotation) {
    case Properties::Rotation::ZERO:
        return 10410;
    case Properties::Rotation::ONE:
        return 10411;
    case Properties::Rotation::TWO:
        return 10412;
    case Properties::Rotation::THREE:
        return 10413;
    case Properties::Rotation::FOUR:
        return 10414;
    case Properties::Rotation::FIVE:
        return 10415;
    case Properties::Rotation::SIX:
        return 10416;
    case Properties::Rotation::SEVEN:
        return 10417;
    case Properties::Rotation::EIGHT:
        return 10418;
    case Properties::Rotation::NINE:
        return 10419;
    case Properties::Rotation::TEN:
        return 10420;
    case Properties::Rotation::ELEVEN:
        return 10421;
    case Properties::Rotation::TWELVE:
        return 10422;
    case Properties::Rotation::THIRTEEN:
        return 10423;
    case Properties::Rotation::FOURTEEN:
        return 10424;
    case Properties::Rotation::FIFTEEN:
        return 10425;
    default:
        return 0;
    }
    return 0;
}
}

}
