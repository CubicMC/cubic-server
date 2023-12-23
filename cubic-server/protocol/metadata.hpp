#ifndef DDDBD732_FDAE_4790_80AF_0C6F59D38D59
#define DDDBD732_FDAE_4790_80AF_0C6F59D38D59

#include <cstdint>
#include <optional>
#include <vector>

#include "Chat.hpp"
#include "chat/Message.hpp"
#include "protocol/Structures.hpp"

struct Position;
enum class Pose;

namespace protocol::entity_metadata {

/**
 * @brief Defines all the types used in metadata serialization
 *
 */
enum class Type : int32_t {
    Byte = 0,
    VarInt = 1,
    VarLong = 2,
    Float = 3,
    String = 4,
    Chat = 5,
    OptChat = 6,
    Slot = 7,
    Boolean = 8,
    Rotation = 9,
    Position = 10,
    OptPosition = 11,
    Direction = 12,
    OptUUID = 13,
    OptBlockID = 14,
    NBT = 15,
    Particle = 16,
    VillagerData = 17,
    OptVarInt = 18,
    Pose = 19,
    CatVariant = 20,
    FrogVariant = 21,
    GlobalPos = 22,
    PaintingVariant = 23,
};

/**
 * @brief Adds a byte to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMByte(std::vector<uint8_t> &data, uint8_t index, uint8_t value);

/**
 * @brief Adds a VarInt to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMVarInt(std::vector<uint8_t> &data, uint8_t index, int32_t value);

/**
 * @brief Adds an optional Chat to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMOptChat(std::vector<uint8_t> &data, uint8_t index, const std::optional<chat::Message> &value);

/**
 * @brief Adds a boolean to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMBoolean(std::vector<uint8_t> &data, uint8_t index, bool value);

/**
 * @brief Adds a Pose to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMPose(std::vector<uint8_t> &data, uint8_t index, Pose value);

/**
 * @brief Adds a float to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMFloat(std::vector<uint8_t> &data, uint8_t index, float value);

/**
 * @brief Adds an optional Position to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMOptPosition(std::vector<uint8_t> &data, uint8_t index, const std::optional<Position> &value);

/**
 * @brief Adds a Slot to a buffer with the metadata headers
 *
 * @param data The output buffer to add to
 * @param index The index of the metadata field for the given entity
 * @param value The value to set
 */
void addMSlot(std::vector<uint8_t> &data, uint8_t index, const Slot &value);

}

#endif /* DDDBD732_FDAE_4790_80AF_0C6F59D38D59 */
