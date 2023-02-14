#include "FloweringAzaleaLeaves.hpp"
#include <stdexcept>

namespace Blocks {
    namespace FloweringAzaleaLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 430;
                    case Properties::Waterlogged::FALSE:
                        return 431;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 432;
                    case Properties::Waterlogged::FALSE:
                        return 433;
                    }
                }
            case Properties::Distance::TWO:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 434;
                    case Properties::Waterlogged::FALSE:
                        return 435;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 436;
                    case Properties::Waterlogged::FALSE:
                        return 437;
                    }
                }
            case Properties::Distance::THREE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 438;
                    case Properties::Waterlogged::FALSE:
                        return 439;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 440;
                    case Properties::Waterlogged::FALSE:
                        return 441;
                    }
                }
            case Properties::Distance::FOUR:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 442;
                    case Properties::Waterlogged::FALSE:
                        return 443;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 444;
                    case Properties::Waterlogged::FALSE:
                        return 445;
                    }
                }
            case Properties::Distance::FIVE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 446;
                    case Properties::Waterlogged::FALSE:
                        return 447;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 448;
                    case Properties::Waterlogged::FALSE:
                        return 449;
                    }
                }
            case Properties::Distance::SIX:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 450;
                    case Properties::Waterlogged::FALSE:
                        return 451;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 452;
                    case Properties::Waterlogged::FALSE:
                        return 453;
                    }
                }
            case Properties::Distance::SEVEN:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 454;
                    case Properties::Waterlogged::FALSE:
                        return 455;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 456;
                    case Properties::Waterlogged::FALSE:
                        return 457;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Distance distance;
            Properties::Persistent persistent;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "distance") {
                    if (prop.second == "1") {
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
                } else if (prop.first == "persistent") {
                    if (prop.second == "true") {
                        persistent = Properties::Persistent::TRUE;
                    } else if (prop.second == "false") {
                        persistent = Properties::Persistent::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"persistent\" value");
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
            return toProtocol(distance, persistent, waterlogged);
        }
    }

}
