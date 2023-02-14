#include "PurpleCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PurpleCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18489;
                    case Properties::Waterlogged::FALSE:
                        return 18490;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18491;
                    case Properties::Waterlogged::FALSE:
                        return 18492;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18493;
                    case Properties::Waterlogged::FALSE:
                        return 18494;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18495;
                    case Properties::Waterlogged::FALSE:
                        return 18496;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18497;
                    case Properties::Waterlogged::FALSE:
                        return 18498;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18499;
                    case Properties::Waterlogged::FALSE:
                        return 18500;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18501;
                    case Properties::Waterlogged::FALSE:
                        return 18502;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18503;
                    case Properties::Waterlogged::FALSE:
                        return 18504;
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
