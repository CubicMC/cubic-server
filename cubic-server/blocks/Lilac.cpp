#include "Lilac.hpp"
namespace Blocks {
    namespace Lilac {
        BlockId toProtocol(Properties::Half half) {
            switch (half) {
            case Properties::Half::UPPER:
                return 10272;
            case Properties::Half::LOWER:
                return 10273;
            default:
                return 0;
            }
            return 0;
        }
    }

}
