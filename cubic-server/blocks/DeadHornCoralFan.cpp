#include "DeadHornCoralFan.hpp"
namespace Blocks {
    namespace DeadHornCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12213;
            case Properties::Waterlogged::FALSE:
                return 12214;
            default:
                return 0;
            }
            return 0;
        }
    }

}
