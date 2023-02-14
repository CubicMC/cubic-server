#include "AcaciaStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace AcaciaStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8004;
                        case Properties::Waterlogged::FALSE:
                            return 8005;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8006;
                        case Properties::Waterlogged::FALSE:
                            return 8007;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8008;
                        case Properties::Waterlogged::FALSE:
                            return 8009;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8010;
                        case Properties::Waterlogged::FALSE:
                            return 8011;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8012;
                        case Properties::Waterlogged::FALSE:
                            return 8013;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8014;
                        case Properties::Waterlogged::FALSE:
                            return 8015;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8016;
                        case Properties::Waterlogged::FALSE:
                            return 8017;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8018;
                        case Properties::Waterlogged::FALSE:
                            return 8019;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8020;
                        case Properties::Waterlogged::FALSE:
                            return 8021;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8022;
                        case Properties::Waterlogged::FALSE:
                            return 8023;
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8024;
                        case Properties::Waterlogged::FALSE:
                            return 8025;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8026;
                        case Properties::Waterlogged::FALSE:
                            return 8027;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8028;
                        case Properties::Waterlogged::FALSE:
                            return 8029;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8030;
                        case Properties::Waterlogged::FALSE:
                            return 8031;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8032;
                        case Properties::Waterlogged::FALSE:
                            return 8033;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8034;
                        case Properties::Waterlogged::FALSE:
                            return 8035;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8036;
                        case Properties::Waterlogged::FALSE:
                            return 8037;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8038;
                        case Properties::Waterlogged::FALSE:
                            return 8039;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8040;
                        case Properties::Waterlogged::FALSE:
                            return 8041;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8042;
                        case Properties::Waterlogged::FALSE:
                            return 8043;
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8044;
                        case Properties::Waterlogged::FALSE:
                            return 8045;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8046;
                        case Properties::Waterlogged::FALSE:
                            return 8047;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8048;
                        case Properties::Waterlogged::FALSE:
                            return 8049;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8050;
                        case Properties::Waterlogged::FALSE:
                            return 8051;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8052;
                        case Properties::Waterlogged::FALSE:
                            return 8053;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8054;
                        case Properties::Waterlogged::FALSE:
                            return 8055;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8056;
                        case Properties::Waterlogged::FALSE:
                            return 8057;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8058;
                        case Properties::Waterlogged::FALSE:
                            return 8059;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8060;
                        case Properties::Waterlogged::FALSE:
                            return 8061;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8062;
                        case Properties::Waterlogged::FALSE:
                            return 8063;
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8064;
                        case Properties::Waterlogged::FALSE:
                            return 8065;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8066;
                        case Properties::Waterlogged::FALSE:
                            return 8067;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8068;
                        case Properties::Waterlogged::FALSE:
                            return 8069;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8070;
                        case Properties::Waterlogged::FALSE:
                            return 8071;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8072;
                        case Properties::Waterlogged::FALSE:
                            return 8073;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8074;
                        case Properties::Waterlogged::FALSE:
                            return 8075;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8076;
                        case Properties::Waterlogged::FALSE:
                            return 8077;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8078;
                        case Properties::Waterlogged::FALSE:
                            return 8079;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8080;
                        case Properties::Waterlogged::FALSE:
                            return 8081;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8082;
                        case Properties::Waterlogged::FALSE:
                            return 8083;
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 4)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Half half;
            Properties::Shape shape;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "facing") {
                    if (prop.second == "north") {
                        facing = Properties::Facing::NORTH;
                    } else if (prop.second == "south") {
                        facing = Properties::Facing::SOUTH;
                    } else if (prop.second == "west") {
                        facing = Properties::Facing::WEST;
                    } else if (prop.second == "east") {
                        facing = Properties::Facing::EAST;
                    } else {
                        throw std::runtime_error("Invalid property \"facing\" value");
                    }
                } else if (prop.first == "half") {
                    if (prop.second == "top") {
                        half = Properties::Half::TOP;
                    } else if (prop.second == "bottom") {
                        half = Properties::Half::BOTTOM;
                    } else {
                        throw std::runtime_error("Invalid property \"half\" value");
                    }
                } else if (prop.first == "shape") {
                    if (prop.second == "straight") {
                        shape = Properties::Shape::STRAIGHT;
                    } else if (prop.second == "inner_left") {
                        shape = Properties::Shape::INNER_LEFT;
                    } else if (prop.second == "inner_right") {
                        shape = Properties::Shape::INNER_RIGHT;
                    } else if (prop.second == "outer_left") {
                        shape = Properties::Shape::OUTER_LEFT;
                    } else if (prop.second == "outer_right") {
                        shape = Properties::Shape::OUTER_RIGHT;
                    } else {
                        throw std::runtime_error("Invalid property \"shape\" value");
                    }
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, half, shape, waterlogged);
        }
    }

}
