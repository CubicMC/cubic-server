#ifndef CHAT_EVENTS_CLICKS_OPEN_URL_HPP
#define CHAT_EVENTS_CLICKS_OPEN_URL_HPP

#include "chat/events/Click.hpp"

namespace chat::message::event {
/**
 * @brief Open an URL
 */
class OpenUrlClick : public OnClick {
public:
    OpenUrlClick(const std::string &url):
        _url(url)
    {
    }

    ~OpenUrlClick() override = default;

    nlohmann::json toJson() const override;

    static std::shared_ptr<OpenUrlClick> fromJson(const nlohmann::json &json);

private:
    std::string _url;
};
} // namespace chat::message::event

#endif // CHAT_EVENTS_CLICKS_OPEN_URL_HPP
