#include "RedstoneWallTorch.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RedstoneWallTorch {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 5574;
                case Properties::Lit::FALSE:
                    return 5575;
                }
            case Properties::Facing::SOUTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 5576;
                case Properties::Lit::FALSE:
                    return 5577;
                }
            case Properties::Facing::WEST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 5578;
                case Properties::Lit::FALSE:
                    return 5579;
                }
            case Properties::Facing::EAST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 5580;
                case Properties::Lit::FALSE:
                    return 5581;
                }
            }
            return 0;
        }
    }

}
