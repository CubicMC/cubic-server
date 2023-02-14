#include "Chain.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Chain {
        BlockId toProtocol(Properties::Axis axis, Properties::Waterlogged waterlogged) {
            switch (axis) {
            case Properties::Axis::X:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5104;
                case Properties::Waterlogged::FALSE:
                    return 5105;
                }
            case Properties::Axis::Y:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5106;
                case Properties::Waterlogged::FALSE:
                    return 5107;
                }
            case Properties::Axis::Z:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5108;
                case Properties::Waterlogged::FALSE:
                    return 5109;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Axis axis;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "axis") {
                    if (prop.second == "x") {
                        axis = Properties::Axis::X;
                    } else if (prop.second == "y") {
                        axis = Properties::Axis::Y;
                    } else if (prop.second == "z") {
                        axis = Properties::Axis::Z;
                    } else {
                        throw std::runtime_error("Invalid property \"axis\" value");
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
            return toProtocol(axis, waterlogged);
        }
    }

}
