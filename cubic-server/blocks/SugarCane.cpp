#include "SugarCane.hpp"
#include <stdexcept>

namespace Blocks {
namespace SugarCane {
BlockId toProtocol(Properties::Age age)
{
    switch (age) {
    case Properties::Age::ZERO:
        return 5633;
    case Properties::Age::ONE:
        return 5634;
    case Properties::Age::TWO:
        return 5635;
    case Properties::Age::THREE:
        return 5636;
    case Properties::Age::FOUR:
        return 5637;
    case Properties::Age::FIVE:
        return 5638;
    case Properties::Age::SIX:
        return 5639;
    case Properties::Age::SEVEN:
        return 5640;
    case Properties::Age::EIGHT:
        return 5641;
    case Properties::Age::NINE:
        return 5642;
    case Properties::Age::TEN:
        return 5643;
    case Properties::Age::ELEVEN:
        return 5644;
    case Properties::Age::TWELVE:
        return 5645;
    case Properties::Age::THIRTEEN:
        return 5646;
    case Properties::Age::FOURTEEN:
        return 5647;
    case Properties::Age::FIFTEEN:
        return 5648;
    }
    return 0;
}
}

}
