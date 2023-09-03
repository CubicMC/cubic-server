#ifndef CUBICSERVER_ENTITY_HPP
#define CUBICSERVER_ENTITY_HPP

#include "EntityType.hpp"
#include "math/Vector2.hpp"
#include "math/Vector3.hpp"
#include "options.hpp"
#include "protocol/ClientPackets.hpp"
#include "types.hpp"
#include "utility/SharedFromThis.hpp"
#include <memory>
#include <utility>

class World;
class WorldGroup;
class Dimension;

/**
 * @brief Defines the different states an entity can have
 *
 */
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

class Entity : public utility::SharedFromThis<Entity> {
public:
    // Subject to change
    // clang-format off
    Entity(std::shared_ptr<Dimension> dim,
        EntityType type,
        u128 uuid = u128::random(),
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
    virtual void setRotation(float yaw, float pitch);

    NODISCARD virtual std::shared_ptr<Dimension> getDimension() { return _dim; }
    NODISCARD virtual std::shared_ptr<World> getWorld();
    NODISCARD virtual std::shared_ptr<WorldGroup> getWorldGroup();

    NODISCARD virtual const u128 &getUuid() const { return _uuid; }
    NODISCARD virtual std::shared_ptr<const Dimension> getDimension() const { return _dim; }
    NODISCARD virtual std::shared_ptr<const World> getWorld() const;
    NODISCARD virtual std::shared_ptr<const WorldGroup> getWorldGroup() const;
    NODISCARD virtual int32_t getId() const { return _id; }
    NODISCARD virtual const Vector3<double> &getPosition() const { return _pos; }
    NODISCARD virtual const Vector2<uint8_t> &getRotation() const { return _rot; }
    NODISCARD virtual const Vector2<float> getRotationDegree() const { return {(float) _rot.x / (256.0f / 360.0f), (float) _rot.z / (256.0f / 360.0f)}; }
    NODISCARD virtual EntityType getType() const { return _type; }

    virtual void teleport(const Vector3<double> &pos);

    // Drop an item when necessary (death of the entity, broken block, ...)
    // The dropped item is determined by the loot tables
    virtual void dropItem(UNUSED const Vector3<double> &pos) {};

    // Check if there is an item to pickup within the entity pickup box
    // (1 block on each side, 0.5 block above & below)
    const std::shared_ptr<Entity> pickupItem();

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    virtual void appendMetadataPacket(std::vector<uint8_t> &data) const;

    /**
     * @brief Specify when an entity crouches and sneaks
     *
     * @param value If the entity crouches and sneaks
     */
    void setCrouching(bool value);

    /**
     * @brief Broadcasts this entity's metadata to all nearby players
     *
     */
    void broadcastMetadata() const;

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
    u128 _uuid;
    Vector3<double> _pos;
    Vector2<uint8_t> _rot;
    Vector3<double> _lastPos;
    Vector2<uint8_t> _lastRot;
    EntityType _type;
};

#endif // CUBICSERVER_ENTITY_HPP
