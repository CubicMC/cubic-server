#include "YellowCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
namespace YellowCandleCake {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 20379;
    case Properties::Lit::FALSE:
        return 20380;
    }
    return 0;
}
}

}
