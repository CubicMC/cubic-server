#include "DetectorRail.hpp"
namespace Blocks {
namespace DetectorRail {
BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
    switch (powered) {
    case Properties::Powered::TRUE:
        switch (shape) {
        case Properties::Shape::NORTH_SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1917;
            case Properties::Waterlogged::FALSE:
                return 1918;
            default:
                return 0;
            }
        case Properties::Shape::EAST_WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1919;
            case Properties::Waterlogged::FALSE:
                return 1920;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1921;
            case Properties::Waterlogged::FALSE:
                return 1922;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1923;
            case Properties::Waterlogged::FALSE:
                return 1924;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_NORTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1925;
            case Properties::Waterlogged::FALSE:
                return 1926;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1927;
            case Properties::Waterlogged::FALSE:
                return 1928;
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
                return 1929;
            case Properties::Waterlogged::FALSE:
                return 1930;
            default:
                return 0;
            }
        case Properties::Shape::EAST_WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1931;
            case Properties::Waterlogged::FALSE:
                return 1932;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1933;
            case Properties::Waterlogged::FALSE:
                return 1934;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1935;
            case Properties::Waterlogged::FALSE:
                return 1936;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_NORTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1937;
            case Properties::Waterlogged::FALSE:
                return 1938;
            default:
                return 0;
            }
        case Properties::Shape::ASCENDING_SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 1939;
            case Properties::Waterlogged::FALSE:
                return 1940;
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
