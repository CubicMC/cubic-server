#include "Rail.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Rail {
        BlockId toProtocol(Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (shape) {
            case Properties::Shape::NORTH_SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4578;
                case Properties::Waterlogged::FALSE:
                    return 4579;
                }
            case Properties::Shape::EAST_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4580;
                case Properties::Waterlogged::FALSE:
                    return 4581;
                }
            case Properties::Shape::ASCENDING_EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4582;
                case Properties::Waterlogged::FALSE:
                    return 4583;
                }
            case Properties::Shape::ASCENDING_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4584;
                case Properties::Waterlogged::FALSE:
                    return 4585;
                }
            case Properties::Shape::ASCENDING_NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4586;
                case Properties::Waterlogged::FALSE:
                    return 4587;
                }
            case Properties::Shape::ASCENDING_SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4588;
                case Properties::Waterlogged::FALSE:
                    return 4589;
                }
            case Properties::Shape::SOUTH_EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4590;
                case Properties::Waterlogged::FALSE:
                    return 4591;
                }
            case Properties::Shape::SOUTH_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4592;
                case Properties::Waterlogged::FALSE:
                    return 4593;
                }
            case Properties::Shape::NORTH_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4594;
                case Properties::Waterlogged::FALSE:
                    return 4595;
                }
            case Properties::Shape::NORTH_EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4596;
                case Properties::Waterlogged::FALSE:
                    return 4597;
                }
            }
            return 0;
        }
    }

}
