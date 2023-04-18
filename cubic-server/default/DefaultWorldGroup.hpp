#ifndef CUBICSERVER_DEFAULT_DEFAULTWORLDGROUP_HPP
#define CUBICSERVER_DEFAULT_DEFAULTWORLDGROUP_HPP

#include "../WorldGroup.hpp"

class DefaultWorldGroup : public WorldGroup {
public:
    DefaultWorldGroup(std::shared_ptr<Chat> chat);
    void initialize() override;
};

#endif // CUBICSERVER_DEFAULT_DEFAULTWORLDGROUP_HPP
