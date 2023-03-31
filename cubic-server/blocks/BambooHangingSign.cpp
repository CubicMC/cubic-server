#include "BambooHangingSign.hpp"
#include <stdexcept>

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
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5320;
            case Properties::Waterlogged::FALSE:
                return 5321;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5322;
            case Properties::Waterlogged::FALSE:
                return 5323;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5324;
            case Properties::Waterlogged::FALSE:
                return 5325;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5326;
            case Properties::Waterlogged::FALSE:
                return 5327;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5328;
            case Properties::Waterlogged::FALSE:
                return 5329;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5330;
            case Properties::Waterlogged::FALSE:
                return 5331;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5332;
            case Properties::Waterlogged::FALSE:
                return 5333;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5334;
            case Properties::Waterlogged::FALSE:
                return 5335;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5336;
            case Properties::Waterlogged::FALSE:
                return 5337;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5338;
            case Properties::Waterlogged::FALSE:
                return 5339;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5340;
            case Properties::Waterlogged::FALSE:
                return 5341;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5342;
            case Properties::Waterlogged::FALSE:
                return 5343;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5344;
            case Properties::Waterlogged::FALSE:
                return 5345;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5346;
            case Properties::Waterlogged::FALSE:
                return 5347;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5348;
            case Properties::Waterlogged::FALSE:
                return 5349;
            }
        }
    case Properties::Attached::FALSE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5350;
            case Properties::Waterlogged::FALSE:
                return 5351;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5352;
            case Properties::Waterlogged::FALSE:
                return 5353;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5354;
            case Properties::Waterlogged::FALSE:
                return 5355;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5356;
            case Properties::Waterlogged::FALSE:
                return 5357;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5358;
            case Properties::Waterlogged::FALSE:
                return 5359;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5360;
            case Properties::Waterlogged::FALSE:
                return 5361;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5362;
            case Properties::Waterlogged::FALSE:
                return 5363;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5364;
            case Properties::Waterlogged::FALSE:
                return 5365;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5366;
            case Properties::Waterlogged::FALSE:
                return 5367;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5368;
            case Properties::Waterlogged::FALSE:
                return 5369;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5370;
            case Properties::Waterlogged::FALSE:
                return 5371;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5372;
            case Properties::Waterlogged::FALSE:
                return 5373;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5374;
            case Properties::Waterlogged::FALSE:
                return 5375;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5376;
            case Properties::Waterlogged::FALSE:
                return 5377;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5378;
            case Properties::Waterlogged::FALSE:
                return 5379;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5380;
            case Properties::Waterlogged::FALSE:
                return 5381;
            }
        }
    }
    return 0;
}
}

}
