#ifndef A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0
#define A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include <optional>
#include <variant>

#include "Structures.hpp"
#include "typeSerialization.hpp"

namespace protocol
{

    enum class ClientPacketID : int32_t {
        Status = 0x00,
        DisconnectLogin = 0x00,
        Ping = 0x01,
        LoginSuccess = 0x02,
        CustomSoundEffect = 0x16,
        WorldEvent = 0x20,
        LoginPlay = 0x23,
        PlayerChatMessage = 0x30,
        SynchronizePlayerPosition = 0x36,
        EntitySoundEffect = 0x5c,
        SoundEffect = 0x5d,
        DisconnectPlay = 0x17,
        KeepAlive = 0x1e,
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

    struct LoginSuccess
    {
        u128 uuid;
        std::string username;
        int32_t numberOfProperties;
        // Don't know how to build a Property thing that is an array of strings and bools
        // std::array<std::variant<std::string, bool>, 4> properties;
        std::string name;
        std::string value;
        bool isSigned;
        std::optional<std::string> signature;
    };

    std::shared_ptr<std::vector<uint8_t>> createLoginSuccess(const LoginSuccess &);

    struct LoginPlay
    {
        int32_t entityID;
        bool isHardcore;
        uint8_t gamemode;
        uint8_t previousGamemode; // must be a signed byte
        std::vector<std::string> dimensionNames;
        nbt::Compound registryCodec;
        std::string dimensionType;
        std::string dimensionName;
        long hashedSeed;
        int32_t maxPlayers;
        int32_t viewDistance;
        int32_t simulationDistance;
        bool reducedDebugInfo;
        bool enableRespawnScreen;
        bool isDebug;
        bool isFlat;
        bool hasDeathLocation;
        std::optional<std::string> deathDimensionName;
        std::optional<Position> deathLocation;
    };

    std::shared_ptr<std::vector<uint8_t>> createLoginPlay(const LoginPlay &);

    struct PlayerChatMessage
    {
        std::string signedContent;
        bool hasUnsignedContent;
        std::string unsignedContent;
        int32_t type;
        u128 senderUUID;
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

    struct SynchronizePlayerPosition
    {
        double x;
        double y;
        double z;
        float yaw;
        float pitch;
        uint8_t flags; // must be a signed byte
        int32_t teleportId;
        bool dismountVehicle;
    };

    std::shared_ptr<SynchronizePlayerPosition> parseSynchronizePlayerPosition(std::vector<uint8_t> &buffer);

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

    struct Disconnect
    {
        std::string reason;
    };

    std::shared_ptr<std::vector<uint8_t>> createLoginDisconnect(const Disconnect &);
    std::shared_ptr<std::vector<uint8_t>> createPlayDisconnect(const Disconnect &);

    std::shared_ptr<std::vector<uint8_t>> createKeepAlive(long id);

}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
