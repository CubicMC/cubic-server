#include "WhiteBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WhiteBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 10282;
            case Properties::Rotation::ONE:
                return 10283;
            case Properties::Rotation::TWO:
                return 10284;
            case Properties::Rotation::THREE:
                return 10285;
            case Properties::Rotation::FOUR:
                return 10286;
            case Properties::Rotation::FIVE:
                return 10287;
            case Properties::Rotation::SIX:
                return 10288;
            case Properties::Rotation::SEVEN:
                return 10289;
            case Properties::Rotation::EIGHT:
                return 10290;
            case Properties::Rotation::NINE:
                return 10291;
            case Properties::Rotation::TEN:
                return 10292;
            case Properties::Rotation::ELEVEN:
                return 10293;
            case Properties::Rotation::TWELVE:
                return 10294;
            case Properties::Rotation::THIRTEEN:
                return 10295;
            case Properties::Rotation::FOURTEEN:
                return 10296;
            case Properties::Rotation::FIFTEEN:
                return 10297;
            }
            return 0;
        }
    }

}
