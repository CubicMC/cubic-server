#include "BubbleColumn.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BubbleColumn {
        BlockId toProtocol(Properties::Drag drag) {
            switch (drag) {
            case Properties::Drag::TRUE:
                return 10548;
            case Properties::Drag::FALSE:
                return 10549;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Drag drag;
            for (auto prop : properties) {
                if (prop.first == "drag") {
                    if (prop.second == "true") {
                        drag = Properties::Drag::TRUE;
                    } else if (prop.second == "false") {
                        drag = Properties::Drag::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"drag\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(drag);
        }
    }

}
