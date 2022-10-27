#include "InstanceGroup.hpp"

#include <utility>

InstanceGroup::InstanceGroup(std::shared_ptr<Chat> chat)
    : _chat(std::move(chat))
{
}
