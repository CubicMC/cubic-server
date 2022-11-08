#ifndef CUBICSERVER_WORLD_HPP
#define CUBICSERVER_WORLD_HPP

#include <vector>
#include <memory>

#include "Entity.hpp"
#include "Chat.hpp"

class World
{
private:
    std::vector<Entity> _entities;
    std::shared_ptr<Chat> _chat;
};


#endif //CUBICSERVER_WORLD_HPP
