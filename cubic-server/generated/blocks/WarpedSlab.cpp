#include "WarpedSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WarpedSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16262;
                case Properties::Waterlogged::FALSE:
                    return 16263;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16264;
                case Properties::Waterlogged::FALSE:
                    return 16265;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16266;
                case Properties::Waterlogged::FALSE:
                    return 16267;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Type type;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "type") {
                    if (prop.second == "top") {
                        type = Properties::Type::TOP;
                    } else if (prop.second == "bottom") {
                        type = Properties::Type::BOTTOM;
                    } else if (prop.second == "double") {
                        type = Properties::Type::DOUBLE;
                    } else {
                        throw std::runtime_error("Invalid property \"type\" value");
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
            return toProtocol(type, waterlogged);
        }
    }

}