#include "GreenCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
namespace GreenCandleCake {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20397;
    case Properties::Lit::FALSE:
        return 20398;
    }
    return 0;
}
}

}
