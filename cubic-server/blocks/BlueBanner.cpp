#include "BlueBanner.hpp"
namespace Blocks {
    namespace BlueBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10458;
            case Properties::Rotation::ONE:
                return 10459;
            case Properties::Rotation::TWO:
                return 10460;
            case Properties::Rotation::THREE:
                return 10461;
            case Properties::Rotation::FOUR:
                return 10462;
            case Properties::Rotation::FIVE:
                return 10463;
            case Properties::Rotation::SIX:
                return 10464;
            case Properties::Rotation::SEVEN:
                return 10465;
            case Properties::Rotation::EIGHT:
                return 10466;
            case Properties::Rotation::NINE:
                return 10467;
            case Properties::Rotation::TEN:
                return 10468;
            case Properties::Rotation::ELEVEN:
                return 10469;
            case Properties::Rotation::TWELVE:
                return 10470;
            case Properties::Rotation::THIRTEEN:
                return 10471;
            case Properties::Rotation::FOURTEEN:
                return 10472;
            case Properties::Rotation::FIFTEEN:
                return 10473;
            }
            return 0;
        }
    }

}
