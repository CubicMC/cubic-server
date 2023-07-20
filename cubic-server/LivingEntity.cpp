#include "LivingEntity.hpp"

#include "generation/generator.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "events/Events.hpp"
#include "events/CancelEvents.hpp"
#include "PluginManager.hpp"


/*
 * @brief Detect the block softness, return multiplicator
 *
 * @param blk The block to check
 */
double LivingEntity::getBlockSoftness(BlockId blk)
{
    static const std::vector<std::string> bImmunes = {
        "ladder", "vine", "scaffolding", "bubble column", "lava", "cobweb", "slime block", "honey block"
    };

    return 1;
}

/*
 * @brief Detect whether the entity should take fall damage, return multiplicator
 *
 * @param env The environment that the entity is in
 */
double LivingEntity::getFalldmgEnvironmentFactor(void)
{
    static const std::vector<std::string> mImmunes = {
        "blaze", "dragon", "ghast", "jockey", "magma cube", "phantom", "vex", "wither", "shulker", // hostile
        "bat", "bee", "chicken", "cat", "iron golem", "snow golem", "ocelot", "parrot" // passive
    };
    // method class dimension: return block from relative position %chunk_sz
    // BlockId blk0 = generation::Generator::getBlock(round(this->_pos.x), round(this->_pos.y), round(this->_pos.z));
    // std::vector<BlockId> blkAroundEntity = {blk[0], blk[1], blk[2]};

    return  // TODO detect block under, make list of soft blocks
            // getBlockSoftness(bAroundEntity[2]) *
            !(// TODO check if entity landed in water
            // !(isInWater(bAroundEntity[0]) || isInWater(bAroundEntity[1]) || isInWater(bAroundEntity[2])) &&
            // TODO waiting for potion effects to be implemented
            // !this->hasEffect(PotionEffect::SlowFalling) &&
            // TODO is mob type immune to fall damage
            // std::find(mImmunes.begin(), mImmunes.end(), this->mobType) == mImmunes.end() &&
            !this->_flyingWithElytra);
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
