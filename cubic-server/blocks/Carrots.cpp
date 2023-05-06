#include "Carrots.hpp"
namespace Blocks {
namespace Carrots {
BlockId toProtocol(Properties::Age age) {
    switch (age) {
    case Properties::Age::ZERO:
        return 8363;
    case Properties::Age::ONE:
        return 8364;
    case Properties::Age::TWO:
        return 8365;
    case Properties::Age::THREE:
        return 8366;
    case Properties::Age::FOUR:
        return 8367;
    case Properties::Age::FIVE:
        return 8368;
    case Properties::Age::SIX:
        return 8369;
    case Properties::Age::SEVEN:
        return 8370;
    default:
        return 0;
    }
    return 0;
}
}

}
