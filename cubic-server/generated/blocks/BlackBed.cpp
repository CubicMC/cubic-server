#include "BlackBed.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BlackBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1519;
                    case Properties::Part::FOOT:
                        return 1520;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1521;
                    case Properties::Part::FOOT:
                        return 1522;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1523;
                    case Properties::Part::FOOT:
                        return 1524;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1525;
                    case Properties::Part::FOOT:
                        return 1526;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1527;
                    case Properties::Part::FOOT:
                        return 1528;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1529;
                    case Properties::Part::FOOT:
                        return 1530;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1531;
                    case Properties::Part::FOOT:
                        return 1532;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1533;
                    case Properties::Part::FOOT:
                        return 1534;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Occupied occupied;
            Properties::Part part;
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
                } else if (prop.first == "occupied") {
                    if (prop.second == "true") {
                        occupied = Properties::Occupied::TRUE;
                    } else if (prop.second == "false") {
                        occupied = Properties::Occupied::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"occupied\" value");
                    }
                } else if (prop.first == "part") {
                    if (prop.second == "head") {
                        part = Properties::Part::HEAD;
                    } else if (prop.second == "foot") {
                        part = Properties::Part::FOOT;
                    } else {
                        throw std::runtime_error("Invalid property \"part\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, occupied, part);
        }
    }

}
