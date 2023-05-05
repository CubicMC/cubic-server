#include "PoweredRail.hpp"
namespace Blocks {
    namespace PoweredRail {
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (powered) {
            case Properties::Powered::TRUE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1893;
                    case Properties::Waterlogged::FALSE:
                        return 1894;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1895;
                    case Properties::Waterlogged::FALSE:
                        return 1896;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1897;
                    case Properties::Waterlogged::FALSE:
                        return 1898;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1899;
                    case Properties::Waterlogged::FALSE:
                        return 1900;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1901;
                    case Properties::Waterlogged::FALSE:
                        return 1902;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1903;
                    case Properties::Waterlogged::FALSE:
                        return 1904;
                    }
                }
            case Properties::Powered::FALSE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1905;
                    case Properties::Waterlogged::FALSE:
                        return 1906;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1907;
                    case Properties::Waterlogged::FALSE:
                        return 1908;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1909;
                    case Properties::Waterlogged::FALSE:
                        return 1910;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1911;
                    case Properties::Waterlogged::FALSE:
                        return 1912;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1913;
                    case Properties::Waterlogged::FALSE:
                        return 1914;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1915;
                    case Properties::Waterlogged::FALSE:
                        return 1916;
                    }
                }
            }
            return 0;
        }
    }

}
