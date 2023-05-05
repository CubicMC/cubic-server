#include "GreenBanner.hpp"
namespace Blocks {
    namespace GreenBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10490;
            case Properties::Rotation::ONE:
                return 10491;
            case Properties::Rotation::TWO:
                return 10492;
            case Properties::Rotation::THREE:
                return 10493;
            case Properties::Rotation::FOUR:
                return 10494;
            case Properties::Rotation::FIVE:
                return 10495;
            case Properties::Rotation::SIX:
                return 10496;
            case Properties::Rotation::SEVEN:
                return 10497;
            case Properties::Rotation::EIGHT:
                return 10498;
            case Properties::Rotation::NINE:
                return 10499;
            case Properties::Rotation::TEN:
                return 10500;
            case Properties::Rotation::ELEVEN:
                return 10501;
            case Properties::Rotation::TWELVE:
                return 10502;
            case Properties::Rotation::THIRTEEN:
                return 10503;
            case Properties::Rotation::FOURTEEN:
                return 10504;
            case Properties::Rotation::FIFTEEN:
                return 10505;
            }
            return 0;
        }
    }

}
