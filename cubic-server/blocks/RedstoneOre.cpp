#include "RedstoneOre.hpp"
namespace Blocks {
namespace RedstoneOre {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 5568;
    case Properties::Lit::FALSE:
        return 5569;
    default:
        return 0;
    }
    return 0;
}
}

}
