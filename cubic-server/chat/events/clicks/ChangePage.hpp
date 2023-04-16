#ifndef CHAT_EVENTS_CLICKS_CHANGE_PAGE_HPP
#define CHAT_EVENTS_CLICKS_CHANGE_PAGE_HPP

#include "chat/events/Click.hpp"

namespace chat::message::event {
class ChangePageClick : public OnClick {
public:
    ChangePageClick(const std::string &page)
        : _page(page)
    {
    }

    nlohmann::json toJson() const override;

    static std::shared_ptr<ChangePageClick> fromJson(const nlohmann::json &json);

private:
    std::string _page;
};
} // namespace chat::message::event

#endif // CHAT_EVENTS_CLICKS_CHANGE_PAGE_HPP
