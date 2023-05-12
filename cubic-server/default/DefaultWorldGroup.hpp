#ifndef CUBICSERVER_DEFAULT_DEFAULTWORLDGROUP_HPP
#define CUBICSERVER_DEFAULT_DEFAULTWORLDGROUP_HPP

#include "../WorldGroup.hpp"

class DefaultWorldGroup : public WorldGroup, public std::enable_shared_from_this<DefaultWorldGroup> {
public:
    DefaultWorldGroup(std::shared_ptr<Chat> chat);
    ~DefaultWorldGroup() override = default;
    void initialize() override;
};

#endif // CUBICSERVER_DEFAULT_DEFAULTWORLDGROUP_HPP
