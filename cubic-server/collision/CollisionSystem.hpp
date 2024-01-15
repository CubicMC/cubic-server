#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

#include "collision/BoundingBox.hpp"
#include "protocol/ClientPackets.hpp"

class Dimension;

class CollisionSystem {
public:
    CollisionSystem() {};
    CollisionSystem(std::shared_ptr<Dimension> dim):
        _dim(dim) {};
    ~CollisionSystem() = default;

    void setDimension(std::shared_ptr<Dimension> dim) { _dim = dim; }
    std::shared_ptr<Dimension> getDimension() { return _dim; }

    std::vector<BoundingBox> getCollisions(const Entity &entity) const;
    std::vector<BoundingBox> getCollisionsWithBlocks(const Entity &entity) const;
    std::vector<BoundingBox> getCollisionsWithEntities(const Entity &entity) const;
    bool doesCollide(const Entity &entity) const;
    bool doesCollideWithBlocks(const Entity &entity) const;
    bool doesCollideWithEntities(const Entity &entity) const;

private:
    std::shared_ptr<Dimension> _dim;
};

#endif // COLLISIONSYSTEM_HPP
