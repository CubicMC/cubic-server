#include "Carrots.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Carrots {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 6923;
            case Properties::Age::ONE:
                return 6924;
            case Properties::Age::TWO:
                return 6925;
            case Properties::Age::THREE:
                return 6926;
            case Properties::Age::FOUR:
                return 6927;
            case Properties::Age::FIVE:
                return 6928;
            case Properties::Age::SIX:
                return 6929;
            case Properties::Age::SEVEN:
                return 6930;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Age age;
            for (auto prop : properties) {
                if (prop.first == "age") {
                    if (prop.second == "0") {
                        age = Properties::Age::ZERO;
                    } else if (prop.second == "1") {
                        age = Properties::Age::ONE;
                    } else if (prop.second == "2") {
                        age = Properties::Age::TWO;
                    } else if (prop.second == "3") {
                        age = Properties::Age::THREE;
                    } else if (prop.second == "4") {
                        age = Properties::Age::FOUR;
                    } else if (prop.second == "5") {
                        age = Properties::Age::FIVE;
                    } else if (prop.second == "6") {
                        age = Properties::Age::SIX;
                    } else if (prop.second == "7") {
                        age = Properties::Age::SEVEN;
                    } else {
                        throw std::runtime_error("Invalid property \"age\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(age);
        }
    }

}
