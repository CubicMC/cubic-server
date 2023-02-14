#include "BirchLeaves.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BirchLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 262;
                    case Properties::Waterlogged::FALSE:
                        return 263;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 264;
                    case Properties::Waterlogged::FALSE:
                        return 265;
                    }
                }
            case Properties::Distance::TWO:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 266;
                    case Properties::Waterlogged::FALSE:
                        return 267;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 268;
                    case Properties::Waterlogged::FALSE:
                        return 269;
                    }
                }
            case Properties::Distance::THREE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 270;
                    case Properties::Waterlogged::FALSE:
                        return 271;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 272;
                    case Properties::Waterlogged::FALSE:
                        return 273;
                    }
                }
            case Properties::Distance::FOUR:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 274;
                    case Properties::Waterlogged::FALSE:
                        return 275;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 276;
                    case Properties::Waterlogged::FALSE:
                        return 277;
                    }
                }
            case Properties::Distance::FIVE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 278;
                    case Properties::Waterlogged::FALSE:
                        return 279;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 280;
                    case Properties::Waterlogged::FALSE:
                        return 281;
                    }
                }
            case Properties::Distance::SIX:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 282;
                    case Properties::Waterlogged::FALSE:
                        return 283;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 284;
                    case Properties::Waterlogged::FALSE:
                        return 285;
                    }
                }
            case Properties::Distance::SEVEN:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 286;
                    case Properties::Waterlogged::FALSE:
                        return 287;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 288;
                    case Properties::Waterlogged::FALSE:
                        return 289;
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
