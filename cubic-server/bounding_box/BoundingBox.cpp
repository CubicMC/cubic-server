#include "BoundingBox.hpp"
#include "math/Vector3.hpp"

BoundingBox::BoundingBox(float width, float height, float depth):
    width(width),
    height(height),
    depth(depth)
{
    this->min = Vector3f(-width / 2, -height / 2, -depth / 2);
    this->max = Vector3f(width / 2, height / 2, depth / 2);
    this->center = Vector3f(0, 0, 0);
}

BoundingBox::BoundingBox(const Vector3f &dimensions):
    BoundingBox(dimensions.x, dimensions.y, dimensions.z)
{
}

BoundingBox::BoundingBox(const Vector3f &min, const Vector3f &max):
    min(min),
    max(max)
{
    this->width = max.x - min.x;
    this->height = max.y - min.y;
    this->depth = max.z - min.z;
    this->center = Vector3f(min.x + this->width / 2, min.y + this->height / 2, min.z + this->depth / 2);
}

bool BoundingBox::contains(const Vector3f &point) const
{
    if (point.x < this->min.x || point.y < this->min.y || point.z < this->min.z || point.x > this->max.x || point.y > this->max.y || point.z > this->max.z) {
        return false;
    }
    return true;
}

bool BoundingBox::intersects(const BoundingBox &other) const
{
    if (this->min.x > other.max.x || this->max.x < other.min.x) {
        return false;
    }
    if (this->min.y > other.max.y || this->max.y < other.min.y) {
        return false;
    }
    if (this->min.z > other.max.z || this->max.z < other.min.z) {
        return false;
    }
    return true;
}

Vector3<float> BoundingBox::getCenter() const
{
    return this->center;
}

Vector3<float> BoundingBox::getDimensions() const
{
    return Vector3f(this->width, this->height, this->depth);
}

Vector3<float> BoundingBox::getMin() const
{
    return this->min;
}

Vector3<float> BoundingBox::getMax() const
{
    return this->max;
}

float BoundingBox::getWidth() const
{
    return this->width;
}

float BoundingBox::getHeight() const
{
    return this->height;
}

float BoundingBox::getDepth() const
{
    return this->depth;
}