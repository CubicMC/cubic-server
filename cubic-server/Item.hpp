#ifndef CUBICSERVER_ITEM_HPP
#define CUBICSERVER_ITEM_HPP

#include "Entity.hpp"
#include "types.hpp"

class Item : public Entity {
public:
    Item(std::shared_ptr<Dimension> dim, protocol::Slot slot):
        Entity(dim, protocol::SpawnEntity::EntityType::Item),
        _slot(slot)
    {
    }
    ~Item() { }

    void tick() override;
    void dropItem(const Vector3<double> &pos) override;
    ItemId getItemId() const { return _slot.itemID; };

private:
    protocol::Slot _slot;
};

#endif // CUBICSERVER_ITEM_HPP
