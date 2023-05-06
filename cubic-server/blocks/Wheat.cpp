#include "Wheat.hpp"
namespace Blocks {
    namespace Wheat {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 4226;
            case Properties::Age::ONE:
                return 4227;
            case Properties::Age::TWO:
                return 4228;
            case Properties::Age::THREE:
                return 4229;
            case Properties::Age::FOUR:
                return 4230;
            case Properties::Age::FIVE:
                return 4231;
            case Properties::Age::SIX:
                return 4232;
            case Properties::Age::SEVEN:
                return 4233;
            default:
                return 0;
            }
            return 0;
        }
    }

}
