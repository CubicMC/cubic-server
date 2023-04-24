#ifndef CHAT_EVENTS_HOVER_ENTITY_HPP
#define CHAT_EVENTS_HOVER_ENTITY_HPP

#include "Entity.hpp"
#include "chat/events/Hover.hpp"

namespace chat::message::event {
/**
 * @brief Show an entity in the hover event
 *
 * @todo The entity is not yet implemented
 */
class EntityHover : public OnHover {
public:
    EntityHover() { }
    // EntityHover(const std::shared_ptr<Entity> &entity):
    //     _entity(entity) {};

    nlohmann::json toJson() const override;

    static std::shared_ptr<EntityHover> fromJson(const nlohmann::json &json);

private:
    // Need to have a shared instead of a weak pointer because the entity can be created from the json
    // Or we need to get the entity from the world
    // That may be a better idea
    // std::shared_ptr<Entity> _entity;
};
} // namespace chat::message

#endif // CHAT_EVENTS_HOVER_ENTITY_HPP
