#include "Bamboo.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Bamboo {
        BlockId toProtocol(Properties::Age age, Properties::Leaves leaves, Properties::Stage stage) {
            switch (age) {
            case Properties::Age::ZERO:
                switch (leaves) {
                case Properties::Leaves::NONE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        return 10533;
                    case Properties::Stage::ONE:
                        return 10534;
                    }
                case Properties::Leaves::SMALL:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        return 10535;
                    case Properties::Stage::ONE:
                        return 10536;
                    }
                case Properties::Leaves::LARGE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        return 10537;
                    case Properties::Stage::ONE:
                        return 10538;
                    }
                }
            case Properties::Age::ONE:
                switch (leaves) {
                case Properties::Leaves::NONE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        return 10539;
                    case Properties::Stage::ONE:
                        return 10540;
                    }
                case Properties::Leaves::SMALL:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        return 10541;
                    case Properties::Stage::ONE:
                        return 10542;
                    }
                case Properties::Leaves::LARGE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        return 10543;
                    case Properties::Stage::ONE:
                        return 10544;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Age age;
            Properties::Leaves leaves;
            Properties::Stage stage;
            for (auto prop : properties) {
                if (prop.first == "age") {
                    if (prop.second == "0") {
                        age = Properties::Age::ZERO;
                    } else if (prop.second == "1") {
                        age = Properties::Age::ONE;
                    } else {
                        throw std::runtime_error("Invalid property \"age\" value");
                    }
                } else if (prop.first == "leaves") {
                    if (prop.second == "none") {
                        leaves = Properties::Leaves::NONE;
                    } else if (prop.second == "small") {
                        leaves = Properties::Leaves::SMALL;
                    } else if (prop.second == "large") {
                        leaves = Properties::Leaves::LARGE;
                    } else {
                        throw std::runtime_error("Invalid property \"leaves\" value");
                    }
                } else if (prop.first == "stage") {
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
            return toProtocol(age, leaves, stage);
        }
    }

}
