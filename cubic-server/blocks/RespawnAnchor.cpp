#include "RespawnAnchor.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RespawnAnchor {
        BlockId toProtocol(Properties::Charges charges) {
            switch (charges) {
            case Properties::Charges::ZERO:
                return 18822;
            case Properties::Charges::ONE:
                return 18823;
            case Properties::Charges::TWO:
                return 18824;
            case Properties::Charges::THREE:
                return 18825;
            case Properties::Charges::FOUR:
                return 18826;
            }
            return 0;
        }
    }

}
