#include "Lava.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Lava {
        BlockId toProtocol(Properties::Level level) {
            switch (level) {
            case Properties::Level::ZERO:
                return 93;
            case Properties::Level::ONE:
                return 94;
            case Properties::Level::TWO:
                return 95;
            case Properties::Level::THREE:
                return 96;
            case Properties::Level::FOUR:
                return 97;
            case Properties::Level::FIVE:
                return 98;
            case Properties::Level::SIX:
                return 99;
            case Properties::Level::SEVEN:
                return 100;
            case Properties::Level::EIGHT:
                return 101;
            case Properties::Level::NINE:
                return 102;
            case Properties::Level::TEN:
                return 103;
            case Properties::Level::ELEVEN:
                return 104;
            case Properties::Level::TWELVE:
                return 105;
            case Properties::Level::THIRTEEN:
                return 106;
            case Properties::Level::FOURTEEN:
                return 107;
            case Properties::Level::FIFTEEN:
                return 108;
            }
            return 0;
        }
    }

}
