#include "Podzol.hpp"
#include <stdexcept>

namespace Blocks {
namespace Podzol {
BlockId toProtocol(Properties::Snowy snowy)
{
    switch (snowy) {
    case Properties::Snowy::TRUE:
        return 12;
    case Properties::Snowy::FALSE:
        return 13;
    }
    return 0;
}
}

}
