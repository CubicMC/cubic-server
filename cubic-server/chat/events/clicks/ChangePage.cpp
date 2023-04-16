#include "ChangePage.hpp"

nlohmann::json chat::message::event::ChangePageClick::toJson() const
{
    nlohmann::json response;

    response["action"] = "change_page";
    response["value"] = _page;

    return response;
}

std::shared_ptr<chat::message::event::ChangePageClick> chat::message::event::ChangePageClick::fromJson(const nlohmann::json &json)
{
    return std::make_shared<ChangePageClick>(json["value"].get<std::string>());
}
