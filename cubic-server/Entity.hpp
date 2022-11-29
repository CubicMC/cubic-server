#ifndef CUBICSERVER_ENTITY_HPP
#define CUBICSERVER_ENTITY_HPP

#include <memory>
class Dimension;

class Entity
{
public:
    // Subject to change
    Entity() {};
    virtual  ~Entity() {};
    virtual void tick() = 0;
    virtual void setDimension(std::shared_ptr<Dimension> dim);
    virtual std::shared_ptr<Dimension> getDimension() const;

protected:
    std::shared_ptr<Dimension> _dim;
};


#endif //CUBICSERVER_ENTITY_HPP
