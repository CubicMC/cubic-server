#include "CollisionSystem.hpp"

#include "Server.hpp"
#include "entities/Entity.hpp"
#include "math/Vector3.hpp"
#include "types.hpp"
#include "Dimension.hpp"

#include <optional>
#include <vector>

std::vector<BoundingBox> CollisionSystem::getCollisions(const Entity &entity) const {
    std::vector<BoundingBox> entitiesCollisions = getCollisionsWithEntities(entity);
    std::vector<BoundingBox> blocksCollisions = getCollisionsWithBlocks(entity);

    entitiesCollisions.insert(entitiesCollisions.end(), blocksCollisions.begin(), blocksCollisions.end());
    return entitiesCollisions;
}

std::vector<BoundingBox> CollisionSystem::getCollisionsWithEntities(const Entity &entity) const {
    const BoundingBox &bb = entity.getBoundingBox();
    std::vector<BoundingBox> result;

    for (auto &ent : _dim->getEntities()) {
        if (ent->getId() == entity.getId()) {
            continue;
        }
        std::optional<BoundingBox> collision = ent->getBoundingBox().intersects(bb);
        if (collision.has_value()) {
            result.push_back(collision.value());
        }
    }

    return result;
}

std::vector<BoundingBox> CollisionSystem::getCollisionsWithBlocks(const Entity &entity) const {
    const BoundingBox &bb = entity.getBoundingBox();
    std::vector<BoundingBox> result;
    Vector3d min = bb.getPosition();
    Vector3d max = min + Vector3d({bb.getDimensions().x, bb.getDimensions().y, bb.getDimensions().z});

    for (double x = min.x; x < max.x; x++) {
        for (double y = min.y; y < max.y; y++) {
            for (double z = min.z; z < max.z; z++) {
                BlockId block = _dim->getBlock(Position(x, y, z));
                if (SHAPE_CONVERTER.fromBlockIdToShape(block) == "empty") {
                    continue;
                }
                std::optional <BoundingBox> collision = BoundingBox({x, y, z}, {1, 1, 1}).intersects(bb);
                if (collision.has_value()) result.push_back(collision.value());
            }
        }
    }

    return result;
}

bool CollisionSystem::doesCollide(const Entity &entity) const {
    return !getCollisions(entity).empty();
}

bool CollisionSystem::doesCollideWithBlocks(const Entity &entity) const {
    return !getCollisionsWithBlocks(entity).empty();
}

bool CollisionSystem::doesCollideWithEntities(const Entity &entity) const {
    return !getCollisionsWithEntities(entity).empty();
}