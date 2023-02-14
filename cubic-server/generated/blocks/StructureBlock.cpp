#include "StructureBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StructureBlock {
        BlockId toProtocol(Properties::Mode mode) {
            switch (mode) {
            case Properties::Mode::SAVE:
                return 16944;
            case Properties::Mode::LOAD:
                return 16945;
            case Properties::Mode::CORNER:
                return 16946;
            case Properties::Mode::DATA:
                return 16947;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Mode mode;
            for (auto prop : properties) {
                if (prop.first == "mode") {
                    if (prop.second == "save") {
                        mode = Properties::Mode::SAVE;
                    } else if (prop.second == "load") {
                        mode = Properties::Mode::LOAD;
                    } else if (prop.second == "corner") {
                        mode = Properties::Mode::CORNER;
                    } else if (prop.second == "data") {
                        mode = Properties::Mode::DATA;
                    } else {
                        throw std::runtime_error("Invalid property \"mode\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(mode);
        }
    }

}
