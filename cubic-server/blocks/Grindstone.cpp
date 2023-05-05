#include "Grindstone.hpp"
namespace Blocks {
    namespace Grindstone {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 17810;
                case Properties::Facing::SOUTH:
                    return 17811;
                case Properties::Facing::WEST:
                    return 17812;
                case Properties::Facing::EAST:
                    return 17813;
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 17814;
                case Properties::Facing::SOUTH:
                    return 17815;
                case Properties::Facing::WEST:
                    return 17816;
                case Properties::Facing::EAST:
                    return 17817;
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 17818;
                case Properties::Facing::SOUTH:
                    return 17819;
                case Properties::Facing::WEST:
                    return 17820;
                case Properties::Facing::EAST:
                    return 17821;
                }
            }
            return 0;
        }
    }

}
