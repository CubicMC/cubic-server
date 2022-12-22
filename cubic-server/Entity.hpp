#ifndef CUBICSERVER_ENTITY_HPP
#define CUBICSERVER_ENTITY_HPP

#include <memory>
#include "Dimension.hpp"

class Entity
{
public:
    // Subject to change
    Entity(std::shared_ptr<Dimension> dim): _dim(dim) {};
    virtual  ~Entity() {};
    virtual void tick() = 0;
    virtual void setDimension(std::shared_ptr<Dimension> dim);
    virtual std::shared_ptr<Dimension> getDimension() const;
    virtual int32_t getId() const;

protected:
    std::shared_ptr<Dimension> _dim;
    int32_t _id;
};


#endif //CUBICSERVER_ENTITY_HPP
