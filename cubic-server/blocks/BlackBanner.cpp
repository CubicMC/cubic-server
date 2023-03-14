#include "BlackBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BlackBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10522;
            case Properties::Rotation::ONE:
                return 10523;
            case Properties::Rotation::TWO:
                return 10524;
            case Properties::Rotation::THREE:
                return 10525;
            case Properties::Rotation::FOUR:
                return 10526;
            case Properties::Rotation::FIVE:
                return 10527;
            case Properties::Rotation::SIX:
                return 10528;
            case Properties::Rotation::SEVEN:
                return 10529;
            case Properties::Rotation::EIGHT:
                return 10530;
            case Properties::Rotation::NINE:
                return 10531;
            case Properties::Rotation::TEN:
                return 10532;
            case Properties::Rotation::ELEVEN:
                return 10533;
            case Properties::Rotation::TWELVE:
                return 10534;
            case Properties::Rotation::THIRTEEN:
                return 10535;
            case Properties::Rotation::FOURTEEN:
                return 10536;
            case Properties::Rotation::FIFTEEN:
                return 10537;
            }
            return 0;
        }
    }

}
