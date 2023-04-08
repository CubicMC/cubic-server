#include "SculkCatalyst.hpp"
#include <stdexcept>

namespace Blocks {
namespace SculkCatalyst {
BlockId toProtocol(Properties::Bloom bloom)
{
    switch (bloom) {
    case Properties::Bloom::TRUE:
        return 20682;
    case Properties::Bloom::FALSE:
        return 20683;
    }
    return 0;
}
}

}
