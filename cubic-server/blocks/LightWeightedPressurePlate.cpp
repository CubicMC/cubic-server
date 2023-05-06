#include "LightWeightedPressurePlate.hpp"
namespace Blocks {
namespace LightWeightedPressurePlate {
BlockId toProtocol(Properties::Power power) {
    switch (power) {
    case Properties::Power::ZERO:
        return 8747;
    case Properties::Power::ONE:
        return 8748;
    case Properties::Power::TWO:
        return 8749;
    case Properties::Power::THREE:
        return 8750;
    case Properties::Power::FOUR:
        return 8751;
    case Properties::Power::FIVE:
        return 8752;
    case Properties::Power::SIX:
        return 8753;
    case Properties::Power::SEVEN:
        return 8754;
    case Properties::Power::EIGHT:
        return 8755;
    case Properties::Power::NINE:
        return 8756;
    case Properties::Power::TEN:
        return 8757;
    case Properties::Power::ELEVEN:
        return 8758;
    case Properties::Power::TWELVE:
        return 8759;
    case Properties::Power::THIRTEEN:
        return 8760;
    case Properties::Power::FOURTEEN:
        return 8761;
    case Properties::Power::FIFTEEN:
        return 8762;
    default:
        return 0;
    }
    return 0;
}
}

}
