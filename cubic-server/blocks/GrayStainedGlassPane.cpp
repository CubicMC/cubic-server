#include "GrayStainedGlassPane.hpp"
#include <stdexcept>

namespace Blocks {
namespace GrayStainedGlassPane {
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
                        return 9200;
                    case Properties::West::FALSE:
                        return 9201;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9202;
                    case Properties::West::FALSE:
                        return 9203;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9204;
                    case Properties::West::FALSE:
                        return 9205;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9206;
                    case Properties::West::FALSE:
                        return 9207;
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
                        return 9208;
                    case Properties::West::FALSE:
                        return 9209;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9210;
                    case Properties::West::FALSE:
                        return 9211;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9212;
                    case Properties::West::FALSE:
                        return 9213;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9214;
                    case Properties::West::FALSE:
                        return 9215;
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
                        return 9216;
                    case Properties::West::FALSE:
                        return 9217;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9218;
                    case Properties::West::FALSE:
                        return 9219;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9220;
                    case Properties::West::FALSE:
                        return 9221;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9222;
                    case Properties::West::FALSE:
                        return 9223;
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
                        return 9224;
                    case Properties::West::FALSE:
                        return 9225;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9226;
                    case Properties::West::FALSE:
                        return 9227;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9228;
                    case Properties::West::FALSE:
                        return 9229;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9230;
                    case Properties::West::FALSE:
                        return 9231;
                    }
                }
            }
        }
    }
    return 0;
}
}

}
