#include "AcaciaHangingSign.hpp"
namespace Blocks {
    namespace AcaciaHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4934;
                    case Properties::Waterlogged::FALSE:
                        return 4935;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4936;
                    case Properties::Waterlogged::FALSE:
                        return 4937;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4938;
                    case Properties::Waterlogged::FALSE:
                        return 4939;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4940;
                    case Properties::Waterlogged::FALSE:
                        return 4941;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4942;
                    case Properties::Waterlogged::FALSE:
                        return 4943;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4944;
                    case Properties::Waterlogged::FALSE:
                        return 4945;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4946;
                    case Properties::Waterlogged::FALSE:
                        return 4947;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4948;
                    case Properties::Waterlogged::FALSE:
                        return 4949;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4950;
                    case Properties::Waterlogged::FALSE:
                        return 4951;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4952;
                    case Properties::Waterlogged::FALSE:
                        return 4953;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4954;
                    case Properties::Waterlogged::FALSE:
                        return 4955;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4956;
                    case Properties::Waterlogged::FALSE:
                        return 4957;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4958;
                    case Properties::Waterlogged::FALSE:
                        return 4959;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4960;
                    case Properties::Waterlogged::FALSE:
                        return 4961;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4962;
                    case Properties::Waterlogged::FALSE:
                        return 4963;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4964;
                    case Properties::Waterlogged::FALSE:
                        return 4965;
                    }
                }
            case Properties::Attached::FALSE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4966;
                    case Properties::Waterlogged::FALSE:
                        return 4967;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4968;
                    case Properties::Waterlogged::FALSE:
                        return 4969;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4970;
                    case Properties::Waterlogged::FALSE:
                        return 4971;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4972;
                    case Properties::Waterlogged::FALSE:
                        return 4973;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4974;
                    case Properties::Waterlogged::FALSE:
                        return 4975;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4976;
                    case Properties::Waterlogged::FALSE:
                        return 4977;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4978;
                    case Properties::Waterlogged::FALSE:
                        return 4979;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4980;
                    case Properties::Waterlogged::FALSE:
                        return 4981;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4982;
                    case Properties::Waterlogged::FALSE:
                        return 4983;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4984;
                    case Properties::Waterlogged::FALSE:
                        return 4985;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4986;
                    case Properties::Waterlogged::FALSE:
                        return 4987;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4988;
                    case Properties::Waterlogged::FALSE:
                        return 4989;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4990;
                    case Properties::Waterlogged::FALSE:
                        return 4991;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4992;
                    case Properties::Waterlogged::FALSE:
                        return 4993;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4994;
                    case Properties::Waterlogged::FALSE:
                        return 4995;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4996;
                    case Properties::Waterlogged::FALSE:
                        return 4997;
                    }
                }
            }
            return 0;
        }
    }

}
