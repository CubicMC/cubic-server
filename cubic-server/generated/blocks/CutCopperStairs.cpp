#include "CutCopperStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CutCopperStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19158;
                        case Properties::Waterlogged::FALSE:
                            return 19159;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19160;
                        case Properties::Waterlogged::FALSE:
                            return 19161;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19162;
                        case Properties::Waterlogged::FALSE:
                            return 19163;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19164;
                        case Properties::Waterlogged::FALSE:
                            return 19165;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19166;
                        case Properties::Waterlogged::FALSE:
                            return 19167;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19168;
                        case Properties::Waterlogged::FALSE:
                            return 19169;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19170;
                        case Properties::Waterlogged::FALSE:
                            return 19171;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19172;
                        case Properties::Waterlogged::FALSE:
                            return 19173;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19174;
                        case Properties::Waterlogged::FALSE:
                            return 19175;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19176;
                        case Properties::Waterlogged::FALSE:
                            return 19177;
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
                            return 19178;
                        case Properties::Waterlogged::FALSE:
                            return 19179;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19180;
                        case Properties::Waterlogged::FALSE:
                            return 19181;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19182;
                        case Properties::Waterlogged::FALSE:
                            return 19183;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19184;
                        case Properties::Waterlogged::FALSE:
                            return 19185;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19186;
                        case Properties::Waterlogged::FALSE:
                            return 19187;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19188;
                        case Properties::Waterlogged::FALSE:
                            return 19189;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19190;
                        case Properties::Waterlogged::FALSE:
                            return 19191;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19192;
                        case Properties::Waterlogged::FALSE:
                            return 19193;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19194;
                        case Properties::Waterlogged::FALSE:
                            return 19195;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19196;
                        case Properties::Waterlogged::FALSE:
                            return 19197;
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
                            return 19198;
                        case Properties::Waterlogged::FALSE:
                            return 19199;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19200;
                        case Properties::Waterlogged::FALSE:
                            return 19201;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19202;
                        case Properties::Waterlogged::FALSE:
                            return 19203;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19204;
                        case Properties::Waterlogged::FALSE:
                            return 19205;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19206;
                        case Properties::Waterlogged::FALSE:
                            return 19207;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19208;
                        case Properties::Waterlogged::FALSE:
                            return 19209;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19210;
                        case Properties::Waterlogged::FALSE:
                            return 19211;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19212;
                        case Properties::Waterlogged::FALSE:
                            return 19213;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19214;
                        case Properties::Waterlogged::FALSE:
                            return 19215;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19216;
                        case Properties::Waterlogged::FALSE:
                            return 19217;
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
                            return 19218;
                        case Properties::Waterlogged::FALSE:
                            return 19219;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19220;
                        case Properties::Waterlogged::FALSE:
                            return 19221;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19222;
                        case Properties::Waterlogged::FALSE:
                            return 19223;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19224;
                        case Properties::Waterlogged::FALSE:
                            return 19225;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19226;
                        case Properties::Waterlogged::FALSE:
                            return 19227;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19228;
                        case Properties::Waterlogged::FALSE:
                            return 19229;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19230;
                        case Properties::Waterlogged::FALSE:
                            return 19231;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19232;
                        case Properties::Waterlogged::FALSE:
                            return 19233;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19234;
                        case Properties::Waterlogged::FALSE:
                            return 19235;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19236;
                        case Properties::Waterlogged::FALSE:
                            return 19237;
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
