#ifndef CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
#define CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL

#include "../../generation/player_constructions/NetherPortal.hpp"
#include "items/UsableItem.hpp"

namespace Items {

/**
 * @brief The 'Flint & Steel' is an item used to put fire to everything, especially your friends' houses (and Nether Portals, but that's not really important there)
 *
 */
struct FlintAndSteel : public UsableItem {
    FlintAndSteel():
        UsableItem(usableItems[1])
    {
    }
    /**
     * @note See Item::UsableItem::onUse() for more info
     *
     */
    void onUseOn(std::shared_ptr<Dimension> dim, Position &pos, UNUSED UsabilityType usage, UNUSED int32_t face, Entity &user) override;

    /**
     * @note See Item::UsableItem::setNbtTag() for more info
     *
     */
    nbt_tag_t *setNbtTag() override;
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
