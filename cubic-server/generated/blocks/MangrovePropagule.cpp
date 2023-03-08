#include "MangrovePropagule.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MangrovePropagule {
        BlockId toProtocol(Properties::Age age, Properties::Hanging hanging, Properties::Stage stage, Properties::Waterlogged waterlogged) {
            switch (age) {
            case Properties::Age::ZERO:
                switch (hanging) {
                case Properties::Hanging::TRUE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 34;
                        case Properties::Waterlogged::FALSE:
                            return 35;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 36;
                        case Properties::Waterlogged::FALSE:
                            return 37;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 38;
                        case Properties::Waterlogged::FALSE:
                            return 39;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 40;
                        case Properties::Waterlogged::FALSE:
                            return 41;
                        }
                    }
                }
            case Properties::Age::ONE:
                switch (hanging) {
                case Properties::Hanging::TRUE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 42;
                        case Properties::Waterlogged::FALSE:
                            return 43;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 44;
                        case Properties::Waterlogged::FALSE:
                            return 45;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 46;
                        case Properties::Waterlogged::FALSE:
                            return 47;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 48;
                        case Properties::Waterlogged::FALSE:
                            return 49;
                        }
                    }
                }
            case Properties::Age::TWO:
                switch (hanging) {
                case Properties::Hanging::TRUE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 50;
                        case Properties::Waterlogged::FALSE:
                            return 51;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 52;
                        case Properties::Waterlogged::FALSE:
                            return 53;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 54;
                        case Properties::Waterlogged::FALSE:
                            return 55;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 56;
                        case Properties::Waterlogged::FALSE:
                            return 57;
                        }
                    }
                }
            case Properties::Age::THREE:
                switch (hanging) {
                case Properties::Hanging::TRUE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 58;
                        case Properties::Waterlogged::FALSE:
                            return 59;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 60;
                        case Properties::Waterlogged::FALSE:
                            return 61;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 62;
                        case Properties::Waterlogged::FALSE:
                            return 63;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 64;
                        case Properties::Waterlogged::FALSE:
                            return 65;
                        }
                    }
                }
            case Properties::Age::FOUR:
                switch (hanging) {
                case Properties::Hanging::TRUE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 66;
                        case Properties::Waterlogged::FALSE:
                            return 67;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 68;
                        case Properties::Waterlogged::FALSE:
                            return 69;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 70;
                        case Properties::Waterlogged::FALSE:
                            return 71;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 72;
                        case Properties::Waterlogged::FALSE:
                            return 73;
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 4)
            throw std::runtime_error("Invalid number of properties");
            Properties::Age age;
            Properties::Hanging hanging;
            Properties::Stage stage;
            Properties::Waterlogged waterlogged;
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
                    } else {
                        throw std::runtime_error("Invalid property \"age\" value");
                    }
                } else if (prop.first == "hanging") {
                    if (prop.second == "true") {
                        hanging = Properties::Hanging::TRUE;
                    } else if (prop.second == "false") {
                        hanging = Properties::Hanging::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"hanging\" value");
                    }
                } else if (prop.first == "stage") {
                    if (prop.second == "0") {
                        stage = Properties::Stage::ZERO;
                    } else if (prop.second == "1") {
                        stage = Properties::Stage::ONE;
                    } else {
                        throw std::runtime_error("Invalid property \"stage\" value");
                    }
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(age, hanging, stage, waterlogged);
        }
    }

}