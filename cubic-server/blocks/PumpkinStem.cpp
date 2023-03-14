#include "PumpkinStem.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PumpkinStem {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 6591;
            case Properties::Age::ONE:
                return 6592;
            case Properties::Age::TWO:
                return 6593;
            case Properties::Age::THREE:
                return 6594;
            case Properties::Age::FOUR:
                return 6595;
            case Properties::Age::FIVE:
                return 6596;
            case Properties::Age::SIX:
                return 6597;
            case Properties::Age::SEVEN:
                return 6598;
            }
            return 0;
        }
    }

}
