#include "BambooHangingSign.hpp"
namespace Blocks {
namespace BambooHangingSign {
BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged)
{
    switch (attached) {
    case Properties::Attached::TRUE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5318;
            case Properties::Waterlogged::FALSE:
                return 5319;
            default:
                return 0;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5320;
            case Properties::Waterlogged::FALSE:
                return 5321;
            default:
                return 0;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5322;
            case Properties::Waterlogged::FALSE:
                return 5323;
            default:
                return 0;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5324;
            case Properties::Waterlogged::FALSE:
                return 5325;
            default:
                return 0;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5326;
            case Properties::Waterlogged::FALSE:
                return 5327;
            default:
                return 0;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5328;
            case Properties::Waterlogged::FALSE:
                return 5329;
            default:
                return 0;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5330;
            case Properties::Waterlogged::FALSE:
                return 5331;
            default:
                return 0;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5332;
            case Properties::Waterlogged::FALSE:
                return 5333;
            default:
                return 0;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5334;
            case Properties::Waterlogged::FALSE:
                return 5335;
            default:
                return 0;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5336;
            case Properties::Waterlogged::FALSE:
                return 5337;
            default:
                return 0;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5338;
            case Properties::Waterlogged::FALSE:
                return 5339;
            default:
                return 0;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5340;
            case Properties::Waterlogged::FALSE:
                return 5341;
            default:
                return 0;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5342;
            case Properties::Waterlogged::FALSE:
                return 5343;
            default:
                return 0;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5344;
            case Properties::Waterlogged::FALSE:
                return 5345;
            default:
                return 0;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5346;
            case Properties::Waterlogged::FALSE:
                return 5347;
            default:
                return 0;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5348;
            case Properties::Waterlogged::FALSE:
                return 5349;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Attached::FALSE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5350;
            case Properties::Waterlogged::FALSE:
                return 5351;
            default:
                return 0;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5352;
            case Properties::Waterlogged::FALSE:
                return 5353;
            default:
                return 0;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5354;
            case Properties::Waterlogged::FALSE:
                return 5355;
            default:
                return 0;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5356;
            case Properties::Waterlogged::FALSE:
                return 5357;
            default:
                return 0;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5358;
            case Properties::Waterlogged::FALSE:
                return 5359;
            default:
                return 0;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5360;
            case Properties::Waterlogged::FALSE:
                return 5361;
            default:
                return 0;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5362;
            case Properties::Waterlogged::FALSE:
                return 5363;
            default:
                return 0;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5364;
            case Properties::Waterlogged::FALSE:
                return 5365;
            default:
                return 0;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5366;
            case Properties::Waterlogged::FALSE:
                return 5367;
            default:
                return 0;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5368;
            case Properties::Waterlogged::FALSE:
                return 5369;
            default:
                return 0;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5370;
            case Properties::Waterlogged::FALSE:
                return 5371;
            default:
                return 0;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5372;
            case Properties::Waterlogged::FALSE:
                return 5373;
            default:
                return 0;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5374;
            case Properties::Waterlogged::FALSE:
                return 5375;
            default:
                return 0;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5376;
            case Properties::Waterlogged::FALSE:
                return 5377;
            default:
                return 0;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5378;
            case Properties::Waterlogged::FALSE:
                return 5379;
            default:
                return 0;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5380;
            case Properties::Waterlogged::FALSE:
                return 5381;
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
