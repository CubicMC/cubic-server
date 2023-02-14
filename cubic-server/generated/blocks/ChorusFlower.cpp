#include "ChorusFlower.hpp"
#include <stdexcept>

namespace Blocks {
    namespace ChorusFlower {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 10009;
            case Properties::Age::ONE:
                return 10010;
            case Properties::Age::TWO:
                return 10011;
            case Properties::Age::THREE:
                return 10012;
            case Properties::Age::FOUR:
                return 10013;
            case Properties::Age::FIVE:
                return 10014;
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
