#ifndef CHAT_EVENTS_CLICKS_RUN_COMMAND_HPP
#define CHAT_EVENTS_CLICKS_RUN_COMMAND_HPP

#include "chat/events/Click.hpp"

namespace chat::message::event {
/**
 * @brief Run a command
 */
class RunCommandClick : public OnClick {
public:
    RunCommandClick(const std::string &command):
        _command(command)
    {
    }

    ~RunCommandClick() override = default;

    nlohmann::json toJson() const override;

    static std::shared_ptr<RunCommandClick> fromJson(const nlohmann::json &json);

private:
    std::string _command;
};
} // namespace chat::message::event

#endif // CHAT_EVENTS_CLICKS_RUN_COMMAND_HPP
