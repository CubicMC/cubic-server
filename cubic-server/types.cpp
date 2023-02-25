#include "types.hpp"

std::ostream &Position::operator<<(std::ostream &os) const
{
    return os << "Position(" << x << ", " << y << ", " << z << ")";
}
