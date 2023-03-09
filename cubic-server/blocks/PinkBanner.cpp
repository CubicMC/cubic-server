#include "PinkBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PinkBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10378;
            case Properties::Rotation::ONE:
                return 10379;
            case Properties::Rotation::TWO:
                return 10380;
            case Properties::Rotation::THREE:
                return 10381;
            case Properties::Rotation::FOUR:
                return 10382;
            case Properties::Rotation::FIVE:
                return 10383;
            case Properties::Rotation::SIX:
                return 10384;
            case Properties::Rotation::SEVEN:
                return 10385;
            case Properties::Rotation::EIGHT:
                return 10386;
            case Properties::Rotation::NINE:
                return 10387;
            case Properties::Rotation::TEN:
                return 10388;
            case Properties::Rotation::ELEVEN:
                return 10389;
            case Properties::Rotation::TWELVE:
                return 10390;
            case Properties::Rotation::THIRTEEN:
                return 10391;
            case Properties::Rotation::FOURTEEN:
                return 10392;
            case Properties::Rotation::FIFTEEN:
                return 10393;
            }
            return 0;
        }
    }

}
