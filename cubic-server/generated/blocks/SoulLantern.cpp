#include "SoulLantern.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SoulLantern {
        BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged) {
            switch (hanging) {
            case Properties::Hanging::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16095;
                case Properties::Waterlogged::FALSE:
                    return 16096;
                }
            case Properties::Hanging::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 16097;
                case Properties::Waterlogged::FALSE:
                    return 16098;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Hanging hanging;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "hanging") {
                    if (prop.second == "true") {
                        hanging = Properties::Hanging::TRUE;
                    } else if (prop.second == "false") {
                        hanging = Properties::Hanging::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"hanging\" value");
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
            return toProtocol(hanging, waterlogged);
        }
    }

}
