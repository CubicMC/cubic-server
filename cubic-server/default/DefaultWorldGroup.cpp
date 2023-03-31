#include <utility>

#include "DefaultWorld.hpp"
#include "DefaultWorldGroup.hpp"

DefaultWorldGroup::DefaultWorldGroup(std::shared_ptr<Chat> chat):
    WorldGroup(std::move(chat))
{
}

void DefaultWorldGroup::initialize()
{
    _worlds.emplace("default", std::make_shared<DefaultWorld>(this));
    _worlds.at("default")->initialize();

    WorldGroup::initialize();
}
