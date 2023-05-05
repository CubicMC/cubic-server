#include "MangrovePropagule.hpp"
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
                            return 36;
                        case Properties::Waterlogged::FALSE:
                            return 37;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 38;
                        case Properties::Waterlogged::FALSE:
                            return 39;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 40;
                        case Properties::Waterlogged::FALSE:
                            return 41;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 42;
                        case Properties::Waterlogged::FALSE:
                            return 43;
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
                            return 44;
                        case Properties::Waterlogged::FALSE:
                            return 45;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 46;
                        case Properties::Waterlogged::FALSE:
                            return 47;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 48;
                        case Properties::Waterlogged::FALSE:
                            return 49;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 50;
                        case Properties::Waterlogged::FALSE:
                            return 51;
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
                            return 52;
                        case Properties::Waterlogged::FALSE:
                            return 53;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 54;
                        case Properties::Waterlogged::FALSE:
                            return 55;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 56;
                        case Properties::Waterlogged::FALSE:
                            return 57;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 58;
                        case Properties::Waterlogged::FALSE:
                            return 59;
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
                            return 60;
                        case Properties::Waterlogged::FALSE:
                            return 61;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 62;
                        case Properties::Waterlogged::FALSE:
                            return 63;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 64;
                        case Properties::Waterlogged::FALSE:
                            return 65;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 66;
                        case Properties::Waterlogged::FALSE:
                            return 67;
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
                            return 68;
                        case Properties::Waterlogged::FALSE:
                            return 69;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 70;
                        case Properties::Waterlogged::FALSE:
                            return 71;
                        }
                    }
                case Properties::Hanging::FALSE:
                    switch (stage) {
                    case Properties::Stage::ZERO:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 72;
                        case Properties::Waterlogged::FALSE:
                            return 73;
                        }
                    case Properties::Stage::ONE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 74;
                        case Properties::Waterlogged::FALSE:
                            return 75;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
