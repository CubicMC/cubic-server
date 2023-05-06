#include "TubeCoralFan.hpp"
namespace Blocks {
    namespace TubeCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12215;
            case Properties::Waterlogged::FALSE:
                return 12216;
            default:
                return 0;
            }
            return 0;
        }
    }

}
