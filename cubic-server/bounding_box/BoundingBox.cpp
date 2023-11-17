#include "BoundingBox.hpp"
#include "math/Vector3.hpp"
#include <optional>

BoundingBox::BoundingBox(float width, float height, float depth):
{
    this->rect.min = Vector3f(-width / 2, -height / 2, -depth / 2);
    this->rect.max = Vector3f(width / 2, height / 2, depth / 2);
    this->rect.center = Vector3f(0, 0, 0);
    this->rect.width = width;
    this->rect.height = height;
    this->rect.depth = depth;
}

BoundingBox::BoundingBox(const Vector3f &dimensions):
    BoundingBox(dimensions.x, dimensions.y, dimensions.z)
{
}

BoundingBox::BoundingBox(const Vector3f &min, const Vector3f &max)
{
    this->rect.min = min;
    this->rect.max = max;
    this->rect.width = max.x - min.x;
    this->rect.height = max.y - min.y;
    this->rect.depth = max.z - min.z;
    this->rect.center = Vector3f(min.x + this->rect.width / 2, min.y + this->rect.height / 2, min.z + this->rect.depth / 2);
}

bool BoundingBox::contains(const Vector3f &point) const
{
    if (point.x < this->rect.min.x || point.y < this->rect.min.y || point.z < this->rect.min.z || point.x > this->rect.max.x || point.y > this->rect.max.y ||
        point.z > this->rect.max.z) {
        return false;
    }
    return true;
}

bool BoundingBox::intersects(const BoundingBox &other) const
{
    if (this->rect.min.x > other.rect.max.x || this->rect.max.x < other.rect.min.x) {
        return false;
    }
    if (this->rect.min.y > other.rect.max.y || this->rect.max.y < other.rect.min.y) {
        return false;
    }
    if (this->rect.min.z > other.rect.max.z || this->rect.max.z < other.rect.min.z) {
        return false;
    }
    return true;
}

std::optional<BoundingBox::Rect> BoundingBox::intersectRect(const BoundingBox &other) const
{
    if (!this->intersects(other)) {
        return std::nullopt;
    }

    float minX = std::max(this->rect.min.x, other.rect.min.x);
    float minY = std::max(this->rect.min.y, other.rect.min.y);
    float minZ = std::max(this->rect.min.z, other.rect.min.z);

    float maxX = std::min(this->rect.max.x, other.rect.max.x);
    float maxY = std::min(this->rect.max.y, other.rect.max.y);
    float maxZ = std::min(this->rect.max.z, other.rect.max.z);

    return Rect {.min = Vector3<float>(minX, minY, minZ), .max = Vector3<float>(maxX, maxY, maxZ), .width = maxX - minX, .height = maxY - minY, .depth = maxZ - minZ};
}

BoundingBox::Rect BoundingBox::getRect() const { return this->rect; }

Vector3<float> BoundingBox::getDimensions() const { return Vector3f(this->rect.width, this->rect.height, this->rect.depth); }

Vector3<float> BoundingBox::getMin() const { return this->rect.min; }

Vector3<float> BoundingBox::getMax() const { return this->rect.max; }

float BoundingBox::getWidth() const { return this->rect.width; }

float BoundingBox::getHeight() const { return this->rect.height; }

float BoundingBox::getDepth() const { return this->rect.depth; }
