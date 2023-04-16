#include "OpenUrl.hpp"

nlohmann::json chat::message::event::OpenUrlClick::toJson() const
{
    nlohmann::json response;

    response["action"] = "open_url";
    response["value"] = _url;

    return response;
}

std::shared_ptr<chat::message::event::OpenUrlClick> chat::message::event::OpenUrlClick::fromJson(const nlohmann::json &json)
{
    return std::make_shared<OpenUrlClick>(json["value"].get<std::string>());
}
