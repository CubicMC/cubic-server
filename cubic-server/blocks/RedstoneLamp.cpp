#include "RedstoneLamp.hpp"
namespace Blocks {
namespace RedstoneLamp {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 7187;
    case Properties::Lit::FALSE:
        return 7188;
    default:
        return 0;
    }
    return 0;
}
}

}
