#include "SculkSensor.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SculkSensor {
        BlockId toProtocol(Properties::Power power, Properties::Sculk_sensor_phase sculk_sensor_phase, Properties::Waterlogged waterlogged) {
            switch (power) {
            case Properties::Power::ZERO:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18673;
                    case Properties::Waterlogged::FALSE:
                        return 18674;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18675;
                    case Properties::Waterlogged::FALSE:
                        return 18676;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18677;
                    case Properties::Waterlogged::FALSE:
                        return 18678;
                    }
                }
            case Properties::Power::ONE:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18679;
                    case Properties::Waterlogged::FALSE:
                        return 18680;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18681;
                    case Properties::Waterlogged::FALSE:
                        return 18682;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18683;
                    case Properties::Waterlogged::FALSE:
                        return 18684;
                    }
                }
            case Properties::Power::TWO:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18685;
                    case Properties::Waterlogged::FALSE:
                        return 18686;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18687;
                    case Properties::Waterlogged::FALSE:
                        return 18688;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18689;
                    case Properties::Waterlogged::FALSE:
                        return 18690;
                    }
                }
            case Properties::Power::THREE:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18691;
                    case Properties::Waterlogged::FALSE:
                        return 18692;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18693;
                    case Properties::Waterlogged::FALSE:
                        return 18694;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18695;
                    case Properties::Waterlogged::FALSE:
                        return 18696;
                    }
                }
            case Properties::Power::FOUR:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18697;
                    case Properties::Waterlogged::FALSE:
                        return 18698;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18699;
                    case Properties::Waterlogged::FALSE:
                        return 18700;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18701;
                    case Properties::Waterlogged::FALSE:
                        return 18702;
                    }
                }
            case Properties::Power::FIVE:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18703;
                    case Properties::Waterlogged::FALSE:
                        return 18704;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18705;
                    case Properties::Waterlogged::FALSE:
                        return 18706;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18707;
                    case Properties::Waterlogged::FALSE:
                        return 18708;
                    }
                }
            case Properties::Power::SIX:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18709;
                    case Properties::Waterlogged::FALSE:
                        return 18710;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18711;
                    case Properties::Waterlogged::FALSE:
                        return 18712;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18713;
                    case Properties::Waterlogged::FALSE:
                        return 18714;
                    }
                }
            case Properties::Power::SEVEN:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18715;
                    case Properties::Waterlogged::FALSE:
                        return 18716;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18717;
                    case Properties::Waterlogged::FALSE:
                        return 18718;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18719;
                    case Properties::Waterlogged::FALSE:
                        return 18720;
                    }
                }
            case Properties::Power::EIGHT:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18721;
                    case Properties::Waterlogged::FALSE:
                        return 18722;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18723;
                    case Properties::Waterlogged::FALSE:
                        return 18724;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18725;
                    case Properties::Waterlogged::FALSE:
                        return 18726;
                    }
                }
            case Properties::Power::NINE:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18727;
                    case Properties::Waterlogged::FALSE:
                        return 18728;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18729;
                    case Properties::Waterlogged::FALSE:
                        return 18730;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18731;
                    case Properties::Waterlogged::FALSE:
                        return 18732;
                    }
                }
            case Properties::Power::TEN:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18733;
                    case Properties::Waterlogged::FALSE:
                        return 18734;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18735;
                    case Properties::Waterlogged::FALSE:
                        return 18736;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18737;
                    case Properties::Waterlogged::FALSE:
                        return 18738;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18739;
                    case Properties::Waterlogged::FALSE:
                        return 18740;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18741;
                    case Properties::Waterlogged::FALSE:
                        return 18742;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18743;
                    case Properties::Waterlogged::FALSE:
                        return 18744;
                    }
                }
            case Properties::Power::TWELVE:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18745;
                    case Properties::Waterlogged::FALSE:
                        return 18746;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18747;
                    case Properties::Waterlogged::FALSE:
                        return 18748;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18749;
                    case Properties::Waterlogged::FALSE:
                        return 18750;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18751;
                    case Properties::Waterlogged::FALSE:
                        return 18752;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18753;
                    case Properties::Waterlogged::FALSE:
                        return 18754;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18755;
                    case Properties::Waterlogged::FALSE:
                        return 18756;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18757;
                    case Properties::Waterlogged::FALSE:
                        return 18758;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18759;
                    case Properties::Waterlogged::FALSE:
                        return 18760;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18761;
                    case Properties::Waterlogged::FALSE:
                        return 18762;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (sculk_sensor_phase) {
                case Properties::Sculk_sensor_phase::INACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18763;
                    case Properties::Waterlogged::FALSE:
                        return 18764;
                    }
                case Properties::Sculk_sensor_phase::ACTIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18765;
                    case Properties::Waterlogged::FALSE:
                        return 18766;
                    }
                case Properties::Sculk_sensor_phase::COOLDOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18767;
                    case Properties::Waterlogged::FALSE:
                        return 18768;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Power power;
            Properties::Sculk_sensor_phase sculk_sensor_phase;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "power") {
                    if (prop.second == "0") {
                        power = Properties::Power::ZERO;
                    } else if (prop.second == "1") {
                        power = Properties::Power::ONE;
                    } else if (prop.second == "2") {
                        power = Properties::Power::TWO;
                    } else if (prop.second == "3") {
                        power = Properties::Power::THREE;
                    } else if (prop.second == "4") {
                        power = Properties::Power::FOUR;
                    } else if (prop.second == "5") {
                        power = Properties::Power::FIVE;
                    } else if (prop.second == "6") {
                        power = Properties::Power::SIX;
                    } else if (prop.second == "7") {
                        power = Properties::Power::SEVEN;
                    } else if (prop.second == "8") {
                        power = Properties::Power::EIGHT;
                    } else if (prop.second == "9") {
                        power = Properties::Power::NINE;
                    } else if (prop.second == "10") {
                        power = Properties::Power::TEN;
                    } else if (prop.second == "11") {
                        power = Properties::Power::ELEVEN;
                    } else if (prop.second == "12") {
                        power = Properties::Power::TWELVE;
                    } else if (prop.second == "13") {
                        power = Properties::Power::THIRTEEN;
                    } else if (prop.second == "14") {
                        power = Properties::Power::FOURTEEN;
                    } else if (prop.second == "15") {
                        power = Properties::Power::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"power\" value");
                    }
                } else if (prop.first == "sculk_sensor_phase") {
                    if (prop.second == "inactive") {
                        sculk_sensor_phase = Properties::Sculk_sensor_phase::INACTIVE;
                    } else if (prop.second == "active") {
                        sculk_sensor_phase = Properties::Sculk_sensor_phase::ACTIVE;
                    } else if (prop.second == "cooldown") {
                        sculk_sensor_phase = Properties::Sculk_sensor_phase::COOLDOWN;
                    } else {
                        throw std::runtime_error("Invalid property \"sculk_sensor_phase\" value");
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
            return toProtocol(power, sculk_sensor_phase, waterlogged);
        }
    }

}
