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
        DISCONNECT = 0x17
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

    struct DisconnectPlayer
    {
        Chat reason;
    };

    std::shared_ptr<std::vector<uint8_t>> disconnectPlayer(const DisconnectPlayer &in);
}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
