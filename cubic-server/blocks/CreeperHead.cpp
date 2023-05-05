#include "CreeperHead.hpp"
namespace Blocks {
    namespace CreeperHead {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 8651;
            case Properties::Rotation::ONE:
                return 8652;
            case Properties::Rotation::TWO:
                return 8653;
            case Properties::Rotation::THREE:
                return 8654;
            case Properties::Rotation::FOUR:
                return 8655;
            case Properties::Rotation::FIVE:
                return 8656;
            case Properties::Rotation::SIX:
                return 8657;
            case Properties::Rotation::SEVEN:
                return 8658;
            case Properties::Rotation::EIGHT:
                return 8659;
            case Properties::Rotation::NINE:
                return 8660;
            case Properties::Rotation::TEN:
                return 8661;
            case Properties::Rotation::ELEVEN:
                return 8662;
            case Properties::Rotation::TWELVE:
                return 8663;
            case Properties::Rotation::THIRTEEN:
                return 8664;
            case Properties::Rotation::FOURTEEN:
                return 8665;
            case Properties::Rotation::FIFTEEN:
                return 8666;
            }
            return 0;
        }
    }

}
