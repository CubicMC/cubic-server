#include "CopyToClipboard.hpp"

nlohmann::json chat::message::event::CopyToClipboardClick::toJson() const
{
    nlohmann::json response;

    response["action"] = "copy_to_clipboard";
    response["value"] = _text;

    return response;
}

std::shared_ptr<chat::message::event::CopyToClipboardClick> chat::message::event::CopyToClipboardClick::fromJson(const nlohmann::json &json)
{
    return std::make_shared<CopyToClipboardClick>(json["value"].get<std::string>());
}
