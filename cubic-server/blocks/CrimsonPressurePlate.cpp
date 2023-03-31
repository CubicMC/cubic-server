#include "CrimsonPressurePlate.hpp"
#include <stdexcept>

namespace Blocks {
namespace CrimsonPressurePlate {
BlockId toProtocol(Properties::Powered powered)
{
    switch (powered) {
    case Properties::Powered::TRUE:
        return 18052;
    case Properties::Powered::FALSE:
        return 18053;
    }
    return 0;
}
}

}
