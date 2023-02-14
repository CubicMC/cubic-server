#include "StrippedCrimsonHyphae.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StrippedCrimsonHyphae {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 16193;
            case Properties::Axis::Y:
                return 16194;
            case Properties::Axis::Z:
                return 16195;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Axis axis;
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
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(axis);
        }
    }

}
