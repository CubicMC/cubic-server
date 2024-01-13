#ifndef CUBICSERVER_ENTITIES_ARROW_HPP
#define CUBICSERVER_ENTITIES_ARROW_HPP

#include "Entity.hpp"

class Arrow : public Entity {
public:
    Arrow(std::shared_ptr<Dimension> dim, int32_t shotByEntity):
        Entity(dim, EntityType::Arrow),
        _shotByEntity(shotByEntity)
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
    int32_t _shotByEntity;
};

#endif // CUBICSERVER_ENTITIES_ARROW_HPP
