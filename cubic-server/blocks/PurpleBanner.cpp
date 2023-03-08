#include "PurpleBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PurpleBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10442;
            case Properties::Rotation::ONE:
                return 10443;
            case Properties::Rotation::TWO:
                return 10444;
            case Properties::Rotation::THREE:
                return 10445;
            case Properties::Rotation::FOUR:
                return 10446;
            case Properties::Rotation::FIVE:
                return 10447;
            case Properties::Rotation::SIX:
                return 10448;
            case Properties::Rotation::SEVEN:
                return 10449;
            case Properties::Rotation::EIGHT:
                return 10450;
            case Properties::Rotation::NINE:
                return 10451;
            case Properties::Rotation::TEN:
                return 10452;
            case Properties::Rotation::ELEVEN:
                return 10453;
            case Properties::Rotation::TWELVE:
                return 10454;
            case Properties::Rotation::THIRTEEN:
                return 10455;
            case Properties::Rotation::FOURTEEN:
                return 10456;
            case Properties::Rotation::FIFTEEN:
                return 10457;
            }
            return 0;
        }
    }

}
