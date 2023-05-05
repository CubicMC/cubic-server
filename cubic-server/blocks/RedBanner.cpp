#include "RedBanner.hpp"
namespace Blocks {
    namespace RedBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10506;
            case Properties::Rotation::ONE:
                return 10507;
            case Properties::Rotation::TWO:
                return 10508;
            case Properties::Rotation::THREE:
                return 10509;
            case Properties::Rotation::FOUR:
                return 10510;
            case Properties::Rotation::FIVE:
                return 10511;
            case Properties::Rotation::SIX:
                return 10512;
            case Properties::Rotation::SEVEN:
                return 10513;
            case Properties::Rotation::EIGHT:
                return 10514;
            case Properties::Rotation::NINE:
                return 10515;
            case Properties::Rotation::TEN:
                return 10516;
            case Properties::Rotation::ELEVEN:
                return 10517;
            case Properties::Rotation::TWELVE:
                return 10518;
            case Properties::Rotation::THIRTEEN:
                return 10519;
            case Properties::Rotation::FOURTEEN:
                return 10520;
            case Properties::Rotation::FIFTEEN:
                return 10521;
            }
            return 0;
        }
    }

}
