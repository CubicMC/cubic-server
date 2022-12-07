#ifndef A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0
#define A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include <optional>
#include <array>

#include "Structures.hpp"

namespace protocol
{

    enum class ClientPacketID : int32_t {
        STATUS = 0x00,
        PING = 0x01,
        PlayerChatMessage = 0x30,
        ChunkDataAndLightUpdate = 0x1F
    };

    struct PingResponse
    {
        int64_t payload;
    };

    std::shared_ptr<std::vector<uint8_t>> createPingResponse(const PingResponse &);

    struct StatusResponse
    {
        std::string payload;
    };

    std::shared_ptr<std::vector<uint8_t>> createStatusResponse(const StatusResponse &);

    struct PlayerChatMessage
    {
        std::string signedContent;
        bool hasUnsignedContent;
        std::string unsignedContent;
        int32_t type;
        __int128 senderUUID;
        std::string senderName;
        bool hasTeamName;
        std::string teamName;
        long timestamp;
        long salt;
        int32_t signatureLength;
        std::vector<uint8_t> signature;
    };

    std::shared_ptr<std::vector<uint8_t>> createPlayerChatMessage(const PlayerChatMessage &);

    // Only for chunk data and light update packet
    struct ChunkDataAndLightUpdate
    {
        int32_t chunkX;
        int32_t chunkZ;
        // NBT heightmaps;
        int32_t size;
        std::vector<uint8_t> data;
        std::vector<BlockEntity> blockEntities;
        bool trustEdges;
        std::vector<long> skyLightMask;
        std::vector<long> blockLightMask;
        std::vector<long> emptySkyLightMask;
        std::vector<long> emptyBlockLightMask;
        std::vector<std::array<uint8_t, LIGHT_ARRAY_SIZE>> skyLight;
        std::vector<std::array<uint8_t, LIGHT_ARRAY_SIZE>> blockLight;
    };
    std::shared_ptr<std::vector<uint8_t>> createChunkDataAndLightUpdate(const ChunkDataAndLightUpdate &);
}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
