#include "LightBlueBanner.hpp"
namespace Blocks {
    namespace LightBlueBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10330;
            case Properties::Rotation::ONE:
                return 10331;
            case Properties::Rotation::TWO:
                return 10332;
            case Properties::Rotation::THREE:
                return 10333;
            case Properties::Rotation::FOUR:
                return 10334;
            case Properties::Rotation::FIVE:
                return 10335;
            case Properties::Rotation::SIX:
                return 10336;
            case Properties::Rotation::SEVEN:
                return 10337;
            case Properties::Rotation::EIGHT:
                return 10338;
            case Properties::Rotation::NINE:
                return 10339;
            case Properties::Rotation::TEN:
                return 10340;
            case Properties::Rotation::ELEVEN:
                return 10341;
            case Properties::Rotation::TWELVE:
                return 10342;
            case Properties::Rotation::THIRTEEN:
                return 10343;
            case Properties::Rotation::FOURTEEN:
                return 10344;
            case Properties::Rotation::FIFTEEN:
                return 10345;
            }
            return 0;
        }
    }

}
