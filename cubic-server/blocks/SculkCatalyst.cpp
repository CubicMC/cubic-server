#include "SculkCatalyst.hpp"
namespace Blocks {
namespace SculkCatalyst {
BlockId toProtocol(Properties::Bloom bloom) {
    switch (bloom) {
    case Properties::Bloom::TRUE:
        return 20682;
    case Properties::Bloom::FALSE:
        return 20683;
    default:
        return 0;
    }
    return 0;
}
}

}
