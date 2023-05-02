#include "LimeStainedGlassPane.hpp"
#include <stdexcept>

namespace Blocks {
namespace LimeStainedGlassPane {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west)
{
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
                        return 9136;
                    case Properties::West::FALSE:
                        return 9137;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9138;
                    case Properties::West::FALSE:
                        return 9139;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9140;
                    case Properties::West::FALSE:
                        return 9141;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9142;
                    case Properties::West::FALSE:
                        return 9143;
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
                        return 9144;
                    case Properties::West::FALSE:
                        return 9145;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9146;
                    case Properties::West::FALSE:
                        return 9147;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9148;
                    case Properties::West::FALSE:
                        return 9149;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9150;
                    case Properties::West::FALSE:
                        return 9151;
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
                        return 9152;
                    case Properties::West::FALSE:
                        return 9153;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9154;
                    case Properties::West::FALSE:
                        return 9155;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9156;
                    case Properties::West::FALSE:
                        return 9157;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9158;
                    case Properties::West::FALSE:
                        return 9159;
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
                        return 9160;
                    case Properties::West::FALSE:
                        return 9161;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9162;
                    case Properties::West::FALSE:
                        return 9163;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9164;
                    case Properties::West::FALSE:
                        return 9165;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9166;
                    case Properties::West::FALSE:
                        return 9167;
                    }
                }
            }
        }
    }
    return 0;
}
}

}
