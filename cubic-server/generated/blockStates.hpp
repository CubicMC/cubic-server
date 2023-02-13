#include <string>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    struct Block {
        std::string name;
        std::vector<std::pair<std::string, std::string>> properties;
    };

    namespace AcaciaButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaPlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaPressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AcaciaWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ActivatorRail {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Shape {
                NORTH_SOUTH,
                EAST_WEST,
                ASCENDING_EAST,
                ASCENDING_WEST,
                ASCENDING_NORTH,
                ASCENDING_SOUTH
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Air {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Allium {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AmethystBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AmethystCluster {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AncientDebris {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Andesite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AndesiteSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AndesiteStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AndesiteWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Anvil {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AttachedMelonStem {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AttachedPumpkinStem {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Azalea {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AzaleaLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace AzureBluet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Bamboo {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE
            };
            enum class Leaves {
                NONE,
                SMALL,
                LARGE
            };
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Leaves leaves, Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BambooSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Barrel {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Open {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Open open);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Barrier {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Basalt {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Beacon {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Bedrock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BeeNest {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Honey_level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Beehive {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Honey_level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Beetroots {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Bell {
        namespace Properties {
            enum class Attachment {
                FLOOR,
                CEILING,
                SINGLE_WALL,
                DOUBLE_WALL
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Attachment attachment, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BigDripleaf {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Tilt {
                NONE,
                UNSTABLE,
                PARTIAL,
                FULL
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Tilt tilt, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BigDripleafStem {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchPlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchPressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BirchWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Blackstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackstoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlackstoneWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlastFurnace {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueIce {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueOrchid {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BlueWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BoneBlock {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Bookshelf {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrainCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrainCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrainCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrainCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrewingStand {
        namespace Properties {
            enum class Has_bottle_0 {
                TRUE,
                FALSE
            };
            enum class Has_bottle_1 {
                TRUE,
                FALSE
            };
            enum class Has_bottle_2 {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Has_bottle_0 has_bottle_0, Properties::Has_bottle_1 has_bottle_1, Properties::Has_bottle_2 has_bottle_2);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Bricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownMushroom {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownMushroomBlock {
        namespace Properties {
            enum class Down {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BrownWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BubbleColumn {
        namespace Properties {
            enum class Drag {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Drag drag);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BubbleCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BubbleCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BubbleCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BubbleCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace BuddingAmethyst {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cactus {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cake {
        namespace Properties {
            enum class Bites {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX
            };
        }
        BlockId toProtocol(Properties::Bites bites);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Calcite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Campfire {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Signal_fire {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Candle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Carrots {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CartographyTable {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CarvedPumpkin {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cauldron {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CaveAir {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CaveVines {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN,
                SIXTEEN,
                SEVENTEEN,
                EIGHTEEN,
                NINETEEN,
                TWENTY,
                TWENTY_ONE,
                TWENTY_TWO,
                TWENTY_THREE,
                TWENTY_FOUR,
                TWENTY_FIVE
            };
            enum class Berries {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Berries berries);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CaveVinesPlant {
        namespace Properties {
            enum class Berries {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Berries berries);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Chain {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Axis axis, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChainCommandBlock {
        namespace Properties {
            enum class Conditional {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Chest {
        namespace Properties {
            enum class Type {
                SINGLE,
                LEFT,
                RIGHT
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChippedAnvil {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledDeepslate {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledNetherBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledPolishedBlackstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledQuartzBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledRedSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChiseledStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChorusFlower {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ChorusPlant {
        namespace Properties {
            enum class Down {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Clay {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CoalBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CoalOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CoarseDirt {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobbledDeepslate {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobbledDeepslateSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobbledDeepslateStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobbledDeepslateWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cobblestone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobblestoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobblestoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CobblestoneWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cobweb {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cocoa {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CommandBlock {
        namespace Properties {
            enum class Conditional {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Comparator {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Mode {
                COMPARE,
                SUBTRACT
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Mode mode, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Composter {
        namespace Properties {
            enum class Level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Conduit {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CopperBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CopperOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Cornflower {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrackedDeepslateBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrackedDeepslateTiles {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrackedNetherBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrackedPolishedBlackstoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrackedStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CraftingTable {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CreeperHead {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CreeperWallHead {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonFungus {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonHyphae {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonNylium {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonPlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonPressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonRoots {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonStem {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CrimsonWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CryingObsidian {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutRedSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutRedSandstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CutSandstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace CyanWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DamagedAnvil {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Dandelion {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakPlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakPressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkOakWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkPrismarine {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkPrismarineSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DarkPrismarineStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DaylightDetector {
        namespace Properties {
            enum class Inverted {
                TRUE,
                FALSE
            };
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Inverted inverted, Properties::Power power);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBrainCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBrainCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBrainCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBrainCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBubbleCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBubbleCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBubbleCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBubbleCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadBush {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadFireCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadFireCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadFireCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadFireCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadHornCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadHornCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadHornCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadHornCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadTubeCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadTubeCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadTubeCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeadTubeCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Deepslate {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateCoalOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateCopperOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateDiamondOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateEmeraldOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateGoldOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateIronOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateLapisOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateRedstoneOre {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateTileSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateTileStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateTileWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DeepslateTiles {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DetectorRail {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Shape {
                NORTH_SOUTH,
                EAST_WEST,
                ASCENDING_EAST,
                ASCENDING_WEST,
                ASCENDING_NORTH,
                ASCENDING_SOUTH
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DiamondBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DiamondOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Diorite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DioriteSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DioriteStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DioriteWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Dirt {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DirtPath {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Dispenser {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Triggered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Triggered triggered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DragonEgg {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DragonHead {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DragonWallHead {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DriedKelpBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace DripstoneBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Dropper {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Triggered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Triggered triggered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EmeraldBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EmeraldOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EnchantingTable {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndGateway {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndPortal {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndPortalFrame {
        namespace Properties {
            enum class Eye {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Eye eye, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndRod {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndStone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndStoneBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndStoneBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndStoneBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EndStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace EnderChest {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ExposedCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ExposedCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ExposedCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ExposedCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Farmland {
        namespace Properties {
            enum class Moisture {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Moisture moisture);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Fern {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Fire {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FireCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FireCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FireCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FireCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FletchingTable {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FlowerPot {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FloweringAzalea {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FloweringAzaleaLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Frogspawn {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace FrostedIce {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Furnace {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GildedBlackstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Glass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GlowLichen {
        namespace Properties {
            enum class Down {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Glowstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GoldBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GoldOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Granite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GraniteSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GraniteStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GraniteWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Grass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrassBlock {
        namespace Properties {
            enum class Snowy {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Snowy snowy);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Gravel {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GrayWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace GreenWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Grindstone {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HangingRoots {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HayBlock {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HeavyWeightedPressurePlate {
        namespace Properties {
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Power power);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HoneyBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HoneycombBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Hopper {
        namespace Properties {
            enum class Enabled {
                TRUE,
                FALSE
            };
            enum class Facing {
                DOWN,
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Enabled enabled, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HornCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HornCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HornCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace HornCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Ice {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedChiseledStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedCobblestone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedCrackedStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedDeepslate {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedMossyStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedStone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace InfestedStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace IronBars {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace IronBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace IronDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace IronOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace IronTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JackOLantern {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Jigsaw {
        namespace Properties {
            enum class Orientation {
                DOWN_EAST,
                DOWN_NORTH,
                DOWN_SOUTH,
                DOWN_WEST,
                UP_EAST,
                UP_NORTH,
                UP_SOUTH,
                UP_WEST,
                WEST_UP,
                EAST_UP,
                NORTH_UP,
                SOUTH_UP
            };
        }
        BlockId toProtocol(Properties::Orientation orientation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Jukebox {
        namespace Properties {
            enum class Has_record {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Has_record has_record);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JunglePlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JunglePressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace JungleWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Kelp {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN,
                SIXTEEN,
                SEVENTEEN,
                EIGHTEEN,
                NINETEEN,
                TWENTY,
                TWENTY_ONE,
                TWENTY_TWO,
                TWENTY_THREE,
                TWENTY_FOUR,
                TWENTY_FIVE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace KelpPlant {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Ladder {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Lantern {
        namespace Properties {
            enum class Hanging {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LapisBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LapisOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LargeAmethystBud {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LargeFern {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Lava {
        namespace Properties {
            enum class Level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LavaCauldron {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Lectern {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Has_book {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Has_book has_book, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Lever {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Light {
        namespace Properties {
            enum class Level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Level level, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightBlueWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightGrayWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightWeightedPressurePlate {
        namespace Properties {
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Power power);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LightningRod {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Lilac {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LilyOfTheValley {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LilyPad {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace LimeWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Lodestone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Loom {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagentaWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MagmaBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangrovePlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangrovePressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangrovePropagule {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Hanging {
                TRUE,
                FALSE
            };
            enum class Stage {
                ZERO,
                ONE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Hanging hanging, Properties::Stage stage, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveRoots {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MangroveWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MediumAmethystBud {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Melon {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MelonStem {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyCobblestone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyCobblestoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyCobblestoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyCobblestoneWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyStoneBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyStoneBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyStoneBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MossyStoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MovingPiston {
        namespace Properties {
            enum class Type {
                NORMAL,
                STICKY
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Mud {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MudBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MudBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MudBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MudBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MuddyMangroveRoots {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace MushroomStem {
        namespace Properties {
            enum class Down {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Mycelium {
        namespace Properties {
            enum class Snowy {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Snowy snowy);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherBrickFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherGoldOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherPortal {
        namespace Properties {
            enum class Axis {
                X,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherQuartzOre {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherSprouts {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherWart {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetherWartBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NetheriteBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Netherrack {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace NoteBlock {
        namespace Properties {
            enum class Instrument {
                HARP,
                BASEDRUM,
                SNARE,
                HAT,
                BASS,
                FLUTE,
                BELL,
                GUITAR,
                CHIME,
                XYLOPHONE,
                IRON_XYLOPHONE,
                COW_BELL,
                DIDGERIDOO,
                BIT,
                BANJO,
                PLING
            };
            enum class Note {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN,
                SIXTEEN,
                SEVENTEEN,
                EIGHTEEN,
                NINETEEN,
                TWENTY,
                TWENTY_ONE,
                TWENTY_TWO,
                TWENTY_THREE,
                TWENTY_FOUR
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Instrument instrument, Properties::Note note, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakPlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakPressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OakWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Observer {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Obsidian {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OchreFroglight {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OrangeWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OxeyeDaisy {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OxidizedCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OxidizedCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OxidizedCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace OxidizedCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PackedIce {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PackedMud {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PearlescentFroglight {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Peony {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PetrifiedOakSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PinkWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Piston {
        namespace Properties {
            enum class Extended {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Extended extended, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PistonHead {
        namespace Properties {
            enum class Type {
                NORMAL,
                STICKY
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Short_ {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Short_ short_);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PlayerHead {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PlayerWallHead {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Podzol {
        namespace Properties {
            enum class Snowy {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Snowy snowy);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PointedDripstone {
        namespace Properties {
            enum class Thickness {
                TIP_MERGE,
                TIP,
                FRUSTUM,
                MIDDLE,
                BASE
            };
            enum class Vertical_direction {
                UP,
                DOWN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Thickness thickness, Properties::Vertical_direction vertical_direction, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedAndesite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedAndesiteSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedAndesiteStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBasalt {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstonePressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedBlackstoneWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDeepslate {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDeepslateSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDeepslateStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDeepslateWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDiorite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDioriteSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedDioriteStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedGranite {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedGraniteSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PolishedGraniteStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Poppy {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Potatoes {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedAcaciaSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedAllium {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedAzaleaBush {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedAzureBluet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedBamboo {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedBirchSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedBlueOrchid {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedBrownMushroom {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedCactus {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedCornflower {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedCrimsonFungus {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedCrimsonRoots {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedDandelion {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedDarkOakSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedDeadBush {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedFern {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedFloweringAzaleaBush {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedJungleSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedLilyOfTheValley {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedMangrovePropagule {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedOakSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedOrangeTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedOxeyeDaisy {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedPinkTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedPoppy {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedRedMushroom {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedRedTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedSpruceSapling {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedWarpedFungus {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedWarpedRoots {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedWhiteTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PottedWitherRose {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PowderSnow {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PowderSnowCauldron {
        namespace Properties {
            enum class Level {
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PoweredRail {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Shape {
                NORTH_SOUTH,
                EAST_WEST,
                ASCENDING_EAST,
                ASCENDING_WEST,
                ASCENDING_NORTH,
                ASCENDING_SOUTH
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Prismarine {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PrismarineBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PrismarineBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PrismarineBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PrismarineSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PrismarineStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PrismarineWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Pumpkin {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PumpkinStem {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpleWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpurBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpurPillar {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpurSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace PurpurStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace QuartzBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace QuartzBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace QuartzPillar {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace QuartzSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace QuartzStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Rail {
        namespace Properties {
            enum class Shape {
                NORTH_SOUTH,
                EAST_WEST,
                ASCENDING_EAST,
                ASCENDING_WEST,
                ASCENDING_NORTH,
                ASCENDING_SOUTH,
                SOUTH_EAST,
                SOUTH_WEST,
                NORTH_WEST,
                NORTH_EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RawCopperBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RawGoldBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RawIronBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedMushroom {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedMushroomBlock {
        namespace Properties {
            enum class Down {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedNetherBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedNetherBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedNetherBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedNetherBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedSand {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedSandstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedSandstoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedSandstoneWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedstoneBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedstoneLamp {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedstoneOre {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedstoneTorch {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedstoneWallTorch {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RedstoneWire {
        namespace Properties {
            enum class East {
                UP,
                SIDE,
                NONE
            };
            enum class North {
                UP,
                SIDE,
                NONE
            };
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class South {
                UP,
                SIDE,
                NONE
            };
            enum class West {
                UP,
                SIDE,
                NONE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::Power power, Properties::South south, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ReinforcedDeepslate {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Repeater {
        namespace Properties {
            enum class Delay {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Locked {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Delay delay, Properties::Facing facing, Properties::Locked locked, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RepeatingCommandBlock {
        namespace Properties {
            enum class Conditional {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RespawnAnchor {
        namespace Properties {
            enum class Charges {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR
            };
        }
        BlockId toProtocol(Properties::Charges charges);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RootedDirt {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace RoseBush {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Sand {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Sandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SandstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SandstoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SandstoneWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Scaffolding {
        namespace Properties {
            enum class Bottom {
                TRUE,
                FALSE
            };
            enum class Distance {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Bottom bottom, Properties::Distance distance, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Sculk {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SculkCatalyst {
        namespace Properties {
            enum class Bloom {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Bloom bloom);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SculkSensor {
        namespace Properties {
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Sculk_sensor_phase {
                INACTIVE,
                ACTIVE,
                COOLDOWN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Power power, Properties::Sculk_sensor_phase sculk_sensor_phase, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SculkShrieker {
        namespace Properties {
            enum class Can_summon {
                TRUE,
                FALSE
            };
            enum class Shrieking {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Can_summon can_summon, Properties::Shrieking shrieking, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SculkVein {
        namespace Properties {
            enum class Down {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SeaLantern {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SeaPickle {
        namespace Properties {
            enum class Pickles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Pickles pickles, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Seagrass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Shroomlight {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SkeletonSkull {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SkeletonWallSkull {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SlimeBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmallAmethystBud {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmallDripleaf {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmithingTable {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Smoker {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothBasalt {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothQuartz {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothQuartzSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothQuartzStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothRedSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothRedSandstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothRedSandstoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothSandstone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothSandstoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothSandstoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothStone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SmoothStoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Snow {
        namespace Properties {
            enum class Layers {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT
            };
        }
        BlockId toProtocol(Properties::Layers layers);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SnowBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulCampfire {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Signal_fire {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulFire {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulLantern {
        namespace Properties {
            enum class Hanging {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulSand {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulSoil {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulTorch {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SoulWallTorch {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Spawner {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Sponge {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SporeBlossom {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceLeaves {
        namespace Properties {
            enum class Distance {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
            enum class Persistent {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SprucePlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SprucePressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SpruceWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StickyPiston {
        namespace Properties {
            enum class Extended {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Extended extended, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Stone {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneBrickSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneBrickStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneBrickWall {
        namespace Properties {
            enum class East {
                NONE,
                LOW,
                TALL
            };
            enum class North {
                NONE,
                LOW,
                TALL
            };
            enum class South {
                NONE,
                LOW,
                TALL
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                NONE,
                LOW,
                TALL
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneBricks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StonePressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StoneStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Stonecutter {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedAcaciaLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedAcaciaWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedBirchLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedBirchWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedCrimsonHyphae {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedCrimsonStem {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedDarkOakLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedDarkOakWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedJungleLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedJungleWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedMangroveLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedMangroveWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedOakLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedOakWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedSpruceLog {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedSpruceWood {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedWarpedHyphae {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StrippedWarpedStem {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StructureBlock {
        namespace Properties {
            enum class Mode {
                SAVE,
                LOAD,
                CORNER,
                DATA
            };
        }
        BlockId toProtocol(Properties::Mode mode);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace StructureVoid {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SugarCane {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Sunflower {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace SweetBerryBush {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TallGrass {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TallSeagrass {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Target {
        namespace Properties {
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Power power);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Terracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TintedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Tnt {
        namespace Properties {
            enum class Unstable {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Unstable unstable);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Torch {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TrappedChest {
        namespace Properties {
            enum class Type {
                SINGLE,
                LEFT,
                RIGHT
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Tripwire {
        namespace Properties {
            enum class Attached {
                TRUE,
                FALSE
            };
            enum class Disarmed {
                TRUE,
                FALSE
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Attached attached, Properties::Disarmed disarmed, Properties::East east, Properties::North north, Properties::Powered powered, Properties::South south, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TripwireHook {
        namespace Properties {
            enum class Attached {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Attached attached, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TubeCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TubeCoralBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TubeCoralFan {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TubeCoralWallFan {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Tuff {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TurtleEgg {
        namespace Properties {
            enum class Eggs {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Hatch {
                ZERO,
                ONE,
                TWO
            };
        }
        BlockId toProtocol(Properties::Eggs eggs, Properties::Hatch hatch);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TwistingVines {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN,
                SIXTEEN,
                SEVENTEEN,
                EIGHTEEN,
                NINETEEN,
                TWENTY,
                TWENTY_ONE,
                TWENTY_TWO,
                TWENTY_THREE,
                TWENTY_FOUR,
                TWENTY_FIVE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace TwistingVinesPlant {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace VerdantFroglight {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Vine {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace VoidAir {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WallTorch {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedFence {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedFenceGate {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class In_wall {
                TRUE,
                FALSE
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedFungus {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedHyphae {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedNylium {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedPlanks {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedPressurePlate {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedRoots {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedSign {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedStem {
        namespace Properties {
            enum class Axis {
                X,
                Y,
                Z
            };
        }
        BlockId toProtocol(Properties::Axis axis);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedWallSign {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WarpedWartBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Water {
        namespace Properties {
            enum class Level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaterCauldron {
        namespace Properties {
            enum class Level {
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedCopperBlock {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedExposedCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedExposedCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedExposedCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedExposedCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedOxidizedCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedOxidizedCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedOxidizedCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedOxidizedCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedWeatheredCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedWeatheredCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedWeatheredCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WaxedWeatheredCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WeatheredCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WeatheredCutCopper {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WeatheredCutCopperSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WeatheredCutCopperStairs {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WeepingVines {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN,
                SIXTEEN,
                SEVENTEEN,
                EIGHTEEN,
                NINETEEN,
                TWENTY,
                TWENTY_ONE,
                TWENTY_TWO,
                TWENTY_THREE,
                TWENTY_FOUR,
                TWENTY_FIVE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WeepingVinesPlant {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WetSponge {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace Wheat {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteTulip {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WhiteWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WitherRose {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WitherSkeletonSkull {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace WitherSkeletonWallSkull {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowBanner {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowCandleCake {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowCarpet {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowConcrete {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowConcretePowder {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowGlazedTerracotta {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowStainedGlass {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowStainedGlassPane {
        namespace Properties {
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowTerracotta {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowWallBanner {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace YellowWool {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ZombieHead {
        namespace Properties {
            enum class Rotation {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Rotation rotation);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    namespace ZombieWallHead {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

    extern const std::unordered_map<std::string, std::function<BlockId(std::vector<std::pair<std::string, std::string>>)>> nameToProtocolId;
    BlockId fromNameToProtocolId(Block block);
    Block toName(BlockId id);
    constexpr int NUMBER_OF_PROTOCOL_IDS = 0;
}
