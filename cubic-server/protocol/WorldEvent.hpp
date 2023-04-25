#ifndef CUBICSERVER_PROTOCOL_WORLDEVENT_HPP
#define CUBICSERVER_PROTOCOL_WORLDEVENT_HPP

#include <cstdint>

namespace protocol {
enum class WorldEventSound : int32_t {
    DispenserDispense = 1000,
    DispenserFail = 1001,
    DispenserLaunch = 1002,
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
    BookPageTurned = 1043
};

enum class WorldEventParticle : int32_t {
    ComposterComposts = 1500,
    LavaConvertsBlock = 1501, // (either water to stone, or removes existing blocks such as torches)
    RedstoneTorchBurnsOut = 1502,
    EnderEyePlaced = 1503,
    SpawnsSmokeParticles = 2000,
    BlockBreakAndBlockBreakSound = 2001,
    SplashPotion = 2002, // RGB color as an integer (e.g. 8364543 for #7FA1FF).
    EyeOfEnderEntityBreakAnimation = 2003,
    MobSpawn = 2004, // particle effect: smoke + flames
    Bonemeal = 2005, // How many particles to spawn (if set to 0, 15 are spawned).
    DragonBreath = 2006,
    InstantSplashPotion = 2007, // RGB color as an integer (e.g. 8364543 for #7FA1FF).
    EnderDragonDestroysBlock = 2008,
    WetSpongeVaporizesInNether = 2009,
    EndGatewaySpawn = 3000,
    EnderdragonGrowl = 3001,
    ElectricSpark = 3002,
    CopperApplyWax = 3003,
    CopperRemoveWax = 3004,
    CopperScrapeOxidation = 3005,
};

enum class RecordId : int32_t { // TODO: Change each enum field to PascalCase
    // sound_event
    // 11 =  680,
    // 13 =  681,
    // 5 =  679,
    // blocks =  682,
    // cat =  683,
    // chirp =  684,
    // far =  685,
    // mall =  686,
    // mellohi =  687,
    // otherside =  693,
    // pigstep =  688,
    // stal =  689,
    // strad =  690,
    // wait =  691

    // item
    eleven = 1068,
    thirteen = 1058,
    five = 1071,
    blocks = 1060,
    cat = 1059,
    chirp = 1061,
    far = 1062,
    mall = 1063,
    mellohi = 1064,
    otherside = 1070,
    pigstep = 1072,
    stal = 1065,
    strad = 1066,
    wait = 1069,
    ward = 1067
};
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_WORLDEVENT_HPP
