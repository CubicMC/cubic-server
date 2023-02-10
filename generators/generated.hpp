#include <string>
#include <cstdint>

typedef uint16_t Block;

namespace Blocks {
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7035;
case Properties::Powered::FALSE:
return 7036;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7037;
case Properties::Powered::FALSE:
return 7038;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7039;
case Properties::Powered::FALSE:
return 7040;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7041;
case Properties::Powered::FALSE:
return 7042;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7043;
case Properties::Powered::FALSE:
return 7044;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7045;
case Properties::Powered::FALSE:
return 7046;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7047;
case Properties::Powered::FALSE:
return 7048;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7049;
case Properties::Powered::FALSE:
return 7050;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7051;
case Properties::Powered::FALSE:
return 7052;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7053;
case Properties::Powered::FALSE:
return 7054;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7055;
case Properties::Powered::FALSE:
return 7056;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7057;
case Properties::Powered::FALSE:
return 7058;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9747;
case Properties::Powered::FALSE:
return 9748;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9749;
case Properties::Powered::FALSE:
return 9750;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9751;
case Properties::Powered::FALSE:
return 9752;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9753;
case Properties::Powered::FALSE:
return 9754;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9755;
case Properties::Powered::FALSE:
return 9756;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9757;
case Properties::Powered::FALSE:
return 9758;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9759;
case Properties::Powered::FALSE:
return 9760;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9761;
case Properties::Powered::FALSE:
return 9762;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9763;
case Properties::Powered::FALSE:
return 9764;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9765;
case Properties::Powered::FALSE:
return 9766;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9767;
case Properties::Powered::FALSE:
return 9768;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9769;
case Properties::Powered::FALSE:
return 9770;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9771;
case Properties::Powered::FALSE:
return 9772;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9773;
case Properties::Powered::FALSE:
return 9774;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9775;
case Properties::Powered::FALSE:
return 9776;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9777;
case Properties::Powered::FALSE:
return 9778;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9779;
case Properties::Powered::FALSE:
return 9780;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9781;
case Properties::Powered::FALSE:
return 9782;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9783;
case Properties::Powered::FALSE:
return 9784;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9785;
case Properties::Powered::FALSE:
return 9786;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9787;
case Properties::Powered::FALSE:
return 9788;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9789;
case Properties::Powered::FALSE:
return 9790;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9791;
case Properties::Powered::FALSE:
return 9792;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9793;
case Properties::Powered::FALSE:
return 9794;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9795;
case Properties::Powered::FALSE:
return 9796;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9797;
case Properties::Powered::FALSE:
return 9798;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9799;
case Properties::Powered::FALSE:
return 9800;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9801;
case Properties::Powered::FALSE:
return 9802;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9803;
case Properties::Powered::FALSE:
return 9804;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9805;
case Properties::Powered::FALSE:
return 9806;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9807;
case Properties::Powered::FALSE:
return 9808;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9809;
case Properties::Powered::FALSE:
return 9810;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 9459;
case Properties::West::FALSE:
return 9460;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9461;
case Properties::West::FALSE:
return 9462;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9463;
case Properties::West::FALSE:
return 9464;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9465;
case Properties::West::FALSE:
return 9466;
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
return 9467;
case Properties::West::FALSE:
return 9468;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9469;
case Properties::West::FALSE:
return 9470;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9471;
case Properties::West::FALSE:
return 9472;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9473;
case Properties::West::FALSE:
return 9474;
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
return 9475;
case Properties::West::FALSE:
return 9476;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9477;
case Properties::West::FALSE:
return 9478;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9479;
case Properties::West::FALSE:
return 9480;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9481;
case Properties::West::FALSE:
return 9482;
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
return 9483;
case Properties::West::FALSE:
return 9484;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9485;
case Properties::West::FALSE:
return 9486;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9487;
case Properties::West::FALSE:
return 9488;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9489;
case Properties::West::FALSE:
return 9490;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9267;
case Properties::Powered::FALSE:
return 9268;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9269;
case Properties::Powered::FALSE:
return 9270;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9271;
case Properties::Powered::FALSE:
return 9272;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9273;
case Properties::Powered::FALSE:
return 9274;
}
}
}
case Properties::Facing::SOUTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9275;
case Properties::Powered::FALSE:
return 9276;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9277;
case Properties::Powered::FALSE:
return 9278;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9279;
case Properties::Powered::FALSE:
return 9280;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9281;
case Properties::Powered::FALSE:
return 9282;
}
}
}
case Properties::Facing::WEST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9283;
case Properties::Powered::FALSE:
return 9284;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9285;
case Properties::Powered::FALSE:
return 9286;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9287;
case Properties::Powered::FALSE:
return 9288;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9289;
case Properties::Powered::FALSE:
return 9290;
}
}
}
case Properties::Facing::EAST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9291;
case Properties::Powered::FALSE:
return 9292;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9293;
case Properties::Powered::FALSE:
return 9294;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9295;
case Properties::Powered::FALSE:
return 9296;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9297;
case Properties::Powered::FALSE:
return 9298;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 318;
case Properties::Waterlogged::FALSE:
return 319;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 320;
case Properties::Waterlogged::FALSE:
return 321;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 322;
case Properties::Waterlogged::FALSE:
return 323;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 324;
case Properties::Waterlogged::FALSE:
return 325;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 326;
case Properties::Waterlogged::FALSE:
return 327;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 328;
case Properties::Waterlogged::FALSE:
return 329;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 330;
case Properties::Waterlogged::FALSE:
return 331;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 332;
case Properties::Waterlogged::FALSE:
return 333;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 334;
case Properties::Waterlogged::FALSE:
return 335;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 336;
case Properties::Waterlogged::FALSE:
return 337;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 338;
case Properties::Waterlogged::FALSE:
return 339;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 340;
case Properties::Waterlogged::FALSE:
return 341;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 342;
case Properties::Waterlogged::FALSE:
return 343;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 344;
case Properties::Waterlogged::FALSE:
return 345;
}
}
}
return 0;
}
}

namespace AcaciaLog {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 129;
case Properties::Axis::Y:
return 130;
case Properties::Axis::Z:
return 131;
}
return 0;
}
}

namespace AcaciaPlanks {
constexpr Block toProtocol() {
return 19;
return 0;
}
}

namespace AcaciaPressurePlate {
namespace Properties {
enum class Powered {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Powered powered) {
switch (powered) {
case Properties::Powered::TRUE:
return 4186;
case Properties::Powered::FALSE:
return 4187;
}
return 0;
}
}

namespace AcaciaSapling {
namespace Properties {
enum class Stage {
ZERO,
ONE
};
}
constexpr Block toProtocol(Properties::Stage stage) {
switch (stage) {
case Properties::Stage::ZERO:
return 30;
case Properties::Stage::ONE:
return 31;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
switch (rotation) {
case Properties::Rotation::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3732;
case Properties::Waterlogged::FALSE:
return 3733;
}
case Properties::Rotation::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3734;
case Properties::Waterlogged::FALSE:
return 3735;
}
case Properties::Rotation::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3736;
case Properties::Waterlogged::FALSE:
return 3737;
}
case Properties::Rotation::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3738;
case Properties::Waterlogged::FALSE:
return 3739;
}
case Properties::Rotation::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3740;
case Properties::Waterlogged::FALSE:
return 3741;
}
case Properties::Rotation::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3742;
case Properties::Waterlogged::FALSE:
return 3743;
}
case Properties::Rotation::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3744;
case Properties::Waterlogged::FALSE:
return 3745;
}
case Properties::Rotation::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3746;
case Properties::Waterlogged::FALSE:
return 3747;
}
case Properties::Rotation::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3748;
case Properties::Waterlogged::FALSE:
return 3749;
}
case Properties::Rotation::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3750;
case Properties::Waterlogged::FALSE:
return 3751;
}
case Properties::Rotation::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3752;
case Properties::Waterlogged::FALSE:
return 3753;
}
case Properties::Rotation::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3754;
case Properties::Waterlogged::FALSE:
return 3755;
}
case Properties::Rotation::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3756;
case Properties::Waterlogged::FALSE:
return 3757;
}
case Properties::Rotation::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3758;
case Properties::Waterlogged::FALSE:
return 3759;
}
case Properties::Rotation::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3760;
case Properties::Waterlogged::FALSE:
return 3761;
}
case Properties::Rotation::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3762;
case Properties::Waterlogged::FALSE:
return 3763;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9065;
case Properties::Waterlogged::FALSE:
return 9066;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9067;
case Properties::Waterlogged::FALSE:
return 9068;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9069;
case Properties::Waterlogged::FALSE:
return 9070;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8004;
case Properties::Waterlogged::FALSE:
return 8005;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8006;
case Properties::Waterlogged::FALSE:
return 8007;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8008;
case Properties::Waterlogged::FALSE:
return 8009;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8010;
case Properties::Waterlogged::FALSE:
return 8011;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8012;
case Properties::Waterlogged::FALSE:
return 8013;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8014;
case Properties::Waterlogged::FALSE:
return 8015;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8016;
case Properties::Waterlogged::FALSE:
return 8017;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8018;
case Properties::Waterlogged::FALSE:
return 8019;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8020;
case Properties::Waterlogged::FALSE:
return 8021;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8022;
case Properties::Waterlogged::FALSE:
return 8023;
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
return 8024;
case Properties::Waterlogged::FALSE:
return 8025;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8026;
case Properties::Waterlogged::FALSE:
return 8027;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8028;
case Properties::Waterlogged::FALSE:
return 8029;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8030;
case Properties::Waterlogged::FALSE:
return 8031;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8032;
case Properties::Waterlogged::FALSE:
return 8033;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8034;
case Properties::Waterlogged::FALSE:
return 8035;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8036;
case Properties::Waterlogged::FALSE:
return 8037;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8038;
case Properties::Waterlogged::FALSE:
return 8039;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8040;
case Properties::Waterlogged::FALSE:
return 8041;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8042;
case Properties::Waterlogged::FALSE:
return 8043;
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
return 8044;
case Properties::Waterlogged::FALSE:
return 8045;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8046;
case Properties::Waterlogged::FALSE:
return 8047;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8048;
case Properties::Waterlogged::FALSE:
return 8049;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8050;
case Properties::Waterlogged::FALSE:
return 8051;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8052;
case Properties::Waterlogged::FALSE:
return 8053;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8054;
case Properties::Waterlogged::FALSE:
return 8055;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8056;
case Properties::Waterlogged::FALSE:
return 8057;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8058;
case Properties::Waterlogged::FALSE:
return 8059;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8060;
case Properties::Waterlogged::FALSE:
return 8061;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8062;
case Properties::Waterlogged::FALSE:
return 8063;
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
return 8064;
case Properties::Waterlogged::FALSE:
return 8065;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8066;
case Properties::Waterlogged::FALSE:
return 8067;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8068;
case Properties::Waterlogged::FALSE:
return 8069;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8070;
case Properties::Waterlogged::FALSE:
return 8071;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8072;
case Properties::Waterlogged::FALSE:
return 8073;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8074;
case Properties::Waterlogged::FALSE:
return 8075;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8076;
case Properties::Waterlogged::FALSE:
return 8077;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8078;
case Properties::Waterlogged::FALSE:
return 8079;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8080;
case Properties::Waterlogged::FALSE:
return 8081;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8082;
case Properties::Waterlogged::FALSE:
return 8083;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4676;
case Properties::Waterlogged::FALSE:
return 4677;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4678;
case Properties::Waterlogged::FALSE:
return 4679;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4680;
case Properties::Waterlogged::FALSE:
return 4681;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4682;
case Properties::Waterlogged::FALSE:
return 4683;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4684;
case Properties::Waterlogged::FALSE:
return 4685;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4686;
case Properties::Waterlogged::FALSE:
return 4687;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4688;
case Properties::Waterlogged::FALSE:
return 4689;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4690;
case Properties::Waterlogged::FALSE:
return 4691;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4692;
case Properties::Waterlogged::FALSE:
return 4693;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4694;
case Properties::Waterlogged::FALSE:
return 4695;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4696;
case Properties::Waterlogged::FALSE:
return 4697;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4698;
case Properties::Waterlogged::FALSE:
return 4699;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4700;
case Properties::Waterlogged::FALSE:
return 4701;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4702;
case Properties::Waterlogged::FALSE:
return 4703;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4704;
case Properties::Waterlogged::FALSE:
return 4705;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4706;
case Properties::Waterlogged::FALSE:
return 4707;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4708;
case Properties::Waterlogged::FALSE:
return 4709;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4710;
case Properties::Waterlogged::FALSE:
return 4711;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4712;
case Properties::Waterlogged::FALSE:
return 4713;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4714;
case Properties::Waterlogged::FALSE:
return 4715;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4716;
case Properties::Waterlogged::FALSE:
return 4717;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4718;
case Properties::Waterlogged::FALSE:
return 4719;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4720;
case Properties::Waterlogged::FALSE:
return 4721;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4722;
case Properties::Waterlogged::FALSE:
return 4723;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4724;
case Properties::Waterlogged::FALSE:
return 4725;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4726;
case Properties::Waterlogged::FALSE:
return 4727;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4728;
case Properties::Waterlogged::FALSE:
return 4729;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4730;
case Properties::Waterlogged::FALSE:
return 4731;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4732;
case Properties::Waterlogged::FALSE:
return 4733;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4734;
case Properties::Waterlogged::FALSE:
return 4735;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4736;
case Properties::Waterlogged::FALSE:
return 4737;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4738;
case Properties::Waterlogged::FALSE:
return 4739;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4056;
case Properties::Waterlogged::FALSE:
return 4057;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4058;
case Properties::Waterlogged::FALSE:
return 4059;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4060;
case Properties::Waterlogged::FALSE:
return 4061;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4062;
case Properties::Waterlogged::FALSE:
return 4063;
}
}
return 0;
}
}

namespace AcaciaWood {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 176;
case Properties::Axis::Y:
return 177;
case Properties::Axis::Z:
return 178;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (powered) {
case Properties::Powered::TRUE:
switch (shape) {
case Properties::Shape::NORTH_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7440;
case Properties::Waterlogged::FALSE:
return 7441;
}
case Properties::Shape::EAST_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7442;
case Properties::Waterlogged::FALSE:
return 7443;
}
case Properties::Shape::ASCENDING_EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7444;
case Properties::Waterlogged::FALSE:
return 7445;
}
case Properties::Shape::ASCENDING_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7446;
case Properties::Waterlogged::FALSE:
return 7447;
}
case Properties::Shape::ASCENDING_NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7448;
case Properties::Waterlogged::FALSE:
return 7449;
}
case Properties::Shape::ASCENDING_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7450;
case Properties::Waterlogged::FALSE:
return 7451;
}
}
case Properties::Powered::FALSE:
switch (shape) {
case Properties::Shape::NORTH_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7452;
case Properties::Waterlogged::FALSE:
return 7453;
}
case Properties::Shape::EAST_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7454;
case Properties::Waterlogged::FALSE:
return 7455;
}
case Properties::Shape::ASCENDING_EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7456;
case Properties::Waterlogged::FALSE:
return 7457;
}
case Properties::Shape::ASCENDING_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7458;
case Properties::Waterlogged::FALSE:
return 7459;
}
case Properties::Shape::ASCENDING_NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7460;
case Properties::Waterlogged::FALSE:
return 7461;
}
case Properties::Shape::ASCENDING_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 7462;
case Properties::Waterlogged::FALSE:
return 7463;
}
}
}
return 0;
}
}

namespace Air {
constexpr Block toProtocol() {
return 0;
return 0;
}
}

namespace Allium {
constexpr Block toProtocol() {
return 1669;
return 0;
}
}

namespace AmethystBlock {
constexpr Block toProtocol() {
return 18619;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18621;
case Properties::Waterlogged::FALSE:
return 18622;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18623;
case Properties::Waterlogged::FALSE:
return 18624;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18625;
case Properties::Waterlogged::FALSE:
return 18626;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18627;
case Properties::Waterlogged::FALSE:
return 18628;
}
case Properties::Facing::UP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18629;
case Properties::Waterlogged::FALSE:
return 18630;
}
case Properties::Facing::DOWN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18631;
case Properties::Waterlogged::FALSE:
return 18632;
}
}
return 0;
}
}

namespace AncientDebris {
constexpr Block toProtocol() {
return 17036;
return 0;
}
}

namespace Andesite {
constexpr Block toProtocol() {
return 6;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11724;
case Properties::Waterlogged::FALSE:
return 11725;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11726;
case Properties::Waterlogged::FALSE:
return 11727;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11728;
case Properties::Waterlogged::FALSE:
return 11729;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11350;
case Properties::Waterlogged::FALSE:
return 11351;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11352;
case Properties::Waterlogged::FALSE:
return 11353;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11354;
case Properties::Waterlogged::FALSE:
return 11355;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11356;
case Properties::Waterlogged::FALSE:
return 11357;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11358;
case Properties::Waterlogged::FALSE:
return 11359;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11360;
case Properties::Waterlogged::FALSE:
return 11361;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11362;
case Properties::Waterlogged::FALSE:
return 11363;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11364;
case Properties::Waterlogged::FALSE:
return 11365;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11366;
case Properties::Waterlogged::FALSE:
return 11367;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11368;
case Properties::Waterlogged::FALSE:
return 11369;
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
return 11370;
case Properties::Waterlogged::FALSE:
return 11371;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11372;
case Properties::Waterlogged::FALSE:
return 11373;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11374;
case Properties::Waterlogged::FALSE:
return 11375;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11376;
case Properties::Waterlogged::FALSE:
return 11377;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11378;
case Properties::Waterlogged::FALSE:
return 11379;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11380;
case Properties::Waterlogged::FALSE:
return 11381;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11382;
case Properties::Waterlogged::FALSE:
return 11383;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11384;
case Properties::Waterlogged::FALSE:
return 11385;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11386;
case Properties::Waterlogged::FALSE:
return 11387;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11388;
case Properties::Waterlogged::FALSE:
return 11389;
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
return 11390;
case Properties::Waterlogged::FALSE:
return 11391;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11392;
case Properties::Waterlogged::FALSE:
return 11393;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11394;
case Properties::Waterlogged::FALSE:
return 11395;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11396;
case Properties::Waterlogged::FALSE:
return 11397;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11398;
case Properties::Waterlogged::FALSE:
return 11399;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11400;
case Properties::Waterlogged::FALSE:
return 11401;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11402;
case Properties::Waterlogged::FALSE:
return 11403;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11404;
case Properties::Waterlogged::FALSE:
return 11405;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11406;
case Properties::Waterlogged::FALSE:
return 11407;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11408;
case Properties::Waterlogged::FALSE:
return 11409;
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
return 11410;
case Properties::Waterlogged::FALSE:
return 11411;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11412;
case Properties::Waterlogged::FALSE:
return 11413;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11414;
case Properties::Waterlogged::FALSE:
return 11415;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11416;
case Properties::Waterlogged::FALSE:
return 11417;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11418;
case Properties::Waterlogged::FALSE:
return 11419;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11420;
case Properties::Waterlogged::FALSE:
return 11421;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11422;
case Properties::Waterlogged::FALSE:
return 11423;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11424;
case Properties::Waterlogged::FALSE:
return 11425;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11426;
case Properties::Waterlogged::FALSE:
return 11427;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11428;
case Properties::Waterlogged::FALSE:
return 11429;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14340;
case Properties::West::LOW:
return 14341;
case Properties::West::TALL:
return 14342;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14343;
case Properties::West::LOW:
return 14344;
case Properties::West::TALL:
return 14345;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14346;
case Properties::West::LOW:
return 14347;
case Properties::West::TALL:
return 14348;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14349;
case Properties::West::LOW:
return 14350;
case Properties::West::TALL:
return 14351;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14352;
case Properties::West::LOW:
return 14353;
case Properties::West::TALL:
return 14354;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14355;
case Properties::West::LOW:
return 14356;
case Properties::West::TALL:
return 14357;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14358;
case Properties::West::LOW:
return 14359;
case Properties::West::TALL:
return 14360;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14361;
case Properties::West::LOW:
return 14362;
case Properties::West::TALL:
return 14363;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14364;
case Properties::West::LOW:
return 14365;
case Properties::West::TALL:
return 14366;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14367;
case Properties::West::LOW:
return 14368;
case Properties::West::TALL:
return 14369;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14370;
case Properties::West::LOW:
return 14371;
case Properties::West::TALL:
return 14372;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14373;
case Properties::West::LOW:
return 14374;
case Properties::West::TALL:
return 14375;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14376;
case Properties::West::LOW:
return 14377;
case Properties::West::TALL:
return 14378;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14379;
case Properties::West::LOW:
return 14380;
case Properties::West::TALL:
return 14381;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14382;
case Properties::West::LOW:
return 14383;
case Properties::West::TALL:
return 14384;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14385;
case Properties::West::LOW:
return 14386;
case Properties::West::TALL:
return 14387;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14388;
case Properties::West::LOW:
return 14389;
case Properties::West::TALL:
return 14390;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14391;
case Properties::West::LOW:
return 14392;
case Properties::West::TALL:
return 14393;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14394;
case Properties::West::LOW:
return 14395;
case Properties::West::TALL:
return 14396;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14397;
case Properties::West::LOW:
return 14398;
case Properties::West::TALL:
return 14399;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14400;
case Properties::West::LOW:
return 14401;
case Properties::West::TALL:
return 14402;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14403;
case Properties::West::LOW:
return 14404;
case Properties::West::TALL:
return 14405;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14406;
case Properties::West::LOW:
return 14407;
case Properties::West::TALL:
return 14408;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14409;
case Properties::West::LOW:
return 14410;
case Properties::West::TALL:
return 14411;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14412;
case Properties::West::LOW:
return 14413;
case Properties::West::TALL:
return 14414;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14415;
case Properties::West::LOW:
return 14416;
case Properties::West::TALL:
return 14417;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14418;
case Properties::West::LOW:
return 14419;
case Properties::West::TALL:
return 14420;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14421;
case Properties::West::LOW:
return 14422;
case Properties::West::TALL:
return 14423;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14424;
case Properties::West::LOW:
return 14425;
case Properties::West::TALL:
return 14426;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14427;
case Properties::West::LOW:
return 14428;
case Properties::West::TALL:
return 14429;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14430;
case Properties::West::LOW:
return 14431;
case Properties::West::TALL:
return 14432;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14433;
case Properties::West::LOW:
return 14434;
case Properties::West::TALL:
return 14435;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14436;
case Properties::West::LOW:
return 14437;
case Properties::West::TALL:
return 14438;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14439;
case Properties::West::LOW:
return 14440;
case Properties::West::TALL:
return 14441;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14442;
case Properties::West::LOW:
return 14443;
case Properties::West::TALL:
return 14444;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14445;
case Properties::West::LOW:
return 14446;
case Properties::West::TALL:
return 14447;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14448;
case Properties::West::LOW:
return 14449;
case Properties::West::TALL:
return 14450;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14451;
case Properties::West::LOW:
return 14452;
case Properties::West::TALL:
return 14453;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14454;
case Properties::West::LOW:
return 14455;
case Properties::West::TALL:
return 14456;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14457;
case Properties::West::LOW:
return 14458;
case Properties::West::TALL:
return 14459;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14460;
case Properties::West::LOW:
return 14461;
case Properties::West::TALL:
return 14462;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14463;
case Properties::West::LOW:
return 14464;
case Properties::West::TALL:
return 14465;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14466;
case Properties::West::LOW:
return 14467;
case Properties::West::TALL:
return 14468;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14469;
case Properties::West::LOW:
return 14470;
case Properties::West::TALL:
return 14471;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14472;
case Properties::West::LOW:
return 14473;
case Properties::West::TALL:
return 14474;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14475;
case Properties::West::LOW:
return 14476;
case Properties::West::TALL:
return 14477;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14478;
case Properties::West::LOW:
return 14479;
case Properties::West::TALL:
return 14480;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14481;
case Properties::West::LOW:
return 14482;
case Properties::West::TALL:
return 14483;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14484;
case Properties::West::LOW:
return 14485;
case Properties::West::TALL:
return 14486;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14487;
case Properties::West::LOW:
return 14488;
case Properties::West::TALL:
return 14489;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14490;
case Properties::West::LOW:
return 14491;
case Properties::West::TALL:
return 14492;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14493;
case Properties::West::LOW:
return 14494;
case Properties::West::TALL:
return 14495;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14496;
case Properties::West::LOW:
return 14497;
case Properties::West::TALL:
return 14498;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14499;
case Properties::West::LOW:
return 14500;
case Properties::West::TALL:
return 14501;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14502;
case Properties::West::LOW:
return 14503;
case Properties::West::TALL:
return 14504;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14505;
case Properties::West::LOW:
return 14506;
case Properties::West::TALL:
return 14507;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14508;
case Properties::West::LOW:
return 14509;
case Properties::West::TALL:
return 14510;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14511;
case Properties::West::LOW:
return 14512;
case Properties::West::TALL:
return 14513;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14514;
case Properties::West::LOW:
return 14515;
case Properties::West::TALL:
return 14516;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14517;
case Properties::West::LOW:
return 14518;
case Properties::West::TALL:
return 14519;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14520;
case Properties::West::LOW:
return 14521;
case Properties::West::TALL:
return 14522;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14523;
case Properties::West::LOW:
return 14524;
case Properties::West::TALL:
return 14525;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14526;
case Properties::West::LOW:
return 14527;
case Properties::West::TALL:
return 14528;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14529;
case Properties::West::LOW:
return 14530;
case Properties::West::TALL:
return 14531;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14532;
case Properties::West::LOW:
return 14533;
case Properties::West::TALL:
return 14534;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14535;
case Properties::West::LOW:
return 14536;
case Properties::West::TALL:
return 14537;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14538;
case Properties::West::LOW:
return 14539;
case Properties::West::TALL:
return 14540;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14541;
case Properties::West::LOW:
return 14542;
case Properties::West::TALL:
return 14543;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14544;
case Properties::West::LOW:
return 14545;
case Properties::West::TALL:
return 14546;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14547;
case Properties::West::LOW:
return 14548;
case Properties::West::TALL:
return 14549;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14550;
case Properties::West::LOW:
return 14551;
case Properties::West::TALL:
return 14552;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14553;
case Properties::West::LOW:
return 14554;
case Properties::West::TALL:
return 14555;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14556;
case Properties::West::LOW:
return 14557;
case Properties::West::TALL:
return 14558;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14559;
case Properties::West::LOW:
return 14560;
case Properties::West::TALL:
return 14561;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14562;
case Properties::West::LOW:
return 14563;
case Properties::West::TALL:
return 14564;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14565;
case Properties::West::LOW:
return 14566;
case Properties::West::TALL:
return 14567;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14568;
case Properties::West::LOW:
return 14569;
case Properties::West::TALL:
return 14570;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14571;
case Properties::West::LOW:
return 14572;
case Properties::West::TALL:
return 14573;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14574;
case Properties::West::LOW:
return 14575;
case Properties::West::TALL:
return 14576;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14577;
case Properties::West::LOW:
return 14578;
case Properties::West::TALL:
return 14579;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14580;
case Properties::West::LOW:
return 14581;
case Properties::West::TALL:
return 14582;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14583;
case Properties::West::LOW:
return 14584;
case Properties::West::TALL:
return 14585;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14586;
case Properties::West::LOW:
return 14587;
case Properties::West::TALL:
return 14588;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14589;
case Properties::West::LOW:
return 14590;
case Properties::West::TALL:
return 14591;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14592;
case Properties::West::LOW:
return 14593;
case Properties::West::TALL:
return 14594;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14595;
case Properties::West::LOW:
return 14596;
case Properties::West::TALL:
return 14597;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14598;
case Properties::West::LOW:
return 14599;
case Properties::West::TALL:
return 14600;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14601;
case Properties::West::LOW:
return 14602;
case Properties::West::TALL:
return 14603;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14604;
case Properties::West::LOW:
return 14605;
case Properties::West::TALL:
return 14606;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14607;
case Properties::West::LOW:
return 14608;
case Properties::West::TALL:
return 14609;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14610;
case Properties::West::LOW:
return 14611;
case Properties::West::TALL:
return 14612;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14613;
case Properties::West::LOW:
return 14614;
case Properties::West::TALL:
return 14615;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14616;
case Properties::West::LOW:
return 14617;
case Properties::West::TALL:
return 14618;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14619;
case Properties::West::LOW:
return 14620;
case Properties::West::TALL:
return 14621;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14622;
case Properties::West::LOW:
return 14623;
case Properties::West::TALL:
return 14624;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14625;
case Properties::West::LOW:
return 14626;
case Properties::West::TALL:
return 14627;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14628;
case Properties::West::LOW:
return 14629;
case Properties::West::TALL:
return 14630;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14631;
case Properties::West::LOW:
return 14632;
case Properties::West::TALL:
return 14633;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14634;
case Properties::West::LOW:
return 14635;
case Properties::West::TALL:
return 14636;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14637;
case Properties::West::LOW:
return 14638;
case Properties::West::TALL:
return 14639;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14640;
case Properties::West::LOW:
return 14641;
case Properties::West::TALL:
return 14642;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14643;
case Properties::West::LOW:
return 14644;
case Properties::West::TALL:
return 14645;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14646;
case Properties::West::LOW:
return 14647;
case Properties::West::TALL:
return 14648;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14649;
case Properties::West::LOW:
return 14650;
case Properties::West::TALL:
return 14651;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14652;
case Properties::West::LOW:
return 14653;
case Properties::West::TALL:
return 14654;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14655;
case Properties::West::LOW:
return 14656;
case Properties::West::TALL:
return 14657;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14658;
case Properties::West::LOW:
return 14659;
case Properties::West::TALL:
return 14660;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14661;
case Properties::West::LOW:
return 14662;
case Properties::West::TALL:
return 14663;
}
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 7227;
case Properties::Facing::SOUTH:
return 7228;
case Properties::Facing::WEST:
return 7229;
case Properties::Facing::EAST:
return 7230;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 5147;
case Properties::Facing::SOUTH:
return 5148;
case Properties::Facing::WEST:
return 5149;
case Properties::Facing::EAST:
return 5150;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 5143;
case Properties::Facing::SOUTH:
return 5144;
case Properties::Facing::WEST:
return 5145;
case Properties::Facing::EAST:
return 5146;
}
return 0;
}
}

namespace Azalea {
constexpr Block toProtocol() {
return 19714;
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 402;
case Properties::Waterlogged::FALSE:
return 403;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 404;
case Properties::Waterlogged::FALSE:
return 405;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 406;
case Properties::Waterlogged::FALSE:
return 407;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 408;
case Properties::Waterlogged::FALSE:
return 409;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 410;
case Properties::Waterlogged::FALSE:
return 411;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 412;
case Properties::Waterlogged::FALSE:
return 413;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 414;
case Properties::Waterlogged::FALSE:
return 415;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 416;
case Properties::Waterlogged::FALSE:
return 417;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 418;
case Properties::Waterlogged::FALSE:
return 419;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 420;
case Properties::Waterlogged::FALSE:
return 421;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 422;
case Properties::Waterlogged::FALSE:
return 423;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 424;
case Properties::Waterlogged::FALSE:
return 425;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 426;
case Properties::Waterlogged::FALSE:
return 427;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 428;
case Properties::Waterlogged::FALSE:
return 429;
}
}
}
return 0;
}
}

namespace AzureBluet {
constexpr Block toProtocol() {
return 1670;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age, Properties::Leaves leaves, Properties::Stage stage) {
switch (age) {
case Properties::Age::ZERO:
switch (leaves) {
case Properties::Leaves::NONE:
switch (stage) {
case Properties::Stage::ZERO:
return 10533;
case Properties::Stage::ONE:
return 10534;
}
case Properties::Leaves::SMALL:
switch (stage) {
case Properties::Stage::ZERO:
return 10535;
case Properties::Stage::ONE:
return 10536;
}
case Properties::Leaves::LARGE:
switch (stage) {
case Properties::Stage::ZERO:
return 10537;
case Properties::Stage::ONE:
return 10538;
}
}
case Properties::Age::ONE:
switch (leaves) {
case Properties::Leaves::NONE:
switch (stage) {
case Properties::Stage::ZERO:
return 10539;
case Properties::Stage::ONE:
return 10540;
}
case Properties::Leaves::SMALL:
switch (stage) {
case Properties::Stage::ZERO:
return 10541;
case Properties::Stage::ONE:
return 10542;
}
case Properties::Leaves::LARGE:
switch (stage) {
case Properties::Stage::ZERO:
return 10543;
case Properties::Stage::ONE:
return 10544;
}
}
}
return 0;
}
}

namespace BambooSapling {
constexpr Block toProtocol() {
return 10532;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Open open) {
switch (facing) {
case Properties::Facing::NORTH:
switch (open) {
case Properties::Open::TRUE:
return 15996;
case Properties::Open::FALSE:
return 15997;
}
case Properties::Facing::EAST:
switch (open) {
case Properties::Open::TRUE:
return 15998;
case Properties::Open::FALSE:
return 15999;
}
case Properties::Facing::SOUTH:
switch (open) {
case Properties::Open::TRUE:
return 16000;
case Properties::Open::FALSE:
return 16001;
}
case Properties::Facing::WEST:
switch (open) {
case Properties::Open::TRUE:
return 16002;
case Properties::Open::FALSE:
return 16003;
}
case Properties::Facing::UP:
switch (open) {
case Properties::Open::TRUE:
return 16004;
case Properties::Open::FALSE:
return 16005;
}
case Properties::Facing::DOWN:
switch (open) {
case Properties::Open::TRUE:
return 16006;
case Properties::Open::FALSE:
return 16007;
}
}
return 0;
}
}

namespace Barrier {
constexpr Block toProtocol() {
return 8245;
return 0;
}
}

namespace Basalt {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 4311;
case Properties::Axis::Y:
return 4312;
case Properties::Axis::Z:
return 4313;
}
return 0;
}
}

namespace Beacon {
constexpr Block toProtocol() {
return 6248;
return 0;
}
}

namespace Bedrock {
constexpr Block toProtocol() {
return 74;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Honey_level honey_level) {
switch (facing) {
case Properties::Facing::NORTH:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 16985;
case Properties::Honey_level::ONE:
return 16986;
case Properties::Honey_level::TWO:
return 16987;
case Properties::Honey_level::THREE:
return 16988;
case Properties::Honey_level::FOUR:
return 16989;
case Properties::Honey_level::FIVE:
return 16990;
}
case Properties::Facing::SOUTH:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 16991;
case Properties::Honey_level::ONE:
return 16992;
case Properties::Honey_level::TWO:
return 16993;
case Properties::Honey_level::THREE:
return 16994;
case Properties::Honey_level::FOUR:
return 16995;
case Properties::Honey_level::FIVE:
return 16996;
}
case Properties::Facing::WEST:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 16997;
case Properties::Honey_level::ONE:
return 16998;
case Properties::Honey_level::TWO:
return 16999;
case Properties::Honey_level::THREE:
return 17000;
case Properties::Honey_level::FOUR:
return 17001;
case Properties::Honey_level::FIVE:
return 17002;
}
case Properties::Facing::EAST:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 17003;
case Properties::Honey_level::ONE:
return 17004;
case Properties::Honey_level::TWO:
return 17005;
case Properties::Honey_level::THREE:
return 17006;
case Properties::Honey_level::FOUR:
return 17007;
case Properties::Honey_level::FIVE:
return 17008;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Honey_level honey_level) {
switch (facing) {
case Properties::Facing::NORTH:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 17009;
case Properties::Honey_level::ONE:
return 17010;
case Properties::Honey_level::TWO:
return 17011;
case Properties::Honey_level::THREE:
return 17012;
case Properties::Honey_level::FOUR:
return 17013;
case Properties::Honey_level::FIVE:
return 17014;
}
case Properties::Facing::SOUTH:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 17015;
case Properties::Honey_level::ONE:
return 17016;
case Properties::Honey_level::TWO:
return 17017;
case Properties::Honey_level::THREE:
return 17018;
case Properties::Honey_level::FOUR:
return 17019;
case Properties::Honey_level::FIVE:
return 17020;
}
case Properties::Facing::WEST:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 17021;
case Properties::Honey_level::ONE:
return 17022;
case Properties::Honey_level::TWO:
return 17023;
case Properties::Honey_level::THREE:
return 17024;
case Properties::Honey_level::FOUR:
return 17025;
case Properties::Honey_level::FIVE:
return 17026;
}
case Properties::Facing::EAST:
switch (honey_level) {
case Properties::Honey_level::ZERO:
return 17027;
case Properties::Honey_level::ONE:
return 17028;
case Properties::Honey_level::TWO:
return 17029;
case Properties::Honey_level::THREE:
return 17030;
case Properties::Honey_level::FOUR:
return 17031;
case Properties::Honey_level::FIVE:
return 17032;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 10100;
case Properties::Age::ONE:
return 10101;
case Properties::Age::TWO:
return 10102;
case Properties::Age::THREE:
return 10103;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Attachment attachment, Properties::Facing facing, Properties::Powered powered) {
switch (attachment) {
case Properties::Attachment::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16059;
case Properties::Powered::FALSE:
return 16060;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16061;
case Properties::Powered::FALSE:
return 16062;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16063;
case Properties::Powered::FALSE:
return 16064;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16065;
case Properties::Powered::FALSE:
return 16066;
}
}
case Properties::Attachment::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16067;
case Properties::Powered::FALSE:
return 16068;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16069;
case Properties::Powered::FALSE:
return 16070;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16071;
case Properties::Powered::FALSE:
return 16072;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16073;
case Properties::Powered::FALSE:
return 16074;
}
}
case Properties::Attachment::SINGLE_WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16075;
case Properties::Powered::FALSE:
return 16076;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16077;
case Properties::Powered::FALSE:
return 16078;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16079;
case Properties::Powered::FALSE:
return 16080;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16081;
case Properties::Powered::FALSE:
return 16082;
}
}
case Properties::Attachment::DOUBLE_WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16083;
case Properties::Powered::FALSE:
return 16084;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16085;
case Properties::Powered::FALSE:
return 16086;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16087;
case Properties::Powered::FALSE:
return 16088;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16089;
case Properties::Powered::FALSE:
return 16090;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Tilt tilt, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (tilt) {
case Properties::Tilt::NONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19718;
case Properties::Waterlogged::FALSE:
return 19719;
}
case Properties::Tilt::UNSTABLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19720;
case Properties::Waterlogged::FALSE:
return 19721;
}
case Properties::Tilt::PARTIAL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19722;
case Properties::Waterlogged::FALSE:
return 19723;
}
case Properties::Tilt::FULL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19724;
case Properties::Waterlogged::FALSE:
return 19725;
}
}
case Properties::Facing::SOUTH:
switch (tilt) {
case Properties::Tilt::NONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19726;
case Properties::Waterlogged::FALSE:
return 19727;
}
case Properties::Tilt::UNSTABLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19728;
case Properties::Waterlogged::FALSE:
return 19729;
}
case Properties::Tilt::PARTIAL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19730;
case Properties::Waterlogged::FALSE:
return 19731;
}
case Properties::Tilt::FULL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19732;
case Properties::Waterlogged::FALSE:
return 19733;
}
}
case Properties::Facing::WEST:
switch (tilt) {
case Properties::Tilt::NONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19734;
case Properties::Waterlogged::FALSE:
return 19735;
}
case Properties::Tilt::UNSTABLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19736;
case Properties::Waterlogged::FALSE:
return 19737;
}
case Properties::Tilt::PARTIAL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19738;
case Properties::Waterlogged::FALSE:
return 19739;
}
case Properties::Tilt::FULL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19740;
case Properties::Waterlogged::FALSE:
return 19741;
}
}
case Properties::Facing::EAST:
switch (tilt) {
case Properties::Tilt::NONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19742;
case Properties::Waterlogged::FALSE:
return 19743;
}
case Properties::Tilt::UNSTABLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19744;
case Properties::Waterlogged::FALSE:
return 19745;
}
case Properties::Tilt::PARTIAL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19746;
case Properties::Waterlogged::FALSE:
return 19747;
}
case Properties::Tilt::FULL:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19748;
case Properties::Waterlogged::FALSE:
return 19749;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19750;
case Properties::Waterlogged::FALSE:
return 19751;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19752;
case Properties::Waterlogged::FALSE:
return 19753;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19754;
case Properties::Waterlogged::FALSE:
return 19755;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19756;
case Properties::Waterlogged::FALSE:
return 19757;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 6987;
case Properties::Powered::FALSE:
return 6988;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 6989;
case Properties::Powered::FALSE:
return 6990;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 6991;
case Properties::Powered::FALSE:
return 6992;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 6993;
case Properties::Powered::FALSE:
return 6994;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 6995;
case Properties::Powered::FALSE:
return 6996;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 6997;
case Properties::Powered::FALSE:
return 6998;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 6999;
case Properties::Powered::FALSE:
return 7000;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7001;
case Properties::Powered::FALSE:
return 7002;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7003;
case Properties::Powered::FALSE:
return 7004;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7005;
case Properties::Powered::FALSE:
return 7006;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7007;
case Properties::Powered::FALSE:
return 7008;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7009;
case Properties::Powered::FALSE:
return 7010;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9619;
case Properties::Powered::FALSE:
return 9620;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9621;
case Properties::Powered::FALSE:
return 9622;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9623;
case Properties::Powered::FALSE:
return 9624;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9625;
case Properties::Powered::FALSE:
return 9626;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9627;
case Properties::Powered::FALSE:
return 9628;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9629;
case Properties::Powered::FALSE:
return 9630;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9631;
case Properties::Powered::FALSE:
return 9632;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9633;
case Properties::Powered::FALSE:
return 9634;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9635;
case Properties::Powered::FALSE:
return 9636;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9637;
case Properties::Powered::FALSE:
return 9638;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9639;
case Properties::Powered::FALSE:
return 9640;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9641;
case Properties::Powered::FALSE:
return 9642;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9643;
case Properties::Powered::FALSE:
return 9644;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9645;
case Properties::Powered::FALSE:
return 9646;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9647;
case Properties::Powered::FALSE:
return 9648;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9649;
case Properties::Powered::FALSE:
return 9650;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9651;
case Properties::Powered::FALSE:
return 9652;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9653;
case Properties::Powered::FALSE:
return 9654;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9655;
case Properties::Powered::FALSE:
return 9656;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9657;
case Properties::Powered::FALSE:
return 9658;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9659;
case Properties::Powered::FALSE:
return 9660;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9661;
case Properties::Powered::FALSE:
return 9662;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9663;
case Properties::Powered::FALSE:
return 9664;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9665;
case Properties::Powered::FALSE:
return 9666;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9667;
case Properties::Powered::FALSE:
return 9668;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9669;
case Properties::Powered::FALSE:
return 9670;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9671;
case Properties::Powered::FALSE:
return 9672;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9673;
case Properties::Powered::FALSE:
return 9674;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9675;
case Properties::Powered::FALSE:
return 9676;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9677;
case Properties::Powered::FALSE:
return 9678;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9679;
case Properties::Powered::FALSE:
return 9680;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9681;
case Properties::Powered::FALSE:
return 9682;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 9395;
case Properties::West::FALSE:
return 9396;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9397;
case Properties::West::FALSE:
return 9398;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9399;
case Properties::West::FALSE:
return 9400;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9401;
case Properties::West::FALSE:
return 9402;
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
return 9403;
case Properties::West::FALSE:
return 9404;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9405;
case Properties::West::FALSE:
return 9406;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9407;
case Properties::West::FALSE:
return 9408;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9409;
case Properties::West::FALSE:
return 9410;
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
return 9411;
case Properties::West::FALSE:
return 9412;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9413;
case Properties::West::FALSE:
return 9414;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9415;
case Properties::West::FALSE:
return 9416;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9417;
case Properties::West::FALSE:
return 9418;
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
return 9419;
case Properties::West::FALSE:
return 9420;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9421;
case Properties::West::FALSE:
return 9422;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9423;
case Properties::West::FALSE:
return 9424;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9425;
case Properties::West::FALSE:
return 9426;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9203;
case Properties::Powered::FALSE:
return 9204;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9205;
case Properties::Powered::FALSE:
return 9206;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9207;
case Properties::Powered::FALSE:
return 9208;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9209;
case Properties::Powered::FALSE:
return 9210;
}
}
}
case Properties::Facing::SOUTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9211;
case Properties::Powered::FALSE:
return 9212;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9213;
case Properties::Powered::FALSE:
return 9214;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9215;
case Properties::Powered::FALSE:
return 9216;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9217;
case Properties::Powered::FALSE:
return 9218;
}
}
}
case Properties::Facing::WEST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9219;
case Properties::Powered::FALSE:
return 9220;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9221;
case Properties::Powered::FALSE:
return 9222;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9223;
case Properties::Powered::FALSE:
return 9224;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9225;
case Properties::Powered::FALSE:
return 9226;
}
}
}
case Properties::Facing::EAST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9227;
case Properties::Powered::FALSE:
return 9228;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9229;
case Properties::Powered::FALSE:
return 9230;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9231;
case Properties::Powered::FALSE:
return 9232;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9233;
case Properties::Powered::FALSE:
return 9234;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 262;
case Properties::Waterlogged::FALSE:
return 263;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 264;
case Properties::Waterlogged::FALSE:
return 265;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 266;
case Properties::Waterlogged::FALSE:
return 267;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 268;
case Properties::Waterlogged::FALSE:
return 269;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 270;
case Properties::Waterlogged::FALSE:
return 271;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 272;
case Properties::Waterlogged::FALSE:
return 273;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 274;
case Properties::Waterlogged::FALSE:
return 275;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 276;
case Properties::Waterlogged::FALSE:
return 277;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 278;
case Properties::Waterlogged::FALSE:
return 279;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 280;
case Properties::Waterlogged::FALSE:
return 281;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 282;
case Properties::Waterlogged::FALSE:
return 283;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 284;
case Properties::Waterlogged::FALSE:
return 285;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 286;
case Properties::Waterlogged::FALSE:
return 287;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 288;
case Properties::Waterlogged::FALSE:
return 289;
}
}
}
return 0;
}
}

namespace BirchLog {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 123;
case Properties::Axis::Y:
return 124;
case Properties::Axis::Z:
return 125;
}
return 0;
}
}

namespace BirchPlanks {
constexpr Block toProtocol() {
return 17;
return 0;
}
}

namespace BirchPressurePlate {
namespace Properties {
enum class Powered {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Powered powered) {
switch (powered) {
case Properties::Powered::TRUE:
return 4182;
case Properties::Powered::FALSE:
return 4183;
}
return 0;
}
}

namespace BirchSapling {
namespace Properties {
enum class Stage {
ZERO,
ONE
};
}
constexpr Block toProtocol(Properties::Stage stage) {
switch (stage) {
case Properties::Stage::ZERO:
return 26;
case Properties::Stage::ONE:
return 27;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
switch (rotation) {
case Properties::Rotation::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3700;
case Properties::Waterlogged::FALSE:
return 3701;
}
case Properties::Rotation::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3702;
case Properties::Waterlogged::FALSE:
return 3703;
}
case Properties::Rotation::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3704;
case Properties::Waterlogged::FALSE:
return 3705;
}
case Properties::Rotation::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3706;
case Properties::Waterlogged::FALSE:
return 3707;
}
case Properties::Rotation::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3708;
case Properties::Waterlogged::FALSE:
return 3709;
}
case Properties::Rotation::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3710;
case Properties::Waterlogged::FALSE:
return 3711;
}
case Properties::Rotation::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3712;
case Properties::Waterlogged::FALSE:
return 3713;
}
case Properties::Rotation::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3714;
case Properties::Waterlogged::FALSE:
return 3715;
}
case Properties::Rotation::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3716;
case Properties::Waterlogged::FALSE:
return 3717;
}
case Properties::Rotation::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3718;
case Properties::Waterlogged::FALSE:
return 3719;
}
case Properties::Rotation::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3720;
case Properties::Waterlogged::FALSE:
return 3721;
}
case Properties::Rotation::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3722;
case Properties::Waterlogged::FALSE:
return 3723;
}
case Properties::Rotation::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3724;
case Properties::Waterlogged::FALSE:
return 3725;
}
case Properties::Rotation::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3726;
case Properties::Waterlogged::FALSE:
return 3727;
}
case Properties::Rotation::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3728;
case Properties::Waterlogged::FALSE:
return 3729;
}
case Properties::Rotation::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3730;
case Properties::Waterlogged::FALSE:
return 3731;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9053;
case Properties::Waterlogged::FALSE:
return 9054;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9055;
case Properties::Waterlogged::FALSE:
return 9056;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9057;
case Properties::Waterlogged::FALSE:
return 9058;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6076;
case Properties::Waterlogged::FALSE:
return 6077;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6078;
case Properties::Waterlogged::FALSE:
return 6079;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6080;
case Properties::Waterlogged::FALSE:
return 6081;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6082;
case Properties::Waterlogged::FALSE:
return 6083;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6084;
case Properties::Waterlogged::FALSE:
return 6085;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6086;
case Properties::Waterlogged::FALSE:
return 6087;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6088;
case Properties::Waterlogged::FALSE:
return 6089;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6090;
case Properties::Waterlogged::FALSE:
return 6091;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6092;
case Properties::Waterlogged::FALSE:
return 6093;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6094;
case Properties::Waterlogged::FALSE:
return 6095;
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
return 6096;
case Properties::Waterlogged::FALSE:
return 6097;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6098;
case Properties::Waterlogged::FALSE:
return 6099;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6100;
case Properties::Waterlogged::FALSE:
return 6101;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6102;
case Properties::Waterlogged::FALSE:
return 6103;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6104;
case Properties::Waterlogged::FALSE:
return 6105;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6106;
case Properties::Waterlogged::FALSE:
return 6107;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6108;
case Properties::Waterlogged::FALSE:
return 6109;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6110;
case Properties::Waterlogged::FALSE:
return 6111;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6112;
case Properties::Waterlogged::FALSE:
return 6113;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6114;
case Properties::Waterlogged::FALSE:
return 6115;
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
return 6116;
case Properties::Waterlogged::FALSE:
return 6117;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6118;
case Properties::Waterlogged::FALSE:
return 6119;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6120;
case Properties::Waterlogged::FALSE:
return 6121;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6122;
case Properties::Waterlogged::FALSE:
return 6123;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6124;
case Properties::Waterlogged::FALSE:
return 6125;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6126;
case Properties::Waterlogged::FALSE:
return 6127;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6128;
case Properties::Waterlogged::FALSE:
return 6129;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6130;
case Properties::Waterlogged::FALSE:
return 6131;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6132;
case Properties::Waterlogged::FALSE:
return 6133;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6134;
case Properties::Waterlogged::FALSE:
return 6135;
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
return 6136;
case Properties::Waterlogged::FALSE:
return 6137;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6138;
case Properties::Waterlogged::FALSE:
return 6139;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6140;
case Properties::Waterlogged::FALSE:
return 6141;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6142;
case Properties::Waterlogged::FALSE:
return 6143;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6144;
case Properties::Waterlogged::FALSE:
return 6145;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6146;
case Properties::Waterlogged::FALSE:
return 6147;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6148;
case Properties::Waterlogged::FALSE:
return 6149;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6150;
case Properties::Waterlogged::FALSE:
return 6151;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6152;
case Properties::Waterlogged::FALSE:
return 6153;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6154;
case Properties::Waterlogged::FALSE:
return 6155;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4548;
case Properties::Waterlogged::FALSE:
return 4549;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4550;
case Properties::Waterlogged::FALSE:
return 4551;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4552;
case Properties::Waterlogged::FALSE:
return 4553;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4554;
case Properties::Waterlogged::FALSE:
return 4555;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4556;
case Properties::Waterlogged::FALSE:
return 4557;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4558;
case Properties::Waterlogged::FALSE:
return 4559;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4560;
case Properties::Waterlogged::FALSE:
return 4561;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4562;
case Properties::Waterlogged::FALSE:
return 4563;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4564;
case Properties::Waterlogged::FALSE:
return 4565;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4566;
case Properties::Waterlogged::FALSE:
return 4567;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4568;
case Properties::Waterlogged::FALSE:
return 4569;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4570;
case Properties::Waterlogged::FALSE:
return 4571;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4572;
case Properties::Waterlogged::FALSE:
return 4573;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4574;
case Properties::Waterlogged::FALSE:
return 4575;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4576;
case Properties::Waterlogged::FALSE:
return 4577;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4578;
case Properties::Waterlogged::FALSE:
return 4579;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4580;
case Properties::Waterlogged::FALSE:
return 4581;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4582;
case Properties::Waterlogged::FALSE:
return 4583;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4584;
case Properties::Waterlogged::FALSE:
return 4585;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4586;
case Properties::Waterlogged::FALSE:
return 4587;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4588;
case Properties::Waterlogged::FALSE:
return 4589;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4590;
case Properties::Waterlogged::FALSE:
return 4591;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4592;
case Properties::Waterlogged::FALSE:
return 4593;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4594;
case Properties::Waterlogged::FALSE:
return 4595;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4596;
case Properties::Waterlogged::FALSE:
return 4597;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4598;
case Properties::Waterlogged::FALSE:
return 4599;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4600;
case Properties::Waterlogged::FALSE:
return 4601;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4602;
case Properties::Waterlogged::FALSE:
return 4603;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4604;
case Properties::Waterlogged::FALSE:
return 4605;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4606;
case Properties::Waterlogged::FALSE:
return 4607;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4608;
case Properties::Waterlogged::FALSE:
return 4609;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4610;
case Properties::Waterlogged::FALSE:
return 4611;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4048;
case Properties::Waterlogged::FALSE:
return 4049;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4050;
case Properties::Waterlogged::FALSE:
return 4051;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4052;
case Properties::Waterlogged::FALSE:
return 4053;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4054;
case Properties::Waterlogged::FALSE:
return 4055;
}
}
return 0;
}
}

namespace BirchWood {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 170;
case Properties::Axis::Y:
return 171;
case Properties::Axis::Z:
return 172;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8878;
case Properties::Rotation::ONE:
return 8879;
case Properties::Rotation::TWO:
return 8880;
case Properties::Rotation::THREE:
return 8881;
case Properties::Rotation::FOUR:
return 8882;
case Properties::Rotation::FIVE:
return 8883;
case Properties::Rotation::SIX:
return 8884;
case Properties::Rotation::SEVEN:
return 8885;
case Properties::Rotation::EIGHT:
return 8886;
case Properties::Rotation::NINE:
return 8887;
case Properties::Rotation::TEN:
return 8888;
case Properties::Rotation::ELEVEN:
return 8889;
case Properties::Rotation::TWELVE:
return 8890;
case Properties::Rotation::THIRTEEN:
return 8891;
case Properties::Rotation::FOURTEEN:
return 8892;
case Properties::Rotation::FIFTEEN:
return 8893;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1519;
case Properties::Part::FOOT:
return 1520;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1521;
case Properties::Part::FOOT:
return 1522;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1523;
case Properties::Part::FOOT:
return 1524;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1525;
case Properties::Part::FOOT:
return 1526;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1527;
case Properties::Part::FOOT:
return 1528;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1529;
case Properties::Part::FOOT:
return 1530;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1531;
case Properties::Part::FOOT:
return 1532;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1533;
case Properties::Part::FOOT:
return 1534;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18569;
case Properties::Waterlogged::FALSE:
return 18570;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18571;
case Properties::Waterlogged::FALSE:
return 18572;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18573;
case Properties::Waterlogged::FALSE:
return 18574;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18575;
case Properties::Waterlogged::FALSE:
return 18576;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18577;
case Properties::Waterlogged::FALSE:
return 18578;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18579;
case Properties::Waterlogged::FALSE:
return 18580;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18581;
case Properties::Waterlogged::FALSE:
return 18582;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18583;
case Properties::Waterlogged::FALSE:
return 18584;
}
}
}
return 0;
}
}

namespace BlackCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18617;
case Properties::Lit::FALSE:
return 18618;
}
return 0;
}
}

namespace BlackCarpet {
constexpr Block toProtocol() {
return 8622;
return 0;
}
}

namespace BlackConcrete {
constexpr Block toProtocol() {
return 10334;
return 0;
}
}

namespace BlackConcretePowder {
constexpr Block toProtocol() {
return 10350;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10315;
case Properties::Facing::SOUTH:
return 10316;
case Properties::Facing::WEST:
return 10317;
case Properties::Facing::EAST:
return 10318;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10249;
case Properties::Facing::EAST:
return 10250;
case Properties::Facing::SOUTH:
return 10251;
case Properties::Facing::WEST:
return 10252;
case Properties::Facing::UP:
return 10253;
case Properties::Facing::DOWN:
return 10254;
}
return 0;
}
}

namespace BlackStainedGlass {
constexpr Block toProtocol() {
return 4419;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7972;
case Properties::West::FALSE:
return 7973;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7974;
case Properties::West::FALSE:
return 7975;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7976;
case Properties::West::FALSE:
return 7977;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7978;
case Properties::West::FALSE:
return 7979;
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
return 7980;
case Properties::West::FALSE:
return 7981;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7982;
case Properties::West::FALSE:
return 7983;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7984;
case Properties::West::FALSE:
return 7985;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7986;
case Properties::West::FALSE:
return 7987;
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
return 7988;
case Properties::West::FALSE:
return 7989;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7990;
case Properties::West::FALSE:
return 7991;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7992;
case Properties::West::FALSE:
return 7993;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7994;
case Properties::West::FALSE:
return 7995;
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
return 7996;
case Properties::West::FALSE:
return 7997;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7998;
case Properties::West::FALSE:
return 7999;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 8000;
case Properties::West::FALSE:
return 8001;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 8002;
case Properties::West::FALSE:
return 8003;
}
}
}
}
}
return 0;
}
}

namespace BlackTerracotta {
constexpr Block toProtocol() {
return 7491;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8954;
case Properties::Facing::SOUTH:
return 8955;
case Properties::Facing::WEST:
return 8956;
case Properties::Facing::EAST:
return 8957;
}
return 0;
}
}

namespace BlackWool {
constexpr Block toProtocol() {
return 1653;
return 0;
}
}

namespace Blackstone {
constexpr Block toProtocol() {
return 17048;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17453;
case Properties::Waterlogged::FALSE:
return 17454;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17455;
case Properties::Waterlogged::FALSE:
return 17456;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17457;
case Properties::Waterlogged::FALSE:
return 17458;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17049;
case Properties::Waterlogged::FALSE:
return 17050;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17051;
case Properties::Waterlogged::FALSE:
return 17052;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17053;
case Properties::Waterlogged::FALSE:
return 17054;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17055;
case Properties::Waterlogged::FALSE:
return 17056;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17057;
case Properties::Waterlogged::FALSE:
return 17058;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17059;
case Properties::Waterlogged::FALSE:
return 17060;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17061;
case Properties::Waterlogged::FALSE:
return 17062;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17063;
case Properties::Waterlogged::FALSE:
return 17064;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17065;
case Properties::Waterlogged::FALSE:
return 17066;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17067;
case Properties::Waterlogged::FALSE:
return 17068;
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
return 17069;
case Properties::Waterlogged::FALSE:
return 17070;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17071;
case Properties::Waterlogged::FALSE:
return 17072;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17073;
case Properties::Waterlogged::FALSE:
return 17074;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17075;
case Properties::Waterlogged::FALSE:
return 17076;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17077;
case Properties::Waterlogged::FALSE:
return 17078;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17079;
case Properties::Waterlogged::FALSE:
return 17080;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17081;
case Properties::Waterlogged::FALSE:
return 17082;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17083;
case Properties::Waterlogged::FALSE:
return 17084;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17085;
case Properties::Waterlogged::FALSE:
return 17086;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17087;
case Properties::Waterlogged::FALSE:
return 17088;
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
return 17089;
case Properties::Waterlogged::FALSE:
return 17090;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17091;
case Properties::Waterlogged::FALSE:
return 17092;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17093;
case Properties::Waterlogged::FALSE:
return 17094;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17095;
case Properties::Waterlogged::FALSE:
return 17096;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17097;
case Properties::Waterlogged::FALSE:
return 17098;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17099;
case Properties::Waterlogged::FALSE:
return 17100;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17101;
case Properties::Waterlogged::FALSE:
return 17102;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17103;
case Properties::Waterlogged::FALSE:
return 17104;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17105;
case Properties::Waterlogged::FALSE:
return 17106;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17107;
case Properties::Waterlogged::FALSE:
return 17108;
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
return 17109;
case Properties::Waterlogged::FALSE:
return 17110;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17111;
case Properties::Waterlogged::FALSE:
return 17112;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17113;
case Properties::Waterlogged::FALSE:
return 17114;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17115;
case Properties::Waterlogged::FALSE:
return 17116;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17117;
case Properties::Waterlogged::FALSE:
return 17118;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17119;
case Properties::Waterlogged::FALSE:
return 17120;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17121;
case Properties::Waterlogged::FALSE:
return 17122;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17123;
case Properties::Waterlogged::FALSE:
return 17124;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17125;
case Properties::Waterlogged::FALSE:
return 17126;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 17127;
case Properties::Waterlogged::FALSE:
return 17128;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17129;
case Properties::West::LOW:
return 17130;
case Properties::West::TALL:
return 17131;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17132;
case Properties::West::LOW:
return 17133;
case Properties::West::TALL:
return 17134;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17135;
case Properties::West::LOW:
return 17136;
case Properties::West::TALL:
return 17137;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17138;
case Properties::West::LOW:
return 17139;
case Properties::West::TALL:
return 17140;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17141;
case Properties::West::LOW:
return 17142;
case Properties::West::TALL:
return 17143;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17144;
case Properties::West::LOW:
return 17145;
case Properties::West::TALL:
return 17146;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17147;
case Properties::West::LOW:
return 17148;
case Properties::West::TALL:
return 17149;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17150;
case Properties::West::LOW:
return 17151;
case Properties::West::TALL:
return 17152;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17153;
case Properties::West::LOW:
return 17154;
case Properties::West::TALL:
return 17155;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17156;
case Properties::West::LOW:
return 17157;
case Properties::West::TALL:
return 17158;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17159;
case Properties::West::LOW:
return 17160;
case Properties::West::TALL:
return 17161;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17162;
case Properties::West::LOW:
return 17163;
case Properties::West::TALL:
return 17164;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17165;
case Properties::West::LOW:
return 17166;
case Properties::West::TALL:
return 17167;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17168;
case Properties::West::LOW:
return 17169;
case Properties::West::TALL:
return 17170;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17171;
case Properties::West::LOW:
return 17172;
case Properties::West::TALL:
return 17173;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17174;
case Properties::West::LOW:
return 17175;
case Properties::West::TALL:
return 17176;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17177;
case Properties::West::LOW:
return 17178;
case Properties::West::TALL:
return 17179;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17180;
case Properties::West::LOW:
return 17181;
case Properties::West::TALL:
return 17182;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17183;
case Properties::West::LOW:
return 17184;
case Properties::West::TALL:
return 17185;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17186;
case Properties::West::LOW:
return 17187;
case Properties::West::TALL:
return 17188;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17189;
case Properties::West::LOW:
return 17190;
case Properties::West::TALL:
return 17191;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17192;
case Properties::West::LOW:
return 17193;
case Properties::West::TALL:
return 17194;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17195;
case Properties::West::LOW:
return 17196;
case Properties::West::TALL:
return 17197;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17198;
case Properties::West::LOW:
return 17199;
case Properties::West::TALL:
return 17200;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17201;
case Properties::West::LOW:
return 17202;
case Properties::West::TALL:
return 17203;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17204;
case Properties::West::LOW:
return 17205;
case Properties::West::TALL:
return 17206;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17207;
case Properties::West::LOW:
return 17208;
case Properties::West::TALL:
return 17209;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17210;
case Properties::West::LOW:
return 17211;
case Properties::West::TALL:
return 17212;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17213;
case Properties::West::LOW:
return 17214;
case Properties::West::TALL:
return 17215;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17216;
case Properties::West::LOW:
return 17217;
case Properties::West::TALL:
return 17218;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17219;
case Properties::West::LOW:
return 17220;
case Properties::West::TALL:
return 17221;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17222;
case Properties::West::LOW:
return 17223;
case Properties::West::TALL:
return 17224;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17225;
case Properties::West::LOW:
return 17226;
case Properties::West::TALL:
return 17227;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17228;
case Properties::West::LOW:
return 17229;
case Properties::West::TALL:
return 17230;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17231;
case Properties::West::LOW:
return 17232;
case Properties::West::TALL:
return 17233;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17234;
case Properties::West::LOW:
return 17235;
case Properties::West::TALL:
return 17236;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17237;
case Properties::West::LOW:
return 17238;
case Properties::West::TALL:
return 17239;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17240;
case Properties::West::LOW:
return 17241;
case Properties::West::TALL:
return 17242;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17243;
case Properties::West::LOW:
return 17244;
case Properties::West::TALL:
return 17245;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17246;
case Properties::West::LOW:
return 17247;
case Properties::West::TALL:
return 17248;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17249;
case Properties::West::LOW:
return 17250;
case Properties::West::TALL:
return 17251;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17252;
case Properties::West::LOW:
return 17253;
case Properties::West::TALL:
return 17254;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17255;
case Properties::West::LOW:
return 17256;
case Properties::West::TALL:
return 17257;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17258;
case Properties::West::LOW:
return 17259;
case Properties::West::TALL:
return 17260;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17261;
case Properties::West::LOW:
return 17262;
case Properties::West::TALL:
return 17263;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17264;
case Properties::West::LOW:
return 17265;
case Properties::West::TALL:
return 17266;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17267;
case Properties::West::LOW:
return 17268;
case Properties::West::TALL:
return 17269;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17270;
case Properties::West::LOW:
return 17271;
case Properties::West::TALL:
return 17272;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17273;
case Properties::West::LOW:
return 17274;
case Properties::West::TALL:
return 17275;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17276;
case Properties::West::LOW:
return 17277;
case Properties::West::TALL:
return 17278;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17279;
case Properties::West::LOW:
return 17280;
case Properties::West::TALL:
return 17281;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17282;
case Properties::West::LOW:
return 17283;
case Properties::West::TALL:
return 17284;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17285;
case Properties::West::LOW:
return 17286;
case Properties::West::TALL:
return 17287;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17288;
case Properties::West::LOW:
return 17289;
case Properties::West::TALL:
return 17290;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17291;
case Properties::West::LOW:
return 17292;
case Properties::West::TALL:
return 17293;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17294;
case Properties::West::LOW:
return 17295;
case Properties::West::TALL:
return 17296;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17297;
case Properties::West::LOW:
return 17298;
case Properties::West::TALL:
return 17299;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17300;
case Properties::West::LOW:
return 17301;
case Properties::West::TALL:
return 17302;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17303;
case Properties::West::LOW:
return 17304;
case Properties::West::TALL:
return 17305;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17306;
case Properties::West::LOW:
return 17307;
case Properties::West::TALL:
return 17308;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17309;
case Properties::West::LOW:
return 17310;
case Properties::West::TALL:
return 17311;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17312;
case Properties::West::LOW:
return 17313;
case Properties::West::TALL:
return 17314;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17315;
case Properties::West::LOW:
return 17316;
case Properties::West::TALL:
return 17317;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17318;
case Properties::West::LOW:
return 17319;
case Properties::West::TALL:
return 17320;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17321;
case Properties::West::LOW:
return 17322;
case Properties::West::TALL:
return 17323;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17324;
case Properties::West::LOW:
return 17325;
case Properties::West::TALL:
return 17326;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17327;
case Properties::West::LOW:
return 17328;
case Properties::West::TALL:
return 17329;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17330;
case Properties::West::LOW:
return 17331;
case Properties::West::TALL:
return 17332;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17333;
case Properties::West::LOW:
return 17334;
case Properties::West::TALL:
return 17335;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17336;
case Properties::West::LOW:
return 17337;
case Properties::West::TALL:
return 17338;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17339;
case Properties::West::LOW:
return 17340;
case Properties::West::TALL:
return 17341;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17342;
case Properties::West::LOW:
return 17343;
case Properties::West::TALL:
return 17344;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17345;
case Properties::West::LOW:
return 17346;
case Properties::West::TALL:
return 17347;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17348;
case Properties::West::LOW:
return 17349;
case Properties::West::TALL:
return 17350;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17351;
case Properties::West::LOW:
return 17352;
case Properties::West::TALL:
return 17353;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17354;
case Properties::West::LOW:
return 17355;
case Properties::West::TALL:
return 17356;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17357;
case Properties::West::LOW:
return 17358;
case Properties::West::TALL:
return 17359;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17360;
case Properties::West::LOW:
return 17361;
case Properties::West::TALL:
return 17362;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17363;
case Properties::West::LOW:
return 17364;
case Properties::West::TALL:
return 17365;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17366;
case Properties::West::LOW:
return 17367;
case Properties::West::TALL:
return 17368;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17369;
case Properties::West::LOW:
return 17370;
case Properties::West::TALL:
return 17371;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17372;
case Properties::West::LOW:
return 17373;
case Properties::West::TALL:
return 17374;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17375;
case Properties::West::LOW:
return 17376;
case Properties::West::TALL:
return 17377;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17378;
case Properties::West::LOW:
return 17379;
case Properties::West::TALL:
return 17380;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17381;
case Properties::West::LOW:
return 17382;
case Properties::West::TALL:
return 17383;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17384;
case Properties::West::LOW:
return 17385;
case Properties::West::TALL:
return 17386;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17387;
case Properties::West::LOW:
return 17388;
case Properties::West::TALL:
return 17389;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17390;
case Properties::West::LOW:
return 17391;
case Properties::West::TALL:
return 17392;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17393;
case Properties::West::LOW:
return 17394;
case Properties::West::TALL:
return 17395;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17396;
case Properties::West::LOW:
return 17397;
case Properties::West::TALL:
return 17398;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17399;
case Properties::West::LOW:
return 17400;
case Properties::West::TALL:
return 17401;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17402;
case Properties::West::LOW:
return 17403;
case Properties::West::TALL:
return 17404;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17405;
case Properties::West::LOW:
return 17406;
case Properties::West::TALL:
return 17407;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17408;
case Properties::West::LOW:
return 17409;
case Properties::West::TALL:
return 17410;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17411;
case Properties::West::LOW:
return 17412;
case Properties::West::TALL:
return 17413;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17414;
case Properties::West::LOW:
return 17415;
case Properties::West::TALL:
return 17416;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17417;
case Properties::West::LOW:
return 17418;
case Properties::West::TALL:
return 17419;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17420;
case Properties::West::LOW:
return 17421;
case Properties::West::TALL:
return 17422;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17423;
case Properties::West::LOW:
return 17424;
case Properties::West::TALL:
return 17425;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17426;
case Properties::West::LOW:
return 17427;
case Properties::West::TALL:
return 17428;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17429;
case Properties::West::LOW:
return 17430;
case Properties::West::TALL:
return 17431;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17432;
case Properties::West::LOW:
return 17433;
case Properties::West::TALL:
return 17434;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17435;
case Properties::West::LOW:
return 17436;
case Properties::West::TALL:
return 17437;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17438;
case Properties::West::LOW:
return 17439;
case Properties::West::TALL:
return 17440;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17441;
case Properties::West::LOW:
return 17442;
case Properties::West::TALL:
return 17443;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17444;
case Properties::West::LOW:
return 17445;
case Properties::West::TALL:
return 17446;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 17447;
case Properties::West::LOW:
return 17448;
case Properties::West::TALL:
return 17449;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 17450;
case Properties::West::LOW:
return 17451;
case Properties::West::TALL:
return 17452;
}
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Lit lit) {
switch (facing) {
case Properties::Facing::NORTH:
switch (lit) {
case Properties::Lit::TRUE:
return 16016;
case Properties::Lit::FALSE:
return 16017;
}
case Properties::Facing::SOUTH:
switch (lit) {
case Properties::Lit::TRUE:
return 16018;
case Properties::Lit::FALSE:
return 16019;
}
case Properties::Facing::WEST:
switch (lit) {
case Properties::Lit::TRUE:
return 16020;
case Properties::Lit::FALSE:
return 16021;
}
case Properties::Facing::EAST:
switch (lit) {
case Properties::Lit::TRUE:
return 16022;
case Properties::Lit::FALSE:
return 16023;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8814;
case Properties::Rotation::ONE:
return 8815;
case Properties::Rotation::TWO:
return 8816;
case Properties::Rotation::THREE:
return 8817;
case Properties::Rotation::FOUR:
return 8818;
case Properties::Rotation::FIVE:
return 8819;
case Properties::Rotation::SIX:
return 8820;
case Properties::Rotation::SEVEN:
return 8821;
case Properties::Rotation::EIGHT:
return 8822;
case Properties::Rotation::NINE:
return 8823;
case Properties::Rotation::TEN:
return 8824;
case Properties::Rotation::ELEVEN:
return 8825;
case Properties::Rotation::TWELVE:
return 8826;
case Properties::Rotation::THIRTEEN:
return 8827;
case Properties::Rotation::FOURTEEN:
return 8828;
case Properties::Rotation::FIFTEEN:
return 8829;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1455;
case Properties::Part::FOOT:
return 1456;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1457;
case Properties::Part::FOOT:
return 1458;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1459;
case Properties::Part::FOOT:
return 1460;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1461;
case Properties::Part::FOOT:
return 1462;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1463;
case Properties::Part::FOOT:
return 1464;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1465;
case Properties::Part::FOOT:
return 1466;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1467;
case Properties::Part::FOOT:
return 1468;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1469;
case Properties::Part::FOOT:
return 1470;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18505;
case Properties::Waterlogged::FALSE:
return 18506;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18507;
case Properties::Waterlogged::FALSE:
return 18508;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18509;
case Properties::Waterlogged::FALSE:
return 18510;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18511;
case Properties::Waterlogged::FALSE:
return 18512;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18513;
case Properties::Waterlogged::FALSE:
return 18514;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18515;
case Properties::Waterlogged::FALSE:
return 18516;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18517;
case Properties::Waterlogged::FALSE:
return 18518;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18519;
case Properties::Waterlogged::FALSE:
return 18520;
}
}
}
return 0;
}
}

namespace BlueCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18609;
case Properties::Lit::FALSE:
return 18610;
}
return 0;
}
}

namespace BlueCarpet {
constexpr Block toProtocol() {
return 8618;
return 0;
}
}

namespace BlueConcrete {
constexpr Block toProtocol() {
return 10330;
return 0;
}
}

namespace BlueConcretePowder {
constexpr Block toProtocol() {
return 10346;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10299;
case Properties::Facing::SOUTH:
return 10300;
case Properties::Facing::WEST:
return 10301;
case Properties::Facing::EAST:
return 10302;
}
return 0;
}
}

namespace BlueIce {
constexpr Block toProtocol() {
return 10529;
return 0;
}
}

namespace BlueOrchid {
constexpr Block toProtocol() {
return 1668;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10225;
case Properties::Facing::EAST:
return 10226;
case Properties::Facing::SOUTH:
return 10227;
case Properties::Facing::WEST:
return 10228;
case Properties::Facing::UP:
return 10229;
case Properties::Facing::DOWN:
return 10230;
}
return 0;
}
}

namespace BlueStainedGlass {
constexpr Block toProtocol() {
return 4415;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7844;
case Properties::West::FALSE:
return 7845;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7846;
case Properties::West::FALSE:
return 7847;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7848;
case Properties::West::FALSE:
return 7849;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7850;
case Properties::West::FALSE:
return 7851;
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
return 7852;
case Properties::West::FALSE:
return 7853;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7854;
case Properties::West::FALSE:
return 7855;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7856;
case Properties::West::FALSE:
return 7857;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7858;
case Properties::West::FALSE:
return 7859;
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
return 7860;
case Properties::West::FALSE:
return 7861;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7862;
case Properties::West::FALSE:
return 7863;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7864;
case Properties::West::FALSE:
return 7865;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7866;
case Properties::West::FALSE:
return 7867;
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
return 7868;
case Properties::West::FALSE:
return 7869;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7870;
case Properties::West::FALSE:
return 7871;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7872;
case Properties::West::FALSE:
return 7873;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7874;
case Properties::West::FALSE:
return 7875;
}
}
}
}
}
return 0;
}
}

namespace BlueTerracotta {
constexpr Block toProtocol() {
return 7487;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8938;
case Properties::Facing::SOUTH:
return 8939;
case Properties::Facing::WEST:
return 8940;
case Properties::Facing::EAST:
return 8941;
}
return 0;
}
}

namespace BlueWool {
constexpr Block toProtocol() {
return 1649;
return 0;
}
}

namespace BoneBlock {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 10137;
case Properties::Axis::Y:
return 10138;
case Properties::Axis::Z:
return 10139;
}
return 0;
}
}

namespace Bookshelf {
constexpr Block toProtocol() {
return 1686;
return 0;
}
}

namespace BrainCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10413;
case Properties::Waterlogged::FALSE:
return 10414;
}
return 0;
}
}

namespace BrainCoralBlock {
constexpr Block toProtocol() {
return 10397;
return 0;
}
}

namespace BrainCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10433;
case Properties::Waterlogged::FALSE:
return 10434;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10489;
case Properties::Waterlogged::FALSE:
return 10490;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10491;
case Properties::Waterlogged::FALSE:
return 10492;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10493;
case Properties::Waterlogged::FALSE:
return 10494;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10495;
case Properties::Waterlogged::FALSE:
return 10496;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Has_bottle_0 has_bottle_0, Properties::Has_bottle_1 has_bottle_1, Properties::Has_bottle_2 has_bottle_2) {
switch (has_bottle_0) {
case Properties::Has_bottle_0::TRUE:
switch (has_bottle_1) {
case Properties::Has_bottle_1::TRUE:
switch (has_bottle_2) {
case Properties::Has_bottle_2::TRUE:
return 5720;
case Properties::Has_bottle_2::FALSE:
return 5721;
}
case Properties::Has_bottle_1::FALSE:
switch (has_bottle_2) {
case Properties::Has_bottle_2::TRUE:
return 5722;
case Properties::Has_bottle_2::FALSE:
return 5723;
}
}
case Properties::Has_bottle_0::FALSE:
switch (has_bottle_1) {
case Properties::Has_bottle_1::TRUE:
switch (has_bottle_2) {
case Properties::Has_bottle_2::TRUE:
return 5724;
case Properties::Has_bottle_2::FALSE:
return 5725;
}
case Properties::Has_bottle_1::FALSE:
switch (has_bottle_2) {
case Properties::Has_bottle_2::TRUE:
return 5726;
case Properties::Has_bottle_2::FALSE:
return 5727;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9119;
case Properties::Waterlogged::FALSE:
return 9120;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9121;
case Properties::Waterlogged::FALSE:
return 9122;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9123;
case Properties::Waterlogged::FALSE:
return 9124;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5359;
case Properties::Waterlogged::FALSE:
return 5360;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5361;
case Properties::Waterlogged::FALSE:
return 5362;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5363;
case Properties::Waterlogged::FALSE:
return 5364;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5365;
case Properties::Waterlogged::FALSE:
return 5366;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5367;
case Properties::Waterlogged::FALSE:
return 5368;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5369;
case Properties::Waterlogged::FALSE:
return 5370;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5371;
case Properties::Waterlogged::FALSE:
return 5372;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5373;
case Properties::Waterlogged::FALSE:
return 5374;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5375;
case Properties::Waterlogged::FALSE:
return 5376;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5377;
case Properties::Waterlogged::FALSE:
return 5378;
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
return 5379;
case Properties::Waterlogged::FALSE:
return 5380;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5381;
case Properties::Waterlogged::FALSE:
return 5382;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5383;
case Properties::Waterlogged::FALSE:
return 5384;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5385;
case Properties::Waterlogged::FALSE:
return 5386;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5387;
case Properties::Waterlogged::FALSE:
return 5388;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5389;
case Properties::Waterlogged::FALSE:
return 5390;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5391;
case Properties::Waterlogged::FALSE:
return 5392;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5393;
case Properties::Waterlogged::FALSE:
return 5394;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5395;
case Properties::Waterlogged::FALSE:
return 5396;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5397;
case Properties::Waterlogged::FALSE:
return 5398;
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
return 5399;
case Properties::Waterlogged::FALSE:
return 5400;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5401;
case Properties::Waterlogged::FALSE:
return 5402;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5403;
case Properties::Waterlogged::FALSE:
return 5404;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5405;
case Properties::Waterlogged::FALSE:
return 5406;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5407;
case Properties::Waterlogged::FALSE:
return 5408;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5409;
case Properties::Waterlogged::FALSE:
return 5410;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5411;
case Properties::Waterlogged::FALSE:
return 5412;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5413;
case Properties::Waterlogged::FALSE:
return 5414;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5415;
case Properties::Waterlogged::FALSE:
return 5416;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5417;
case Properties::Waterlogged::FALSE:
return 5418;
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
return 5419;
case Properties::Waterlogged::FALSE:
return 5420;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5421;
case Properties::Waterlogged::FALSE:
return 5422;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5423;
case Properties::Waterlogged::FALSE:
return 5424;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5425;
case Properties::Waterlogged::FALSE:
return 5426;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5427;
case Properties::Waterlogged::FALSE:
return 5428;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5429;
case Properties::Waterlogged::FALSE:
return 5430;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5431;
case Properties::Waterlogged::FALSE:
return 5432;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5433;
case Properties::Waterlogged::FALSE:
return 5434;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5435;
case Properties::Waterlogged::FALSE:
return 5436;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5437;
case Properties::Waterlogged::FALSE:
return 5438;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11748;
case Properties::West::LOW:
return 11749;
case Properties::West::TALL:
return 11750;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11751;
case Properties::West::LOW:
return 11752;
case Properties::West::TALL:
return 11753;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11754;
case Properties::West::LOW:
return 11755;
case Properties::West::TALL:
return 11756;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11757;
case Properties::West::LOW:
return 11758;
case Properties::West::TALL:
return 11759;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11760;
case Properties::West::LOW:
return 11761;
case Properties::West::TALL:
return 11762;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11763;
case Properties::West::LOW:
return 11764;
case Properties::West::TALL:
return 11765;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11766;
case Properties::West::LOW:
return 11767;
case Properties::West::TALL:
return 11768;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11769;
case Properties::West::LOW:
return 11770;
case Properties::West::TALL:
return 11771;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11772;
case Properties::West::LOW:
return 11773;
case Properties::West::TALL:
return 11774;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11775;
case Properties::West::LOW:
return 11776;
case Properties::West::TALL:
return 11777;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11778;
case Properties::West::LOW:
return 11779;
case Properties::West::TALL:
return 11780;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11781;
case Properties::West::LOW:
return 11782;
case Properties::West::TALL:
return 11783;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11784;
case Properties::West::LOW:
return 11785;
case Properties::West::TALL:
return 11786;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11787;
case Properties::West::LOW:
return 11788;
case Properties::West::TALL:
return 11789;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11790;
case Properties::West::LOW:
return 11791;
case Properties::West::TALL:
return 11792;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11793;
case Properties::West::LOW:
return 11794;
case Properties::West::TALL:
return 11795;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11796;
case Properties::West::LOW:
return 11797;
case Properties::West::TALL:
return 11798;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11799;
case Properties::West::LOW:
return 11800;
case Properties::West::TALL:
return 11801;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11802;
case Properties::West::LOW:
return 11803;
case Properties::West::TALL:
return 11804;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11805;
case Properties::West::LOW:
return 11806;
case Properties::West::TALL:
return 11807;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11808;
case Properties::West::LOW:
return 11809;
case Properties::West::TALL:
return 11810;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11811;
case Properties::West::LOW:
return 11812;
case Properties::West::TALL:
return 11813;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11814;
case Properties::West::LOW:
return 11815;
case Properties::West::TALL:
return 11816;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11817;
case Properties::West::LOW:
return 11818;
case Properties::West::TALL:
return 11819;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11820;
case Properties::West::LOW:
return 11821;
case Properties::West::TALL:
return 11822;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11823;
case Properties::West::LOW:
return 11824;
case Properties::West::TALL:
return 11825;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11826;
case Properties::West::LOW:
return 11827;
case Properties::West::TALL:
return 11828;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11829;
case Properties::West::LOW:
return 11830;
case Properties::West::TALL:
return 11831;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11832;
case Properties::West::LOW:
return 11833;
case Properties::West::TALL:
return 11834;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11835;
case Properties::West::LOW:
return 11836;
case Properties::West::TALL:
return 11837;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11838;
case Properties::West::LOW:
return 11839;
case Properties::West::TALL:
return 11840;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11841;
case Properties::West::LOW:
return 11842;
case Properties::West::TALL:
return 11843;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11844;
case Properties::West::LOW:
return 11845;
case Properties::West::TALL:
return 11846;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11847;
case Properties::West::LOW:
return 11848;
case Properties::West::TALL:
return 11849;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11850;
case Properties::West::LOW:
return 11851;
case Properties::West::TALL:
return 11852;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11853;
case Properties::West::LOW:
return 11854;
case Properties::West::TALL:
return 11855;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11856;
case Properties::West::LOW:
return 11857;
case Properties::West::TALL:
return 11858;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11859;
case Properties::West::LOW:
return 11860;
case Properties::West::TALL:
return 11861;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11862;
case Properties::West::LOW:
return 11863;
case Properties::West::TALL:
return 11864;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11865;
case Properties::West::LOW:
return 11866;
case Properties::West::TALL:
return 11867;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11868;
case Properties::West::LOW:
return 11869;
case Properties::West::TALL:
return 11870;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11871;
case Properties::West::LOW:
return 11872;
case Properties::West::TALL:
return 11873;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11874;
case Properties::West::LOW:
return 11875;
case Properties::West::TALL:
return 11876;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11877;
case Properties::West::LOW:
return 11878;
case Properties::West::TALL:
return 11879;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11880;
case Properties::West::LOW:
return 11881;
case Properties::West::TALL:
return 11882;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11883;
case Properties::West::LOW:
return 11884;
case Properties::West::TALL:
return 11885;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11886;
case Properties::West::LOW:
return 11887;
case Properties::West::TALL:
return 11888;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11889;
case Properties::West::LOW:
return 11890;
case Properties::West::TALL:
return 11891;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11892;
case Properties::West::LOW:
return 11893;
case Properties::West::TALL:
return 11894;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11895;
case Properties::West::LOW:
return 11896;
case Properties::West::TALL:
return 11897;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11898;
case Properties::West::LOW:
return 11899;
case Properties::West::TALL:
return 11900;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11901;
case Properties::West::LOW:
return 11902;
case Properties::West::TALL:
return 11903;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11904;
case Properties::West::LOW:
return 11905;
case Properties::West::TALL:
return 11906;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11907;
case Properties::West::LOW:
return 11908;
case Properties::West::TALL:
return 11909;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11910;
case Properties::West::LOW:
return 11911;
case Properties::West::TALL:
return 11912;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11913;
case Properties::West::LOW:
return 11914;
case Properties::West::TALL:
return 11915;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11916;
case Properties::West::LOW:
return 11917;
case Properties::West::TALL:
return 11918;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11919;
case Properties::West::LOW:
return 11920;
case Properties::West::TALL:
return 11921;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11922;
case Properties::West::LOW:
return 11923;
case Properties::West::TALL:
return 11924;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11925;
case Properties::West::LOW:
return 11926;
case Properties::West::TALL:
return 11927;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11928;
case Properties::West::LOW:
return 11929;
case Properties::West::TALL:
return 11930;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11931;
case Properties::West::LOW:
return 11932;
case Properties::West::TALL:
return 11933;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11934;
case Properties::West::LOW:
return 11935;
case Properties::West::TALL:
return 11936;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11937;
case Properties::West::LOW:
return 11938;
case Properties::West::TALL:
return 11939;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11940;
case Properties::West::LOW:
return 11941;
case Properties::West::TALL:
return 11942;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11943;
case Properties::West::LOW:
return 11944;
case Properties::West::TALL:
return 11945;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11946;
case Properties::West::LOW:
return 11947;
case Properties::West::TALL:
return 11948;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11949;
case Properties::West::LOW:
return 11950;
case Properties::West::TALL:
return 11951;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11952;
case Properties::West::LOW:
return 11953;
case Properties::West::TALL:
return 11954;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11955;
case Properties::West::LOW:
return 11956;
case Properties::West::TALL:
return 11957;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11958;
case Properties::West::LOW:
return 11959;
case Properties::West::TALL:
return 11960;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11961;
case Properties::West::LOW:
return 11962;
case Properties::West::TALL:
return 11963;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11964;
case Properties::West::LOW:
return 11965;
case Properties::West::TALL:
return 11966;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11967;
case Properties::West::LOW:
return 11968;
case Properties::West::TALL:
return 11969;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11970;
case Properties::West::LOW:
return 11971;
case Properties::West::TALL:
return 11972;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11973;
case Properties::West::LOW:
return 11974;
case Properties::West::TALL:
return 11975;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11976;
case Properties::West::LOW:
return 11977;
case Properties::West::TALL:
return 11978;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11979;
case Properties::West::LOW:
return 11980;
case Properties::West::TALL:
return 11981;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11982;
case Properties::West::LOW:
return 11983;
case Properties::West::TALL:
return 11984;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11985;
case Properties::West::LOW:
return 11986;
case Properties::West::TALL:
return 11987;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11988;
case Properties::West::LOW:
return 11989;
case Properties::West::TALL:
return 11990;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11991;
case Properties::West::LOW:
return 11992;
case Properties::West::TALL:
return 11993;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 11994;
case Properties::West::LOW:
return 11995;
case Properties::West::TALL:
return 11996;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 11997;
case Properties::West::LOW:
return 11998;
case Properties::West::TALL:
return 11999;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12000;
case Properties::West::LOW:
return 12001;
case Properties::West::TALL:
return 12002;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12003;
case Properties::West::LOW:
return 12004;
case Properties::West::TALL:
return 12005;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12006;
case Properties::West::LOW:
return 12007;
case Properties::West::TALL:
return 12008;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12009;
case Properties::West::LOW:
return 12010;
case Properties::West::TALL:
return 12011;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12012;
case Properties::West::LOW:
return 12013;
case Properties::West::TALL:
return 12014;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12015;
case Properties::West::LOW:
return 12016;
case Properties::West::TALL:
return 12017;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12018;
case Properties::West::LOW:
return 12019;
case Properties::West::TALL:
return 12020;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12021;
case Properties::West::LOW:
return 12022;
case Properties::West::TALL:
return 12023;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12024;
case Properties::West::LOW:
return 12025;
case Properties::West::TALL:
return 12026;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12027;
case Properties::West::LOW:
return 12028;
case Properties::West::TALL:
return 12029;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12030;
case Properties::West::LOW:
return 12031;
case Properties::West::TALL:
return 12032;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12033;
case Properties::West::LOW:
return 12034;
case Properties::West::TALL:
return 12035;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12036;
case Properties::West::LOW:
return 12037;
case Properties::West::TALL:
return 12038;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12039;
case Properties::West::LOW:
return 12040;
case Properties::West::TALL:
return 12041;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12042;
case Properties::West::LOW:
return 12043;
case Properties::West::TALL:
return 12044;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12045;
case Properties::West::LOW:
return 12046;
case Properties::West::TALL:
return 12047;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12048;
case Properties::West::LOW:
return 12049;
case Properties::West::TALL:
return 12050;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12051;
case Properties::West::LOW:
return 12052;
case Properties::West::TALL:
return 12053;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12054;
case Properties::West::LOW:
return 12055;
case Properties::West::TALL:
return 12056;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12057;
case Properties::West::LOW:
return 12058;
case Properties::West::TALL:
return 12059;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12060;
case Properties::West::LOW:
return 12061;
case Properties::West::TALL:
return 12062;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12063;
case Properties::West::LOW:
return 12064;
case Properties::West::TALL:
return 12065;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12066;
case Properties::West::LOW:
return 12067;
case Properties::West::TALL:
return 12068;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12069;
case Properties::West::LOW:
return 12070;
case Properties::West::TALL:
return 12071;
}
}
}
}
}
}
return 0;
}
}

namespace Bricks {
constexpr Block toProtocol() {
return 1683;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8830;
case Properties::Rotation::ONE:
return 8831;
case Properties::Rotation::TWO:
return 8832;
case Properties::Rotation::THREE:
return 8833;
case Properties::Rotation::FOUR:
return 8834;
case Properties::Rotation::FIVE:
return 8835;
case Properties::Rotation::SIX:
return 8836;
case Properties::Rotation::SEVEN:
return 8837;
case Properties::Rotation::EIGHT:
return 8838;
case Properties::Rotation::NINE:
return 8839;
case Properties::Rotation::TEN:
return 8840;
case Properties::Rotation::ELEVEN:
return 8841;
case Properties::Rotation::TWELVE:
return 8842;
case Properties::Rotation::THIRTEEN:
return 8843;
case Properties::Rotation::FOURTEEN:
return 8844;
case Properties::Rotation::FIFTEEN:
return 8845;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1471;
case Properties::Part::FOOT:
return 1472;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1473;
case Properties::Part::FOOT:
return 1474;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1475;
case Properties::Part::FOOT:
return 1476;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1477;
case Properties::Part::FOOT:
return 1478;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1479;
case Properties::Part::FOOT:
return 1480;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1481;
case Properties::Part::FOOT:
return 1482;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1483;
case Properties::Part::FOOT:
return 1484;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1485;
case Properties::Part::FOOT:
return 1486;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18521;
case Properties::Waterlogged::FALSE:
return 18522;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18523;
case Properties::Waterlogged::FALSE:
return 18524;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18525;
case Properties::Waterlogged::FALSE:
return 18526;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18527;
case Properties::Waterlogged::FALSE:
return 18528;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18529;
case Properties::Waterlogged::FALSE:
return 18530;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18531;
case Properties::Waterlogged::FALSE:
return 18532;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18533;
case Properties::Waterlogged::FALSE:
return 18534;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18535;
case Properties::Waterlogged::FALSE:
return 18536;
}
}
}
return 0;
}
}

namespace BrownCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18611;
case Properties::Lit::FALSE:
return 18612;
}
return 0;
}
}

namespace BrownCarpet {
constexpr Block toProtocol() {
return 8619;
return 0;
}
}

namespace BrownConcrete {
constexpr Block toProtocol() {
return 10331;
return 0;
}
}

namespace BrownConcretePowder {
constexpr Block toProtocol() {
return 10347;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10303;
case Properties::Facing::SOUTH:
return 10304;
case Properties::Facing::WEST:
return 10305;
case Properties::Facing::EAST:
return 10306;
}
return 0;
}
}

namespace BrownMushroom {
constexpr Block toProtocol() {
return 1679;
return 0;
}
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
constexpr Block toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
switch (down) {
case Properties::Down::TRUE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4880;
case Properties::West::FALSE:
return 4881;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4882;
case Properties::West::FALSE:
return 4883;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4884;
case Properties::West::FALSE:
return 4885;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4886;
case Properties::West::FALSE:
return 4887;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4888;
case Properties::West::FALSE:
return 4889;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4890;
case Properties::West::FALSE:
return 4891;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4892;
case Properties::West::FALSE:
return 4893;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4894;
case Properties::West::FALSE:
return 4895;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4896;
case Properties::West::FALSE:
return 4897;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4898;
case Properties::West::FALSE:
return 4899;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4900;
case Properties::West::FALSE:
return 4901;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4902;
case Properties::West::FALSE:
return 4903;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4904;
case Properties::West::FALSE:
return 4905;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4906;
case Properties::West::FALSE:
return 4907;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4908;
case Properties::West::FALSE:
return 4909;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4910;
case Properties::West::FALSE:
return 4911;
}
}
}
}
}
case Properties::Down::FALSE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4912;
case Properties::West::FALSE:
return 4913;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4914;
case Properties::West::FALSE:
return 4915;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4916;
case Properties::West::FALSE:
return 4917;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4918;
case Properties::West::FALSE:
return 4919;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4920;
case Properties::West::FALSE:
return 4921;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4922;
case Properties::West::FALSE:
return 4923;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4924;
case Properties::West::FALSE:
return 4925;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4926;
case Properties::West::FALSE:
return 4927;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4928;
case Properties::West::FALSE:
return 4929;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4930;
case Properties::West::FALSE:
return 4931;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4932;
case Properties::West::FALSE:
return 4933;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4934;
case Properties::West::FALSE:
return 4935;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4936;
case Properties::West::FALSE:
return 4937;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4938;
case Properties::West::FALSE:
return 4939;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 4940;
case Properties::West::FALSE:
return 4941;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 4942;
case Properties::West::FALSE:
return 4943;
}
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10231;
case Properties::Facing::EAST:
return 10232;
case Properties::Facing::SOUTH:
return 10233;
case Properties::Facing::WEST:
return 10234;
case Properties::Facing::UP:
return 10235;
case Properties::Facing::DOWN:
return 10236;
}
return 0;
}
}

namespace BrownStainedGlass {
constexpr Block toProtocol() {
return 4416;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7876;
case Properties::West::FALSE:
return 7877;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7878;
case Properties::West::FALSE:
return 7879;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7880;
case Properties::West::FALSE:
return 7881;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7882;
case Properties::West::FALSE:
return 7883;
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
return 7884;
case Properties::West::FALSE:
return 7885;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7886;
case Properties::West::FALSE:
return 7887;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7888;
case Properties::West::FALSE:
return 7889;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7890;
case Properties::West::FALSE:
return 7891;
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
return 7892;
case Properties::West::FALSE:
return 7893;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7894;
case Properties::West::FALSE:
return 7895;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7896;
case Properties::West::FALSE:
return 7897;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7898;
case Properties::West::FALSE:
return 7899;
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
return 7900;
case Properties::West::FALSE:
return 7901;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7902;
case Properties::West::FALSE:
return 7903;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7904;
case Properties::West::FALSE:
return 7905;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7906;
case Properties::West::FALSE:
return 7907;
}
}
}
}
}
return 0;
}
}

namespace BrownTerracotta {
constexpr Block toProtocol() {
return 7488;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8942;
case Properties::Facing::SOUTH:
return 8943;
case Properties::Facing::WEST:
return 8944;
case Properties::Facing::EAST:
return 8945;
}
return 0;
}
}

namespace BrownWool {
constexpr Block toProtocol() {
return 1650;
return 0;
}
}

namespace BubbleColumn {
namespace Properties {
enum class Drag {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Drag drag) {
switch (drag) {
case Properties::Drag::TRUE:
return 10548;
case Properties::Drag::FALSE:
return 10549;
}
return 0;
}
}

namespace BubbleCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10415;
case Properties::Waterlogged::FALSE:
return 10416;
}
return 0;
}
}

namespace BubbleCoralBlock {
constexpr Block toProtocol() {
return 10398;
return 0;
}
}

namespace BubbleCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10435;
case Properties::Waterlogged::FALSE:
return 10436;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10497;
case Properties::Waterlogged::FALSE:
return 10498;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10499;
case Properties::Waterlogged::FALSE:
return 10500;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10501;
case Properties::Waterlogged::FALSE:
return 10502;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10503;
case Properties::Waterlogged::FALSE:
return 10504;
}
}
return 0;
}
}

namespace BuddingAmethyst {
constexpr Block toProtocol() {
return 18620;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 4240;
case Properties::Age::ONE:
return 4241;
case Properties::Age::TWO:
return 4242;
case Properties::Age::THREE:
return 4243;
case Properties::Age::FOUR:
return 4244;
case Properties::Age::FIVE:
return 4245;
case Properties::Age::SIX:
return 4246;
case Properties::Age::SEVEN:
return 4247;
case Properties::Age::EIGHT:
return 4248;
case Properties::Age::NINE:
return 4249;
case Properties::Age::TEN:
return 4250;
case Properties::Age::ELEVEN:
return 4251;
case Properties::Age::TWELVE:
return 4252;
case Properties::Age::THIRTEEN:
return 4253;
case Properties::Age::FOURTEEN:
return 4254;
case Properties::Age::FIFTEEN:
return 4255;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Bites bites) {
switch (bites) {
case Properties::Bites::ZERO:
return 4333;
case Properties::Bites::ONE:
return 4334;
case Properties::Bites::TWO:
return 4335;
case Properties::Bites::THREE:
return 4336;
case Properties::Bites::FOUR:
return 4337;
case Properties::Bites::FIVE:
return 4338;
case Properties::Bites::SIX:
return 4339;
}
return 0;
}
}

namespace Calcite {
constexpr Block toProtocol() {
return 18670;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (lit) {
case Properties::Lit::TRUE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16099;
case Properties::Waterlogged::FALSE:
return 16100;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16101;
case Properties::Waterlogged::FALSE:
return 16102;
}
}
case Properties::Lit::FALSE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16103;
case Properties::Waterlogged::FALSE:
return 16104;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16105;
case Properties::Waterlogged::FALSE:
return 16106;
}
}
}
case Properties::Facing::SOUTH:
switch (lit) {
case Properties::Lit::TRUE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16107;
case Properties::Waterlogged::FALSE:
return 16108;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16109;
case Properties::Waterlogged::FALSE:
return 16110;
}
}
case Properties::Lit::FALSE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16111;
case Properties::Waterlogged::FALSE:
return 16112;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16113;
case Properties::Waterlogged::FALSE:
return 16114;
}
}
}
case Properties::Facing::WEST:
switch (lit) {
case Properties::Lit::TRUE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16115;
case Properties::Waterlogged::FALSE:
return 16116;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16117;
case Properties::Waterlogged::FALSE:
return 16118;
}
}
case Properties::Lit::FALSE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16119;
case Properties::Waterlogged::FALSE:
return 16120;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16121;
case Properties::Waterlogged::FALSE:
return 16122;
}
}
}
case Properties::Facing::EAST:
switch (lit) {
case Properties::Lit::TRUE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16123;
case Properties::Waterlogged::FALSE:
return 16124;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16125;
case Properties::Waterlogged::FALSE:
return 16126;
}
}
case Properties::Lit::FALSE:
switch (signal_fire) {
case Properties::Signal_fire::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16127;
case Properties::Waterlogged::FALSE:
return 16128;
}
case Properties::Signal_fire::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16129;
case Properties::Waterlogged::FALSE:
return 16130;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18313;
case Properties::Waterlogged::FALSE:
return 18314;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18315;
case Properties::Waterlogged::FALSE:
return 18316;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18317;
case Properties::Waterlogged::FALSE:
return 18318;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18319;
case Properties::Waterlogged::FALSE:
return 18320;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18321;
case Properties::Waterlogged::FALSE:
return 18322;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18323;
case Properties::Waterlogged::FALSE:
return 18324;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18325;
case Properties::Waterlogged::FALSE:
return 18326;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18327;
case Properties::Waterlogged::FALSE:
return 18328;
}
}
}
return 0;
}
}

namespace CandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18585;
case Properties::Lit::FALSE:
return 18586;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 6923;
case Properties::Age::ONE:
return 6924;
case Properties::Age::TWO:
return 6925;
case Properties::Age::THREE:
return 6926;
case Properties::Age::FOUR:
return 6927;
case Properties::Age::FIVE:
return 6928;
case Properties::Age::SIX:
return 6929;
case Properties::Age::SEVEN:
return 6930;
}
return 0;
}
}

namespace CartographyTable {
constexpr Block toProtocol() {
return 16024;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 4325;
case Properties::Facing::SOUTH:
return 4326;
case Properties::Facing::WEST:
return 4327;
case Properties::Facing::EAST:
return 4328;
}
return 0;
}
}

namespace Cauldron {
constexpr Block toProtocol() {
return 5728;
return 0;
}
}

namespace CaveAir {
constexpr Block toProtocol() {
return 10547;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age, Properties::Berries berries) {
switch (age) {
case Properties::Age::ZERO:
switch (berries) {
case Properties::Berries::TRUE:
return 19659;
case Properties::Berries::FALSE:
return 19660;
}
case Properties::Age::ONE:
switch (berries) {
case Properties::Berries::TRUE:
return 19661;
case Properties::Berries::FALSE:
return 19662;
}
case Properties::Age::TWO:
switch (berries) {
case Properties::Berries::TRUE:
return 19663;
case Properties::Berries::FALSE:
return 19664;
}
case Properties::Age::THREE:
switch (berries) {
case Properties::Berries::TRUE:
return 19665;
case Properties::Berries::FALSE:
return 19666;
}
case Properties::Age::FOUR:
switch (berries) {
case Properties::Berries::TRUE:
return 19667;
case Properties::Berries::FALSE:
return 19668;
}
case Properties::Age::FIVE:
switch (berries) {
case Properties::Berries::TRUE:
return 19669;
case Properties::Berries::FALSE:
return 19670;
}
case Properties::Age::SIX:
switch (berries) {
case Properties::Berries::TRUE:
return 19671;
case Properties::Berries::FALSE:
return 19672;
}
case Properties::Age::SEVEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19673;
case Properties::Berries::FALSE:
return 19674;
}
case Properties::Age::EIGHT:
switch (berries) {
case Properties::Berries::TRUE:
return 19675;
case Properties::Berries::FALSE:
return 19676;
}
case Properties::Age::NINE:
switch (berries) {
case Properties::Berries::TRUE:
return 19677;
case Properties::Berries::FALSE:
return 19678;
}
case Properties::Age::TEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19679;
case Properties::Berries::FALSE:
return 19680;
}
case Properties::Age::ELEVEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19681;
case Properties::Berries::FALSE:
return 19682;
}
case Properties::Age::TWELVE:
switch (berries) {
case Properties::Berries::TRUE:
return 19683;
case Properties::Berries::FALSE:
return 19684;
}
case Properties::Age::THIRTEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19685;
case Properties::Berries::FALSE:
return 19686;
}
case Properties::Age::FOURTEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19687;
case Properties::Berries::FALSE:
return 19688;
}
case Properties::Age::FIFTEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19689;
case Properties::Berries::FALSE:
return 19690;
}
case Properties::Age::SIXTEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19691;
case Properties::Berries::FALSE:
return 19692;
}
case Properties::Age::SEVENTEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19693;
case Properties::Berries::FALSE:
return 19694;
}
case Properties::Age::EIGHTEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19695;
case Properties::Berries::FALSE:
return 19696;
}
case Properties::Age::NINETEEN:
switch (berries) {
case Properties::Berries::TRUE:
return 19697;
case Properties::Berries::FALSE:
return 19698;
}
case Properties::Age::TWENTY:
switch (berries) {
case Properties::Berries::TRUE:
return 19699;
case Properties::Berries::FALSE:
return 19700;
}
case Properties::Age::TWENTY_ONE:
switch (berries) {
case Properties::Berries::TRUE:
return 19701;
case Properties::Berries::FALSE:
return 19702;
}
case Properties::Age::TWENTY_TWO:
switch (berries) {
case Properties::Berries::TRUE:
return 19703;
case Properties::Berries::FALSE:
return 19704;
}
case Properties::Age::TWENTY_THREE:
switch (berries) {
case Properties::Berries::TRUE:
return 19705;
case Properties::Berries::FALSE:
return 19706;
}
case Properties::Age::TWENTY_FOUR:
switch (berries) {
case Properties::Berries::TRUE:
return 19707;
case Properties::Berries::FALSE:
return 19708;
}
case Properties::Age::TWENTY_FIVE:
switch (berries) {
case Properties::Berries::TRUE:
return 19709;
case Properties::Berries::FALSE:
return 19710;
}
}
return 0;
}
}

namespace CaveVinesPlant {
namespace Properties {
enum class Berries {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Berries berries) {
switch (berries) {
case Properties::Berries::TRUE:
return 19711;
case Properties::Berries::FALSE:
return 19712;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Axis axis, Properties::Waterlogged waterlogged) {
switch (axis) {
case Properties::Axis::X:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5104;
case Properties::Waterlogged::FALSE:
return 5105;
}
case Properties::Axis::Y:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5106;
case Properties::Waterlogged::FALSE:
return 5107;
}
case Properties::Axis::Z:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5108;
case Properties::Waterlogged::FALSE:
return 5109;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Conditional conditional, Properties::Facing facing) {
switch (conditional) {
case Properties::Conditional::TRUE:
switch (facing) {
case Properties::Facing::NORTH:
return 10118;
case Properties::Facing::EAST:
return 10119;
case Properties::Facing::SOUTH:
return 10120;
case Properties::Facing::WEST:
return 10121;
case Properties::Facing::UP:
return 10122;
case Properties::Facing::DOWN:
return 10123;
}
case Properties::Conditional::FALSE:
switch (facing) {
case Properties::Facing::NORTH:
return 10124;
case Properties::Facing::EAST:
return 10125;
case Properties::Facing::SOUTH:
return 10126;
case Properties::Facing::WEST:
return 10127;
case Properties::Facing::UP:
return 10128;
case Properties::Facing::DOWN:
return 10129;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::SINGLE:
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2288;
case Properties::Waterlogged::FALSE:
return 2289;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2294;
case Properties::Waterlogged::FALSE:
return 2295;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2300;
case Properties::Waterlogged::FALSE:
return 2301;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2306;
case Properties::Waterlogged::FALSE:
return 2307;
}
}
case Properties::Type::LEFT:
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2290;
case Properties::Waterlogged::FALSE:
return 2291;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2296;
case Properties::Waterlogged::FALSE:
return 2297;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2302;
case Properties::Waterlogged::FALSE:
return 2303;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2308;
case Properties::Waterlogged::FALSE:
return 2309;
}
}
case Properties::Type::RIGHT:
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2292;
case Properties::Waterlogged::FALSE:
return 2293;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2298;
case Properties::Waterlogged::FALSE:
return 2299;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2304;
case Properties::Waterlogged::FALSE:
return 2305;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 2310;
case Properties::Waterlogged::FALSE:
return 2311;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 7231;
case Properties::Facing::SOUTH:
return 7232;
case Properties::Facing::WEST:
return 7233;
case Properties::Facing::EAST:
return 7234;
}
return 0;
}
}

namespace ChiseledDeepslate {
constexpr Block toProtocol() {
return 21425;
return 0;
}
}

namespace ChiseledNetherBricks {
constexpr Block toProtocol() {
return 18310;
return 0;
}
}

namespace ChiseledPolishedBlackstone {
constexpr Block toProtocol() {
return 17462;
return 0;
}
}

namespace ChiseledQuartzBlock {
constexpr Block toProtocol() {
return 7356;
return 0;
}
}

namespace ChiseledRedSandstone {
constexpr Block toProtocol() {
return 8959;
return 0;
}
}

namespace ChiseledSandstone {
constexpr Block toProtocol() {
return 477;
return 0;
}
}

namespace ChiseledStoneBricks {
constexpr Block toProtocol() {
return 4871;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 10009;
case Properties::Age::ONE:
return 10010;
case Properties::Age::TWO:
return 10011;
case Properties::Age::THREE:
return 10012;
case Properties::Age::FOUR:
return 10013;
case Properties::Age::FIVE:
return 10014;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
switch (down) {
case Properties::Down::TRUE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9945;
case Properties::West::FALSE:
return 9946;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9947;
case Properties::West::FALSE:
return 9948;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9949;
case Properties::West::FALSE:
return 9950;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9951;
case Properties::West::FALSE:
return 9952;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9953;
case Properties::West::FALSE:
return 9954;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9955;
case Properties::West::FALSE:
return 9956;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9957;
case Properties::West::FALSE:
return 9958;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9959;
case Properties::West::FALSE:
return 9960;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9961;
case Properties::West::FALSE:
return 9962;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9963;
case Properties::West::FALSE:
return 9964;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9965;
case Properties::West::FALSE:
return 9966;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9967;
case Properties::West::FALSE:
return 9968;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9969;
case Properties::West::FALSE:
return 9970;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9971;
case Properties::West::FALSE:
return 9972;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9973;
case Properties::West::FALSE:
return 9974;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9975;
case Properties::West::FALSE:
return 9976;
}
}
}
}
}
case Properties::Down::FALSE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9977;
case Properties::West::FALSE:
return 9978;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9979;
case Properties::West::FALSE:
return 9980;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9981;
case Properties::West::FALSE:
return 9982;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9983;
case Properties::West::FALSE:
return 9984;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9985;
case Properties::West::FALSE:
return 9986;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9987;
case Properties::West::FALSE:
return 9988;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9989;
case Properties::West::FALSE:
return 9990;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9991;
case Properties::West::FALSE:
return 9992;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9993;
case Properties::West::FALSE:
return 9994;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9995;
case Properties::West::FALSE:
return 9996;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9997;
case Properties::West::FALSE:
return 9998;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9999;
case Properties::West::FALSE:
return 10000;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 10001;
case Properties::West::FALSE:
return 10002;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 10003;
case Properties::West::FALSE:
return 10004;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 10005;
case Properties::West::FALSE:
return 10006;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 10007;
case Properties::West::FALSE:
return 10008;
}
}
}
}
}
}
return 0;
}
}

namespace Clay {
constexpr Block toProtocol() {
return 4256;
return 0;
}
}

namespace CoalBlock {
constexpr Block toProtocol() {
return 8624;
return 0;
}
}

namespace CoalOre {
constexpr Block toProtocol() {
return 114;
return 0;
}
}

namespace CoarseDirt {
constexpr Block toProtocol() {
return 11;
return 0;
}
}

namespace CobbledDeepslate {
constexpr Block toProtocol() {
return 19781;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19862;
case Properties::Waterlogged::FALSE:
return 19863;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19864;
case Properties::Waterlogged::FALSE:
return 19865;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19866;
case Properties::Waterlogged::FALSE:
return 19867;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19782;
case Properties::Waterlogged::FALSE:
return 19783;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19784;
case Properties::Waterlogged::FALSE:
return 19785;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19786;
case Properties::Waterlogged::FALSE:
return 19787;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19788;
case Properties::Waterlogged::FALSE:
return 19789;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19790;
case Properties::Waterlogged::FALSE:
return 19791;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19792;
case Properties::Waterlogged::FALSE:
return 19793;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19794;
case Properties::Waterlogged::FALSE:
return 19795;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19796;
case Properties::Waterlogged::FALSE:
return 19797;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19798;
case Properties::Waterlogged::FALSE:
return 19799;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19800;
case Properties::Waterlogged::FALSE:
return 19801;
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
return 19802;
case Properties::Waterlogged::FALSE:
return 19803;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19804;
case Properties::Waterlogged::FALSE:
return 19805;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19806;
case Properties::Waterlogged::FALSE:
return 19807;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19808;
case Properties::Waterlogged::FALSE:
return 19809;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19810;
case Properties::Waterlogged::FALSE:
return 19811;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19812;
case Properties::Waterlogged::FALSE:
return 19813;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19814;
case Properties::Waterlogged::FALSE:
return 19815;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19816;
case Properties::Waterlogged::FALSE:
return 19817;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19818;
case Properties::Waterlogged::FALSE:
return 19819;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19820;
case Properties::Waterlogged::FALSE:
return 19821;
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
return 19822;
case Properties::Waterlogged::FALSE:
return 19823;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19824;
case Properties::Waterlogged::FALSE:
return 19825;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19826;
case Properties::Waterlogged::FALSE:
return 19827;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19828;
case Properties::Waterlogged::FALSE:
return 19829;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19830;
case Properties::Waterlogged::FALSE:
return 19831;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19832;
case Properties::Waterlogged::FALSE:
return 19833;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19834;
case Properties::Waterlogged::FALSE:
return 19835;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19836;
case Properties::Waterlogged::FALSE:
return 19837;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19838;
case Properties::Waterlogged::FALSE:
return 19839;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19840;
case Properties::Waterlogged::FALSE:
return 19841;
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
return 19842;
case Properties::Waterlogged::FALSE:
return 19843;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19844;
case Properties::Waterlogged::FALSE:
return 19845;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19846;
case Properties::Waterlogged::FALSE:
return 19847;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19848;
case Properties::Waterlogged::FALSE:
return 19849;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19850;
case Properties::Waterlogged::FALSE:
return 19851;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19852;
case Properties::Waterlogged::FALSE:
return 19853;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19854;
case Properties::Waterlogged::FALSE:
return 19855;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19856;
case Properties::Waterlogged::FALSE:
return 19857;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19858;
case Properties::Waterlogged::FALSE:
return 19859;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19860;
case Properties::Waterlogged::FALSE:
return 19861;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19868;
case Properties::West::LOW:
return 19869;
case Properties::West::TALL:
return 19870;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19871;
case Properties::West::LOW:
return 19872;
case Properties::West::TALL:
return 19873;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19874;
case Properties::West::LOW:
return 19875;
case Properties::West::TALL:
return 19876;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19877;
case Properties::West::LOW:
return 19878;
case Properties::West::TALL:
return 19879;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19880;
case Properties::West::LOW:
return 19881;
case Properties::West::TALL:
return 19882;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19883;
case Properties::West::LOW:
return 19884;
case Properties::West::TALL:
return 19885;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19886;
case Properties::West::LOW:
return 19887;
case Properties::West::TALL:
return 19888;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19889;
case Properties::West::LOW:
return 19890;
case Properties::West::TALL:
return 19891;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19892;
case Properties::West::LOW:
return 19893;
case Properties::West::TALL:
return 19894;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19895;
case Properties::West::LOW:
return 19896;
case Properties::West::TALL:
return 19897;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19898;
case Properties::West::LOW:
return 19899;
case Properties::West::TALL:
return 19900;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19901;
case Properties::West::LOW:
return 19902;
case Properties::West::TALL:
return 19903;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19904;
case Properties::West::LOW:
return 19905;
case Properties::West::TALL:
return 19906;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19907;
case Properties::West::LOW:
return 19908;
case Properties::West::TALL:
return 19909;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19910;
case Properties::West::LOW:
return 19911;
case Properties::West::TALL:
return 19912;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19913;
case Properties::West::LOW:
return 19914;
case Properties::West::TALL:
return 19915;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19916;
case Properties::West::LOW:
return 19917;
case Properties::West::TALL:
return 19918;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19919;
case Properties::West::LOW:
return 19920;
case Properties::West::TALL:
return 19921;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19922;
case Properties::West::LOW:
return 19923;
case Properties::West::TALL:
return 19924;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19925;
case Properties::West::LOW:
return 19926;
case Properties::West::TALL:
return 19927;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19928;
case Properties::West::LOW:
return 19929;
case Properties::West::TALL:
return 19930;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19931;
case Properties::West::LOW:
return 19932;
case Properties::West::TALL:
return 19933;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19934;
case Properties::West::LOW:
return 19935;
case Properties::West::TALL:
return 19936;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19937;
case Properties::West::LOW:
return 19938;
case Properties::West::TALL:
return 19939;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19940;
case Properties::West::LOW:
return 19941;
case Properties::West::TALL:
return 19942;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19943;
case Properties::West::LOW:
return 19944;
case Properties::West::TALL:
return 19945;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19946;
case Properties::West::LOW:
return 19947;
case Properties::West::TALL:
return 19948;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19949;
case Properties::West::LOW:
return 19950;
case Properties::West::TALL:
return 19951;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19952;
case Properties::West::LOW:
return 19953;
case Properties::West::TALL:
return 19954;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19955;
case Properties::West::LOW:
return 19956;
case Properties::West::TALL:
return 19957;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19958;
case Properties::West::LOW:
return 19959;
case Properties::West::TALL:
return 19960;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19961;
case Properties::West::LOW:
return 19962;
case Properties::West::TALL:
return 19963;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19964;
case Properties::West::LOW:
return 19965;
case Properties::West::TALL:
return 19966;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19967;
case Properties::West::LOW:
return 19968;
case Properties::West::TALL:
return 19969;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19970;
case Properties::West::LOW:
return 19971;
case Properties::West::TALL:
return 19972;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19973;
case Properties::West::LOW:
return 19974;
case Properties::West::TALL:
return 19975;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19976;
case Properties::West::LOW:
return 19977;
case Properties::West::TALL:
return 19978;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19979;
case Properties::West::LOW:
return 19980;
case Properties::West::TALL:
return 19981;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19982;
case Properties::West::LOW:
return 19983;
case Properties::West::TALL:
return 19984;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19985;
case Properties::West::LOW:
return 19986;
case Properties::West::TALL:
return 19987;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19988;
case Properties::West::LOW:
return 19989;
case Properties::West::TALL:
return 19990;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19991;
case Properties::West::LOW:
return 19992;
case Properties::West::TALL:
return 19993;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 19994;
case Properties::West::LOW:
return 19995;
case Properties::West::TALL:
return 19996;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 19997;
case Properties::West::LOW:
return 19998;
case Properties::West::TALL:
return 19999;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20000;
case Properties::West::LOW:
return 20001;
case Properties::West::TALL:
return 20002;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20003;
case Properties::West::LOW:
return 20004;
case Properties::West::TALL:
return 20005;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20006;
case Properties::West::LOW:
return 20007;
case Properties::West::TALL:
return 20008;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20009;
case Properties::West::LOW:
return 20010;
case Properties::West::TALL:
return 20011;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20012;
case Properties::West::LOW:
return 20013;
case Properties::West::TALL:
return 20014;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20015;
case Properties::West::LOW:
return 20016;
case Properties::West::TALL:
return 20017;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20018;
case Properties::West::LOW:
return 20019;
case Properties::West::TALL:
return 20020;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20021;
case Properties::West::LOW:
return 20022;
case Properties::West::TALL:
return 20023;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20024;
case Properties::West::LOW:
return 20025;
case Properties::West::TALL:
return 20026;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20027;
case Properties::West::LOW:
return 20028;
case Properties::West::TALL:
return 20029;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20030;
case Properties::West::LOW:
return 20031;
case Properties::West::TALL:
return 20032;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20033;
case Properties::West::LOW:
return 20034;
case Properties::West::TALL:
return 20035;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20036;
case Properties::West::LOW:
return 20037;
case Properties::West::TALL:
return 20038;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20039;
case Properties::West::LOW:
return 20040;
case Properties::West::TALL:
return 20041;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20042;
case Properties::West::LOW:
return 20043;
case Properties::West::TALL:
return 20044;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20045;
case Properties::West::LOW:
return 20046;
case Properties::West::TALL:
return 20047;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20048;
case Properties::West::LOW:
return 20049;
case Properties::West::TALL:
return 20050;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20051;
case Properties::West::LOW:
return 20052;
case Properties::West::TALL:
return 20053;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20054;
case Properties::West::LOW:
return 20055;
case Properties::West::TALL:
return 20056;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20057;
case Properties::West::LOW:
return 20058;
case Properties::West::TALL:
return 20059;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20060;
case Properties::West::LOW:
return 20061;
case Properties::West::TALL:
return 20062;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20063;
case Properties::West::LOW:
return 20064;
case Properties::West::TALL:
return 20065;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20066;
case Properties::West::LOW:
return 20067;
case Properties::West::TALL:
return 20068;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20069;
case Properties::West::LOW:
return 20070;
case Properties::West::TALL:
return 20071;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20072;
case Properties::West::LOW:
return 20073;
case Properties::West::TALL:
return 20074;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20075;
case Properties::West::LOW:
return 20076;
case Properties::West::TALL:
return 20077;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20078;
case Properties::West::LOW:
return 20079;
case Properties::West::TALL:
return 20080;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20081;
case Properties::West::LOW:
return 20082;
case Properties::West::TALL:
return 20083;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20084;
case Properties::West::LOW:
return 20085;
case Properties::West::TALL:
return 20086;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20087;
case Properties::West::LOW:
return 20088;
case Properties::West::TALL:
return 20089;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20090;
case Properties::West::LOW:
return 20091;
case Properties::West::TALL:
return 20092;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20093;
case Properties::West::LOW:
return 20094;
case Properties::West::TALL:
return 20095;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20096;
case Properties::West::LOW:
return 20097;
case Properties::West::TALL:
return 20098;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20099;
case Properties::West::LOW:
return 20100;
case Properties::West::TALL:
return 20101;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20102;
case Properties::West::LOW:
return 20103;
case Properties::West::TALL:
return 20104;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20105;
case Properties::West::LOW:
return 20106;
case Properties::West::TALL:
return 20107;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20108;
case Properties::West::LOW:
return 20109;
case Properties::West::TALL:
return 20110;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20111;
case Properties::West::LOW:
return 20112;
case Properties::West::TALL:
return 20113;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20114;
case Properties::West::LOW:
return 20115;
case Properties::West::TALL:
return 20116;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20117;
case Properties::West::LOW:
return 20118;
case Properties::West::TALL:
return 20119;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20120;
case Properties::West::LOW:
return 20121;
case Properties::West::TALL:
return 20122;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20123;
case Properties::West::LOW:
return 20124;
case Properties::West::TALL:
return 20125;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20126;
case Properties::West::LOW:
return 20127;
case Properties::West::TALL:
return 20128;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20129;
case Properties::West::LOW:
return 20130;
case Properties::West::TALL:
return 20131;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20132;
case Properties::West::LOW:
return 20133;
case Properties::West::TALL:
return 20134;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20135;
case Properties::West::LOW:
return 20136;
case Properties::West::TALL:
return 20137;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20138;
case Properties::West::LOW:
return 20139;
case Properties::West::TALL:
return 20140;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20141;
case Properties::West::LOW:
return 20142;
case Properties::West::TALL:
return 20143;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20144;
case Properties::West::LOW:
return 20145;
case Properties::West::TALL:
return 20146;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20147;
case Properties::West::LOW:
return 20148;
case Properties::West::TALL:
return 20149;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20150;
case Properties::West::LOW:
return 20151;
case Properties::West::TALL:
return 20152;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20153;
case Properties::West::LOW:
return 20154;
case Properties::West::TALL:
return 20155;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20156;
case Properties::West::LOW:
return 20157;
case Properties::West::TALL:
return 20158;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20159;
case Properties::West::LOW:
return 20160;
case Properties::West::TALL:
return 20161;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20162;
case Properties::West::LOW:
return 20163;
case Properties::West::TALL:
return 20164;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20165;
case Properties::West::LOW:
return 20166;
case Properties::West::TALL:
return 20167;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20168;
case Properties::West::LOW:
return 20169;
case Properties::West::TALL:
return 20170;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20171;
case Properties::West::LOW:
return 20172;
case Properties::West::TALL:
return 20173;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20174;
case Properties::West::LOW:
return 20175;
case Properties::West::TALL:
return 20176;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20177;
case Properties::West::LOW:
return 20178;
case Properties::West::TALL:
return 20179;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20180;
case Properties::West::LOW:
return 20181;
case Properties::West::TALL:
return 20182;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20183;
case Properties::West::LOW:
return 20184;
case Properties::West::TALL:
return 20185;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20186;
case Properties::West::LOW:
return 20187;
case Properties::West::TALL:
return 20188;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20189;
case Properties::West::LOW:
return 20190;
case Properties::West::TALL:
return 20191;
}
}
}
}
}
}
return 0;
}
}

namespace Cobblestone {
constexpr Block toProtocol() {
return 14;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9113;
case Properties::Waterlogged::FALSE:
return 9114;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9115;
case Properties::Waterlogged::FALSE:
return 9116;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9117;
case Properties::Waterlogged::FALSE:
return 9118;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3952;
case Properties::Waterlogged::FALSE:
return 3953;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3954;
case Properties::Waterlogged::FALSE:
return 3955;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3956;
case Properties::Waterlogged::FALSE:
return 3957;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3958;
case Properties::Waterlogged::FALSE:
return 3959;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3960;
case Properties::Waterlogged::FALSE:
return 3961;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3962;
case Properties::Waterlogged::FALSE:
return 3963;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3964;
case Properties::Waterlogged::FALSE:
return 3965;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3966;
case Properties::Waterlogged::FALSE:
return 3967;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3968;
case Properties::Waterlogged::FALSE:
return 3969;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3970;
case Properties::Waterlogged::FALSE:
return 3971;
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
return 3972;
case Properties::Waterlogged::FALSE:
return 3973;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3974;
case Properties::Waterlogged::FALSE:
return 3975;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3976;
case Properties::Waterlogged::FALSE:
return 3977;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3978;
case Properties::Waterlogged::FALSE:
return 3979;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3980;
case Properties::Waterlogged::FALSE:
return 3981;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3982;
case Properties::Waterlogged::FALSE:
return 3983;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3984;
case Properties::Waterlogged::FALSE:
return 3985;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3986;
case Properties::Waterlogged::FALSE:
return 3987;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3988;
case Properties::Waterlogged::FALSE:
return 3989;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3990;
case Properties::Waterlogged::FALSE:
return 3991;
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
return 3992;
case Properties::Waterlogged::FALSE:
return 3993;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3994;
case Properties::Waterlogged::FALSE:
return 3995;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3996;
case Properties::Waterlogged::FALSE:
return 3997;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3998;
case Properties::Waterlogged::FALSE:
return 3999;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4000;
case Properties::Waterlogged::FALSE:
return 4001;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4002;
case Properties::Waterlogged::FALSE:
return 4003;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4004;
case Properties::Waterlogged::FALSE:
return 4005;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4006;
case Properties::Waterlogged::FALSE:
return 4007;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4008;
case Properties::Waterlogged::FALSE:
return 4009;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4010;
case Properties::Waterlogged::FALSE:
return 4011;
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
return 4012;
case Properties::Waterlogged::FALSE:
return 4013;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4014;
case Properties::Waterlogged::FALSE:
return 4015;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4016;
case Properties::Waterlogged::FALSE:
return 4017;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4018;
case Properties::Waterlogged::FALSE:
return 4019;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4020;
case Properties::Waterlogged::FALSE:
return 4021;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4022;
case Properties::Waterlogged::FALSE:
return 4023;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4024;
case Properties::Waterlogged::FALSE:
return 4025;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4026;
case Properties::Waterlogged::FALSE:
return 4027;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4028;
case Properties::Waterlogged::FALSE:
return 4029;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4030;
case Properties::Waterlogged::FALSE:
return 4031;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6249;
case Properties::West::LOW:
return 6250;
case Properties::West::TALL:
return 6251;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6252;
case Properties::West::LOW:
return 6253;
case Properties::West::TALL:
return 6254;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6255;
case Properties::West::LOW:
return 6256;
case Properties::West::TALL:
return 6257;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6258;
case Properties::West::LOW:
return 6259;
case Properties::West::TALL:
return 6260;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6261;
case Properties::West::LOW:
return 6262;
case Properties::West::TALL:
return 6263;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6264;
case Properties::West::LOW:
return 6265;
case Properties::West::TALL:
return 6266;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6267;
case Properties::West::LOW:
return 6268;
case Properties::West::TALL:
return 6269;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6270;
case Properties::West::LOW:
return 6271;
case Properties::West::TALL:
return 6272;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6273;
case Properties::West::LOW:
return 6274;
case Properties::West::TALL:
return 6275;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6276;
case Properties::West::LOW:
return 6277;
case Properties::West::TALL:
return 6278;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6279;
case Properties::West::LOW:
return 6280;
case Properties::West::TALL:
return 6281;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6282;
case Properties::West::LOW:
return 6283;
case Properties::West::TALL:
return 6284;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6285;
case Properties::West::LOW:
return 6286;
case Properties::West::TALL:
return 6287;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6288;
case Properties::West::LOW:
return 6289;
case Properties::West::TALL:
return 6290;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6291;
case Properties::West::LOW:
return 6292;
case Properties::West::TALL:
return 6293;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6294;
case Properties::West::LOW:
return 6295;
case Properties::West::TALL:
return 6296;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6297;
case Properties::West::LOW:
return 6298;
case Properties::West::TALL:
return 6299;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6300;
case Properties::West::LOW:
return 6301;
case Properties::West::TALL:
return 6302;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6303;
case Properties::West::LOW:
return 6304;
case Properties::West::TALL:
return 6305;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6306;
case Properties::West::LOW:
return 6307;
case Properties::West::TALL:
return 6308;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6309;
case Properties::West::LOW:
return 6310;
case Properties::West::TALL:
return 6311;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6312;
case Properties::West::LOW:
return 6313;
case Properties::West::TALL:
return 6314;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6315;
case Properties::West::LOW:
return 6316;
case Properties::West::TALL:
return 6317;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6318;
case Properties::West::LOW:
return 6319;
case Properties::West::TALL:
return 6320;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6321;
case Properties::West::LOW:
return 6322;
case Properties::West::TALL:
return 6323;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6324;
case Properties::West::LOW:
return 6325;
case Properties::West::TALL:
return 6326;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6327;
case Properties::West::LOW:
return 6328;
case Properties::West::TALL:
return 6329;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6330;
case Properties::West::LOW:
return 6331;
case Properties::West::TALL:
return 6332;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6333;
case Properties::West::LOW:
return 6334;
case Properties::West::TALL:
return 6335;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6336;
case Properties::West::LOW:
return 6337;
case Properties::West::TALL:
return 6338;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6339;
case Properties::West::LOW:
return 6340;
case Properties::West::TALL:
return 6341;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6342;
case Properties::West::LOW:
return 6343;
case Properties::West::TALL:
return 6344;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6345;
case Properties::West::LOW:
return 6346;
case Properties::West::TALL:
return 6347;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6348;
case Properties::West::LOW:
return 6349;
case Properties::West::TALL:
return 6350;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6351;
case Properties::West::LOW:
return 6352;
case Properties::West::TALL:
return 6353;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6354;
case Properties::West::LOW:
return 6355;
case Properties::West::TALL:
return 6356;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6357;
case Properties::West::LOW:
return 6358;
case Properties::West::TALL:
return 6359;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6360;
case Properties::West::LOW:
return 6361;
case Properties::West::TALL:
return 6362;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6363;
case Properties::West::LOW:
return 6364;
case Properties::West::TALL:
return 6365;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6366;
case Properties::West::LOW:
return 6367;
case Properties::West::TALL:
return 6368;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6369;
case Properties::West::LOW:
return 6370;
case Properties::West::TALL:
return 6371;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6372;
case Properties::West::LOW:
return 6373;
case Properties::West::TALL:
return 6374;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6375;
case Properties::West::LOW:
return 6376;
case Properties::West::TALL:
return 6377;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6378;
case Properties::West::LOW:
return 6379;
case Properties::West::TALL:
return 6380;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6381;
case Properties::West::LOW:
return 6382;
case Properties::West::TALL:
return 6383;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6384;
case Properties::West::LOW:
return 6385;
case Properties::West::TALL:
return 6386;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6387;
case Properties::West::LOW:
return 6388;
case Properties::West::TALL:
return 6389;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6390;
case Properties::West::LOW:
return 6391;
case Properties::West::TALL:
return 6392;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6393;
case Properties::West::LOW:
return 6394;
case Properties::West::TALL:
return 6395;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6396;
case Properties::West::LOW:
return 6397;
case Properties::West::TALL:
return 6398;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6399;
case Properties::West::LOW:
return 6400;
case Properties::West::TALL:
return 6401;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6402;
case Properties::West::LOW:
return 6403;
case Properties::West::TALL:
return 6404;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6405;
case Properties::West::LOW:
return 6406;
case Properties::West::TALL:
return 6407;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6408;
case Properties::West::LOW:
return 6409;
case Properties::West::TALL:
return 6410;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6411;
case Properties::West::LOW:
return 6412;
case Properties::West::TALL:
return 6413;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6414;
case Properties::West::LOW:
return 6415;
case Properties::West::TALL:
return 6416;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6417;
case Properties::West::LOW:
return 6418;
case Properties::West::TALL:
return 6419;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6420;
case Properties::West::LOW:
return 6421;
case Properties::West::TALL:
return 6422;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6423;
case Properties::West::LOW:
return 6424;
case Properties::West::TALL:
return 6425;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6426;
case Properties::West::LOW:
return 6427;
case Properties::West::TALL:
return 6428;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6429;
case Properties::West::LOW:
return 6430;
case Properties::West::TALL:
return 6431;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6432;
case Properties::West::LOW:
return 6433;
case Properties::West::TALL:
return 6434;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6435;
case Properties::West::LOW:
return 6436;
case Properties::West::TALL:
return 6437;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6438;
case Properties::West::LOW:
return 6439;
case Properties::West::TALL:
return 6440;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6441;
case Properties::West::LOW:
return 6442;
case Properties::West::TALL:
return 6443;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6444;
case Properties::West::LOW:
return 6445;
case Properties::West::TALL:
return 6446;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6447;
case Properties::West::LOW:
return 6448;
case Properties::West::TALL:
return 6449;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6450;
case Properties::West::LOW:
return 6451;
case Properties::West::TALL:
return 6452;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6453;
case Properties::West::LOW:
return 6454;
case Properties::West::TALL:
return 6455;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6456;
case Properties::West::LOW:
return 6457;
case Properties::West::TALL:
return 6458;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6459;
case Properties::West::LOW:
return 6460;
case Properties::West::TALL:
return 6461;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6462;
case Properties::West::LOW:
return 6463;
case Properties::West::TALL:
return 6464;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6465;
case Properties::West::LOW:
return 6466;
case Properties::West::TALL:
return 6467;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6468;
case Properties::West::LOW:
return 6469;
case Properties::West::TALL:
return 6470;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6471;
case Properties::West::LOW:
return 6472;
case Properties::West::TALL:
return 6473;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6474;
case Properties::West::LOW:
return 6475;
case Properties::West::TALL:
return 6476;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6477;
case Properties::West::LOW:
return 6478;
case Properties::West::TALL:
return 6479;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6480;
case Properties::West::LOW:
return 6481;
case Properties::West::TALL:
return 6482;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6483;
case Properties::West::LOW:
return 6484;
case Properties::West::TALL:
return 6485;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6486;
case Properties::West::LOW:
return 6487;
case Properties::West::TALL:
return 6488;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6489;
case Properties::West::LOW:
return 6490;
case Properties::West::TALL:
return 6491;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6492;
case Properties::West::LOW:
return 6493;
case Properties::West::TALL:
return 6494;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6495;
case Properties::West::LOW:
return 6496;
case Properties::West::TALL:
return 6497;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6498;
case Properties::West::LOW:
return 6499;
case Properties::West::TALL:
return 6500;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6501;
case Properties::West::LOW:
return 6502;
case Properties::West::TALL:
return 6503;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6504;
case Properties::West::LOW:
return 6505;
case Properties::West::TALL:
return 6506;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6507;
case Properties::West::LOW:
return 6508;
case Properties::West::TALL:
return 6509;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6510;
case Properties::West::LOW:
return 6511;
case Properties::West::TALL:
return 6512;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6513;
case Properties::West::LOW:
return 6514;
case Properties::West::TALL:
return 6515;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6516;
case Properties::West::LOW:
return 6517;
case Properties::West::TALL:
return 6518;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6519;
case Properties::West::LOW:
return 6520;
case Properties::West::TALL:
return 6521;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6522;
case Properties::West::LOW:
return 6523;
case Properties::West::TALL:
return 6524;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6525;
case Properties::West::LOW:
return 6526;
case Properties::West::TALL:
return 6527;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6528;
case Properties::West::LOW:
return 6529;
case Properties::West::TALL:
return 6530;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6531;
case Properties::West::LOW:
return 6532;
case Properties::West::TALL:
return 6533;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6534;
case Properties::West::LOW:
return 6535;
case Properties::West::TALL:
return 6536;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6537;
case Properties::West::LOW:
return 6538;
case Properties::West::TALL:
return 6539;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6540;
case Properties::West::LOW:
return 6541;
case Properties::West::TALL:
return 6542;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6543;
case Properties::West::LOW:
return 6544;
case Properties::West::TALL:
return 6545;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6546;
case Properties::West::LOW:
return 6547;
case Properties::West::TALL:
return 6548;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6549;
case Properties::West::LOW:
return 6550;
case Properties::West::TALL:
return 6551;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6552;
case Properties::West::LOW:
return 6553;
case Properties::West::TALL:
return 6554;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6555;
case Properties::West::LOW:
return 6556;
case Properties::West::TALL:
return 6557;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6558;
case Properties::West::LOW:
return 6559;
case Properties::West::TALL:
return 6560;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6561;
case Properties::West::LOW:
return 6562;
case Properties::West::TALL:
return 6563;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6564;
case Properties::West::LOW:
return 6565;
case Properties::West::TALL:
return 6566;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6567;
case Properties::West::LOW:
return 6568;
case Properties::West::TALL:
return 6569;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6570;
case Properties::West::LOW:
return 6571;
case Properties::West::TALL:
return 6572;
}
}
}
}
}
}
return 0;
}
}

namespace Cobweb {
constexpr Block toProtocol() {
return 1595;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age, Properties::Facing facing) {
switch (age) {
case Properties::Age::ZERO:
switch (facing) {
case Properties::Facing::NORTH:
return 5749;
case Properties::Facing::SOUTH:
return 5750;
case Properties::Facing::WEST:
return 5751;
case Properties::Facing::EAST:
return 5752;
}
case Properties::Age::ONE:
switch (facing) {
case Properties::Facing::NORTH:
return 5753;
case Properties::Facing::SOUTH:
return 5754;
case Properties::Facing::WEST:
return 5755;
case Properties::Facing::EAST:
return 5756;
}
case Properties::Age::TWO:
switch (facing) {
case Properties::Facing::NORTH:
return 5757;
case Properties::Facing::SOUTH:
return 5758;
case Properties::Facing::WEST:
return 5759;
case Properties::Facing::EAST:
return 5760;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Conditional conditional, Properties::Facing facing) {
switch (conditional) {
case Properties::Conditional::TRUE:
switch (facing) {
case Properties::Facing::NORTH:
return 6236;
case Properties::Facing::EAST:
return 6237;
case Properties::Facing::SOUTH:
return 6238;
case Properties::Facing::WEST:
return 6239;
case Properties::Facing::UP:
return 6240;
case Properties::Facing::DOWN:
return 6241;
}
case Properties::Conditional::FALSE:
switch (facing) {
case Properties::Facing::NORTH:
return 6242;
case Properties::Facing::EAST:
return 6243;
case Properties::Facing::SOUTH:
return 6244;
case Properties::Facing::WEST:
return 6245;
case Properties::Facing::UP:
return 6246;
case Properties::Facing::DOWN:
return 6247;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Mode mode, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (mode) {
case Properties::Mode::COMPARE:
switch (powered) {
case Properties::Powered::TRUE:
return 7295;
case Properties::Powered::FALSE:
return 7296;
}
case Properties::Mode::SUBTRACT:
switch (powered) {
case Properties::Powered::TRUE:
return 7297;
case Properties::Powered::FALSE:
return 7298;
}
}
case Properties::Facing::SOUTH:
switch (mode) {
case Properties::Mode::COMPARE:
switch (powered) {
case Properties::Powered::TRUE:
return 7299;
case Properties::Powered::FALSE:
return 7300;
}
case Properties::Mode::SUBTRACT:
switch (powered) {
case Properties::Powered::TRUE:
return 7301;
case Properties::Powered::FALSE:
return 7302;
}
}
case Properties::Facing::WEST:
switch (mode) {
case Properties::Mode::COMPARE:
switch (powered) {
case Properties::Powered::TRUE:
return 7303;
case Properties::Powered::FALSE:
return 7304;
}
case Properties::Mode::SUBTRACT:
switch (powered) {
case Properties::Powered::TRUE:
return 7305;
case Properties::Powered::FALSE:
return 7306;
}
}
case Properties::Facing::EAST:
switch (mode) {
case Properties::Mode::COMPARE:
switch (powered) {
case Properties::Powered::TRUE:
return 7307;
case Properties::Powered::FALSE:
return 7308;
}
case Properties::Mode::SUBTRACT:
switch (powered) {
case Properties::Powered::TRUE:
return 7309;
case Properties::Powered::FALSE:
return 7310;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Level level) {
switch (level) {
case Properties::Level::ZERO:
return 16960;
case Properties::Level::ONE:
return 16961;
case Properties::Level::TWO:
return 16962;
case Properties::Level::THREE:
return 16963;
case Properties::Level::FOUR:
return 16964;
case Properties::Level::FIVE:
return 16965;
case Properties::Level::SIX:
return 16966;
case Properties::Level::SEVEN:
return 16967;
case Properties::Level::EIGHT:
return 16968;
}
return 0;
}
}

namespace Conduit {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10530;
case Properties::Waterlogged::FALSE:
return 10531;
}
return 0;
}
}

namespace CopperBlock {
constexpr Block toProtocol() {
return 18911;
return 0;
}
}

namespace CopperOre {
constexpr Block toProtocol() {
return 18912;
return 0;
}
}

namespace Cornflower {
constexpr Block toProtocol() {
return 1676;
return 0;
}
}

namespace CrackedDeepslateBricks {
constexpr Block toProtocol() {
return 21426;
return 0;
}
}

namespace CrackedDeepslateTiles {
constexpr Block toProtocol() {
return 21427;
return 0;
}
}

namespace CrackedNetherBricks {
constexpr Block toProtocol() {
return 18311;
return 0;
}
}

namespace CrackedPolishedBlackstoneBricks {
constexpr Block toProtocol() {
return 17461;
return 0;
}
}

namespace CrackedStoneBricks {
constexpr Block toProtocol() {
return 4870;
return 0;
}
}

namespace CraftingTable {
constexpr Block toProtocol() {
return 3611;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 7187;
case Properties::Rotation::ONE:
return 7188;
case Properties::Rotation::TWO:
return 7189;
case Properties::Rotation::THREE:
return 7190;
case Properties::Rotation::FOUR:
return 7191;
case Properties::Rotation::FIVE:
return 7192;
case Properties::Rotation::SIX:
return 7193;
case Properties::Rotation::SEVEN:
return 7194;
case Properties::Rotation::EIGHT:
return 7195;
case Properties::Rotation::NINE:
return 7196;
case Properties::Rotation::TEN:
return 7197;
case Properties::Rotation::ELEVEN:
return 7198;
case Properties::Rotation::TWELVE:
return 7199;
case Properties::Rotation::THIRTEEN:
return 7200;
case Properties::Rotation::FOURTEEN:
return 7201;
case Properties::Rotation::FIFTEEN:
return 7202;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 7203;
case Properties::Facing::SOUTH:
return 7204;
case Properties::Facing::WEST:
return 7205;
case Properties::Facing::EAST:
return 7206;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16688;
case Properties::Powered::FALSE:
return 16689;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16690;
case Properties::Powered::FALSE:
return 16691;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16692;
case Properties::Powered::FALSE:
return 16693;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16694;
case Properties::Powered::FALSE:
return 16695;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16696;
case Properties::Powered::FALSE:
return 16697;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16698;
case Properties::Powered::FALSE:
return 16699;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16700;
case Properties::Powered::FALSE:
return 16701;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16702;
case Properties::Powered::FALSE:
return 16703;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16704;
case Properties::Powered::FALSE:
return 16705;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 16706;
case Properties::Powered::FALSE:
return 16707;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 16708;
case Properties::Powered::FALSE:
return 16709;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 16710;
case Properties::Powered::FALSE:
return 16711;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16736;
case Properties::Powered::FALSE:
return 16737;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16738;
case Properties::Powered::FALSE:
return 16739;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16740;
case Properties::Powered::FALSE:
return 16741;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16742;
case Properties::Powered::FALSE:
return 16743;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16744;
case Properties::Powered::FALSE:
return 16745;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16746;
case Properties::Powered::FALSE:
return 16747;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16748;
case Properties::Powered::FALSE:
return 16749;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16750;
case Properties::Powered::FALSE:
return 16751;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16752;
case Properties::Powered::FALSE:
return 16753;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16754;
case Properties::Powered::FALSE:
return 16755;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16756;
case Properties::Powered::FALSE:
return 16757;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16758;
case Properties::Powered::FALSE:
return 16759;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16760;
case Properties::Powered::FALSE:
return 16761;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16762;
case Properties::Powered::FALSE:
return 16763;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16764;
case Properties::Powered::FALSE:
return 16765;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16766;
case Properties::Powered::FALSE:
return 16767;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16768;
case Properties::Powered::FALSE:
return 16769;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16770;
case Properties::Powered::FALSE:
return 16771;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16772;
case Properties::Powered::FALSE:
return 16773;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16774;
case Properties::Powered::FALSE:
return 16775;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16776;
case Properties::Powered::FALSE:
return 16777;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16778;
case Properties::Powered::FALSE:
return 16779;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16780;
case Properties::Powered::FALSE:
return 16781;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16782;
case Properties::Powered::FALSE:
return 16783;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16784;
case Properties::Powered::FALSE:
return 16785;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16786;
case Properties::Powered::FALSE:
return 16787;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16788;
case Properties::Powered::FALSE:
return 16789;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16790;
case Properties::Powered::FALSE:
return 16791;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16792;
case Properties::Powered::FALSE:
return 16793;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16794;
case Properties::Powered::FALSE:
return 16795;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16796;
case Properties::Powered::FALSE:
return 16797;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16798;
case Properties::Powered::FALSE:
return 16799;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 16272;
case Properties::West::FALSE:
return 16273;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16274;
case Properties::West::FALSE:
return 16275;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 16276;
case Properties::West::FALSE:
return 16277;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16278;
case Properties::West::FALSE:
return 16279;
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
return 16280;
case Properties::West::FALSE:
return 16281;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16282;
case Properties::West::FALSE:
return 16283;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 16284;
case Properties::West::FALSE:
return 16285;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16286;
case Properties::West::FALSE:
return 16287;
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
return 16288;
case Properties::West::FALSE:
return 16289;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16290;
case Properties::West::FALSE:
return 16291;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 16292;
case Properties::West::FALSE:
return 16293;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16294;
case Properties::West::FALSE:
return 16295;
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
return 16296;
case Properties::West::FALSE:
return 16297;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16298;
case Properties::West::FALSE:
return 16299;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 16300;
case Properties::West::FALSE:
return 16301;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 16302;
case Properties::West::FALSE:
return 16303;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16464;
case Properties::Powered::FALSE:
return 16465;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16466;
case Properties::Powered::FALSE:
return 16467;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16468;
case Properties::Powered::FALSE:
return 16469;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16470;
case Properties::Powered::FALSE:
return 16471;
}
}
}
case Properties::Facing::SOUTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16472;
case Properties::Powered::FALSE:
return 16473;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16474;
case Properties::Powered::FALSE:
return 16475;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16476;
case Properties::Powered::FALSE:
return 16477;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16478;
case Properties::Powered::FALSE:
return 16479;
}
}
}
case Properties::Facing::WEST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16480;
case Properties::Powered::FALSE:
return 16481;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16482;
case Properties::Powered::FALSE:
return 16483;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16484;
case Properties::Powered::FALSE:
return 16485;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16486;
case Properties::Powered::FALSE:
return 16487;
}
}
}
case Properties::Facing::EAST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16488;
case Properties::Powered::FALSE:
return 16489;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16490;
case Properties::Powered::FALSE:
return 16491;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16492;
case Properties::Powered::FALSE:
return 16493;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16494;
case Properties::Powered::FALSE:
return 16495;
}
}
}
}
return 0;
}
}

namespace CrimsonFungus {
constexpr Block toProtocol() {
return 16197;
return 0;
}
}

namespace CrimsonHyphae {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 16190;
case Properties::Axis::Y:
return 16191;
case Properties::Axis::Z:
return 16192;
}
return 0;
}
}

namespace CrimsonNylium {
constexpr Block toProtocol() {
return 16196;
return 0;
}
}

namespace CrimsonPlanks {
constexpr Block toProtocol() {
return 16254;
return 0;
}
}

namespace CrimsonPressurePlate {
namespace Properties {
enum class Powered {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Powered powered) {
switch (powered) {
case Properties::Powered::TRUE:
return 16268;
case Properties::Powered::FALSE:
return 16269;
}
return 0;
}
}

namespace CrimsonRoots {
constexpr Block toProtocol() {
return 16253;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
switch (rotation) {
case Properties::Rotation::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16864;
case Properties::Waterlogged::FALSE:
return 16865;
}
case Properties::Rotation::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16866;
case Properties::Waterlogged::FALSE:
return 16867;
}
case Properties::Rotation::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16868;
case Properties::Waterlogged::FALSE:
return 16869;
}
case Properties::Rotation::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16870;
case Properties::Waterlogged::FALSE:
return 16871;
}
case Properties::Rotation::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16872;
case Properties::Waterlogged::FALSE:
return 16873;
}
case Properties::Rotation::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16874;
case Properties::Waterlogged::FALSE:
return 16875;
}
case Properties::Rotation::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16876;
case Properties::Waterlogged::FALSE:
return 16877;
}
case Properties::Rotation::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16878;
case Properties::Waterlogged::FALSE:
return 16879;
}
case Properties::Rotation::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16880;
case Properties::Waterlogged::FALSE:
return 16881;
}
case Properties::Rotation::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16882;
case Properties::Waterlogged::FALSE:
return 16883;
}
case Properties::Rotation::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16884;
case Properties::Waterlogged::FALSE:
return 16885;
}
case Properties::Rotation::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16886;
case Properties::Waterlogged::FALSE:
return 16887;
}
case Properties::Rotation::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16888;
case Properties::Waterlogged::FALSE:
return 16889;
}
case Properties::Rotation::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16890;
case Properties::Waterlogged::FALSE:
return 16891;
}
case Properties::Rotation::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16892;
case Properties::Waterlogged::FALSE:
return 16893;
}
case Properties::Rotation::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16894;
case Properties::Waterlogged::FALSE:
return 16895;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16256;
case Properties::Waterlogged::FALSE:
return 16257;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16258;
case Properties::Waterlogged::FALSE:
return 16259;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16260;
case Properties::Waterlogged::FALSE:
return 16261;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16528;
case Properties::Waterlogged::FALSE:
return 16529;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16530;
case Properties::Waterlogged::FALSE:
return 16531;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16532;
case Properties::Waterlogged::FALSE:
return 16533;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16534;
case Properties::Waterlogged::FALSE:
return 16535;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16536;
case Properties::Waterlogged::FALSE:
return 16537;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16538;
case Properties::Waterlogged::FALSE:
return 16539;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16540;
case Properties::Waterlogged::FALSE:
return 16541;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16542;
case Properties::Waterlogged::FALSE:
return 16543;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16544;
case Properties::Waterlogged::FALSE:
return 16545;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16546;
case Properties::Waterlogged::FALSE:
return 16547;
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
return 16548;
case Properties::Waterlogged::FALSE:
return 16549;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16550;
case Properties::Waterlogged::FALSE:
return 16551;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16552;
case Properties::Waterlogged::FALSE:
return 16553;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16554;
case Properties::Waterlogged::FALSE:
return 16555;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16556;
case Properties::Waterlogged::FALSE:
return 16557;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16558;
case Properties::Waterlogged::FALSE:
return 16559;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16560;
case Properties::Waterlogged::FALSE:
return 16561;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16562;
case Properties::Waterlogged::FALSE:
return 16563;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16564;
case Properties::Waterlogged::FALSE:
return 16565;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16566;
case Properties::Waterlogged::FALSE:
return 16567;
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
return 16568;
case Properties::Waterlogged::FALSE:
return 16569;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16570;
case Properties::Waterlogged::FALSE:
return 16571;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16572;
case Properties::Waterlogged::FALSE:
return 16573;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16574;
case Properties::Waterlogged::FALSE:
return 16575;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16576;
case Properties::Waterlogged::FALSE:
return 16577;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16578;
case Properties::Waterlogged::FALSE:
return 16579;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16580;
case Properties::Waterlogged::FALSE:
return 16581;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16582;
case Properties::Waterlogged::FALSE:
return 16583;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16584;
case Properties::Waterlogged::FALSE:
return 16585;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16586;
case Properties::Waterlogged::FALSE:
return 16587;
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
return 16588;
case Properties::Waterlogged::FALSE:
return 16589;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16590;
case Properties::Waterlogged::FALSE:
return 16591;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16592;
case Properties::Waterlogged::FALSE:
return 16593;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16594;
case Properties::Waterlogged::FALSE:
return 16595;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16596;
case Properties::Waterlogged::FALSE:
return 16597;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16598;
case Properties::Waterlogged::FALSE:
return 16599;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16600;
case Properties::Waterlogged::FALSE:
return 16601;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16602;
case Properties::Waterlogged::FALSE:
return 16603;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16604;
case Properties::Waterlogged::FALSE:
return 16605;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16606;
case Properties::Waterlogged::FALSE:
return 16607;
}
}
}
}
return 0;
}
}

namespace CrimsonStem {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 16184;
case Properties::Axis::Y:
return 16185;
case Properties::Axis::Z:
return 16186;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16336;
case Properties::Waterlogged::FALSE:
return 16337;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16338;
case Properties::Waterlogged::FALSE:
return 16339;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16340;
case Properties::Waterlogged::FALSE:
return 16341;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16342;
case Properties::Waterlogged::FALSE:
return 16343;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16344;
case Properties::Waterlogged::FALSE:
return 16345;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16346;
case Properties::Waterlogged::FALSE:
return 16347;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16348;
case Properties::Waterlogged::FALSE:
return 16349;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16350;
case Properties::Waterlogged::FALSE:
return 16351;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16352;
case Properties::Waterlogged::FALSE:
return 16353;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16354;
case Properties::Waterlogged::FALSE:
return 16355;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16356;
case Properties::Waterlogged::FALSE:
return 16357;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16358;
case Properties::Waterlogged::FALSE:
return 16359;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16360;
case Properties::Waterlogged::FALSE:
return 16361;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16362;
case Properties::Waterlogged::FALSE:
return 16363;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16364;
case Properties::Waterlogged::FALSE:
return 16365;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16366;
case Properties::Waterlogged::FALSE:
return 16367;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16368;
case Properties::Waterlogged::FALSE:
return 16369;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16370;
case Properties::Waterlogged::FALSE:
return 16371;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16372;
case Properties::Waterlogged::FALSE:
return 16373;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16374;
case Properties::Waterlogged::FALSE:
return 16375;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16376;
case Properties::Waterlogged::FALSE:
return 16377;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16378;
case Properties::Waterlogged::FALSE:
return 16379;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16380;
case Properties::Waterlogged::FALSE:
return 16381;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16382;
case Properties::Waterlogged::FALSE:
return 16383;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16384;
case Properties::Waterlogged::FALSE:
return 16385;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16386;
case Properties::Waterlogged::FALSE:
return 16387;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16388;
case Properties::Waterlogged::FALSE:
return 16389;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16390;
case Properties::Waterlogged::FALSE:
return 16391;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16392;
case Properties::Waterlogged::FALSE:
return 16393;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16394;
case Properties::Waterlogged::FALSE:
return 16395;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16396;
case Properties::Waterlogged::FALSE:
return 16397;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16398;
case Properties::Waterlogged::FALSE:
return 16399;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16928;
case Properties::Waterlogged::FALSE:
return 16929;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16930;
case Properties::Waterlogged::FALSE:
return 16931;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16932;
case Properties::Waterlogged::FALSE:
return 16933;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16934;
case Properties::Waterlogged::FALSE:
return 16935;
}
}
return 0;
}
}

namespace CryingObsidian {
constexpr Block toProtocol() {
return 17037;
return 0;
}
}

namespace CutCopper {
constexpr Block toProtocol() {
return 18917;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19256;
case Properties::Waterlogged::FALSE:
return 19257;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19258;
case Properties::Waterlogged::FALSE:
return 19259;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19260;
case Properties::Waterlogged::FALSE:
return 19261;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19158;
case Properties::Waterlogged::FALSE:
return 19159;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19160;
case Properties::Waterlogged::FALSE:
return 19161;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19162;
case Properties::Waterlogged::FALSE:
return 19163;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19164;
case Properties::Waterlogged::FALSE:
return 19165;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19166;
case Properties::Waterlogged::FALSE:
return 19167;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19168;
case Properties::Waterlogged::FALSE:
return 19169;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19170;
case Properties::Waterlogged::FALSE:
return 19171;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19172;
case Properties::Waterlogged::FALSE:
return 19173;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19174;
case Properties::Waterlogged::FALSE:
return 19175;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19176;
case Properties::Waterlogged::FALSE:
return 19177;
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
return 19178;
case Properties::Waterlogged::FALSE:
return 19179;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19180;
case Properties::Waterlogged::FALSE:
return 19181;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19182;
case Properties::Waterlogged::FALSE:
return 19183;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19184;
case Properties::Waterlogged::FALSE:
return 19185;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19186;
case Properties::Waterlogged::FALSE:
return 19187;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19188;
case Properties::Waterlogged::FALSE:
return 19189;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19190;
case Properties::Waterlogged::FALSE:
return 19191;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19192;
case Properties::Waterlogged::FALSE:
return 19193;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19194;
case Properties::Waterlogged::FALSE:
return 19195;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19196;
case Properties::Waterlogged::FALSE:
return 19197;
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
return 19198;
case Properties::Waterlogged::FALSE:
return 19199;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19200;
case Properties::Waterlogged::FALSE:
return 19201;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19202;
case Properties::Waterlogged::FALSE:
return 19203;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19204;
case Properties::Waterlogged::FALSE:
return 19205;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19206;
case Properties::Waterlogged::FALSE:
return 19207;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19208;
case Properties::Waterlogged::FALSE:
return 19209;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19210;
case Properties::Waterlogged::FALSE:
return 19211;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19212;
case Properties::Waterlogged::FALSE:
return 19213;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19214;
case Properties::Waterlogged::FALSE:
return 19215;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19216;
case Properties::Waterlogged::FALSE:
return 19217;
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
return 19218;
case Properties::Waterlogged::FALSE:
return 19219;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19220;
case Properties::Waterlogged::FALSE:
return 19221;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19222;
case Properties::Waterlogged::FALSE:
return 19223;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19224;
case Properties::Waterlogged::FALSE:
return 19225;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19226;
case Properties::Waterlogged::FALSE:
return 19227;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19228;
case Properties::Waterlogged::FALSE:
return 19229;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19230;
case Properties::Waterlogged::FALSE:
return 19231;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19232;
case Properties::Waterlogged::FALSE:
return 19233;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19234;
case Properties::Waterlogged::FALSE:
return 19235;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19236;
case Properties::Waterlogged::FALSE:
return 19237;
}
}
}
}
return 0;
}
}

namespace CutRedSandstone {
constexpr Block toProtocol() {
return 8960;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9155;
case Properties::Waterlogged::FALSE:
return 9156;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9157;
case Properties::Waterlogged::FALSE:
return 9158;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9159;
case Properties::Waterlogged::FALSE:
return 9160;
}
}
return 0;
}
}

namespace CutSandstone {
constexpr Block toProtocol() {
return 478;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9101;
case Properties::Waterlogged::FALSE:
return 9102;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9103;
case Properties::Waterlogged::FALSE:
return 9104;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9105;
case Properties::Waterlogged::FALSE:
return 9106;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8782;
case Properties::Rotation::ONE:
return 8783;
case Properties::Rotation::TWO:
return 8784;
case Properties::Rotation::THREE:
return 8785;
case Properties::Rotation::FOUR:
return 8786;
case Properties::Rotation::FIVE:
return 8787;
case Properties::Rotation::SIX:
return 8788;
case Properties::Rotation::SEVEN:
return 8789;
case Properties::Rotation::EIGHT:
return 8790;
case Properties::Rotation::NINE:
return 8791;
case Properties::Rotation::TEN:
return 8792;
case Properties::Rotation::ELEVEN:
return 8793;
case Properties::Rotation::TWELVE:
return 8794;
case Properties::Rotation::THIRTEEN:
return 8795;
case Properties::Rotation::FOURTEEN:
return 8796;
case Properties::Rotation::FIFTEEN:
return 8797;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1423;
case Properties::Part::FOOT:
return 1424;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1425;
case Properties::Part::FOOT:
return 1426;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1427;
case Properties::Part::FOOT:
return 1428;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1429;
case Properties::Part::FOOT:
return 1430;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1431;
case Properties::Part::FOOT:
return 1432;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1433;
case Properties::Part::FOOT:
return 1434;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1435;
case Properties::Part::FOOT:
return 1436;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1437;
case Properties::Part::FOOT:
return 1438;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18473;
case Properties::Waterlogged::FALSE:
return 18474;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18475;
case Properties::Waterlogged::FALSE:
return 18476;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18477;
case Properties::Waterlogged::FALSE:
return 18478;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18479;
case Properties::Waterlogged::FALSE:
return 18480;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18481;
case Properties::Waterlogged::FALSE:
return 18482;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18483;
case Properties::Waterlogged::FALSE:
return 18484;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18485;
case Properties::Waterlogged::FALSE:
return 18486;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18487;
case Properties::Waterlogged::FALSE:
return 18488;
}
}
}
return 0;
}
}

namespace CyanCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18605;
case Properties::Lit::FALSE:
return 18606;
}
return 0;
}
}

namespace CyanCarpet {
constexpr Block toProtocol() {
return 8616;
return 0;
}
}

namespace CyanConcrete {
constexpr Block toProtocol() {
return 10328;
return 0;
}
}

namespace CyanConcretePowder {
constexpr Block toProtocol() {
return 10344;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10291;
case Properties::Facing::SOUTH:
return 10292;
case Properties::Facing::WEST:
return 10293;
case Properties::Facing::EAST:
return 10294;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10213;
case Properties::Facing::EAST:
return 10214;
case Properties::Facing::SOUTH:
return 10215;
case Properties::Facing::WEST:
return 10216;
case Properties::Facing::UP:
return 10217;
case Properties::Facing::DOWN:
return 10218;
}
return 0;
}
}

namespace CyanStainedGlass {
constexpr Block toProtocol() {
return 4413;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7780;
case Properties::West::FALSE:
return 7781;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7782;
case Properties::West::FALSE:
return 7783;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7784;
case Properties::West::FALSE:
return 7785;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7786;
case Properties::West::FALSE:
return 7787;
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
return 7788;
case Properties::West::FALSE:
return 7789;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7790;
case Properties::West::FALSE:
return 7791;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7792;
case Properties::West::FALSE:
return 7793;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7794;
case Properties::West::FALSE:
return 7795;
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
return 7796;
case Properties::West::FALSE:
return 7797;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7798;
case Properties::West::FALSE:
return 7799;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7800;
case Properties::West::FALSE:
return 7801;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7802;
case Properties::West::FALSE:
return 7803;
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
return 7804;
case Properties::West::FALSE:
return 7805;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7806;
case Properties::West::FALSE:
return 7807;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7808;
case Properties::West::FALSE:
return 7809;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7810;
case Properties::West::FALSE:
return 7811;
}
}
}
}
}
return 0;
}
}

namespace CyanTerracotta {
constexpr Block toProtocol() {
return 7485;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8930;
case Properties::Facing::SOUTH:
return 8931;
case Properties::Facing::WEST:
return 8932;
case Properties::Facing::EAST:
return 8933;
}
return 0;
}
}

namespace CyanWool {
constexpr Block toProtocol() {
return 1647;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 7235;
case Properties::Facing::SOUTH:
return 7236;
case Properties::Facing::WEST:
return 7237;
case Properties::Facing::EAST:
return 7238;
}
return 0;
}
}

namespace Dandelion {
constexpr Block toProtocol() {
return 1666;
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7059;
case Properties::Powered::FALSE:
return 7060;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7061;
case Properties::Powered::FALSE:
return 7062;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7063;
case Properties::Powered::FALSE:
return 7064;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7065;
case Properties::Powered::FALSE:
return 7066;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7067;
case Properties::Powered::FALSE:
return 7068;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7069;
case Properties::Powered::FALSE:
return 7070;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7071;
case Properties::Powered::FALSE:
return 7072;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7073;
case Properties::Powered::FALSE:
return 7074;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7075;
case Properties::Powered::FALSE:
return 7076;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7077;
case Properties::Powered::FALSE:
return 7078;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7079;
case Properties::Powered::FALSE:
return 7080;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7081;
case Properties::Powered::FALSE:
return 7082;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9811;
case Properties::Powered::FALSE:
return 9812;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9813;
case Properties::Powered::FALSE:
return 9814;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9815;
case Properties::Powered::FALSE:
return 9816;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9817;
case Properties::Powered::FALSE:
return 9818;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9819;
case Properties::Powered::FALSE:
return 9820;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9821;
case Properties::Powered::FALSE:
return 9822;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9823;
case Properties::Powered::FALSE:
return 9824;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9825;
case Properties::Powered::FALSE:
return 9826;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9827;
case Properties::Powered::FALSE:
return 9828;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9829;
case Properties::Powered::FALSE:
return 9830;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9831;
case Properties::Powered::FALSE:
return 9832;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9833;
case Properties::Powered::FALSE:
return 9834;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9835;
case Properties::Powered::FALSE:
return 9836;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9837;
case Properties::Powered::FALSE:
return 9838;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9839;
case Properties::Powered::FALSE:
return 9840;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9841;
case Properties::Powered::FALSE:
return 9842;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9843;
case Properties::Powered::FALSE:
return 9844;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9845;
case Properties::Powered::FALSE:
return 9846;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9847;
case Properties::Powered::FALSE:
return 9848;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9849;
case Properties::Powered::FALSE:
return 9850;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9851;
case Properties::Powered::FALSE:
return 9852;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9853;
case Properties::Powered::FALSE:
return 9854;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9855;
case Properties::Powered::FALSE:
return 9856;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9857;
case Properties::Powered::FALSE:
return 9858;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9859;
case Properties::Powered::FALSE:
return 9860;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9861;
case Properties::Powered::FALSE:
return 9862;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9863;
case Properties::Powered::FALSE:
return 9864;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9865;
case Properties::Powered::FALSE:
return 9866;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9867;
case Properties::Powered::FALSE:
return 9868;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9869;
case Properties::Powered::FALSE:
return 9870;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9871;
case Properties::Powered::FALSE:
return 9872;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9873;
case Properties::Powered::FALSE:
return 9874;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 9491;
case Properties::West::FALSE:
return 9492;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9493;
case Properties::West::FALSE:
return 9494;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9495;
case Properties::West::FALSE:
return 9496;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9497;
case Properties::West::FALSE:
return 9498;
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
return 9499;
case Properties::West::FALSE:
return 9500;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9501;
case Properties::West::FALSE:
return 9502;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9503;
case Properties::West::FALSE:
return 9504;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9505;
case Properties::West::FALSE:
return 9506;
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
return 9507;
case Properties::West::FALSE:
return 9508;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9509;
case Properties::West::FALSE:
return 9510;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9511;
case Properties::West::FALSE:
return 9512;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9513;
case Properties::West::FALSE:
return 9514;
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
return 9515;
case Properties::West::FALSE:
return 9516;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9517;
case Properties::West::FALSE:
return 9518;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9519;
case Properties::West::FALSE:
return 9520;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9521;
case Properties::West::FALSE:
return 9522;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9299;
case Properties::Powered::FALSE:
return 9300;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9301;
case Properties::Powered::FALSE:
return 9302;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9303;
case Properties::Powered::FALSE:
return 9304;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9305;
case Properties::Powered::FALSE:
return 9306;
}
}
}
case Properties::Facing::SOUTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9307;
case Properties::Powered::FALSE:
return 9308;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9309;
case Properties::Powered::FALSE:
return 9310;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9311;
case Properties::Powered::FALSE:
return 9312;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9313;
case Properties::Powered::FALSE:
return 9314;
}
}
}
case Properties::Facing::WEST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9315;
case Properties::Powered::FALSE:
return 9316;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9317;
case Properties::Powered::FALSE:
return 9318;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9319;
case Properties::Powered::FALSE:
return 9320;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9321;
case Properties::Powered::FALSE:
return 9322;
}
}
}
case Properties::Facing::EAST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9323;
case Properties::Powered::FALSE:
return 9324;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9325;
case Properties::Powered::FALSE:
return 9326;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9327;
case Properties::Powered::FALSE:
return 9328;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9329;
case Properties::Powered::FALSE:
return 9330;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 346;
case Properties::Waterlogged::FALSE:
return 347;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 348;
case Properties::Waterlogged::FALSE:
return 349;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 350;
case Properties::Waterlogged::FALSE:
return 351;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 352;
case Properties::Waterlogged::FALSE:
return 353;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 354;
case Properties::Waterlogged::FALSE:
return 355;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 356;
case Properties::Waterlogged::FALSE:
return 357;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 358;
case Properties::Waterlogged::FALSE:
return 359;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 360;
case Properties::Waterlogged::FALSE:
return 361;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 362;
case Properties::Waterlogged::FALSE:
return 363;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 364;
case Properties::Waterlogged::FALSE:
return 365;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 366;
case Properties::Waterlogged::FALSE:
return 367;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 368;
case Properties::Waterlogged::FALSE:
return 369;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 370;
case Properties::Waterlogged::FALSE:
return 371;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 372;
case Properties::Waterlogged::FALSE:
return 373;
}
}
}
return 0;
}
}

namespace DarkOakLog {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 132;
case Properties::Axis::Y:
return 133;
case Properties::Axis::Z:
return 134;
}
return 0;
}
}

namespace DarkOakPlanks {
constexpr Block toProtocol() {
return 20;
return 0;
}
}

namespace DarkOakPressurePlate {
namespace Properties {
enum class Powered {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Powered powered) {
switch (powered) {
case Properties::Powered::TRUE:
return 4188;
case Properties::Powered::FALSE:
return 4189;
}
return 0;
}
}

namespace DarkOakSapling {
namespace Properties {
enum class Stage {
ZERO,
ONE
};
}
constexpr Block toProtocol(Properties::Stage stage) {
switch (stage) {
case Properties::Stage::ZERO:
return 32;
case Properties::Stage::ONE:
return 33;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
switch (rotation) {
case Properties::Rotation::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3796;
case Properties::Waterlogged::FALSE:
return 3797;
}
case Properties::Rotation::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3798;
case Properties::Waterlogged::FALSE:
return 3799;
}
case Properties::Rotation::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3800;
case Properties::Waterlogged::FALSE:
return 3801;
}
case Properties::Rotation::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3802;
case Properties::Waterlogged::FALSE:
return 3803;
}
case Properties::Rotation::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3804;
case Properties::Waterlogged::FALSE:
return 3805;
}
case Properties::Rotation::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3806;
case Properties::Waterlogged::FALSE:
return 3807;
}
case Properties::Rotation::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3808;
case Properties::Waterlogged::FALSE:
return 3809;
}
case Properties::Rotation::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3810;
case Properties::Waterlogged::FALSE:
return 3811;
}
case Properties::Rotation::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3812;
case Properties::Waterlogged::FALSE:
return 3813;
}
case Properties::Rotation::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3814;
case Properties::Waterlogged::FALSE:
return 3815;
}
case Properties::Rotation::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3816;
case Properties::Waterlogged::FALSE:
return 3817;
}
case Properties::Rotation::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3818;
case Properties::Waterlogged::FALSE:
return 3819;
}
case Properties::Rotation::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3820;
case Properties::Waterlogged::FALSE:
return 3821;
}
case Properties::Rotation::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3822;
case Properties::Waterlogged::FALSE:
return 3823;
}
case Properties::Rotation::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3824;
case Properties::Waterlogged::FALSE:
return 3825;
}
case Properties::Rotation::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3826;
case Properties::Waterlogged::FALSE:
return 3827;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9071;
case Properties::Waterlogged::FALSE:
return 9072;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9073;
case Properties::Waterlogged::FALSE:
return 9074;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9075;
case Properties::Waterlogged::FALSE:
return 9076;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8084;
case Properties::Waterlogged::FALSE:
return 8085;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8086;
case Properties::Waterlogged::FALSE:
return 8087;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8088;
case Properties::Waterlogged::FALSE:
return 8089;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8090;
case Properties::Waterlogged::FALSE:
return 8091;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8092;
case Properties::Waterlogged::FALSE:
return 8093;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8094;
case Properties::Waterlogged::FALSE:
return 8095;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8096;
case Properties::Waterlogged::FALSE:
return 8097;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8098;
case Properties::Waterlogged::FALSE:
return 8099;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8100;
case Properties::Waterlogged::FALSE:
return 8101;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8102;
case Properties::Waterlogged::FALSE:
return 8103;
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
return 8104;
case Properties::Waterlogged::FALSE:
return 8105;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8106;
case Properties::Waterlogged::FALSE:
return 8107;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8108;
case Properties::Waterlogged::FALSE:
return 8109;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8110;
case Properties::Waterlogged::FALSE:
return 8111;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8112;
case Properties::Waterlogged::FALSE:
return 8113;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8114;
case Properties::Waterlogged::FALSE:
return 8115;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8116;
case Properties::Waterlogged::FALSE:
return 8117;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8118;
case Properties::Waterlogged::FALSE:
return 8119;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8120;
case Properties::Waterlogged::FALSE:
return 8121;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8122;
case Properties::Waterlogged::FALSE:
return 8123;
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
return 8124;
case Properties::Waterlogged::FALSE:
return 8125;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8126;
case Properties::Waterlogged::FALSE:
return 8127;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8128;
case Properties::Waterlogged::FALSE:
return 8129;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8130;
case Properties::Waterlogged::FALSE:
return 8131;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8132;
case Properties::Waterlogged::FALSE:
return 8133;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8134;
case Properties::Waterlogged::FALSE:
return 8135;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8136;
case Properties::Waterlogged::FALSE:
return 8137;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8138;
case Properties::Waterlogged::FALSE:
return 8139;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8140;
case Properties::Waterlogged::FALSE:
return 8141;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8142;
case Properties::Waterlogged::FALSE:
return 8143;
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
return 8144;
case Properties::Waterlogged::FALSE:
return 8145;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8146;
case Properties::Waterlogged::FALSE:
return 8147;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8148;
case Properties::Waterlogged::FALSE:
return 8149;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8150;
case Properties::Waterlogged::FALSE:
return 8151;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8152;
case Properties::Waterlogged::FALSE:
return 8153;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8154;
case Properties::Waterlogged::FALSE:
return 8155;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8156;
case Properties::Waterlogged::FALSE:
return 8157;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8158;
case Properties::Waterlogged::FALSE:
return 8159;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8160;
case Properties::Waterlogged::FALSE:
return 8161;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8162;
case Properties::Waterlogged::FALSE:
return 8163;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4740;
case Properties::Waterlogged::FALSE:
return 4741;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4742;
case Properties::Waterlogged::FALSE:
return 4743;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4744;
case Properties::Waterlogged::FALSE:
return 4745;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4746;
case Properties::Waterlogged::FALSE:
return 4747;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4748;
case Properties::Waterlogged::FALSE:
return 4749;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4750;
case Properties::Waterlogged::FALSE:
return 4751;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4752;
case Properties::Waterlogged::FALSE:
return 4753;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4754;
case Properties::Waterlogged::FALSE:
return 4755;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4756;
case Properties::Waterlogged::FALSE:
return 4757;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4758;
case Properties::Waterlogged::FALSE:
return 4759;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4760;
case Properties::Waterlogged::FALSE:
return 4761;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4762;
case Properties::Waterlogged::FALSE:
return 4763;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4764;
case Properties::Waterlogged::FALSE:
return 4765;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4766;
case Properties::Waterlogged::FALSE:
return 4767;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4768;
case Properties::Waterlogged::FALSE:
return 4769;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4770;
case Properties::Waterlogged::FALSE:
return 4771;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4772;
case Properties::Waterlogged::FALSE:
return 4773;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4774;
case Properties::Waterlogged::FALSE:
return 4775;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4776;
case Properties::Waterlogged::FALSE:
return 4777;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4778;
case Properties::Waterlogged::FALSE:
return 4779;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4780;
case Properties::Waterlogged::FALSE:
return 4781;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4782;
case Properties::Waterlogged::FALSE:
return 4783;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4784;
case Properties::Waterlogged::FALSE:
return 4785;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4786;
case Properties::Waterlogged::FALSE:
return 4787;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4788;
case Properties::Waterlogged::FALSE:
return 4789;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4790;
case Properties::Waterlogged::FALSE:
return 4791;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4792;
case Properties::Waterlogged::FALSE:
return 4793;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4794;
case Properties::Waterlogged::FALSE:
return 4795;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4796;
case Properties::Waterlogged::FALSE:
return 4797;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4798;
case Properties::Waterlogged::FALSE:
return 4799;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4800;
case Properties::Waterlogged::FALSE:
return 4801;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4802;
case Properties::Waterlogged::FALSE:
return 4803;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4072;
case Properties::Waterlogged::FALSE:
return 4073;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4074;
case Properties::Waterlogged::FALSE:
return 4075;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4076;
case Properties::Waterlogged::FALSE:
return 4077;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4078;
case Properties::Waterlogged::FALSE:
return 4079;
}
}
return 0;
}
}

namespace DarkOakWood {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 179;
case Properties::Axis::Y:
return 180;
case Properties::Axis::Z:
return 181;
}
return 0;
}
}

namespace DarkPrismarine {
constexpr Block toProtocol() {
return 8344;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8597;
case Properties::Waterlogged::FALSE:
return 8598;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8599;
case Properties::Waterlogged::FALSE:
return 8600;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8601;
case Properties::Waterlogged::FALSE:
return 8602;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8505;
case Properties::Waterlogged::FALSE:
return 8506;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8507;
case Properties::Waterlogged::FALSE:
return 8508;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8509;
case Properties::Waterlogged::FALSE:
return 8510;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8511;
case Properties::Waterlogged::FALSE:
return 8512;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8513;
case Properties::Waterlogged::FALSE:
return 8514;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8515;
case Properties::Waterlogged::FALSE:
return 8516;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8517;
case Properties::Waterlogged::FALSE:
return 8518;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8519;
case Properties::Waterlogged::FALSE:
return 8520;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8521;
case Properties::Waterlogged::FALSE:
return 8522;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8523;
case Properties::Waterlogged::FALSE:
return 8524;
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
return 8525;
case Properties::Waterlogged::FALSE:
return 8526;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8527;
case Properties::Waterlogged::FALSE:
return 8528;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8529;
case Properties::Waterlogged::FALSE:
return 8530;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8531;
case Properties::Waterlogged::FALSE:
return 8532;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8533;
case Properties::Waterlogged::FALSE:
return 8534;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8535;
case Properties::Waterlogged::FALSE:
return 8536;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8537;
case Properties::Waterlogged::FALSE:
return 8538;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8539;
case Properties::Waterlogged::FALSE:
return 8540;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8541;
case Properties::Waterlogged::FALSE:
return 8542;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8543;
case Properties::Waterlogged::FALSE:
return 8544;
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
return 8545;
case Properties::Waterlogged::FALSE:
return 8546;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8547;
case Properties::Waterlogged::FALSE:
return 8548;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8549;
case Properties::Waterlogged::FALSE:
return 8550;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8551;
case Properties::Waterlogged::FALSE:
return 8552;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8553;
case Properties::Waterlogged::FALSE:
return 8554;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8555;
case Properties::Waterlogged::FALSE:
return 8556;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8557;
case Properties::Waterlogged::FALSE:
return 8558;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8559;
case Properties::Waterlogged::FALSE:
return 8560;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8561;
case Properties::Waterlogged::FALSE:
return 8562;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8563;
case Properties::Waterlogged::FALSE:
return 8564;
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
return 8565;
case Properties::Waterlogged::FALSE:
return 8566;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8567;
case Properties::Waterlogged::FALSE:
return 8568;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8569;
case Properties::Waterlogged::FALSE:
return 8570;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8571;
case Properties::Waterlogged::FALSE:
return 8572;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8573;
case Properties::Waterlogged::FALSE:
return 8574;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8575;
case Properties::Waterlogged::FALSE:
return 8576;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8577;
case Properties::Waterlogged::FALSE:
return 8578;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8579;
case Properties::Waterlogged::FALSE:
return 8580;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8581;
case Properties::Waterlogged::FALSE:
return 8582;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8583;
case Properties::Waterlogged::FALSE:
return 8584;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Inverted inverted, Properties::Power power) {
switch (inverted) {
case Properties::Inverted::TRUE:
switch (power) {
case Properties::Power::ZERO:
return 7311;
case Properties::Power::ONE:
return 7312;
case Properties::Power::TWO:
return 7313;
case Properties::Power::THREE:
return 7314;
case Properties::Power::FOUR:
return 7315;
case Properties::Power::FIVE:
return 7316;
case Properties::Power::SIX:
return 7317;
case Properties::Power::SEVEN:
return 7318;
case Properties::Power::EIGHT:
return 7319;
case Properties::Power::NINE:
return 7320;
case Properties::Power::TEN:
return 7321;
case Properties::Power::ELEVEN:
return 7322;
case Properties::Power::TWELVE:
return 7323;
case Properties::Power::THIRTEEN:
return 7324;
case Properties::Power::FOURTEEN:
return 7325;
case Properties::Power::FIFTEEN:
return 7326;
}
case Properties::Inverted::FALSE:
switch (power) {
case Properties::Power::ZERO:
return 7327;
case Properties::Power::ONE:
return 7328;
case Properties::Power::TWO:
return 7329;
case Properties::Power::THREE:
return 7330;
case Properties::Power::FOUR:
return 7331;
case Properties::Power::FIVE:
return 7332;
case Properties::Power::SIX:
return 7333;
case Properties::Power::SEVEN:
return 7334;
case Properties::Power::EIGHT:
return 7335;
case Properties::Power::NINE:
return 7336;
case Properties::Power::TEN:
return 7337;
case Properties::Power::ELEVEN:
return 7338;
case Properties::Power::TWELVE:
return 7339;
case Properties::Power::THIRTEEN:
return 7340;
case Properties::Power::FOURTEEN:
return 7341;
case Properties::Power::FIFTEEN:
return 7342;
}
}
return 0;
}
}

namespace DeadBrainCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10403;
case Properties::Waterlogged::FALSE:
return 10404;
}
return 0;
}
}

namespace DeadBrainCoralBlock {
constexpr Block toProtocol() {
return 10392;
return 0;
}
}

namespace DeadBrainCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10423;
case Properties::Waterlogged::FALSE:
return 10424;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10449;
case Properties::Waterlogged::FALSE:
return 10450;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10451;
case Properties::Waterlogged::FALSE:
return 10452;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10453;
case Properties::Waterlogged::FALSE:
return 10454;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10455;
case Properties::Waterlogged::FALSE:
return 10456;
}
}
return 0;
}
}

namespace DeadBubbleCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10405;
case Properties::Waterlogged::FALSE:
return 10406;
}
return 0;
}
}

namespace DeadBubbleCoralBlock {
constexpr Block toProtocol() {
return 10393;
return 0;
}
}

namespace DeadBubbleCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10425;
case Properties::Waterlogged::FALSE:
return 10426;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10457;
case Properties::Waterlogged::FALSE:
return 10458;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10459;
case Properties::Waterlogged::FALSE:
return 10460;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10461;
case Properties::Waterlogged::FALSE:
return 10462;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10463;
case Properties::Waterlogged::FALSE:
return 10464;
}
}
return 0;
}
}

namespace DeadBush {
constexpr Block toProtocol() {
return 1598;
return 0;
}
}

namespace DeadFireCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10407;
case Properties::Waterlogged::FALSE:
return 10408;
}
return 0;
}
}

namespace DeadFireCoralBlock {
constexpr Block toProtocol() {
return 10394;
return 0;
}
}

namespace DeadFireCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10427;
case Properties::Waterlogged::FALSE:
return 10428;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10465;
case Properties::Waterlogged::FALSE:
return 10466;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10467;
case Properties::Waterlogged::FALSE:
return 10468;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10469;
case Properties::Waterlogged::FALSE:
return 10470;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10471;
case Properties::Waterlogged::FALSE:
return 10472;
}
}
return 0;
}
}

namespace DeadHornCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10409;
case Properties::Waterlogged::FALSE:
return 10410;
}
return 0;
}
}

namespace DeadHornCoralBlock {
constexpr Block toProtocol() {
return 10395;
return 0;
}
}

namespace DeadHornCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10429;
case Properties::Waterlogged::FALSE:
return 10430;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10473;
case Properties::Waterlogged::FALSE:
return 10474;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10475;
case Properties::Waterlogged::FALSE:
return 10476;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10477;
case Properties::Waterlogged::FALSE:
return 10478;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10479;
case Properties::Waterlogged::FALSE:
return 10480;
}
}
return 0;
}
}

namespace DeadTubeCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10401;
case Properties::Waterlogged::FALSE:
return 10402;
}
return 0;
}
}

namespace DeadTubeCoralBlock {
constexpr Block toProtocol() {
return 10391;
return 0;
}
}

namespace DeadTubeCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10421;
case Properties::Waterlogged::FALSE:
return 10422;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10441;
case Properties::Waterlogged::FALSE:
return 10442;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10443;
case Properties::Waterlogged::FALSE:
return 10444;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10445;
case Properties::Waterlogged::FALSE:
return 10446;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10447;
case Properties::Waterlogged::FALSE:
return 10448;
}
}
return 0;
}
}

namespace Deepslate {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 19778;
case Properties::Axis::Y:
return 19779;
case Properties::Axis::Z:
return 19780;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21095;
case Properties::Waterlogged::FALSE:
return 21096;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21097;
case Properties::Waterlogged::FALSE:
return 21098;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21099;
case Properties::Waterlogged::FALSE:
return 21100;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21015;
case Properties::Waterlogged::FALSE:
return 21016;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21017;
case Properties::Waterlogged::FALSE:
return 21018;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21019;
case Properties::Waterlogged::FALSE:
return 21020;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21021;
case Properties::Waterlogged::FALSE:
return 21022;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21023;
case Properties::Waterlogged::FALSE:
return 21024;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21025;
case Properties::Waterlogged::FALSE:
return 21026;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21027;
case Properties::Waterlogged::FALSE:
return 21028;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21029;
case Properties::Waterlogged::FALSE:
return 21030;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21031;
case Properties::Waterlogged::FALSE:
return 21032;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21033;
case Properties::Waterlogged::FALSE:
return 21034;
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
return 21035;
case Properties::Waterlogged::FALSE:
return 21036;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21037;
case Properties::Waterlogged::FALSE:
return 21038;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21039;
case Properties::Waterlogged::FALSE:
return 21040;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21041;
case Properties::Waterlogged::FALSE:
return 21042;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21043;
case Properties::Waterlogged::FALSE:
return 21044;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21045;
case Properties::Waterlogged::FALSE:
return 21046;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21047;
case Properties::Waterlogged::FALSE:
return 21048;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21049;
case Properties::Waterlogged::FALSE:
return 21050;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21051;
case Properties::Waterlogged::FALSE:
return 21052;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21053;
case Properties::Waterlogged::FALSE:
return 21054;
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
return 21055;
case Properties::Waterlogged::FALSE:
return 21056;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21057;
case Properties::Waterlogged::FALSE:
return 21058;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21059;
case Properties::Waterlogged::FALSE:
return 21060;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21061;
case Properties::Waterlogged::FALSE:
return 21062;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21063;
case Properties::Waterlogged::FALSE:
return 21064;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21065;
case Properties::Waterlogged::FALSE:
return 21066;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21067;
case Properties::Waterlogged::FALSE:
return 21068;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21069;
case Properties::Waterlogged::FALSE:
return 21070;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21071;
case Properties::Waterlogged::FALSE:
return 21072;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21073;
case Properties::Waterlogged::FALSE:
return 21074;
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
return 21075;
case Properties::Waterlogged::FALSE:
return 21076;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21077;
case Properties::Waterlogged::FALSE:
return 21078;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21079;
case Properties::Waterlogged::FALSE:
return 21080;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21081;
case Properties::Waterlogged::FALSE:
return 21082;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21083;
case Properties::Waterlogged::FALSE:
return 21084;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21085;
case Properties::Waterlogged::FALSE:
return 21086;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21087;
case Properties::Waterlogged::FALSE:
return 21088;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21089;
case Properties::Waterlogged::FALSE:
return 21090;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21091;
case Properties::Waterlogged::FALSE:
return 21092;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 21093;
case Properties::Waterlogged::FALSE:
return 21094;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21101;
case Properties::West::LOW:
return 21102;
case Properties::West::TALL:
return 21103;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21104;
case Properties::West::LOW:
return 21105;
case Properties::West::TALL:
return 21106;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21107;
case Properties::West::LOW:
return 21108;
case Properties::West::TALL:
return 21109;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21110;
case Properties::West::LOW:
return 21111;
case Properties::West::TALL:
return 21112;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21113;
case Properties::West::LOW:
return 21114;
case Properties::West::TALL:
return 21115;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21116;
case Properties::West::LOW:
return 21117;
case Properties::West::TALL:
return 21118;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21119;
case Properties::West::LOW:
return 21120;
case Properties::West::TALL:
return 21121;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21122;
case Properties::West::LOW:
return 21123;
case Properties::West::TALL:
return 21124;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21125;
case Properties::West::LOW:
return 21126;
case Properties::West::TALL:
return 21127;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21128;
case Properties::West::LOW:
return 21129;
case Properties::West::TALL:
return 21130;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21131;
case Properties::West::LOW:
return 21132;
case Properties::West::TALL:
return 21133;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21134;
case Properties::West::LOW:
return 21135;
case Properties::West::TALL:
return 21136;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21137;
case Properties::West::LOW:
return 21138;
case Properties::West::TALL:
return 21139;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21140;
case Properties::West::LOW:
return 21141;
case Properties::West::TALL:
return 21142;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21143;
case Properties::West::LOW:
return 21144;
case Properties::West::TALL:
return 21145;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21146;
case Properties::West::LOW:
return 21147;
case Properties::West::TALL:
return 21148;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21149;
case Properties::West::LOW:
return 21150;
case Properties::West::TALL:
return 21151;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21152;
case Properties::West::LOW:
return 21153;
case Properties::West::TALL:
return 21154;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21155;
case Properties::West::LOW:
return 21156;
case Properties::West::TALL:
return 21157;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21158;
case Properties::West::LOW:
return 21159;
case Properties::West::TALL:
return 21160;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21161;
case Properties::West::LOW:
return 21162;
case Properties::West::TALL:
return 21163;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21164;
case Properties::West::LOW:
return 21165;
case Properties::West::TALL:
return 21166;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21167;
case Properties::West::LOW:
return 21168;
case Properties::West::TALL:
return 21169;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21170;
case Properties::West::LOW:
return 21171;
case Properties::West::TALL:
return 21172;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21173;
case Properties::West::LOW:
return 21174;
case Properties::West::TALL:
return 21175;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21176;
case Properties::West::LOW:
return 21177;
case Properties::West::TALL:
return 21178;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21179;
case Properties::West::LOW:
return 21180;
case Properties::West::TALL:
return 21181;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21182;
case Properties::West::LOW:
return 21183;
case Properties::West::TALL:
return 21184;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21185;
case Properties::West::LOW:
return 21186;
case Properties::West::TALL:
return 21187;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21188;
case Properties::West::LOW:
return 21189;
case Properties::West::TALL:
return 21190;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21191;
case Properties::West::LOW:
return 21192;
case Properties::West::TALL:
return 21193;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21194;
case Properties::West::LOW:
return 21195;
case Properties::West::TALL:
return 21196;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21197;
case Properties::West::LOW:
return 21198;
case Properties::West::TALL:
return 21199;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21200;
case Properties::West::LOW:
return 21201;
case Properties::West::TALL:
return 21202;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21203;
case Properties::West::LOW:
return 21204;
case Properties::West::TALL:
return 21205;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21206;
case Properties::West::LOW:
return 21207;
case Properties::West::TALL:
return 21208;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21209;
case Properties::West::LOW:
return 21210;
case Properties::West::TALL:
return 21211;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21212;
case Properties::West::LOW:
return 21213;
case Properties::West::TALL:
return 21214;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21215;
case Properties::West::LOW:
return 21216;
case Properties::West::TALL:
return 21217;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21218;
case Properties::West::LOW:
return 21219;
case Properties::West::TALL:
return 21220;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21221;
case Properties::West::LOW:
return 21222;
case Properties::West::TALL:
return 21223;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21224;
case Properties::West::LOW:
return 21225;
case Properties::West::TALL:
return 21226;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21227;
case Properties::West::LOW:
return 21228;
case Properties::West::TALL:
return 21229;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21230;
case Properties::West::LOW:
return 21231;
case Properties::West::TALL:
return 21232;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21233;
case Properties::West::LOW:
return 21234;
case Properties::West::TALL:
return 21235;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21236;
case Properties::West::LOW:
return 21237;
case Properties::West::TALL:
return 21238;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21239;
case Properties::West::LOW:
return 21240;
case Properties::West::TALL:
return 21241;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21242;
case Properties::West::LOW:
return 21243;
case Properties::West::TALL:
return 21244;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21245;
case Properties::West::LOW:
return 21246;
case Properties::West::TALL:
return 21247;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21248;
case Properties::West::LOW:
return 21249;
case Properties::West::TALL:
return 21250;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21251;
case Properties::West::LOW:
return 21252;
case Properties::West::TALL:
return 21253;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21254;
case Properties::West::LOW:
return 21255;
case Properties::West::TALL:
return 21256;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21257;
case Properties::West::LOW:
return 21258;
case Properties::West::TALL:
return 21259;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21260;
case Properties::West::LOW:
return 21261;
case Properties::West::TALL:
return 21262;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21263;
case Properties::West::LOW:
return 21264;
case Properties::West::TALL:
return 21265;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21266;
case Properties::West::LOW:
return 21267;
case Properties::West::TALL:
return 21268;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21269;
case Properties::West::LOW:
return 21270;
case Properties::West::TALL:
return 21271;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21272;
case Properties::West::LOW:
return 21273;
case Properties::West::TALL:
return 21274;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21275;
case Properties::West::LOW:
return 21276;
case Properties::West::TALL:
return 21277;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21278;
case Properties::West::LOW:
return 21279;
case Properties::West::TALL:
return 21280;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21281;
case Properties::West::LOW:
return 21282;
case Properties::West::TALL:
return 21283;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21284;
case Properties::West::LOW:
return 21285;
case Properties::West::TALL:
return 21286;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21287;
case Properties::West::LOW:
return 21288;
case Properties::West::TALL:
return 21289;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21290;
case Properties::West::LOW:
return 21291;
case Properties::West::TALL:
return 21292;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21293;
case Properties::West::LOW:
return 21294;
case Properties::West::TALL:
return 21295;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21296;
case Properties::West::LOW:
return 21297;
case Properties::West::TALL:
return 21298;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21299;
case Properties::West::LOW:
return 21300;
case Properties::West::TALL:
return 21301;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21302;
case Properties::West::LOW:
return 21303;
case Properties::West::TALL:
return 21304;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21305;
case Properties::West::LOW:
return 21306;
case Properties::West::TALL:
return 21307;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21308;
case Properties::West::LOW:
return 21309;
case Properties::West::TALL:
return 21310;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21311;
case Properties::West::LOW:
return 21312;
case Properties::West::TALL:
return 21313;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21314;
case Properties::West::LOW:
return 21315;
case Properties::West::TALL:
return 21316;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21317;
case Properties::West::LOW:
return 21318;
case Properties::West::TALL:
return 21319;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21320;
case Properties::West::LOW:
return 21321;
case Properties::West::TALL:
return 21322;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21323;
case Properties::West::LOW:
return 21324;
case Properties::West::TALL:
return 21325;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21326;
case Properties::West::LOW:
return 21327;
case Properties::West::TALL:
return 21328;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21329;
case Properties::West::LOW:
return 21330;
case Properties::West::TALL:
return 21331;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21332;
case Properties::West::LOW:
return 21333;
case Properties::West::TALL:
return 21334;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21335;
case Properties::West::LOW:
return 21336;
case Properties::West::TALL:
return 21337;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21338;
case Properties::West::LOW:
return 21339;
case Properties::West::TALL:
return 21340;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21341;
case Properties::West::LOW:
return 21342;
case Properties::West::TALL:
return 21343;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21344;
case Properties::West::LOW:
return 21345;
case Properties::West::TALL:
return 21346;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21347;
case Properties::West::LOW:
return 21348;
case Properties::West::TALL:
return 21349;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21350;
case Properties::West::LOW:
return 21351;
case Properties::West::TALL:
return 21352;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21353;
case Properties::West::LOW:
return 21354;
case Properties::West::TALL:
return 21355;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21356;
case Properties::West::LOW:
return 21357;
case Properties::West::TALL:
return 21358;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21359;
case Properties::West::LOW:
return 21360;
case Properties::West::TALL:
return 21361;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21362;
case Properties::West::LOW:
return 21363;
case Properties::West::TALL:
return 21364;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21365;
case Properties::West::LOW:
return 21366;
case Properties::West::TALL:
return 21367;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21368;
case Properties::West::LOW:
return 21369;
case Properties::West::TALL:
return 21370;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21371;
case Properties::West::LOW:
return 21372;
case Properties::West::TALL:
return 21373;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21374;
case Properties::West::LOW:
return 21375;
case Properties::West::TALL:
return 21376;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21377;
case Properties::West::LOW:
return 21378;
case Properties::West::TALL:
return 21379;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21380;
case Properties::West::LOW:
return 21381;
case Properties::West::TALL:
return 21382;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21383;
case Properties::West::LOW:
return 21384;
case Properties::West::TALL:
return 21385;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21386;
case Properties::West::LOW:
return 21387;
case Properties::West::TALL:
return 21388;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21389;
case Properties::West::LOW:
return 21390;
case Properties::West::TALL:
return 21391;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21392;
case Properties::West::LOW:
return 21393;
case Properties::West::TALL:
return 21394;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21395;
case Properties::West::LOW:
return 21396;
case Properties::West::TALL:
return 21397;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21398;
case Properties::West::LOW:
return 21399;
case Properties::West::TALL:
return 21400;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21401;
case Properties::West::LOW:
return 21402;
case Properties::West::TALL:
return 21403;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21404;
case Properties::West::LOW:
return 21405;
case Properties::West::TALL:
return 21406;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21407;
case Properties::West::LOW:
return 21408;
case Properties::West::TALL:
return 21409;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21410;
case Properties::West::LOW:
return 21411;
case Properties::West::TALL:
return 21412;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21413;
case Properties::West::LOW:
return 21414;
case Properties::West::TALL:
return 21415;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21416;
case Properties::West::LOW:
return 21417;
case Properties::West::TALL:
return 21418;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21419;
case Properties::West::LOW:
return 21420;
case Properties::West::TALL:
return 21421;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21422;
case Properties::West::LOW:
return 21423;
case Properties::West::TALL:
return 21424;
}
}
}
}
}
}
return 0;
}
}

namespace DeepslateBricks {
constexpr Block toProtocol() {
return 21014;
return 0;
}
}

namespace DeepslateCoalOre {
constexpr Block toProtocol() {
return 115;
return 0;
}
}

namespace DeepslateCopperOre {
constexpr Block toProtocol() {
return 18913;
return 0;
}
}

namespace DeepslateDiamondOre {
constexpr Block toProtocol() {
return 3609;
return 0;
}
}

namespace DeepslateEmeraldOre {
constexpr Block toProtocol() {
return 5842;
return 0;
}
}

namespace DeepslateGoldOre {
constexpr Block toProtocol() {
return 111;
return 0;
}
}

namespace DeepslateIronOre {
constexpr Block toProtocol() {
return 113;
return 0;
}
}

namespace DeepslateLapisOre {
constexpr Block toProtocol() {
return 462;
return 0;
}
}

namespace DeepslateRedstoneOre {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 4194;
case Properties::Lit::FALSE:
return 4195;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20684;
case Properties::Waterlogged::FALSE:
return 20685;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20686;
case Properties::Waterlogged::FALSE:
return 20687;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20688;
case Properties::Waterlogged::FALSE:
return 20689;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20604;
case Properties::Waterlogged::FALSE:
return 20605;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20606;
case Properties::Waterlogged::FALSE:
return 20607;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20608;
case Properties::Waterlogged::FALSE:
return 20609;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20610;
case Properties::Waterlogged::FALSE:
return 20611;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20612;
case Properties::Waterlogged::FALSE:
return 20613;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20614;
case Properties::Waterlogged::FALSE:
return 20615;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20616;
case Properties::Waterlogged::FALSE:
return 20617;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20618;
case Properties::Waterlogged::FALSE:
return 20619;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20620;
case Properties::Waterlogged::FALSE:
return 20621;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20622;
case Properties::Waterlogged::FALSE:
return 20623;
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
return 20624;
case Properties::Waterlogged::FALSE:
return 20625;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20626;
case Properties::Waterlogged::FALSE:
return 20627;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20628;
case Properties::Waterlogged::FALSE:
return 20629;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20630;
case Properties::Waterlogged::FALSE:
return 20631;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20632;
case Properties::Waterlogged::FALSE:
return 20633;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20634;
case Properties::Waterlogged::FALSE:
return 20635;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20636;
case Properties::Waterlogged::FALSE:
return 20637;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20638;
case Properties::Waterlogged::FALSE:
return 20639;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20640;
case Properties::Waterlogged::FALSE:
return 20641;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20642;
case Properties::Waterlogged::FALSE:
return 20643;
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
return 20644;
case Properties::Waterlogged::FALSE:
return 20645;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20646;
case Properties::Waterlogged::FALSE:
return 20647;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20648;
case Properties::Waterlogged::FALSE:
return 20649;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20650;
case Properties::Waterlogged::FALSE:
return 20651;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20652;
case Properties::Waterlogged::FALSE:
return 20653;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20654;
case Properties::Waterlogged::FALSE:
return 20655;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20656;
case Properties::Waterlogged::FALSE:
return 20657;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20658;
case Properties::Waterlogged::FALSE:
return 20659;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20660;
case Properties::Waterlogged::FALSE:
return 20661;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20662;
case Properties::Waterlogged::FALSE:
return 20663;
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
return 20664;
case Properties::Waterlogged::FALSE:
return 20665;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20666;
case Properties::Waterlogged::FALSE:
return 20667;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20668;
case Properties::Waterlogged::FALSE:
return 20669;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20670;
case Properties::Waterlogged::FALSE:
return 20671;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20672;
case Properties::Waterlogged::FALSE:
return 20673;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20674;
case Properties::Waterlogged::FALSE:
return 20675;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20676;
case Properties::Waterlogged::FALSE:
return 20677;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20678;
case Properties::Waterlogged::FALSE:
return 20679;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20680;
case Properties::Waterlogged::FALSE:
return 20681;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 20682;
case Properties::Waterlogged::FALSE:
return 20683;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20690;
case Properties::West::LOW:
return 20691;
case Properties::West::TALL:
return 20692;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20693;
case Properties::West::LOW:
return 20694;
case Properties::West::TALL:
return 20695;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20696;
case Properties::West::LOW:
return 20697;
case Properties::West::TALL:
return 20698;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20699;
case Properties::West::LOW:
return 20700;
case Properties::West::TALL:
return 20701;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20702;
case Properties::West::LOW:
return 20703;
case Properties::West::TALL:
return 20704;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20705;
case Properties::West::LOW:
return 20706;
case Properties::West::TALL:
return 20707;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20708;
case Properties::West::LOW:
return 20709;
case Properties::West::TALL:
return 20710;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20711;
case Properties::West::LOW:
return 20712;
case Properties::West::TALL:
return 20713;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20714;
case Properties::West::LOW:
return 20715;
case Properties::West::TALL:
return 20716;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20717;
case Properties::West::LOW:
return 20718;
case Properties::West::TALL:
return 20719;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20720;
case Properties::West::LOW:
return 20721;
case Properties::West::TALL:
return 20722;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20723;
case Properties::West::LOW:
return 20724;
case Properties::West::TALL:
return 20725;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20726;
case Properties::West::LOW:
return 20727;
case Properties::West::TALL:
return 20728;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20729;
case Properties::West::LOW:
return 20730;
case Properties::West::TALL:
return 20731;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20732;
case Properties::West::LOW:
return 20733;
case Properties::West::TALL:
return 20734;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20735;
case Properties::West::LOW:
return 20736;
case Properties::West::TALL:
return 20737;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20738;
case Properties::West::LOW:
return 20739;
case Properties::West::TALL:
return 20740;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20741;
case Properties::West::LOW:
return 20742;
case Properties::West::TALL:
return 20743;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20744;
case Properties::West::LOW:
return 20745;
case Properties::West::TALL:
return 20746;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20747;
case Properties::West::LOW:
return 20748;
case Properties::West::TALL:
return 20749;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20750;
case Properties::West::LOW:
return 20751;
case Properties::West::TALL:
return 20752;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20753;
case Properties::West::LOW:
return 20754;
case Properties::West::TALL:
return 20755;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20756;
case Properties::West::LOW:
return 20757;
case Properties::West::TALL:
return 20758;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20759;
case Properties::West::LOW:
return 20760;
case Properties::West::TALL:
return 20761;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20762;
case Properties::West::LOW:
return 20763;
case Properties::West::TALL:
return 20764;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20765;
case Properties::West::LOW:
return 20766;
case Properties::West::TALL:
return 20767;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20768;
case Properties::West::LOW:
return 20769;
case Properties::West::TALL:
return 20770;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20771;
case Properties::West::LOW:
return 20772;
case Properties::West::TALL:
return 20773;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20774;
case Properties::West::LOW:
return 20775;
case Properties::West::TALL:
return 20776;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20777;
case Properties::West::LOW:
return 20778;
case Properties::West::TALL:
return 20779;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20780;
case Properties::West::LOW:
return 20781;
case Properties::West::TALL:
return 20782;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20783;
case Properties::West::LOW:
return 20784;
case Properties::West::TALL:
return 20785;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20786;
case Properties::West::LOW:
return 20787;
case Properties::West::TALL:
return 20788;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20789;
case Properties::West::LOW:
return 20790;
case Properties::West::TALL:
return 20791;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20792;
case Properties::West::LOW:
return 20793;
case Properties::West::TALL:
return 20794;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20795;
case Properties::West::LOW:
return 20796;
case Properties::West::TALL:
return 20797;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20798;
case Properties::West::LOW:
return 20799;
case Properties::West::TALL:
return 20800;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20801;
case Properties::West::LOW:
return 20802;
case Properties::West::TALL:
return 20803;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20804;
case Properties::West::LOW:
return 20805;
case Properties::West::TALL:
return 20806;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20807;
case Properties::West::LOW:
return 20808;
case Properties::West::TALL:
return 20809;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20810;
case Properties::West::LOW:
return 20811;
case Properties::West::TALL:
return 20812;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20813;
case Properties::West::LOW:
return 20814;
case Properties::West::TALL:
return 20815;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20816;
case Properties::West::LOW:
return 20817;
case Properties::West::TALL:
return 20818;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20819;
case Properties::West::LOW:
return 20820;
case Properties::West::TALL:
return 20821;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20822;
case Properties::West::LOW:
return 20823;
case Properties::West::TALL:
return 20824;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20825;
case Properties::West::LOW:
return 20826;
case Properties::West::TALL:
return 20827;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20828;
case Properties::West::LOW:
return 20829;
case Properties::West::TALL:
return 20830;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20831;
case Properties::West::LOW:
return 20832;
case Properties::West::TALL:
return 20833;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20834;
case Properties::West::LOW:
return 20835;
case Properties::West::TALL:
return 20836;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20837;
case Properties::West::LOW:
return 20838;
case Properties::West::TALL:
return 20839;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20840;
case Properties::West::LOW:
return 20841;
case Properties::West::TALL:
return 20842;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20843;
case Properties::West::LOW:
return 20844;
case Properties::West::TALL:
return 20845;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20846;
case Properties::West::LOW:
return 20847;
case Properties::West::TALL:
return 20848;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20849;
case Properties::West::LOW:
return 20850;
case Properties::West::TALL:
return 20851;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20852;
case Properties::West::LOW:
return 20853;
case Properties::West::TALL:
return 20854;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20855;
case Properties::West::LOW:
return 20856;
case Properties::West::TALL:
return 20857;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20858;
case Properties::West::LOW:
return 20859;
case Properties::West::TALL:
return 20860;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20861;
case Properties::West::LOW:
return 20862;
case Properties::West::TALL:
return 20863;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20864;
case Properties::West::LOW:
return 20865;
case Properties::West::TALL:
return 20866;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20867;
case Properties::West::LOW:
return 20868;
case Properties::West::TALL:
return 20869;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20870;
case Properties::West::LOW:
return 20871;
case Properties::West::TALL:
return 20872;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20873;
case Properties::West::LOW:
return 20874;
case Properties::West::TALL:
return 20875;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20876;
case Properties::West::LOW:
return 20877;
case Properties::West::TALL:
return 20878;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20879;
case Properties::West::LOW:
return 20880;
case Properties::West::TALL:
return 20881;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20882;
case Properties::West::LOW:
return 20883;
case Properties::West::TALL:
return 20884;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20885;
case Properties::West::LOW:
return 20886;
case Properties::West::TALL:
return 20887;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20888;
case Properties::West::LOW:
return 20889;
case Properties::West::TALL:
return 20890;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20891;
case Properties::West::LOW:
return 20892;
case Properties::West::TALL:
return 20893;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20894;
case Properties::West::LOW:
return 20895;
case Properties::West::TALL:
return 20896;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20897;
case Properties::West::LOW:
return 20898;
case Properties::West::TALL:
return 20899;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20900;
case Properties::West::LOW:
return 20901;
case Properties::West::TALL:
return 20902;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20903;
case Properties::West::LOW:
return 20904;
case Properties::West::TALL:
return 20905;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20906;
case Properties::West::LOW:
return 20907;
case Properties::West::TALL:
return 20908;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20909;
case Properties::West::LOW:
return 20910;
case Properties::West::TALL:
return 20911;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20912;
case Properties::West::LOW:
return 20913;
case Properties::West::TALL:
return 20914;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20915;
case Properties::West::LOW:
return 20916;
case Properties::West::TALL:
return 20917;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20918;
case Properties::West::LOW:
return 20919;
case Properties::West::TALL:
return 20920;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20921;
case Properties::West::LOW:
return 20922;
case Properties::West::TALL:
return 20923;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20924;
case Properties::West::LOW:
return 20925;
case Properties::West::TALL:
return 20926;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20927;
case Properties::West::LOW:
return 20928;
case Properties::West::TALL:
return 20929;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20930;
case Properties::West::LOW:
return 20931;
case Properties::West::TALL:
return 20932;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20933;
case Properties::West::LOW:
return 20934;
case Properties::West::TALL:
return 20935;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20936;
case Properties::West::LOW:
return 20937;
case Properties::West::TALL:
return 20938;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20939;
case Properties::West::LOW:
return 20940;
case Properties::West::TALL:
return 20941;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20942;
case Properties::West::LOW:
return 20943;
case Properties::West::TALL:
return 20944;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20945;
case Properties::West::LOW:
return 20946;
case Properties::West::TALL:
return 20947;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20948;
case Properties::West::LOW:
return 20949;
case Properties::West::TALL:
return 20950;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20951;
case Properties::West::LOW:
return 20952;
case Properties::West::TALL:
return 20953;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20954;
case Properties::West::LOW:
return 20955;
case Properties::West::TALL:
return 20956;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20957;
case Properties::West::LOW:
return 20958;
case Properties::West::TALL:
return 20959;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20960;
case Properties::West::LOW:
return 20961;
case Properties::West::TALL:
return 20962;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20963;
case Properties::West::LOW:
return 20964;
case Properties::West::TALL:
return 20965;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20966;
case Properties::West::LOW:
return 20967;
case Properties::West::TALL:
return 20968;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20969;
case Properties::West::LOW:
return 20970;
case Properties::West::TALL:
return 20971;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20972;
case Properties::West::LOW:
return 20973;
case Properties::West::TALL:
return 20974;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20975;
case Properties::West::LOW:
return 20976;
case Properties::West::TALL:
return 20977;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20978;
case Properties::West::LOW:
return 20979;
case Properties::West::TALL:
return 20980;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20981;
case Properties::West::LOW:
return 20982;
case Properties::West::TALL:
return 20983;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20984;
case Properties::West::LOW:
return 20985;
case Properties::West::TALL:
return 20986;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20987;
case Properties::West::LOW:
return 20988;
case Properties::West::TALL:
return 20989;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20990;
case Properties::West::LOW:
return 20991;
case Properties::West::TALL:
return 20992;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20993;
case Properties::West::LOW:
return 20994;
case Properties::West::TALL:
return 20995;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 20996;
case Properties::West::LOW:
return 20997;
case Properties::West::TALL:
return 20998;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 20999;
case Properties::West::LOW:
return 21000;
case Properties::West::TALL:
return 21001;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21002;
case Properties::West::LOW:
return 21003;
case Properties::West::TALL:
return 21004;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21005;
case Properties::West::LOW:
return 21006;
case Properties::West::TALL:
return 21007;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 21008;
case Properties::West::LOW:
return 21009;
case Properties::West::TALL:
return 21010;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 21011;
case Properties::West::LOW:
return 21012;
case Properties::West::TALL:
return 21013;
}
}
}
}
}
}
return 0;
}
}

namespace DeepslateTiles {
constexpr Block toProtocol() {
return 20603;
return 0;
}
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
constexpr Block toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (powered) {
case Properties::Powered::TRUE:
switch (shape) {
case Properties::Shape::NORTH_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1559;
case Properties::Waterlogged::FALSE:
return 1560;
}
case Properties::Shape::EAST_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1561;
case Properties::Waterlogged::FALSE:
return 1562;
}
case Properties::Shape::ASCENDING_EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1563;
case Properties::Waterlogged::FALSE:
return 1564;
}
case Properties::Shape::ASCENDING_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1565;
case Properties::Waterlogged::FALSE:
return 1566;
}
case Properties::Shape::ASCENDING_NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1567;
case Properties::Waterlogged::FALSE:
return 1568;
}
case Properties::Shape::ASCENDING_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1569;
case Properties::Waterlogged::FALSE:
return 1570;
}
}
case Properties::Powered::FALSE:
switch (shape) {
case Properties::Shape::NORTH_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1571;
case Properties::Waterlogged::FALSE:
return 1572;
}
case Properties::Shape::EAST_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1573;
case Properties::Waterlogged::FALSE:
return 1574;
}
case Properties::Shape::ASCENDING_EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1575;
case Properties::Waterlogged::FALSE:
return 1576;
}
case Properties::Shape::ASCENDING_WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1577;
case Properties::Waterlogged::FALSE:
return 1578;
}
case Properties::Shape::ASCENDING_NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1579;
case Properties::Waterlogged::FALSE:
return 1580;
}
case Properties::Shape::ASCENDING_SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 1581;
case Properties::Waterlogged::FALSE:
return 1582;
}
}
}
return 0;
}
}

namespace DiamondBlock {
constexpr Block toProtocol() {
return 3610;
return 0;
}
}

namespace DiamondOre {
constexpr Block toProtocol() {
return 3608;
return 0;
}
}

namespace Diorite {
constexpr Block toProtocol() {
return 4;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11742;
case Properties::Waterlogged::FALSE:
return 11743;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11744;
case Properties::Waterlogged::FALSE:
return 11745;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11746;
case Properties::Waterlogged::FALSE:
return 11747;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11590;
case Properties::Waterlogged::FALSE:
return 11591;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11592;
case Properties::Waterlogged::FALSE:
return 11593;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11594;
case Properties::Waterlogged::FALSE:
return 11595;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11596;
case Properties::Waterlogged::FALSE:
return 11597;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11598;
case Properties::Waterlogged::FALSE:
return 11599;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11600;
case Properties::Waterlogged::FALSE:
return 11601;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11602;
case Properties::Waterlogged::FALSE:
return 11603;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11604;
case Properties::Waterlogged::FALSE:
return 11605;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11606;
case Properties::Waterlogged::FALSE:
return 11607;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11608;
case Properties::Waterlogged::FALSE:
return 11609;
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
return 11610;
case Properties::Waterlogged::FALSE:
return 11611;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11612;
case Properties::Waterlogged::FALSE:
return 11613;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11614;
case Properties::Waterlogged::FALSE:
return 11615;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11616;
case Properties::Waterlogged::FALSE:
return 11617;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11618;
case Properties::Waterlogged::FALSE:
return 11619;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11620;
case Properties::Waterlogged::FALSE:
return 11621;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11622;
case Properties::Waterlogged::FALSE:
return 11623;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11624;
case Properties::Waterlogged::FALSE:
return 11625;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11626;
case Properties::Waterlogged::FALSE:
return 11627;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11628;
case Properties::Waterlogged::FALSE:
return 11629;
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
return 11630;
case Properties::Waterlogged::FALSE:
return 11631;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11632;
case Properties::Waterlogged::FALSE:
return 11633;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11634;
case Properties::Waterlogged::FALSE:
return 11635;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11636;
case Properties::Waterlogged::FALSE:
return 11637;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11638;
case Properties::Waterlogged::FALSE:
return 11639;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11640;
case Properties::Waterlogged::FALSE:
return 11641;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11642;
case Properties::Waterlogged::FALSE:
return 11643;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11644;
case Properties::Waterlogged::FALSE:
return 11645;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11646;
case Properties::Waterlogged::FALSE:
return 11647;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11648;
case Properties::Waterlogged::FALSE:
return 11649;
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
return 11650;
case Properties::Waterlogged::FALSE:
return 11651;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11652;
case Properties::Waterlogged::FALSE:
return 11653;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11654;
case Properties::Waterlogged::FALSE:
return 11655;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11656;
case Properties::Waterlogged::FALSE:
return 11657;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11658;
case Properties::Waterlogged::FALSE:
return 11659;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11660;
case Properties::Waterlogged::FALSE:
return 11661;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11662;
case Properties::Waterlogged::FALSE:
return 11663;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11664;
case Properties::Waterlogged::FALSE:
return 11665;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11666;
case Properties::Waterlogged::FALSE:
return 11667;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11668;
case Properties::Waterlogged::FALSE:
return 11669;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15636;
case Properties::West::LOW:
return 15637;
case Properties::West::TALL:
return 15638;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15639;
case Properties::West::LOW:
return 15640;
case Properties::West::TALL:
return 15641;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15642;
case Properties::West::LOW:
return 15643;
case Properties::West::TALL:
return 15644;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15645;
case Properties::West::LOW:
return 15646;
case Properties::West::TALL:
return 15647;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15648;
case Properties::West::LOW:
return 15649;
case Properties::West::TALL:
return 15650;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15651;
case Properties::West::LOW:
return 15652;
case Properties::West::TALL:
return 15653;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15654;
case Properties::West::LOW:
return 15655;
case Properties::West::TALL:
return 15656;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15657;
case Properties::West::LOW:
return 15658;
case Properties::West::TALL:
return 15659;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15660;
case Properties::West::LOW:
return 15661;
case Properties::West::TALL:
return 15662;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15663;
case Properties::West::LOW:
return 15664;
case Properties::West::TALL:
return 15665;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15666;
case Properties::West::LOW:
return 15667;
case Properties::West::TALL:
return 15668;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15669;
case Properties::West::LOW:
return 15670;
case Properties::West::TALL:
return 15671;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15672;
case Properties::West::LOW:
return 15673;
case Properties::West::TALL:
return 15674;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15675;
case Properties::West::LOW:
return 15676;
case Properties::West::TALL:
return 15677;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15678;
case Properties::West::LOW:
return 15679;
case Properties::West::TALL:
return 15680;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15681;
case Properties::West::LOW:
return 15682;
case Properties::West::TALL:
return 15683;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15684;
case Properties::West::LOW:
return 15685;
case Properties::West::TALL:
return 15686;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15687;
case Properties::West::LOW:
return 15688;
case Properties::West::TALL:
return 15689;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15690;
case Properties::West::LOW:
return 15691;
case Properties::West::TALL:
return 15692;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15693;
case Properties::West::LOW:
return 15694;
case Properties::West::TALL:
return 15695;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15696;
case Properties::West::LOW:
return 15697;
case Properties::West::TALL:
return 15698;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15699;
case Properties::West::LOW:
return 15700;
case Properties::West::TALL:
return 15701;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15702;
case Properties::West::LOW:
return 15703;
case Properties::West::TALL:
return 15704;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15705;
case Properties::West::LOW:
return 15706;
case Properties::West::TALL:
return 15707;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15708;
case Properties::West::LOW:
return 15709;
case Properties::West::TALL:
return 15710;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15711;
case Properties::West::LOW:
return 15712;
case Properties::West::TALL:
return 15713;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15714;
case Properties::West::LOW:
return 15715;
case Properties::West::TALL:
return 15716;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15717;
case Properties::West::LOW:
return 15718;
case Properties::West::TALL:
return 15719;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15720;
case Properties::West::LOW:
return 15721;
case Properties::West::TALL:
return 15722;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15723;
case Properties::West::LOW:
return 15724;
case Properties::West::TALL:
return 15725;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15726;
case Properties::West::LOW:
return 15727;
case Properties::West::TALL:
return 15728;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15729;
case Properties::West::LOW:
return 15730;
case Properties::West::TALL:
return 15731;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15732;
case Properties::West::LOW:
return 15733;
case Properties::West::TALL:
return 15734;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15735;
case Properties::West::LOW:
return 15736;
case Properties::West::TALL:
return 15737;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15738;
case Properties::West::LOW:
return 15739;
case Properties::West::TALL:
return 15740;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15741;
case Properties::West::LOW:
return 15742;
case Properties::West::TALL:
return 15743;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15744;
case Properties::West::LOW:
return 15745;
case Properties::West::TALL:
return 15746;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15747;
case Properties::West::LOW:
return 15748;
case Properties::West::TALL:
return 15749;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15750;
case Properties::West::LOW:
return 15751;
case Properties::West::TALL:
return 15752;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15753;
case Properties::West::LOW:
return 15754;
case Properties::West::TALL:
return 15755;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15756;
case Properties::West::LOW:
return 15757;
case Properties::West::TALL:
return 15758;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15759;
case Properties::West::LOW:
return 15760;
case Properties::West::TALL:
return 15761;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15762;
case Properties::West::LOW:
return 15763;
case Properties::West::TALL:
return 15764;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15765;
case Properties::West::LOW:
return 15766;
case Properties::West::TALL:
return 15767;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15768;
case Properties::West::LOW:
return 15769;
case Properties::West::TALL:
return 15770;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15771;
case Properties::West::LOW:
return 15772;
case Properties::West::TALL:
return 15773;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15774;
case Properties::West::LOW:
return 15775;
case Properties::West::TALL:
return 15776;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15777;
case Properties::West::LOW:
return 15778;
case Properties::West::TALL:
return 15779;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15780;
case Properties::West::LOW:
return 15781;
case Properties::West::TALL:
return 15782;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15783;
case Properties::West::LOW:
return 15784;
case Properties::West::TALL:
return 15785;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15786;
case Properties::West::LOW:
return 15787;
case Properties::West::TALL:
return 15788;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15789;
case Properties::West::LOW:
return 15790;
case Properties::West::TALL:
return 15791;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15792;
case Properties::West::LOW:
return 15793;
case Properties::West::TALL:
return 15794;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15795;
case Properties::West::LOW:
return 15796;
case Properties::West::TALL:
return 15797;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15798;
case Properties::West::LOW:
return 15799;
case Properties::West::TALL:
return 15800;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15801;
case Properties::West::LOW:
return 15802;
case Properties::West::TALL:
return 15803;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15804;
case Properties::West::LOW:
return 15805;
case Properties::West::TALL:
return 15806;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15807;
case Properties::West::LOW:
return 15808;
case Properties::West::TALL:
return 15809;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15810;
case Properties::West::LOW:
return 15811;
case Properties::West::TALL:
return 15812;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15813;
case Properties::West::LOW:
return 15814;
case Properties::West::TALL:
return 15815;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15816;
case Properties::West::LOW:
return 15817;
case Properties::West::TALL:
return 15818;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15819;
case Properties::West::LOW:
return 15820;
case Properties::West::TALL:
return 15821;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15822;
case Properties::West::LOW:
return 15823;
case Properties::West::TALL:
return 15824;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15825;
case Properties::West::LOW:
return 15826;
case Properties::West::TALL:
return 15827;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15828;
case Properties::West::LOW:
return 15829;
case Properties::West::TALL:
return 15830;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15831;
case Properties::West::LOW:
return 15832;
case Properties::West::TALL:
return 15833;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15834;
case Properties::West::LOW:
return 15835;
case Properties::West::TALL:
return 15836;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15837;
case Properties::West::LOW:
return 15838;
case Properties::West::TALL:
return 15839;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15840;
case Properties::West::LOW:
return 15841;
case Properties::West::TALL:
return 15842;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15843;
case Properties::West::LOW:
return 15844;
case Properties::West::TALL:
return 15845;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15846;
case Properties::West::LOW:
return 15847;
case Properties::West::TALL:
return 15848;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15849;
case Properties::West::LOW:
return 15850;
case Properties::West::TALL:
return 15851;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15852;
case Properties::West::LOW:
return 15853;
case Properties::West::TALL:
return 15854;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15855;
case Properties::West::LOW:
return 15856;
case Properties::West::TALL:
return 15857;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15858;
case Properties::West::LOW:
return 15859;
case Properties::West::TALL:
return 15860;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15861;
case Properties::West::LOW:
return 15862;
case Properties::West::TALL:
return 15863;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15864;
case Properties::West::LOW:
return 15865;
case Properties::West::TALL:
return 15866;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15867;
case Properties::West::LOW:
return 15868;
case Properties::West::TALL:
return 15869;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15870;
case Properties::West::LOW:
return 15871;
case Properties::West::TALL:
return 15872;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15873;
case Properties::West::LOW:
return 15874;
case Properties::West::TALL:
return 15875;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15876;
case Properties::West::LOW:
return 15877;
case Properties::West::TALL:
return 15878;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15879;
case Properties::West::LOW:
return 15880;
case Properties::West::TALL:
return 15881;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15882;
case Properties::West::LOW:
return 15883;
case Properties::West::TALL:
return 15884;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15885;
case Properties::West::LOW:
return 15886;
case Properties::West::TALL:
return 15887;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15888;
case Properties::West::LOW:
return 15889;
case Properties::West::TALL:
return 15890;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15891;
case Properties::West::LOW:
return 15892;
case Properties::West::TALL:
return 15893;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15894;
case Properties::West::LOW:
return 15895;
case Properties::West::TALL:
return 15896;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15897;
case Properties::West::LOW:
return 15898;
case Properties::West::TALL:
return 15899;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15900;
case Properties::West::LOW:
return 15901;
case Properties::West::TALL:
return 15902;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15903;
case Properties::West::LOW:
return 15904;
case Properties::West::TALL:
return 15905;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15906;
case Properties::West::LOW:
return 15907;
case Properties::West::TALL:
return 15908;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15909;
case Properties::West::LOW:
return 15910;
case Properties::West::TALL:
return 15911;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15912;
case Properties::West::LOW:
return 15913;
case Properties::West::TALL:
return 15914;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15915;
case Properties::West::LOW:
return 15916;
case Properties::West::TALL:
return 15917;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15918;
case Properties::West::LOW:
return 15919;
case Properties::West::TALL:
return 15920;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15921;
case Properties::West::LOW:
return 15922;
case Properties::West::TALL:
return 15923;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15924;
case Properties::West::LOW:
return 15925;
case Properties::West::TALL:
return 15926;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15927;
case Properties::West::LOW:
return 15928;
case Properties::West::TALL:
return 15929;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15930;
case Properties::West::LOW:
return 15931;
case Properties::West::TALL:
return 15932;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15933;
case Properties::West::LOW:
return 15934;
case Properties::West::TALL:
return 15935;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15936;
case Properties::West::LOW:
return 15937;
case Properties::West::TALL:
return 15938;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15939;
case Properties::West::LOW:
return 15940;
case Properties::West::TALL:
return 15941;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15942;
case Properties::West::LOW:
return 15943;
case Properties::West::TALL:
return 15944;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15945;
case Properties::West::LOW:
return 15946;
case Properties::West::TALL:
return 15947;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15948;
case Properties::West::LOW:
return 15949;
case Properties::West::TALL:
return 15950;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15951;
case Properties::West::LOW:
return 15952;
case Properties::West::TALL:
return 15953;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15954;
case Properties::West::LOW:
return 15955;
case Properties::West::TALL:
return 15956;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15957;
case Properties::West::LOW:
return 15958;
case Properties::West::TALL:
return 15959;
}
}
}
}
}
}
return 0;
}
}

namespace Dirt {
constexpr Block toProtocol() {
return 10;
return 0;
}
}

namespace DirtPath {
constexpr Block toProtocol() {
return 10104;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Triggered triggered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (triggered) {
case Properties::Triggered::TRUE:
return 464;
case Properties::Triggered::FALSE:
return 465;
}
case Properties::Facing::EAST:
switch (triggered) {
case Properties::Triggered::TRUE:
return 466;
case Properties::Triggered::FALSE:
return 467;
}
case Properties::Facing::SOUTH:
switch (triggered) {
case Properties::Triggered::TRUE:
return 468;
case Properties::Triggered::FALSE:
return 469;
}
case Properties::Facing::WEST:
switch (triggered) {
case Properties::Triggered::TRUE:
return 470;
case Properties::Triggered::FALSE:
return 471;
}
case Properties::Facing::UP:
switch (triggered) {
case Properties::Triggered::TRUE:
return 472;
case Properties::Triggered::FALSE:
return 473;
}
case Properties::Facing::DOWN:
switch (triggered) {
case Properties::Triggered::TRUE:
return 474;
case Properties::Triggered::FALSE:
return 475;
}
}
return 0;
}
}

namespace DragonEgg {
constexpr Block toProtocol() {
return 5746;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 7207;
case Properties::Rotation::ONE:
return 7208;
case Properties::Rotation::TWO:
return 7209;
case Properties::Rotation::THREE:
return 7210;
case Properties::Rotation::FOUR:
return 7211;
case Properties::Rotation::FIVE:
return 7212;
case Properties::Rotation::SIX:
return 7213;
case Properties::Rotation::SEVEN:
return 7214;
case Properties::Rotation::EIGHT:
return 7215;
case Properties::Rotation::NINE:
return 7216;
case Properties::Rotation::TEN:
return 7217;
case Properties::Rotation::ELEVEN:
return 7218;
case Properties::Rotation::TWELVE:
return 7219;
case Properties::Rotation::THIRTEEN:
return 7220;
case Properties::Rotation::FOURTEEN:
return 7221;
case Properties::Rotation::FIFTEEN:
return 7222;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 7223;
case Properties::Facing::SOUTH:
return 7224;
case Properties::Facing::WEST:
return 7225;
case Properties::Facing::EAST:
return 7226;
}
return 0;
}
}

namespace DriedKelpBlock {
constexpr Block toProtocol() {
return 10378;
return 0;
}
}

namespace DripstoneBlock {
constexpr Block toProtocol() {
return 19658;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Triggered triggered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (triggered) {
case Properties::Triggered::TRUE:
return 7464;
case Properties::Triggered::FALSE:
return 7465;
}
case Properties::Facing::EAST:
switch (triggered) {
case Properties::Triggered::TRUE:
return 7466;
case Properties::Triggered::FALSE:
return 7467;
}
case Properties::Facing::SOUTH:
switch (triggered) {
case Properties::Triggered::TRUE:
return 7468;
case Properties::Triggered::FALSE:
return 7469;
}
case Properties::Facing::WEST:
switch (triggered) {
case Properties::Triggered::TRUE:
return 7470;
case Properties::Triggered::FALSE:
return 7471;
}
case Properties::Facing::UP:
switch (triggered) {
case Properties::Triggered::TRUE:
return 7472;
case Properties::Triggered::FALSE:
return 7473;
}
case Properties::Facing::DOWN:
switch (triggered) {
case Properties::Triggered::TRUE:
return 7474;
case Properties::Triggered::FALSE:
return 7475;
}
}
return 0;
}
}

namespace EmeraldBlock {
constexpr Block toProtocol() {
return 5995;
return 0;
}
}

namespace EmeraldOre {
constexpr Block toProtocol() {
return 5841;
return 0;
}
}

namespace EnchantingTable {
constexpr Block toProtocol() {
return 5719;
return 0;
}
}

namespace EndGateway {
constexpr Block toProtocol() {
return 10105;
return 0;
}
}

namespace EndPortal {
constexpr Block toProtocol() {
return 5736;
return 0;
}
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
constexpr Block toProtocol(Properties::Eye eye, Properties::Facing facing) {
switch (eye) {
case Properties::Eye::TRUE:
switch (facing) {
case Properties::Facing::NORTH:
return 5737;
case Properties::Facing::SOUTH:
return 5738;
case Properties::Facing::WEST:
return 5739;
case Properties::Facing::EAST:
return 5740;
}
case Properties::Eye::FALSE:
switch (facing) {
case Properties::Facing::NORTH:
return 5741;
case Properties::Facing::SOUTH:
return 5742;
case Properties::Facing::WEST:
return 5743;
case Properties::Facing::EAST:
return 5744;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 9939;
case Properties::Facing::EAST:
return 9940;
case Properties::Facing::SOUTH:
return 9941;
case Properties::Facing::WEST:
return 9942;
case Properties::Facing::UP:
return 9943;
case Properties::Facing::DOWN:
return 9944;
}
return 0;
}
}

namespace EndStone {
constexpr Block toProtocol() {
return 5745;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11700;
case Properties::Waterlogged::FALSE:
return 11701;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11702;
case Properties::Waterlogged::FALSE:
return 11703;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11704;
case Properties::Waterlogged::FALSE:
return 11705;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10950;
case Properties::Waterlogged::FALSE:
return 10951;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10952;
case Properties::Waterlogged::FALSE:
return 10953;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10954;
case Properties::Waterlogged::FALSE:
return 10955;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10956;
case Properties::Waterlogged::FALSE:
return 10957;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10958;
case Properties::Waterlogged::FALSE:
return 10959;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10960;
case Properties::Waterlogged::FALSE:
return 10961;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10962;
case Properties::Waterlogged::FALSE:
return 10963;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10964;
case Properties::Waterlogged::FALSE:
return 10965;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10966;
case Properties::Waterlogged::FALSE:
return 10967;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10968;
case Properties::Waterlogged::FALSE:
return 10969;
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
return 10970;
case Properties::Waterlogged::FALSE:
return 10971;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10972;
case Properties::Waterlogged::FALSE:
return 10973;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10974;
case Properties::Waterlogged::FALSE:
return 10975;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10976;
case Properties::Waterlogged::FALSE:
return 10977;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10978;
case Properties::Waterlogged::FALSE:
return 10979;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10980;
case Properties::Waterlogged::FALSE:
return 10981;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10982;
case Properties::Waterlogged::FALSE:
return 10983;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10984;
case Properties::Waterlogged::FALSE:
return 10985;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10986;
case Properties::Waterlogged::FALSE:
return 10987;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10988;
case Properties::Waterlogged::FALSE:
return 10989;
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
return 10990;
case Properties::Waterlogged::FALSE:
return 10991;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10992;
case Properties::Waterlogged::FALSE:
return 10993;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10994;
case Properties::Waterlogged::FALSE:
return 10995;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10996;
case Properties::Waterlogged::FALSE:
return 10997;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10998;
case Properties::Waterlogged::FALSE:
return 10999;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11000;
case Properties::Waterlogged::FALSE:
return 11001;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11002;
case Properties::Waterlogged::FALSE:
return 11003;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11004;
case Properties::Waterlogged::FALSE:
return 11005;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11006;
case Properties::Waterlogged::FALSE:
return 11007;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11008;
case Properties::Waterlogged::FALSE:
return 11009;
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
return 11010;
case Properties::Waterlogged::FALSE:
return 11011;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11012;
case Properties::Waterlogged::FALSE:
return 11013;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11014;
case Properties::Waterlogged::FALSE:
return 11015;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11016;
case Properties::Waterlogged::FALSE:
return 11017;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11018;
case Properties::Waterlogged::FALSE:
return 11019;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11020;
case Properties::Waterlogged::FALSE:
return 11021;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11022;
case Properties::Waterlogged::FALSE:
return 11023;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11024;
case Properties::Waterlogged::FALSE:
return 11025;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11026;
case Properties::Waterlogged::FALSE:
return 11027;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11028;
case Properties::Waterlogged::FALSE:
return 11029;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15312;
case Properties::West::LOW:
return 15313;
case Properties::West::TALL:
return 15314;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15315;
case Properties::West::LOW:
return 15316;
case Properties::West::TALL:
return 15317;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15318;
case Properties::West::LOW:
return 15319;
case Properties::West::TALL:
return 15320;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15321;
case Properties::West::LOW:
return 15322;
case Properties::West::TALL:
return 15323;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15324;
case Properties::West::LOW:
return 15325;
case Properties::West::TALL:
return 15326;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15327;
case Properties::West::LOW:
return 15328;
case Properties::West::TALL:
return 15329;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15330;
case Properties::West::LOW:
return 15331;
case Properties::West::TALL:
return 15332;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15333;
case Properties::West::LOW:
return 15334;
case Properties::West::TALL:
return 15335;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15336;
case Properties::West::LOW:
return 15337;
case Properties::West::TALL:
return 15338;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15339;
case Properties::West::LOW:
return 15340;
case Properties::West::TALL:
return 15341;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15342;
case Properties::West::LOW:
return 15343;
case Properties::West::TALL:
return 15344;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15345;
case Properties::West::LOW:
return 15346;
case Properties::West::TALL:
return 15347;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15348;
case Properties::West::LOW:
return 15349;
case Properties::West::TALL:
return 15350;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15351;
case Properties::West::LOW:
return 15352;
case Properties::West::TALL:
return 15353;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15354;
case Properties::West::LOW:
return 15355;
case Properties::West::TALL:
return 15356;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15357;
case Properties::West::LOW:
return 15358;
case Properties::West::TALL:
return 15359;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15360;
case Properties::West::LOW:
return 15361;
case Properties::West::TALL:
return 15362;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15363;
case Properties::West::LOW:
return 15364;
case Properties::West::TALL:
return 15365;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15366;
case Properties::West::LOW:
return 15367;
case Properties::West::TALL:
return 15368;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15369;
case Properties::West::LOW:
return 15370;
case Properties::West::TALL:
return 15371;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15372;
case Properties::West::LOW:
return 15373;
case Properties::West::TALL:
return 15374;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15375;
case Properties::West::LOW:
return 15376;
case Properties::West::TALL:
return 15377;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15378;
case Properties::West::LOW:
return 15379;
case Properties::West::TALL:
return 15380;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15381;
case Properties::West::LOW:
return 15382;
case Properties::West::TALL:
return 15383;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15384;
case Properties::West::LOW:
return 15385;
case Properties::West::TALL:
return 15386;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15387;
case Properties::West::LOW:
return 15388;
case Properties::West::TALL:
return 15389;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15390;
case Properties::West::LOW:
return 15391;
case Properties::West::TALL:
return 15392;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15393;
case Properties::West::LOW:
return 15394;
case Properties::West::TALL:
return 15395;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15396;
case Properties::West::LOW:
return 15397;
case Properties::West::TALL:
return 15398;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15399;
case Properties::West::LOW:
return 15400;
case Properties::West::TALL:
return 15401;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15402;
case Properties::West::LOW:
return 15403;
case Properties::West::TALL:
return 15404;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15405;
case Properties::West::LOW:
return 15406;
case Properties::West::TALL:
return 15407;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15408;
case Properties::West::LOW:
return 15409;
case Properties::West::TALL:
return 15410;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15411;
case Properties::West::LOW:
return 15412;
case Properties::West::TALL:
return 15413;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15414;
case Properties::West::LOW:
return 15415;
case Properties::West::TALL:
return 15416;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15417;
case Properties::West::LOW:
return 15418;
case Properties::West::TALL:
return 15419;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15420;
case Properties::West::LOW:
return 15421;
case Properties::West::TALL:
return 15422;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15423;
case Properties::West::LOW:
return 15424;
case Properties::West::TALL:
return 15425;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15426;
case Properties::West::LOW:
return 15427;
case Properties::West::TALL:
return 15428;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15429;
case Properties::West::LOW:
return 15430;
case Properties::West::TALL:
return 15431;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15432;
case Properties::West::LOW:
return 15433;
case Properties::West::TALL:
return 15434;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15435;
case Properties::West::LOW:
return 15436;
case Properties::West::TALL:
return 15437;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15438;
case Properties::West::LOW:
return 15439;
case Properties::West::TALL:
return 15440;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15441;
case Properties::West::LOW:
return 15442;
case Properties::West::TALL:
return 15443;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15444;
case Properties::West::LOW:
return 15445;
case Properties::West::TALL:
return 15446;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15447;
case Properties::West::LOW:
return 15448;
case Properties::West::TALL:
return 15449;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15450;
case Properties::West::LOW:
return 15451;
case Properties::West::TALL:
return 15452;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15453;
case Properties::West::LOW:
return 15454;
case Properties::West::TALL:
return 15455;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15456;
case Properties::West::LOW:
return 15457;
case Properties::West::TALL:
return 15458;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15459;
case Properties::West::LOW:
return 15460;
case Properties::West::TALL:
return 15461;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15462;
case Properties::West::LOW:
return 15463;
case Properties::West::TALL:
return 15464;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15465;
case Properties::West::LOW:
return 15466;
case Properties::West::TALL:
return 15467;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15468;
case Properties::West::LOW:
return 15469;
case Properties::West::TALL:
return 15470;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15471;
case Properties::West::LOW:
return 15472;
case Properties::West::TALL:
return 15473;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15474;
case Properties::West::LOW:
return 15475;
case Properties::West::TALL:
return 15476;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15477;
case Properties::West::LOW:
return 15478;
case Properties::West::TALL:
return 15479;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15480;
case Properties::West::LOW:
return 15481;
case Properties::West::TALL:
return 15482;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15483;
case Properties::West::LOW:
return 15484;
case Properties::West::TALL:
return 15485;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15486;
case Properties::West::LOW:
return 15487;
case Properties::West::TALL:
return 15488;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15489;
case Properties::West::LOW:
return 15490;
case Properties::West::TALL:
return 15491;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15492;
case Properties::West::LOW:
return 15493;
case Properties::West::TALL:
return 15494;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15495;
case Properties::West::LOW:
return 15496;
case Properties::West::TALL:
return 15497;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15498;
case Properties::West::LOW:
return 15499;
case Properties::West::TALL:
return 15500;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15501;
case Properties::West::LOW:
return 15502;
case Properties::West::TALL:
return 15503;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15504;
case Properties::West::LOW:
return 15505;
case Properties::West::TALL:
return 15506;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15507;
case Properties::West::LOW:
return 15508;
case Properties::West::TALL:
return 15509;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15510;
case Properties::West::LOW:
return 15511;
case Properties::West::TALL:
return 15512;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15513;
case Properties::West::LOW:
return 15514;
case Properties::West::TALL:
return 15515;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15516;
case Properties::West::LOW:
return 15517;
case Properties::West::TALL:
return 15518;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15519;
case Properties::West::LOW:
return 15520;
case Properties::West::TALL:
return 15521;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15522;
case Properties::West::LOW:
return 15523;
case Properties::West::TALL:
return 15524;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15525;
case Properties::West::LOW:
return 15526;
case Properties::West::TALL:
return 15527;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15528;
case Properties::West::LOW:
return 15529;
case Properties::West::TALL:
return 15530;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15531;
case Properties::West::LOW:
return 15532;
case Properties::West::TALL:
return 15533;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15534;
case Properties::West::LOW:
return 15535;
case Properties::West::TALL:
return 15536;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15537;
case Properties::West::LOW:
return 15538;
case Properties::West::TALL:
return 15539;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15540;
case Properties::West::LOW:
return 15541;
case Properties::West::TALL:
return 15542;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15543;
case Properties::West::LOW:
return 15544;
case Properties::West::TALL:
return 15545;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15546;
case Properties::West::LOW:
return 15547;
case Properties::West::TALL:
return 15548;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15549;
case Properties::West::LOW:
return 15550;
case Properties::West::TALL:
return 15551;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15552;
case Properties::West::LOW:
return 15553;
case Properties::West::TALL:
return 15554;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15555;
case Properties::West::LOW:
return 15556;
case Properties::West::TALL:
return 15557;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15558;
case Properties::West::LOW:
return 15559;
case Properties::West::TALL:
return 15560;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15561;
case Properties::West::LOW:
return 15562;
case Properties::West::TALL:
return 15563;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15564;
case Properties::West::LOW:
return 15565;
case Properties::West::TALL:
return 15566;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15567;
case Properties::West::LOW:
return 15568;
case Properties::West::TALL:
return 15569;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15570;
case Properties::West::LOW:
return 15571;
case Properties::West::TALL:
return 15572;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15573;
case Properties::West::LOW:
return 15574;
case Properties::West::TALL:
return 15575;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15576;
case Properties::West::LOW:
return 15577;
case Properties::West::TALL:
return 15578;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15579;
case Properties::West::LOW:
return 15580;
case Properties::West::TALL:
return 15581;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15582;
case Properties::West::LOW:
return 15583;
case Properties::West::TALL:
return 15584;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15585;
case Properties::West::LOW:
return 15586;
case Properties::West::TALL:
return 15587;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15588;
case Properties::West::LOW:
return 15589;
case Properties::West::TALL:
return 15590;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15591;
case Properties::West::LOW:
return 15592;
case Properties::West::TALL:
return 15593;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15594;
case Properties::West::LOW:
return 15595;
case Properties::West::TALL:
return 15596;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15597;
case Properties::West::LOW:
return 15598;
case Properties::West::TALL:
return 15599;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15600;
case Properties::West::LOW:
return 15601;
case Properties::West::TALL:
return 15602;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15603;
case Properties::West::LOW:
return 15604;
case Properties::West::TALL:
return 15605;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15606;
case Properties::West::LOW:
return 15607;
case Properties::West::TALL:
return 15608;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15609;
case Properties::West::LOW:
return 15610;
case Properties::West::TALL:
return 15611;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15612;
case Properties::West::LOW:
return 15613;
case Properties::West::TALL:
return 15614;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15615;
case Properties::West::LOW:
return 15616;
case Properties::West::TALL:
return 15617;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15618;
case Properties::West::LOW:
return 15619;
case Properties::West::TALL:
return 15620;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15621;
case Properties::West::LOW:
return 15622;
case Properties::West::TALL:
return 15623;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15624;
case Properties::West::LOW:
return 15625;
case Properties::West::TALL:
return 15626;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15627;
case Properties::West::LOW:
return 15628;
case Properties::West::TALL:
return 15629;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 15630;
case Properties::West::LOW:
return 15631;
case Properties::West::TALL:
return 15632;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 15633;
case Properties::West::LOW:
return 15634;
case Properties::West::TALL:
return 15635;
}
}
}
}
}
}
return 0;
}
}

namespace EndStoneBricks {
constexpr Block toProtocol() {
return 10099;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5843;
case Properties::Waterlogged::FALSE:
return 5844;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5845;
case Properties::Waterlogged::FALSE:
return 5846;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5847;
case Properties::Waterlogged::FALSE:
return 5848;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5849;
case Properties::Waterlogged::FALSE:
return 5850;
}
}
return 0;
}
}

namespace ExposedCopper {
constexpr Block toProtocol() {
return 18910;
return 0;
}
}

namespace ExposedCutCopper {
constexpr Block toProtocol() {
return 18916;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19250;
case Properties::Waterlogged::FALSE:
return 19251;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19252;
case Properties::Waterlogged::FALSE:
return 19253;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19254;
case Properties::Waterlogged::FALSE:
return 19255;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19078;
case Properties::Waterlogged::FALSE:
return 19079;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19080;
case Properties::Waterlogged::FALSE:
return 19081;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19082;
case Properties::Waterlogged::FALSE:
return 19083;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19084;
case Properties::Waterlogged::FALSE:
return 19085;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19086;
case Properties::Waterlogged::FALSE:
return 19087;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19088;
case Properties::Waterlogged::FALSE:
return 19089;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19090;
case Properties::Waterlogged::FALSE:
return 19091;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19092;
case Properties::Waterlogged::FALSE:
return 19093;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19094;
case Properties::Waterlogged::FALSE:
return 19095;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19096;
case Properties::Waterlogged::FALSE:
return 19097;
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
return 19098;
case Properties::Waterlogged::FALSE:
return 19099;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19100;
case Properties::Waterlogged::FALSE:
return 19101;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19102;
case Properties::Waterlogged::FALSE:
return 19103;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19104;
case Properties::Waterlogged::FALSE:
return 19105;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19106;
case Properties::Waterlogged::FALSE:
return 19107;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19108;
case Properties::Waterlogged::FALSE:
return 19109;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19110;
case Properties::Waterlogged::FALSE:
return 19111;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19112;
case Properties::Waterlogged::FALSE:
return 19113;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19114;
case Properties::Waterlogged::FALSE:
return 19115;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19116;
case Properties::Waterlogged::FALSE:
return 19117;
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
return 19118;
case Properties::Waterlogged::FALSE:
return 19119;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19120;
case Properties::Waterlogged::FALSE:
return 19121;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19122;
case Properties::Waterlogged::FALSE:
return 19123;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19124;
case Properties::Waterlogged::FALSE:
return 19125;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19126;
case Properties::Waterlogged::FALSE:
return 19127;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19128;
case Properties::Waterlogged::FALSE:
return 19129;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19130;
case Properties::Waterlogged::FALSE:
return 19131;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19132;
case Properties::Waterlogged::FALSE:
return 19133;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19134;
case Properties::Waterlogged::FALSE:
return 19135;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19136;
case Properties::Waterlogged::FALSE:
return 19137;
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
return 19138;
case Properties::Waterlogged::FALSE:
return 19139;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19140;
case Properties::Waterlogged::FALSE:
return 19141;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19142;
case Properties::Waterlogged::FALSE:
return 19143;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19144;
case Properties::Waterlogged::FALSE:
return 19145;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19146;
case Properties::Waterlogged::FALSE:
return 19147;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19148;
case Properties::Waterlogged::FALSE:
return 19149;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19150;
case Properties::Waterlogged::FALSE:
return 19151;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19152;
case Properties::Waterlogged::FALSE:
return 19153;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19154;
case Properties::Waterlogged::FALSE:
return 19155;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19156;
case Properties::Waterlogged::FALSE:
return 19157;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Moisture moisture) {
switch (moisture) {
case Properties::Moisture::ZERO:
return 3620;
case Properties::Moisture::ONE:
return 3621;
case Properties::Moisture::TWO:
return 3622;
case Properties::Moisture::THREE:
return 3623;
case Properties::Moisture::FOUR:
return 3624;
case Properties::Moisture::FIVE:
return 3625;
case Properties::Moisture::SIX:
return 3626;
case Properties::Moisture::SEVEN:
return 3627;
}
return 0;
}
}

namespace Fern {
constexpr Block toProtocol() {
return 1597;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
switch (age) {
case Properties::Age::ZERO:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1694;
case Properties::West::FALSE:
return 1695;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1696;
case Properties::West::FALSE:
return 1697;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1698;
case Properties::West::FALSE:
return 1699;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1700;
case Properties::West::FALSE:
return 1701;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1702;
case Properties::West::FALSE:
return 1703;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1704;
case Properties::West::FALSE:
return 1705;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1706;
case Properties::West::FALSE:
return 1707;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1708;
case Properties::West::FALSE:
return 1709;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1710;
case Properties::West::FALSE:
return 1711;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1712;
case Properties::West::FALSE:
return 1713;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1714;
case Properties::West::FALSE:
return 1715;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1716;
case Properties::West::FALSE:
return 1717;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1718;
case Properties::West::FALSE:
return 1719;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1720;
case Properties::West::FALSE:
return 1721;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1722;
case Properties::West::FALSE:
return 1723;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1724;
case Properties::West::FALSE:
return 1725;
}
}
}
}
}
case Properties::Age::ONE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1726;
case Properties::West::FALSE:
return 1727;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1728;
case Properties::West::FALSE:
return 1729;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1730;
case Properties::West::FALSE:
return 1731;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1732;
case Properties::West::FALSE:
return 1733;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1734;
case Properties::West::FALSE:
return 1735;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1736;
case Properties::West::FALSE:
return 1737;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1738;
case Properties::West::FALSE:
return 1739;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1740;
case Properties::West::FALSE:
return 1741;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1742;
case Properties::West::FALSE:
return 1743;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1744;
case Properties::West::FALSE:
return 1745;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1746;
case Properties::West::FALSE:
return 1747;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1748;
case Properties::West::FALSE:
return 1749;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1750;
case Properties::West::FALSE:
return 1751;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1752;
case Properties::West::FALSE:
return 1753;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1754;
case Properties::West::FALSE:
return 1755;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1756;
case Properties::West::FALSE:
return 1757;
}
}
}
}
}
case Properties::Age::TWO:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1758;
case Properties::West::FALSE:
return 1759;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1760;
case Properties::West::FALSE:
return 1761;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1762;
case Properties::West::FALSE:
return 1763;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1764;
case Properties::West::FALSE:
return 1765;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1766;
case Properties::West::FALSE:
return 1767;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1768;
case Properties::West::FALSE:
return 1769;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1770;
case Properties::West::FALSE:
return 1771;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1772;
case Properties::West::FALSE:
return 1773;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1774;
case Properties::West::FALSE:
return 1775;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1776;
case Properties::West::FALSE:
return 1777;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1778;
case Properties::West::FALSE:
return 1779;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1780;
case Properties::West::FALSE:
return 1781;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1782;
case Properties::West::FALSE:
return 1783;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1784;
case Properties::West::FALSE:
return 1785;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1786;
case Properties::West::FALSE:
return 1787;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1788;
case Properties::West::FALSE:
return 1789;
}
}
}
}
}
case Properties::Age::THREE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1790;
case Properties::West::FALSE:
return 1791;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1792;
case Properties::West::FALSE:
return 1793;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1794;
case Properties::West::FALSE:
return 1795;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1796;
case Properties::West::FALSE:
return 1797;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1798;
case Properties::West::FALSE:
return 1799;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1800;
case Properties::West::FALSE:
return 1801;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1802;
case Properties::West::FALSE:
return 1803;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1804;
case Properties::West::FALSE:
return 1805;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1806;
case Properties::West::FALSE:
return 1807;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1808;
case Properties::West::FALSE:
return 1809;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1810;
case Properties::West::FALSE:
return 1811;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1812;
case Properties::West::FALSE:
return 1813;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1814;
case Properties::West::FALSE:
return 1815;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1816;
case Properties::West::FALSE:
return 1817;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1818;
case Properties::West::FALSE:
return 1819;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1820;
case Properties::West::FALSE:
return 1821;
}
}
}
}
}
case Properties::Age::FOUR:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1822;
case Properties::West::FALSE:
return 1823;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1824;
case Properties::West::FALSE:
return 1825;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1826;
case Properties::West::FALSE:
return 1827;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1828;
case Properties::West::FALSE:
return 1829;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1830;
case Properties::West::FALSE:
return 1831;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1832;
case Properties::West::FALSE:
return 1833;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1834;
case Properties::West::FALSE:
return 1835;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1836;
case Properties::West::FALSE:
return 1837;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1838;
case Properties::West::FALSE:
return 1839;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1840;
case Properties::West::FALSE:
return 1841;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1842;
case Properties::West::FALSE:
return 1843;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1844;
case Properties::West::FALSE:
return 1845;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1846;
case Properties::West::FALSE:
return 1847;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1848;
case Properties::West::FALSE:
return 1849;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1850;
case Properties::West::FALSE:
return 1851;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1852;
case Properties::West::FALSE:
return 1853;
}
}
}
}
}
case Properties::Age::FIVE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1854;
case Properties::West::FALSE:
return 1855;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1856;
case Properties::West::FALSE:
return 1857;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1858;
case Properties::West::FALSE:
return 1859;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1860;
case Properties::West::FALSE:
return 1861;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1862;
case Properties::West::FALSE:
return 1863;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1864;
case Properties::West::FALSE:
return 1865;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1866;
case Properties::West::FALSE:
return 1867;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1868;
case Properties::West::FALSE:
return 1869;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1870;
case Properties::West::FALSE:
return 1871;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1872;
case Properties::West::FALSE:
return 1873;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1874;
case Properties::West::FALSE:
return 1875;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1876;
case Properties::West::FALSE:
return 1877;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1878;
case Properties::West::FALSE:
return 1879;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1880;
case Properties::West::FALSE:
return 1881;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1882;
case Properties::West::FALSE:
return 1883;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1884;
case Properties::West::FALSE:
return 1885;
}
}
}
}
}
case Properties::Age::SIX:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1886;
case Properties::West::FALSE:
return 1887;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1888;
case Properties::West::FALSE:
return 1889;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1890;
case Properties::West::FALSE:
return 1891;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1892;
case Properties::West::FALSE:
return 1893;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1894;
case Properties::West::FALSE:
return 1895;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1896;
case Properties::West::FALSE:
return 1897;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1898;
case Properties::West::FALSE:
return 1899;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1900;
case Properties::West::FALSE:
return 1901;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1902;
case Properties::West::FALSE:
return 1903;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1904;
case Properties::West::FALSE:
return 1905;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1906;
case Properties::West::FALSE:
return 1907;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1908;
case Properties::West::FALSE:
return 1909;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1910;
case Properties::West::FALSE:
return 1911;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1912;
case Properties::West::FALSE:
return 1913;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1914;
case Properties::West::FALSE:
return 1915;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1916;
case Properties::West::FALSE:
return 1917;
}
}
}
}
}
case Properties::Age::SEVEN:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1918;
case Properties::West::FALSE:
return 1919;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1920;
case Properties::West::FALSE:
return 1921;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1922;
case Properties::West::FALSE:
return 1923;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1924;
case Properties::West::FALSE:
return 1925;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1926;
case Properties::West::FALSE:
return 1927;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1928;
case Properties::West::FALSE:
return 1929;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1930;
case Properties::West::FALSE:
return 1931;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1932;
case Properties::West::FALSE:
return 1933;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1934;
case Properties::West::FALSE:
return 1935;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1936;
case Properties::West::FALSE:
return 1937;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1938;
case Properties::West::FALSE:
return 1939;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1940;
case Properties::West::FALSE:
return 1941;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1942;
case Properties::West::FALSE:
return 1943;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1944;
case Properties::West::FALSE:
return 1945;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1946;
case Properties::West::FALSE:
return 1947;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1948;
case Properties::West::FALSE:
return 1949;
}
}
}
}
}
case Properties::Age::EIGHT:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1950;
case Properties::West::FALSE:
return 1951;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1952;
case Properties::West::FALSE:
return 1953;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1954;
case Properties::West::FALSE:
return 1955;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1956;
case Properties::West::FALSE:
return 1957;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1958;
case Properties::West::FALSE:
return 1959;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1960;
case Properties::West::FALSE:
return 1961;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1962;
case Properties::West::FALSE:
return 1963;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1964;
case Properties::West::FALSE:
return 1965;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1966;
case Properties::West::FALSE:
return 1967;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1968;
case Properties::West::FALSE:
return 1969;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1970;
case Properties::West::FALSE:
return 1971;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1972;
case Properties::West::FALSE:
return 1973;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1974;
case Properties::West::FALSE:
return 1975;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1976;
case Properties::West::FALSE:
return 1977;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1978;
case Properties::West::FALSE:
return 1979;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1980;
case Properties::West::FALSE:
return 1981;
}
}
}
}
}
case Properties::Age::NINE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1982;
case Properties::West::FALSE:
return 1983;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1984;
case Properties::West::FALSE:
return 1985;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1986;
case Properties::West::FALSE:
return 1987;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1988;
case Properties::West::FALSE:
return 1989;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1990;
case Properties::West::FALSE:
return 1991;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1992;
case Properties::West::FALSE:
return 1993;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1994;
case Properties::West::FALSE:
return 1995;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 1996;
case Properties::West::FALSE:
return 1997;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 1998;
case Properties::West::FALSE:
return 1999;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2000;
case Properties::West::FALSE:
return 2001;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2002;
case Properties::West::FALSE:
return 2003;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2004;
case Properties::West::FALSE:
return 2005;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2006;
case Properties::West::FALSE:
return 2007;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2008;
case Properties::West::FALSE:
return 2009;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2010;
case Properties::West::FALSE:
return 2011;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2012;
case Properties::West::FALSE:
return 2013;
}
}
}
}
}
case Properties::Age::TEN:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2014;
case Properties::West::FALSE:
return 2015;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2016;
case Properties::West::FALSE:
return 2017;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2018;
case Properties::West::FALSE:
return 2019;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2020;
case Properties::West::FALSE:
return 2021;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2022;
case Properties::West::FALSE:
return 2023;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2024;
case Properties::West::FALSE:
return 2025;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2026;
case Properties::West::FALSE:
return 2027;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2028;
case Properties::West::FALSE:
return 2029;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2030;
case Properties::West::FALSE:
return 2031;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2032;
case Properties::West::FALSE:
return 2033;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2034;
case Properties::West::FALSE:
return 2035;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2036;
case Properties::West::FALSE:
return 2037;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2038;
case Properties::West::FALSE:
return 2039;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2040;
case Properties::West::FALSE:
return 2041;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2042;
case Properties::West::FALSE:
return 2043;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2044;
case Properties::West::FALSE:
return 2045;
}
}
}
}
}
case Properties::Age::ELEVEN:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2046;
case Properties::West::FALSE:
return 2047;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2048;
case Properties::West::FALSE:
return 2049;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2050;
case Properties::West::FALSE:
return 2051;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2052;
case Properties::West::FALSE:
return 2053;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2054;
case Properties::West::FALSE:
return 2055;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2056;
case Properties::West::FALSE:
return 2057;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2058;
case Properties::West::FALSE:
return 2059;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2060;
case Properties::West::FALSE:
return 2061;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2062;
case Properties::West::FALSE:
return 2063;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2064;
case Properties::West::FALSE:
return 2065;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2066;
case Properties::West::FALSE:
return 2067;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2068;
case Properties::West::FALSE:
return 2069;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2070;
case Properties::West::FALSE:
return 2071;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2072;
case Properties::West::FALSE:
return 2073;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2074;
case Properties::West::FALSE:
return 2075;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2076;
case Properties::West::FALSE:
return 2077;
}
}
}
}
}
case Properties::Age::TWELVE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2078;
case Properties::West::FALSE:
return 2079;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2080;
case Properties::West::FALSE:
return 2081;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2082;
case Properties::West::FALSE:
return 2083;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2084;
case Properties::West::FALSE:
return 2085;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2086;
case Properties::West::FALSE:
return 2087;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2088;
case Properties::West::FALSE:
return 2089;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2090;
case Properties::West::FALSE:
return 2091;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2092;
case Properties::West::FALSE:
return 2093;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2094;
case Properties::West::FALSE:
return 2095;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2096;
case Properties::West::FALSE:
return 2097;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2098;
case Properties::West::FALSE:
return 2099;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2100;
case Properties::West::FALSE:
return 2101;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2102;
case Properties::West::FALSE:
return 2103;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2104;
case Properties::West::FALSE:
return 2105;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2106;
case Properties::West::FALSE:
return 2107;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2108;
case Properties::West::FALSE:
return 2109;
}
}
}
}
}
case Properties::Age::THIRTEEN:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2110;
case Properties::West::FALSE:
return 2111;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2112;
case Properties::West::FALSE:
return 2113;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2114;
case Properties::West::FALSE:
return 2115;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2116;
case Properties::West::FALSE:
return 2117;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2118;
case Properties::West::FALSE:
return 2119;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2120;
case Properties::West::FALSE:
return 2121;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2122;
case Properties::West::FALSE:
return 2123;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2124;
case Properties::West::FALSE:
return 2125;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2126;
case Properties::West::FALSE:
return 2127;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2128;
case Properties::West::FALSE:
return 2129;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2130;
case Properties::West::FALSE:
return 2131;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2132;
case Properties::West::FALSE:
return 2133;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2134;
case Properties::West::FALSE:
return 2135;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2136;
case Properties::West::FALSE:
return 2137;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2138;
case Properties::West::FALSE:
return 2139;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2140;
case Properties::West::FALSE:
return 2141;
}
}
}
}
}
case Properties::Age::FOURTEEN:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2142;
case Properties::West::FALSE:
return 2143;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2144;
case Properties::West::FALSE:
return 2145;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2146;
case Properties::West::FALSE:
return 2147;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2148;
case Properties::West::FALSE:
return 2149;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2150;
case Properties::West::FALSE:
return 2151;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2152;
case Properties::West::FALSE:
return 2153;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2154;
case Properties::West::FALSE:
return 2155;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2156;
case Properties::West::FALSE:
return 2157;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2158;
case Properties::West::FALSE:
return 2159;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2160;
case Properties::West::FALSE:
return 2161;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2162;
case Properties::West::FALSE:
return 2163;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2164;
case Properties::West::FALSE:
return 2165;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2166;
case Properties::West::FALSE:
return 2167;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2168;
case Properties::West::FALSE:
return 2169;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2170;
case Properties::West::FALSE:
return 2171;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2172;
case Properties::West::FALSE:
return 2173;
}
}
}
}
}
case Properties::Age::FIFTEEN:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2174;
case Properties::West::FALSE:
return 2175;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2176;
case Properties::West::FALSE:
return 2177;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2178;
case Properties::West::FALSE:
return 2179;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2180;
case Properties::West::FALSE:
return 2181;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2182;
case Properties::West::FALSE:
return 2183;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2184;
case Properties::West::FALSE:
return 2185;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2186;
case Properties::West::FALSE:
return 2187;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2188;
case Properties::West::FALSE:
return 2189;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2190;
case Properties::West::FALSE:
return 2191;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2192;
case Properties::West::FALSE:
return 2193;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2194;
case Properties::West::FALSE:
return 2195;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2196;
case Properties::West::FALSE:
return 2197;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2198;
case Properties::West::FALSE:
return 2199;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2200;
case Properties::West::FALSE:
return 2201;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 2202;
case Properties::West::FALSE:
return 2203;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 2204;
case Properties::West::FALSE:
return 2205;
}
}
}
}
}
}
return 0;
}
}

namespace FireCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10417;
case Properties::Waterlogged::FALSE:
return 10418;
}
return 0;
}
}

namespace FireCoralBlock {
constexpr Block toProtocol() {
return 10399;
return 0;
}
}

namespace FireCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10437;
case Properties::Waterlogged::FALSE:
return 10438;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10505;
case Properties::Waterlogged::FALSE:
return 10506;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10507;
case Properties::Waterlogged::FALSE:
return 10508;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10509;
case Properties::Waterlogged::FALSE:
return 10510;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10511;
case Properties::Waterlogged::FALSE:
return 10512;
}
}
return 0;
}
}

namespace FletchingTable {
constexpr Block toProtocol() {
return 16025;
return 0;
}
}

namespace FlowerPot {
constexpr Block toProtocol() {
return 6897;
return 0;
}
}

namespace FloweringAzalea {
constexpr Block toProtocol() {
return 19715;
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 430;
case Properties::Waterlogged::FALSE:
return 431;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 432;
case Properties::Waterlogged::FALSE:
return 433;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 434;
case Properties::Waterlogged::FALSE:
return 435;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 436;
case Properties::Waterlogged::FALSE:
return 437;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 438;
case Properties::Waterlogged::FALSE:
return 439;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 440;
case Properties::Waterlogged::FALSE:
return 441;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 442;
case Properties::Waterlogged::FALSE:
return 443;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 444;
case Properties::Waterlogged::FALSE:
return 445;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 446;
case Properties::Waterlogged::FALSE:
return 447;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 448;
case Properties::Waterlogged::FALSE:
return 449;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 450;
case Properties::Waterlogged::FALSE:
return 451;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 452;
case Properties::Waterlogged::FALSE:
return 453;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 454;
case Properties::Waterlogged::FALSE:
return 455;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 456;
case Properties::Waterlogged::FALSE:
return 457;
}
}
}
return 0;
}
}

namespace Frogspawn {
constexpr Block toProtocol() {
return 21446;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 10130;
case Properties::Age::ONE:
return 10131;
case Properties::Age::TWO:
return 10132;
case Properties::Age::THREE:
return 10133;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Lit lit) {
switch (facing) {
case Properties::Facing::NORTH:
switch (lit) {
case Properties::Lit::TRUE:
return 3628;
case Properties::Lit::FALSE:
return 3629;
}
case Properties::Facing::SOUTH:
switch (lit) {
case Properties::Lit::TRUE:
return 3630;
case Properties::Lit::FALSE:
return 3631;
}
case Properties::Facing::WEST:
switch (lit) {
case Properties::Lit::TRUE:
return 3632;
case Properties::Lit::FALSE:
return 3633;
}
case Properties::Facing::EAST:
switch (lit) {
case Properties::Lit::TRUE:
return 3634;
case Properties::Lit::FALSE:
return 3635;
}
}
return 0;
}
}

namespace GildedBlackstone {
constexpr Block toProtocol() {
return 17873;
return 0;
}
}

namespace Glass {
constexpr Block toProtocol() {
return 460;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 5110;
case Properties::West::FALSE:
return 5111;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5112;
case Properties::West::FALSE:
return 5113;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5114;
case Properties::West::FALSE:
return 5115;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5116;
case Properties::West::FALSE:
return 5117;
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
return 5118;
case Properties::West::FALSE:
return 5119;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5120;
case Properties::West::FALSE:
return 5121;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5122;
case Properties::West::FALSE:
return 5123;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5124;
case Properties::West::FALSE:
return 5125;
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
return 5126;
case Properties::West::FALSE:
return 5127;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5128;
case Properties::West::FALSE:
return 5129;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5130;
case Properties::West::FALSE:
return 5131;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5132;
case Properties::West::FALSE:
return 5133;
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
return 5134;
case Properties::West::FALSE:
return 5135;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5136;
case Properties::West::FALSE:
return 5137;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5138;
case Properties::West::FALSE:
return 5139;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5140;
case Properties::West::FALSE:
return 5141;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (down) {
case Properties::Down::TRUE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5199;
case Properties::West::FALSE:
return 5200;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5201;
case Properties::West::FALSE:
return 5202;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5203;
case Properties::West::FALSE:
return 5204;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5205;
case Properties::West::FALSE:
return 5206;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5207;
case Properties::West::FALSE:
return 5208;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5209;
case Properties::West::FALSE:
return 5210;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5211;
case Properties::West::FALSE:
return 5212;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5213;
case Properties::West::FALSE:
return 5214;
}
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5215;
case Properties::West::FALSE:
return 5216;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5217;
case Properties::West::FALSE:
return 5218;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5219;
case Properties::West::FALSE:
return 5220;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5221;
case Properties::West::FALSE:
return 5222;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5223;
case Properties::West::FALSE:
return 5224;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5225;
case Properties::West::FALSE:
return 5226;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5227;
case Properties::West::FALSE:
return 5228;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5229;
case Properties::West::FALSE:
return 5230;
}
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5231;
case Properties::West::FALSE:
return 5232;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5233;
case Properties::West::FALSE:
return 5234;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5235;
case Properties::West::FALSE:
return 5236;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5237;
case Properties::West::FALSE:
return 5238;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5239;
case Properties::West::FALSE:
return 5240;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5241;
case Properties::West::FALSE:
return 5242;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5243;
case Properties::West::FALSE:
return 5244;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5245;
case Properties::West::FALSE:
return 5246;
}
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5247;
case Properties::West::FALSE:
return 5248;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5249;
case Properties::West::FALSE:
return 5250;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5251;
case Properties::West::FALSE:
return 5252;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5253;
case Properties::West::FALSE:
return 5254;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5255;
case Properties::West::FALSE:
return 5256;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5257;
case Properties::West::FALSE:
return 5258;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5259;
case Properties::West::FALSE:
return 5260;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5261;
case Properties::West::FALSE:
return 5262;
}
}
}
}
}
}
case Properties::Down::FALSE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5263;
case Properties::West::FALSE:
return 5264;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5265;
case Properties::West::FALSE:
return 5266;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5267;
case Properties::West::FALSE:
return 5268;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5269;
case Properties::West::FALSE:
return 5270;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5271;
case Properties::West::FALSE:
return 5272;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5273;
case Properties::West::FALSE:
return 5274;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5275;
case Properties::West::FALSE:
return 5276;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5277;
case Properties::West::FALSE:
return 5278;
}
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5279;
case Properties::West::FALSE:
return 5280;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5281;
case Properties::West::FALSE:
return 5282;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5283;
case Properties::West::FALSE:
return 5284;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5285;
case Properties::West::FALSE:
return 5286;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5287;
case Properties::West::FALSE:
return 5288;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5289;
case Properties::West::FALSE:
return 5290;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5291;
case Properties::West::FALSE:
return 5292;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5293;
case Properties::West::FALSE:
return 5294;
}
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5295;
case Properties::West::FALSE:
return 5296;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5297;
case Properties::West::FALSE:
return 5298;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5299;
case Properties::West::FALSE:
return 5300;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5301;
case Properties::West::FALSE:
return 5302;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5303;
case Properties::West::FALSE:
return 5304;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5305;
case Properties::West::FALSE:
return 5306;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5307;
case Properties::West::FALSE:
return 5308;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5309;
case Properties::West::FALSE:
return 5310;
}
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5311;
case Properties::West::FALSE:
return 5312;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5313;
case Properties::West::FALSE:
return 5314;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5315;
case Properties::West::FALSE:
return 5316;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5317;
case Properties::West::FALSE:
return 5318;
}
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5319;
case Properties::West::FALSE:
return 5320;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5321;
case Properties::West::FALSE:
return 5322;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5323;
case Properties::West::FALSE:
return 5324;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5325;
case Properties::West::FALSE:
return 5326;
}
}
}
}
}
}
}
return 0;
}
}

namespace Glowstone {
constexpr Block toProtocol() {
return 4322;
return 0;
}
}

namespace GoldBlock {
constexpr Block toProtocol() {
return 1681;
return 0;
}
}

namespace GoldOre {
constexpr Block toProtocol() {
return 110;
return 0;
}
}

namespace Granite {
constexpr Block toProtocol() {
return 2;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11718;
case Properties::Waterlogged::FALSE:
return 11719;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11720;
case Properties::Waterlogged::FALSE:
return 11721;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11722;
case Properties::Waterlogged::FALSE:
return 11723;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11270;
case Properties::Waterlogged::FALSE:
return 11271;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11272;
case Properties::Waterlogged::FALSE:
return 11273;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11274;
case Properties::Waterlogged::FALSE:
return 11275;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11276;
case Properties::Waterlogged::FALSE:
return 11277;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11278;
case Properties::Waterlogged::FALSE:
return 11279;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11280;
case Properties::Waterlogged::FALSE:
return 11281;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11282;
case Properties::Waterlogged::FALSE:
return 11283;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11284;
case Properties::Waterlogged::FALSE:
return 11285;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11286;
case Properties::Waterlogged::FALSE:
return 11287;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11288;
case Properties::Waterlogged::FALSE:
return 11289;
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
return 11290;
case Properties::Waterlogged::FALSE:
return 11291;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11292;
case Properties::Waterlogged::FALSE:
return 11293;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11294;
case Properties::Waterlogged::FALSE:
return 11295;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11296;
case Properties::Waterlogged::FALSE:
return 11297;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11298;
case Properties::Waterlogged::FALSE:
return 11299;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11300;
case Properties::Waterlogged::FALSE:
return 11301;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11302;
case Properties::Waterlogged::FALSE:
return 11303;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11304;
case Properties::Waterlogged::FALSE:
return 11305;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11306;
case Properties::Waterlogged::FALSE:
return 11307;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11308;
case Properties::Waterlogged::FALSE:
return 11309;
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
return 11310;
case Properties::Waterlogged::FALSE:
return 11311;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11312;
case Properties::Waterlogged::FALSE:
return 11313;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11314;
case Properties::Waterlogged::FALSE:
return 11315;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11316;
case Properties::Waterlogged::FALSE:
return 11317;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11318;
case Properties::Waterlogged::FALSE:
return 11319;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11320;
case Properties::Waterlogged::FALSE:
return 11321;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11322;
case Properties::Waterlogged::FALSE:
return 11323;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11324;
case Properties::Waterlogged::FALSE:
return 11325;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11326;
case Properties::Waterlogged::FALSE:
return 11327;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11328;
case Properties::Waterlogged::FALSE:
return 11329;
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
return 11330;
case Properties::Waterlogged::FALSE:
return 11331;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11332;
case Properties::Waterlogged::FALSE:
return 11333;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11334;
case Properties::Waterlogged::FALSE:
return 11335;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11336;
case Properties::Waterlogged::FALSE:
return 11337;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11338;
case Properties::Waterlogged::FALSE:
return 11339;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11340;
case Properties::Waterlogged::FALSE:
return 11341;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11342;
case Properties::Waterlogged::FALSE:
return 11343;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11344;
case Properties::Waterlogged::FALSE:
return 11345;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11346;
case Properties::Waterlogged::FALSE:
return 11347;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11348;
case Properties::Waterlogged::FALSE:
return 11349;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13044;
case Properties::West::LOW:
return 13045;
case Properties::West::TALL:
return 13046;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13047;
case Properties::West::LOW:
return 13048;
case Properties::West::TALL:
return 13049;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13050;
case Properties::West::LOW:
return 13051;
case Properties::West::TALL:
return 13052;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13053;
case Properties::West::LOW:
return 13054;
case Properties::West::TALL:
return 13055;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13056;
case Properties::West::LOW:
return 13057;
case Properties::West::TALL:
return 13058;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13059;
case Properties::West::LOW:
return 13060;
case Properties::West::TALL:
return 13061;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13062;
case Properties::West::LOW:
return 13063;
case Properties::West::TALL:
return 13064;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13065;
case Properties::West::LOW:
return 13066;
case Properties::West::TALL:
return 13067;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13068;
case Properties::West::LOW:
return 13069;
case Properties::West::TALL:
return 13070;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13071;
case Properties::West::LOW:
return 13072;
case Properties::West::TALL:
return 13073;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13074;
case Properties::West::LOW:
return 13075;
case Properties::West::TALL:
return 13076;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13077;
case Properties::West::LOW:
return 13078;
case Properties::West::TALL:
return 13079;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13080;
case Properties::West::LOW:
return 13081;
case Properties::West::TALL:
return 13082;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13083;
case Properties::West::LOW:
return 13084;
case Properties::West::TALL:
return 13085;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13086;
case Properties::West::LOW:
return 13087;
case Properties::West::TALL:
return 13088;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13089;
case Properties::West::LOW:
return 13090;
case Properties::West::TALL:
return 13091;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13092;
case Properties::West::LOW:
return 13093;
case Properties::West::TALL:
return 13094;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13095;
case Properties::West::LOW:
return 13096;
case Properties::West::TALL:
return 13097;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13098;
case Properties::West::LOW:
return 13099;
case Properties::West::TALL:
return 13100;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13101;
case Properties::West::LOW:
return 13102;
case Properties::West::TALL:
return 13103;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13104;
case Properties::West::LOW:
return 13105;
case Properties::West::TALL:
return 13106;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13107;
case Properties::West::LOW:
return 13108;
case Properties::West::TALL:
return 13109;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13110;
case Properties::West::LOW:
return 13111;
case Properties::West::TALL:
return 13112;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13113;
case Properties::West::LOW:
return 13114;
case Properties::West::TALL:
return 13115;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13116;
case Properties::West::LOW:
return 13117;
case Properties::West::TALL:
return 13118;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13119;
case Properties::West::LOW:
return 13120;
case Properties::West::TALL:
return 13121;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13122;
case Properties::West::LOW:
return 13123;
case Properties::West::TALL:
return 13124;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13125;
case Properties::West::LOW:
return 13126;
case Properties::West::TALL:
return 13127;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13128;
case Properties::West::LOW:
return 13129;
case Properties::West::TALL:
return 13130;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13131;
case Properties::West::LOW:
return 13132;
case Properties::West::TALL:
return 13133;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13134;
case Properties::West::LOW:
return 13135;
case Properties::West::TALL:
return 13136;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13137;
case Properties::West::LOW:
return 13138;
case Properties::West::TALL:
return 13139;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13140;
case Properties::West::LOW:
return 13141;
case Properties::West::TALL:
return 13142;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13143;
case Properties::West::LOW:
return 13144;
case Properties::West::TALL:
return 13145;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13146;
case Properties::West::LOW:
return 13147;
case Properties::West::TALL:
return 13148;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13149;
case Properties::West::LOW:
return 13150;
case Properties::West::TALL:
return 13151;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13152;
case Properties::West::LOW:
return 13153;
case Properties::West::TALL:
return 13154;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13155;
case Properties::West::LOW:
return 13156;
case Properties::West::TALL:
return 13157;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13158;
case Properties::West::LOW:
return 13159;
case Properties::West::TALL:
return 13160;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13161;
case Properties::West::LOW:
return 13162;
case Properties::West::TALL:
return 13163;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13164;
case Properties::West::LOW:
return 13165;
case Properties::West::TALL:
return 13166;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13167;
case Properties::West::LOW:
return 13168;
case Properties::West::TALL:
return 13169;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13170;
case Properties::West::LOW:
return 13171;
case Properties::West::TALL:
return 13172;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13173;
case Properties::West::LOW:
return 13174;
case Properties::West::TALL:
return 13175;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13176;
case Properties::West::LOW:
return 13177;
case Properties::West::TALL:
return 13178;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13179;
case Properties::West::LOW:
return 13180;
case Properties::West::TALL:
return 13181;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13182;
case Properties::West::LOW:
return 13183;
case Properties::West::TALL:
return 13184;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13185;
case Properties::West::LOW:
return 13186;
case Properties::West::TALL:
return 13187;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13188;
case Properties::West::LOW:
return 13189;
case Properties::West::TALL:
return 13190;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13191;
case Properties::West::LOW:
return 13192;
case Properties::West::TALL:
return 13193;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13194;
case Properties::West::LOW:
return 13195;
case Properties::West::TALL:
return 13196;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13197;
case Properties::West::LOW:
return 13198;
case Properties::West::TALL:
return 13199;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13200;
case Properties::West::LOW:
return 13201;
case Properties::West::TALL:
return 13202;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13203;
case Properties::West::LOW:
return 13204;
case Properties::West::TALL:
return 13205;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13206;
case Properties::West::LOW:
return 13207;
case Properties::West::TALL:
return 13208;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13209;
case Properties::West::LOW:
return 13210;
case Properties::West::TALL:
return 13211;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13212;
case Properties::West::LOW:
return 13213;
case Properties::West::TALL:
return 13214;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13215;
case Properties::West::LOW:
return 13216;
case Properties::West::TALL:
return 13217;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13218;
case Properties::West::LOW:
return 13219;
case Properties::West::TALL:
return 13220;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13221;
case Properties::West::LOW:
return 13222;
case Properties::West::TALL:
return 13223;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13224;
case Properties::West::LOW:
return 13225;
case Properties::West::TALL:
return 13226;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13227;
case Properties::West::LOW:
return 13228;
case Properties::West::TALL:
return 13229;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13230;
case Properties::West::LOW:
return 13231;
case Properties::West::TALL:
return 13232;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13233;
case Properties::West::LOW:
return 13234;
case Properties::West::TALL:
return 13235;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13236;
case Properties::West::LOW:
return 13237;
case Properties::West::TALL:
return 13238;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13239;
case Properties::West::LOW:
return 13240;
case Properties::West::TALL:
return 13241;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13242;
case Properties::West::LOW:
return 13243;
case Properties::West::TALL:
return 13244;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13245;
case Properties::West::LOW:
return 13246;
case Properties::West::TALL:
return 13247;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13248;
case Properties::West::LOW:
return 13249;
case Properties::West::TALL:
return 13250;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13251;
case Properties::West::LOW:
return 13252;
case Properties::West::TALL:
return 13253;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13254;
case Properties::West::LOW:
return 13255;
case Properties::West::TALL:
return 13256;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13257;
case Properties::West::LOW:
return 13258;
case Properties::West::TALL:
return 13259;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13260;
case Properties::West::LOW:
return 13261;
case Properties::West::TALL:
return 13262;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13263;
case Properties::West::LOW:
return 13264;
case Properties::West::TALL:
return 13265;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13266;
case Properties::West::LOW:
return 13267;
case Properties::West::TALL:
return 13268;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13269;
case Properties::West::LOW:
return 13270;
case Properties::West::TALL:
return 13271;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13272;
case Properties::West::LOW:
return 13273;
case Properties::West::TALL:
return 13274;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13275;
case Properties::West::LOW:
return 13276;
case Properties::West::TALL:
return 13277;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13278;
case Properties::West::LOW:
return 13279;
case Properties::West::TALL:
return 13280;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13281;
case Properties::West::LOW:
return 13282;
case Properties::West::TALL:
return 13283;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13284;
case Properties::West::LOW:
return 13285;
case Properties::West::TALL:
return 13286;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13287;
case Properties::West::LOW:
return 13288;
case Properties::West::TALL:
return 13289;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13290;
case Properties::West::LOW:
return 13291;
case Properties::West::TALL:
return 13292;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13293;
case Properties::West::LOW:
return 13294;
case Properties::West::TALL:
return 13295;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13296;
case Properties::West::LOW:
return 13297;
case Properties::West::TALL:
return 13298;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13299;
case Properties::West::LOW:
return 13300;
case Properties::West::TALL:
return 13301;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13302;
case Properties::West::LOW:
return 13303;
case Properties::West::TALL:
return 13304;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13305;
case Properties::West::LOW:
return 13306;
case Properties::West::TALL:
return 13307;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13308;
case Properties::West::LOW:
return 13309;
case Properties::West::TALL:
return 13310;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13311;
case Properties::West::LOW:
return 13312;
case Properties::West::TALL:
return 13313;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13314;
case Properties::West::LOW:
return 13315;
case Properties::West::TALL:
return 13316;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13317;
case Properties::West::LOW:
return 13318;
case Properties::West::TALL:
return 13319;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13320;
case Properties::West::LOW:
return 13321;
case Properties::West::TALL:
return 13322;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13323;
case Properties::West::LOW:
return 13324;
case Properties::West::TALL:
return 13325;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13326;
case Properties::West::LOW:
return 13327;
case Properties::West::TALL:
return 13328;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13329;
case Properties::West::LOW:
return 13330;
case Properties::West::TALL:
return 13331;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13332;
case Properties::West::LOW:
return 13333;
case Properties::West::TALL:
return 13334;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13335;
case Properties::West::LOW:
return 13336;
case Properties::West::TALL:
return 13337;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13338;
case Properties::West::LOW:
return 13339;
case Properties::West::TALL:
return 13340;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13341;
case Properties::West::LOW:
return 13342;
case Properties::West::TALL:
return 13343;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13344;
case Properties::West::LOW:
return 13345;
case Properties::West::TALL:
return 13346;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13347;
case Properties::West::LOW:
return 13348;
case Properties::West::TALL:
return 13349;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13350;
case Properties::West::LOW:
return 13351;
case Properties::West::TALL:
return 13352;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13353;
case Properties::West::LOW:
return 13354;
case Properties::West::TALL:
return 13355;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13356;
case Properties::West::LOW:
return 13357;
case Properties::West::TALL:
return 13358;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13359;
case Properties::West::LOW:
return 13360;
case Properties::West::TALL:
return 13361;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13362;
case Properties::West::LOW:
return 13363;
case Properties::West::TALL:
return 13364;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13365;
case Properties::West::LOW:
return 13366;
case Properties::West::TALL:
return 13367;
}
}
}
}
}
}
return 0;
}
}

namespace Grass {
constexpr Block toProtocol() {
return 1596;
return 0;
}
}

namespace GrassBlock {
namespace Properties {
enum class Snowy {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Snowy snowy) {
switch (snowy) {
case Properties::Snowy::TRUE:
return 8;
case Properties::Snowy::FALSE:
return 9;
}
return 0;
}
}

namespace Gravel {
constexpr Block toProtocol() {
return 109;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8750;
case Properties::Rotation::ONE:
return 8751;
case Properties::Rotation::TWO:
return 8752;
case Properties::Rotation::THREE:
return 8753;
case Properties::Rotation::FOUR:
return 8754;
case Properties::Rotation::FIVE:
return 8755;
case Properties::Rotation::SIX:
return 8756;
case Properties::Rotation::SEVEN:
return 8757;
case Properties::Rotation::EIGHT:
return 8758;
case Properties::Rotation::NINE:
return 8759;
case Properties::Rotation::TEN:
return 8760;
case Properties::Rotation::ELEVEN:
return 8761;
case Properties::Rotation::TWELVE:
return 8762;
case Properties::Rotation::THIRTEEN:
return 8763;
case Properties::Rotation::FOURTEEN:
return 8764;
case Properties::Rotation::FIFTEEN:
return 8765;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1391;
case Properties::Part::FOOT:
return 1392;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1393;
case Properties::Part::FOOT:
return 1394;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1395;
case Properties::Part::FOOT:
return 1396;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1397;
case Properties::Part::FOOT:
return 1398;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1399;
case Properties::Part::FOOT:
return 1400;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1401;
case Properties::Part::FOOT:
return 1402;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1403;
case Properties::Part::FOOT:
return 1404;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1405;
case Properties::Part::FOOT:
return 1406;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18441;
case Properties::Waterlogged::FALSE:
return 18442;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18443;
case Properties::Waterlogged::FALSE:
return 18444;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18445;
case Properties::Waterlogged::FALSE:
return 18446;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18447;
case Properties::Waterlogged::FALSE:
return 18448;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18449;
case Properties::Waterlogged::FALSE:
return 18450;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18451;
case Properties::Waterlogged::FALSE:
return 18452;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18453;
case Properties::Waterlogged::FALSE:
return 18454;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18455;
case Properties::Waterlogged::FALSE:
return 18456;
}
}
}
return 0;
}
}

namespace GrayCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18601;
case Properties::Lit::FALSE:
return 18602;
}
return 0;
}
}

namespace GrayCarpet {
constexpr Block toProtocol() {
return 8614;
return 0;
}
}

namespace GrayConcrete {
constexpr Block toProtocol() {
return 10326;
return 0;
}
}

namespace GrayConcretePowder {
constexpr Block toProtocol() {
return 10342;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10283;
case Properties::Facing::SOUTH:
return 10284;
case Properties::Facing::WEST:
return 10285;
case Properties::Facing::EAST:
return 10286;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10201;
case Properties::Facing::EAST:
return 10202;
case Properties::Facing::SOUTH:
return 10203;
case Properties::Facing::WEST:
return 10204;
case Properties::Facing::UP:
return 10205;
case Properties::Facing::DOWN:
return 10206;
}
return 0;
}
}

namespace GrayStainedGlass {
constexpr Block toProtocol() {
return 4411;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7716;
case Properties::West::FALSE:
return 7717;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7718;
case Properties::West::FALSE:
return 7719;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7720;
case Properties::West::FALSE:
return 7721;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7722;
case Properties::West::FALSE:
return 7723;
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
return 7724;
case Properties::West::FALSE:
return 7725;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7726;
case Properties::West::FALSE:
return 7727;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7728;
case Properties::West::FALSE:
return 7729;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7730;
case Properties::West::FALSE:
return 7731;
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
return 7732;
case Properties::West::FALSE:
return 7733;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7734;
case Properties::West::FALSE:
return 7735;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7736;
case Properties::West::FALSE:
return 7737;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7738;
case Properties::West::FALSE:
return 7739;
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
return 7740;
case Properties::West::FALSE:
return 7741;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7742;
case Properties::West::FALSE:
return 7743;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7744;
case Properties::West::FALSE:
return 7745;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7746;
case Properties::West::FALSE:
return 7747;
}
}
}
}
}
return 0;
}
}

namespace GrayTerracotta {
constexpr Block toProtocol() {
return 7483;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8922;
case Properties::Facing::SOUTH:
return 8923;
case Properties::Facing::WEST:
return 8924;
case Properties::Facing::EAST:
return 8925;
}
return 0;
}
}

namespace GrayWool {
constexpr Block toProtocol() {
return 1645;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8846;
case Properties::Rotation::ONE:
return 8847;
case Properties::Rotation::TWO:
return 8848;
case Properties::Rotation::THREE:
return 8849;
case Properties::Rotation::FOUR:
return 8850;
case Properties::Rotation::FIVE:
return 8851;
case Properties::Rotation::SIX:
return 8852;
case Properties::Rotation::SEVEN:
return 8853;
case Properties::Rotation::EIGHT:
return 8854;
case Properties::Rotation::NINE:
return 8855;
case Properties::Rotation::TEN:
return 8856;
case Properties::Rotation::ELEVEN:
return 8857;
case Properties::Rotation::TWELVE:
return 8858;
case Properties::Rotation::THIRTEEN:
return 8859;
case Properties::Rotation::FOURTEEN:
return 8860;
case Properties::Rotation::FIFTEEN:
return 8861;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1487;
case Properties::Part::FOOT:
return 1488;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1489;
case Properties::Part::FOOT:
return 1490;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1491;
case Properties::Part::FOOT:
return 1492;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1493;
case Properties::Part::FOOT:
return 1494;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1495;
case Properties::Part::FOOT:
return 1496;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1497;
case Properties::Part::FOOT:
return 1498;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1499;
case Properties::Part::FOOT:
return 1500;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1501;
case Properties::Part::FOOT:
return 1502;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18537;
case Properties::Waterlogged::FALSE:
return 18538;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18539;
case Properties::Waterlogged::FALSE:
return 18540;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18541;
case Properties::Waterlogged::FALSE:
return 18542;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18543;
case Properties::Waterlogged::FALSE:
return 18544;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18545;
case Properties::Waterlogged::FALSE:
return 18546;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18547;
case Properties::Waterlogged::FALSE:
return 18548;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18549;
case Properties::Waterlogged::FALSE:
return 18550;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18551;
case Properties::Waterlogged::FALSE:
return 18552;
}
}
}
return 0;
}
}

namespace GreenCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18613;
case Properties::Lit::FALSE:
return 18614;
}
return 0;
}
}

namespace GreenCarpet {
constexpr Block toProtocol() {
return 8620;
return 0;
}
}

namespace GreenConcrete {
constexpr Block toProtocol() {
return 10332;
return 0;
}
}

namespace GreenConcretePowder {
constexpr Block toProtocol() {
return 10348;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10307;
case Properties::Facing::SOUTH:
return 10308;
case Properties::Facing::WEST:
return 10309;
case Properties::Facing::EAST:
return 10310;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10237;
case Properties::Facing::EAST:
return 10238;
case Properties::Facing::SOUTH:
return 10239;
case Properties::Facing::WEST:
return 10240;
case Properties::Facing::UP:
return 10241;
case Properties::Facing::DOWN:
return 10242;
}
return 0;
}
}

namespace GreenStainedGlass {
constexpr Block toProtocol() {
return 4417;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7908;
case Properties::West::FALSE:
return 7909;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7910;
case Properties::West::FALSE:
return 7911;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7912;
case Properties::West::FALSE:
return 7913;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7914;
case Properties::West::FALSE:
return 7915;
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
return 7916;
case Properties::West::FALSE:
return 7917;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7918;
case Properties::West::FALSE:
return 7919;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7920;
case Properties::West::FALSE:
return 7921;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7922;
case Properties::West::FALSE:
return 7923;
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
return 7924;
case Properties::West::FALSE:
return 7925;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7926;
case Properties::West::FALSE:
return 7927;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7928;
case Properties::West::FALSE:
return 7929;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7930;
case Properties::West::FALSE:
return 7931;
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
return 7932;
case Properties::West::FALSE:
return 7933;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7934;
case Properties::West::FALSE:
return 7935;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7936;
case Properties::West::FALSE:
return 7937;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7938;
case Properties::West::FALSE:
return 7939;
}
}
}
}
}
return 0;
}
}

namespace GreenTerracotta {
constexpr Block toProtocol() {
return 7489;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8946;
case Properties::Facing::SOUTH:
return 8947;
case Properties::Facing::WEST:
return 8948;
case Properties::Facing::EAST:
return 8949;
}
return 0;
}
}

namespace GreenWool {
constexpr Block toProtocol() {
return 1651;
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
return 16026;
case Properties::Facing::SOUTH:
return 16027;
case Properties::Facing::WEST:
return 16028;
case Properties::Facing::EAST:
return 16029;
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
return 16030;
case Properties::Facing::SOUTH:
return 16031;
case Properties::Facing::WEST:
return 16032;
case Properties::Facing::EAST:
return 16033;
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
return 16034;
case Properties::Facing::SOUTH:
return 16035;
case Properties::Facing::WEST:
return 16036;
case Properties::Facing::EAST:
return 16037;
}
}
return 0;
}
}

namespace HangingRoots {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19774;
case Properties::Waterlogged::FALSE:
return 19775;
}
return 0;
}
}

namespace HayBlock {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 8604;
case Properties::Axis::Y:
return 8605;
case Properties::Axis::Z:
return 8606;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Power power) {
switch (power) {
case Properties::Power::ZERO:
return 7279;
case Properties::Power::ONE:
return 7280;
case Properties::Power::TWO:
return 7281;
case Properties::Power::THREE:
return 7282;
case Properties::Power::FOUR:
return 7283;
case Properties::Power::FIVE:
return 7284;
case Properties::Power::SIX:
return 7285;
case Properties::Power::SEVEN:
return 7286;
case Properties::Power::EIGHT:
return 7287;
case Properties::Power::NINE:
return 7288;
case Properties::Power::TEN:
return 7289;
case Properties::Power::ELEVEN:
return 7290;
case Properties::Power::TWELVE:
return 7291;
case Properties::Power::THIRTEEN:
return 7292;
case Properties::Power::FOURTEEN:
return 7293;
case Properties::Power::FIFTEEN:
return 7294;
}
return 0;
}
}

namespace HoneyBlock {
constexpr Block toProtocol() {
return 17033;
return 0;
}
}

namespace HoneycombBlock {
constexpr Block toProtocol() {
return 17034;
return 0;
}
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
constexpr Block toProtocol(Properties::Enabled enabled, Properties::Facing facing) {
switch (enabled) {
case Properties::Enabled::TRUE:
switch (facing) {
case Properties::Facing::DOWN:
return 7345;
case Properties::Facing::NORTH:
return 7346;
case Properties::Facing::SOUTH:
return 7347;
case Properties::Facing::WEST:
return 7348;
case Properties::Facing::EAST:
return 7349;
}
case Properties::Enabled::FALSE:
switch (facing) {
case Properties::Facing::DOWN:
return 7350;
case Properties::Facing::NORTH:
return 7351;
case Properties::Facing::SOUTH:
return 7352;
case Properties::Facing::WEST:
return 7353;
case Properties::Facing::EAST:
return 7354;
}
}
return 0;
}
}

namespace HornCoral {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10419;
case Properties::Waterlogged::FALSE:
return 10420;
}
return 0;
}
}

namespace HornCoralBlock {
constexpr Block toProtocol() {
return 10400;
return 0;
}
}

namespace HornCoralFan {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10439;
case Properties::Waterlogged::FALSE:
return 10440;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10513;
case Properties::Waterlogged::FALSE:
return 10514;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10515;
case Properties::Waterlogged::FALSE:
return 10516;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10517;
case Properties::Waterlogged::FALSE:
return 10518;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10519;
case Properties::Waterlogged::FALSE:
return 10520;
}
}
return 0;
}
}

namespace Ice {
constexpr Block toProtocol() {
return 4238;
return 0;
}
}

namespace InfestedChiseledStoneBricks {
constexpr Block toProtocol() {
return 4879;
return 0;
}
}

namespace InfestedCobblestone {
constexpr Block toProtocol() {
return 4875;
return 0;
}
}

namespace InfestedCrackedStoneBricks {
constexpr Block toProtocol() {
return 4878;
return 0;
}
}

namespace InfestedDeepslate {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 21428;
case Properties::Axis::Y:
return 21429;
case Properties::Axis::Z:
return 21430;
}
return 0;
}
}

namespace InfestedMossyStoneBricks {
constexpr Block toProtocol() {
return 4877;
return 0;
}
}

namespace InfestedStone {
constexpr Block toProtocol() {
return 4874;
return 0;
}
}

namespace InfestedStoneBricks {
constexpr Block toProtocol() {
return 4876;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 5072;
case Properties::West::FALSE:
return 5073;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5074;
case Properties::West::FALSE:
return 5075;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5076;
case Properties::West::FALSE:
return 5077;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5078;
case Properties::West::FALSE:
return 5079;
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
return 5080;
case Properties::West::FALSE:
return 5081;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5082;
case Properties::West::FALSE:
return 5083;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5084;
case Properties::West::FALSE:
return 5085;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5086;
case Properties::West::FALSE:
return 5087;
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
return 5088;
case Properties::West::FALSE:
return 5089;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5090;
case Properties::West::FALSE:
return 5091;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5092;
case Properties::West::FALSE:
return 5093;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5094;
case Properties::West::FALSE:
return 5095;
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
return 5096;
case Properties::West::FALSE:
return 5097;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5098;
case Properties::West::FALSE:
return 5099;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5100;
case Properties::West::FALSE:
return 5101;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5102;
case Properties::West::FALSE:
return 5103;
}
}
}
}
}
return 0;
}
}

namespace IronBlock {
constexpr Block toProtocol() {
return 1682;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4114;
case Properties::Powered::FALSE:
return 4115;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4116;
case Properties::Powered::FALSE:
return 4117;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4118;
case Properties::Powered::FALSE:
return 4119;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4120;
case Properties::Powered::FALSE:
return 4121;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4122;
case Properties::Powered::FALSE:
return 4123;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4124;
case Properties::Powered::FALSE:
return 4125;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4126;
case Properties::Powered::FALSE:
return 4127;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4128;
case Properties::Powered::FALSE:
return 4129;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4130;
case Properties::Powered::FALSE:
return 4131;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4132;
case Properties::Powered::FALSE:
return 4133;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4134;
case Properties::Powered::FALSE:
return 4135;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4136;
case Properties::Powered::FALSE:
return 4137;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4138;
case Properties::Powered::FALSE:
return 4139;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4140;
case Properties::Powered::FALSE:
return 4141;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4142;
case Properties::Powered::FALSE:
return 4143;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4144;
case Properties::Powered::FALSE:
return 4145;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4146;
case Properties::Powered::FALSE:
return 4147;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4148;
case Properties::Powered::FALSE:
return 4149;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4150;
case Properties::Powered::FALSE:
return 4151;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4152;
case Properties::Powered::FALSE:
return 4153;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4154;
case Properties::Powered::FALSE:
return 4155;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4156;
case Properties::Powered::FALSE:
return 4157;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4158;
case Properties::Powered::FALSE:
return 4159;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4160;
case Properties::Powered::FALSE:
return 4161;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4162;
case Properties::Powered::FALSE:
return 4163;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4164;
case Properties::Powered::FALSE:
return 4165;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4166;
case Properties::Powered::FALSE:
return 4167;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4168;
case Properties::Powered::FALSE:
return 4169;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4170;
case Properties::Powered::FALSE:
return 4171;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4172;
case Properties::Powered::FALSE:
return 4173;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 4174;
case Properties::Powered::FALSE:
return 4175;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 4176;
case Properties::Powered::FALSE:
return 4177;
}
}
}
}
}
return 0;
}
}

namespace IronOre {
constexpr Block toProtocol() {
return 112;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8278;
case Properties::Waterlogged::FALSE:
return 8279;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8280;
case Properties::Waterlogged::FALSE:
return 8281;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8282;
case Properties::Waterlogged::FALSE:
return 8283;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8284;
case Properties::Waterlogged::FALSE:
return 8285;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8286;
case Properties::Waterlogged::FALSE:
return 8287;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8288;
case Properties::Waterlogged::FALSE:
return 8289;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8290;
case Properties::Waterlogged::FALSE:
return 8291;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8292;
case Properties::Waterlogged::FALSE:
return 8293;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8294;
case Properties::Waterlogged::FALSE:
return 8295;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8296;
case Properties::Waterlogged::FALSE:
return 8297;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8298;
case Properties::Waterlogged::FALSE:
return 8299;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8300;
case Properties::Waterlogged::FALSE:
return 8301;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8302;
case Properties::Waterlogged::FALSE:
return 8303;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8304;
case Properties::Waterlogged::FALSE:
return 8305;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8306;
case Properties::Waterlogged::FALSE:
return 8307;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8308;
case Properties::Waterlogged::FALSE:
return 8309;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8310;
case Properties::Waterlogged::FALSE:
return 8311;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8312;
case Properties::Waterlogged::FALSE:
return 8313;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8314;
case Properties::Waterlogged::FALSE:
return 8315;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8316;
case Properties::Waterlogged::FALSE:
return 8317;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8318;
case Properties::Waterlogged::FALSE:
return 8319;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8320;
case Properties::Waterlogged::FALSE:
return 8321;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8322;
case Properties::Waterlogged::FALSE:
return 8323;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8324;
case Properties::Waterlogged::FALSE:
return 8325;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8326;
case Properties::Waterlogged::FALSE:
return 8327;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8328;
case Properties::Waterlogged::FALSE:
return 8329;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8330;
case Properties::Waterlogged::FALSE:
return 8331;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8332;
case Properties::Waterlogged::FALSE:
return 8333;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8334;
case Properties::Waterlogged::FALSE:
return 8335;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8336;
case Properties::Waterlogged::FALSE:
return 8337;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8338;
case Properties::Waterlogged::FALSE:
return 8339;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8340;
case Properties::Waterlogged::FALSE:
return 8341;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 4329;
case Properties::Facing::SOUTH:
return 4330;
case Properties::Facing::WEST:
return 4331;
case Properties::Facing::EAST:
return 4332;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Orientation orientation) {
switch (orientation) {
case Properties::Orientation::DOWN_EAST:
return 16948;
case Properties::Orientation::DOWN_NORTH:
return 16949;
case Properties::Orientation::DOWN_SOUTH:
return 16950;
case Properties::Orientation::DOWN_WEST:
return 16951;
case Properties::Orientation::UP_EAST:
return 16952;
case Properties::Orientation::UP_NORTH:
return 16953;
case Properties::Orientation::UP_SOUTH:
return 16954;
case Properties::Orientation::UP_WEST:
return 16955;
case Properties::Orientation::WEST_UP:
return 16956;
case Properties::Orientation::EAST_UP:
return 16957;
case Properties::Orientation::NORTH_UP:
return 16958;
case Properties::Orientation::SOUTH_UP:
return 16959;
}
return 0;
}
}

namespace Jukebox {
namespace Properties {
enum class Has_record {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Has_record has_record) {
switch (has_record) {
case Properties::Has_record::TRUE:
return 4273;
case Properties::Has_record::FALSE:
return 4274;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7011;
case Properties::Powered::FALSE:
return 7012;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7013;
case Properties::Powered::FALSE:
return 7014;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7015;
case Properties::Powered::FALSE:
return 7016;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7017;
case Properties::Powered::FALSE:
return 7018;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7019;
case Properties::Powered::FALSE:
return 7020;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7021;
case Properties::Powered::FALSE:
return 7022;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7023;
case Properties::Powered::FALSE:
return 7024;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7025;
case Properties::Powered::FALSE:
return 7026;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7027;
case Properties::Powered::FALSE:
return 7028;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7029;
case Properties::Powered::FALSE:
return 7030;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7031;
case Properties::Powered::FALSE:
return 7032;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7033;
case Properties::Powered::FALSE:
return 7034;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9683;
case Properties::Powered::FALSE:
return 9684;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9685;
case Properties::Powered::FALSE:
return 9686;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9687;
case Properties::Powered::FALSE:
return 9688;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9689;
case Properties::Powered::FALSE:
return 9690;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9691;
case Properties::Powered::FALSE:
return 9692;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9693;
case Properties::Powered::FALSE:
return 9694;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9695;
case Properties::Powered::FALSE:
return 9696;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9697;
case Properties::Powered::FALSE:
return 9698;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9699;
case Properties::Powered::FALSE:
return 9700;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9701;
case Properties::Powered::FALSE:
return 9702;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9703;
case Properties::Powered::FALSE:
return 9704;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9705;
case Properties::Powered::FALSE:
return 9706;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9707;
case Properties::Powered::FALSE:
return 9708;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9709;
case Properties::Powered::FALSE:
return 9710;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9711;
case Properties::Powered::FALSE:
return 9712;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9713;
case Properties::Powered::FALSE:
return 9714;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9715;
case Properties::Powered::FALSE:
return 9716;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9717;
case Properties::Powered::FALSE:
return 9718;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9719;
case Properties::Powered::FALSE:
return 9720;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9721;
case Properties::Powered::FALSE:
return 9722;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9723;
case Properties::Powered::FALSE:
return 9724;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9725;
case Properties::Powered::FALSE:
return 9726;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9727;
case Properties::Powered::FALSE:
return 9728;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9729;
case Properties::Powered::FALSE:
return 9730;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9731;
case Properties::Powered::FALSE:
return 9732;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9733;
case Properties::Powered::FALSE:
return 9734;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9735;
case Properties::Powered::FALSE:
return 9736;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9737;
case Properties::Powered::FALSE:
return 9738;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9739;
case Properties::Powered::FALSE:
return 9740;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9741;
case Properties::Powered::FALSE:
return 9742;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9743;
case Properties::Powered::FALSE:
return 9744;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9745;
case Properties::Powered::FALSE:
return 9746;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 9427;
case Properties::West::FALSE:
return 9428;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9429;
case Properties::West::FALSE:
return 9430;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9431;
case Properties::West::FALSE:
return 9432;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9433;
case Properties::West::FALSE:
return 9434;
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
return 9435;
case Properties::West::FALSE:
return 9436;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9437;
case Properties::West::FALSE:
return 9438;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9439;
case Properties::West::FALSE:
return 9440;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9441;
case Properties::West::FALSE:
return 9442;
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
return 9443;
case Properties::West::FALSE:
return 9444;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9445;
case Properties::West::FALSE:
return 9446;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9447;
case Properties::West::FALSE:
return 9448;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9449;
case Properties::West::FALSE:
return 9450;
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
return 9451;
case Properties::West::FALSE:
return 9452;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9453;
case Properties::West::FALSE:
return 9454;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9455;
case Properties::West::FALSE:
return 9456;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9457;
case Properties::West::FALSE:
return 9458;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9235;
case Properties::Powered::FALSE:
return 9236;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9237;
case Properties::Powered::FALSE:
return 9238;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9239;
case Properties::Powered::FALSE:
return 9240;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9241;
case Properties::Powered::FALSE:
return 9242;
}
}
}
case Properties::Facing::SOUTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9243;
case Properties::Powered::FALSE:
return 9244;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9245;
case Properties::Powered::FALSE:
return 9246;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9247;
case Properties::Powered::FALSE:
return 9248;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9249;
case Properties::Powered::FALSE:
return 9250;
}
}
}
case Properties::Facing::WEST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9251;
case Properties::Powered::FALSE:
return 9252;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9253;
case Properties::Powered::FALSE:
return 9254;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9255;
case Properties::Powered::FALSE:
return 9256;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9257;
case Properties::Powered::FALSE:
return 9258;
}
}
}
case Properties::Facing::EAST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9259;
case Properties::Powered::FALSE:
return 9260;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9261;
case Properties::Powered::FALSE:
return 9262;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9263;
case Properties::Powered::FALSE:
return 9264;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9265;
case Properties::Powered::FALSE:
return 9266;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 290;
case Properties::Waterlogged::FALSE:
return 291;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 292;
case Properties::Waterlogged::FALSE:
return 293;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 294;
case Properties::Waterlogged::FALSE:
return 295;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 296;
case Properties::Waterlogged::FALSE:
return 297;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 298;
case Properties::Waterlogged::FALSE:
return 299;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 300;
case Properties::Waterlogged::FALSE:
return 301;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 302;
case Properties::Waterlogged::FALSE:
return 303;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 304;
case Properties::Waterlogged::FALSE:
return 305;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 306;
case Properties::Waterlogged::FALSE:
return 307;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 308;
case Properties::Waterlogged::FALSE:
return 309;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 310;
case Properties::Waterlogged::FALSE:
return 311;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 312;
case Properties::Waterlogged::FALSE:
return 313;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 314;
case Properties::Waterlogged::FALSE:
return 315;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 316;
case Properties::Waterlogged::FALSE:
return 317;
}
}
}
return 0;
}
}

namespace JungleLog {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 126;
case Properties::Axis::Y:
return 127;
case Properties::Axis::Z:
return 128;
}
return 0;
}
}

namespace JunglePlanks {
constexpr Block toProtocol() {
return 18;
return 0;
}
}

namespace JunglePressurePlate {
namespace Properties {
enum class Powered {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Powered powered) {
switch (powered) {
case Properties::Powered::TRUE:
return 4184;
case Properties::Powered::FALSE:
return 4185;
}
return 0;
}
}

namespace JungleSapling {
namespace Properties {
enum class Stage {
ZERO,
ONE
};
}
constexpr Block toProtocol(Properties::Stage stage) {
switch (stage) {
case Properties::Stage::ZERO:
return 28;
case Properties::Stage::ONE:
return 29;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
switch (rotation) {
case Properties::Rotation::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3764;
case Properties::Waterlogged::FALSE:
return 3765;
}
case Properties::Rotation::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3766;
case Properties::Waterlogged::FALSE:
return 3767;
}
case Properties::Rotation::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3768;
case Properties::Waterlogged::FALSE:
return 3769;
}
case Properties::Rotation::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3770;
case Properties::Waterlogged::FALSE:
return 3771;
}
case Properties::Rotation::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3772;
case Properties::Waterlogged::FALSE:
return 3773;
}
case Properties::Rotation::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3774;
case Properties::Waterlogged::FALSE:
return 3775;
}
case Properties::Rotation::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3776;
case Properties::Waterlogged::FALSE:
return 3777;
}
case Properties::Rotation::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3778;
case Properties::Waterlogged::FALSE:
return 3779;
}
case Properties::Rotation::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3780;
case Properties::Waterlogged::FALSE:
return 3781;
}
case Properties::Rotation::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3782;
case Properties::Waterlogged::FALSE:
return 3783;
}
case Properties::Rotation::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3784;
case Properties::Waterlogged::FALSE:
return 3785;
}
case Properties::Rotation::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3786;
case Properties::Waterlogged::FALSE:
return 3787;
}
case Properties::Rotation::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3788;
case Properties::Waterlogged::FALSE:
return 3789;
}
case Properties::Rotation::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3790;
case Properties::Waterlogged::FALSE:
return 3791;
}
case Properties::Rotation::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3792;
case Properties::Waterlogged::FALSE:
return 3793;
}
case Properties::Rotation::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3794;
case Properties::Waterlogged::FALSE:
return 3795;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9059;
case Properties::Waterlogged::FALSE:
return 9060;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9061;
case Properties::Waterlogged::FALSE:
return 9062;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9063;
case Properties::Waterlogged::FALSE:
return 9064;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6156;
case Properties::Waterlogged::FALSE:
return 6157;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6158;
case Properties::Waterlogged::FALSE:
return 6159;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6160;
case Properties::Waterlogged::FALSE:
return 6161;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6162;
case Properties::Waterlogged::FALSE:
return 6163;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6164;
case Properties::Waterlogged::FALSE:
return 6165;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6166;
case Properties::Waterlogged::FALSE:
return 6167;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6168;
case Properties::Waterlogged::FALSE:
return 6169;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6170;
case Properties::Waterlogged::FALSE:
return 6171;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6172;
case Properties::Waterlogged::FALSE:
return 6173;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6174;
case Properties::Waterlogged::FALSE:
return 6175;
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
return 6176;
case Properties::Waterlogged::FALSE:
return 6177;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6178;
case Properties::Waterlogged::FALSE:
return 6179;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6180;
case Properties::Waterlogged::FALSE:
return 6181;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6182;
case Properties::Waterlogged::FALSE:
return 6183;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6184;
case Properties::Waterlogged::FALSE:
return 6185;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6186;
case Properties::Waterlogged::FALSE:
return 6187;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6188;
case Properties::Waterlogged::FALSE:
return 6189;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6190;
case Properties::Waterlogged::FALSE:
return 6191;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6192;
case Properties::Waterlogged::FALSE:
return 6193;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6194;
case Properties::Waterlogged::FALSE:
return 6195;
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
return 6196;
case Properties::Waterlogged::FALSE:
return 6197;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6198;
case Properties::Waterlogged::FALSE:
return 6199;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6200;
case Properties::Waterlogged::FALSE:
return 6201;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6202;
case Properties::Waterlogged::FALSE:
return 6203;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6204;
case Properties::Waterlogged::FALSE:
return 6205;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6206;
case Properties::Waterlogged::FALSE:
return 6207;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6208;
case Properties::Waterlogged::FALSE:
return 6209;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6210;
case Properties::Waterlogged::FALSE:
return 6211;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6212;
case Properties::Waterlogged::FALSE:
return 6213;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6214;
case Properties::Waterlogged::FALSE:
return 6215;
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
return 6216;
case Properties::Waterlogged::FALSE:
return 6217;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6218;
case Properties::Waterlogged::FALSE:
return 6219;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6220;
case Properties::Waterlogged::FALSE:
return 6221;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6222;
case Properties::Waterlogged::FALSE:
return 6223;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6224;
case Properties::Waterlogged::FALSE:
return 6225;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6226;
case Properties::Waterlogged::FALSE:
return 6227;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6228;
case Properties::Waterlogged::FALSE:
return 6229;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6230;
case Properties::Waterlogged::FALSE:
return 6231;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6232;
case Properties::Waterlogged::FALSE:
return 6233;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 6234;
case Properties::Waterlogged::FALSE:
return 6235;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4612;
case Properties::Waterlogged::FALSE:
return 4613;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4614;
case Properties::Waterlogged::FALSE:
return 4615;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4616;
case Properties::Waterlogged::FALSE:
return 4617;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4618;
case Properties::Waterlogged::FALSE:
return 4619;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4620;
case Properties::Waterlogged::FALSE:
return 4621;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4622;
case Properties::Waterlogged::FALSE:
return 4623;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4624;
case Properties::Waterlogged::FALSE:
return 4625;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4626;
case Properties::Waterlogged::FALSE:
return 4627;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4628;
case Properties::Waterlogged::FALSE:
return 4629;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4630;
case Properties::Waterlogged::FALSE:
return 4631;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4632;
case Properties::Waterlogged::FALSE:
return 4633;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4634;
case Properties::Waterlogged::FALSE:
return 4635;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4636;
case Properties::Waterlogged::FALSE:
return 4637;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4638;
case Properties::Waterlogged::FALSE:
return 4639;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4640;
case Properties::Waterlogged::FALSE:
return 4641;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4642;
case Properties::Waterlogged::FALSE:
return 4643;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4644;
case Properties::Waterlogged::FALSE:
return 4645;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4646;
case Properties::Waterlogged::FALSE:
return 4647;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4648;
case Properties::Waterlogged::FALSE:
return 4649;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4650;
case Properties::Waterlogged::FALSE:
return 4651;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4652;
case Properties::Waterlogged::FALSE:
return 4653;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4654;
case Properties::Waterlogged::FALSE:
return 4655;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4656;
case Properties::Waterlogged::FALSE:
return 4657;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4658;
case Properties::Waterlogged::FALSE:
return 4659;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4660;
case Properties::Waterlogged::FALSE:
return 4661;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4662;
case Properties::Waterlogged::FALSE:
return 4663;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4664;
case Properties::Waterlogged::FALSE:
return 4665;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4666;
case Properties::Waterlogged::FALSE:
return 4667;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4668;
case Properties::Waterlogged::FALSE:
return 4669;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4670;
case Properties::Waterlogged::FALSE:
return 4671;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4672;
case Properties::Waterlogged::FALSE:
return 4673;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4674;
case Properties::Waterlogged::FALSE:
return 4675;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4064;
case Properties::Waterlogged::FALSE:
return 4065;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4066;
case Properties::Waterlogged::FALSE:
return 4067;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4068;
case Properties::Waterlogged::FALSE:
return 4069;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4070;
case Properties::Waterlogged::FALSE:
return 4071;
}
}
return 0;
}
}

namespace JungleWood {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 173;
case Properties::Axis::Y:
return 174;
case Properties::Axis::Z:
return 175;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 10351;
case Properties::Age::ONE:
return 10352;
case Properties::Age::TWO:
return 10353;
case Properties::Age::THREE:
return 10354;
case Properties::Age::FOUR:
return 10355;
case Properties::Age::FIVE:
return 10356;
case Properties::Age::SIX:
return 10357;
case Properties::Age::SEVEN:
return 10358;
case Properties::Age::EIGHT:
return 10359;
case Properties::Age::NINE:
return 10360;
case Properties::Age::TEN:
return 10361;
case Properties::Age::ELEVEN:
return 10362;
case Properties::Age::TWELVE:
return 10363;
case Properties::Age::THIRTEEN:
return 10364;
case Properties::Age::FOURTEEN:
return 10365;
case Properties::Age::FIFTEEN:
return 10366;
case Properties::Age::SIXTEEN:
return 10367;
case Properties::Age::SEVENTEEN:
return 10368;
case Properties::Age::EIGHTEEN:
return 10369;
case Properties::Age::NINETEEN:
return 10370;
case Properties::Age::TWENTY:
return 10371;
case Properties::Age::TWENTY_ONE:
return 10372;
case Properties::Age::TWENTY_TWO:
return 10373;
case Properties::Age::TWENTY_THREE:
return 10374;
case Properties::Age::TWENTY_FOUR:
return 10375;
case Properties::Age::TWENTY_FIVE:
return 10376;
}
return 0;
}
}

namespace KelpPlant {
constexpr Block toProtocol() {
return 10377;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3924;
case Properties::Waterlogged::FALSE:
return 3925;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3926;
case Properties::Waterlogged::FALSE:
return 3927;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3928;
case Properties::Waterlogged::FALSE:
return 3929;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3930;
case Properties::Waterlogged::FALSE:
return 3931;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged) {
switch (hanging) {
case Properties::Hanging::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16091;
case Properties::Waterlogged::FALSE:
return 16092;
}
case Properties::Hanging::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 16093;
case Properties::Waterlogged::FALSE:
return 16094;
}
}
return 0;
}
}

namespace LapisBlock {
constexpr Block toProtocol() {
return 463;
return 0;
}
}

namespace LapisOre {
constexpr Block toProtocol() {
return 461;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18633;
case Properties::Waterlogged::FALSE:
return 18634;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18635;
case Properties::Waterlogged::FALSE:
return 18636;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18637;
case Properties::Waterlogged::FALSE:
return 18638;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18639;
case Properties::Waterlogged::FALSE:
return 18640;
}
case Properties::Facing::UP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18641;
case Properties::Waterlogged::FALSE:
return 18642;
}
case Properties::Facing::DOWN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18643;
case Properties::Waterlogged::FALSE:
return 18644;
}
}
return 0;
}
}

namespace LargeFern {
namespace Properties {
enum class Half {
UPPER,
LOWER
};
}
constexpr Block toProtocol(Properties::Half half) {
switch (half) {
case Properties::Half::UPPER:
return 8636;
case Properties::Half::LOWER:
return 8637;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Level level) {
switch (level) {
case Properties::Level::ZERO:
return 91;
case Properties::Level::ONE:
return 92;
case Properties::Level::TWO:
return 93;
case Properties::Level::THREE:
return 94;
case Properties::Level::FOUR:
return 95;
case Properties::Level::FIVE:
return 96;
case Properties::Level::SIX:
return 97;
case Properties::Level::SEVEN:
return 98;
case Properties::Level::EIGHT:
return 99;
case Properties::Level::NINE:
return 100;
case Properties::Level::TEN:
return 101;
case Properties::Level::ELEVEN:
return 102;
case Properties::Level::TWELVE:
return 103;
case Properties::Level::THIRTEEN:
return 104;
case Properties::Level::FOURTEEN:
return 105;
case Properties::Level::FIFTEEN:
return 106;
}
return 0;
}
}

namespace LavaCauldron {
constexpr Block toProtocol() {
return 5732;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Has_book has_book, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (has_book) {
case Properties::Has_book::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16038;
case Properties::Powered::FALSE:
return 16039;
}
case Properties::Has_book::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16040;
case Properties::Powered::FALSE:
return 16041;
}
}
case Properties::Facing::SOUTH:
switch (has_book) {
case Properties::Has_book::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16042;
case Properties::Powered::FALSE:
return 16043;
}
case Properties::Has_book::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16044;
case Properties::Powered::FALSE:
return 16045;
}
}
case Properties::Facing::WEST:
switch (has_book) {
case Properties::Has_book::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16046;
case Properties::Powered::FALSE:
return 16047;
}
case Properties::Has_book::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16048;
case Properties::Powered::FALSE:
return 16049;
}
}
case Properties::Facing::EAST:
switch (has_book) {
case Properties::Has_book::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 16050;
case Properties::Powered::FALSE:
return 16051;
}
case Properties::Has_book::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 16052;
case Properties::Powered::FALSE:
return 16053;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 4088;
case Properties::Powered::FALSE:
return 4089;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 4090;
case Properties::Powered::FALSE:
return 4091;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 4092;
case Properties::Powered::FALSE:
return 4093;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 4094;
case Properties::Powered::FALSE:
return 4095;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 4096;
case Properties::Powered::FALSE:
return 4097;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 4098;
case Properties::Powered::FALSE:
return 4099;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 4100;
case Properties::Powered::FALSE:
return 4101;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 4102;
case Properties::Powered::FALSE:
return 4103;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 4104;
case Properties::Powered::FALSE:
return 4105;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 4106;
case Properties::Powered::FALSE:
return 4107;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 4108;
case Properties::Powered::FALSE:
return 4109;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 4110;
case Properties::Powered::FALSE:
return 4111;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Level level, Properties::Waterlogged waterlogged) {
switch (level) {
case Properties::Level::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8246;
case Properties::Waterlogged::FALSE:
return 8247;
}
case Properties::Level::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8248;
case Properties::Waterlogged::FALSE:
return 8249;
}
case Properties::Level::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8250;
case Properties::Waterlogged::FALSE:
return 8251;
}
case Properties::Level::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8252;
case Properties::Waterlogged::FALSE:
return 8253;
}
case Properties::Level::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8254;
case Properties::Waterlogged::FALSE:
return 8255;
}
case Properties::Level::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8256;
case Properties::Waterlogged::FALSE:
return 8257;
}
case Properties::Level::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8258;
case Properties::Waterlogged::FALSE:
return 8259;
}
case Properties::Level::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8260;
case Properties::Waterlogged::FALSE:
return 8261;
}
case Properties::Level::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8262;
case Properties::Waterlogged::FALSE:
return 8263;
}
case Properties::Level::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8264;
case Properties::Waterlogged::FALSE:
return 8265;
}
case Properties::Level::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8266;
case Properties::Waterlogged::FALSE:
return 8267;
}
case Properties::Level::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8268;
case Properties::Waterlogged::FALSE:
return 8269;
}
case Properties::Level::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8270;
case Properties::Waterlogged::FALSE:
return 8271;
}
case Properties::Level::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8272;
case Properties::Waterlogged::FALSE:
return 8273;
}
case Properties::Level::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8274;
case Properties::Waterlogged::FALSE:
return 8275;
}
case Properties::Level::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8276;
case Properties::Waterlogged::FALSE:
return 8277;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8686;
case Properties::Rotation::ONE:
return 8687;
case Properties::Rotation::TWO:
return 8688;
case Properties::Rotation::THREE:
return 8689;
case Properties::Rotation::FOUR:
return 8690;
case Properties::Rotation::FIVE:
return 8691;
case Properties::Rotation::SIX:
return 8692;
case Properties::Rotation::SEVEN:
return 8693;
case Properties::Rotation::EIGHT:
return 8694;
case Properties::Rotation::NINE:
return 8695;
case Properties::Rotation::TEN:
return 8696;
case Properties::Rotation::ELEVEN:
return 8697;
case Properties::Rotation::TWELVE:
return 8698;
case Properties::Rotation::THIRTEEN:
return 8699;
case Properties::Rotation::FOURTEEN:
return 8700;
case Properties::Rotation::FIFTEEN:
return 8701;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1327;
case Properties::Part::FOOT:
return 1328;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1329;
case Properties::Part::FOOT:
return 1330;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1331;
case Properties::Part::FOOT:
return 1332;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1333;
case Properties::Part::FOOT:
return 1334;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1335;
case Properties::Part::FOOT:
return 1336;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1337;
case Properties::Part::FOOT:
return 1338;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1339;
case Properties::Part::FOOT:
return 1340;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1341;
case Properties::Part::FOOT:
return 1342;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18377;
case Properties::Waterlogged::FALSE:
return 18378;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18379;
case Properties::Waterlogged::FALSE:
return 18380;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18381;
case Properties::Waterlogged::FALSE:
return 18382;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18383;
case Properties::Waterlogged::FALSE:
return 18384;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18385;
case Properties::Waterlogged::FALSE:
return 18386;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18387;
case Properties::Waterlogged::FALSE:
return 18388;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18389;
case Properties::Waterlogged::FALSE:
return 18390;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18391;
case Properties::Waterlogged::FALSE:
return 18392;
}
}
}
return 0;
}
}

namespace LightBlueCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18593;
case Properties::Lit::FALSE:
return 18594;
}
return 0;
}
}

namespace LightBlueCarpet {
constexpr Block toProtocol() {
return 8610;
return 0;
}
}

namespace LightBlueConcrete {
constexpr Block toProtocol() {
return 10322;
return 0;
}
}

namespace LightBlueConcretePowder {
constexpr Block toProtocol() {
return 10338;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10267;
case Properties::Facing::SOUTH:
return 10268;
case Properties::Facing::WEST:
return 10269;
case Properties::Facing::EAST:
return 10270;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10177;
case Properties::Facing::EAST:
return 10178;
case Properties::Facing::SOUTH:
return 10179;
case Properties::Facing::WEST:
return 10180;
case Properties::Facing::UP:
return 10181;
case Properties::Facing::DOWN:
return 10182;
}
return 0;
}
}

namespace LightBlueStainedGlass {
constexpr Block toProtocol() {
return 4407;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7588;
case Properties::West::FALSE:
return 7589;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7590;
case Properties::West::FALSE:
return 7591;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7592;
case Properties::West::FALSE:
return 7593;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7594;
case Properties::West::FALSE:
return 7595;
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
return 7596;
case Properties::West::FALSE:
return 7597;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7598;
case Properties::West::FALSE:
return 7599;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7600;
case Properties::West::FALSE:
return 7601;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7602;
case Properties::West::FALSE:
return 7603;
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
return 7604;
case Properties::West::FALSE:
return 7605;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7606;
case Properties::West::FALSE:
return 7607;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7608;
case Properties::West::FALSE:
return 7609;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7610;
case Properties::West::FALSE:
return 7611;
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
return 7612;
case Properties::West::FALSE:
return 7613;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7614;
case Properties::West::FALSE:
return 7615;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7616;
case Properties::West::FALSE:
return 7617;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7618;
case Properties::West::FALSE:
return 7619;
}
}
}
}
}
return 0;
}
}

namespace LightBlueTerracotta {
constexpr Block toProtocol() {
return 7479;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8906;
case Properties::Facing::SOUTH:
return 8907;
case Properties::Facing::WEST:
return 8908;
case Properties::Facing::EAST:
return 8909;
}
return 0;
}
}

namespace LightBlueWool {
constexpr Block toProtocol() {
return 1641;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8766;
case Properties::Rotation::ONE:
return 8767;
case Properties::Rotation::TWO:
return 8768;
case Properties::Rotation::THREE:
return 8769;
case Properties::Rotation::FOUR:
return 8770;
case Properties::Rotation::FIVE:
return 8771;
case Properties::Rotation::SIX:
return 8772;
case Properties::Rotation::SEVEN:
return 8773;
case Properties::Rotation::EIGHT:
return 8774;
case Properties::Rotation::NINE:
return 8775;
case Properties::Rotation::TEN:
return 8776;
case Properties::Rotation::ELEVEN:
return 8777;
case Properties::Rotation::TWELVE:
return 8778;
case Properties::Rotation::THIRTEEN:
return 8779;
case Properties::Rotation::FOURTEEN:
return 8780;
case Properties::Rotation::FIFTEEN:
return 8781;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1407;
case Properties::Part::FOOT:
return 1408;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1409;
case Properties::Part::FOOT:
return 1410;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1411;
case Properties::Part::FOOT:
return 1412;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1413;
case Properties::Part::FOOT:
return 1414;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1415;
case Properties::Part::FOOT:
return 1416;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1417;
case Properties::Part::FOOT:
return 1418;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1419;
case Properties::Part::FOOT:
return 1420;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1421;
case Properties::Part::FOOT:
return 1422;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18457;
case Properties::Waterlogged::FALSE:
return 18458;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18459;
case Properties::Waterlogged::FALSE:
return 18460;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18461;
case Properties::Waterlogged::FALSE:
return 18462;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18463;
case Properties::Waterlogged::FALSE:
return 18464;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18465;
case Properties::Waterlogged::FALSE:
return 18466;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18467;
case Properties::Waterlogged::FALSE:
return 18468;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18469;
case Properties::Waterlogged::FALSE:
return 18470;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18471;
case Properties::Waterlogged::FALSE:
return 18472;
}
}
}
return 0;
}
}

namespace LightGrayCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18603;
case Properties::Lit::FALSE:
return 18604;
}
return 0;
}
}

namespace LightGrayCarpet {
constexpr Block toProtocol() {
return 8615;
return 0;
}
}

namespace LightGrayConcrete {
constexpr Block toProtocol() {
return 10327;
return 0;
}
}

namespace LightGrayConcretePowder {
constexpr Block toProtocol() {
return 10343;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10287;
case Properties::Facing::SOUTH:
return 10288;
case Properties::Facing::WEST:
return 10289;
case Properties::Facing::EAST:
return 10290;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10207;
case Properties::Facing::EAST:
return 10208;
case Properties::Facing::SOUTH:
return 10209;
case Properties::Facing::WEST:
return 10210;
case Properties::Facing::UP:
return 10211;
case Properties::Facing::DOWN:
return 10212;
}
return 0;
}
}

namespace LightGrayStainedGlass {
constexpr Block toProtocol() {
return 4412;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7748;
case Properties::West::FALSE:
return 7749;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7750;
case Properties::West::FALSE:
return 7751;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7752;
case Properties::West::FALSE:
return 7753;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7754;
case Properties::West::FALSE:
return 7755;
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
return 7756;
case Properties::West::FALSE:
return 7757;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7758;
case Properties::West::FALSE:
return 7759;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7760;
case Properties::West::FALSE:
return 7761;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7762;
case Properties::West::FALSE:
return 7763;
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
return 7764;
case Properties::West::FALSE:
return 7765;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7766;
case Properties::West::FALSE:
return 7767;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7768;
case Properties::West::FALSE:
return 7769;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7770;
case Properties::West::FALSE:
return 7771;
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
return 7772;
case Properties::West::FALSE:
return 7773;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7774;
case Properties::West::FALSE:
return 7775;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7776;
case Properties::West::FALSE:
return 7777;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7778;
case Properties::West::FALSE:
return 7779;
}
}
}
}
}
return 0;
}
}

namespace LightGrayTerracotta {
constexpr Block toProtocol() {
return 7484;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8926;
case Properties::Facing::SOUTH:
return 8927;
case Properties::Facing::WEST:
return 8928;
case Properties::Facing::EAST:
return 8929;
}
return 0;
}
}

namespace LightGrayWool {
constexpr Block toProtocol() {
return 1646;
return 0;
}
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
constexpr Block toProtocol(Properties::Power power) {
switch (power) {
case Properties::Power::ZERO:
return 7263;
case Properties::Power::ONE:
return 7264;
case Properties::Power::TWO:
return 7265;
case Properties::Power::THREE:
return 7266;
case Properties::Power::FOUR:
return 7267;
case Properties::Power::FIVE:
return 7268;
case Properties::Power::SIX:
return 7269;
case Properties::Power::SEVEN:
return 7270;
case Properties::Power::EIGHT:
return 7271;
case Properties::Power::NINE:
return 7272;
case Properties::Power::TEN:
return 7273;
case Properties::Power::ELEVEN:
return 7274;
case Properties::Power::TWELVE:
return 7275;
case Properties::Power::THIRTEEN:
return 7276;
case Properties::Power::FOURTEEN:
return 7277;
case Properties::Power::FIFTEEN:
return 7278;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19614;
case Properties::Waterlogged::FALSE:
return 19615;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19616;
case Properties::Waterlogged::FALSE:
return 19617;
}
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19618;
case Properties::Waterlogged::FALSE:
return 19619;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19620;
case Properties::Waterlogged::FALSE:
return 19621;
}
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19622;
case Properties::Waterlogged::FALSE:
return 19623;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19624;
case Properties::Waterlogged::FALSE:
return 19625;
}
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19626;
case Properties::Waterlogged::FALSE:
return 19627;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19628;
case Properties::Waterlogged::FALSE:
return 19629;
}
}
case Properties::Facing::UP:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19630;
case Properties::Waterlogged::FALSE:
return 19631;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19632;
case Properties::Waterlogged::FALSE:
return 19633;
}
}
case Properties::Facing::DOWN:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19634;
case Properties::Waterlogged::FALSE:
return 19635;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 19636;
case Properties::Waterlogged::FALSE:
return 19637;
}
}
}
return 0;
}
}

namespace Lilac {
namespace Properties {
enum class Half {
UPPER,
LOWER
};
}
constexpr Block toProtocol(Properties::Half half) {
switch (half) {
case Properties::Half::UPPER:
return 8628;
case Properties::Half::LOWER:
return 8629;
}
return 0;
}
}

namespace LilyOfTheValley {
constexpr Block toProtocol() {
return 1678;
return 0;
}
}

namespace LilyPad {
constexpr Block toProtocol() {
return 5601;
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8718;
case Properties::Rotation::ONE:
return 8719;
case Properties::Rotation::TWO:
return 8720;
case Properties::Rotation::THREE:
return 8721;
case Properties::Rotation::FOUR:
return 8722;
case Properties::Rotation::FIVE:
return 8723;
case Properties::Rotation::SIX:
return 8724;
case Properties::Rotation::SEVEN:
return 8725;
case Properties::Rotation::EIGHT:
return 8726;
case Properties::Rotation::NINE:
return 8727;
case Properties::Rotation::TEN:
return 8728;
case Properties::Rotation::ELEVEN:
return 8729;
case Properties::Rotation::TWELVE:
return 8730;
case Properties::Rotation::THIRTEEN:
return 8731;
case Properties::Rotation::FOURTEEN:
return 8732;
case Properties::Rotation::FIFTEEN:
return 8733;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1359;
case Properties::Part::FOOT:
return 1360;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1361;
case Properties::Part::FOOT:
return 1362;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1363;
case Properties::Part::FOOT:
return 1364;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1365;
case Properties::Part::FOOT:
return 1366;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1367;
case Properties::Part::FOOT:
return 1368;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1369;
case Properties::Part::FOOT:
return 1370;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1371;
case Properties::Part::FOOT:
return 1372;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1373;
case Properties::Part::FOOT:
return 1374;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18409;
case Properties::Waterlogged::FALSE:
return 18410;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18411;
case Properties::Waterlogged::FALSE:
return 18412;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18413;
case Properties::Waterlogged::FALSE:
return 18414;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18415;
case Properties::Waterlogged::FALSE:
return 18416;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18417;
case Properties::Waterlogged::FALSE:
return 18418;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18419;
case Properties::Waterlogged::FALSE:
return 18420;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18421;
case Properties::Waterlogged::FALSE:
return 18422;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18423;
case Properties::Waterlogged::FALSE:
return 18424;
}
}
}
return 0;
}
}

namespace LimeCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18597;
case Properties::Lit::FALSE:
return 18598;
}
return 0;
}
}

namespace LimeCarpet {
constexpr Block toProtocol() {
return 8612;
return 0;
}
}

namespace LimeConcrete {
constexpr Block toProtocol() {
return 10324;
return 0;
}
}

namespace LimeConcretePowder {
constexpr Block toProtocol() {
return 10340;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10275;
case Properties::Facing::SOUTH:
return 10276;
case Properties::Facing::WEST:
return 10277;
case Properties::Facing::EAST:
return 10278;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10189;
case Properties::Facing::EAST:
return 10190;
case Properties::Facing::SOUTH:
return 10191;
case Properties::Facing::WEST:
return 10192;
case Properties::Facing::UP:
return 10193;
case Properties::Facing::DOWN:
return 10194;
}
return 0;
}
}

namespace LimeStainedGlass {
constexpr Block toProtocol() {
return 4409;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7652;
case Properties::West::FALSE:
return 7653;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7654;
case Properties::West::FALSE:
return 7655;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7656;
case Properties::West::FALSE:
return 7657;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7658;
case Properties::West::FALSE:
return 7659;
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
return 7660;
case Properties::West::FALSE:
return 7661;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7662;
case Properties::West::FALSE:
return 7663;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7664;
case Properties::West::FALSE:
return 7665;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7666;
case Properties::West::FALSE:
return 7667;
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
return 7668;
case Properties::West::FALSE:
return 7669;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7670;
case Properties::West::FALSE:
return 7671;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7672;
case Properties::West::FALSE:
return 7673;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7674;
case Properties::West::FALSE:
return 7675;
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
return 7676;
case Properties::West::FALSE:
return 7677;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7678;
case Properties::West::FALSE:
return 7679;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7680;
case Properties::West::FALSE:
return 7681;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7682;
case Properties::West::FALSE:
return 7683;
}
}
}
}
}
return 0;
}
}

namespace LimeTerracotta {
constexpr Block toProtocol() {
return 7481;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8914;
case Properties::Facing::SOUTH:
return 8915;
case Properties::Facing::WEST:
return 8916;
case Properties::Facing::EAST:
return 8917;
}
return 0;
}
}

namespace LimeWool {
constexpr Block toProtocol() {
return 1643;
return 0;
}
}

namespace Lodestone {
constexpr Block toProtocol() {
return 17047;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 15992;
case Properties::Facing::SOUTH:
return 15993;
case Properties::Facing::WEST:
return 15994;
case Properties::Facing::EAST:
return 15995;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation) {
switch (rotation) {
case Properties::Rotation::ZERO:
return 8670;
case Properties::Rotation::ONE:
return 8671;
case Properties::Rotation::TWO:
return 8672;
case Properties::Rotation::THREE:
return 8673;
case Properties::Rotation::FOUR:
return 8674;
case Properties::Rotation::FIVE:
return 8675;
case Properties::Rotation::SIX:
return 8676;
case Properties::Rotation::SEVEN:
return 8677;
case Properties::Rotation::EIGHT:
return 8678;
case Properties::Rotation::NINE:
return 8679;
case Properties::Rotation::TEN:
return 8680;
case Properties::Rotation::ELEVEN:
return 8681;
case Properties::Rotation::TWELVE:
return 8682;
case Properties::Rotation::THIRTEEN:
return 8683;
case Properties::Rotation::FOURTEEN:
return 8684;
case Properties::Rotation::FIFTEEN:
return 8685;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
switch (facing) {
case Properties::Facing::NORTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1311;
case Properties::Part::FOOT:
return 1312;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1313;
case Properties::Part::FOOT:
return 1314;
}
}
case Properties::Facing::SOUTH:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1315;
case Properties::Part::FOOT:
return 1316;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1317;
case Properties::Part::FOOT:
return 1318;
}
}
case Properties::Facing::WEST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1319;
case Properties::Part::FOOT:
return 1320;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1321;
case Properties::Part::FOOT:
return 1322;
}
}
case Properties::Facing::EAST:
switch (occupied) {
case Properties::Occupied::TRUE:
switch (part) {
case Properties::Part::HEAD:
return 1323;
case Properties::Part::FOOT:
return 1324;
}
case Properties::Occupied::FALSE:
switch (part) {
case Properties::Part::HEAD:
return 1325;
case Properties::Part::FOOT:
return 1326;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
switch (candles) {
case Properties::Candles::ONE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18361;
case Properties::Waterlogged::FALSE:
return 18362;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18363;
case Properties::Waterlogged::FALSE:
return 18364;
}
}
case Properties::Candles::TWO:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18365;
case Properties::Waterlogged::FALSE:
return 18366;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18367;
case Properties::Waterlogged::FALSE:
return 18368;
}
}
case Properties::Candles::THREE:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18369;
case Properties::Waterlogged::FALSE:
return 18370;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18371;
case Properties::Waterlogged::FALSE:
return 18372;
}
}
case Properties::Candles::FOUR:
switch (lit) {
case Properties::Lit::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18373;
case Properties::Waterlogged::FALSE:
return 18374;
}
case Properties::Lit::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18375;
case Properties::Waterlogged::FALSE:
return 18376;
}
}
}
return 0;
}
}

namespace MagentaCandleCake {
namespace Properties {
enum class Lit {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Lit lit) {
switch (lit) {
case Properties::Lit::TRUE:
return 18591;
case Properties::Lit::FALSE:
return 18592;
}
return 0;
}
}

namespace MagentaCarpet {
constexpr Block toProtocol() {
return 8609;
return 0;
}
}

namespace MagentaConcrete {
constexpr Block toProtocol() {
return 10321;
return 0;
}
}

namespace MagentaConcretePowder {
constexpr Block toProtocol() {
return 10337;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10263;
case Properties::Facing::SOUTH:
return 10264;
case Properties::Facing::WEST:
return 10265;
case Properties::Facing::EAST:
return 10266;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 10171;
case Properties::Facing::EAST:
return 10172;
case Properties::Facing::SOUTH:
return 10173;
case Properties::Facing::WEST:
return 10174;
case Properties::Facing::UP:
return 10175;
case Properties::Facing::DOWN:
return 10176;
}
return 0;
}
}

namespace MagentaStainedGlass {
constexpr Block toProtocol() {
return 4406;
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 7556;
case Properties::West::FALSE:
return 7557;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7558;
case Properties::West::FALSE:
return 7559;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7560;
case Properties::West::FALSE:
return 7561;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7562;
case Properties::West::FALSE:
return 7563;
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
return 7564;
case Properties::West::FALSE:
return 7565;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7566;
case Properties::West::FALSE:
return 7567;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7568;
case Properties::West::FALSE:
return 7569;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7570;
case Properties::West::FALSE:
return 7571;
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
return 7572;
case Properties::West::FALSE:
return 7573;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7574;
case Properties::West::FALSE:
return 7575;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7576;
case Properties::West::FALSE:
return 7577;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7578;
case Properties::West::FALSE:
return 7579;
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
return 7580;
case Properties::West::FALSE:
return 7581;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7582;
case Properties::West::FALSE:
return 7583;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 7584;
case Properties::West::FALSE:
return 7585;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 7586;
case Properties::West::FALSE:
return 7587;
}
}
}
}
}
return 0;
}
}

namespace MagentaTerracotta {
constexpr Block toProtocol() {
return 7478;
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing) {
switch (facing) {
case Properties::Facing::NORTH:
return 8902;
case Properties::Facing::SOUTH:
return 8903;
case Properties::Facing::WEST:
return 8904;
case Properties::Facing::EAST:
return 8905;
}
return 0;
}
}

namespace MagentaWool {
constexpr Block toProtocol() {
return 1640;
return 0;
}
}

namespace MagmaBlock {
constexpr Block toProtocol() {
return 10134;
return 0;
}
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
constexpr Block toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
switch (face) {
case Properties::Face::FLOOR:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7083;
case Properties::Powered::FALSE:
return 7084;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7085;
case Properties::Powered::FALSE:
return 7086;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7087;
case Properties::Powered::FALSE:
return 7088;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7089;
case Properties::Powered::FALSE:
return 7090;
}
}
case Properties::Face::WALL:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7091;
case Properties::Powered::FALSE:
return 7092;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7093;
case Properties::Powered::FALSE:
return 7094;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7095;
case Properties::Powered::FALSE:
return 7096;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7097;
case Properties::Powered::FALSE:
return 7098;
}
}
case Properties::Face::CEILING:
switch (facing) {
case Properties::Facing::NORTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7099;
case Properties::Powered::FALSE:
return 7100;
}
case Properties::Facing::SOUTH:
switch (powered) {
case Properties::Powered::TRUE:
return 7101;
case Properties::Powered::FALSE:
return 7102;
}
case Properties::Facing::WEST:
switch (powered) {
case Properties::Powered::TRUE:
return 7103;
case Properties::Powered::FALSE:
return 7104;
}
case Properties::Facing::EAST:
switch (powered) {
case Properties::Powered::TRUE:
return 7105;
case Properties::Powered::FALSE:
return 7106;
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9875;
case Properties::Powered::FALSE:
return 9876;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9877;
case Properties::Powered::FALSE:
return 9878;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9879;
case Properties::Powered::FALSE:
return 9880;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9881;
case Properties::Powered::FALSE:
return 9882;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9883;
case Properties::Powered::FALSE:
return 9884;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9885;
case Properties::Powered::FALSE:
return 9886;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9887;
case Properties::Powered::FALSE:
return 9888;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9889;
case Properties::Powered::FALSE:
return 9890;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9891;
case Properties::Powered::FALSE:
return 9892;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9893;
case Properties::Powered::FALSE:
return 9894;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9895;
case Properties::Powered::FALSE:
return 9896;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9897;
case Properties::Powered::FALSE:
return 9898;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9899;
case Properties::Powered::FALSE:
return 9900;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9901;
case Properties::Powered::FALSE:
return 9902;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9903;
case Properties::Powered::FALSE:
return 9904;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9905;
case Properties::Powered::FALSE:
return 9906;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9907;
case Properties::Powered::FALSE:
return 9908;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9909;
case Properties::Powered::FALSE:
return 9910;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9911;
case Properties::Powered::FALSE:
return 9912;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9913;
case Properties::Powered::FALSE:
return 9914;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9915;
case Properties::Powered::FALSE:
return 9916;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9917;
case Properties::Powered::FALSE:
return 9918;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9919;
case Properties::Powered::FALSE:
return 9920;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9921;
case Properties::Powered::FALSE:
return 9922;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::UPPER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9923;
case Properties::Powered::FALSE:
return 9924;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9925;
case Properties::Powered::FALSE:
return 9926;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9927;
case Properties::Powered::FALSE:
return 9928;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9929;
case Properties::Powered::FALSE:
return 9930;
}
}
}
case Properties::Half::LOWER:
switch (hinge) {
case Properties::Hinge::LEFT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9931;
case Properties::Powered::FALSE:
return 9932;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9933;
case Properties::Powered::FALSE:
return 9934;
}
}
case Properties::Hinge::RIGHT:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9935;
case Properties::Powered::FALSE:
return 9936;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9937;
case Properties::Powered::FALSE:
return 9938;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 9523;
case Properties::West::FALSE:
return 9524;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9525;
case Properties::West::FALSE:
return 9526;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9527;
case Properties::West::FALSE:
return 9528;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9529;
case Properties::West::FALSE:
return 9530;
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
return 9531;
case Properties::West::FALSE:
return 9532;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9533;
case Properties::West::FALSE:
return 9534;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9535;
case Properties::West::FALSE:
return 9536;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9537;
case Properties::West::FALSE:
return 9538;
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
return 9539;
case Properties::West::FALSE:
return 9540;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9541;
case Properties::West::FALSE:
return 9542;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9543;
case Properties::West::FALSE:
return 9544;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9545;
case Properties::West::FALSE:
return 9546;
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
return 9547;
case Properties::West::FALSE:
return 9548;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9549;
case Properties::West::FALSE:
return 9550;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 9551;
case Properties::West::FALSE:
return 9552;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 9553;
case Properties::West::FALSE:
return 9554;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
switch (facing) {
case Properties::Facing::NORTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9331;
case Properties::Powered::FALSE:
return 9332;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9333;
case Properties::Powered::FALSE:
return 9334;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9335;
case Properties::Powered::FALSE:
return 9336;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9337;
case Properties::Powered::FALSE:
return 9338;
}
}
}
case Properties::Facing::SOUTH:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9339;
case Properties::Powered::FALSE:
return 9340;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9341;
case Properties::Powered::FALSE:
return 9342;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9343;
case Properties::Powered::FALSE:
return 9344;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9345;
case Properties::Powered::FALSE:
return 9346;
}
}
}
case Properties::Facing::WEST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9347;
case Properties::Powered::FALSE:
return 9348;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9349;
case Properties::Powered::FALSE:
return 9350;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9351;
case Properties::Powered::FALSE:
return 9352;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9353;
case Properties::Powered::FALSE:
return 9354;
}
}
}
case Properties::Facing::EAST:
switch (in_wall) {
case Properties::In_wall::TRUE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9355;
case Properties::Powered::FALSE:
return 9356;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9357;
case Properties::Powered::FALSE:
return 9358;
}
}
case Properties::In_wall::FALSE:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
return 9359;
case Properties::Powered::FALSE:
return 9360;
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
return 9361;
case Properties::Powered::FALSE:
return 9362;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
switch (distance) {
case Properties::Distance::ONE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 374;
case Properties::Waterlogged::FALSE:
return 375;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 376;
case Properties::Waterlogged::FALSE:
return 377;
}
}
case Properties::Distance::TWO:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 378;
case Properties::Waterlogged::FALSE:
return 379;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 380;
case Properties::Waterlogged::FALSE:
return 381;
}
}
case Properties::Distance::THREE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 382;
case Properties::Waterlogged::FALSE:
return 383;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 384;
case Properties::Waterlogged::FALSE:
return 385;
}
}
case Properties::Distance::FOUR:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 386;
case Properties::Waterlogged::FALSE:
return 387;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 388;
case Properties::Waterlogged::FALSE:
return 389;
}
}
case Properties::Distance::FIVE:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 390;
case Properties::Waterlogged::FALSE:
return 391;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 392;
case Properties::Waterlogged::FALSE:
return 393;
}
}
case Properties::Distance::SIX:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 394;
case Properties::Waterlogged::FALSE:
return 395;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 396;
case Properties::Waterlogged::FALSE:
return 397;
}
}
case Properties::Distance::SEVEN:
switch (persistent) {
case Properties::Persistent::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 398;
case Properties::Waterlogged::FALSE:
return 399;
}
case Properties::Persistent::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 400;
case Properties::Waterlogged::FALSE:
return 401;
}
}
}
return 0;
}
}

namespace MangroveLog {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 135;
case Properties::Axis::Y:
return 136;
case Properties::Axis::Z:
return 137;
}
return 0;
}
}

namespace MangrovePlanks {
constexpr Block toProtocol() {
return 21;
return 0;
}
}

namespace MangrovePressurePlate {
namespace Properties {
enum class Powered {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Powered powered) {
switch (powered) {
case Properties::Powered::TRUE:
return 4190;
case Properties::Powered::FALSE:
return 4191;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Age age, Properties::Hanging hanging, Properties::Stage stage, Properties::Waterlogged waterlogged) {
switch (age) {
case Properties::Age::ZERO:
switch (hanging) {
case Properties::Hanging::TRUE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 34;
case Properties::Waterlogged::FALSE:
return 35;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 36;
case Properties::Waterlogged::FALSE:
return 37;
}
}
case Properties::Hanging::FALSE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 38;
case Properties::Waterlogged::FALSE:
return 39;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 40;
case Properties::Waterlogged::FALSE:
return 41;
}
}
}
case Properties::Age::ONE:
switch (hanging) {
case Properties::Hanging::TRUE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 42;
case Properties::Waterlogged::FALSE:
return 43;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 44;
case Properties::Waterlogged::FALSE:
return 45;
}
}
case Properties::Hanging::FALSE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 46;
case Properties::Waterlogged::FALSE:
return 47;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 48;
case Properties::Waterlogged::FALSE:
return 49;
}
}
}
case Properties::Age::TWO:
switch (hanging) {
case Properties::Hanging::TRUE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 50;
case Properties::Waterlogged::FALSE:
return 51;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 52;
case Properties::Waterlogged::FALSE:
return 53;
}
}
case Properties::Hanging::FALSE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 54;
case Properties::Waterlogged::FALSE:
return 55;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 56;
case Properties::Waterlogged::FALSE:
return 57;
}
}
}
case Properties::Age::THREE:
switch (hanging) {
case Properties::Hanging::TRUE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 58;
case Properties::Waterlogged::FALSE:
return 59;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 60;
case Properties::Waterlogged::FALSE:
return 61;
}
}
case Properties::Hanging::FALSE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 62;
case Properties::Waterlogged::FALSE:
return 63;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 64;
case Properties::Waterlogged::FALSE:
return 65;
}
}
}
case Properties::Age::FOUR:
switch (hanging) {
case Properties::Hanging::TRUE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 66;
case Properties::Waterlogged::FALSE:
return 67;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 68;
case Properties::Waterlogged::FALSE:
return 69;
}
}
case Properties::Hanging::FALSE:
switch (stage) {
case Properties::Stage::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 70;
case Properties::Waterlogged::FALSE:
return 71;
}
case Properties::Stage::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 72;
case Properties::Waterlogged::FALSE:
return 73;
}
}
}
}
return 0;
}
}

namespace MangroveRoots {
namespace Properties {
enum class Waterlogged {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Waterlogged waterlogged) {
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 138;
case Properties::Waterlogged::FALSE:
return 139;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
switch (rotation) {
case Properties::Rotation::ZERO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3828;
case Properties::Waterlogged::FALSE:
return 3829;
}
case Properties::Rotation::ONE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3830;
case Properties::Waterlogged::FALSE:
return 3831;
}
case Properties::Rotation::TWO:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3832;
case Properties::Waterlogged::FALSE:
return 3833;
}
case Properties::Rotation::THREE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3834;
case Properties::Waterlogged::FALSE:
return 3835;
}
case Properties::Rotation::FOUR:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3836;
case Properties::Waterlogged::FALSE:
return 3837;
}
case Properties::Rotation::FIVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3838;
case Properties::Waterlogged::FALSE:
return 3839;
}
case Properties::Rotation::SIX:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3840;
case Properties::Waterlogged::FALSE:
return 3841;
}
case Properties::Rotation::SEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3842;
case Properties::Waterlogged::FALSE:
return 3843;
}
case Properties::Rotation::EIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3844;
case Properties::Waterlogged::FALSE:
return 3845;
}
case Properties::Rotation::NINE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3846;
case Properties::Waterlogged::FALSE:
return 3847;
}
case Properties::Rotation::TEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3848;
case Properties::Waterlogged::FALSE:
return 3849;
}
case Properties::Rotation::ELEVEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3850;
case Properties::Waterlogged::FALSE:
return 3851;
}
case Properties::Rotation::TWELVE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3852;
case Properties::Waterlogged::FALSE:
return 3853;
}
case Properties::Rotation::THIRTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3854;
case Properties::Waterlogged::FALSE:
return 3855;
}
case Properties::Rotation::FOURTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3856;
case Properties::Waterlogged::FALSE:
return 3857;
}
case Properties::Rotation::FIFTEEN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 3858;
case Properties::Waterlogged::FALSE:
return 3859;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9077;
case Properties::Waterlogged::FALSE:
return 9078;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9079;
case Properties::Waterlogged::FALSE:
return 9080;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9081;
case Properties::Waterlogged::FALSE:
return 9082;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8164;
case Properties::Waterlogged::FALSE:
return 8165;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8166;
case Properties::Waterlogged::FALSE:
return 8167;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8168;
case Properties::Waterlogged::FALSE:
return 8169;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8170;
case Properties::Waterlogged::FALSE:
return 8171;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8172;
case Properties::Waterlogged::FALSE:
return 8173;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8174;
case Properties::Waterlogged::FALSE:
return 8175;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8176;
case Properties::Waterlogged::FALSE:
return 8177;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8178;
case Properties::Waterlogged::FALSE:
return 8179;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8180;
case Properties::Waterlogged::FALSE:
return 8181;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8182;
case Properties::Waterlogged::FALSE:
return 8183;
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
return 8184;
case Properties::Waterlogged::FALSE:
return 8185;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8186;
case Properties::Waterlogged::FALSE:
return 8187;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8188;
case Properties::Waterlogged::FALSE:
return 8189;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8190;
case Properties::Waterlogged::FALSE:
return 8191;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8192;
case Properties::Waterlogged::FALSE:
return 8193;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8194;
case Properties::Waterlogged::FALSE:
return 8195;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8196;
case Properties::Waterlogged::FALSE:
return 8197;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8198;
case Properties::Waterlogged::FALSE:
return 8199;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8200;
case Properties::Waterlogged::FALSE:
return 8201;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8202;
case Properties::Waterlogged::FALSE:
return 8203;
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
return 8204;
case Properties::Waterlogged::FALSE:
return 8205;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8206;
case Properties::Waterlogged::FALSE:
return 8207;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8208;
case Properties::Waterlogged::FALSE:
return 8209;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8210;
case Properties::Waterlogged::FALSE:
return 8211;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8212;
case Properties::Waterlogged::FALSE:
return 8213;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8214;
case Properties::Waterlogged::FALSE:
return 8215;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8216;
case Properties::Waterlogged::FALSE:
return 8217;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8218;
case Properties::Waterlogged::FALSE:
return 8219;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8220;
case Properties::Waterlogged::FALSE:
return 8221;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8222;
case Properties::Waterlogged::FALSE:
return 8223;
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
return 8224;
case Properties::Waterlogged::FALSE:
return 8225;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8226;
case Properties::Waterlogged::FALSE:
return 8227;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8228;
case Properties::Waterlogged::FALSE:
return 8229;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8230;
case Properties::Waterlogged::FALSE:
return 8231;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8232;
case Properties::Waterlogged::FALSE:
return 8233;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8234;
case Properties::Waterlogged::FALSE:
return 8235;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8236;
case Properties::Waterlogged::FALSE:
return 8237;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8238;
case Properties::Waterlogged::FALSE:
return 8239;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8240;
case Properties::Waterlogged::FALSE:
return 8241;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 8242;
case Properties::Waterlogged::FALSE:
return 8243;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4804;
case Properties::Waterlogged::FALSE:
return 4805;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4806;
case Properties::Waterlogged::FALSE:
return 4807;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4808;
case Properties::Waterlogged::FALSE:
return 4809;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4810;
case Properties::Waterlogged::FALSE:
return 4811;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4812;
case Properties::Waterlogged::FALSE:
return 4813;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4814;
case Properties::Waterlogged::FALSE:
return 4815;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4816;
case Properties::Waterlogged::FALSE:
return 4817;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4818;
case Properties::Waterlogged::FALSE:
return 4819;
}
}
}
}
case Properties::Facing::SOUTH:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4820;
case Properties::Waterlogged::FALSE:
return 4821;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4822;
case Properties::Waterlogged::FALSE:
return 4823;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4824;
case Properties::Waterlogged::FALSE:
return 4825;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4826;
case Properties::Waterlogged::FALSE:
return 4827;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4828;
case Properties::Waterlogged::FALSE:
return 4829;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4830;
case Properties::Waterlogged::FALSE:
return 4831;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4832;
case Properties::Waterlogged::FALSE:
return 4833;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4834;
case Properties::Waterlogged::FALSE:
return 4835;
}
}
}
}
case Properties::Facing::WEST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4836;
case Properties::Waterlogged::FALSE:
return 4837;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4838;
case Properties::Waterlogged::FALSE:
return 4839;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4840;
case Properties::Waterlogged::FALSE:
return 4841;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4842;
case Properties::Waterlogged::FALSE:
return 4843;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4844;
case Properties::Waterlogged::FALSE:
return 4845;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4846;
case Properties::Waterlogged::FALSE:
return 4847;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4848;
case Properties::Waterlogged::FALSE:
return 4849;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4850;
case Properties::Waterlogged::FALSE:
return 4851;
}
}
}
}
case Properties::Facing::EAST:
switch (half) {
case Properties::Half::TOP:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4852;
case Properties::Waterlogged::FALSE:
return 4853;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4854;
case Properties::Waterlogged::FALSE:
return 4855;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4856;
case Properties::Waterlogged::FALSE:
return 4857;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4858;
case Properties::Waterlogged::FALSE:
return 4859;
}
}
}
case Properties::Half::BOTTOM:
switch (open) {
case Properties::Open::TRUE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4860;
case Properties::Waterlogged::FALSE:
return 4861;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4862;
case Properties::Waterlogged::FALSE:
return 4863;
}
}
case Properties::Open::FALSE:
switch (powered) {
case Properties::Powered::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4864;
case Properties::Waterlogged::FALSE:
return 4865;
}
case Properties::Powered::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4866;
case Properties::Waterlogged::FALSE:
return 4867;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4080;
case Properties::Waterlogged::FALSE:
return 4081;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4082;
case Properties::Waterlogged::FALSE:
return 4083;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4084;
case Properties::Waterlogged::FALSE:
return 4085;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 4086;
case Properties::Waterlogged::FALSE:
return 4087;
}
}
return 0;
}
}

namespace MangroveWood {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 182;
case Properties::Axis::Y:
return 183;
case Properties::Axis::Z:
return 184;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18645;
case Properties::Waterlogged::FALSE:
return 18646;
}
case Properties::Facing::EAST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18647;
case Properties::Waterlogged::FALSE:
return 18648;
}
case Properties::Facing::SOUTH:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18649;
case Properties::Waterlogged::FALSE:
return 18650;
}
case Properties::Facing::WEST:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18651;
case Properties::Waterlogged::FALSE:
return 18652;
}
case Properties::Facing::UP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18653;
case Properties::Waterlogged::FALSE:
return 18654;
}
case Properties::Facing::DOWN:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 18655;
case Properties::Waterlogged::FALSE:
return 18656;
}
}
return 0;
}
}

namespace Melon {
constexpr Block toProtocol() {
return 5142;
return 0;
}
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
constexpr Block toProtocol(Properties::Age age) {
switch (age) {
case Properties::Age::ZERO:
return 5159;
case Properties::Age::ONE:
return 5160;
case Properties::Age::TWO:
return 5161;
case Properties::Age::THREE:
return 5162;
case Properties::Age::FOUR:
return 5163;
case Properties::Age::FIVE:
return 5164;
case Properties::Age::SIX:
return 5165;
case Properties::Age::SEVEN:
return 5166;
}
return 0;
}
}

namespace MossBlock {
constexpr Block toProtocol() {
return 19717;
return 0;
}
}

namespace MossCarpet {
constexpr Block toProtocol() {
return 19716;
return 0;
}
}

namespace MossyCobblestone {
constexpr Block toProtocol() {
return 1687;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11694;
case Properties::Waterlogged::FALSE:
return 11695;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11696;
case Properties::Waterlogged::FALSE:
return 11697;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11698;
case Properties::Waterlogged::FALSE:
return 11699;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10870;
case Properties::Waterlogged::FALSE:
return 10871;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10872;
case Properties::Waterlogged::FALSE:
return 10873;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10874;
case Properties::Waterlogged::FALSE:
return 10875;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10876;
case Properties::Waterlogged::FALSE:
return 10877;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10878;
case Properties::Waterlogged::FALSE:
return 10879;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10880;
case Properties::Waterlogged::FALSE:
return 10881;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10882;
case Properties::Waterlogged::FALSE:
return 10883;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10884;
case Properties::Waterlogged::FALSE:
return 10885;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10886;
case Properties::Waterlogged::FALSE:
return 10887;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10888;
case Properties::Waterlogged::FALSE:
return 10889;
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
return 10890;
case Properties::Waterlogged::FALSE:
return 10891;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10892;
case Properties::Waterlogged::FALSE:
return 10893;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10894;
case Properties::Waterlogged::FALSE:
return 10895;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10896;
case Properties::Waterlogged::FALSE:
return 10897;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10898;
case Properties::Waterlogged::FALSE:
return 10899;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10900;
case Properties::Waterlogged::FALSE:
return 10901;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10902;
case Properties::Waterlogged::FALSE:
return 10903;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10904;
case Properties::Waterlogged::FALSE:
return 10905;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10906;
case Properties::Waterlogged::FALSE:
return 10907;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10908;
case Properties::Waterlogged::FALSE:
return 10909;
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
return 10910;
case Properties::Waterlogged::FALSE:
return 10911;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10912;
case Properties::Waterlogged::FALSE:
return 10913;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10914;
case Properties::Waterlogged::FALSE:
return 10915;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10916;
case Properties::Waterlogged::FALSE:
return 10917;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10918;
case Properties::Waterlogged::FALSE:
return 10919;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10920;
case Properties::Waterlogged::FALSE:
return 10921;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10922;
case Properties::Waterlogged::FALSE:
return 10923;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10924;
case Properties::Waterlogged::FALSE:
return 10925;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10926;
case Properties::Waterlogged::FALSE:
return 10927;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10928;
case Properties::Waterlogged::FALSE:
return 10929;
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
return 10930;
case Properties::Waterlogged::FALSE:
return 10931;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10932;
case Properties::Waterlogged::FALSE:
return 10933;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10934;
case Properties::Waterlogged::FALSE:
return 10935;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10936;
case Properties::Waterlogged::FALSE:
return 10937;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10938;
case Properties::Waterlogged::FALSE:
return 10939;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10940;
case Properties::Waterlogged::FALSE:
return 10941;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10942;
case Properties::Waterlogged::FALSE:
return 10943;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10944;
case Properties::Waterlogged::FALSE:
return 10945;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10946;
case Properties::Waterlogged::FALSE:
return 10947;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10948;
case Properties::Waterlogged::FALSE:
return 10949;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6573;
case Properties::West::LOW:
return 6574;
case Properties::West::TALL:
return 6575;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6576;
case Properties::West::LOW:
return 6577;
case Properties::West::TALL:
return 6578;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6579;
case Properties::West::LOW:
return 6580;
case Properties::West::TALL:
return 6581;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6582;
case Properties::West::LOW:
return 6583;
case Properties::West::TALL:
return 6584;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6585;
case Properties::West::LOW:
return 6586;
case Properties::West::TALL:
return 6587;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6588;
case Properties::West::LOW:
return 6589;
case Properties::West::TALL:
return 6590;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6591;
case Properties::West::LOW:
return 6592;
case Properties::West::TALL:
return 6593;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6594;
case Properties::West::LOW:
return 6595;
case Properties::West::TALL:
return 6596;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6597;
case Properties::West::LOW:
return 6598;
case Properties::West::TALL:
return 6599;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6600;
case Properties::West::LOW:
return 6601;
case Properties::West::TALL:
return 6602;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6603;
case Properties::West::LOW:
return 6604;
case Properties::West::TALL:
return 6605;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6606;
case Properties::West::LOW:
return 6607;
case Properties::West::TALL:
return 6608;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6609;
case Properties::West::LOW:
return 6610;
case Properties::West::TALL:
return 6611;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6612;
case Properties::West::LOW:
return 6613;
case Properties::West::TALL:
return 6614;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6615;
case Properties::West::LOW:
return 6616;
case Properties::West::TALL:
return 6617;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6618;
case Properties::West::LOW:
return 6619;
case Properties::West::TALL:
return 6620;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6621;
case Properties::West::LOW:
return 6622;
case Properties::West::TALL:
return 6623;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6624;
case Properties::West::LOW:
return 6625;
case Properties::West::TALL:
return 6626;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6627;
case Properties::West::LOW:
return 6628;
case Properties::West::TALL:
return 6629;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6630;
case Properties::West::LOW:
return 6631;
case Properties::West::TALL:
return 6632;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6633;
case Properties::West::LOW:
return 6634;
case Properties::West::TALL:
return 6635;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6636;
case Properties::West::LOW:
return 6637;
case Properties::West::TALL:
return 6638;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6639;
case Properties::West::LOW:
return 6640;
case Properties::West::TALL:
return 6641;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6642;
case Properties::West::LOW:
return 6643;
case Properties::West::TALL:
return 6644;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6645;
case Properties::West::LOW:
return 6646;
case Properties::West::TALL:
return 6647;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6648;
case Properties::West::LOW:
return 6649;
case Properties::West::TALL:
return 6650;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6651;
case Properties::West::LOW:
return 6652;
case Properties::West::TALL:
return 6653;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6654;
case Properties::West::LOW:
return 6655;
case Properties::West::TALL:
return 6656;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6657;
case Properties::West::LOW:
return 6658;
case Properties::West::TALL:
return 6659;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6660;
case Properties::West::LOW:
return 6661;
case Properties::West::TALL:
return 6662;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6663;
case Properties::West::LOW:
return 6664;
case Properties::West::TALL:
return 6665;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6666;
case Properties::West::LOW:
return 6667;
case Properties::West::TALL:
return 6668;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6669;
case Properties::West::LOW:
return 6670;
case Properties::West::TALL:
return 6671;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6672;
case Properties::West::LOW:
return 6673;
case Properties::West::TALL:
return 6674;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6675;
case Properties::West::LOW:
return 6676;
case Properties::West::TALL:
return 6677;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6678;
case Properties::West::LOW:
return 6679;
case Properties::West::TALL:
return 6680;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6681;
case Properties::West::LOW:
return 6682;
case Properties::West::TALL:
return 6683;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6684;
case Properties::West::LOW:
return 6685;
case Properties::West::TALL:
return 6686;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6687;
case Properties::West::LOW:
return 6688;
case Properties::West::TALL:
return 6689;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6690;
case Properties::West::LOW:
return 6691;
case Properties::West::TALL:
return 6692;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6693;
case Properties::West::LOW:
return 6694;
case Properties::West::TALL:
return 6695;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6696;
case Properties::West::LOW:
return 6697;
case Properties::West::TALL:
return 6698;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6699;
case Properties::West::LOW:
return 6700;
case Properties::West::TALL:
return 6701;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6702;
case Properties::West::LOW:
return 6703;
case Properties::West::TALL:
return 6704;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6705;
case Properties::West::LOW:
return 6706;
case Properties::West::TALL:
return 6707;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6708;
case Properties::West::LOW:
return 6709;
case Properties::West::TALL:
return 6710;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6711;
case Properties::West::LOW:
return 6712;
case Properties::West::TALL:
return 6713;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6714;
case Properties::West::LOW:
return 6715;
case Properties::West::TALL:
return 6716;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6717;
case Properties::West::LOW:
return 6718;
case Properties::West::TALL:
return 6719;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6720;
case Properties::West::LOW:
return 6721;
case Properties::West::TALL:
return 6722;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6723;
case Properties::West::LOW:
return 6724;
case Properties::West::TALL:
return 6725;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6726;
case Properties::West::LOW:
return 6727;
case Properties::West::TALL:
return 6728;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6729;
case Properties::West::LOW:
return 6730;
case Properties::West::TALL:
return 6731;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6732;
case Properties::West::LOW:
return 6733;
case Properties::West::TALL:
return 6734;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6735;
case Properties::West::LOW:
return 6736;
case Properties::West::TALL:
return 6737;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6738;
case Properties::West::LOW:
return 6739;
case Properties::West::TALL:
return 6740;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6741;
case Properties::West::LOW:
return 6742;
case Properties::West::TALL:
return 6743;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6744;
case Properties::West::LOW:
return 6745;
case Properties::West::TALL:
return 6746;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6747;
case Properties::West::LOW:
return 6748;
case Properties::West::TALL:
return 6749;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6750;
case Properties::West::LOW:
return 6751;
case Properties::West::TALL:
return 6752;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6753;
case Properties::West::LOW:
return 6754;
case Properties::West::TALL:
return 6755;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6756;
case Properties::West::LOW:
return 6757;
case Properties::West::TALL:
return 6758;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6759;
case Properties::West::LOW:
return 6760;
case Properties::West::TALL:
return 6761;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6762;
case Properties::West::LOW:
return 6763;
case Properties::West::TALL:
return 6764;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6765;
case Properties::West::LOW:
return 6766;
case Properties::West::TALL:
return 6767;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6768;
case Properties::West::LOW:
return 6769;
case Properties::West::TALL:
return 6770;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6771;
case Properties::West::LOW:
return 6772;
case Properties::West::TALL:
return 6773;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6774;
case Properties::West::LOW:
return 6775;
case Properties::West::TALL:
return 6776;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6777;
case Properties::West::LOW:
return 6778;
case Properties::West::TALL:
return 6779;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6780;
case Properties::West::LOW:
return 6781;
case Properties::West::TALL:
return 6782;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6783;
case Properties::West::LOW:
return 6784;
case Properties::West::TALL:
return 6785;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6786;
case Properties::West::LOW:
return 6787;
case Properties::West::TALL:
return 6788;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6789;
case Properties::West::LOW:
return 6790;
case Properties::West::TALL:
return 6791;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6792;
case Properties::West::LOW:
return 6793;
case Properties::West::TALL:
return 6794;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6795;
case Properties::West::LOW:
return 6796;
case Properties::West::TALL:
return 6797;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6798;
case Properties::West::LOW:
return 6799;
case Properties::West::TALL:
return 6800;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6801;
case Properties::West::LOW:
return 6802;
case Properties::West::TALL:
return 6803;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6804;
case Properties::West::LOW:
return 6805;
case Properties::West::TALL:
return 6806;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6807;
case Properties::West::LOW:
return 6808;
case Properties::West::TALL:
return 6809;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6810;
case Properties::West::LOW:
return 6811;
case Properties::West::TALL:
return 6812;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6813;
case Properties::West::LOW:
return 6814;
case Properties::West::TALL:
return 6815;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6816;
case Properties::West::LOW:
return 6817;
case Properties::West::TALL:
return 6818;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6819;
case Properties::West::LOW:
return 6820;
case Properties::West::TALL:
return 6821;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6822;
case Properties::West::LOW:
return 6823;
case Properties::West::TALL:
return 6824;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6825;
case Properties::West::LOW:
return 6826;
case Properties::West::TALL:
return 6827;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6828;
case Properties::West::LOW:
return 6829;
case Properties::West::TALL:
return 6830;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6831;
case Properties::West::LOW:
return 6832;
case Properties::West::TALL:
return 6833;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6834;
case Properties::West::LOW:
return 6835;
case Properties::West::TALL:
return 6836;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6837;
case Properties::West::LOW:
return 6838;
case Properties::West::TALL:
return 6839;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6840;
case Properties::West::LOW:
return 6841;
case Properties::West::TALL:
return 6842;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6843;
case Properties::West::LOW:
return 6844;
case Properties::West::TALL:
return 6845;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6846;
case Properties::West::LOW:
return 6847;
case Properties::West::TALL:
return 6848;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6849;
case Properties::West::LOW:
return 6850;
case Properties::West::TALL:
return 6851;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6852;
case Properties::West::LOW:
return 6853;
case Properties::West::TALL:
return 6854;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6855;
case Properties::West::LOW:
return 6856;
case Properties::West::TALL:
return 6857;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6858;
case Properties::West::LOW:
return 6859;
case Properties::West::TALL:
return 6860;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6861;
case Properties::West::LOW:
return 6862;
case Properties::West::TALL:
return 6863;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6864;
case Properties::West::LOW:
return 6865;
case Properties::West::TALL:
return 6866;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6867;
case Properties::West::LOW:
return 6868;
case Properties::West::TALL:
return 6869;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6870;
case Properties::West::LOW:
return 6871;
case Properties::West::TALL:
return 6872;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6873;
case Properties::West::LOW:
return 6874;
case Properties::West::TALL:
return 6875;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6876;
case Properties::West::LOW:
return 6877;
case Properties::West::TALL:
return 6878;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6879;
case Properties::West::LOW:
return 6880;
case Properties::West::TALL:
return 6881;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6882;
case Properties::West::LOW:
return 6883;
case Properties::West::TALL:
return 6884;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6885;
case Properties::West::LOW:
return 6886;
case Properties::West::TALL:
return 6887;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6888;
case Properties::West::LOW:
return 6889;
case Properties::West::TALL:
return 6890;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 6891;
case Properties::West::LOW:
return 6892;
case Properties::West::TALL:
return 6893;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 6894;
case Properties::West::LOW:
return 6895;
case Properties::West::TALL:
return 6896;
}
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11682;
case Properties::Waterlogged::FALSE:
return 11683;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11684;
case Properties::Waterlogged::FALSE:
return 11685;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 11686;
case Properties::Waterlogged::FALSE:
return 11687;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10710;
case Properties::Waterlogged::FALSE:
return 10711;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10712;
case Properties::Waterlogged::FALSE:
return 10713;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10714;
case Properties::Waterlogged::FALSE:
return 10715;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10716;
case Properties::Waterlogged::FALSE:
return 10717;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10718;
case Properties::Waterlogged::FALSE:
return 10719;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10720;
case Properties::Waterlogged::FALSE:
return 10721;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10722;
case Properties::Waterlogged::FALSE:
return 10723;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10724;
case Properties::Waterlogged::FALSE:
return 10725;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10726;
case Properties::Waterlogged::FALSE:
return 10727;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10728;
case Properties::Waterlogged::FALSE:
return 10729;
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
return 10730;
case Properties::Waterlogged::FALSE:
return 10731;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10732;
case Properties::Waterlogged::FALSE:
return 10733;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10734;
case Properties::Waterlogged::FALSE:
return 10735;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10736;
case Properties::Waterlogged::FALSE:
return 10737;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10738;
case Properties::Waterlogged::FALSE:
return 10739;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10740;
case Properties::Waterlogged::FALSE:
return 10741;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10742;
case Properties::Waterlogged::FALSE:
return 10743;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10744;
case Properties::Waterlogged::FALSE:
return 10745;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10746;
case Properties::Waterlogged::FALSE:
return 10747;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10748;
case Properties::Waterlogged::FALSE:
return 10749;
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
return 10750;
case Properties::Waterlogged::FALSE:
return 10751;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10752;
case Properties::Waterlogged::FALSE:
return 10753;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10754;
case Properties::Waterlogged::FALSE:
return 10755;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10756;
case Properties::Waterlogged::FALSE:
return 10757;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10758;
case Properties::Waterlogged::FALSE:
return 10759;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10760;
case Properties::Waterlogged::FALSE:
return 10761;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10762;
case Properties::Waterlogged::FALSE:
return 10763;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10764;
case Properties::Waterlogged::FALSE:
return 10765;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10766;
case Properties::Waterlogged::FALSE:
return 10767;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10768;
case Properties::Waterlogged::FALSE:
return 10769;
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
return 10770;
case Properties::Waterlogged::FALSE:
return 10771;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10772;
case Properties::Waterlogged::FALSE:
return 10773;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10774;
case Properties::Waterlogged::FALSE:
return 10775;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10776;
case Properties::Waterlogged::FALSE:
return 10777;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10778;
case Properties::Waterlogged::FALSE:
return 10779;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10780;
case Properties::Waterlogged::FALSE:
return 10781;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10782;
case Properties::Waterlogged::FALSE:
return 10783;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10784;
case Properties::Waterlogged::FALSE:
return 10785;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10786;
case Properties::Waterlogged::FALSE:
return 10787;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 10788;
case Properties::Waterlogged::FALSE:
return 10789;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12720;
case Properties::West::LOW:
return 12721;
case Properties::West::TALL:
return 12722;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12723;
case Properties::West::LOW:
return 12724;
case Properties::West::TALL:
return 12725;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12726;
case Properties::West::LOW:
return 12727;
case Properties::West::TALL:
return 12728;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12729;
case Properties::West::LOW:
return 12730;
case Properties::West::TALL:
return 12731;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12732;
case Properties::West::LOW:
return 12733;
case Properties::West::TALL:
return 12734;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12735;
case Properties::West::LOW:
return 12736;
case Properties::West::TALL:
return 12737;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12738;
case Properties::West::LOW:
return 12739;
case Properties::West::TALL:
return 12740;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12741;
case Properties::West::LOW:
return 12742;
case Properties::West::TALL:
return 12743;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12744;
case Properties::West::LOW:
return 12745;
case Properties::West::TALL:
return 12746;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12747;
case Properties::West::LOW:
return 12748;
case Properties::West::TALL:
return 12749;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12750;
case Properties::West::LOW:
return 12751;
case Properties::West::TALL:
return 12752;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12753;
case Properties::West::LOW:
return 12754;
case Properties::West::TALL:
return 12755;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12756;
case Properties::West::LOW:
return 12757;
case Properties::West::TALL:
return 12758;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12759;
case Properties::West::LOW:
return 12760;
case Properties::West::TALL:
return 12761;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12762;
case Properties::West::LOW:
return 12763;
case Properties::West::TALL:
return 12764;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12765;
case Properties::West::LOW:
return 12766;
case Properties::West::TALL:
return 12767;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12768;
case Properties::West::LOW:
return 12769;
case Properties::West::TALL:
return 12770;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12771;
case Properties::West::LOW:
return 12772;
case Properties::West::TALL:
return 12773;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12774;
case Properties::West::LOW:
return 12775;
case Properties::West::TALL:
return 12776;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12777;
case Properties::West::LOW:
return 12778;
case Properties::West::TALL:
return 12779;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12780;
case Properties::West::LOW:
return 12781;
case Properties::West::TALL:
return 12782;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12783;
case Properties::West::LOW:
return 12784;
case Properties::West::TALL:
return 12785;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12786;
case Properties::West::LOW:
return 12787;
case Properties::West::TALL:
return 12788;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12789;
case Properties::West::LOW:
return 12790;
case Properties::West::TALL:
return 12791;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12792;
case Properties::West::LOW:
return 12793;
case Properties::West::TALL:
return 12794;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12795;
case Properties::West::LOW:
return 12796;
case Properties::West::TALL:
return 12797;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12798;
case Properties::West::LOW:
return 12799;
case Properties::West::TALL:
return 12800;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12801;
case Properties::West::LOW:
return 12802;
case Properties::West::TALL:
return 12803;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12804;
case Properties::West::LOW:
return 12805;
case Properties::West::TALL:
return 12806;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12807;
case Properties::West::LOW:
return 12808;
case Properties::West::TALL:
return 12809;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12810;
case Properties::West::LOW:
return 12811;
case Properties::West::TALL:
return 12812;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12813;
case Properties::West::LOW:
return 12814;
case Properties::West::TALL:
return 12815;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12816;
case Properties::West::LOW:
return 12817;
case Properties::West::TALL:
return 12818;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12819;
case Properties::West::LOW:
return 12820;
case Properties::West::TALL:
return 12821;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12822;
case Properties::West::LOW:
return 12823;
case Properties::West::TALL:
return 12824;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12825;
case Properties::West::LOW:
return 12826;
case Properties::West::TALL:
return 12827;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12828;
case Properties::West::LOW:
return 12829;
case Properties::West::TALL:
return 12830;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12831;
case Properties::West::LOW:
return 12832;
case Properties::West::TALL:
return 12833;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12834;
case Properties::West::LOW:
return 12835;
case Properties::West::TALL:
return 12836;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12837;
case Properties::West::LOW:
return 12838;
case Properties::West::TALL:
return 12839;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12840;
case Properties::West::LOW:
return 12841;
case Properties::West::TALL:
return 12842;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12843;
case Properties::West::LOW:
return 12844;
case Properties::West::TALL:
return 12845;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12846;
case Properties::West::LOW:
return 12847;
case Properties::West::TALL:
return 12848;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12849;
case Properties::West::LOW:
return 12850;
case Properties::West::TALL:
return 12851;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12852;
case Properties::West::LOW:
return 12853;
case Properties::West::TALL:
return 12854;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12855;
case Properties::West::LOW:
return 12856;
case Properties::West::TALL:
return 12857;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12858;
case Properties::West::LOW:
return 12859;
case Properties::West::TALL:
return 12860;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12861;
case Properties::West::LOW:
return 12862;
case Properties::West::TALL:
return 12863;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12864;
case Properties::West::LOW:
return 12865;
case Properties::West::TALL:
return 12866;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12867;
case Properties::West::LOW:
return 12868;
case Properties::West::TALL:
return 12869;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12870;
case Properties::West::LOW:
return 12871;
case Properties::West::TALL:
return 12872;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12873;
case Properties::West::LOW:
return 12874;
case Properties::West::TALL:
return 12875;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12876;
case Properties::West::LOW:
return 12877;
case Properties::West::TALL:
return 12878;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12879;
case Properties::West::LOW:
return 12880;
case Properties::West::TALL:
return 12881;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12882;
case Properties::West::LOW:
return 12883;
case Properties::West::TALL:
return 12884;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12885;
case Properties::West::LOW:
return 12886;
case Properties::West::TALL:
return 12887;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12888;
case Properties::West::LOW:
return 12889;
case Properties::West::TALL:
return 12890;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12891;
case Properties::West::LOW:
return 12892;
case Properties::West::TALL:
return 12893;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12894;
case Properties::West::LOW:
return 12895;
case Properties::West::TALL:
return 12896;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12897;
case Properties::West::LOW:
return 12898;
case Properties::West::TALL:
return 12899;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12900;
case Properties::West::LOW:
return 12901;
case Properties::West::TALL:
return 12902;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12903;
case Properties::West::LOW:
return 12904;
case Properties::West::TALL:
return 12905;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12906;
case Properties::West::LOW:
return 12907;
case Properties::West::TALL:
return 12908;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12909;
case Properties::West::LOW:
return 12910;
case Properties::West::TALL:
return 12911;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12912;
case Properties::West::LOW:
return 12913;
case Properties::West::TALL:
return 12914;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12915;
case Properties::West::LOW:
return 12916;
case Properties::West::TALL:
return 12917;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12918;
case Properties::West::LOW:
return 12919;
case Properties::West::TALL:
return 12920;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12921;
case Properties::West::LOW:
return 12922;
case Properties::West::TALL:
return 12923;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12924;
case Properties::West::LOW:
return 12925;
case Properties::West::TALL:
return 12926;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12927;
case Properties::West::LOW:
return 12928;
case Properties::West::TALL:
return 12929;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12930;
case Properties::West::LOW:
return 12931;
case Properties::West::TALL:
return 12932;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12933;
case Properties::West::LOW:
return 12934;
case Properties::West::TALL:
return 12935;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12936;
case Properties::West::LOW:
return 12937;
case Properties::West::TALL:
return 12938;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12939;
case Properties::West::LOW:
return 12940;
case Properties::West::TALL:
return 12941;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12942;
case Properties::West::LOW:
return 12943;
case Properties::West::TALL:
return 12944;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12945;
case Properties::West::LOW:
return 12946;
case Properties::West::TALL:
return 12947;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12948;
case Properties::West::LOW:
return 12949;
case Properties::West::TALL:
return 12950;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12951;
case Properties::West::LOW:
return 12952;
case Properties::West::TALL:
return 12953;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12954;
case Properties::West::LOW:
return 12955;
case Properties::West::TALL:
return 12956;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12957;
case Properties::West::LOW:
return 12958;
case Properties::West::TALL:
return 12959;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12960;
case Properties::West::LOW:
return 12961;
case Properties::West::TALL:
return 12962;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12963;
case Properties::West::LOW:
return 12964;
case Properties::West::TALL:
return 12965;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12966;
case Properties::West::LOW:
return 12967;
case Properties::West::TALL:
return 12968;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12969;
case Properties::West::LOW:
return 12970;
case Properties::West::TALL:
return 12971;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12972;
case Properties::West::LOW:
return 12973;
case Properties::West::TALL:
return 12974;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12975;
case Properties::West::LOW:
return 12976;
case Properties::West::TALL:
return 12977;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12978;
case Properties::West::LOW:
return 12979;
case Properties::West::TALL:
return 12980;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12981;
case Properties::West::LOW:
return 12982;
case Properties::West::TALL:
return 12983;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12984;
case Properties::West::LOW:
return 12985;
case Properties::West::TALL:
return 12986;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12987;
case Properties::West::LOW:
return 12988;
case Properties::West::TALL:
return 12989;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12990;
case Properties::West::LOW:
return 12991;
case Properties::West::TALL:
return 12992;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12993;
case Properties::West::LOW:
return 12994;
case Properties::West::TALL:
return 12995;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 12996;
case Properties::West::LOW:
return 12997;
case Properties::West::TALL:
return 12998;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 12999;
case Properties::West::LOW:
return 13000;
case Properties::West::TALL:
return 13001;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13002;
case Properties::West::LOW:
return 13003;
case Properties::West::TALL:
return 13004;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13005;
case Properties::West::LOW:
return 13006;
case Properties::West::TALL:
return 13007;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13008;
case Properties::West::LOW:
return 13009;
case Properties::West::TALL:
return 13010;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13011;
case Properties::West::LOW:
return 13012;
case Properties::West::TALL:
return 13013;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13014;
case Properties::West::LOW:
return 13015;
case Properties::West::TALL:
return 13016;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13017;
case Properties::West::LOW:
return 13018;
case Properties::West::TALL:
return 13019;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13020;
case Properties::West::LOW:
return 13021;
case Properties::West::TALL:
return 13022;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13023;
case Properties::West::LOW:
return 13024;
case Properties::West::TALL:
return 13025;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13026;
case Properties::West::LOW:
return 13027;
case Properties::West::TALL:
return 13028;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13029;
case Properties::West::LOW:
return 13030;
case Properties::West::TALL:
return 13031;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13032;
case Properties::West::LOW:
return 13033;
case Properties::West::TALL:
return 13034;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13035;
case Properties::West::LOW:
return 13036;
case Properties::West::TALL:
return 13037;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13038;
case Properties::West::LOW:
return 13039;
case Properties::West::TALL:
return 13040;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13041;
case Properties::West::LOW:
return 13042;
case Properties::West::TALL:
return 13043;
}
}
}
}
}
}
return 0;
}
}

namespace MossyStoneBricks {
constexpr Block toProtocol() {
return 4869;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Facing facing) {
switch (type) {
case Properties::Type::NORMAL:
switch (facing) {
case Properties::Facing::NORTH:
return 1654;
case Properties::Facing::EAST:
return 1656;
case Properties::Facing::SOUTH:
return 1658;
case Properties::Facing::WEST:
return 1660;
case Properties::Facing::UP:
return 1662;
case Properties::Facing::DOWN:
return 1664;
}
case Properties::Type::STICKY:
switch (facing) {
case Properties::Facing::NORTH:
return 1655;
case Properties::Facing::EAST:
return 1657;
case Properties::Facing::SOUTH:
return 1659;
case Properties::Facing::WEST:
return 1661;
case Properties::Facing::UP:
return 1663;
case Properties::Facing::DOWN:
return 1665;
}
}
return 0;
}
}

namespace Mud {
constexpr Block toProtocol() {
return 19777;
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9131;
case Properties::Waterlogged::FALSE:
return 9132;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9133;
case Properties::Waterlogged::FALSE:
return 9134;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9135;
case Properties::Waterlogged::FALSE:
return 9136;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5519;
case Properties::Waterlogged::FALSE:
return 5520;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5521;
case Properties::Waterlogged::FALSE:
return 5522;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5523;
case Properties::Waterlogged::FALSE:
return 5524;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5525;
case Properties::Waterlogged::FALSE:
return 5526;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5527;
case Properties::Waterlogged::FALSE:
return 5528;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5529;
case Properties::Waterlogged::FALSE:
return 5530;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5531;
case Properties::Waterlogged::FALSE:
return 5532;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5533;
case Properties::Waterlogged::FALSE:
return 5534;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5535;
case Properties::Waterlogged::FALSE:
return 5536;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5537;
case Properties::Waterlogged::FALSE:
return 5538;
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
return 5539;
case Properties::Waterlogged::FALSE:
return 5540;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5541;
case Properties::Waterlogged::FALSE:
return 5542;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5543;
case Properties::Waterlogged::FALSE:
return 5544;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5545;
case Properties::Waterlogged::FALSE:
return 5546;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5547;
case Properties::Waterlogged::FALSE:
return 5548;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5549;
case Properties::Waterlogged::FALSE:
return 5550;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5551;
case Properties::Waterlogged::FALSE:
return 5552;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5553;
case Properties::Waterlogged::FALSE:
return 5554;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5555;
case Properties::Waterlogged::FALSE:
return 5556;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5557;
case Properties::Waterlogged::FALSE:
return 5558;
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
return 5559;
case Properties::Waterlogged::FALSE:
return 5560;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5561;
case Properties::Waterlogged::FALSE:
return 5562;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5563;
case Properties::Waterlogged::FALSE:
return 5564;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5565;
case Properties::Waterlogged::FALSE:
return 5566;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5567;
case Properties::Waterlogged::FALSE:
return 5568;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5569;
case Properties::Waterlogged::FALSE:
return 5570;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5571;
case Properties::Waterlogged::FALSE:
return 5572;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5573;
case Properties::Waterlogged::FALSE:
return 5574;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5575;
case Properties::Waterlogged::FALSE:
return 5576;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5577;
case Properties::Waterlogged::FALSE:
return 5578;
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
return 5579;
case Properties::Waterlogged::FALSE:
return 5580;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5581;
case Properties::Waterlogged::FALSE:
return 5582;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5583;
case Properties::Waterlogged::FALSE:
return 5584;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5585;
case Properties::Waterlogged::FALSE:
return 5586;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5587;
case Properties::Waterlogged::FALSE:
return 5588;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5589;
case Properties::Waterlogged::FALSE:
return 5590;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5591;
case Properties::Waterlogged::FALSE:
return 5592;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5593;
case Properties::Waterlogged::FALSE:
return 5594;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5595;
case Properties::Waterlogged::FALSE:
return 5596;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5597;
case Properties::Waterlogged::FALSE:
return 5598;
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
switch (east) {
case Properties::East::NONE:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13692;
case Properties::West::LOW:
return 13693;
case Properties::West::TALL:
return 13694;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13695;
case Properties::West::LOW:
return 13696;
case Properties::West::TALL:
return 13697;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13698;
case Properties::West::LOW:
return 13699;
case Properties::West::TALL:
return 13700;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13701;
case Properties::West::LOW:
return 13702;
case Properties::West::TALL:
return 13703;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13704;
case Properties::West::LOW:
return 13705;
case Properties::West::TALL:
return 13706;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13707;
case Properties::West::LOW:
return 13708;
case Properties::West::TALL:
return 13709;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13710;
case Properties::West::LOW:
return 13711;
case Properties::West::TALL:
return 13712;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13713;
case Properties::West::LOW:
return 13714;
case Properties::West::TALL:
return 13715;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13716;
case Properties::West::LOW:
return 13717;
case Properties::West::TALL:
return 13718;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13719;
case Properties::West::LOW:
return 13720;
case Properties::West::TALL:
return 13721;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13722;
case Properties::West::LOW:
return 13723;
case Properties::West::TALL:
return 13724;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13725;
case Properties::West::LOW:
return 13726;
case Properties::West::TALL:
return 13727;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13728;
case Properties::West::LOW:
return 13729;
case Properties::West::TALL:
return 13730;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13731;
case Properties::West::LOW:
return 13732;
case Properties::West::TALL:
return 13733;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13734;
case Properties::West::LOW:
return 13735;
case Properties::West::TALL:
return 13736;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13737;
case Properties::West::LOW:
return 13738;
case Properties::West::TALL:
return 13739;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13740;
case Properties::West::LOW:
return 13741;
case Properties::West::TALL:
return 13742;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13743;
case Properties::West::LOW:
return 13744;
case Properties::West::TALL:
return 13745;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13746;
case Properties::West::LOW:
return 13747;
case Properties::West::TALL:
return 13748;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13749;
case Properties::West::LOW:
return 13750;
case Properties::West::TALL:
return 13751;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13752;
case Properties::West::LOW:
return 13753;
case Properties::West::TALL:
return 13754;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13755;
case Properties::West::LOW:
return 13756;
case Properties::West::TALL:
return 13757;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13758;
case Properties::West::LOW:
return 13759;
case Properties::West::TALL:
return 13760;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13761;
case Properties::West::LOW:
return 13762;
case Properties::West::TALL:
return 13763;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13764;
case Properties::West::LOW:
return 13765;
case Properties::West::TALL:
return 13766;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13767;
case Properties::West::LOW:
return 13768;
case Properties::West::TALL:
return 13769;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13770;
case Properties::West::LOW:
return 13771;
case Properties::West::TALL:
return 13772;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13773;
case Properties::West::LOW:
return 13774;
case Properties::West::TALL:
return 13775;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13776;
case Properties::West::LOW:
return 13777;
case Properties::West::TALL:
return 13778;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13779;
case Properties::West::LOW:
return 13780;
case Properties::West::TALL:
return 13781;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13782;
case Properties::West::LOW:
return 13783;
case Properties::West::TALL:
return 13784;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13785;
case Properties::West::LOW:
return 13786;
case Properties::West::TALL:
return 13787;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13788;
case Properties::West::LOW:
return 13789;
case Properties::West::TALL:
return 13790;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13791;
case Properties::West::LOW:
return 13792;
case Properties::West::TALL:
return 13793;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13794;
case Properties::West::LOW:
return 13795;
case Properties::West::TALL:
return 13796;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13797;
case Properties::West::LOW:
return 13798;
case Properties::West::TALL:
return 13799;
}
}
}
}
}
case Properties::East::LOW:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13800;
case Properties::West::LOW:
return 13801;
case Properties::West::TALL:
return 13802;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13803;
case Properties::West::LOW:
return 13804;
case Properties::West::TALL:
return 13805;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13806;
case Properties::West::LOW:
return 13807;
case Properties::West::TALL:
return 13808;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13809;
case Properties::West::LOW:
return 13810;
case Properties::West::TALL:
return 13811;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13812;
case Properties::West::LOW:
return 13813;
case Properties::West::TALL:
return 13814;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13815;
case Properties::West::LOW:
return 13816;
case Properties::West::TALL:
return 13817;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13818;
case Properties::West::LOW:
return 13819;
case Properties::West::TALL:
return 13820;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13821;
case Properties::West::LOW:
return 13822;
case Properties::West::TALL:
return 13823;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13824;
case Properties::West::LOW:
return 13825;
case Properties::West::TALL:
return 13826;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13827;
case Properties::West::LOW:
return 13828;
case Properties::West::TALL:
return 13829;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13830;
case Properties::West::LOW:
return 13831;
case Properties::West::TALL:
return 13832;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13833;
case Properties::West::LOW:
return 13834;
case Properties::West::TALL:
return 13835;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13836;
case Properties::West::LOW:
return 13837;
case Properties::West::TALL:
return 13838;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13839;
case Properties::West::LOW:
return 13840;
case Properties::West::TALL:
return 13841;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13842;
case Properties::West::LOW:
return 13843;
case Properties::West::TALL:
return 13844;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13845;
case Properties::West::LOW:
return 13846;
case Properties::West::TALL:
return 13847;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13848;
case Properties::West::LOW:
return 13849;
case Properties::West::TALL:
return 13850;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13851;
case Properties::West::LOW:
return 13852;
case Properties::West::TALL:
return 13853;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13854;
case Properties::West::LOW:
return 13855;
case Properties::West::TALL:
return 13856;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13857;
case Properties::West::LOW:
return 13858;
case Properties::West::TALL:
return 13859;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13860;
case Properties::West::LOW:
return 13861;
case Properties::West::TALL:
return 13862;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13863;
case Properties::West::LOW:
return 13864;
case Properties::West::TALL:
return 13865;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13866;
case Properties::West::LOW:
return 13867;
case Properties::West::TALL:
return 13868;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13869;
case Properties::West::LOW:
return 13870;
case Properties::West::TALL:
return 13871;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13872;
case Properties::West::LOW:
return 13873;
case Properties::West::TALL:
return 13874;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13875;
case Properties::West::LOW:
return 13876;
case Properties::West::TALL:
return 13877;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13878;
case Properties::West::LOW:
return 13879;
case Properties::West::TALL:
return 13880;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13881;
case Properties::West::LOW:
return 13882;
case Properties::West::TALL:
return 13883;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13884;
case Properties::West::LOW:
return 13885;
case Properties::West::TALL:
return 13886;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13887;
case Properties::West::LOW:
return 13888;
case Properties::West::TALL:
return 13889;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13890;
case Properties::West::LOW:
return 13891;
case Properties::West::TALL:
return 13892;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13893;
case Properties::West::LOW:
return 13894;
case Properties::West::TALL:
return 13895;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13896;
case Properties::West::LOW:
return 13897;
case Properties::West::TALL:
return 13898;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13899;
case Properties::West::LOW:
return 13900;
case Properties::West::TALL:
return 13901;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13902;
case Properties::West::LOW:
return 13903;
case Properties::West::TALL:
return 13904;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13905;
case Properties::West::LOW:
return 13906;
case Properties::West::TALL:
return 13907;
}
}
}
}
}
case Properties::East::TALL:
switch (north) {
case Properties::North::NONE:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13908;
case Properties::West::LOW:
return 13909;
case Properties::West::TALL:
return 13910;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13911;
case Properties::West::LOW:
return 13912;
case Properties::West::TALL:
return 13913;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13914;
case Properties::West::LOW:
return 13915;
case Properties::West::TALL:
return 13916;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13917;
case Properties::West::LOW:
return 13918;
case Properties::West::TALL:
return 13919;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13920;
case Properties::West::LOW:
return 13921;
case Properties::West::TALL:
return 13922;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13923;
case Properties::West::LOW:
return 13924;
case Properties::West::TALL:
return 13925;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13926;
case Properties::West::LOW:
return 13927;
case Properties::West::TALL:
return 13928;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13929;
case Properties::West::LOW:
return 13930;
case Properties::West::TALL:
return 13931;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13932;
case Properties::West::LOW:
return 13933;
case Properties::West::TALL:
return 13934;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13935;
case Properties::West::LOW:
return 13936;
case Properties::West::TALL:
return 13937;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13938;
case Properties::West::LOW:
return 13939;
case Properties::West::TALL:
return 13940;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13941;
case Properties::West::LOW:
return 13942;
case Properties::West::TALL:
return 13943;
}
}
}
}
case Properties::North::LOW:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13944;
case Properties::West::LOW:
return 13945;
case Properties::West::TALL:
return 13946;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13947;
case Properties::West::LOW:
return 13948;
case Properties::West::TALL:
return 13949;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13950;
case Properties::West::LOW:
return 13951;
case Properties::West::TALL:
return 13952;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13953;
case Properties::West::LOW:
return 13954;
case Properties::West::TALL:
return 13955;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13956;
case Properties::West::LOW:
return 13957;
case Properties::West::TALL:
return 13958;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13959;
case Properties::West::LOW:
return 13960;
case Properties::West::TALL:
return 13961;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13962;
case Properties::West::LOW:
return 13963;
case Properties::West::TALL:
return 13964;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13965;
case Properties::West::LOW:
return 13966;
case Properties::West::TALL:
return 13967;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13968;
case Properties::West::LOW:
return 13969;
case Properties::West::TALL:
return 13970;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13971;
case Properties::West::LOW:
return 13972;
case Properties::West::TALL:
return 13973;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13974;
case Properties::West::LOW:
return 13975;
case Properties::West::TALL:
return 13976;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13977;
case Properties::West::LOW:
return 13978;
case Properties::West::TALL:
return 13979;
}
}
}
}
case Properties::North::TALL:
switch (south) {
case Properties::South::NONE:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13980;
case Properties::West::LOW:
return 13981;
case Properties::West::TALL:
return 13982;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13983;
case Properties::West::LOW:
return 13984;
case Properties::West::TALL:
return 13985;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13986;
case Properties::West::LOW:
return 13987;
case Properties::West::TALL:
return 13988;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13989;
case Properties::West::LOW:
return 13990;
case Properties::West::TALL:
return 13991;
}
}
}
case Properties::South::LOW:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13992;
case Properties::West::LOW:
return 13993;
case Properties::West::TALL:
return 13994;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 13995;
case Properties::West::LOW:
return 13996;
case Properties::West::TALL:
return 13997;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 13998;
case Properties::West::LOW:
return 13999;
case Properties::West::TALL:
return 14000;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14001;
case Properties::West::LOW:
return 14002;
case Properties::West::TALL:
return 14003;
}
}
}
case Properties::South::TALL:
switch (up) {
case Properties::Up::TRUE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14004;
case Properties::West::LOW:
return 14005;
case Properties::West::TALL:
return 14006;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14007;
case Properties::West::LOW:
return 14008;
case Properties::West::TALL:
return 14009;
}
}
case Properties::Up::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::NONE:
return 14010;
case Properties::West::LOW:
return 14011;
case Properties::West::TALL:
return 14012;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::NONE:
return 14013;
case Properties::West::LOW:
return 14014;
case Properties::West::TALL:
return 14015;
}
}
}
}
}
}
return 0;
}
}

namespace MudBricks {
constexpr Block toProtocol() {
return 4873;
return 0;
}
}

namespace MuddyMangroveRoots {
namespace Properties {
enum class Axis {
X,
Y,
Z
};
}
constexpr Block toProtocol(Properties::Axis axis) {
switch (axis) {
case Properties::Axis::X:
return 140;
case Properties::Axis::Y:
return 141;
case Properties::Axis::Z:
return 142;
}
return 0;
}
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
constexpr Block toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
switch (down) {
case Properties::Down::TRUE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5008;
case Properties::West::FALSE:
return 5009;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5010;
case Properties::West::FALSE:
return 5011;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5012;
case Properties::West::FALSE:
return 5013;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5014;
case Properties::West::FALSE:
return 5015;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5016;
case Properties::West::FALSE:
return 5017;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5018;
case Properties::West::FALSE:
return 5019;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5020;
case Properties::West::FALSE:
return 5021;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5022;
case Properties::West::FALSE:
return 5023;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5024;
case Properties::West::FALSE:
return 5025;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5026;
case Properties::West::FALSE:
return 5027;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5028;
case Properties::West::FALSE:
return 5029;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5030;
case Properties::West::FALSE:
return 5031;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5032;
case Properties::West::FALSE:
return 5033;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5034;
case Properties::West::FALSE:
return 5035;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5036;
case Properties::West::FALSE:
return 5037;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5038;
case Properties::West::FALSE:
return 5039;
}
}
}
}
}
case Properties::Down::FALSE:
switch (east) {
case Properties::East::TRUE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5040;
case Properties::West::FALSE:
return 5041;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5042;
case Properties::West::FALSE:
return 5043;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5044;
case Properties::West::FALSE:
return 5045;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5046;
case Properties::West::FALSE:
return 5047;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5048;
case Properties::West::FALSE:
return 5049;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5050;
case Properties::West::FALSE:
return 5051;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5052;
case Properties::West::FALSE:
return 5053;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5054;
case Properties::West::FALSE:
return 5055;
}
}
}
}
case Properties::East::FALSE:
switch (north) {
case Properties::North::TRUE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5056;
case Properties::West::FALSE:
return 5057;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5058;
case Properties::West::FALSE:
return 5059;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5060;
case Properties::West::FALSE:
return 5061;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5062;
case Properties::West::FALSE:
return 5063;
}
}
}
case Properties::North::FALSE:
switch (south) {
case Properties::South::TRUE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5064;
case Properties::West::FALSE:
return 5065;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5066;
case Properties::West::FALSE:
return 5067;
}
}
case Properties::South::FALSE:
switch (up) {
case Properties::Up::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5068;
case Properties::West::FALSE:
return 5069;
}
case Properties::Up::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5070;
case Properties::West::FALSE:
return 5071;
}
}
}
}
}
}
return 0;
}
}

namespace Mycelium {
namespace Properties {
enum class Snowy {
TRUE,
FALSE
};
}
constexpr Block toProtocol(Properties::Snowy snowy) {
switch (snowy) {
case Properties::Snowy::TRUE:
return 5599;
case Properties::Snowy::FALSE:
return 5600;
}
return 0;
}
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
constexpr Block toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
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
return 5603;
case Properties::West::FALSE:
return 5604;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5605;
case Properties::West::FALSE:
return 5606;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5607;
case Properties::West::FALSE:
return 5608;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5609;
case Properties::West::FALSE:
return 5610;
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
return 5611;
case Properties::West::FALSE:
return 5612;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5613;
case Properties::West::FALSE:
return 5614;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5615;
case Properties::West::FALSE:
return 5616;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5617;
case Properties::West::FALSE:
return 5618;
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
return 5619;
case Properties::West::FALSE:
return 5620;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5621;
case Properties::West::FALSE:
return 5622;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5623;
case Properties::West::FALSE:
return 5624;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5625;
case Properties::West::FALSE:
return 5626;
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
return 5627;
case Properties::West::FALSE:
return 5628;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5629;
case Properties::West::FALSE:
return 5630;
}
}
case Properties::South::FALSE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
switch (west) {
case Properties::West::TRUE:
return 5631;
case Properties::West::FALSE:
return 5632;
}
case Properties::Waterlogged::FALSE:
switch (west) {
case Properties::West::TRUE:
return 5633;
case Properties::West::FALSE:
return 5634;
}
}
}
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
switch (type) {
case Properties::Type::TOP:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9137;
case Properties::Waterlogged::FALSE:
return 9138;
}
case Properties::Type::BOTTOM:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9139;
case Properties::Waterlogged::FALSE:
return 9140;
}
case Properties::Type::DOUBLE:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 9141;
case Properties::Waterlogged::FALSE:
return 9142;
}
}
return 0;
}
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
constexpr Block toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
switch (facing) {
case Properties::Facing::NORTH:
switch (half) {
case Properties::Half::TOP:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5635;
case Properties::Waterlogged::FALSE:
return 5636;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5637;
case Properties::Waterlogged::FALSE:
return 5638;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5639;
case Properties::Waterlogged::FALSE:
return 5640;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5641;
case Properties::Waterlogged::FALSE:
return 5642;
}
case Properties::Shape::OUTER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5643;
case Properties::Waterlogged::FALSE:
return 5644;
}
}
case Properties::Half::BOTTOM:
switch (shape) {
case Properties::Shape::STRAIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5645;
case Properties::Waterlogged::FALSE:
return 5646;
}
case Properties::Shape::INNER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5647;
case Properties::Waterlogged::FALSE:
return 5648;
}
case Properties::Shape::INNER_RIGHT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5649;
case Properties::Waterlogged::FALSE:
return 5650;
}
case Properties::Shape::OUTER_LEFT:
switch (waterlogged) {
case Properties::Waterlogged::TRUE:
return 5651;
return 5652;
}
}
}
}
}