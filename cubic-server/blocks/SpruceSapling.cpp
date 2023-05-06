#include "SpruceSapling.hpp"
namespace Blocks {
namespace SpruceSapling {
BlockId toProtocol(Properties::Stage stage) {
    switch (stage) {
    case Properties::Stage::ZERO:
        return 26;
    case Properties::Stage::ONE:
        return 27;
    default:
        return 0;
    }
    return 0;
}
}

}
