#ifndef CUBICSERVER_ENTITY_HPP
#define CUBICSERVER_ENTITY_HPP

#include "math/Vector2.hpp"
#include "math/Vector3.hpp"
#include "options.hpp"
#include "protocol/ClientPackets.hpp"
#include "types.hpp"
#include <memory>

class World;
class WorldGroup;
class Dimension;

class Entity : public std::enable_shared_from_this<Entity> {
    enum class Pose {
        Standing,
        FallFlying,
        Sleeping,
        Swimming,
        SpinAttack,
        Sneaking,
        LongJumping,
        Dying,
        Croaking,
        UsingTongue,
        Roaring,
        Sniffing,
        Emerging,
        Digging
    };

public:
    // Subject to change
    // clang-format off
    Entity(std::shared_ptr<Dimension> dim,
        protocol::SpawnEntity::EntityType type,
        bool onFire = false,
        bool crouching = false,
        bool sprinting = false,
        bool swimming = false,
        bool invisible = false,
        bool glowing = false,
        bool flyingWithElytra = false,
        int16_t airTicks = 300,
        std::string customName = "",
        bool customNameVisible = false,
        bool silent = false,
        bool noGravity = false,
        Pose pose = Pose::Standing,
        int16_t tickFrozenInPowderedSnow = 0,
        Vector3<double> pos = {0, 0, 0},
        Vector2<uint8_t> rot = {0, 0},
        Vector3<double> lastPos = {0, 0, 0},
        Vector2<uint8_t> lastRot = {0, 0});
    // clang-format on
    virtual ~Entity() {};
    virtual void tick() = 0;
    virtual void setDimension(std::shared_ptr<Dimension> dim);
    virtual void setPosition(const Vector3<double> &pos, bool on_ground);
    virtual void setPosition(double x, double y, double z, bool on_ground);
    virtual void forceSetPosition(const Vector3<double> &pos);
    virtual void forceSetPosition(double x, double y, double z);
    virtual void setRotation(const Vector2<uint8_t> &rot);
    virtual void setRotation(uint8_t yaw, uint8_t pitch);
    NODISCARD virtual std::shared_ptr<Dimension> getDimension() const;
    NODISCARD virtual std::shared_ptr<World> getWorld() const;
    NODISCARD virtual std::shared_ptr<WorldGroup> getWorldGroup() const;
    NODISCARD virtual int32_t getId() const;
    NODISCARD virtual Vector3<double> &getPosition();
    NODISCARD virtual const Vector3<double> &getPosition() const;
    NODISCARD virtual Vector2<uint8_t> &getRotation();
    NODISCARD virtual const Vector2<uint8_t> &getRotation() const;
    NODISCARD virtual Vector3<double> &getLastPosition();
    NODISCARD virtual Vector2<uint8_t> &getLastRotation();
    NODISCARD virtual protocol::SpawnEntity::EntityType getType() const { return _type; }

    virtual void teleport(const Vector3<double> &pos);

    // Drop an item when necessary (death of the entity, broken block, ...)
    // The dropped item is determined by the loot tables
    virtual void dropItem(UNUSED const Vector3<double> &pos) {};

protected:
    std::shared_ptr<Dimension> _dim;
    bool _onFire;
    bool _crouching;
    // bool _unused; (previously used for _riding)
    bool _sprinting;
    bool _swimming;
    bool _invisible;
    bool _glowing;
    bool _flyingWithElytra;
    int16_t _airTicks;
    std::string _customName;
    bool _customNameVisible;
    bool _silent;
    bool _noGravity;
    Pose _pose;
    int16_t _tickFrozenInPowderedSnow;
    int32_t _id;
    Vector3<double> _pos;
    Vector2<uint8_t> _rot;
    Vector3<double> _lastPos;
    Vector2<uint8_t> _lastRot;
    protocol::SpawnEntity::EntityType _type;
};

#endif // CUBICSERVER_ENTITY_HPP
