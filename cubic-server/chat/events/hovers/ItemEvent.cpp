#include "chat/events/hovers/ItemEvent.hpp"
#include "entities/Item.hpp"

std::shared_ptr<chat::message::event::ItemHover> chat::message::event::ItemHover::fromJson(const nlohmann::json &json)
{
    // TODO: Implement item
    std::shared_ptr<ItemHover> event = std::make_shared<ItemHover>(world_storage::Item(json["contents"]["id"].get<std::string>()));

    return event;
}

nlohmann::json chat::message::event::ItemHover::toJson() const
{
    nlohmann::json response;

    response["action"] = "show_item";
    response["contents"] = nlohmann::json::object();
    // TODO: Implement item
    response["contents"]["id"] = _item.getName();

    return response;
}
