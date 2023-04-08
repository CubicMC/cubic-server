#include "DarkOakStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace DarkOakStairs {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9568;
                case Properties::Waterlogged::FALSE:
                    return 9569;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9570;
                case Properties::Waterlogged::FALSE:
                    return 9571;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9572;
                case Properties::Waterlogged::FALSE:
                    return 9573;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9574;
                case Properties::Waterlogged::FALSE:
                    return 9575;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9576;
                case Properties::Waterlogged::FALSE:
                    return 9577;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9578;
                case Properties::Waterlogged::FALSE:
                    return 9579;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9580;
                case Properties::Waterlogged::FALSE:
                    return 9581;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9582;
                case Properties::Waterlogged::FALSE:
                    return 9583;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9584;
                case Properties::Waterlogged::FALSE:
                    return 9585;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9586;
                case Properties::Waterlogged::FALSE:
                    return 9587;
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
                    return 9588;
                case Properties::Waterlogged::FALSE:
                    return 9589;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9590;
                case Properties::Waterlogged::FALSE:
                    return 9591;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9592;
                case Properties::Waterlogged::FALSE:
                    return 9593;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9594;
                case Properties::Waterlogged::FALSE:
                    return 9595;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9596;
                case Properties::Waterlogged::FALSE:
                    return 9597;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9598;
                case Properties::Waterlogged::FALSE:
                    return 9599;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9600;
                case Properties::Waterlogged::FALSE:
                    return 9601;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9602;
                case Properties::Waterlogged::FALSE:
                    return 9603;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9604;
                case Properties::Waterlogged::FALSE:
                    return 9605;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9606;
                case Properties::Waterlogged::FALSE:
                    return 9607;
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
                    return 9608;
                case Properties::Waterlogged::FALSE:
                    return 9609;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9610;
                case Properties::Waterlogged::FALSE:
                    return 9611;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9612;
                case Properties::Waterlogged::FALSE:
                    return 9613;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9614;
                case Properties::Waterlogged::FALSE:
                    return 9615;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9616;
                case Properties::Waterlogged::FALSE:
                    return 9617;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9618;
                case Properties::Waterlogged::FALSE:
                    return 9619;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9620;
                case Properties::Waterlogged::FALSE:
                    return 9621;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9622;
                case Properties::Waterlogged::FALSE:
                    return 9623;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9624;
                case Properties::Waterlogged::FALSE:
                    return 9625;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9626;
                case Properties::Waterlogged::FALSE:
                    return 9627;
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
                    return 9628;
                case Properties::Waterlogged::FALSE:
                    return 9629;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9630;
                case Properties::Waterlogged::FALSE:
                    return 9631;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9632;
                case Properties::Waterlogged::FALSE:
                    return 9633;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9634;
                case Properties::Waterlogged::FALSE:
                    return 9635;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9636;
                case Properties::Waterlogged::FALSE:
                    return 9637;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9638;
                case Properties::Waterlogged::FALSE:
                    return 9639;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9640;
                case Properties::Waterlogged::FALSE:
                    return 9641;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9642;
                case Properties::Waterlogged::FALSE:
                    return 9643;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9644;
                case Properties::Waterlogged::FALSE:
                    return 9645;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 9646;
                case Properties::Waterlogged::FALSE:
                    return 9647;
                }
            }
        }
    }
    return 0;
}
}

}
