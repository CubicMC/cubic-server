#include "AcaciaSapling.hpp"
#include <stdexcept>

namespace Blocks {
namespace AcaciaSapling {
BlockId toProtocol(Properties::Stage stage)
{
    switch (stage) {
    case Properties::Stage::ZERO:
        return 32;
    case Properties::Stage::ONE:
        return 33;
    }
    return 0;
}
}

}
