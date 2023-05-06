#include "LimeBanner.hpp"
namespace Blocks {
namespace LimeBanner {
BlockId toProtocol(Properties::Rotation rotation)
{
    switch (rotation) {
    case Properties::Rotation::ZERO:
        return 10362;
    case Properties::Rotation::ONE:
        return 10363;
    case Properties::Rotation::TWO:
        return 10364;
    case Properties::Rotation::THREE:
        return 10365;
    case Properties::Rotation::FOUR:
        return 10366;
    case Properties::Rotation::FIVE:
        return 10367;
    case Properties::Rotation::SIX:
        return 10368;
    case Properties::Rotation::SEVEN:
        return 10369;
    case Properties::Rotation::EIGHT:
        return 10370;
    case Properties::Rotation::NINE:
        return 10371;
    case Properties::Rotation::TEN:
        return 10372;
    case Properties::Rotation::ELEVEN:
        return 10373;
    case Properties::Rotation::TWELVE:
        return 10374;
    case Properties::Rotation::THIRTEEN:
        return 10375;
    case Properties::Rotation::FOURTEEN:
        return 10376;
    case Properties::Rotation::FIFTEEN:
        return 10377;
    default:
        return 0;
    }
    return 0;
}
}

}
