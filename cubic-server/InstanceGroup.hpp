#ifndef CUBICSERVER_INSTANCEGROUP_HPP
#define CUBICSERVER_INSTANCEGROUP_HPP


#include <memory>

#include "Chat.hpp"

class InstanceGroup
{
public:
    InstanceGroup(std::shared_ptr<Chat> chat);
private:
    std::shared_ptr<Chat> _chat;
};


#endif //CUBICSERVER_INSTANCEGROUP_HPP
