#include "AcaciaPressurePlate.hpp"
#include <stdexcept>

namespace Blocks {
namespace AcaciaPressurePlate {
BlockId toProtocol(Properties::Powered powered)
{
    switch (powered) {
    case Properties::Powered::TRUE:
        return 5560;
    case Properties::Powered::FALSE:
        return 5561;
    }
    return 0;
}
}

}
