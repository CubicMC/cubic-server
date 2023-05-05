#include "ZombieHead.hpp"
namespace Blocks {
    namespace ZombieHead {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 8611;
            case Properties::Rotation::ONE:
                return 8612;
            case Properties::Rotation::TWO:
                return 8613;
            case Properties::Rotation::THREE:
                return 8614;
            case Properties::Rotation::FOUR:
                return 8615;
            case Properties::Rotation::FIVE:
                return 8616;
            case Properties::Rotation::SIX:
                return 8617;
            case Properties::Rotation::SEVEN:
                return 8618;
            case Properties::Rotation::EIGHT:
                return 8619;
            case Properties::Rotation::NINE:
                return 8620;
            case Properties::Rotation::TEN:
                return 8621;
            case Properties::Rotation::ELEVEN:
                return 8622;
            case Properties::Rotation::TWELVE:
                return 8623;
            case Properties::Rotation::THIRTEEN:
                return 8624;
            case Properties::Rotation::FOURTEEN:
                return 8625;
            case Properties::Rotation::FIFTEEN:
                return 8626;
            }
            return 0;
        }
    }

}
