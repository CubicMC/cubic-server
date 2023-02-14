#include "PrismarineStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PrismarineStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8345;
                        case Properties::Waterlogged::FALSE:
                            return 8346;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8347;
                        case Properties::Waterlogged::FALSE:
                            return 8348;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8349;
                        case Properties::Waterlogged::FALSE:
                            return 8350;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8351;
                        case Properties::Waterlogged::FALSE:
                            return 8352;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8353;
                        case Properties::Waterlogged::FALSE:
                            return 8354;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8355;
                        case Properties::Waterlogged::FALSE:
                            return 8356;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8357;
                        case Properties::Waterlogged::FALSE:
                            return 8358;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8359;
                        case Properties::Waterlogged::FALSE:
                            return 8360;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8361;
                        case Properties::Waterlogged::FALSE:
                            return 8362;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8363;
                        case Properties::Waterlogged::FALSE:
                            return 8364;
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
                            return 8365;
                        case Properties::Waterlogged::FALSE:
                            return 8366;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8367;
                        case Properties::Waterlogged::FALSE:
                            return 8368;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8369;
                        case Properties::Waterlogged::FALSE:
                            return 8370;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8371;
                        case Properties::Waterlogged::FALSE:
                            return 8372;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8373;
                        case Properties::Waterlogged::FALSE:
                            return 8374;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8375;
                        case Properties::Waterlogged::FALSE:
                            return 8376;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8377;
                        case Properties::Waterlogged::FALSE:
                            return 8378;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8379;
                        case Properties::Waterlogged::FALSE:
                            return 8380;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8381;
                        case Properties::Waterlogged::FALSE:
                            return 8382;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8383;
                        case Properties::Waterlogged::FALSE:
                            return 8384;
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
                            return 8385;
                        case Properties::Waterlogged::FALSE:
                            return 8386;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8387;
                        case Properties::Waterlogged::FALSE:
                            return 8388;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8389;
                        case Properties::Waterlogged::FALSE:
                            return 8390;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8391;
                        case Properties::Waterlogged::FALSE:
                            return 8392;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8393;
                        case Properties::Waterlogged::FALSE:
                            return 8394;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8395;
                        case Properties::Waterlogged::FALSE:
                            return 8396;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8397;
                        case Properties::Waterlogged::FALSE:
                            return 8398;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8399;
                        case Properties::Waterlogged::FALSE:
                            return 8400;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8401;
                        case Properties::Waterlogged::FALSE:
                            return 8402;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8403;
                        case Properties::Waterlogged::FALSE:
                            return 8404;
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
                            return 8405;
                        case Properties::Waterlogged::FALSE:
                            return 8406;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8407;
                        case Properties::Waterlogged::FALSE:
                            return 8408;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8409;
                        case Properties::Waterlogged::FALSE:
                            return 8410;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8411;
                        case Properties::Waterlogged::FALSE:
                            return 8412;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8413;
                        case Properties::Waterlogged::FALSE:
                            return 8414;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8415;
                        case Properties::Waterlogged::FALSE:
                            return 8416;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8417;
                        case Properties::Waterlogged::FALSE:
                            return 8418;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8419;
                        case Properties::Waterlogged::FALSE:
                            return 8420;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8421;
                        case Properties::Waterlogged::FALSE:
                            return 8422;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 8423;
                        case Properties::Waterlogged::FALSE:
                            return 8424;
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
