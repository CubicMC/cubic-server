#include "Scaffolding.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Scaffolding {
        BlockId toProtocol(Properties::Bottom bottom, Properties::Distance distance, Properties::Waterlogged waterlogged) {
            switch (bottom) {
            case Properties::Bottom::TRUE:
                switch (distance) {
                case Properties::Distance::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15960;
                    case Properties::Waterlogged::FALSE:
                        return 15961;
                    }
                case Properties::Distance::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15962;
                    case Properties::Waterlogged::FALSE:
                        return 15963;
                    }
                case Properties::Distance::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15964;
                    case Properties::Waterlogged::FALSE:
                        return 15965;
                    }
                case Properties::Distance::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15966;
                    case Properties::Waterlogged::FALSE:
                        return 15967;
                    }
                case Properties::Distance::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15968;
                    case Properties::Waterlogged::FALSE:
                        return 15969;
                    }
                case Properties::Distance::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15970;
                    case Properties::Waterlogged::FALSE:
                        return 15971;
                    }
                case Properties::Distance::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15972;
                    case Properties::Waterlogged::FALSE:
                        return 15973;
                    }
                case Properties::Distance::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15974;
                    case Properties::Waterlogged::FALSE:
                        return 15975;
                    }
                }
            case Properties::Bottom::FALSE:
                switch (distance) {
                case Properties::Distance::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15976;
                    case Properties::Waterlogged::FALSE:
                        return 15977;
                    }
                case Properties::Distance::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15978;
                    case Properties::Waterlogged::FALSE:
                        return 15979;
                    }
                case Properties::Distance::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15980;
                    case Properties::Waterlogged::FALSE:
                        return 15981;
                    }
                case Properties::Distance::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15982;
                    case Properties::Waterlogged::FALSE:
                        return 15983;
                    }
                case Properties::Distance::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15984;
                    case Properties::Waterlogged::FALSE:
                        return 15985;
                    }
                case Properties::Distance::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15986;
                    case Properties::Waterlogged::FALSE:
                        return 15987;
                    }
                case Properties::Distance::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15988;
                    case Properties::Waterlogged::FALSE:
                        return 15989;
                    }
                case Properties::Distance::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 15990;
                    case Properties::Waterlogged::FALSE:
                        return 15991;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Bottom bottom;
            Properties::Distance distance;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "bottom") {
                    if (prop.second == "true") {
                        bottom = Properties::Bottom::TRUE;
                    } else if (prop.second == "false") {
                        bottom = Properties::Bottom::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"bottom\" value");
                    }
                } else if (prop.first == "distance") {
                    if (prop.second == "0") {
                        distance = Properties::Distance::ZERO;
                    } else if (prop.second == "1") {
                        distance = Properties::Distance::ONE;
                    } else if (prop.second == "2") {
                        distance = Properties::Distance::TWO;
                    } else if (prop.second == "3") {
                        distance = Properties::Distance::THREE;
                    } else if (prop.second == "4") {
                        distance = Properties::Distance::FOUR;
                    } else if (prop.second == "5") {
                        distance = Properties::Distance::FIVE;
                    } else if (prop.second == "6") {
                        distance = Properties::Distance::SIX;
                    } else if (prop.second == "7") {
                        distance = Properties::Distance::SEVEN;
                    } else {
                        throw std::runtime_error("Invalid property \"distance\" value");
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
            return toProtocol(bottom, distance, waterlogged);
        }
    }

}
