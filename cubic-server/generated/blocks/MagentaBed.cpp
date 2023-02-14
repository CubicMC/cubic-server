#include "MagentaBed.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MagentaBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1311;
                    case Properties::Part::FOOT:
                        return 1312;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1313;
                    case Properties::Part::FOOT:
                        return 1314;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1315;
                    case Properties::Part::FOOT:
                        return 1316;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1317;
                    case Properties::Part::FOOT:
                        return 1318;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1319;
                    case Properties::Part::FOOT:
                        return 1320;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1321;
                    case Properties::Part::FOOT:
                        return 1322;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1323;
                    case Properties::Part::FOOT:
                        return 1324;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1325;
                    case Properties::Part::FOOT:
                        return 1326;
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
