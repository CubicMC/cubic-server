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
        CustomSoundEffect = 0x16,
        WorldEvent = 0x20,
        PlayerChatMessage = 0x30,
        EntitySoundEffect = 0x5c,
        SoundEffect = 0x5d,
        Disconnect = 0x17,
        StopSound = 0x5e
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

    struct WorldEvent
    {
        int32_t event;
        Position position;
        int32_t data;
        bool disableRelativeVolume;
    };

    std::shared_ptr<std::vector<uint8_t>> createWorldEvent(const WorldEvent &);

    struct CustomSoundEffect
    {
        std::string name;
        int32_t category;
        int32_t x;
        int32_t y;
        int32_t z;
        float volume;
        float pitch;
        long seed;
    };

    std::shared_ptr<std::vector<uint8_t>> createCustomSoundEffect(const CustomSoundEffect &);

    struct EntitySoundEffect
    {
        int32_t soundId;
        int32_t category;
        int32_t entityId;
        float volume;
        float pitch;
    };

    std::shared_ptr<std::vector<uint8_t>> createEntitySoundEffect(const EntitySoundEffect &);

    struct SoundEffect
    {
        int32_t soundId;
        int32_t category;
        int32_t x;
        int32_t y;
        int32_t z;
        float volume;
        float pitch;
        long seed;
    };

    std::shared_ptr<std::vector<uint8_t>> createSoundEffect(const SoundEffect &);

    struct StopSound
    {
        uint8_t flags;
        int32_t source;
        std::string sound;
    };

    std::shared_ptr<std::vector<uint8_t>> createStopSound(const StopSound &);

    struct DisconnectReason
    {
        std::string reason;
    };

    std::shared_ptr<std::vector<uint8_t>> DisconnectPlayerReason(const DisconnectReason &);
}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
