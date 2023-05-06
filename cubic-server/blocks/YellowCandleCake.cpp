#include "YellowCandleCake.hpp"
namespace Blocks {
namespace YellowCandleCake {
BlockId toProtocol(Properties::Lit lit) {
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20379;
    case Properties::Lit::FALSE:
        return 20380;
    default:
        return 0;
    }
    return 0;
}
}

}
