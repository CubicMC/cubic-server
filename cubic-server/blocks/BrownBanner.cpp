#include "BrownBanner.hpp"
namespace Blocks {
    namespace BrownBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10474;
            case Properties::Rotation::ONE:
                return 10475;
            case Properties::Rotation::TWO:
                return 10476;
            case Properties::Rotation::THREE:
                return 10477;
            case Properties::Rotation::FOUR:
                return 10478;
            case Properties::Rotation::FIVE:
                return 10479;
            case Properties::Rotation::SIX:
                return 10480;
            case Properties::Rotation::SEVEN:
                return 10481;
            case Properties::Rotation::EIGHT:
                return 10482;
            case Properties::Rotation::NINE:
                return 10483;
            case Properties::Rotation::TEN:
                return 10484;
            case Properties::Rotation::ELEVEN:
                return 10485;
            case Properties::Rotation::TWELVE:
                return 10486;
            case Properties::Rotation::THIRTEEN:
                return 10487;
            case Properties::Rotation::FOURTEEN:
                return 10488;
            case Properties::Rotation::FIFTEEN:
                return 10489;
            }
            return 0;
        }
    }

}
