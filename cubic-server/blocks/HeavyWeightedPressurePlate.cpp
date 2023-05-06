#include "HeavyWeightedPressurePlate.hpp"
namespace Blocks {
namespace HeavyWeightedPressurePlate {
BlockId toProtocol(Properties::Power power) {
    switch (power) {
    case Properties::Power::ZERO:
        return 8763;
    case Properties::Power::ONE:
        return 8764;
    case Properties::Power::TWO:
        return 8765;
    case Properties::Power::THREE:
        return 8766;
    case Properties::Power::FOUR:
        return 8767;
    case Properties::Power::FIVE:
        return 8768;
    case Properties::Power::SIX:
        return 8769;
    case Properties::Power::SEVEN:
        return 8770;
    case Properties::Power::EIGHT:
        return 8771;
    case Properties::Power::NINE:
        return 8772;
    case Properties::Power::TEN:
        return 8773;
    case Properties::Power::ELEVEN:
        return 8774;
    case Properties::Power::TWELVE:
        return 8775;
    case Properties::Power::THIRTEEN:
        return 8776;
    case Properties::Power::FOURTEEN:
        return 8777;
    case Properties::Power::FIFTEEN:
        return 8778;
    default:
        return 0;
    }
    return 0;
}
}

}
