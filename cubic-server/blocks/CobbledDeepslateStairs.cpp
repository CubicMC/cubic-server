#include "CobbledDeepslateStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CobbledDeepslateStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21566;
                        case Properties::Waterlogged::FALSE:
                            return 21567;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21568;
                        case Properties::Waterlogged::FALSE:
                            return 21569;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21570;
                        case Properties::Waterlogged::FALSE:
                            return 21571;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21572;
                        case Properties::Waterlogged::FALSE:
                            return 21573;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21574;
                        case Properties::Waterlogged::FALSE:
                            return 21575;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21576;
                        case Properties::Waterlogged::FALSE:
                            return 21577;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21578;
                        case Properties::Waterlogged::FALSE:
                            return 21579;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21580;
                        case Properties::Waterlogged::FALSE:
                            return 21581;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21582;
                        case Properties::Waterlogged::FALSE:
                            return 21583;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21584;
                        case Properties::Waterlogged::FALSE:
                            return 21585;
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21586;
                        case Properties::Waterlogged::FALSE:
                            return 21587;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21588;
                        case Properties::Waterlogged::FALSE:
                            return 21589;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21590;
                        case Properties::Waterlogged::FALSE:
                            return 21591;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21592;
                        case Properties::Waterlogged::FALSE:
                            return 21593;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21594;
                        case Properties::Waterlogged::FALSE:
                            return 21595;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21596;
                        case Properties::Waterlogged::FALSE:
                            return 21597;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21598;
                        case Properties::Waterlogged::FALSE:
                            return 21599;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21600;
                        case Properties::Waterlogged::FALSE:
                            return 21601;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21602;
                        case Properties::Waterlogged::FALSE:
                            return 21603;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21604;
                        case Properties::Waterlogged::FALSE:
                            return 21605;
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21606;
                        case Properties::Waterlogged::FALSE:
                            return 21607;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21608;
                        case Properties::Waterlogged::FALSE:
                            return 21609;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21610;
                        case Properties::Waterlogged::FALSE:
                            return 21611;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21612;
                        case Properties::Waterlogged::FALSE:
                            return 21613;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21614;
                        case Properties::Waterlogged::FALSE:
                            return 21615;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21616;
                        case Properties::Waterlogged::FALSE:
                            return 21617;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21618;
                        case Properties::Waterlogged::FALSE:
                            return 21619;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21620;
                        case Properties::Waterlogged::FALSE:
                            return 21621;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21622;
                        case Properties::Waterlogged::FALSE:
                            return 21623;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21624;
                        case Properties::Waterlogged::FALSE:
                            return 21625;
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21626;
                        case Properties::Waterlogged::FALSE:
                            return 21627;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21628;
                        case Properties::Waterlogged::FALSE:
                            return 21629;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21630;
                        case Properties::Waterlogged::FALSE:
                            return 21631;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21632;
                        case Properties::Waterlogged::FALSE:
                            return 21633;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21634;
                        case Properties::Waterlogged::FALSE:
                            return 21635;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21636;
                        case Properties::Waterlogged::FALSE:
                            return 21637;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21638;
                        case Properties::Waterlogged::FALSE:
                            return 21639;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21640;
                        case Properties::Waterlogged::FALSE:
                            return 21641;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21642;
                        case Properties::Waterlogged::FALSE:
                            return 21643;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21644;
                        case Properties::Waterlogged::FALSE:
                            return 21645;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
