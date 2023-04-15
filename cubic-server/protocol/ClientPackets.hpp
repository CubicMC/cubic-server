#ifndef A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0
#define A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0

#include <cstdint>
#include <memory>
#include <optional>
#include <stdint.h>
#include <string>
#include <variant>
#include <vector>

#include "Structures.hpp"
#include "typeSerialization.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

namespace protocol {

enum class ClientPacketID : int32_t {
    // Login State
    DisconnectLogin = 0x00,
    LoginSuccess = 0x02,

    // Status State
    Status = 0x00,
    Ping = 0x01,

    // Play State
    SpawnPlayer = 0x02,
    EntityAnimation = 0x03,
    BlockUpdate = 0x09,
    PluginMessage = 0x15,
    // CustomSoundEffect = 0x16, TODO: This is removed in the last revision of wiki.vg
    DisconnectPlay = 0x17,
    UnloadChunk = 0x1b,
    KeepAlive = 0x1F,
    ChunkDataAndLightUpdate = 0x20,
    WorldEvent = 0x21,
    LoginPlay = 0x24,
    UpdateEntityPosition = 0x27,
    UpdateEntityPositionRotation = 0x28,
    UpdateEntityRotation = 0x29,
    PlayerAbilities = 0x30,
    PlayerChatMessage = 0x31,
    PlayerInfoRemove = 0x35,
    PlayerInfoUpdate = 0x36,
    SynchronizePlayerPosition = 0x38,
    RemoveEntities = 0x3A,
    HeadRotation = 0x3E,
    ServerData = 0x41,
    CenterChunk = 0x4a,
    EntityVelocity = 0x50,
    Health = 0x53,
    UpdateTime = 0x5A,
    EntitySoundEffect = 0x5D,
    SoundEffect = 0x5E,
    StopSound = 0x5F,
    SystemChatMessage = 0x60,
    TeleportEntity = 0x64,
    FeatureFlags = 0x67,
};

struct Disconnect {
    std::string reason;
};
std::unique_ptr<std::vector<uint8_t>> createLoginDisconnect(const Disconnect &);

struct LoginSuccess {
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
std::unique_ptr<std::vector<uint8_t>> createLoginSuccess(const LoginSuccess &);

struct StatusResponse {
    std::string payload;
};
std::unique_ptr<std::vector<uint8_t>> createStatusResponse(const StatusResponse &);

struct PingResponse {
    int64_t payload;
};
std::unique_ptr<std::vector<uint8_t>> createPingResponse(const PingResponse &);

struct SpawnPlayer {
    int32_t entity_id;
    u128 player_uuid;
    double x;
    double y;
    double z;
    uint8_t yaw;
    uint8_t pitch;
};
std::unique_ptr<std::vector<uint8_t>> createSpawnPlayer(const SpawnPlayer &);

enum class EntityAnimationID : uint8_t {
    SwingMainArm = 0x00,
    TakeDamage = 0x01,
    LeaveBed = 0x02,
    SwingOffHand = 0x03,
    CriticalEffect = 0x04,
    MagicCriticalEffect = 0x05,
};
std::unique_ptr<std::vector<uint8_t>> createEntityAnimation(EntityAnimationID animId, int32_t entityID);

struct BlockUpdate {
    Position location;
    int32_t block_id;
};
std::unique_ptr<std::vector<uint8_t>> createBlockUpdate(const BlockUpdate &);

struct PluginMessageResponse {
    std::string channel;
    std::vector<uint8_t> data;
};
std::unique_ptr<std::vector<uint8_t>> createPluginMessageResponse(const PluginMessageResponse &);

struct CustomSoundEffect {
    std::string name;
    int32_t category;
    int32_t x;
    int32_t y;
    int32_t z;
    float volume;
    float pitch;
    long seed;
};
std::unique_ptr<std::vector<uint8_t>> createCustomSoundEffect(const CustomSoundEffect &);

std::unique_ptr<std::vector<uint8_t>> createPlayDisconnect(const Disconnect &);

std::unique_ptr<std::vector<uint8_t>> createUnloadChunk(const Position2D &);

std::unique_ptr<std::vector<uint8_t>> createKeepAlive(long id);

// Only for chunk data and light update packet
struct ChunkDataAndLightUpdate {
    int32_t chunkX;
    int32_t chunkZ;
    nbt::Compound heightmaps;
    const world_storage::ChunkColumn &data;
    std::vector<BlockEntity> blockEntities;
    bool trustEdges;
    std::vector<long> skyLightMask;
    std::vector<long> blockLightMask;
    std::vector<long> emptySkyLightMask;
    std::vector<long> emptyBlockLightMask;
    std::vector<std::array<uint8_t, LIGHT_ARRAY_SIZE>> skyLight;
    std::vector<std::array<uint8_t, LIGHT_ARRAY_SIZE>> blockLight;
};
std::unique_ptr<std::vector<uint8_t>> createChunkDataAndLightUpdate(const ChunkDataAndLightUpdate &);

struct WorldEvent {
    int32_t event;
    Position position;
    int32_t data;
    bool disableRelativeVolume;
};
std::unique_ptr<std::vector<uint8_t>> createWorldEvent(const WorldEvent &);

struct LoginPlay {
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
std::unique_ptr<std::vector<uint8_t>> createLoginPlay(const LoginPlay &);

struct UpdateEntityPosition {
    int32_t entityId;
    int16_t deltaX;
    int16_t deltaY;
    int16_t deltaZ;
    bool onGround;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateEntityPosition(const UpdateEntityPosition &);

struct UpdateEntityPositionRotation {
    int32_t entityId;
    int16_t deltaX;
    int16_t deltaY;
    int16_t deltaZ;
    uint8_t yaw;
    uint8_t pitch;
    bool onGround;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateEntityPositionRotation(const UpdateEntityPositionRotation &);

struct UpdateEntityRotation {
    int32_t entityId;
    uint8_t yaw;
    uint8_t pitch;
    bool onGround;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateEntityRotation(const UpdateEntityRotation &);

enum PlayerAbilitiesFlags : uint8_t {
    Invulnerable = 0x01,
    Flying = 0x02,
    AllowFlying = 0x04,
    CreativeMode = 0x08
};
struct PlayerAbilitiesClient {
    uint8_t flags;
    float flyingSpeed;
    float fieldOfViewModifier;
};
std::unique_ptr<std::vector<uint8_t>> createPlayerAbilities(const PlayerAbilitiesClient &in);

struct PlayerChatMessage {
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
std::unique_ptr<std::vector<uint8_t>> createPlayerChatMessage(const PlayerChatMessage &);

struct PlayerInfoRemove {
    std::vector<u128> uuids;
};
std::unique_ptr<std::vector<uint8_t>> createPlayerInfoRemove(const PlayerInfoRemove &);

struct _AddPlayer {
    std::string name;
    int32_t numberOfProperties;
    // properties lol
};

struct _UpdateGamemode {
    int32_t gamemode;
};

struct _UpdateLatency {
    int32_t latency;
};

struct _UpdateDisplayName {
    bool hasDisplayName;
    std::string displayName;
};

struct _InitializeChat {
    // TODO: Let Miki do it xd
    bool has_sig_data;
};

struct _UpdateListed {
    bool listed;
};

struct _Actions {
    u128 uuid;
    // AddPlayer
    _AddPlayer addPlayer;

    // InitializeChat
    _InitializeChat initializeChat;

    // UpdateGamemode
    _UpdateGamemode updateGamemode;

    // UpdateListed
    _UpdateListed updateListed;

    // UpdateLatency
    _UpdateLatency updateLatency;

    // UpdateDisplayName
    _UpdateDisplayName updateDisplayName;
};

enum class PlayerInfoUpdateActions : uint8_t {
    AddPlayer = 0b00000001,
    InitializeChat = 0b00000010,
    UpdateGamemode = 0b00000100,
    UpdateListed = 0b00001000,
    UpdateLatency = 0b00010000,
    UpdateDisplayName = 0b00100000,
};

struct PlayerInfoUpdate {
    uint8_t actions;
    int32_t numberOfActions;
    std::vector<_Actions> actionSets;
};
std::unique_ptr<std::vector<uint8_t>> createPlayerInfoUpdate(const PlayerInfoUpdate &);

struct SynchronizePlayerPosition {
    double x;
    double y;
    double z;
    float yaw;
    float pitch;
    uint8_t flags; // must be a signed byte
    int32_t teleportId;
    bool dismountVehicle;
};
std::unique_ptr<std::vector<uint8_t>> createSynchronizePlayerPosition(const SynchronizePlayerPosition &);

struct RemoveEntities {
    std::vector<int32_t> entities;
};
std::unique_ptr<std::vector<uint8_t>> createRemoveEntities(const RemoveEntities &in);

struct HeadRotation {
    int32_t entityID;
    uint8_t headYaw;
};
std::unique_ptr<std::vector<uint8_t>> createHeadRotation(const HeadRotation &in);

struct ServerData {
    bool has_motd;
    std::string motd;
    bool has_icon;
    std::string icon;
    bool enforce_secure_chat;
};
std::unique_ptr<std::vector<uint8_t>> createServerData(const ServerData &in);

std::unique_ptr<std::vector<uint8_t>> createCenterChunk(const Position2D &in);

struct UpdateTime {
    long world_age;
    long time_of_day;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateTime(const UpdateTime &);

struct EntitySoundEffect {
    int32_t soundId;
    int32_t category;
    int32_t entityId;
    float volume;
    float pitch;
    long seed;
};
std::unique_ptr<std::vector<uint8_t>> createEntitySoundEffect(const EntitySoundEffect &);

struct SoundEffect {
    int32_t soundId;
    int32_t category;
    int32_t x;
    int32_t y;
    int32_t z;
    float volume;
    float pitch;
    long seed;
};
std::unique_ptr<std::vector<uint8_t>> createSoundEffect(const SoundEffect &);

struct StopSound {
    uint8_t flags;
    int32_t source;
    std::string sound;
};
std::unique_ptr<std::vector<uint8_t>> createStopSound(const StopSound &);

struct SystemChatMessage {
    std::string JSONData;
    bool overlay;
};

std::unique_ptr<std::vector<uint8_t>> createSystemChatMessage(const SystemChatMessage &);

struct EntityVelocity {
    int32_t entity_id;
    int16_t velocity_x;
    int16_t velocity_y;
    int16_t velocity_z;
};

std::unique_ptr<std::vector<uint8_t>> createEntityVelocity(const EntityVelocity &);

struct Health {
    float health;
    int32_t food;
    float foodSaturation;
};

std::unique_ptr<std::vector<uint8_t>> createHealth(const Health &);

struct TeleportEntity {
    int32_t entityID;
    double x;
    double y;
    double z;
    uint8_t yaw;
    uint8_t pitch;
    bool onGround;
};
std::unique_ptr<std::vector<uint8_t>> createTeleportEntity(const TeleportEntity &);

struct FeatureFlags {
    std::vector<std::string> flags;
};
std::unique_ptr<std::vector<uint8_t>> createFeatureFlags(const FeatureFlags &in);
}

#endif /* A7ADDD9E_6961_4A3D_AAB2_DF37DB6915F0 */
