#include "AcaciaSapling.hpp"
namespace Blocks {
namespace AcaciaSapling {
BlockId toProtocol(Properties::Stage stage)
{
    switch (stage) {
    case Properties::Stage::ZERO:
        return 32;
    case Properties::Stage::ONE:
        return 33;
    default:
        return 0;
    }
    return 0;
}
}

}
