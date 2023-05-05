#include "PlayerHead.hpp"
namespace Blocks {
    namespace PlayerHead {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 8631;
            case Properties::Rotation::ONE:
                return 8632;
            case Properties::Rotation::TWO:
                return 8633;
            case Properties::Rotation::THREE:
                return 8634;
            case Properties::Rotation::FOUR:
                return 8635;
            case Properties::Rotation::FIVE:
                return 8636;
            case Properties::Rotation::SIX:
                return 8637;
            case Properties::Rotation::SEVEN:
                return 8638;
            case Properties::Rotation::EIGHT:
                return 8639;
            case Properties::Rotation::NINE:
                return 8640;
            case Properties::Rotation::TEN:
                return 8641;
            case Properties::Rotation::ELEVEN:
                return 8642;
            case Properties::Rotation::TWELVE:
                return 8643;
            case Properties::Rotation::THIRTEEN:
                return 8644;
            case Properties::Rotation::FOURTEEN:
                return 8645;
            case Properties::Rotation::FIFTEEN:
                return 8646;
            }
            return 0;
        }
    }

}
