#ifndef CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP
#define CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP

#include "types.hpp"
#include <array>
#include <memory>
#include <string>
#include <string_view>

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

static constexpr std::array<std::pair<std::string_view, TileEntityType>, 39> tileEntityNamesToTypes = {
    std::pair<std::string_view, TileEntityType> {"bee", TileEntityType::Beehive},
    std::pair<std::string_view, TileEntityType> {"hanging_sign", TileEntityType::HangingSign},
    std::pair<std::string_view, TileEntityType> {"sign", TileEntityType::Sign},
    std::pair<std::string_view, TileEntityType> {"sculk_sensor", TileEntityType::SculkSensor},
    std::pair<std::string_view, TileEntityType> {"sculk_catalyst", TileEntityType::SculkCatalyst},
    std::pair<std::string_view, TileEntityType> {"sculk_shrieker", TileEntityType::SculkShrieker},
    std::pair<std::string_view, TileEntityType> {"banner", TileEntityType::Banner},
    std::pair<std::string_view, TileEntityType> {"trapped_chest", TileEntityType::TrappedChest},
    std::pair<std::string_view, TileEntityType> {"ender_chest", TileEntityType::EnderChest},
    std::pair<std::string_view, TileEntityType> {"chest", TileEntityType::Chest},
    std::pair<std::string_view, TileEntityType> {"dispenser", TileEntityType::Dispenser},
    std::pair<std::string_view, TileEntityType> {"furnace", TileEntityType::Furnace},
    std::pair<std::string_view, TileEntityType> {"brewing_stand", TileEntityType::BrewingStand},
    std::pair<std::string_view, TileEntityType> {"hopper", TileEntityType::Hopper},
    std::pair<std::string_view, TileEntityType> {"dropper", TileEntityType::Dropper},
    std::pair<std::string_view, TileEntityType> {"shulker_box", TileEntityType::ShulkerBox},
    std::pair<std::string_view, TileEntityType> {"barrel", TileEntityType::Barrel},
    std::pair<std::string_view, TileEntityType> {"smoker", TileEntityType::Smoker},
    std::pair<std::string_view, TileEntityType> {"blast_furnace", TileEntityType::BlastFurnace},
    std::pair<std::string_view, TileEntityType> {"campfire", TileEntityType::Campfire},
    std::pair<std::string_view, TileEntityType> {"lectern", TileEntityType::Lectern},
    std::pair<std::string_view, TileEntityType> {"chiseled_bookshelf", TileEntityType::ChiseledBookshelf},
    std::pair<std::string_view, TileEntityType> {"beacon", TileEntityType::Beacon},
    std::pair<std::string_view, TileEntityType> {"spawner", TileEntityType::Spawner},
    std::pair<std::string_view, TileEntityType> {"moving_piston", TileEntityType::MovingPiston},
    std::pair<std::string_view, TileEntityType> {"jukebox", TileEntityType::Jukebox},
    std::pair<std::string_view, TileEntityType> {"enchanting_table", TileEntityType::EnchantingTable},
    std::pair<std::string_view, TileEntityType> {"end_portal", TileEntityType::EndPortal},
    std::pair<std::string_view, TileEntityType> {"skull", TileEntityType::Skull},
    std::pair<std::string_view, TileEntityType> {"head", TileEntityType::Skull},
    std::pair<std::string_view, TileEntityType> {"command_block", TileEntityType::CommandBlock},
    std::pair<std::string_view, TileEntityType> {"end_gateway", TileEntityType::EndGateway},
    std::pair<std::string_view, TileEntityType> {"structure_block", TileEntityType::StructureBlock},
    std::pair<std::string_view, TileEntityType> {"jigsaw", TileEntityType::Jigsaw},
    std::pair<std::string_view, TileEntityType> {"daylight_detector", TileEntityType::DaylightDetector},
    std::pair<std::string_view, TileEntityType> {"comparator", TileEntityType::Comparator},
    std::pair<std::string_view, TileEntityType> {"bed", TileEntityType::Bed},
    std::pair<std::string_view, TileEntityType> {"conduit", TileEntityType::Conduit},
    std::pair<std::string_view, TileEntityType> {"bell", TileEntityType::Bell}};

constexpr TileEntityType convertBlockNameToBlockEntityType(const std::string &name)
{
    for (const auto &[tileEntityName, tileEntityType] : tileEntityNamesToTypes) {
        if (name.find(tileEntityName) != std::string::npos) {
            return tileEntityType;
        }
    }
    return TileEntityType::UnknownType;
};

class TileEntity;
}

namespace tile_entity {
std::shared_ptr<tile_entity::TileEntity> createTileEntity(BlockId blockId, Position position);
}

#endif // CUBICSERVER_TILEENTITY_TILEENTITIESLIST_HPP
