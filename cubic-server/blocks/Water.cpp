#include "Water.hpp"
namespace Blocks {
namespace Water {
BlockId toProtocol(Properties::Level level)
{
    switch (level) {
    case Properties::Level::ZERO:
        return 77;
    case Properties::Level::ONE:
        return 78;
    case Properties::Level::TWO:
        return 79;
    case Properties::Level::THREE:
        return 80;
    case Properties::Level::FOUR:
        return 81;
    case Properties::Level::FIVE:
        return 82;
    case Properties::Level::SIX:
        return 83;
    case Properties::Level::SEVEN:
        return 84;
    case Properties::Level::EIGHT:
        return 85;
    case Properties::Level::NINE:
        return 86;
    case Properties::Level::TEN:
        return 87;
    case Properties::Level::ELEVEN:
        return 88;
    case Properties::Level::TWELVE:
        return 89;
    case Properties::Level::THIRTEEN:
        return 90;
    case Properties::Level::FOURTEEN:
        return 91;
    case Properties::Level::FIFTEEN:
        return 92;
    default:
        return 0;
    }
    return 0;
}
}

}
