#include "Snow.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Snow {
        BlockId toProtocol(Properties::Layers layers) {
            switch (layers) {
            case Properties::Layers::ONE:
                return 4230;
            case Properties::Layers::TWO:
                return 4231;
            case Properties::Layers::THREE:
                return 4232;
            case Properties::Layers::FOUR:
                return 4233;
            case Properties::Layers::FIVE:
                return 4234;
            case Properties::Layers::SIX:
                return 4235;
            case Properties::Layers::SEVEN:
                return 4236;
            case Properties::Layers::EIGHT:
                return 4237;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Layers layers;
            for (auto prop : properties) {
                if (prop.first == "layers") {
                    if (prop.second == "1") {
                        layers = Properties::Layers::ONE;
                    } else if (prop.second == "2") {
                        layers = Properties::Layers::TWO;
                    } else if (prop.second == "3") {
                        layers = Properties::Layers::THREE;
                    } else if (prop.second == "4") {
                        layers = Properties::Layers::FOUR;
                    } else if (prop.second == "5") {
                        layers = Properties::Layers::FIVE;
                    } else if (prop.second == "6") {
                        layers = Properties::Layers::SIX;
                    } else if (prop.second == "7") {
                        layers = Properties::Layers::SEVEN;
                    } else if (prop.second == "8") {
                        layers = Properties::Layers::EIGHT;
                    } else {
                        throw std::runtime_error("Invalid property \"layers\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(layers);
        }
    }

}
