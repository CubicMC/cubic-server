#ifndef CHAT_EVENTS_HOVER_ENTITY_HPP
#define CHAT_EVENTS_HOVER_ENTITY_HPP

#include "chat/events/Hover.hpp"
#include <functional>
#include <optional>

class Entity;

namespace chat::message::event {
/**
 * @brief Show an entity in the hover event
 *
 * @todo The entity is not yet implemented
 */
class EntityHover : public OnHover {
public:
    EntityHover() = default;
    EntityHover(const Entity &entity):
        _entity(entity) {};

    ~EntityHover() override = default;

    nlohmann::json toJson() const override;

    static std::shared_ptr<EntityHover> fromJson(const nlohmann::json &json);

private:
    std::optional<std::reference_wrapper<const Entity>> _entity;
};
} // namespace chat::message

#endif // CHAT_EVENTS_HOVER_ENTITY_HPP
