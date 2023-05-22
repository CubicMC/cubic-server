#include "types.hpp"

std::ostream &operator<<(std::ostream &os, const Position &pos) { return os << "Position(" << pos.x << ", " << pos.y << ", " << pos.z << ")"; }
std::ostream &operator<<(std::ostream &os, const Position2D &pos) { return os << "Position2D(" << pos.x << ", " << pos.z << ")"; }
std::ostream &operator<<(std::ostream &os, const Rotation &rot) { return os << "Rotation(yaw: " << rot.yaw << ", pitch: " << rot.pitch << ")"; }
