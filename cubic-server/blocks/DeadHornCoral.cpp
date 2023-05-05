#include "DeadHornCoral.hpp"
namespace Blocks {
    namespace DeadHornCoral {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12193;
            case Properties::Waterlogged::FALSE:
                return 12194;
            }
            return 0;
        }
    }

}
