#include "MelonStem.hpp"
namespace Blocks {
namespace MelonStem {
BlockId toProtocol(Properties::Age age)
{
    switch (age) {
    case Properties::Age::ZERO:
        return 6599;
    case Properties::Age::ONE:
        return 6600;
    case Properties::Age::TWO:
        return 6601;
    case Properties::Age::THREE:
        return 6602;
    case Properties::Age::FOUR:
        return 6603;
    case Properties::Age::FIVE:
        return 6604;
    case Properties::Age::SIX:
        return 6605;
    case Properties::Age::SEVEN:
        return 6606;
    default:
        return 0;
    }
    return 0;
}
}

}
