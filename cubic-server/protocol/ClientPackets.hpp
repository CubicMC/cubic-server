#ifndef CUBICSERVER_PROTOCOL_CLIENTPACKETS_HPP
#define CUBICSERVER_PROTOCOL_CLIENTPACKETS_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "PlayerAttributes.hpp"
#include "Structures.hpp"
#include "chat/Message.hpp"
#include "common.hpp"
#include "entities/EntityType.hpp"
#include "protocol/container/Container.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

class Entity;

namespace protocol {

enum class ClientPacketID : int32_t {
    // Login State
    DisconnectLogin = 0x00,
    EncryptionRequest = 0x01,
    LoginSuccess = 0x02,
    SetCompression = 0x03,

    // Status State
    Status = 0x00,
    Ping = 0x01,

    // Play State
    SpawnEntity = 0x00,
    SpawnPlayer = 0x02,
    EntityAnimation = 0x03,
    BlockEntityData = 0x07,
    BlockUpdate = 0x09,
    ChangeDifficulty = 0x0B,
    Commands = 0x0E,
    CloseContainer = 0x0F,
    SetContainerContent = 0x10,
    SetContainerProperty = 0x11,
    SetContainerSlot = 0x12,
    PluginMessage = 0x15,
    DisconnectPlay = 0x17,
    EntityEvent = 0x19,
    UnloadChunk = 0x1b,
    GameEvent = 0x1c,
    InitializeWorldBorder = 0x1e,
    KeepAlive = 0x1F,
    ChunkDataAndLightUpdate = 0x20,
    WorldEvent = 0x21,
    LoginPlay = 0x24,
    UpdateEntityPosition = 0x27,
    UpdateEntityPositionRotation = 0x28,
    UpdateEntityRotation = 0x29,
    OpenScreen = 0x2c,
    PlayerAbilities = 0x30,
    PlayerChatMessage = 0x31,
    PlayerInfoRemove = 0x35,
    PlayerInfoUpdate = 0x36,
    SynchronizePlayerPosition = 0x38,
    UpdateRecipesBook = 0x39,
    RemoveEntities = 0x3A,
    Respawn = 0x3D,
    HeadRotation = 0x3E,
    UpdateSectionBlocks = 0x3F,
    ServerData = 0x41,
    SetHeldItem = 0x49,
    CenterChunk = 0x4a,
    SetDefaultSpawnPosition = 0x4c,
    DisplayObjective = 0x4d,
    SetEntityMetadata = 0x4e,
    EntityVelocity = 0x50,
    SetEquipment = 0x51,
    SetExperience = 0x52,
    Health = 0x53,
    UpdateObjective = 0x54,
    UpdateTeam = 0x56,
    UpdateScore = 0x57,
    SetSubtitleText = 0x59,
    UpdateTime = 0x5A,
    SetTitleText = 0x5B,
    SetTitleAnimationTimes = 0x5c,
    EntitySoundEffect = 0x5D,
    SoundEffect = 0x5E,
    StopSound = 0x5F,
    SystemChatMessage = 0x60,
    PickupItem = 0x63,
    TeleportEntity = 0x64,
    UpdateAdvancements = 0x65,
    UpdateAttributes = 0x66,
    FeatureFlags = 0x67,
    UpdateRecipes = 0x69,
    UpdateTags = 0x6A,
};

struct Disconnect {
    std::string reason;
};
std::unique_ptr<std::vector<uint8_t>> createLoginDisconnect(const Disconnect &);

struct EncryptionRequest {
    std::string serverID;
    std::vector<uint8_t> publicKey;
    std::vector<uint8_t> verifyToken;
};
std::unique_ptr<std::vector<uint8_t>> createEncryptionRequest(const EncryptionRequest &);

struct LoginSuccess {
    u128 uuid;
    std::string username;
    std::vector<PlayerProperty> properties;
};
std::unique_ptr<std::vector<uint8_t>> createLoginSuccess(const LoginSuccess &);

std::unique_ptr<std::vector<uint8_t>> createSetCompression(int32_t compressionTreshold);

struct StatusResponse {
    std::string payload;
};
std::unique_ptr<std::vector<uint8_t>> createStatusResponse(const StatusResponse &);

struct PingResponse {
    int64_t payload;
};
std::unique_ptr<std::vector<uint8_t>> createPingResponse(const PingResponse &);

struct SpawnEntity {
    int32_t entityId;
    u128 entityUuid;
    EntityType type;
    double x;
    double y;
    double z;
    uint8_t pitch;
    uint8_t yaw;
    uint8_t headYaw;
    int32_t data;
    int16_t velocityX;
    int16_t velocityY;
    int16_t velocityZ;
};
std::unique_ptr<std::vector<uint8_t>> createSpawnEntity(const SpawnEntity &);

struct SpawnPlayer {
    int32_t entityId;
    u128 playerUuid;
    double x;
    double y;
    double z;
    uint8_t yaw;
    uint8_t pitch;
};
std::unique_ptr<std::vector<uint8_t>> createSpawnPlayer(const SpawnPlayer &);

struct EntityAnimation {
    enum class ID : uint8_t {
        SwingMainArm = 0x00,
        TakeDamage = 0x01,
        LeaveBed = 0x02,
        SwingOffHand = 0x03,
        CriticalEffect = 0x04,
        MagicCriticalEffect = 0x05,
    } animId;
    int32_t entityId;
};
std::unique_ptr<std::vector<uint8_t>> createEntityAnimation(EntityAnimation::ID animId, int32_t entityID);

struct BlockEntityData {
    Position location;
    int32_t type;
    nbt_tag_t *nbtData;
};
std::unique_ptr<std::vector<uint8_t>> createBlockEntityData(const BlockEntityData &);

struct BlockUpdate {
    Position location;
    int32_t blockId;
};
std::unique_ptr<std::vector<uint8_t>> createBlockUpdate(const BlockUpdate &);

struct ChangeDifficultyClient {
    uint8_t difficulty;
    bool locked;
};
std::unique_ptr<std::vector<uint8_t>> createChangeDifficultyClient(const ChangeDifficultyClient &);

struct Commands {
    std::vector<int> nodes;
    int32_t rootIndex;
};
std::unique_ptr<std::vector<uint8_t>> createCommands(const Commands &);

struct CloseContainer {
    uint8_t windowId;
};
std::unique_ptr<std::vector<uint8_t>> createCloseContainer(const CloseContainer &);

struct SetContainerContent {
    const std::shared_ptr<container::Container> container;
};
std::unique_ptr<std::vector<uint8_t>> createSetContainerContent(const SetContainerContent &);

struct SetContainerProperty {
    uint8_t windowId;
    int16_t property;
    int16_t value;
};
std::unique_ptr<std::vector<uint8_t>> createSetContainerProperty(const SetContainerProperty &);

struct SetContainerSlot {
    SetContainerSlot(const std::shared_ptr<const container::Container> &container, int8_t containerId, int16_t slot):
        container(container),
        containerId(containerId),
        slot(slot)
    {
    }
    SetContainerSlot(const std::shared_ptr<const container::Container> &container, int16_t slot):
        container(container),
        containerId(container->id()),
        slot(slot)
    {
    }
    const std::shared_ptr<const container::Container> container;
    int8_t containerId;
    int16_t slot;
};
std::unique_ptr<std::vector<uint8_t>> createSetContainerSlot(const SetContainerSlot &);

struct PluginMessageResponse {
    std::string channel;
    std::vector<uint8_t> data;
};
std::unique_ptr<std::vector<uint8_t>> createPluginMessageResponse(const PluginMessageResponse &);

std::unique_ptr<std::vector<uint8_t>> createPlayDisconnect(const Disconnect &);

struct EntityEvent {
    int32_t entityId;
    uint8_t eventStatus;
};
std::unique_ptr<std::vector<uint8_t>> createEntityEvent(const EntityEvent &);

std::unique_ptr<std::vector<uint8_t>> createUnloadChunk(const Position2D &);

struct GameEvent {
    enum class Event : uint8_t {
        NoRespawnBlockAvailable,
        EndRaining,
        BeginRaining,
        ChangeGamemode,
        WinGame,
        DemoEvent,
        ArrowHitPlayer,
        RainLevelChange,
        ThunderLevelChange,
        PlayPufferfishStingSound,
        PlayElderGuardianMobAppearance,
        EnableRespawnScreen
    } event;
    float value;
};

std::unique_ptr<std::vector<uint8_t>> createGameEvent(const GameEvent &);
struct InitializeWorldBorder {
    double x;
    double z;
    double oldDiameter;
    double newDiameter;
    int64_t speed;
    int32_t portalTeleportBoundary;
    int32_t warningTime;
    int32_t warningBlocks;
};
std::unique_ptr<std::vector<uint8_t>> createInitializeWorldBorder(const InitializeWorldBorder &);

std::unique_ptr<std::vector<uint8_t>> createKeepAlive(long id);

// Only for chunk data and light update packet
struct ChunkDataAndLightUpdate {
    int32_t chunkX;
    int32_t chunkZ;
    // std::shared_ptr<nbt::Compound> heightmaps;
    const world_storage::ChunkColumn &data;
};
std::unique_ptr<std::vector<uint8_t>> createChunkDataAndLightUpdate(const ChunkDataAndLightUpdate &);

struct WorldEvent {
    enum class Event : int32_t {
        // Sound
        DispenserDispenses = 1000,
        DispenserFailsToDispense = 1001,
        DispenserShoots = 1002,
        EnderEyeLaunched = 1003,
        FireworkShot = 1004,
        IronDoorOpened = 1005,
        WoodenDoorOpened = 1006,
        WoodenTrapdoorOpened = 1007,
        FenceGateOpened = 1008,
        FireExtinguished = 1009,
        PlayRecord = 1010,
        IronDoorClosed = 1011,
        WoodenDoorClosed = 1012,
        WoodenTrapdoorClosed = 1013,
        FenceGateClosed = 1014,
        GhastWarns = 1015,
        GhastShoots = 1016,
        EnderdragonShoots = 1017,
        BlazeShoots = 1018,
        ZombieAttacksWoodDoor = 1019,
        ZombieAttacksIronDoor = 1020,
        ZombieBreaksWoodDoor = 1021,
        WitherBreaksBlock = 1022,
        WitherSpawned = 1023,
        WitherShoots = 1024,
        BatTakesOff = 1025,
        ZombieInfects = 1026,
        ZombieVillagerConverted = 1027,
        EnderDragonDeath = 1028,
        AnvilDestroyed = 1029,
        AnvilUsed = 1030,
        AnvilLanded = 1031,
        PortalTravel = 1032,
        ChorusFlowerGrown = 1033,
        ChorusFlowerDied = 1034,
        BrewingStandBrewed = 1035,
        IronTrapdoorOpened = 1036,
        IronTrapdoorClosed = 1037,
        EndPortalCreatedInOverworld = 1038,
        PhantomBites = 1039,
        ZombieConvertsToDrowned = 1040,
        HuskConvertsToZombieByDrowning = 1041,
        GrindstoneUsed = 1042,
        BookPageTurned = 1043,
        // Particle
        ComposterComposts = 1500,
        LavaConvertsBlock = 1501,
        RedstoneTorchBurnsOut = 1502,
        EnderEyePlaced = 1503,
        SpawnsTenSmokeParticles = 2000,
        BlockBreakAndBlockBreakSound = 2001,
        SplashPotion = 2002,
        EyeOfEnderEntityBreakAnimation = 2003,
        MobSpawnParticleEffect = 2004,
        BonemealParticles = 2005,
        DragonBreath = 2006,
        InstantSplashPotion = 2007,
        EnderDragonDestroysBlock = 2008,
        WetSpongeVaporizesInNether = 2009,
        EndGatewaySpawn = 3000,
        EnderdragonGrowl = 3001,
        ElectricSpark = 3002,
        CopperApplyWax = 3003,
        CopperRemoveWax = 3004,
        CopperScrapeOxidation = 3005,

    } event;
    Position position;
    int32_t data;
    bool disableRelativeVolume;
};
std::unique_ptr<std::vector<uint8_t>> createWorldEvent(const WorldEvent &);

struct LoginPlay {
    int32_t entityID;
    bool isHardcore;
    player_attributes::Gamemode gamemode;
    player_attributes::Gamemode previousGamemode; // must be a signed byte
    std::vector<std::string> dimensionNames;
    const std::shared_ptr<const nbt::Compound> &registryCodec;
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
    std::string deathDimensionName;
    Position deathLocation;
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

struct OpenScreen {
    int32_t id;
    int32_t type;
    const chat::Message &title;
};
std::unique_ptr<std::vector<uint8_t>> createOpenScreen(const OpenScreen &in);

struct PlayerAbilitiesClient {
    uint8_t flags;
    float flyingSpeed;
    float fieldOfViewModifier;
};
std::unique_ptr<std::vector<uint8_t>> createPlayerAbilities(const PlayerAbilitiesClient &in);

struct PlayerChatMessage {
    // Header
    u128 senderUUID;
    int32_t index;
    bool hasSignature;
    std::vector<uint8_t> signature;

    // Body
    std::string message;
    int64_t timestamp;
    int64_t salt;

    // Previous messages
    // A previous message is a message ID and the message signature
    std::vector<std::pair<int32_t, std::vector<uint8_t>>> previousMessages;

    // Other
    bool hasUnsignedContent;
    std::string unsignedContent;
    int32_t filterType;
    std::vector<int64_t> filterData;

    // Network
    int32_t chatType;
    std::string networkName;
    bool hasNetworkTargetName;
    std::string networkTargetName;
};
std::unique_ptr<std::vector<uint8_t>> createPlayerChatMessage(const PlayerChatMessage &);

struct PlayerInfoRemove {
    std::vector<u128> uuids;
};
std::unique_ptr<std::vector<uint8_t>> createPlayerInfoRemove(const PlayerInfoRemove &);

struct PlayerInfoUpdate {
    enum class Actions : uint8_t {
        AddPlayer = 0b00000001,
        InitializeChat = 0b00000010,
        UpdateGamemode = 0b00000100,
        UpdateListed = 0b00001000,
        UpdateLatency = 0b00010000,
        UpdateDisplayName = 0b00100000,
    };
    struct Action {
        u128 uuid;
        struct AddPlayer {
            std::string name;
            std::vector<PlayerProperty> properties;
        } addPlayer;

        struct InitializeChat {
            // TODO: Let Miki do it xd
            bool hasSigData;
        } initializeChat;

        struct UpdateGamemode {
            int32_t gamemode;
        } updateGamemode;

        struct UpdateListed {
            bool listed;
        } updateListed;

        struct UpdateLatency {
            int32_t latency;
        } updateLatency;

        struct UpdateDisplayName {
            bool hasDisplayName;
            std::string displayName;
        } updateDisplayName;
    };
    uint8_t actions;
    std::vector<Action> actionSets;
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

struct UpdateRecipesBook {
    int32_t action;
    bool craftingRecipeBookOpen;
    bool craftingRecipeBookFilterActive;
    bool smeltingRecipeBookOpen;
    bool smeltingRecipeBookFilterActive;
    bool blastFurnaceRecipeBookOpen;
    bool blastFurnaceRecipeBookFilterActive;
    bool smokerRecipeBookOpen;
    bool smokerRecipeBookFilterActive;
    std::vector<std::string> recipesId;
    std::vector<std::string> recipiesIdForInit;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateRecipesBook(const UpdateRecipesBook &);

struct RemoveEntities {
    std::vector<int32_t> entities;
};
std::unique_ptr<std::vector<uint8_t>> createRemoveEntities(const RemoveEntities &in);

struct Respawn {
    std::string dimensionType;
    std::string dimensionName;
    long hashedSeed;
    player_attributes::Gamemode gamemode;
    player_attributes::Gamemode previousGamemode;
    bool isDebug;
    bool isFlat;
    bool copyMetadata;
    bool hasDeathLocation;
    std::string deathDimensionName;
    Position deathLocation;
};
std::unique_ptr<std::vector<uint8_t>> createRespawn(const Respawn &in);

struct HeadRotation {
    int32_t entityID;
    uint8_t headYaw;
};
std::unique_ptr<std::vector<uint8_t>> createHeadRotation(const HeadRotation &in);

struct UpdateSectionBlock {
    const Position pos;
    const world_storage::ChunkColumn &chunkData;
    bool suppressLightUpdates;
    std::vector<std::pair<Position, BlockId>> blocks;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateSectionBlock(const UpdateSectionBlock &in);

struct ServerData {
    bool hasMotd;
    std::string motd;
    bool hasIcon;
    std::string icon;
    bool enforceSecureChat;
};
std::unique_ptr<std::vector<uint8_t>> createServerData(const ServerData &in);

struct SetHeldItemClient {
    uint8_t slot; // must be a byte
};
std::unique_ptr<std::vector<uint8_t>> createSetHeldItemClient(const SetHeldItemClient &);

std::unique_ptr<std::vector<uint8_t>> createCenterChunk(const Position2D &in);

struct SetDefaultSpawnPosition {
    Position position;
    float angle;
};
std::unique_ptr<std::vector<uint8_t>> createSetDefaultSpawnPosition(const SetDefaultSpawnPosition &);

struct DisplayObjective {
    uint8_t position;
    std::string name;
};
std::unique_ptr<std::vector<uint8_t>> createDisplayObjective(const DisplayObjective &);

std::unique_ptr<std::vector<uint8_t>> createSetEntityMetadata(const Entity &);

struct UpdateTime {
    long worldAge;
    long timeOfDay;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateTime(const UpdateTime &);

struct SetTitleText {
    chat::Message title;
};
std::unique_ptr<std::vector<uint8_t>> createSetTitleText(const SetTitleText &);

struct SetTitleAnimationTimes {
    int32_t fadeIn;
    int32_t stay;
    int32_t fadeOut;
};
std::unique_ptr<std::vector<uint8_t>> createSetTitleAnimationTimes(const SetTitleAnimationTimes &);

struct EntitySoundEffect {
    EntitySoundEffect(int32_t soundId, int32_t category, int32_t entityId, float volume, float pitch, long seed):
        soundId(soundId + 1), // see https://wiki.vg/index.php?title=Protocol&oldid=18067#Entity_Sound_Effect
        category(category),
        entityId(entityId),
        volume(volume),
        pitch(pitch),
        seed(seed)
    {
    }
    EntitySoundEffect(std::string soundName, bool hasFixedRange, float range, int32_t category, int32_t entityId, float volume, float pitch):
        soundId(0), // see https://wiki.vg/index.php?title=Protocol&oldid=18067#Entity_Sound_Effect
        soundName(soundName),
        hasFixedRange(hasFixedRange),
        range(range),
        category(category),
        entityId(entityId),
        volume(volume),
        pitch(pitch),
        seed(0)
    {
    }
    int32_t soundId;
    std::string soundName;
    bool hasFixedRange;
    float range;
    int32_t category;
    int32_t entityId;
    float volume;
    float pitch;
    long seed;
};
std::unique_ptr<std::vector<uint8_t>> createEntitySoundEffect(const EntitySoundEffect &);

struct SoundEffect {
    SoundEffect(int32_t soundId, int32_t category, int32_t x, int32_t y, int32_t z, float volume, float pitch, long seed):
        soundId(soundId + 1), // see https://wiki.vg/index.php?title=Protocol&oldid=18067#Entity_Sound_Effect
        category(category),
        x(x),
        y(y),
        z(z),
        volume(volume),
        pitch(pitch),
        seed(seed)
    {
    }
    SoundEffect(std::string soundName, bool hasFixedRange, float range, int32_t category, int32_t x, int32_t y, int32_t z, float volume, float pitch, long seed):
        soundId(0), // see https://wiki.vg/index.php?title=Protocol&oldid=18067#Entity_Sound_Effect
        soundName(soundName),
        hasFixedRange(hasFixedRange),
        range(range),
        category(category),
        x(x),
        y(y),
        z(z),
        volume(volume),
        pitch(pitch),
        seed(seed)
    {
    }
    int32_t soundId;
    std::string soundName;
    bool hasFixedRange;
    float range;
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

struct PickupItem {
    int32_t collectedEntityId;
    int32_t collectorEntityId;
    int32_t pickupItemCount;
};
std::unique_ptr<std::vector<uint8_t>> createPickupItem(const PickupItem &);

struct EntityVelocity {
    int32_t entityId;
    int16_t velocityX;
    int16_t velocityY;
    int16_t velocityZ;
};
std::unique_ptr<std::vector<uint8_t>> createEntityVelocity(const EntityVelocity &);

struct SetEquipment {
    int32_t entityId;
    enum class EquipmentPosition : int8_t {
        MainHand = 0,
        OffHand = 1,
        ArmorSlotBoots = 2,
        ArmorSlotLegs = 3,
        ArmorSlotChest = 4,
        ArmorSlotHelmet = 5,
    };
    std::vector<std::pair<EquipmentPosition, Slot>> equipment;
};
std::unique_ptr<std::vector<uint8_t>> createSetEquipment(const SetEquipment &);

struct SetExperience {
    float experienceBar;
    int32_t totalExperience;
    int32_t level;
};
std::unique_ptr<std::vector<uint8_t>> createSetExperience(const SetExperience &);

struct Health {
    float health;
    int32_t food;
    float foodSaturation;
};
std::unique_ptr<std::vector<uint8_t>> createHealth(const Health &);

struct UpdateObjectives {
    std::string name;
    uint8_t mode;
    chat::Message value;
    enum class Type : int32_t {
        Integers = 0,
        Hearts = 1
    } type;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateObjectives(const UpdateObjectives &);

struct UpdateTeams {
    std::string name;
    uint8_t mode;
    chat::Message displayName;
    uint8_t friendlyFalgs;
    std::string nameTagVisibility;
    std::string collisionRule;
    enum class Color : int32_t {
        Black = 0,
        DarkBlue = 1,
        DarkGreen = 2,
        DarkAqua = 3,
        DarkRed = 4,
        DarkPurple = 5,
        Gold = 6,
        Gray = 7,
        DarkGray = 8,
        Blue = 9,
        Green = 10,
        Aqua = 11,
        Red = 12,
        Pink = 13,
        Yellow = 14,
        White = 15,
        Obfuscated = 16,
        Bold = 17,
        StrikeThrough = 18,
        Underlined = 19,
        Italic = 20,
        Reset = 21
    } color;
    chat::Message prefix;
    chat::Message suffix;
    std::vector<std::string> entities;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateTeams(const UpdateTeams &);

struct UpdateScore {
    std::string name;
    int32_t action;
    std::string objective;
    int32_t value;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateScore(const UpdateScore &);

struct SetSubtitleText {
    chat::Message subtitle;
};
std::unique_ptr<std::vector<uint8_t>> createSetSubtitleText(const SetSubtitleText &);

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

struct UpdateAdvancements {
    struct AdvancementMapping {
        std::string identifier;
        struct Advancement {
            struct Criteria {
                std::string key;
                // std::string value;
            };
            bool hasParent;
            std::string parent;
            bool hasDisplay;
            struct Display {
                std::string title;
                std::string description;
                Slot icon;
                enum class FrameType : int32_t {
                    task = 0,
                    challenge = 1,
                    goal = 2,
                } frameType;
                enum class Flags : int32_t {
                    hasBackgroundTexture = 0x01,
                    showToast = 0x02,
                    hidden = 0x04,
                } flags;
                std::string backgroundTexture;
                float xCoord;
                float yCoord;
            } displayData;
            std::vector<Criteria> criteria;
            std::vector<std::vector<std::string>> requirements;
        } advancement;
    };
    struct ProgressMapping {
        struct CriteriaMapping {
            struct CriterionProgress {
                bool achived;
                long dateOfAchieving;
            };
            std::string identifier;
            CriterionProgress criteria;
        };
        std::string identifier;
        std::vector<CriteriaMapping> advancementProgress;
    };
    bool resetOrClear;
    std::vector<AdvancementMapping> advancementMapping;
    std::vector<std::string> identifiers;
    std::vector<ProgressMapping> progressMapping;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateAdvancements(const UpdateAdvancements &);

struct UpdateAttributes {
    struct Property {
        struct Modifier {
            u128 uuid;
            double amount;
            enum class Operation : uint8_t {
                AddSubstractAmount = 0,
                AddSubstractAmountPercent = 1,
                MultiplyByAmountPercent = 2,
            } operation;
        };
        std::string key;
        std::string value;
        std::vector<Modifier> modifiers;
    };
    int32_t entityId;
    std::vector<Property> attributes;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateAttributes(const UpdateAttributes &);

struct FeatureFlags {
    std::vector<std::string> flags;
};
std::unique_ptr<std::vector<uint8_t>> createFeatureFlags(const FeatureFlags &in);

struct UpdateRecipes {
    std::vector<int> recipes;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateRecipes(const UpdateRecipes &);

struct UpdateTags {
    std::vector<int> tags;
};
std::unique_ptr<std::vector<uint8_t>> createUpdateTags(const UpdateTags &);
}

#endif // CUBICSERVER_PROTOCOL_CLIENTPACKETS_HPP
