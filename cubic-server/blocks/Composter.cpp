#include "Composter.hpp"
#include <stdexcept>

namespace Blocks {
namespace Composter {
BlockId toProtocol(Properties::Level level)
{
    switch (level) {
    case Properties::Level::ZERO:
        return 18744;
    case Properties::Level::ONE:
        return 18745;
    case Properties::Level::TWO:
        return 18746;
    case Properties::Level::THREE:
        return 18747;
    case Properties::Level::FOUR:
        return 18748;
    case Properties::Level::FIVE:
        return 18749;
    case Properties::Level::SIX:
        return 18750;
    case Properties::Level::SEVEN:
        return 18751;
    case Properties::Level::EIGHT:
        return 18752;
    }
    return 0;
}
}

}
