#ifndef CUBICSERVER_ENTITY_HPP
#define CUBICSERVER_ENTITY_HPP

#include "math/Vector2.hpp"
#include "math/Vector3.hpp"
#include "options.hpp"
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
    Entity(std::shared_ptr<Dimension> dim);
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

    virtual void teleport(const Vector3<double> &pos);

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
};

#endif // CUBICSERVER_ENTITY_HPP
