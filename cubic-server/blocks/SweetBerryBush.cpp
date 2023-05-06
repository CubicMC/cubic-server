#include "SweetBerryBush.hpp"
namespace Blocks {
    namespace SweetBerryBush {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 17947;
            case Properties::Age::ONE:
                return 17948;
            case Properties::Age::TWO:
                return 17949;
            case Properties::Age::THREE:
                return 17950;
            default:
                return 0;
            }
            return 0;
        }
    }

}
