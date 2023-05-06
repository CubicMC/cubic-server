#include "Target.hpp"
namespace Blocks {
namespace Target {
BlockId toProtocol(Properties::Power power)
{
    switch (power) {
    case Properties::Power::ZERO:
        return 18753;
    case Properties::Power::ONE:
        return 18754;
    case Properties::Power::TWO:
        return 18755;
    case Properties::Power::THREE:
        return 18756;
    case Properties::Power::FOUR:
        return 18757;
    case Properties::Power::FIVE:
        return 18758;
    case Properties::Power::SIX:
        return 18759;
    case Properties::Power::SEVEN:
        return 18760;
    case Properties::Power::EIGHT:
        return 18761;
    case Properties::Power::NINE:
        return 18762;
    case Properties::Power::TEN:
        return 18763;
    case Properties::Power::ELEVEN:
        return 18764;
    case Properties::Power::TWELVE:
        return 18765;
    case Properties::Power::THIRTEEN:
        return 18766;
    case Properties::Power::FOURTEEN:
        return 18767;
    case Properties::Power::FIFTEEN:
        return 18768;
    default:
        return 0;
    }
    return 0;
}
}

}
