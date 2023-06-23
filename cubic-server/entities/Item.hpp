#ifndef CUBICSERVER_ENTITIES_ITEM_HPP
#define CUBICSERVER_ENTITIES_ITEM_HPP

#include "Entity.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"

class Item : public Entity {
public:
    Item(std::shared_ptr<Dimension> dim, protocol::Slot slot):
        Entity(dim, EntityType::Item),
        _slot(slot)
    {
    }
    ~Item() { }

    void tick() override;
    void dropItem(const Vector3<double> &pos) override;
    const protocol::Slot &getItem() const { return _slot; };

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    void appendMetadataPacket(std::vector<uint8_t> &data) const override;

private:
    protocol::Slot _slot;
};

#endif // CUBICSERVER_ENTITIES_ITEM_HPP
