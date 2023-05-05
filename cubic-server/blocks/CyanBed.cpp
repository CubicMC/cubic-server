#include "CyanBed.hpp"
namespace Blocks {
    namespace CyanBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1781;
                    case Properties::Part::FOOT:
                        return 1782;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1783;
                    case Properties::Part::FOOT:
                        return 1784;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1785;
                    case Properties::Part::FOOT:
                        return 1786;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1787;
                    case Properties::Part::FOOT:
                        return 1788;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1789;
                    case Properties::Part::FOOT:
                        return 1790;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1791;
                    case Properties::Part::FOOT:
                        return 1792;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1793;
                    case Properties::Part::FOOT:
                        return 1794;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1795;
                    case Properties::Part::FOOT:
                        return 1796;
                    }
                }
            }
            return 0;
        }
    }

}
