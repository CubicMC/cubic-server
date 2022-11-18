#ifndef A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0
#define A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include <optional>

namespace protocol
{

    enum class ClientPacketID : int32_t {
        STATUS = 0x00,
        PING = 0x01,
        DISCONNECT = 0x17,
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
        int32_t signatureLength;
        std::vector<uint8_t> signature;
    };

    std::shared_ptr<std::vector<uint8_t>> createPlayerChatMessage(const PlayerChatMessage &);
    
    struct DisconnectReason
    {
        std::string reason;
    };

    std::shared_ptr<std::vector<uint8_t>> DisconnectPlayerReason(const DisconnectReason &);
}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
