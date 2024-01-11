#ifndef CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP
#define CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP

#include "types.hpp"
#include <array>
#include <memory>
#include <string>

namespace tile_entity {
enum class TileEntityType : int {
    UnknownType = -1,
    Furnace = 0,
    Chest = 1,
    TrappedChest = 2,
    EnderChest = 3,
    Jukebox = 4,
    Dispenser = 5,
    Dropper = 6,
    Sign = 7,
    HangingSign = 8,
    Spawner = 9,
    MovingPiston = 10,
    BrewingStand = 11,
    EnchantingTable = 12,
    EndPortal = 13,
    Beacon = 14,
    Skull = 15,
    DaylightDetector = 16,
    Hopper = 17,
    Comparator = 18,
    Banner = 19,
    StructureBlock = 20,
    EndGateway = 21,
    CommandBlock = 22,
    ShulkerBox = 23,
    Bed = 24,
    Conduit = 25,
    Barrel = 26,
    Smoker = 27,
    BlastFurnace = 28,
    Lectern = 29,
    Bell = 30,
    Jigsaw = 31,
    Campfire = 32,
    Beehive = 33,
    SculkSensor = 34,
    SculkCatalyst = 35,
    SculkShrieker = 36,
    ChiseledBookshelf = 37,
};

constexpr TileEntityType convertBlockNameToBlockEntityType(const std::string &name)
{
    if (name.find("bee") != std::string::npos)
        return TileEntityType::Beehive;
    if (name.find("hanging_sign") != std::string::npos)
        return TileEntityType::HangingSign;
    if (name.find("sign") != std::string::npos)
        return TileEntityType::Sign;
    if (name.find("sculk_sensor") != std::string::npos)
        return TileEntityType::SculkSensor;
    if (name.find("sculk_catalyst") != std::string::npos)
        return TileEntityType::SculkCatalyst;
    if (name.find("sculk_shrieker") != std::string::npos)
        return TileEntityType::SculkShrieker;
    if (name.find("banner") != std::string::npos)
        return TileEntityType::Banner;
    if (name.find("trapped_chest") != std::string::npos)
        return TileEntityType::TrappedChest;
    if (name.find("ender_chest") != std::string::npos)
        return TileEntityType::EnderChest;
    if (name.find("chest") != std::string::npos)
        return TileEntityType::Chest;
    if (name.find("dispenser") != std::string::npos)
        return TileEntityType::Dispenser;
    if (name.find("furnace") != std::string::npos)
        return TileEntityType::Furnace;
    if (name.find("brewing_stand") != std::string::npos)
        return TileEntityType::BrewingStand;
    if (name.find("hopper") != std::string::npos)
        return TileEntityType::Hopper;
    if (name.find("dropper") != std::string::npos)
        return TileEntityType::Dropper;
    if (name.find("shulker_box") != std::string::npos)
        return TileEntityType::ShulkerBox;
    if (name.find("barrel") != std::string::npos)
        return TileEntityType::Barrel;
    if (name.find("smoker") != std::string::npos)
        return TileEntityType::Smoker;
    if (name.find("blast_furnace") != std::string::npos)
        return TileEntityType::BlastFurnace;
    if (name.find("campfire") != std::string::npos)
        return TileEntityType::Campfire;
    if (name.find("lectern") != std::string::npos)
        return TileEntityType::Lectern;
    if (name.find("chiseled_bookshelf") != std::string::npos)
        return TileEntityType::ChiseledBookshelf;
    if (name.find("beacon") != std::string::npos)
        return TileEntityType::Beacon;
    if (name.find("spawner") != std::string::npos)
        return TileEntityType::Spawner;
    if (name.find("moving_piston") != std::string::npos)
        return TileEntityType::MovingPiston;
    if (name.find("jukebox") != std::string::npos)
        return TileEntityType::Jukebox;
    if (name.find("enchanting_table") != std::string::npos)
        return TileEntityType::EnchantingTable;
    if (name.find("end_portal") != std::string::npos)
        return TileEntityType::EndPortal;
    if (name.find("skull") != std::string::npos || name.find("head") != std::string::npos)
        return TileEntityType::Skull;
    if (name.find("command_block") != std::string::npos)
        return TileEntityType::CommandBlock;
    if (name.find("end_gateway") != std::string::npos)
        return TileEntityType::EndGateway;
    if (name.find("structure_block") != std::string::npos)
        return TileEntityType::StructureBlock;
    if (name.find("jigsaw") != std::string::npos)
        return TileEntityType::Jigsaw;
    if (name.find("daylight_detector") != std::string::npos)
        return TileEntityType::DaylightDetector;
    if (name.find("comparator") != std::string::npos)
        return TileEntityType::Comparator;
    if (name.find("bed") != std::string::npos)
        return TileEntityType::Bed;
    if (name.find("conduit") != std::string::npos)
        return TileEntityType::Conduit;
    if (name.find("bell") != std::string::npos)
        return TileEntityType::Bell;
    return TileEntityType::UnknownType;
};

class TileEntity;
}

namespace tile_entity {
std::shared_ptr<tile_entity::TileEntity> createTileEntity(BlockId blockId, Position position);
}

#endif // CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP
