#include "Potatoes.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Potatoes {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 8371;
            case Properties::Age::ONE:
                return 8372;
            case Properties::Age::TWO:
                return 8373;
            case Properties::Age::THREE:
                return 8374;
            case Properties::Age::FOUR:
                return 8375;
            case Properties::Age::FIVE:
                return 8376;
            case Properties::Age::SIX:
                return 8377;
            case Properties::Age::SEVEN:
                return 8378;
            }
            return 0;
        }
    }

}
