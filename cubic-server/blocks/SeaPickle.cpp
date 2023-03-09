#include "SeaPickle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SeaPickle {
        BlockId toProtocol(Properties::Pickles pickles, Properties::Waterlogged waterlogged) {
            switch (pickles) {
            case Properties::Pickles::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12305;
                case Properties::Waterlogged::FALSE:
                    return 12306;
                }
            case Properties::Pickles::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12307;
                case Properties::Waterlogged::FALSE:
                    return 12308;
                }
            case Properties::Pickles::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12309;
                case Properties::Waterlogged::FALSE:
                    return 12310;
                }
            case Properties::Pickles::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12311;
                case Properties::Waterlogged::FALSE:
                    return 12312;
                }
            }
            return 0;
        }
    }

}
