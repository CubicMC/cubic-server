#include "CandleCake.hpp"
namespace Blocks {
namespace CandleCake {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20369;
    case Properties::Lit::FALSE:
        return 20370;
    default:
        return 0;
    }
    return 0;
}
}

}
