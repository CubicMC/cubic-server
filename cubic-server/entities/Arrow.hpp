#ifndef CUBICSERVER_ENTITIES_ARROW_HPP
#define CUBICSERVER_ENTITIES_ARROW_HPP

#include "Entity.hpp"

class Arrow : public Entity {
public:
    Arrow(std::shared_ptr<Dimension> dim):
        Entity(dim, EntityType::Arrow)
    {
    }
    ~Arrow() { }

    void tick() override;

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    void appendMetadataPacket(std::vector<uint8_t> &data) const override;

private:
};

#endif // CUBICSERVER_ENTITIES_ARROW_HPP
