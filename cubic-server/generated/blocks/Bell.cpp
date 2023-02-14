#include "Bell.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Bell {
        BlockId toProtocol(Properties::Attachment attachment, Properties::Facing facing, Properties::Powered powered) {
            switch (attachment) {
            case Properties::Attachment::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16059;
                    case Properties::Powered::FALSE:
                        return 16060;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16061;
                    case Properties::Powered::FALSE:
                        return 16062;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16063;
                    case Properties::Powered::FALSE:
                        return 16064;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16065;
                    case Properties::Powered::FALSE:
                        return 16066;
                    }
                }
            case Properties::Attachment::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16067;
                    case Properties::Powered::FALSE:
                        return 16068;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16069;
                    case Properties::Powered::FALSE:
                        return 16070;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16071;
                    case Properties::Powered::FALSE:
                        return 16072;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16073;
                    case Properties::Powered::FALSE:
                        return 16074;
                    }
                }
            case Properties::Attachment::SINGLE_WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16075;
                    case Properties::Powered::FALSE:
                        return 16076;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16077;
                    case Properties::Powered::FALSE:
                        return 16078;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16079;
                    case Properties::Powered::FALSE:
                        return 16080;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16081;
                    case Properties::Powered::FALSE:
                        return 16082;
                    }
                }
            case Properties::Attachment::DOUBLE_WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16083;
                    case Properties::Powered::FALSE:
                        return 16084;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16085;
                    case Properties::Powered::FALSE:
                        return 16086;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16087;
                    case Properties::Powered::FALSE:
                        return 16088;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16089;
                    case Properties::Powered::FALSE:
                        return 16090;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Attachment attachment;
            Properties::Facing facing;
            Properties::Powered powered;
            for (auto prop : properties) {
                if (prop.first == "attachment") {
                    if (prop.second == "floor") {
                        attachment = Properties::Attachment::FLOOR;
                    } else if (prop.second == "ceiling") {
                        attachment = Properties::Attachment::CEILING;
                    } else if (prop.second == "single_wall") {
                        attachment = Properties::Attachment::SINGLE_WALL;
                    } else if (prop.second == "double_wall") {
                        attachment = Properties::Attachment::DOUBLE_WALL;
                    } else {
                        throw std::runtime_error("Invalid property \"attachment\" value");
                    }
                } else if (prop.first == "facing") {
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
                } else if (prop.first == "powered") {
                    if (prop.second == "true") {
                        powered = Properties::Powered::TRUE;
                    } else if (prop.second == "false") {
                        powered = Properties::Powered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"powered\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(attachment, facing, powered);
        }
    }

}
