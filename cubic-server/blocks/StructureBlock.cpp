#include "StructureBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StructureBlock {
        BlockId toProtocol(Properties::Mode mode) {
            switch (mode) {
            case Properties::Mode::SAVE:
                return 18728;
            case Properties::Mode::LOAD:
                return 18729;
            case Properties::Mode::CORNER:
                return 18730;
            case Properties::Mode::DATA:
                return 18731;
            }
            return 0;
        }
    }

}
