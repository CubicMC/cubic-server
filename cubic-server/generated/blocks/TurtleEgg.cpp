#include "TurtleEgg.hpp"
#include <stdexcept>

namespace Blocks {
    namespace TurtleEgg {
        BlockId toProtocol(Properties::Eggs eggs, Properties::Hatch hatch) {
            switch (eggs) {
            case Properties::Eggs::ONE:
                switch (hatch) {
                case Properties::Hatch::ZERO:
                    return 10379;
                case Properties::Hatch::ONE:
                    return 10380;
                case Properties::Hatch::TWO:
                    return 10381;
                }
            case Properties::Eggs::TWO:
                switch (hatch) {
                case Properties::Hatch::ZERO:
                    return 10382;
                case Properties::Hatch::ONE:
                    return 10383;
                case Properties::Hatch::TWO:
                    return 10384;
                }
            case Properties::Eggs::THREE:
                switch (hatch) {
                case Properties::Hatch::ZERO:
                    return 10385;
                case Properties::Hatch::ONE:
                    return 10386;
                case Properties::Hatch::TWO:
                    return 10387;
                }
            case Properties::Eggs::FOUR:
                switch (hatch) {
                case Properties::Hatch::ZERO:
                    return 10388;
                case Properties::Hatch::ONE:
                    return 10389;
                case Properties::Hatch::TWO:
                    return 10390;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Eggs eggs;
            Properties::Hatch hatch;
            for (auto prop : properties) {
                if (prop.first == "eggs") {
                    if (prop.second == "1") {
                        eggs = Properties::Eggs::ONE;
                    } else if (prop.second == "2") {
                        eggs = Properties::Eggs::TWO;
                    } else if (prop.second == "3") {
                        eggs = Properties::Eggs::THREE;
                    } else if (prop.second == "4") {
                        eggs = Properties::Eggs::FOUR;
                    } else {
                        throw std::runtime_error("Invalid property \"eggs\" value");
                    }
                } else if (prop.first == "hatch") {
                    if (prop.second == "0") {
                        hatch = Properties::Hatch::ZERO;
                    } else if (prop.second == "1") {
                        hatch = Properties::Hatch::ONE;
                    } else if (prop.second == "2") {
                        hatch = Properties::Hatch::TWO;
                    } else {
                        throw std::runtime_error("Invalid property \"hatch\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(eggs, hatch);
        }
    }

}
