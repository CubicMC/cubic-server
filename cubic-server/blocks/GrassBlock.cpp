#include "GrassBlock.hpp"
namespace Blocks {
namespace GrassBlock {
BlockId toProtocol(Properties::Snowy snowy) {
    switch (snowy) {
    case Properties::Snowy::TRUE:
        return 8;
    case Properties::Snowy::FALSE:
        return 9;
    default:
        return 0;
    }
    return 0;
}
}

}
