#include "CyanBanner.hpp"
namespace Blocks {
    namespace CyanBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10426;
            case Properties::Rotation::ONE:
                return 10427;
            case Properties::Rotation::TWO:
                return 10428;
            case Properties::Rotation::THREE:
                return 10429;
            case Properties::Rotation::FOUR:
                return 10430;
            case Properties::Rotation::FIVE:
                return 10431;
            case Properties::Rotation::SIX:
                return 10432;
            case Properties::Rotation::SEVEN:
                return 10433;
            case Properties::Rotation::EIGHT:
                return 10434;
            case Properties::Rotation::NINE:
                return 10435;
            case Properties::Rotation::TEN:
                return 10436;
            case Properties::Rotation::ELEVEN:
                return 10437;
            case Properties::Rotation::TWELVE:
                return 10438;
            case Properties::Rotation::THIRTEEN:
                return 10439;
            case Properties::Rotation::FOURTEEN:
                return 10440;
            case Properties::Rotation::FIFTEEN:
                return 10441;
            }
            return 0;
        }
    }

}
