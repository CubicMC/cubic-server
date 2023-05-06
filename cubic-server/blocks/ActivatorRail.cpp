#include "ActivatorRail.hpp"
namespace Blocks {
    namespace ActivatorRail {
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (powered) {
            case Properties::Powered::TRUE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8924;
                    case Properties::Waterlogged::FALSE:
                        return 8925;
                    default:
                        return 0;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8926;
                    case Properties::Waterlogged::FALSE:
                        return 8927;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8928;
                    case Properties::Waterlogged::FALSE:
                        return 8929;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8930;
                    case Properties::Waterlogged::FALSE:
                        return 8931;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8932;
                    case Properties::Waterlogged::FALSE:
                        return 8933;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8934;
                    case Properties::Waterlogged::FALSE:
                        return 8935;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Powered::FALSE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8936;
                    case Properties::Waterlogged::FALSE:
                        return 8937;
                    default:
                        return 0;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8938;
                    case Properties::Waterlogged::FALSE:
                        return 8939;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8940;
                    case Properties::Waterlogged::FALSE:
                        return 8941;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8942;
                    case Properties::Waterlogged::FALSE:
                        return 8943;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8944;
                    case Properties::Waterlogged::FALSE:
                        return 8945;
                    default:
                        return 0;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 8946;
                    case Properties::Waterlogged::FALSE:
                        return 8947;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
            return 0;
        }
    }

}
