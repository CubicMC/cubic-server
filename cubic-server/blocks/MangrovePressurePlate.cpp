#include "MangrovePressurePlate.hpp"
namespace Blocks {
namespace MangrovePressurePlate {
BlockId toProtocol(Properties::Powered powered)
{
    switch (powered) {
    case Properties::Powered::TRUE:
        return 5564;
    case Properties::Powered::FALSE:
        return 5565;
    default:
        return 0;
    }
    return 0;
}
}

}
