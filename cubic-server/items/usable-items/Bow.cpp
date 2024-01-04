#include "Bow.hpp"
#include "Dimension.hpp"
#include "entities/Arrow.hpp"
#include "entities/Entity.hpp"
#include "items/UsableItem.hpp"
#include "logging/logging.hpp"

nbt_tag_t *Items::Bow::setNbtTag()
{
    int32_t DAMAGE = 0;
    int32_t UNBREAKABLE = this->_isUnbreakable;
    std::string_view DAMAGE_TAG = "Damage";
    std::string_view UNBREAKABLE_TAG = "Breakable";
    auto root = nbt_new_tag_compound();
    auto damage = nbt_new_tag_int(DAMAGE);
    auto breakable = nbt_new_tag_int(UNBREAKABLE);
    nbt_set_tag_name(damage, DAMAGE_TAG.data(), DAMAGE_TAG.size());
    nbt_set_tag_name(breakable, UNBREAKABLE_TAG.data(), UNBREAKABLE_TAG.size());
    nbt_tag_compound_append(root, damage);
    nbt_tag_compound_append(root, breakable);

    return root;
}

void Items::Bow::onUse(std::shared_ptr<Dimension> dim, Entity &user, UsabilityType usage)
{
    auto &entityRotation = user.getRotation();
    auto arr = dim->makeEntity<Arrow>();
    arr->forceSetPosition(user.getPosition());
    LINFO("spawn entity arrow");
    dim->spawnEntity(arr);
}
