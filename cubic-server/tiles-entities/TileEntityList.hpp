#ifndef CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP
#define CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP

#include <array>
#include <string>

const std::array<std::string, 155> tileEntityNameList {
    "beehive",
    "bee_nest",
    "oak_sign",
    "spruce_sign",
    "birch_sign",
    "acacia_sign",
    "jungle_sign",
    "dark_oak_sign",
    "mangrove_sign",
    "bamboo_sign",
    "oak_wall_sign",
    "spruce_wall_sign",
    "birch_wall_sign",
    "acacia_wall_sign",
    "jungle_wall_sign",
    "dark_oak_wall_sign",
    "mangrove_wall_sign",
    "bamboo_wall_sign",
    "oak_hanging_sign",
    "spruce_hanging_sign",
    "birch_hanging_sign",
    "acacia_hanging_sign",
    "jungle_hanging_sign",
    "dark_oak_hanging_sign",
    "crimson_hanging_sign",
    "warped_hanging_sign",
    "mangrove_hanging_sign",
    "bamboo_hanging_sign",
    "oak_wall_hanging_sign",
    "spruce_wall_hanging_sign",
    "birch_wall_hanging_sign",
    "acacia_wall_hanging_sign",
    "jungle_wall_hanging_sign",
    "dark_oak_wall_hanging_sign",
    "mangrove_wall_hanging_sign",
    "crimson_wall_hanging_sign",
    "warped_wall_hanging_sign",
    "bamboo_wall_hanging_sign",
    "crimson_sign",
    "warped_sign",
    "crimson_wall_sign",
    "warped_wall_sign",
    "sculk_sensor",
    "sculk_catalyst"
    "sculk_shrieker",
    "white_banner",
    "orange_banner",
    "magenta_banner",
    "light_blue_banner",
    "yellow_banner",
    "lime_banner",
    "pink_banner",
    "gray_banner",
    "light_gray_banner",
    "cyan_banner",
    "purple_banner",
    "blue_banner",
    "brown_banner",
    "green_banner",
    "red_banner",
    "black_banner",
    "white_wall_banner",
    "orange_wall_banner",
    "magenta_wall_banner",
    "light_blue_wall_banner",
    "yellow_wall_banner",
    "lime_wall_banner",
    "pink_wall_banner",
    "gray_wall_banner",
    "light_gray_wall_banner",
    "cyan_wall_banner",
    "purple_wall_banner",
    "blue_wall_banner",
    "brown_wall_banner",
    "green_wall_banner",
    "red_wall_banner",
    "black_wall_banner",
    "chest",
    "trapped_chest",
    "dispenser",
    "furnace",
    "brewing_stand",
    "hopper",
    "dropper",
    "shulker_box",
    "white_shulker_box",
    "orange_shulker_box",
    "magenta_shulker_box",
    "light_blue_shulker_box",
    "yellow_shulker_box",
    "lime_shulker_box",
    "pink_shulker_box",
    "gray_shulker_box",
    "light_gray_shulker_box",
    "cyan_shulker_box",
    "purple_shulker_box",
    "blue_shulker_box",
    "brown_shulker_box",
    "green_shulker_box",
    "red_shulker_box",
    "black_shulker_box",
    "barrel",
    "smoker",
    "blast_furnace",
    "campfire",
    "soul_campfire",
    "lectern",
    "chiseled_bookshelf",
    "beacon",
    "spawner",
    "moving_piston",
    "jukebox",
    "enchanting_table",
    "end_portal",
    "ender_chest",
    "skeleton_skull",
    "skeleton_wall_skull",
    "wither_skeleton_skull",
    "wither_skeleton_wall_skull",
    "zombie_head",
    "zombie_wall_head",
    "player_head",
    "player_wall_head",
    "creeper_head",
    "creeper_wall_head",
    "dragon_head",
    "dragon_wall_head",
    "piglin_head",
    "piglin_wall_head",
    "command_block",
    "repeating_command_block",
    "chain_command_block",

    "end_gateway",
    "structure_block",
    "jigsaw",
    "daylight_detector",
    "comparator",
    "white_bed",
    "orange_bed",
    "magenta_bed",
    "light_blue_bed",
    "yellow_bed",
    "lime_bed",
    "pink_bed",
    "gray_bed",
    "light_gray_bed",
    "cyan_bed",
    "purple_bed",
    "blue_bed",
    "brown_bed",
    "green_bed",
    "red_bed",
    "black_bed",
    "conduit",
    "bell",
};

constexpr int convertBlockNameToBlockEntityType(const std::string &name)
{
    if (name.find("bee") != std::string::npos)
        return 33;
    if (name.find("hanging_sign") != std::string::npos)
        return 8;
    if (name.find("sign") != std::string::npos)
        return 7;
    if (name.find("sculk_sensor") != std::string::npos)
        return 34;
    if (name.find("sculk_catalyst") != std::string::npos)
        return 35;
    if (name.find("sculk_shrieker") != std::string::npos)
        return 36;
    if (name.find("banner") != std::string::npos)
        return 19;
    if (name.find("trapped_chest") != std::string::npos)
        return 2;
    if (name.find("ender_chest") != std::string::npos)
        return 3;
    if (name.find("chest") != std::string::npos)
        return 1;
    if (name.find("dispenser") != std::string::npos)
        return 5;
    if (name.find("furnace") != std::string::npos)
        return 0;
    if (name.find("brewing_stand") != std::string::npos)
        return 11;
    if (name.find("hopper") != std::string::npos)
        return 17;
    if (name.find("dropper") != std::string::npos)
        return 6;
    if (name.find("shulker_box") != std::string::npos)
        return 23;
    if (name.find("barrel") != std::string::npos)
        return 26;
    if (name.find("smoker") != std::string::npos)
        return 27;
    if (name.find("blast_furnace") != std::string::npos)
        return 28;
    if (name.find("campfire") != std::string::npos)
        return 32;
    if (name.find("lectern") != std::string::npos)
        return 29;
    if (name.find("chiseled_bookshelf") != std::string::npos)
        return 37;
    if (name.find("beacon") != std::string::npos)
        return 14;
    if (name.find("spawner") != std::string::npos)
        return 9;
    if (name.find("moving_piston") != std::string::npos)
        return 10;
    if (name.find("jukebox") != std::string::npos)
        return 4;
    if (name.find("enchanting_table") != std::string::npos)
        return 12;
    if (name.find("end_portal") != std::string::npos)
        return 13;
    if (name.find("skull") != std::string::npos || name.find("head") != std::string::npos)
        return 15;
    if (name.find("command_block") != std::string::npos)
        return 22;
    if (name.find("end_gateway") != std::string::npos)
        return 21;
    if (name.find("structure_block") != std::string::npos)
        return 20;
    if (name.find("jigsaw") != std::string::npos)
        return 31;
    if (name.find("daylight_detector") != std::string::npos)
        return 16;
    if (name.find("comparator") != std::string::npos)
        return 18;
    if (name.find("bed") != std::string::npos)
        return 24;
    if (name.find("conduit") != std::string::npos)
        return 25;
    if (name.find("bell") != std::string::npos)
        return 30;
    return -1;
};

#endif // CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP
