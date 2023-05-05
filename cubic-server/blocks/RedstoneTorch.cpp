#include "RedstoneTorch.hpp"
namespace Blocks {
    namespace RedstoneTorch {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 5572;
            case Properties::Lit::FALSE:
                return 5573;
            }
            return 0;
        }
    }

}
