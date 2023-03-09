#include "SpruceFenceGate.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SpruceFenceGate {
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10827;
                        case Properties::Powered::FALSE:
                            return 10828;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10829;
                        case Properties::Powered::FALSE:
                            return 10830;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10831;
                        case Properties::Powered::FALSE:
                            return 10832;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10833;
                        case Properties::Powered::FALSE:
                            return 10834;
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
                            return 10835;
                        case Properties::Powered::FALSE:
                            return 10836;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10837;
                        case Properties::Powered::FALSE:
                            return 10838;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10839;
                        case Properties::Powered::FALSE:
                            return 10840;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10841;
                        case Properties::Powered::FALSE:
                            return 10842;
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
                            return 10843;
                        case Properties::Powered::FALSE:
                            return 10844;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10845;
                        case Properties::Powered::FALSE:
                            return 10846;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10847;
                        case Properties::Powered::FALSE:
                            return 10848;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10849;
                        case Properties::Powered::FALSE:
                            return 10850;
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
                            return 10851;
                        case Properties::Powered::FALSE:
                            return 10852;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10853;
                        case Properties::Powered::FALSE:
                            return 10854;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10855;
                        case Properties::Powered::FALSE:
                            return 10856;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10857;
                        case Properties::Powered::FALSE:
                            return 10858;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
