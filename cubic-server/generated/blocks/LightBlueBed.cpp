#include "LightBlueBed.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LightBlueBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1327;
                    case Properties::Part::FOOT:
                        return 1328;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1329;
                    case Properties::Part::FOOT:
                        return 1330;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1331;
                    case Properties::Part::FOOT:
                        return 1332;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1333;
                    case Properties::Part::FOOT:
                        return 1334;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1335;
                    case Properties::Part::FOOT:
                        return 1336;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1337;
                    case Properties::Part::FOOT:
                        return 1338;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1339;
                    case Properties::Part::FOOT:
                        return 1340;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1341;
                    case Properties::Part::FOOT:
                        return 1342;
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
