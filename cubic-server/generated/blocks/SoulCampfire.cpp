#include "SoulCampfire.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SoulCampfire {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16131;
                        case Properties::Waterlogged::FALSE:
                            return 16132;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16133;
                        case Properties::Waterlogged::FALSE:
                            return 16134;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16135;
                        case Properties::Waterlogged::FALSE:
                            return 16136;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16137;
                        case Properties::Waterlogged::FALSE:
                            return 16138;
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
                            return 16139;
                        case Properties::Waterlogged::FALSE:
                            return 16140;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16141;
                        case Properties::Waterlogged::FALSE:
                            return 16142;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16143;
                        case Properties::Waterlogged::FALSE:
                            return 16144;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16145;
                        case Properties::Waterlogged::FALSE:
                            return 16146;
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
                            return 16147;
                        case Properties::Waterlogged::FALSE:
                            return 16148;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16149;
                        case Properties::Waterlogged::FALSE:
                            return 16150;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16151;
                        case Properties::Waterlogged::FALSE:
                            return 16152;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16153;
                        case Properties::Waterlogged::FALSE:
                            return 16154;
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
                            return 16155;
                        case Properties::Waterlogged::FALSE:
                            return 16156;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16157;
                        case Properties::Waterlogged::FALSE:
                            return 16158;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16159;
                        case Properties::Waterlogged::FALSE:
                            return 16160;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 16161;
                        case Properties::Waterlogged::FALSE:
                            return 16162;
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
