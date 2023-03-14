#include "GlassPane.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GlassPane {
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
            switch (east) {
            case Properties::East::TRUE:
                switch (north) {
                case Properties::North::TRUE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6550;
                            case Properties::West::FALSE:
                                return 6551;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6552;
                            case Properties::West::FALSE:
                                return 6553;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6554;
                            case Properties::West::FALSE:
                                return 6555;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6556;
                            case Properties::West::FALSE:
                                return 6557;
                            }
                        }
                    }
                case Properties::North::FALSE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6558;
                            case Properties::West::FALSE:
                                return 6559;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6560;
                            case Properties::West::FALSE:
                                return 6561;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6562;
                            case Properties::West::FALSE:
                                return 6563;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6564;
                            case Properties::West::FALSE:
                                return 6565;
                            }
                        }
                    }
                }
            case Properties::East::FALSE:
                switch (north) {
                case Properties::North::TRUE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6566;
                            case Properties::West::FALSE:
                                return 6567;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6568;
                            case Properties::West::FALSE:
                                return 6569;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6570;
                            case Properties::West::FALSE:
                                return 6571;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6572;
                            case Properties::West::FALSE:
                                return 6573;
                            }
                        }
                    }
                case Properties::North::FALSE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6574;
                            case Properties::West::FALSE:
                                return 6575;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6576;
                            case Properties::West::FALSE:
                                return 6577;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6578;
                            case Properties::West::FALSE:
                                return 6579;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6580;
                            case Properties::West::FALSE:
                                return 6581;
                            }
                        }
                    }
                }
            }
            return 0;
        }
    }

}
