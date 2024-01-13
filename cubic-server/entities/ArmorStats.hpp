#ifndef CUBICSERVER_ENTITIES_ARMORSTATS_HPP
#define CUBICSERVER_ENTITIES_ARMORSTATS_HPP

namespace armor {
enum Type {
    Head = 5,
    Chest = 6,
    Legs = 7,
    Feet = 8
};

struct ArmorPiece {
    Type slot;
    std::string item;
    int8_t protectionLevel;
    int8_t toughnessLevel;
};

namespace turtle {

const ArmorPiece helmet = {Head, "minecraft:turtle_helmet", 2, 0};

} // namespace turtle

namespace leather {

const ArmorPiece helmet = {Head, "minecraft:leather_helmet", 1, 0};
const ArmorPiece chestplate = {Chest, "minecraft:leather_chestplate", 3, 0};
const ArmorPiece leggings = {Legs, "minecraft:leather_leggings", 2, 0};
const ArmorPiece boots = {Feet, "minecraft:leather_boots", 1, 0};

} // namespace leather

namespace golden {

const ArmorPiece helmet = {Head, "minecraft:golden_helmet", 2, 0};
const ArmorPiece chestplate = {Chest, "minecraft:golden_chestplate", 5, 0};
const ArmorPiece leggings = {Legs, "minecraft:golden_leggings", 3, 0};
const ArmorPiece boots = {Feet, "minecraft:golden_boots", 1, 0};

} // namespace golden

namespace chainmail {

const ArmorPiece helmet = {Head, "minecraft:chainmail_helmet", 2, 0};
const ArmorPiece chestplate = {Chest, "minecraft:chainmail_chestplate", 5, 0};
const ArmorPiece leggings = {Legs, "minecraft:chainmail_leggings", 4, 0};
const ArmorPiece boots = {Feet, "minecraft:chainmail_boots", 1, 0};

} // namespace chainmail

namespace iron {

const ArmorPiece helmet = {Head, "minecraft:iron_helmet", 2, 0};
const ArmorPiece chestplate = {Chest, "minecraft:iron_chestplate", 6, 0};
const ArmorPiece leggings = {Legs, "minecraft:iron_leggings", 5, 0};
const ArmorPiece boots = {Feet, "minecraft:iron_boots", 2, 0};

} // namespace iron

namespace diamond {

const ArmorPiece helmet = {Head, "minecraft:diamond_helmet", 3, 2};
const ArmorPiece chestplate = {Chest, "minecraft:diamond_chestplate", 8, 2};
const ArmorPiece leggings = {Legs, "minecraft:diamond_leggings", 6, 2};
const ArmorPiece boots = {Feet, "minecraft:diamond_boots", 3, 2};

} // namespace diamond

namespace netherite {

const ArmorPiece helmet = {Head, "minecraft:netherite_helmet", 3, 3};
const ArmorPiece chestplate = {Chest, "minecraft:netherite_chestplate", 8, 3};
const ArmorPiece leggings = {Legs, "minecraft:netherite_leggings", 6, 3};
const ArmorPiece boots = {Feet, "minecraft:netherite_boots", 3, 3};

} // namespace netherite

const ArmorPiece armors[25] = {
    turtle::helmet,    leather::helmet,       leather::chestplate, leather::leggings,     leather::boots,      golden::helmet,    golden::chestplate,
    golden::leggings,  golden::boots,         chainmail::helmet,   chainmail::chestplate, chainmail::leggings, chainmail::boots,  iron::helmet,
    iron::chestplate,  iron::leggings,        iron::boots,         diamond::helmet,       diamond::chestplate, diamond::leggings, diamond::boots,
    netherite::helmet, netherite::chestplate, netherite::leggings, netherite::boots,
};

} // namespace armor

#endif // CUBICSERVER_ENTITIES_ARMORSTATS_HPP
