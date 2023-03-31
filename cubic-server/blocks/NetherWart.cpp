#include "NetherWart.hpp"
#include <stdexcept>

namespace Blocks {
namespace NetherWart {
BlockId toProtocol(Properties::Age age)
{
    switch (age) {
    case Properties::Age::ZERO:
        return 7155;
    case Properties::Age::ONE:
        return 7156;
    case Properties::Age::TWO:
        return 7157;
    case Properties::Age::THREE:
        return 7158;
    }
    return 0;
}
}

}
