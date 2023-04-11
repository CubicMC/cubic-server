#include "HoverEvent.hpp"
#include "logging/Logger.hpp"

nlohmann::json chat::message::HoverEvent::toJson() const
{
    nlohmann::json response;

    switch (action) {
    case Action::ShowText:
        response["action"] = "show_text";
        break;
    case Action::ShowItem:
        response["action"] = "show_item";
        break;
    case Action::ShowEntity:
        response["action"] = "show_entity";
        break;
    default:
        LERROR("Unknown hover event action: ", static_cast<int32_t>(action));
        break;
    }

    response["contents"] == value;
    // response["contents"] = nlohmann::json::object();
    // response["contents"]["type"] = "minecraft:player";
    // response["contents"]["id"] = "7e4a61cc-83fa-4441-a299-bf69786e610a";
    // response["contents"]["name"] = chat::Message("PlayerName").toJson();
    /*
    A JSON-NBT String describing the entity. Contains 3 values: id, the entity's UUID (with dashes);
    type (optional), which contains the resource location for the entity's type (eg minecraft:zombie);
    and name, which contains the entity's custom name (if present).
    Note that this is a String and not a JSON object. It should be set in a String directly ("value":"{id:7e4a61cc-83fa-4441-a299-bf69786e610a,type:minecraft:zombie,name:Zombie}")
    or as the content of a component. If the entity is invalid, "Invalid Entity!" will be displayed.
    Note that the client does not need to have the given entity loaded.
    */
    // response["value"] = value;

    return response;
}

chat::message::HoverEvent chat::message::HoverEvent::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::message::HoverEvent chat::message::HoverEvent::fromJson(const nlohmann::json &json)
{
    HoverEvent event;
    std::string action = json["action"].get<std::string>();
    if (action == "show_text")
        event.action = Action::ShowText;
    else if (action == "show_item")
        event.action = Action::ShowItem;
    else if (action == "show_entity")
        event.action = Action::ShowEntity;
    else
        throw std::runtime_error("Unknown hover event action: " + action);
    event.value = json["value"].get<std::string>();
    return event;
}
