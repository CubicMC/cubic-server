#include "DragonHead.hpp"
namespace Blocks {
namespace DragonHead {
BlockId toProtocol(Properties::Rotation rotation)
{
    switch (rotation) {
    case Properties::Rotation::ZERO:
        return 8671;
    case Properties::Rotation::ONE:
        return 8672;
    case Properties::Rotation::TWO:
        return 8673;
    case Properties::Rotation::THREE:
        return 8674;
    case Properties::Rotation::FOUR:
        return 8675;
    case Properties::Rotation::FIVE:
        return 8676;
    case Properties::Rotation::SIX:
        return 8677;
    case Properties::Rotation::SEVEN:
        return 8678;
    case Properties::Rotation::EIGHT:
        return 8679;
    case Properties::Rotation::NINE:
        return 8680;
    case Properties::Rotation::TEN:
        return 8681;
    case Properties::Rotation::ELEVEN:
        return 8682;
    case Properties::Rotation::TWELVE:
        return 8683;
    case Properties::Rotation::THIRTEEN:
        return 8684;
    case Properties::Rotation::FOURTEEN:
        return 8685;
    case Properties::Rotation::FIFTEEN:
        return 8686;
    default:
        return 0;
    }
    return 0;
}
}

}
