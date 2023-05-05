#include "Tnt.hpp"
namespace Blocks {
    namespace Tnt {
        BlockId toProtocol(Properties::Unstable unstable) {
            switch (unstable) {
            case Properties::Unstable::TRUE:
                return 2042;
            case Properties::Unstable::FALSE:
                return 2043;
            }
            return 0;
        }
    }

}
