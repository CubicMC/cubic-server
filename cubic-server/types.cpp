#include "types.hpp"

std::ostream &operator<<(std::ostream &os, const Position &pos)
{
    return os << "Position(" << pos.x << ", " << pos.y << ", " << pos.z << ")";
}

std::ostream &operator<<(std::ostream &os, const Position2D &pos)
{
    return os << "Position2D(" << pos.x << ", " << pos.z << ")";
}

std::ostream &operator<<(std::ostream &os, const Rotation &rot)
{
    return os << "Rotation(yaw: " << rot.yaw << ", pitch: " << rot.pitch << ")";
}

std::string u128::toString() const {
    std::stringstream uuidsstr;
    std::string uuidstr;

    uuidsstr << std::setfill('0') << std::setw(16) << std::hex << this->most << std::setfill('0') << std::setw(16) << this->least;
    uuidstr = uuidsstr.str();
    uuidstr.insert(8, "-");
    uuidstr.insert(13, "-");
    uuidstr.insert(18, "-");
    uuidstr.insert(23, "-");
    return uuidstr;
}