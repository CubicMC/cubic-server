#include "Peony.hpp"
namespace Blocks {
    namespace Peony {
        BlockId toProtocol(Properties::Half half) {
            switch (half) {
            case Properties::Half::UPPER:
                return 10276;
            case Properties::Half::LOWER:
                return 10277;
            }
            return 0;
        }
    }

}
