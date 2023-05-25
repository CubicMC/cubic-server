#include "Click.hpp"

#include "clicks/ChangePage.hpp"
#include "clicks/CopyToClipboard.hpp"
#include "clicks/OpenUrl.hpp"
#include "clicks/RunCommand.hpp"
#include "clicks/SuggestCommand.hpp"
#include "logging/logging.hpp"

std::shared_ptr<chat::message::event::OnClick> chat::message::event::OnClick::deserialize(const std::string &json) { return fromJson(nlohmann::json::parse(json)); }

std::shared_ptr<chat::message::event::OnClick> chat::message::event::OnClick::fromJson(const nlohmann::json &json)
{
    std::string action = json["action"].get<std::string>();

    if (action == "open_url")
        return OpenUrlClick::fromJson(json);
    else if (action == "run_command")
        return RunCommandClick::fromJson(json);
    else if (action == "suggest_command")
        return SuggestCommandClick::fromJson(json);
    else if (action == "change_page")
        return ChangePageClick::fromJson(json);
    else if (action == "copy_to_clipboard")
        return CopyToClipboardClick::fromJson(json);

    throw std::runtime_error("Unknown click event action: " + action);
}
