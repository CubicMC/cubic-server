#include "logging/Logger.hpp"
#include "ClickEvent.hpp"

nlohmann::json chat::message::ClickEvent::toJson() const
{
    nlohmann::json response;

    switch (action) {
    case Action::OpenURL:
        response["action"] = "open_url";
        break;
    case Action::OpenFile:
        response["action"] = "open_file";
        break;
    case Action::RunCommand:
        response["action"] = "run_command";
        break;
    case Action::SuggestCommand:
        response["action"] = "suggest_command";
        break;
    case Action::ChangePage:
        response["action"] = "change_page";
        break;
    case Action::CopyToClipboard:
        response["action"] = "copy_to_clipboard";
        break;
    default:
        LERROR("Unknown click event action: ", static_cast<int32_t>(action));
        break;
    }

    response["value"] = value;

    return response;
}

chat::message::ClickEvent chat::message::ClickEvent::deserialize(const std::string &message)
{
    nlohmann::json json = nlohmann::json::parse(message);
    return fromJson(json);
}

chat::message::ClickEvent chat::message::ClickEvent::fromJson(const nlohmann::json &json)
{
    ClickEvent event;
    std::string action = json["action"].get<std::string>();
    if (action == "open_url")
        event.action = Action::OpenURL;
    else if (action == "open_file")
        event.action = Action::OpenFile;
    else if (action == "run_command")
        event.action = Action::RunCommand;
    else if (action == "suggest_command")
        event.action = Action::SuggestCommand;
    else if (action == "change_page")
        event.action = Action::ChangePage;
    else if (action == "copy_to_clipboard")
        event.action = Action::CopyToClipboard;
    else
        throw std::runtime_error("Unknown click event action: " + action);
    event.value = json["value"].get<std::string>();
    return event;
}
