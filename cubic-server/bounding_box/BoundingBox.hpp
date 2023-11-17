#include "math/Vector3.hpp"

class BoundingBox {
public:
    typedef Vector3<float> Vector3f;
public:
    BoundingBox(float width, float height, float depth);
    BoundingBox(const Vector3f& dimensions);
    BoundingBox(const Vector3f& min, const Vector3f& max);

    bool contains(const Vector3f& point) const;
    bool intersects(const BoundingBox& other) const;
    Vector3f getCenter() const;
    Vector3f getDimensions() const;
    Vector3f getMin() const;
    Vector3f getMax() const;
    float getWidth() const;
    float getHeight() const;
    float getDepth() const;

private:
    Vector3f center;
    Vector3f min;
    Vector3f max;
    float width;
    float height;
    float depth;
};