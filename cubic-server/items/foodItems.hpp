#ifndef CUBICSERVER_ITEMS_FOODITEMS_HPP
#define CUBICSERVER_ITEMS_FOODITEMS_HPP

#include <array>
#include <string_view>

namespace Items {
struct FoodItem {
    const std::string_view name;
    const int id;
    const int foodValue;
    const float saturation;
    // TODO: Add effects
};
// TODO: Change that to use a json file (https://github.com/PrismarineJS/minecraft-data/blob/master/data/pc/1.19.3/foods.json)
// clang-format off
constexpr std::array<FoodItem, 41> foodItems {
    FoodItem {"Apple", 734, 4, 2.4f},
    FoodItem {"Baked Potato", 1025, 5, 6.0f},
    FoodItem {"Beetroot", 1078, 1, 1.2f},
    FoodItem {"Beetroot Soup", 1080, 6, 7.2f},
    FoodItem {"Bread", 790, 5, 6.0f},
    FoodItem {"Cake slice", -1, 2, 0.4f},
    // FoodItem {"Cake whole", -1, 14, 2.8f},
    FoodItem {"Carrot", 1023, 3, 3.6f},
    FoodItem {"Chorus Fruit", 1076, 4, 2.4f},
    FoodItem {"Cooked Chicken", 923, 6, 7.2f},
    FoodItem {"Cooked Cod", 872, 5, 6.0f},
    FoodItem {"Cooked Mutton", 1058, 6, 9.6f},
    FoodItem {"Cooked Porkchop", 817, 8, 12.8f},
    FoodItem {"Cooked Rabbit", 1045, 5, 6.0f},
    FoodItem {"Cooked Salmon", 873, 6, 9.6f},
    FoodItem {"Cookie", 913, 2, 0.4f},
    FoodItem {"Dried Kelp", 917, 1, 0.6f},
    FoodItem {"Enchanted Golden Apple", 820, 4, 9.6f},
    FoodItem {"Golden Apple", 819, 4, 9.6f},
    FoodItem {"Glow Berries", 1135, 2, 0.4f},
    FoodItem {"Golden Carrot", 1028, 6, 14.4f},
    FoodItem {"Honey Bottle", 1142, 6, 1.2f},
    FoodItem {"Melon Slice", 916, 2, 1.2f},
    FoodItem {"Mushroom Stew", 784, 6, 7.2f},
    FoodItem {"Poisonous Potato", 1026, 2, 1.2f},
    FoodItem {"Potato", 1024, 1, 0.6f},
    FoodItem {"Pufferfish", 871, 1, 0.2f},
    FoodItem {"Pumpkin Pie", 1037, 8, 4.8f},
    FoodItem {"Rabbit Stew", 1046, 10, 12.0f},
    FoodItem {"Raw Beef", 920, 3, 1.8f},
    FoodItem {"Raw Chicken", 922, 2, 1.2f},
    FoodItem {"Raw Cod", 868, 2, 0.4f},
    FoodItem {"Raw Mutton", 1057, 2, 1.2f},
    FoodItem {"Raw Porkchop", 816, 3, 1.8f},
    FoodItem {"Raw Rabbit", 1044, 3, 1.8f},
    FoodItem {"Raw Salmon", 869, 2, 0.4f},
    FoodItem {"Rotten Flesh", 924, 4, 0.8f},
    FoodItem {"Spider Eye", 932, 2, 3.2f},
    FoodItem {"Steak", 921, 8, 12.8f},
    FoodItem {"Suspicious Stew", 1113, 6, 7.2f},
    FoodItem {"Sweet Berries", 1134, 2, 0.4f},
    FoodItem {"Tropical Fish", 870, 1, 0.2f}
};
// clang-format on
}

#endif // CUBICSERVER_ITEMS_FOODITEMS_HPP
