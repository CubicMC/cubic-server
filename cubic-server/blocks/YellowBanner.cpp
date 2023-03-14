#include "YellowBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace YellowBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10346;
            case Properties::Rotation::ONE:
                return 10347;
            case Properties::Rotation::TWO:
                return 10348;
            case Properties::Rotation::THREE:
                return 10349;
            case Properties::Rotation::FOUR:
                return 10350;
            case Properties::Rotation::FIVE:
                return 10351;
            case Properties::Rotation::SIX:
                return 10352;
            case Properties::Rotation::SEVEN:
                return 10353;
            case Properties::Rotation::EIGHT:
                return 10354;
            case Properties::Rotation::NINE:
                return 10355;
            case Properties::Rotation::TEN:
                return 10356;
            case Properties::Rotation::ELEVEN:
                return 10357;
            case Properties::Rotation::TWELVE:
                return 10358;
            case Properties::Rotation::THIRTEEN:
                return 10359;
            case Properties::Rotation::FOURTEEN:
                return 10360;
            case Properties::Rotation::FIFTEEN:
                return 10361;
            }
            return 0;
        }
    }

}
