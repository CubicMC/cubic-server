#include "GrayBed.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GrayBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1749;
                    case Properties::Part::FOOT:
                        return 1750;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1751;
                    case Properties::Part::FOOT:
                        return 1752;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1753;
                    case Properties::Part::FOOT:
                        return 1754;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1755;
                    case Properties::Part::FOOT:
                        return 1756;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1757;
                    case Properties::Part::FOOT:
                        return 1758;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1759;
                    case Properties::Part::FOOT:
                        return 1760;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1761;
                    case Properties::Part::FOOT:
                        return 1762;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1763;
                    case Properties::Part::FOOT:
                        return 1764;
                    }
                }
            }
            return 0;
        }
    }

}
