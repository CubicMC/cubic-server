#include "Campfire.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Campfire {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16099;
                        case Properties::Waterlogged::FALSE:
                            return 16100;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16101;
                        case Properties::Waterlogged::FALSE:
                            return 16102;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16103;
                        case Properties::Waterlogged::FALSE:
                            return 16104;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16105;
                        case Properties::Waterlogged::FALSE:
                            return 16106;
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16107;
                        case Properties::Waterlogged::FALSE:
                            return 16108;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16109;
                        case Properties::Waterlogged::FALSE:
                            return 16110;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16111;
                        case Properties::Waterlogged::FALSE:
                            return 16112;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16113;
                        case Properties::Waterlogged::FALSE:
                            return 16114;
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16115;
                        case Properties::Waterlogged::FALSE:
                            return 16116;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16117;
                        case Properties::Waterlogged::FALSE:
                            return 16118;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16119;
                        case Properties::Waterlogged::FALSE:
                            return 16120;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16121;
                        case Properties::Waterlogged::FALSE:
                            return 16122;
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16123;
                        case Properties::Waterlogged::FALSE:
                            return 16124;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16125;
                        case Properties::Waterlogged::FALSE:
                            return 16126;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16127;
                        case Properties::Waterlogged::FALSE:
                            return 16128;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16129;
                        case Properties::Waterlogged::FALSE:
                            return 16130;
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
            Properties::Lit lit;
            Properties::Signal_fire signal_fire;
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
                } else if (prop.first == "lit") {
                    if (prop.second == "true") {
                        lit = Properties::Lit::TRUE;
                    } else if (prop.second == "false") {
                        lit = Properties::Lit::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"lit\" value");
                    }
                } else if (prop.first == "signal_fire") {
                    if (prop.second == "true") {
                        signal_fire = Properties::Signal_fire::TRUE;
                    } else if (prop.second == "false") {
                        signal_fire = Properties::Signal_fire::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"signal_fire\" value");
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
            return toProtocol(facing, lit, signal_fire, waterlogged);
        }
    }

}
