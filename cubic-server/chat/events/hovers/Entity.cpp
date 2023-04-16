#include "Entity.hpp"

std::shared_ptr<chat::message::event::EntityHover> chat::message::event::EntityHover::fromJson(const nlohmann::json &json)
{
    std::shared_ptr<EntityHover> event = std::make_shared<EntityHover>();

    // TODO: Implement entity
    // event->_entity = std::make_shared<Entity>(json["contents"]["id"].get<std::string>());

    return event;
}

nlohmann::json chat::message::event::EntityHover::toJson() const
{
    nlohmann::json response;

    response["action"] = "show_entity";
    response["contents"] = nlohmann::json::object();
    response["contents"]["type"] = "minecraft:player";
    response["contents"]["id"] = "00000000-0000-0000-0000-000000000000";
    // response["contents"]["id"] = _entity->uuid().toString();
    // TODO: Implement entity

    return response;
}
