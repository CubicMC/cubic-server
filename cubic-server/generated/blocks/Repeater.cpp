#include "Repeater.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Repeater {
        BlockId toProtocol(Properties::Delay delay, Properties::Facing facing, Properties::Locked locked, Properties::Powered powered) {
            switch (delay) {
            case Properties::Delay::ONE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4340;
                        case Properties::Powered::FALSE:
                            return 4341;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4342;
                        case Properties::Powered::FALSE:
                            return 4343;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4344;
                        case Properties::Powered::FALSE:
                            return 4345;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4346;
                        case Properties::Powered::FALSE:
                            return 4347;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4348;
                        case Properties::Powered::FALSE:
                            return 4349;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4350;
                        case Properties::Powered::FALSE:
                            return 4351;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4352;
                        case Properties::Powered::FALSE:
                            return 4353;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4354;
                        case Properties::Powered::FALSE:
                            return 4355;
                        }
                    }
                }
            case Properties::Delay::TWO:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4356;
                        case Properties::Powered::FALSE:
                            return 4357;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4358;
                        case Properties::Powered::FALSE:
                            return 4359;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4360;
                        case Properties::Powered::FALSE:
                            return 4361;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4362;
                        case Properties::Powered::FALSE:
                            return 4363;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4364;
                        case Properties::Powered::FALSE:
                            return 4365;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4366;
                        case Properties::Powered::FALSE:
                            return 4367;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4368;
                        case Properties::Powered::FALSE:
                            return 4369;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4370;
                        case Properties::Powered::FALSE:
                            return 4371;
                        }
                    }
                }
            case Properties::Delay::THREE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4372;
                        case Properties::Powered::FALSE:
                            return 4373;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4374;
                        case Properties::Powered::FALSE:
                            return 4375;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4376;
                        case Properties::Powered::FALSE:
                            return 4377;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4378;
                        case Properties::Powered::FALSE:
                            return 4379;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4380;
                        case Properties::Powered::FALSE:
                            return 4381;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4382;
                        case Properties::Powered::FALSE:
                            return 4383;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4384;
                        case Properties::Powered::FALSE:
                            return 4385;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4386;
                        case Properties::Powered::FALSE:
                            return 4387;
                        }
                    }
                }
            case Properties::Delay::FOUR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4388;
                        case Properties::Powered::FALSE:
                            return 4389;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4390;
                        case Properties::Powered::FALSE:
                            return 4391;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4392;
                        case Properties::Powered::FALSE:
                            return 4393;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4394;
                        case Properties::Powered::FALSE:
                            return 4395;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4396;
                        case Properties::Powered::FALSE:
                            return 4397;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4398;
                        case Properties::Powered::FALSE:
                            return 4399;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4400;
                        case Properties::Powered::FALSE:
                            return 4401;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 4402;
                        case Properties::Powered::FALSE:
                            return 4403;
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 4)
            throw std::runtime_error("Invalid number of properties");
            Properties::Delay delay;
            Properties::Facing facing;
            Properties::Locked locked;
            Properties::Powered powered;
            for (auto prop : properties) {
                if (prop.first == "delay") {
                    if (prop.second == "1") {
                        delay = Properties::Delay::ONE;
                    } else if (prop.second == "2") {
                        delay = Properties::Delay::TWO;
                    } else if (prop.second == "3") {
                        delay = Properties::Delay::THREE;
                    } else if (prop.second == "4") {
                        delay = Properties::Delay::FOUR;
                    } else {
                        throw std::runtime_error("Invalid property \"delay\" value");
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
                } else if (prop.first == "locked") {
                    if (prop.second == "true") {
                        locked = Properties::Locked::TRUE;
                    } else if (prop.second == "false") {
                        locked = Properties::Locked::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"locked\" value");
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
            return toProtocol(delay, facing, locked, powered);
        }
    }

}
