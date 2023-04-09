#include "JungleSapling.hpp"
#include <stdexcept>

namespace Blocks {
namespace JungleSapling {
BlockId toProtocol(Properties::Stage stage)
{
    switch (stage) {
    case Properties::Stage::ZERO:
        return 30;
    case Properties::Stage::ONE:
        return 31;
    }
    return 0;
}
}

}
