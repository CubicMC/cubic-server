#include "PistonHead.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PistonHead {
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Short_ short_) {
            switch (type) {
            case Properties::Type::NORMAL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1614;
                    case Properties::Short_::FALSE:
                        return 1616;
                    }
                case Properties::Facing::EAST:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1618;
                    case Properties::Short_::FALSE:
                        return 1620;
                    }
                case Properties::Facing::SOUTH:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1622;
                    case Properties::Short_::FALSE:
                        return 1624;
                    }
                case Properties::Facing::WEST:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1626;
                    case Properties::Short_::FALSE:
                        return 1628;
                    }
                case Properties::Facing::UP:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1630;
                    case Properties::Short_::FALSE:
                        return 1632;
                    }
                case Properties::Facing::DOWN:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1634;
                    case Properties::Short_::FALSE:
                        return 1636;
                    }
                }
            case Properties::Type::STICKY:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1615;
                    case Properties::Short_::FALSE:
                        return 1617;
                    }
                case Properties::Facing::EAST:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1619;
                    case Properties::Short_::FALSE:
                        return 1621;
                    }
                case Properties::Facing::SOUTH:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1623;
                    case Properties::Short_::FALSE:
                        return 1625;
                    }
                case Properties::Facing::WEST:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1627;
                    case Properties::Short_::FALSE:
                        return 1629;
                    }
                case Properties::Facing::UP:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1631;
                    case Properties::Short_::FALSE:
                        return 1633;
                    }
                case Properties::Facing::DOWN:
                    switch (short_) {
                    case Properties::Short_::TRUE:
                        return 1635;
                    case Properties::Short_::FALSE:
                        return 1637;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Type type;
            Properties::Facing facing;
            Properties::Short_ short_;
            for (auto prop : properties) {
                if (prop.first == "type") {
                    if (prop.second == "normal") {
                        type = Properties::Type::NORMAL;
                    } else if (prop.second == "sticky") {
                        type = Properties::Type::STICKY;
                    } else {
                        throw std::runtime_error("Invalid property \"type\" value");
                    }
                } else if (prop.first == "facing") {
                    if (prop.second == "north") {
                        facing = Properties::Facing::NORTH;
                    } else if (prop.second == "east") {
                        facing = Properties::Facing::EAST;
                    } else if (prop.second == "south") {
                        facing = Properties::Facing::SOUTH;
                    } else if (prop.second == "west") {
                        facing = Properties::Facing::WEST;
                    } else if (prop.second == "up") {
                        facing = Properties::Facing::UP;
                    } else if (prop.second == "down") {
                        facing = Properties::Facing::DOWN;
                    } else {
                        throw std::runtime_error("Invalid property \"facing\" value");
                    }
                } else if (prop.first == "short_") {
                    if (prop.second == "true") {
                        short_ = Properties::Short_::TRUE;
                    } else if (prop.second == "false") {
                        short_ = Properties::Short_::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"short_\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(type, facing, short_);
        }
    }

}
