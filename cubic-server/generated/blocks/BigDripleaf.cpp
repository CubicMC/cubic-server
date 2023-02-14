#include "BigDripleaf.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BigDripleaf {
        BlockId toProtocol(Properties::Facing facing, Properties::Tilt tilt, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (tilt) {
                case Properties::Tilt::NONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19718;
                    case Properties::Waterlogged::FALSE:
                        return 19719;
                    }
                case Properties::Tilt::UNSTABLE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19720;
                    case Properties::Waterlogged::FALSE:
                        return 19721;
                    }
                case Properties::Tilt::PARTIAL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19722;
                    case Properties::Waterlogged::FALSE:
                        return 19723;
                    }
                case Properties::Tilt::FULL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19724;
                    case Properties::Waterlogged::FALSE:
                        return 19725;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (tilt) {
                case Properties::Tilt::NONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19726;
                    case Properties::Waterlogged::FALSE:
                        return 19727;
                    }
                case Properties::Tilt::UNSTABLE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19728;
                    case Properties::Waterlogged::FALSE:
                        return 19729;
                    }
                case Properties::Tilt::PARTIAL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19730;
                    case Properties::Waterlogged::FALSE:
                        return 19731;
                    }
                case Properties::Tilt::FULL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19732;
                    case Properties::Waterlogged::FALSE:
                        return 19733;
                    }
                }
            case Properties::Facing::WEST:
                switch (tilt) {
                case Properties::Tilt::NONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19734;
                    case Properties::Waterlogged::FALSE:
                        return 19735;
                    }
                case Properties::Tilt::UNSTABLE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19736;
                    case Properties::Waterlogged::FALSE:
                        return 19737;
                    }
                case Properties::Tilt::PARTIAL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19738;
                    case Properties::Waterlogged::FALSE:
                        return 19739;
                    }
                case Properties::Tilt::FULL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19740;
                    case Properties::Waterlogged::FALSE:
                        return 19741;
                    }
                }
            case Properties::Facing::EAST:
                switch (tilt) {
                case Properties::Tilt::NONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19742;
                    case Properties::Waterlogged::FALSE:
                        return 19743;
                    }
                case Properties::Tilt::UNSTABLE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19744;
                    case Properties::Waterlogged::FALSE:
                        return 19745;
                    }
                case Properties::Tilt::PARTIAL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19746;
                    case Properties::Waterlogged::FALSE:
                        return 19747;
                    }
                case Properties::Tilt::FULL:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19748;
                    case Properties::Waterlogged::FALSE:
                        return 19749;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Tilt tilt;
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
                } else if (prop.first == "tilt") {
                    if (prop.second == "none") {
                        tilt = Properties::Tilt::NONE;
                    } else if (prop.second == "unstable") {
                        tilt = Properties::Tilt::UNSTABLE;
                    } else if (prop.second == "partial") {
                        tilt = Properties::Tilt::PARTIAL;
                    } else if (prop.second == "full") {
                        tilt = Properties::Tilt::FULL;
                    } else {
                        throw std::runtime_error("Invalid property \"tilt\" value");
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
            return toProtocol(facing, tilt, waterlogged);
        }
    }

}
