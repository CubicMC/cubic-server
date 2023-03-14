#include "MagentaBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MagentaBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10314;
            case Properties::Rotation::ONE:
                return 10315;
            case Properties::Rotation::TWO:
                return 10316;
            case Properties::Rotation::THREE:
                return 10317;
            case Properties::Rotation::FOUR:
                return 10318;
            case Properties::Rotation::FIVE:
                return 10319;
            case Properties::Rotation::SIX:
                return 10320;
            case Properties::Rotation::SEVEN:
                return 10321;
            case Properties::Rotation::EIGHT:
                return 10322;
            case Properties::Rotation::NINE:
                return 10323;
            case Properties::Rotation::TEN:
                return 10324;
            case Properties::Rotation::ELEVEN:
                return 10325;
            case Properties::Rotation::TWELVE:
                return 10326;
            case Properties::Rotation::THIRTEEN:
                return 10327;
            case Properties::Rotation::FOURTEEN:
                return 10328;
            case Properties::Rotation::FIFTEEN:
                return 10329;
            }
            return 0;
        }
    }

}
