#include "NetherWart.hpp"
namespace Blocks {
    namespace NetherWart {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 7155;
            case Properties::Age::ONE:
                return 7156;
            case Properties::Age::TWO:
                return 7157;
            case Properties::Age::THREE:
                return 7158;
            default:
                return 0;
            }
            return 0;
        }
    }

}
