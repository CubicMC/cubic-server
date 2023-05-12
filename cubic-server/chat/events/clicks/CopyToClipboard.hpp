#ifndef CHAT_EVENTS_CLICKS_COPY_TO_CLIP_HPP
#define CHAT_EVENTS_CLICKS_COPY_TO_CLIP_HPP

#include "chat/events/Click.hpp"

namespace chat::message::event {
/**
 * @brief Copy a text to the clipboard
 */
class CopyToClipboardClick : public OnClick {
public:
    CopyToClipboardClick(const std::string &text):
        _text(text)
    {
    }
    ~CopyToClipboardClick() override = default;

    nlohmann::json toJson() const override;

    static std::shared_ptr<CopyToClipboardClick> fromJson(const nlohmann::json &json);

private:
    std::string _text;
};
} // namespace chat::message::event

#endif // CHAT_EVENTS_CLICKS_COPY_TO_CLIP_HPP
