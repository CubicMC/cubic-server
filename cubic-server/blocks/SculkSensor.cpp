#include "SculkSensor.hpp"
namespace Blocks {
namespace SculkSensor {
BlockId toProtocol(Properties::Power power, Properties::Sculk_sensor_phase sculk_sensor_phase, Properties::Waterlogged waterlogged) {
    switch (power) {
    case Properties::Power::ZERO:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20457;
            case Properties::Waterlogged::FALSE:
                return 20458;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20459;
            case Properties::Waterlogged::FALSE:
                return 20460;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20461;
            case Properties::Waterlogged::FALSE:
                return 20462;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::ONE:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20463;
            case Properties::Waterlogged::FALSE:
                return 20464;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20465;
            case Properties::Waterlogged::FALSE:
                return 20466;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20467;
            case Properties::Waterlogged::FALSE:
                return 20468;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::TWO:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20469;
            case Properties::Waterlogged::FALSE:
                return 20470;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20471;
            case Properties::Waterlogged::FALSE:
                return 20472;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20473;
            case Properties::Waterlogged::FALSE:
                return 20474;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::THREE:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20475;
            case Properties::Waterlogged::FALSE:
                return 20476;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20477;
            case Properties::Waterlogged::FALSE:
                return 20478;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20479;
            case Properties::Waterlogged::FALSE:
                return 20480;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::FOUR:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20481;
            case Properties::Waterlogged::FALSE:
                return 20482;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20483;
            case Properties::Waterlogged::FALSE:
                return 20484;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20485;
            case Properties::Waterlogged::FALSE:
                return 20486;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::FIVE:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20487;
            case Properties::Waterlogged::FALSE:
                return 20488;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20489;
            case Properties::Waterlogged::FALSE:
                return 20490;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20491;
            case Properties::Waterlogged::FALSE:
                return 20492;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::SIX:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20493;
            case Properties::Waterlogged::FALSE:
                return 20494;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20495;
            case Properties::Waterlogged::FALSE:
                return 20496;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20497;
            case Properties::Waterlogged::FALSE:
                return 20498;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::SEVEN:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20499;
            case Properties::Waterlogged::FALSE:
                return 20500;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20501;
            case Properties::Waterlogged::FALSE:
                return 20502;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20503;
            case Properties::Waterlogged::FALSE:
                return 20504;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::EIGHT:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20505;
            case Properties::Waterlogged::FALSE:
                return 20506;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20507;
            case Properties::Waterlogged::FALSE:
                return 20508;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20509;
            case Properties::Waterlogged::FALSE:
                return 20510;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::NINE:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20511;
            case Properties::Waterlogged::FALSE:
                return 20512;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20513;
            case Properties::Waterlogged::FALSE:
                return 20514;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20515;
            case Properties::Waterlogged::FALSE:
                return 20516;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::TEN:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20517;
            case Properties::Waterlogged::FALSE:
                return 20518;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20519;
            case Properties::Waterlogged::FALSE:
                return 20520;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20521;
            case Properties::Waterlogged::FALSE:
                return 20522;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::ELEVEN:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20523;
            case Properties::Waterlogged::FALSE:
                return 20524;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20525;
            case Properties::Waterlogged::FALSE:
                return 20526;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20527;
            case Properties::Waterlogged::FALSE:
                return 20528;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::TWELVE:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20529;
            case Properties::Waterlogged::FALSE:
                return 20530;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20531;
            case Properties::Waterlogged::FALSE:
                return 20532;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20533;
            case Properties::Waterlogged::FALSE:
                return 20534;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::THIRTEEN:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20535;
            case Properties::Waterlogged::FALSE:
                return 20536;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20537;
            case Properties::Waterlogged::FALSE:
                return 20538;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20539;
            case Properties::Waterlogged::FALSE:
                return 20540;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::FOURTEEN:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20541;
            case Properties::Waterlogged::FALSE:
                return 20542;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20543;
            case Properties::Waterlogged::FALSE:
                return 20544;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20545;
            case Properties::Waterlogged::FALSE:
                return 20546;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Power::FIFTEEN:
        switch (sculk_sensor_phase) {
        case Properties::Sculk_sensor_phase::INACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20547;
            case Properties::Waterlogged::FALSE:
                return 20548;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::ACTIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20549;
            case Properties::Waterlogged::FALSE:
                return 20550;
            default:
                return 0;
            }
        case Properties::Sculk_sensor_phase::COOLDOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20551;
            case Properties::Waterlogged::FALSE:
                return 20552;
            default:
                return 0;
            }
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
