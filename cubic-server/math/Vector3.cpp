#include "Vector3.hpp"
#include "types.hpp"

template<>
constexpr Vector3<double>::operator Position() const noexcept
{
    return Position {static_cast<Position::valueType>(this->x), static_cast<Position::valueType>(this->y), static_cast<Position::valueType>(this->z)};
}
