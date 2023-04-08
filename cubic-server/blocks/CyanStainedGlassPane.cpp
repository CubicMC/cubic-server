#include "CyanStainedGlassPane.hpp"
#include <stdexcept>

namespace Blocks {
namespace CyanStainedGlassPane {
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
                        return 9264;
                    case Properties::West::FALSE:
                        return 9265;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9266;
                    case Properties::West::FALSE:
                        return 9267;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9268;
                    case Properties::West::FALSE:
                        return 9269;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9270;
                    case Properties::West::FALSE:
                        return 9271;
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
                        return 9272;
                    case Properties::West::FALSE:
                        return 9273;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9274;
                    case Properties::West::FALSE:
                        return 9275;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9276;
                    case Properties::West::FALSE:
                        return 9277;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9278;
                    case Properties::West::FALSE:
                        return 9279;
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
                        return 9280;
                    case Properties::West::FALSE:
                        return 9281;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9282;
                    case Properties::West::FALSE:
                        return 9283;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9284;
                    case Properties::West::FALSE:
                        return 9285;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9286;
                    case Properties::West::FALSE:
                        return 9287;
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
                        return 9288;
                    case Properties::West::FALSE:
                        return 9289;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9290;
                    case Properties::West::FALSE:
                        return 9291;
                    }
                }
            case Properties::South::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9292;
                    case Properties::West::FALSE:
                        return 9293;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9294;
                    case Properties::West::FALSE:
                        return 9295;
                    }
                }
            }
        }
    }
    return 0;
}
}

}
