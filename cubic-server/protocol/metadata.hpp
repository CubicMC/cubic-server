#ifndef DDDBD732_FDAE_4790_80AF_0C6F59D38D59
#define DDDBD732_FDAE_4790_80AF_0C6F59D38D59

#include <cstdint>
#include <optional>
#include <vector>

#include "Chat.hpp"
#include "chat/Message.hpp"

class Position;
enum class Pose;

namespace protocol::entity_metadata {

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

void addMByte(std::vector<uint8_t> &data, uint8_t index, uint8_t value);
void addMVarInt(std::vector<uint8_t> &data, uint8_t index, int32_t value);
void addMOptChat(std::vector<uint8_t> &data, uint8_t index, const std::optional<chat::Message> &value);
void addMBoolean(std::vector<uint8_t> &data, uint8_t index, bool value);
void addMPose(std::vector<uint8_t> &data, uint8_t index, Pose value);
void addMFloat(std::vector<uint8_t> &data, uint8_t index, float value);
void addMOptPosition(std::vector<uint8_t> &data, uint8_t index, const std::optional<Position> &value);

}

#endif /* DDDBD732_FDAE_4790_80AF_0C6F59D38D59 */
