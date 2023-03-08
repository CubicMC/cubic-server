#include "YellowCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace YellowCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18393;
                    case Properties::Waterlogged::FALSE:
                        return 18394;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18395;
                    case Properties::Waterlogged::FALSE:
                        return 18396;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18397;
                    case Properties::Waterlogged::FALSE:
                        return 18398;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18399;
                    case Properties::Waterlogged::FALSE:
                        return 18400;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18401;
                    case Properties::Waterlogged::FALSE:
                        return 18402;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18403;
                    case Properties::Waterlogged::FALSE:
                        return 18404;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18405;
                    case Properties::Waterlogged::FALSE:
                        return 18406;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18407;
                    case Properties::Waterlogged::FALSE:
                        return 18408;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Candles candles;
            Properties::Lit lit;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "candles") {
                    if (prop.second == "1") {
                        candles = Properties::Candles::ONE;
                    } else if (prop.second == "2") {
                        candles = Properties::Candles::TWO;
                    } else if (prop.second == "3") {
                        candles = Properties::Candles::THREE;
                    } else if (prop.second == "4") {
                        candles = Properties::Candles::FOUR;
                    } else {
                        throw std::runtime_error("Invalid property \"candles\" value");
                    }
                } else if (prop.first == "lit") {
                    if (prop.second == "true") {
                        lit = Properties::Lit::TRUE;
                    } else if (prop.second == "false") {
                        lit = Properties::Lit::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"lit\" value");
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
            return toProtocol(candles, lit, waterlogged);
        }
    }

}