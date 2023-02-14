#include "WhiteBed.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WhiteBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1279;
                    case Properties::Part::FOOT:
                        return 1280;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1281;
                    case Properties::Part::FOOT:
                        return 1282;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1283;
                    case Properties::Part::FOOT:
                        return 1284;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1285;
                    case Properties::Part::FOOT:
                        return 1286;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1287;
                    case Properties::Part::FOOT:
                        return 1288;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1289;
                    case Properties::Part::FOOT:
                        return 1290;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1291;
                    case Properties::Part::FOOT:
                        return 1292;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1293;
                    case Properties::Part::FOOT:
                        return 1294;
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
