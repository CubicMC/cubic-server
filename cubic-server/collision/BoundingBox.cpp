#include "BoundingBox.hpp"
#include "math/Vector3.hpp"
#include <optional>

BoundingBox::BoundingBox(const Vector3d &position, const Vector3f &dimensions):
    _pos(position),
    _dim(dimensions)
{
}

bool BoundingBox::contains(const Vector3d &point) const
{
    return (point.x >= _pos.x && point.x <= _pos.x + _dim.x) && (point.y >= _pos.y && point.y <= _pos.y + _dim.y) && (point.z >= _pos.z && point.z <= _pos.z + _dim.z);
}

bool BoundingBox::contains(const BoundingBox &other) const
{
    return (other._pos.x < _pos.x + _dim.x && other._pos.x + other._dim.x > _pos.x) && (other._pos.y < _pos.y + _dim.y && other._pos.y + other._dim.y > _pos.y) &&
        (other._pos.z < _pos.z + _dim.z && other._pos.z + other._dim.z > _pos.z);
}

std::optional<BoundingBox> BoundingBox::intersects(const BoundingBox &other) const
{
    Vector3d min = Vector3d(std::max(_pos.x, other._pos.x), std::max(_pos.y, other._pos.y), std::max(_pos.z, other._pos.z));
    Vector3d max = Vector3d(
        std::min(_pos.x + _dim.x, other._pos.x + other._dim.x), std::min(_pos.y + _dim.y, other._pos.y + other._dim.y), std::min(_pos.z + _dim.z, other._pos.z + other._dim.z)
    );

    if (min.x <= max.x && min.y <= max.y && min.z <= max.z) {
        return BoundingBox(min, Vector3f(max.x - min.x, max.y - min.y, max.z - min.z));
    }
    return std::nullopt;
}

Vector3d BoundingBox::getPosition() const { return this->_pos; }

Vector3f BoundingBox::getDimensions() const { return this->_dim; }

void BoundingBox::setPosition(const Vector3d pos) { this->_pos = pos; }

void BoundingBox::setDimensions(const Vector3f dim) { this->_dim = dim; }
