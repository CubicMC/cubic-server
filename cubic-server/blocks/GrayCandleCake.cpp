#include "GrayCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
namespace GrayCandleCake {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20385;
    case Properties::Lit::FALSE:
        return 20386;
    }
    return 0;
}
}

}
