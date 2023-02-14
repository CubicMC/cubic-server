#include "Jukebox.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Jukebox {
        BlockId toProtocol(Properties::Has_record has_record) {
            switch (has_record) {
            case Properties::Has_record::TRUE:
                return 4273;
            case Properties::Has_record::FALSE:
                return 4274;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Has_record has_record;
            for (auto prop : properties) {
                if (prop.first == "has_record") {
                    if (prop.second == "true") {
                        has_record = Properties::Has_record::TRUE;
                    } else if (prop.second == "false") {
                        has_record = Properties::Has_record::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"has_record\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(has_record);
        }
    }

}
