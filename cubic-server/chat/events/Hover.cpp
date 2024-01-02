#include "Hover.hpp"

#include "hovers/EntityEvent.hpp"
#include "hovers/ItemEvent.hpp"
#include "hovers/Text.hpp"
#include "logging/logging.hpp"

std::shared_ptr<chat::message::event::OnHover> chat::message::event::OnHover::deserialize(const std::string &message) { return fromJson(nlohmann::json::parse(message)); }

std::shared_ptr<chat::message::event::OnHover> chat::message::event::OnHover::fromJson(const nlohmann::json &json)
{
    ;
    std::string action = json["action"].get<std::string>();

    if (action == "show_text")
        return TextHover::fromJson(json);
    else if (action == "show_item")
        return ItemHover::fromJson(json);
    else if (action == "show_entity")
        return EntityHover::fromJson(json);

    throw std::runtime_error("Unknown hover event action: " + action);
}
