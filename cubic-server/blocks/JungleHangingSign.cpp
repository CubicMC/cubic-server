#include "JungleHangingSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace JungleHangingSign {
BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged)
{
    switch (attached) {
    case Properties::Attached::TRUE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4998;
            case Properties::Waterlogged::FALSE:
                return 4999;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5000;
            case Properties::Waterlogged::FALSE:
                return 5001;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5002;
            case Properties::Waterlogged::FALSE:
                return 5003;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5004;
            case Properties::Waterlogged::FALSE:
                return 5005;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5006;
            case Properties::Waterlogged::FALSE:
                return 5007;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5008;
            case Properties::Waterlogged::FALSE:
                return 5009;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5010;
            case Properties::Waterlogged::FALSE:
                return 5011;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5012;
            case Properties::Waterlogged::FALSE:
                return 5013;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5014;
            case Properties::Waterlogged::FALSE:
                return 5015;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5016;
            case Properties::Waterlogged::FALSE:
                return 5017;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5018;
            case Properties::Waterlogged::FALSE:
                return 5019;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5020;
            case Properties::Waterlogged::FALSE:
                return 5021;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5022;
            case Properties::Waterlogged::FALSE:
                return 5023;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5024;
            case Properties::Waterlogged::FALSE:
                return 5025;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5026;
            case Properties::Waterlogged::FALSE:
                return 5027;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5028;
            case Properties::Waterlogged::FALSE:
                return 5029;
            }
        }
    case Properties::Attached::FALSE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5030;
            case Properties::Waterlogged::FALSE:
                return 5031;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5032;
            case Properties::Waterlogged::FALSE:
                return 5033;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5034;
            case Properties::Waterlogged::FALSE:
                return 5035;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5036;
            case Properties::Waterlogged::FALSE:
                return 5037;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5038;
            case Properties::Waterlogged::FALSE:
                return 5039;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5040;
            case Properties::Waterlogged::FALSE:
                return 5041;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5042;
            case Properties::Waterlogged::FALSE:
                return 5043;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5044;
            case Properties::Waterlogged::FALSE:
                return 5045;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5046;
            case Properties::Waterlogged::FALSE:
                return 5047;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5048;
            case Properties::Waterlogged::FALSE:
                return 5049;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5050;
            case Properties::Waterlogged::FALSE:
                return 5051;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5052;
            case Properties::Waterlogged::FALSE:
                return 5053;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5054;
            case Properties::Waterlogged::FALSE:
                return 5055;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5056;
            case Properties::Waterlogged::FALSE:
                return 5057;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5058;
            case Properties::Waterlogged::FALSE:
                return 5059;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 5060;
            case Properties::Waterlogged::FALSE:
                return 5061;
            }
        }
    }
    return 0;
}
}

}
