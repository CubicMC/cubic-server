#include "ChorusFlower.hpp"
#include <stdexcept>

namespace Blocks {
    namespace ChorusFlower {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 11793;
            case Properties::Age::ONE:
                return 11794;
            case Properties::Age::TWO:
                return 11795;
            case Properties::Age::THREE:
                return 11796;
            case Properties::Age::FOUR:
                return 11797;
            case Properties::Age::FIVE:
                return 11798;
            }
            return 0;
        }
    }

}
