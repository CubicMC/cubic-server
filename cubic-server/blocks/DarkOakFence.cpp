#include "DarkOakFence.hpp"
#include <stdexcept>

namespace Blocks {
namespace DarkOakFence {
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
                        return 11179;
                    case Properties::West::FALSE:
                        return 11180;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11181;
                    case Properties::West::FALSE:
                        return 11182;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11183;
                    case Properties::West::FALSE:
                        return 11184;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11185;
                    case Properties::West::FALSE:
                        return 11186;
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
                        return 11187;
                    case Properties::West::FALSE:
                        return 11188;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11189;
                    case Properties::West::FALSE:
                        return 11190;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11191;
                    case Properties::West::FALSE:
                        return 11192;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11193;
                    case Properties::West::FALSE:
                        return 11194;
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
                        return 11195;
                    case Properties::West::FALSE:
                        return 11196;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11197;
                    case Properties::West::FALSE:
                        return 11198;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11199;
                    case Properties::West::FALSE:
                        return 11200;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11201;
                    case Properties::West::FALSE:
                        return 11202;
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
                        return 11203;
                    case Properties::West::FALSE:
                        return 11204;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11205;
                    case Properties::West::FALSE:
                        return 11206;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11207;
                    case Properties::West::FALSE:
                        return 11208;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11209;
                    case Properties::West::FALSE:
                        return 11210;
                    }
                }
            }
        }
    }
    return 0;
}
}

}
