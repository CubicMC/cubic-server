#include "Cactus.hpp"
namespace Blocks {
namespace Cactus {
BlockId toProtocol(Properties::Age age) {
    switch (age) {
    case Properties::Age::ZERO:
        return 5616;
    case Properties::Age::ONE:
        return 5617;
    case Properties::Age::TWO:
        return 5618;
    case Properties::Age::THREE:
        return 5619;
    case Properties::Age::FOUR:
        return 5620;
    case Properties::Age::FIVE:
        return 5621;
    case Properties::Age::SIX:
        return 5622;
    case Properties::Age::SEVEN:
        return 5623;
    case Properties::Age::EIGHT:
        return 5624;
    case Properties::Age::NINE:
        return 5625;
    case Properties::Age::TEN:
        return 5626;
    case Properties::Age::ELEVEN:
        return 5627;
    case Properties::Age::TWELVE:
        return 5628;
    case Properties::Age::THIRTEEN:
        return 5629;
    case Properties::Age::FOURTEEN:
        return 5630;
    case Properties::Age::FIFTEEN:
        return 5631;
    default:
        return 0;
    }
    return 0;
}
}

}
