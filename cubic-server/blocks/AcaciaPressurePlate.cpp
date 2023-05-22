#include "AcaciaPressurePlate.hpp"
namespace Blocks {
namespace AcaciaPressurePlate {
BlockId toProtocol(Properties::Powered powered)
{
    switch (powered) {
    case Properties::Powered::TRUE:
        return 5560;
    case Properties::Powered::FALSE:
        return 5561;
    default:
        return 0;
    }
    return 0;
}
}

}
