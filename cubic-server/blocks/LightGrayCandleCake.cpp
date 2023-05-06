#include "LightGrayCandleCake.hpp"
namespace Blocks {
namespace LightGrayCandleCake {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20387;
    case Properties::Lit::FALSE:
        return 20388;
    default:
        return 0;
    }
    return 0;
}
}

}
