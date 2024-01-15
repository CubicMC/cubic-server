#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include "math/Vector3.hpp"
#include <optional>

class BoundingBox {
public:
    constexpr BoundingBox(const Vector3d &position = Vector3d(0, 0, 0), const Vector3f &dimensions = Vector3f(1, 1, 1)):
        _pos(position),
        _dim(dimensions) {};

    bool contains(const Vector3d &point) const;
    bool contains(const BoundingBox &other) const;
    std::optional<BoundingBox> intersects(const BoundingBox &other) const;

    Vector3d getPosition() const;
    Vector3f getDimensions() const;
    void setPosition(const Vector3d pos);
    void setDimensions(const Vector3f dim);

private:
    Vector3d _pos;
    Vector3f _dim;
};

#endif // BOUNDINGBOX_HPP
