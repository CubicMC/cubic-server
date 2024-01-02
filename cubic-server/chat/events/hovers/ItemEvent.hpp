#ifndef CHAT_EVENTS_HOVER_ITEM_HPP
#define CHAT_EVENTS_HOVER_ITEM_HPP

#include "chat/events/Hover.hpp"

#include "world_storage/Item.hpp"

namespace chat::message::event {
/**
 * @brief Show an item in the hover event
 *
 * @todo The item has not been implemented yet, so this will do for now
 */
class ItemHover : public OnHover {
public:
    ItemHover(const world_storage::Item &item):
        _item(item) {};

    ~ItemHover() override = default;

    nlohmann::json toJson() const override;

    static std::shared_ptr<ItemHover> fromJson(const nlohmann::json &json);

private:
    world_storage::Item _item;
};
} // namespace chat::message

#endif // CHAT_EVENTS_HOVER_SHOWITEM_HPP
