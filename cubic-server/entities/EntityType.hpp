#ifndef CUBICSERVER_ENTITIES_ENTITY_TYPE_HPP
#define CUBICSERVER_ENTITIES_ENTITY_TYPE_HPP

#include <cstdint>
#include <string>

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
};

inline std::string getEntityTypeName(EntityType type)
{
    switch (type) {
    case EntityType::Allay:
        return "minecraft:allay";
    case EntityType::AreaEffectCloud:
        return "minecraft:area_effect_cloud";
    case EntityType::ArmorStand:
        return "minecraft:armor_stand";
    case EntityType::Arrow:
        return "minecraft:arrow";
    case EntityType::Axolotl:
        return "minecraft:axolotl";
    case EntityType::Bat:
        return "minecraft:bat";
    case EntityType::Bee:
        return "minecraft:bee";
    case EntityType::Blaze:
        return "minecraft:blaze";
    case EntityType::Boat:
        return "minecraft:boat";
    case EntityType::ChestBoat:
        return "minecraft:chest_boat";
    case EntityType::Cat:
        return "minecraft:cat";
    case EntityType::Camel:
        return "minecraft:camel";
    case EntityType::CaveSpider:
        return "minecraft:cave_spider";
    case EntityType::Chicken:
        return "minecraft:chicken";
    case EntityType::Cod:
        return "minecraft:cod";
    case EntityType::Cow:
        return "minecraft:cow";
    case EntityType::Creeper:
        return "minecraft:creeper";
    case EntityType::Dolphin:
        return "minecraft:dolphin";
    case EntityType::Donkey:
        return "minecraft:donkey";
    case EntityType::DragonFireball:
        return "minecraft:dragon_fireball";
    case EntityType::Drowned:
        return "minecraft:drowned";
    case EntityType::ElderGuardian:
        return "minecraft:elder_guardian";
    case EntityType::EndCrystal:
        return "minecraft:end_crystal";
    case EntityType::EnderDragon:
        return "minecraft:ender_dragon";
    case EntityType::Enderman:
        return "minecraft:enderman";
    case EntityType::Endermite:
        return "minecraft:endermite";
    case EntityType::Evoker:
        return "minecraft:evoker";
    case EntityType::EvokerFangs:
        return "minecraft:evoker_fangs";
    case EntityType::ExperienceOrb:
        return "minecraft:experience_orb";
    case EntityType::EyeOfEnder:
        return "minecraft:eye_of_ender";
    case EntityType::FallingBlock:
        return "minecraft:falling_block";
    case EntityType::FireworkRocket:
        return "minecraft:firework_rocket";
    case EntityType::Fox:
        return "minecraft:fox";
    case EntityType::Frog:
        return "minecraft:frog";
    case EntityType::Ghast:
        return "minecraft:ghast";
    case EntityType::Giant:
        return "minecraft:giant";
    case EntityType::GlowItemFrame:
        return "minecraft:glow_item_frame";
    case EntityType::GlowSquid:
        return "minecraft:glow_squid";
    case EntityType::Goat:
        return "minecraft:goat";
    case EntityType::Guardian:
        return "minecraft:guardian";
    case EntityType::Hoglin:
        return "minecraft:hoglin";
    case EntityType::Horse:
        return "minecraft:horse";
    case EntityType::Husk:
        return "minecraft:husk";
    case EntityType::Illusioner:
        return "minecraft:illusioner";
    case EntityType::IronGolem:
        return "minecraft:iron_golem";
    case EntityType::Item:
        return "minecraft:item";
    case EntityType::ItemFrame:
        return "minecraft:item_frame";
    case EntityType::Fireball:
        return "minecraft:fireball";
    case EntityType::LeashKnot:
        return "minecraft:leash_knot";
    case EntityType::LightningBolt:
        return "minecraft:lightning_bolt";
    case EntityType::Llama:
        return "minecraft:llama";
    case EntityType::LlamaSpit:
        return "minecraft:llama_spit";
    case EntityType::MagmaCube:
        return "minecraft:magma_cube";
    case EntityType::Marker:
        return "minecraft:marker";
    case EntityType::Minecart:
        return "minecraft:minecart";
    case EntityType::ChestMinecart:
        return "minecraft:chest_minecart";
    case EntityType::CommandBlockMinecart:
        return "minecraft:command_block_minecart";
    case EntityType::FurnaceMinecart:
        return "minecraft:furnace_minecart";
    case EntityType::HopperMinecart:
        return "minecraft:hopper_minecart";
    case EntityType::SpawnerMinecart:
        return "minecraft:spawner_minecart";
    case EntityType::TntMinecart:
        return "minecraft:tnt_minecart";
    case EntityType::Mule:
        return "minecraft:mule";
    case EntityType::Mooshroom:
        return "minecraft:mooshroom";
    case EntityType::Ocelot:
        return "minecraft:ocelot";
    case EntityType::Painting:
        return "minecraft:painting";
    case EntityType::Panda:
        return "minecraft:panda";
    case EntityType::Parrot:
        return "minecraft:parrot";
    case EntityType::Phantom:
        return "minecraft:phantom";
    case EntityType::Pig:
        return "minecraft:pig";
    case EntityType::Piglin:
        return "minecraft:piglin";
    case EntityType::PiglinBrute:
        return "minecraft:piglin_brute";
    case EntityType::Pillager:
        return "minecraft:pillager";
    case EntityType::PolarBear:
        return "minecraft:polar_bear";
    case EntityType::Tnt:
        return "minecraft:tnt";
    case EntityType::Pufferfish:
        return "minecraft:pufferfish";
    case EntityType::Rabbit:
        return "minecraft:rabbit";
    case EntityType::Ravager:
        return "minecraft:ravager";
    case EntityType::Salmon:
        return "minecraft:salmon";
    case EntityType::Sheep:
        return "minecraft:sheep";
    case EntityType::Shulker:
        return "minecraft:shulker";
    case EntityType::ShulkerBullet:
        return "minecraft:shulker_bullet";
    case EntityType::Silverfish:
        return "minecraft:silverfish";
    case EntityType::Skeleton:
        return "minecraft:skeleton";
    case EntityType::SkeletonHorse:
        return "minecraft:skeleton_horse";
    case EntityType::Slime:
        return "minecraft:slime";
    case EntityType::SmallFireball:
        return "minecraft:small_fireball";
    case EntityType::SnowGolem:
        return "minecraft:snow_golem";
    case EntityType::Snowball:
        return "minecraft:snowball";
    case EntityType::SpectralArrow:
        return "minecraft:spectral_arrow";
    case EntityType::Spider:
        return "minecraft:spider";
    case EntityType::Squid:
        return "minecraft:squid";
    case EntityType::Stray:
        return "minecraft:stray";
    case EntityType::Strider:
        return "minecraft:strider";
    case EntityType::Tadpole:
        return "minecraft:tadpole";
    case EntityType::Egg:
        return "minecraft:egg";
    case EntityType::EnderPearl:
        return "minecraft:ender_pearl";
    case EntityType::ExperienceBottle:
        return "minecraft:experience_bottle";
    case EntityType::Potion:
        return "minecraft:potion";
    case EntityType::Trident:
        return "minecraft:trident";
    case EntityType::TraderLlama:
        return "minecraft:trader_llama";
    case EntityType::TropicalFish:
        return "minecraft:tropical_fish";
    case EntityType::Turtle:
        return "minecraft:turtle";
    case EntityType::Vex:
        return "minecraft:vex";
    case EntityType::Villager:
        return "minecraft:villager";
    case EntityType::Vindicaton:
        return "minecraft:vindicaton";
    case EntityType::WanderingTrader:
        return "minecraft:wandering_trader";
    case EntityType::Warden:
        return "minecraft:warden";
    case EntityType::Witch:
        return "minecraft:witch";
    case EntityType::Wither:
        return "minecraft:wither";
    case EntityType::WitherSkeleton:
        return "minecraft:wither_skeleton";
    case EntityType::WitherSkull:
        return "minecraft:wither_skull";
    case EntityType::Wolf:
        return "minecraft:wolf";
    case EntityType::Zoglin:
        return "minecraft:zoglin";
    case EntityType::Zombie:
        return "minecraft:zombie";
    case EntityType::ZombieHorse:
        return "minecraft:zombie_horse";
    case EntityType::ZombieVillager:
        return "minecraft:zombie_villager";
    case EntityType::ZombifiedPiglin:
        return "minecraft:zombified_piglin";
    case EntityType::Player:
        return "minecraft:player";
    case EntityType::FishingBobber:
        return "minecraft:fishing_bobber";
    default:
        return "minecraft:unknown";
    }
}

#endif // CUBICSERVER_ENTITIES_ENTITY_TYPE_HPP
