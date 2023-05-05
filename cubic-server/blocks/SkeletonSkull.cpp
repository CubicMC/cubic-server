#include "SkeletonSkull.hpp"
namespace Blocks {
    namespace SkeletonSkull {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 8571;
            case Properties::Rotation::ONE:
                return 8572;
            case Properties::Rotation::TWO:
                return 8573;
            case Properties::Rotation::THREE:
                return 8574;
            case Properties::Rotation::FOUR:
                return 8575;
            case Properties::Rotation::FIVE:
                return 8576;
            case Properties::Rotation::SIX:
                return 8577;
            case Properties::Rotation::SEVEN:
                return 8578;
            case Properties::Rotation::EIGHT:
                return 8579;
            case Properties::Rotation::NINE:
                return 8580;
            case Properties::Rotation::TEN:
                return 8581;
            case Properties::Rotation::ELEVEN:
                return 8582;
            case Properties::Rotation::TWELVE:
                return 8583;
            case Properties::Rotation::THIRTEEN:
                return 8584;
            case Properties::Rotation::FOURTEEN:
                return 8585;
            case Properties::Rotation::FIFTEEN:
                return 8586;
            }
            return 0;
        }
    }

}
