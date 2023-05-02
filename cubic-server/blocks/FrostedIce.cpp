#include "FrostedIce.hpp"
#include <stdexcept>

namespace Blocks {
namespace FrostedIce {
BlockId toProtocol(Properties::Age age)
{
    switch (age) {
    case Properties::Age::ZERO:
        return 11914;
    case Properties::Age::ONE:
        return 11915;
    case Properties::Age::TWO:
        return 11916;
    case Properties::Age::THREE:
        return 11917;
    }
    return 0;
}
}

}
