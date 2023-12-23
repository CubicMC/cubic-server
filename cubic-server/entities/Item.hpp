#ifndef CUBICSERVER_ENTITIES_ITEM_HPP
#define CUBICSERVER_ENTITIES_ITEM_HPP

#include "Entity.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"

class Item : public Entity {
public:
    Item(std::shared_ptr<Dimension> dim, protocol::Slot slot):
        Entity(dim, EntityType::Item),
        _slot(slot),
        _nbTicksBeforePickable(0)
    {
    }
    ~Item() { }

    void tick() override;
    void dropItem(const Vector3<double> &pos, bool isDroppedWillingly = true) override;
    const protocol::Slot &getItem() const { return _slot; };

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    void appendMetadataPacket(std::vector<uint8_t> &data) const override;

    /**
     * @brief Returns if the item is beyond ton unpickable period
     *
     * @return true The item is pickable
     * @return false The item is not pickable
     */
    inline bool isPickable() { return _nbTicksBeforePickable == 0; }

private:
    protocol::Slot _slot;
    size_t _nbTicksBeforePickable;
};

#endif // CUBICSERVER_ENTITIES_ITEM_HPP
