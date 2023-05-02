#include "RunCommand.hpp"

nlohmann::json chat::message::event::RunCommandClick::toJson() const
{
    nlohmann::json response;

    response["action"] = "run_command";
    response["value"] = _command;

    return response;
}

std::shared_ptr<chat::message::event::RunCommandClick> chat::message::event::RunCommandClick::fromJson(const nlohmann::json &json)
{
    return std::make_shared<RunCommandClick>(json["value"].get<std::string>());
}
