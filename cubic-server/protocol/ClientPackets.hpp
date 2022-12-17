#ifndef A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0
#define A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include <optional>

#include "Structures.hpp"

namespace protocol
{

    enum class ClientPacketID : int32_t {
        Status = 0x00,
        Ping = 0x01,
        Disconnect = 0x17,
        WorldEvent = 0x20,
        PlayerChatMessage = 0x30
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
        std::vector<uint8_t> signature;
    };

    std::shared_ptr<std::vector<uint8_t>> createPlayerChatMessage(const PlayerChatMessage &);
    
    struct DisconnectReason
    {
        std::string reason;
    };

    std::shared_ptr<std::vector<uint8_t>> createDisconnectPlayerReason(const DisconnectReason &);
    struct WorldEvent
    {
        int32_t event;
        Position position;
        int32_t data;
        bool disableRelativeVolume;
    };

    std::shared_ptr<std::vector<uint8_t>> createWorldEvent(const WorldEvent &);

}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
