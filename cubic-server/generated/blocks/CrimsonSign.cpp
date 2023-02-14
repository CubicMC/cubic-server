#include "CrimsonSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CrimsonSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16864;
                case Properties::Waterlogged::FALSE:
                    return 16865;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16866;
                case Properties::Waterlogged::FALSE:
                    return 16867;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16868;
                case Properties::Waterlogged::FALSE:
                    return 16869;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16870;
                case Properties::Waterlogged::FALSE:
                    return 16871;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16872;
                case Properties::Waterlogged::FALSE:
                    return 16873;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16874;
                case Properties::Waterlogged::FALSE:
                    return 16875;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16876;
                case Properties::Waterlogged::FALSE:
                    return 16877;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16878;
                case Properties::Waterlogged::FALSE:
                    return 16879;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16880;
                case Properties::Waterlogged::FALSE:
                    return 16881;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16882;
                case Properties::Waterlogged::FALSE:
                    return 16883;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16884;
                case Properties::Waterlogged::FALSE:
                    return 16885;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16886;
                case Properties::Waterlogged::FALSE:
                    return 16887;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16888;
                case Properties::Waterlogged::FALSE:
                    return 16889;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16890;
                case Properties::Waterlogged::FALSE:
                    return 16891;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16892;
                case Properties::Waterlogged::FALSE:
                    return 16893;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16894;
                case Properties::Waterlogged::FALSE:
                    return 16895;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Rotation rotation;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "rotation") {
                    if (prop.second == "0") {
                        rotation = Properties::Rotation::ZERO;
                    } else if (prop.second == "1") {
                        rotation = Properties::Rotation::ONE;
                    } else if (prop.second == "2") {
                        rotation = Properties::Rotation::TWO;
                    } else if (prop.second == "3") {
                        rotation = Properties::Rotation::THREE;
                    } else if (prop.second == "4") {
                        rotation = Properties::Rotation::FOUR;
                    } else if (prop.second == "5") {
                        rotation = Properties::Rotation::FIVE;
                    } else if (prop.second == "6") {
                        rotation = Properties::Rotation::SIX;
                    } else if (prop.second == "7") {
                        rotation = Properties::Rotation::SEVEN;
                    } else if (prop.second == "8") {
                        rotation = Properties::Rotation::EIGHT;
                    } else if (prop.second == "9") {
                        rotation = Properties::Rotation::NINE;
                    } else if (prop.second == "10") {
                        rotation = Properties::Rotation::TEN;
                    } else if (prop.second == "11") {
                        rotation = Properties::Rotation::ELEVEN;
                    } else if (prop.second == "12") {
                        rotation = Properties::Rotation::TWELVE;
                    } else if (prop.second == "13") {
                        rotation = Properties::Rotation::THIRTEEN;
                    } else if (prop.second == "14") {
                        rotation = Properties::Rotation::FOURTEEN;
                    } else if (prop.second == "15") {
                        rotation = Properties::Rotation::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"rotation\" value");
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
            return toProtocol(rotation, waterlogged);
        }
    }

}
