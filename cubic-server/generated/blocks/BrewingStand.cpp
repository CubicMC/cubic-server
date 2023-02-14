#include "BrewingStand.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BrewingStand {
        BlockId toProtocol(Properties::Has_bottle_0 has_bottle_0, Properties::Has_bottle_1 has_bottle_1, Properties::Has_bottle_2 has_bottle_2) {
            switch (has_bottle_0) {
            case Properties::Has_bottle_0::TRUE:
                switch (has_bottle_1) {
                case Properties::Has_bottle_1::TRUE:
                    switch (has_bottle_2) {
                    case Properties::Has_bottle_2::TRUE:
                        return 5720;
                    case Properties::Has_bottle_2::FALSE:
                        return 5721;
                    }
                case Properties::Has_bottle_1::FALSE:
                    switch (has_bottle_2) {
                    case Properties::Has_bottle_2::TRUE:
                        return 5722;
                    case Properties::Has_bottle_2::FALSE:
                        return 5723;
                    }
                }
            case Properties::Has_bottle_0::FALSE:
                switch (has_bottle_1) {
                case Properties::Has_bottle_1::TRUE:
                    switch (has_bottle_2) {
                    case Properties::Has_bottle_2::TRUE:
                        return 5724;
                    case Properties::Has_bottle_2::FALSE:
                        return 5725;
                    }
                case Properties::Has_bottle_1::FALSE:
                    switch (has_bottle_2) {
                    case Properties::Has_bottle_2::TRUE:
                        return 5726;
                    case Properties::Has_bottle_2::FALSE:
                        return 5727;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Has_bottle_0 has_bottle_0;
            Properties::Has_bottle_1 has_bottle_1;
            Properties::Has_bottle_2 has_bottle_2;
            for (auto prop : properties) {
                if (prop.first == "has_bottle_0") {
                    if (prop.second == "true") {
                        has_bottle_0 = Properties::Has_bottle_0::TRUE;
                    } else if (prop.second == "false") {
                        has_bottle_0 = Properties::Has_bottle_0::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"has_bottle_0\" value");
                    }
                } else if (prop.first == "has_bottle_1") {
                    if (prop.second == "true") {
                        has_bottle_1 = Properties::Has_bottle_1::TRUE;
                    } else if (prop.second == "false") {
                        has_bottle_1 = Properties::Has_bottle_1::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"has_bottle_1\" value");
                    }
                } else if (prop.first == "has_bottle_2") {
                    if (prop.second == "true") {
                        has_bottle_2 = Properties::Has_bottle_2::TRUE;
                    } else if (prop.second == "false") {
                        has_bottle_2 = Properties::Has_bottle_2::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"has_bottle_2\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(has_bottle_0, has_bottle_1, has_bottle_2);
        }
    }

}
