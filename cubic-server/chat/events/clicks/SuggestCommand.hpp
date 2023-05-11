#ifndef CHAT_EVENTS_CLICKS_SUGGEST_COMMAND_HPP
#define CHAT_EVENTS_CLICKS_SUGGEST_COMMAND_HPP

#include "chat/events/Click.hpp"

namespace chat::message::event {
/**
 * @brief Suggest a command to the player
 */
class SuggestCommandClick : public OnClick {
public:
    SuggestCommandClick(const std::string &command):
        _command(command)
    {
    }

    ~SuggestCommandClick() override = default;

    nlohmann::json toJson() const override;

    static std::shared_ptr<SuggestCommandClick> fromJson(const nlohmann::json &json);

private:
    std::string _command;
};
} // namespace chat::message::event

#endif // CHAT_EVENTS_CLICKS_SUGGEST_COMMAND_HPP
