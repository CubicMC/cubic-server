#include "BirchHangingSign.hpp"
namespace Blocks {
    namespace BirchHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4870;
                    case Properties::Waterlogged::FALSE:
                        return 4871;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4872;
                    case Properties::Waterlogged::FALSE:
                        return 4873;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4874;
                    case Properties::Waterlogged::FALSE:
                        return 4875;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4876;
                    case Properties::Waterlogged::FALSE:
                        return 4877;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4878;
                    case Properties::Waterlogged::FALSE:
                        return 4879;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4880;
                    case Properties::Waterlogged::FALSE:
                        return 4881;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4882;
                    case Properties::Waterlogged::FALSE:
                        return 4883;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4884;
                    case Properties::Waterlogged::FALSE:
                        return 4885;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4886;
                    case Properties::Waterlogged::FALSE:
                        return 4887;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4888;
                    case Properties::Waterlogged::FALSE:
                        return 4889;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4890;
                    case Properties::Waterlogged::FALSE:
                        return 4891;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4892;
                    case Properties::Waterlogged::FALSE:
                        return 4893;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4894;
                    case Properties::Waterlogged::FALSE:
                        return 4895;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4896;
                    case Properties::Waterlogged::FALSE:
                        return 4897;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4898;
                    case Properties::Waterlogged::FALSE:
                        return 4899;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4900;
                    case Properties::Waterlogged::FALSE:
                        return 4901;
                    }
                }
            case Properties::Attached::FALSE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4902;
                    case Properties::Waterlogged::FALSE:
                        return 4903;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4904;
                    case Properties::Waterlogged::FALSE:
                        return 4905;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4906;
                    case Properties::Waterlogged::FALSE:
                        return 4907;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4908;
                    case Properties::Waterlogged::FALSE:
                        return 4909;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4910;
                    case Properties::Waterlogged::FALSE:
                        return 4911;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4912;
                    case Properties::Waterlogged::FALSE:
                        return 4913;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4914;
                    case Properties::Waterlogged::FALSE:
                        return 4915;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4916;
                    case Properties::Waterlogged::FALSE:
                        return 4917;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4918;
                    case Properties::Waterlogged::FALSE:
                        return 4919;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4920;
                    case Properties::Waterlogged::FALSE:
                        return 4921;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4922;
                    case Properties::Waterlogged::FALSE:
                        return 4923;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4924;
                    case Properties::Waterlogged::FALSE:
                        return 4925;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4926;
                    case Properties::Waterlogged::FALSE:
                        return 4927;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4928;
                    case Properties::Waterlogged::FALSE:
                        return 4929;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4930;
                    case Properties::Waterlogged::FALSE:
                        return 4931;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4932;
                    case Properties::Waterlogged::FALSE:
                        return 4933;
                    }
                }
            }
            return 0;
        }
    }

}
