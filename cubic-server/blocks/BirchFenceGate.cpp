#include "BirchFenceGate.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BirchFenceGate {
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10859;
                        case Properties::Powered::FALSE:
                            return 10860;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10861;
                        case Properties::Powered::FALSE:
                            return 10862;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10863;
                        case Properties::Powered::FALSE:
                            return 10864;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10865;
                        case Properties::Powered::FALSE:
                            return 10866;
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10867;
                        case Properties::Powered::FALSE:
                            return 10868;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10869;
                        case Properties::Powered::FALSE:
                            return 10870;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10871;
                        case Properties::Powered::FALSE:
                            return 10872;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10873;
                        case Properties::Powered::FALSE:
                            return 10874;
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10875;
                        case Properties::Powered::FALSE:
                            return 10876;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10877;
                        case Properties::Powered::FALSE:
                            return 10878;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10879;
                        case Properties::Powered::FALSE:
                            return 10880;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10881;
                        case Properties::Powered::FALSE:
                            return 10882;
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10883;
                        case Properties::Powered::FALSE:
                            return 10884;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10885;
                        case Properties::Powered::FALSE:
                            return 10886;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10887;
                        case Properties::Powered::FALSE:
                            return 10888;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10889;
                        case Properties::Powered::FALSE:
                            return 10890;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
