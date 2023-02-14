#include "MangroveLeaves.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MangroveLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 374;
                    case Properties::Waterlogged::FALSE:
                        return 375;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 376;
                    case Properties::Waterlogged::FALSE:
                        return 377;
                    }
                }
            case Properties::Distance::TWO:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 378;
                    case Properties::Waterlogged::FALSE:
                        return 379;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 380;
                    case Properties::Waterlogged::FALSE:
                        return 381;
                    }
                }
            case Properties::Distance::THREE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 382;
                    case Properties::Waterlogged::FALSE:
                        return 383;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 384;
                    case Properties::Waterlogged::FALSE:
                        return 385;
                    }
                }
            case Properties::Distance::FOUR:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 386;
                    case Properties::Waterlogged::FALSE:
                        return 387;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 388;
                    case Properties::Waterlogged::FALSE:
                        return 389;
                    }
                }
            case Properties::Distance::FIVE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 390;
                    case Properties::Waterlogged::FALSE:
                        return 391;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 392;
                    case Properties::Waterlogged::FALSE:
                        return 393;
                    }
                }
            case Properties::Distance::SIX:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 394;
                    case Properties::Waterlogged::FALSE:
                        return 395;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 396;
                    case Properties::Waterlogged::FALSE:
                        return 397;
                    }
                }
            case Properties::Distance::SEVEN:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 398;
                    case Properties::Waterlogged::FALSE:
                        return 399;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 400;
                    case Properties::Waterlogged::FALSE:
                        return 401;
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
