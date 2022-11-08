#include "WorldGroup.hpp"

#include <utility>

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat)
    : _chat(std::move(chat))
{
}
