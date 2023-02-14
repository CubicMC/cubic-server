#include "SeaPickle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SeaPickle {
        BlockId toProtocol(Properties::Pickles pickles, Properties::Waterlogged waterlogged) {
            switch (pickles) {
            case Properties::Pickles::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10521;
                case Properties::Waterlogged::FALSE:
                    return 10522;
                }
            case Properties::Pickles::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10523;
                case Properties::Waterlogged::FALSE:
                    return 10524;
                }
            case Properties::Pickles::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10525;
                case Properties::Waterlogged::FALSE:
                    return 10526;
                }
            case Properties::Pickles::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10527;
                case Properties::Waterlogged::FALSE:
                    return 10528;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Pickles pickles;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "pickles") {
                    if (prop.second == "1") {
                        pickles = Properties::Pickles::ONE;
                    } else if (prop.second == "2") {
                        pickles = Properties::Pickles::TWO;
                    } else if (prop.second == "3") {
                        pickles = Properties::Pickles::THREE;
                    } else if (prop.second == "4") {
                        pickles = Properties::Pickles::FOUR;
                    } else {
                        throw std::runtime_error("Invalid property \"pickles\" value");
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
            return toProtocol(pickles, waterlogged);
        }
    }

}
