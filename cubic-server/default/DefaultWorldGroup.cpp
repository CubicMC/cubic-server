#include "DefaultWorldGroup.hpp"

#include <utility>

#include "DefaultWorld.hpp"

DefaultWorldGroup::DefaultWorldGroup(std::shared_ptr<Chat> chat):
    WorldGroup(std::move(chat))
{
}

void DefaultWorldGroup::initialize()
{
    _worlds.emplace("default", std::make_shared<DefaultWorld>(shared_from_this(), "world2")); // TODO(huntears): config
    _worlds.at("default")->initialize();

    WorldGroup::initialize();
}
