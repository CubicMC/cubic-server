#include "EntityEvent.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"
#include <memory>

std::shared_ptr<chat::message::event::EntityHover> chat::message::event::EntityHover::fromJson(UNUSED const nlohmann::json &json)
{
    // TODO: Get entity from json
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
    response["contents"]["type"] = getEntityTypeName(_entity->get().getType());
    response["contents"]["id"] = _entity->get().getUuid().toString();
    if (_entity.has_value()) {
        try {
            const auto &player = dynamic_cast<const Player &>(_entity->get());
            response["contents"]["name"] = player.getUsername();
        } catch (std::bad_cast &e) {
        }
    }
    // TODO: Implement entity

    return response;
}
