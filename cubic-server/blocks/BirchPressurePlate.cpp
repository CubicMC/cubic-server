#include "BirchPressurePlate.hpp"
#include <stdexcept>

namespace Blocks {
namespace BirchPressurePlate {
BlockId toProtocol(Properties::Powered powered)
{
    switch (powered) {
    case Properties::Powered::TRUE:
        return 5556;
    case Properties::Powered::FALSE:
        return 5557;
    }
    return 0;
}
}

}
