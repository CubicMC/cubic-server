#ifndef CUBICSERVER_AI_AI_HPP
#define CUBICSERVER_AI_AI_HPP

#include "math/Vector3.hpp"
#include <memory>
#include <queue>

class Entity;

namespace ai {

/**
 * @brief The basic AI interface
 */
class AI {
public:
    AI(Entity &entity):
        _entity(entity) {};
    virtual ~AI() {};

    /**
     * @brief Check if the AI can do something
     *
     * @return true
     * @return false
     */
    virtual bool see() = 0;

    /**
     * @brief Create a path to the targeted position
     */
    virtual void think() = 0;

    /**
     * @brief Move the entity or do something
     */
    virtual void act() = 0;

    /**
     * @brief The brain of the AI, call see(), think() and act()
     *
     * @return true
     * @return false if see() return false
     */
    virtual bool brain()
    {
        if (!see())
            return false;
        if (_path.empty())
            think();
        else
            act();
        return true;
    }

protected:
    std::queue<Vector3<double>> _path;
    Entity &_entity;
};
} // namespace ai

#endif // CUBICSERVER_AI_AI_HPP
