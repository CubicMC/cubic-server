#include "GrayBanner.hpp"
namespace Blocks {
    namespace GrayBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10394;
            case Properties::Rotation::ONE:
                return 10395;
            case Properties::Rotation::TWO:
                return 10396;
            case Properties::Rotation::THREE:
                return 10397;
            case Properties::Rotation::FOUR:
                return 10398;
            case Properties::Rotation::FIVE:
                return 10399;
            case Properties::Rotation::SIX:
                return 10400;
            case Properties::Rotation::SEVEN:
                return 10401;
            case Properties::Rotation::EIGHT:
                return 10402;
            case Properties::Rotation::NINE:
                return 10403;
            case Properties::Rotation::TEN:
                return 10404;
            case Properties::Rotation::ELEVEN:
                return 10405;
            case Properties::Rotation::TWELVE:
                return 10406;
            case Properties::Rotation::THIRTEEN:
                return 10407;
            case Properties::Rotation::FOURTEEN:
                return 10408;
            case Properties::Rotation::FIFTEEN:
                return 10409;
            }
            return 0;
        }
    }

}
