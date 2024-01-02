#include "metadata.hpp"
#include "entities/Entity.hpp"
#include "protocol/serialization/addPrimaryType.hpp"

#define METADATA_HEADER(type) \
    addByte(data, index);     \
    addVarInt(data, (int32_t) Type::type)

namespace protocol::entity_metadata {

void addMByte(std::vector<uint8_t> &data, uint8_t index, uint8_t value)
{
    METADATA_HEADER(Byte);
    addByte(data, value);
}

void addMVarInt(std::vector<uint8_t> &data, uint8_t index, int32_t value)
{
    METADATA_HEADER(VarInt);
    addVarInt(data, value);
}

void addMOptChat(std::vector<uint8_t> &data, uint8_t index, const std::optional<chat::Message> &value)
{
    METADATA_HEADER(OptChat);
    addBoolean(data, value.has_value());
    if (value.has_value())
        addChat(data, value->serialize());
}

void addMBoolean(std::vector<uint8_t> &data, uint8_t index, bool value)
{
    METADATA_HEADER(Boolean);
    addBoolean(data, value);
}

void addMPose(std::vector<uint8_t> &data, uint8_t index, Pose value)
{
    METADATA_HEADER(Pose);
    addVarInt(data, (int32_t) value);
}

void addMFloat(std::vector<uint8_t> &data, uint8_t index, float value)
{
    METADATA_HEADER(Float);
    addFloat(data, value);
}

void addMOptPosition(std::vector<uint8_t> &data, uint8_t index, const std::optional<Position> &value)
{
    METADATA_HEADER(OptPosition);
    addBoolean(data, value.has_value());
    if (value.has_value())
        addPosition(data, *value);
}

void addMSlot(std::vector<uint8_t> &data, uint8_t index, const Slot &value)
{
    METADATA_HEADER(Slot);
    addSlot(data, value);
}

}
