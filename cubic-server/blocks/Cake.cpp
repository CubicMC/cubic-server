#include "Cake.hpp"
#include <stdexcept>

namespace Blocks {
namespace Cake {
BlockId toProtocol(Properties::Bites bites)
{
    switch (bites) {
    case Properties::Bites::ZERO:
        return 5709;
    case Properties::Bites::ONE:
        return 5710;
    case Properties::Bites::TWO:
        return 5711;
    case Properties::Bites::THREE:
        return 5712;
    case Properties::Bites::FOUR:
        return 5713;
    case Properties::Bites::FIVE:
        return 5714;
    case Properties::Bites::SIX:
        return 5715;
    }
    return 0;
}
}

}
