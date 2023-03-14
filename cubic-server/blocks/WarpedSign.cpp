#include "WarpedSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WarpedSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18680;
                case Properties::Waterlogged::FALSE:
                    return 18681;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18682;
                case Properties::Waterlogged::FALSE:
                    return 18683;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18684;
                case Properties::Waterlogged::FALSE:
                    return 18685;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18686;
                case Properties::Waterlogged::FALSE:
                    return 18687;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18688;
                case Properties::Waterlogged::FALSE:
                    return 18689;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18690;
                case Properties::Waterlogged::FALSE:
                    return 18691;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18692;
                case Properties::Waterlogged::FALSE:
                    return 18693;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18694;
                case Properties::Waterlogged::FALSE:
                    return 18695;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18696;
                case Properties::Waterlogged::FALSE:
                    return 18697;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18698;
                case Properties::Waterlogged::FALSE:
                    return 18699;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18700;
                case Properties::Waterlogged::FALSE:
                    return 18701;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18702;
                case Properties::Waterlogged::FALSE:
                    return 18703;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18704;
                case Properties::Waterlogged::FALSE:
                    return 18705;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18706;
                case Properties::Waterlogged::FALSE:
                    return 18707;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18708;
                case Properties::Waterlogged::FALSE:
                    return 18709;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18710;
                case Properties::Waterlogged::FALSE:
                    return 18711;
                }
            }
            return 0;
        }
    }

}
