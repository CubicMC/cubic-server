#include "LivingEntity.hpp"

#include "generation/generator.hpp"
#include "protocol/ClientPackets.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "events/Events.hpp"
#include "events/CancelEvents.hpp"
#include "PluginManager.hpp"

/*
 * @brief Detect the block softness, return multiplicator
 *
 * @param palette The palette of the dimension that the entity is in
 * @param blkId   The block to check
 */
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
/*
 * @brief Detect whether the entity should take fall damage, return multiplicator
 *
 * @param dim The dimension that the entity is in
 */
double LivingEntity::getFalldmgEnvironmentFactor(void)
{
    static const std::list<EType> mobImmune = {
        EType::Blaze, EType::EnderDragon, EType::Ghast, EType::MagmaCube,
        EType::Phantom, EType::Vex, EType::Wither, EType::Shulker, // hostile
        EType::Bat, EType::Bee, EType::Chicken, EType::Cat, EType::IronGolem,
        EType::SnowGolem, EType::Ocelot, EType::Parrot, // passive
    };
    // method class dimension: return block from relative position %chunk_sz
    BlockId blkUnder = 0; // TODO = generation::Generator::getBlock(
    //     round(this->_pos.x), round(this->_pos.y - 2), round(this->_pos.z));

    if (std::find(mobImmune.begin(), mobImmune.end(), this->_type) != mobImmune.end())
        return 0.0;
    return // getBlockSoftness(???, blkUnder) *
            !(// TODO is entity sitting? boat, saddled entity...
            // !this->isSitting() &&
            // TODO waiting for potion effects to be implemented
            // !this->hasEffect(PotionEffect::SlowFalling) &&
            !this->_flyingWithElytra); // does not handle kinetic collision
}

/*
 * @brief Deal fall damage to the entity
 *
 * @param height The height level from which the entity fell
 */
void LivingEntity::applyFalldamage(const double &height)
{
    int fallDamage = ceil(height - this->_pos.y); // nb of blocks fallen
    static const std::vector<std::string> mHalfDmg = {
        "camel", "donkey", "horse", "mule", "skeleton horse", "skeleton horseman", "zombie horse"
    };

    fallDamage -= 3; // mobs don't take damage if they fall 3 blocks or less
    if (fallDamage <= 0)
        return;
    if (fallDamage >= this->_health + 0.5) { // making sure death is infliged if fall damage is too high
        this->damage(999);
        return;
    }
//    if (std::find(mHalfDmg.begin(), mHalfDmg.end(), this->mobType) != mHalfDmg.end())
//        fallDamage /= 2;
//    else if (this->mobType == "llama")
//        fallDamage = (fallDamage - 3) / 2;
//    else if (this->mobType == "goat" || this->mobType == "frog" || this->mobType == "fox")
//        fallDamage -= (5 + 5 * this->mobType == "goat");
//    else
    this->damage(fallDamage < 0 ? 0 : fallDamage);
}

/*
 * @brief Attack the entity
 *
 * @param damage The damage to deal
 * @param source The source of the damage
 */
void LivingEntity::attack(const Vector3<double> &source)
{
    //  TODO : think about how to deal with damage calculation later
    onEvent(Server::getInstance()->getPluginManager(), onEntityDamage, this, 1.0f);
    this->damage(1);
    this->knockback(source);
}

/*
 * @brief Inflict damage to the entity
 *
 * @param damage The damage to deal
 */
void LivingEntity::damage(float damage)
{
    bool canceled = false;

    onEventCancelable(Server::getInstance()->getPluginManager(), onEntityDamage, canceled, this, damage);

    if (canceled)
        return;
    _health -= damage;
}

/*
 * @brief Inflict knockback to the entity
 *
 * @param source The source of the knockback
 * @param force The force of the knockback
 */
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
