#ifndef CUBICSERVER_AI_AI_HPP
#define CUBICSERVER_AI_AI_HPP

#include "math/Vector3.hpp"
#include <memory>
#include <queue>

class Entity;

namespace ai {
class AI {
public:
    AI(std::shared_ptr<Entity> entity):
        _entity(entity) {};
    virtual ~AI() {};

    virtual bool see() = 0;
    virtual void think() = 0;
    virtual void act() = 0;
    virtual void brain()
    {
        if (!see())
            return;
        if (_path.empty())
            think();
        else
            act();
    }

protected:
    std::queue<Vector3<double>> _path;
    std::shared_ptr<Entity> _entity;
};
} // namespace ai

#endif // CUBICSERVER_AI_AI_HPP
