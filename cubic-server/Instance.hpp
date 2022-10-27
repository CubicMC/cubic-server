#ifndef CUBICSERVER_INSTANCE_HPP
#define CUBICSERVER_INSTANCE_HPP

#include <vector>
#include <memory>

#include "Entity.hpp"
#include "Chat.hpp"

class Instance
{
private:
    std::vector<Entity> _entities;
    std::shared_ptr<Chat> _chat;
};


#endif //CUBICSERVER_INSTANCE_HPP
