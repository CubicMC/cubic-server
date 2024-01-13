#ifndef CUBICSERVER_ITEMS_USABLE_ITEMS_BOW
#define CUBICSERVER_ITEMS_USABLE_ITEMS_BOW

#include "items/UsableItem.hpp"
#include "types.hpp"

namespace Items {

/**
 * @brief A bow to shoot arrows at people, funny ding go brrrrrrr
 *
 */
struct Bow : public UsableItem {
    Bow(const std::string_view stringId, const int32_t numeralId, const ItemMaxDurabilityByType maxDurability, bool isUnbreakable, const UsabilityType usabilityType):
        UsableItem(stringId, numeralId, maxDurability, isUnbreakable, usabilityType)
    {
    }

    Bow(const UsableItem &other):
        UsableItem(other)
    {
    }

    void onUse(std::shared_ptr<Dimension> dim, Entity &user, UsabilityType usage) override;

    /**
     * @note See Item::UsableItem::setNbtTag() for more info
     *
     */
    nbt_tag_t *setNbtTag() override;

    bool canUpdateDamage = false;
};

}

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_BOW
