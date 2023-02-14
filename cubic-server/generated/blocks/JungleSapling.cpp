#include "JungleSapling.hpp"
#include <stdexcept>

namespace Blocks {
    namespace JungleSapling {
        BlockId toProtocol(Properties::Stage stage) {
            switch (stage) {
            case Properties::Stage::ZERO:
                return 28;
            case Properties::Stage::ONE:
                return 29;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Stage stage;
            for (auto prop : properties) {
                if (prop.first == "stage") {
                    if (prop.second == "0") {
                        stage = Properties::Stage::ZERO;
                    } else if (prop.second == "1") {
                        stage = Properties::Stage::ONE;
                    } else {
                        throw std::runtime_error("Invalid property \"stage\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(stage);
        }
    }

}
