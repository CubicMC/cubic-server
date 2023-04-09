#include "MagentaCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
namespace MagentaCandleCake {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20375;
    case Properties::Lit::FALSE:
        return 20376;
    }
    return 0;
}
}

}
