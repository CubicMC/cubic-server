#include "DetectorRail.hpp"
#include <stdexcept>

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
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1919;
                    case Properties::Waterlogged::FALSE:
                        return 1920;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1921;
                    case Properties::Waterlogged::FALSE:
                        return 1922;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1923;
                    case Properties::Waterlogged::FALSE:
                        return 1924;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1925;
                    case Properties::Waterlogged::FALSE:
                        return 1926;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1927;
                    case Properties::Waterlogged::FALSE:
                        return 1928;
                    }
                }
            case Properties::Powered::FALSE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1929;
                    case Properties::Waterlogged::FALSE:
                        return 1930;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1931;
                    case Properties::Waterlogged::FALSE:
                        return 1932;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1933;
                    case Properties::Waterlogged::FALSE:
                        return 1934;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1935;
                    case Properties::Waterlogged::FALSE:
                        return 1936;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1937;
                    case Properties::Waterlogged::FALSE:
                        return 1938;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1939;
                    case Properties::Waterlogged::FALSE:
                        return 1940;
                    }
                }
            }
            return 0;
        }
    }

}
