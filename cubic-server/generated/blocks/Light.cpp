#include "Light.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Light {
        BlockId toProtocol(Properties::Level level, Properties::Waterlogged waterlogged) {
            switch (level) {
            case Properties::Level::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8246;
                case Properties::Waterlogged::FALSE:
                    return 8247;
                }
            case Properties::Level::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8248;
                case Properties::Waterlogged::FALSE:
                    return 8249;
                }
            case Properties::Level::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8250;
                case Properties::Waterlogged::FALSE:
                    return 8251;
                }
            case Properties::Level::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8252;
                case Properties::Waterlogged::FALSE:
                    return 8253;
                }
            case Properties::Level::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8254;
                case Properties::Waterlogged::FALSE:
                    return 8255;
                }
            case Properties::Level::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8256;
                case Properties::Waterlogged::FALSE:
                    return 8257;
                }
            case Properties::Level::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8258;
                case Properties::Waterlogged::FALSE:
                    return 8259;
                }
            case Properties::Level::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8260;
                case Properties::Waterlogged::FALSE:
                    return 8261;
                }
            case Properties::Level::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8262;
                case Properties::Waterlogged::FALSE:
                    return 8263;
                }
            case Properties::Level::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8264;
                case Properties::Waterlogged::FALSE:
                    return 8265;
                }
            case Properties::Level::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8266;
                case Properties::Waterlogged::FALSE:
                    return 8267;
                }
            case Properties::Level::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8268;
                case Properties::Waterlogged::FALSE:
                    return 8269;
                }
            case Properties::Level::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8270;
                case Properties::Waterlogged::FALSE:
                    return 8271;
                }
            case Properties::Level::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8272;
                case Properties::Waterlogged::FALSE:
                    return 8273;
                }
            case Properties::Level::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8274;
                case Properties::Waterlogged::FALSE:
                    return 8275;
                }
            case Properties::Level::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8276;
                case Properties::Waterlogged::FALSE:
                    return 8277;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Level level;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "level") {
                    if (prop.second == "0") {
                        level = Properties::Level::ZERO;
                    } else if (prop.second == "1") {
                        level = Properties::Level::ONE;
                    } else if (prop.second == "2") {
                        level = Properties::Level::TWO;
                    } else if (prop.second == "3") {
                        level = Properties::Level::THREE;
                    } else if (prop.second == "4") {
                        level = Properties::Level::FOUR;
                    } else if (prop.second == "5") {
                        level = Properties::Level::FIVE;
                    } else if (prop.second == "6") {
                        level = Properties::Level::SIX;
                    } else if (prop.second == "7") {
                        level = Properties::Level::SEVEN;
                    } else if (prop.second == "8") {
                        level = Properties::Level::EIGHT;
                    } else if (prop.second == "9") {
                        level = Properties::Level::NINE;
                    } else if (prop.second == "10") {
                        level = Properties::Level::TEN;
                    } else if (prop.second == "11") {
                        level = Properties::Level::ELEVEN;
                    } else if (prop.second == "12") {
                        level = Properties::Level::TWELVE;
                    } else if (prop.second == "13") {
                        level = Properties::Level::THIRTEEN;
                    } else if (prop.second == "14") {
                        level = Properties::Level::FOURTEEN;
                    } else if (prop.second == "15") {
                        level = Properties::Level::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"level\" value");
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
            return toProtocol(level, waterlogged);
        }
    }

}
