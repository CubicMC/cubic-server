#include "Lilac.hpp"
#include <stdexcept>

namespace Blocks {
namespace Lilac {
BlockId toProtocol(Properties::Half half)
{
    switch (half) {
    case Properties::Half::UPPER:
        return 10272;
    case Properties::Half::LOWER:
        return 10273;
    }
    return 0;
}
}

}
