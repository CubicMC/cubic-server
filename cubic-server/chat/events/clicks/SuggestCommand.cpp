#include "SuggestCommand.hpp"

nlohmann::json chat::message::event::SuggestCommandClick::toJson() const
{
    nlohmann::json response;

    response["action"] = "suggest_command";
    response["value"] = _command;

    return response;
}

std::shared_ptr<chat::message::event::SuggestCommandClick> chat::message::event::SuggestCommandClick::fromJson(const nlohmann::json &json)
{
    return std::make_shared<SuggestCommandClick>(json["value"].get<std::string>());
}
