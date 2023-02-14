#include "RedCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RedCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18553;
                    case Properties::Waterlogged::FALSE:
                        return 18554;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18555;
                    case Properties::Waterlogged::FALSE:
                        return 18556;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18557;
                    case Properties::Waterlogged::FALSE:
                        return 18558;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18559;
                    case Properties::Waterlogged::FALSE:
                        return 18560;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18561;
                    case Properties::Waterlogged::FALSE:
                        return 18562;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18563;
                    case Properties::Waterlogged::FALSE:
                        return 18564;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18565;
                    case Properties::Waterlogged::FALSE:
                        return 18566;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18567;
                    case Properties::Waterlogged::FALSE:
                        return 18568;
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
