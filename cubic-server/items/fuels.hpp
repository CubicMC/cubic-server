#ifndef CUBICSERVER_ITEMS_FUELS_HPP
#define CUBICSERVER_ITEMS_FUELS_HPP

#include "types.hpp"
#include <array>
#include <string_view>

namespace Items {

struct FuelItem {
    std::string_view name;
    int burnTime;
};

constexpr std::array<FuelItem, 50> fuels {
    FuelItem {"lava_bucket", 20000},
    FuelItem {"coal_block", 16000},
    FuelItem {"dried_kelp_block", 4000},
    FuelItem {"blaze_rod", 2400},
    FuelItem {"coal", 1600},
    FuelItem {"charcoal", 1600},
    FuelItem {"boat", 1200}, // any boats and chest boats
    FuelItem {"slab", 150}, // any slabs
    FuelItem {"bamboo_mosaic", 300}, // stairs and blocks
    FuelItem {"bee_nest", 300},
    FuelItem {"beehive", 300},
    FuelItem {"bookshelf", 300}, // bookshelf and chiseled bookshelf
    FuelItem {"bamboo_block", 300},
    FuelItem {"log", 300}, // any logs
    FuelItem {"wooden", 200}, // wooden tools
    FuelItem {"wood", 300}, // any woods
    FuelItem {"planks", 300}, // any planks
    FuelItem {"stairs", 300}, // any stairs
    FuelItem {"pressure_plate", 300}, // any pressure plates
    FuelItem {"button", 100}, // any buttons
    FuelItem {"trapdoor", 300}, // any trapdoors
    FuelItem {"fence", 300}, // any fences
    FuelItem {"roots", 300}, // mangrove roots
    FuelItem {"ladder", 300},
    FuelItem {"crafting_table", 300},
    FuelItem {"cartography_table", 300},
    FuelItem {"fletching_table", 300},
    FuelItem {"smithing_table", 300},
    FuelItem {"loom", 300},
    FuelItem {"lectern", 300},
    FuelItem {"composter", 300},
    FuelItem {"chest", 300}, // chest and trapped chest
    FuelItem {"barrel", 300},
    FuelItem {"daylight_detector", 300},
    FuelItem {"jukebox", 300},
    FuelItem {"note_block", 300},
    FuelItem {"banner", 300}, // any banners
    FuelItem {"bowl", 100},
    FuelItem {"bow", 300}, // bow and crossbow
    FuelItem {"fishing_rod", 300},
    FuelItem {"door", 200}, // any doors
    FuelItem {"sign", 200}, // any signs and hanging signs
    FuelItem {"sapling", 100}, // any saplings
    FuelItem {"stick", 100},
    FuelItem {"dead_bush", 100},
    FuelItem {"azalea", 100},
    FuelItem {"wool", 100}, // any wool
    FuelItem {"carpet", 67}, // any carpets
    FuelItem {"bamboo", 50},
    FuelItem {"scaffolding", 50},
};
}

#endif // CUBICSERVER_ITEMS_FUELS_HPP
