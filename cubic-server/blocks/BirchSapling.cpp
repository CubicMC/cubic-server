#include "BirchSapling.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BirchSapling {
        BlockId toProtocol(Properties::Stage stage) {
            switch (stage) {
            case Properties::Stage::ZERO:
                return 28;
            case Properties::Stage::ONE:
                return 29;
            }
            return 0;
        }
    }

}
