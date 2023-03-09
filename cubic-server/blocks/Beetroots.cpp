#include "Beetroots.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Beetroots {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 11884;
            case Properties::Age::ONE:
                return 11885;
            case Properties::Age::TWO:
                return 11886;
            case Properties::Age::THREE:
                return 11887;
            }
            return 0;
        }
    }

}
