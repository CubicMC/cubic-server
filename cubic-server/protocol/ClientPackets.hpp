#ifndef CUBICSERVER_PROTOCOL_CLIENTPACKETS_HPP
#define CUBICSERVER_PROTOCOL_CLIENTPACKETS_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "PlayerAttributes.hpp"
#include "Structures.hpp"
#include "common.hpp"
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
    SpawnEntity = 0x00,
    SpawnPlayer = 0x02,
    EntityAnimation = 0x03,
    BlockUpdate = 0x09,
    ChangeDifficulty = 0x0B,
    Commands = 0x0E,
    SetContainerContent = 0x10,
    PluginMessage = 0x15,
    // CustomSoundEffect = 0x16, TODO: This is removed in the last revision of wiki.vg
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
    PlayerAbilities = 0x30,
    PlayerChatMessage = 0x31,
    PlayerInfoRemove = 0x35,
    PlayerInfoUpdate = 0x36,
    SynchronizePlayerPosition = 0x38,
    UpdateRecipesBook = 0x39,
    RemoveEntities = 0x3A,
    HeadRotation = 0x3E,
    ServerData = 0x41,
    SetHeldItem = 0x49,
    CenterChunk = 0x4a,
    SetDefaultSpawnPosition = 0x4c,
    // SetEntityMetadata = 0x4e, HAHA LOL
    EntityVelocity = 0x50,
    SetExperience = 0x52,
    Health = 0x53,
    UpdateTime = 0x5A,
    EntitySoundEffect = 0x5D,
    SoundEffect = 0x5E,
    StopSound = 0x5F,
    SystemChatMessage = 0x60,
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

struct LoginSuccess {
    struct Property {
        std::string name;
        std::string value;
        bool isSigned;
        std::string signature;
    };
    u128 uuid;
    std::string username;
    int32_t numberOfProperties;
    std::vector<Property> properties;
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

struct SpawnEntity {
    int32_t entityId;
    u128 entityUuid;
    enum class EntityType : int32_t {
        Allay = 0,
        AreaEffectCloud = 1,
        ArmorStand = 2,
        Arrow = 3,
        Axolotl = 4,
        Bat = 5,
        Bee = 6,
        Blaze = 7,
        // BlockDisplay = 8,
        Boat = 8,
        ChestBoat = 9,
        Cat = 10,
        Camel = 11, // update_1_20
        CaveSpider = 12,
        Chicken = 13,
        Cod = 14,
        Cow = 15,
        Creeper = 16,
        Dolphin = 17,
        Donkey = 18,
        DragonFireball = 19,
        Drowned = 20,
        ElderGuardian = 21,
        EndCrystal = 22,
        EnderDragon = 23,
        Enderman = 24,
        Endermite = 25,
        Evoker = 26,
        EvokerFangs = 27,
        ExperienceOrb = 28, // SpawnExperienceOrb
        EyeOfEnder = 29,
        FallingBlock = 30,
        FireworkRocket = 31,
        Fox = 32,
        Frog = 33,
        Ghast = 34,
        Giant = 35,
        GlowItemFrame = 36,
        GlowSquid = 37,
        Goat = 38,
        Guardian = 39,
        Hoglin = 40,
        Horse = 41,
        Husk = 42,
        Illusioner = 43,
        IronGolem = 44,
        Item = 45,
        ItemFrame = 46,
        Fireball = 47,
        LeashKnot = 48,
        LightningBolt = 49,
        Llama = 50,
        LlamaSpit = 51,
        MagmaCube = 52,
        // Interaction = 52,  // 1.19.4
        Marker = 53, // Not spawnable
        Minecart = 54,
        ChestMinecart = 55,
        // ItemDisplay = 55,  // 1.19.4
        CommandBlockMinecart = 56,
        FurnaceMinecart = 57,
        HopperMinecart = 58,
        SpawnerMinecart = 59,
        TntMinecart = 60,
        Mule = 61,
        Mooshroom = 62,
        Ocelot = 63,
        Painting = 64,
        Panda = 65,
        Parrot = 66,
        Phantom = 67,
        Pig = 68,
        Piglin = 69,
        PiglinBrute = 70,
        Pillager = 71,
        PolarBear = 72,
        Tnt = 73,
        Pufferfish = 74,
        Rabbit = 75,
        Ravager = 76,
        Salmon = 77,
        Sheep = 78,
        Shulker = 79,
        ShulkerBullet = 80,
        Silverfish = 81,
        Skeleton = 82,
        SkeletonHorse = 83,
        Slime = 84,
        SmallFireball = 85,
        SnowGolem = 86,
        Snowball = 87,
        SpectralArrow = 88,
        Spider = 89,
        Squid = 90,
        // Sniffer = 90,         // update_1_20
        Stray = 91,
        Strider = 92,
        Tadpole = 93,
        Egg = 94,
        EnderPearl = 95,
        ExperienceBottle = 96,
        Potion = 97,
        Trident = 98,
        TraderLlama = 99,
        // TextDisplay = 100,   // 1.19.4
        TropicalFish = 100,
        Turtle = 101,
        Vex = 102,
        Villager = 103,
        Vindicaton = 104,
        WanderingTrader = 105,
        Warden = 106,
        Witch = 107,
        Wither = 108,
        WitherSkeleton = 109,
        WitherSkull = 110,
        Wolf = 111,
        Zoglin = 112,
        Zombie = 113,
        ZombieHorse = 114,
        ZombieVillager = 115,
        ZombifiedPiglin = 116,
        Player = 117, // SpawnPlayer
        FishingBobber = 118,
    } type;
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

struct SetContainerContent {
    uint8_t windowId;
    int32_t stateId;
    std::vector<Slot> slotData;
    Slot carriedItem;
};
std::unique_ptr<std::vector<uint8_t>> createSetContainerContent(const SetContainerContent &);

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
    std::shared_ptr<nbt::Compound> registryCodec;
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

struct PlayerAbilitiesClient {
    enum Flags : uint8_t {
        Invulnerable = 0x01,
        Flying = 0x02,
        AllowFlying = 0x04,
        CreativeMode = 0x08
    };
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
            struct Property {
                std::string name;
                std::string value;
                bool isSigned;
                std::string signature;
            };
            std::string name;
            std::vector<Property> properties;
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

struct HeadRotation {
    int32_t entityID;
    uint8_t headYaw;
};
std::unique_ptr<std::vector<uint8_t>> createHeadRotation(const HeadRotation &in);

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

// struct SetEntityMetadata {
//     struct EntityMetadata {
//         uint8_t index;
//         enum class Type : int32_t {
//             Byte = 0,
//             VarInt = 1,
//             VarLong = 2,
//             Float = 3,
//             String = 4,
//             Chat = 5,
//             OptChat = 6,
//             Slot = 7,
//             Boolean = 8,
//             Rotation = 9,
//             Position = 10,
//             OptPosition = 11,
//             Direction = 12,
//             OptUUID = 13,
//             BlockID = 14,
//             OptBlockID = 15,
//             NBT = 16,
//             Particle = 17,
//             VillagerData = 18,
//             OptVarInt = 19,
//             Pose = 20,
//             CatVariant = 21,
//             FrogVariant = 22,
//             OptGlobalPos = 23,
//             PaintingVariant = 24,
//             SnifferState = 25,
//             Vector3 = 26,
//             Quaternion = 27,
//         } type;
//         // TODO: value GLHF;
//     };
//     int32_t entityId;
//     std::vector<EntityMetadata> metadata;
// };
// std::unique_ptr<std::vector<uint8_t>> createSetEntityMetadata(const SetEntityMetadata &);

struct UpdateTime {
    long worldAge;
    long timeOfDay;
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
    int32_t entityId;
    int16_t velocityX;
    int16_t velocityY;
    int16_t velocityZ;
};
std::unique_ptr<std::vector<uint8_t>> createEntityVelocity(const EntityVelocity &);

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
