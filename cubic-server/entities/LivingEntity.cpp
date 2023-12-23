#include "LivingEntity.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "PluginManager.hpp"
#include "Server.hpp"
#include "events/CancelEvents.hpp"
#include "events/Events.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"
#include <optional>

double LivingEntity::getBlockSoftness(Blocks::GlobalPalette palette, const BlockId &blkId)
{
    std::string blk = palette.fromProtocolIdToBlock(blkId).name;
    static const std::list<std::string> blkImmune = {
        "ladder", "vine", "bubble_column", "water", "lava", "cobweb", "slime_block", "honey_block"
    };
    if (std::find(blkImmune.begin(), blkImmune.end(), blk) != blkImmune.end())
        return 0.0;
    if (blk == "scaffolding" && this->_crouching)
        return 0.0;
    if (blk == "hay_block")
        return 0.2;
    if (blk != "bedrock" && blk.find("bed") != std::string::npos)
        return 0.5;
    return 1.0;
}

typedef protocol::SpawnEntity::EntityType EType;
double LivingEntity::getFallDmgEnvironmentFactor(Blocks::GlobalPalette palette)
{
    static const std::list<EType> mobImmune = {
        EType::Blaze, EType::EnderDragon, EType::Ghast, EType::MagmaCube,
        EType::Phantom, EType::Vex, EType::Wither, EType::Shulker, // hostile
        EType::Bat, EType::Bee, EType::Chicken, EType::Cat, EType::IronGolem,
        EType::SnowGolem, EType::Ocelot, EType::Parrot, // passive
    };
    BlockId blkUnder = _dim->getChunk(this->_pos.x, this->_pos.z).getBlock(
        {(int) this->_pos.x % 16, (int) (this->_pos.y - 2) % 16, (int) this->_pos.z % 16}
    );
    if (std::find(mobImmune.begin(), mobImmune.end(), this->_type) != mobImmune.end())
        return 0.0;
    return getBlockSoftness(palette, blkUnder) *
            (// TODO is entity sitting? in a boat, riding a saddled entity...
            // !this->isSitting() &&
            // TODO waiting for potion effects to be implemented
            // !this->hasEffect(PotionEffect::SlowFalling) &&
            // !this->_flyingWithElytra
            true); // does not handle kinetic collision
}

void LivingEntity::applyFallDamage(const double &height)
{
    int fallDamage = ceil(height - this->_pos.y); // nb of blocks fallen
    static const std::vector<EType> mobHalfDmg = {
        EType::Camel, EType::Donkey, EType::Horse, EType::Mule, EType::SkeletonHorse, EType::ZombieHorse
    };
    fallDamage -= 3; // mobs don't take damage if they fall 3 blocks or less
    if (fallDamage <= 0)
        return;
    if (std::find(mobHalfDmg.begin(), mobHalfDmg.end(), this->_type) != mobHalfDmg.end())
        fallDamage /= 2;
    else if (this->_type == EType::Llama) // llamas take damage from 6 blocks or more
        fallDamage = (fallDamage - 3) / 2;
    else if (this->_type == EType::Goat || this->_type == EType::Frog || this->_type == EType::Fox)
        fallDamage -= (5 + 5 * (this->_type == EType::Goat));
    if (fallDamage >= this->_health + 0.5) // making sure death is infliged if fall damage is too high
        fallDamage = 999;
    this->damage((fallDamage < 0) * fallDamage);
}

void LivingEntity::attack(float damage, const Vector3<double> &source)
{
    //  TODO : think about how to deal with damage calculation later
    onEvent(Server::getInstance()->getPluginManager(), onEntityDamage, this, 1.0f);
    this->damage(damage);
    this->knockback(source);
}

void LivingEntity::damage(float damage)
{
    bool canceled = false;

    onEventCancelable(Server::getInstance()->getPluginManager(), onEntityDamage, canceled, this, damage);

    if (canceled)
        return;
    _health -= damage;
    broadcastMetadata();
    LDEBUG("entity type {} with id {} took damage {}, health is now {}", this->_type, this->_id, damage, _health);
}

void LivingEntity::knockback(const Vector3<double> &source, float force)
{
    // compute knockback
    // TODO(huntears): Change how the knockback is calculated to be more "vanilla like"
    Vector2<double> pos2d = _pos;
    Vector2<double> source2d = source;
    Vector2<double> direction = source2d - pos2d;
    direction.normalize();

    Vector3<double> kb(direction.x, 1.0f, direction.z);

    kb *= force;

    // send entity velocity too connected players (should be optimized)
    for (auto player : _dim->getPlayers()) {
        player->sendEntityVelocity({_id, static_cast<int16_t>(kb.x), static_cast<int16_t>(kb.y), static_cast<int16_t>(kb.z)});
        player->sendEntityAnimation(protocol::EntityAnimation::ID::TakeDamage, _id);
    }
}

void LivingEntity::setHealth(float health) { _health = health; }

float &LivingEntity::getHealth() { return _health; }

const float &LivingEntity::getHealth() const { return _health; }

void LivingEntity::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    // Hand state flags
    uint8_t flag = 0;
    if (_handState.isHandActive)
        flag |= 0x01;
    flag |= (uint8_t) _handState.activeHand;
    if (_handState.isInRiptideSpinAttack)
        flag |= 0x04;
    addMByte(data, 8, flag);

    // Health
    addMFloat(data, 9, _health);

    // Potion effect color
    addMVarInt(data, 10, _potionEffectColor);

    // Is potion effect ambient
    addMBoolean(data, 11, _isPotionEffectAmbient);

    // Num Arrows in entity
    addMVarInt(data, 12, _numArrowsInEntity);

    // Num Bee Stingers in entity
    addMVarInt(data, 13, _numBeeStingerInEntity);

    // Location of the bed the entity is currently sleeping in
    addMOptPosition(data, 14, _isSleeping ? std::optional<Position>(_posBedSleeping) : std::nullopt);
}
