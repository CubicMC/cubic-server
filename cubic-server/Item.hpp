#ifndef CUBICSERVER_ITEM_HPP
#define CUBICSERVER_ITEM_HPP

#include "Entity.hpp"
#include "types.hpp"

class Item : public Entity {
public:
    Item(std::shared_ptr<Dimension> dim, ItemId itemId):
        Entity(dim, protocol::SpawnEntity::EntityType::Item)
    {
        _itemId = itemId;
    }
    ~Item() { }

    void tick() override;
    void dropItem(const Vector3<double> &pos) override;
    ItemId getItemId() const { return _itemId; };

private:
    ItemId _itemId;
};

#endif // CUBICSERVER_ITEM_HPP
