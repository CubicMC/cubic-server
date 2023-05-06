#include "OrangeBanner.hpp"
namespace Blocks {
    namespace OrangeBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10298;
            case Properties::Rotation::ONE:
                return 10299;
            case Properties::Rotation::TWO:
                return 10300;
            case Properties::Rotation::THREE:
                return 10301;
            case Properties::Rotation::FOUR:
                return 10302;
            case Properties::Rotation::FIVE:
                return 10303;
            case Properties::Rotation::SIX:
                return 10304;
            case Properties::Rotation::SEVEN:
                return 10305;
            case Properties::Rotation::EIGHT:
                return 10306;
            case Properties::Rotation::NINE:
                return 10307;
            case Properties::Rotation::TEN:
                return 10308;
            case Properties::Rotation::ELEVEN:
                return 10309;
            case Properties::Rotation::TWELVE:
                return 10310;
            case Properties::Rotation::THIRTEEN:
                return 10311;
            case Properties::Rotation::FOURTEEN:
                return 10312;
            case Properties::Rotation::FIFTEEN:
                return 10313;
            default:
                return 0;
            }
            return 0;
        }
    }

}
