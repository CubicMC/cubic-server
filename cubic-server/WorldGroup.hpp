#ifndef CUBICSERVER_WORLDGROUP_HPP
#define CUBICSERVER_WORLDGROUP_HPP


#include <memory>

#include "Chat.hpp"

class WorldGroup
{
public:
    WorldGroup(std::shared_ptr<Chat> chat);
private:
    std::shared_ptr<Chat> _chat;
};


#endif //CUBICSERVER_WORLDGROUP_HPP
