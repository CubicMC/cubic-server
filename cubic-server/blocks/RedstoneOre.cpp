#include "RedstoneOre.hpp"
#include <stdexcept>

namespace Blocks {
namespace RedstoneOre {
BlockId toProtocol(Properties::Lit lit)
{
    switch (lit) {
    case Properties::Lit::TRUE:
        return 5568;
    case Properties::Lit::FALSE:
        return 5569;
    }
    return 0;
}
}

}
