#ifndef CUBICSERVER_ENTITIES_ARMORSTATS_HPP
#define CUBICSERVER_ENTITIES_ARMORSTATS_HPP

namespace armor {
enum Type {
    Head = 5,
    Chest = 6,
    Legs = 7,
    Feet = 8
}

struct ArmorPiece {
    Type slot;
    int8_t protectionLevel;
    int8_t toughnessLevel;
};

namespace turtle {

constexpr ArmorPiece helmet = {Head, 2, 0};

} // namespace turtle

namespace leather {

constexpr ArmorPiece helmet = {Head, 1, 0};
constexpr ArmorPiece chestplate = {Chest, 3, 0};
constexpr ArmorPiece leggings = {Legs, 2, 0};
constexpr ArmorPiece boots = {Feet, 1, 0};

} // namespace leather

namespace golden {

constexpr ArmorPiece helmet = {Head, 2, 0};
constexpr ArmorPiece chestplate = {Chest, 5, 0};
constexpr ArmorPiece leggings = {Legs, 3, 0};
constexpr ArmorPiece boots = {Feet, 1, 0};

} // namespace golden

namespace chainmail {

constexpr ArmorPiece helmet = {Head, 2, 0};
constexpr ArmorPiece chestplate = {Chest, 5, 0};
constexpr ArmorPiece leggings = {Legs, 4, 0};
constexpr ArmorPiece boots = {Feet, 1, 0};

} // namespace chainmail

namespace iron {

constexpr ArmorPiece helmet = {Head, 2, 0};
constexpr ArmorPiece chestplate = {Chest, 6, 0};
constexpr ArmorPiece leggings = {Legs, 5, 0};
constexpr ArmorPiece boots = {Feet, 2, 0};

} // namespace iron

namespace diamond {

constexpr ArmorPiece helmet = {Head, 3, 2};
constexpr ArmorPiece chestplate = {Chest, 8, 2};
constexpr ArmorPiece leggings = {Legs, 5, 2};
constexpr ArmorPiece boots = {Feet, 3, 2};

} // namespace diamond

namespace netherite {

constexpr ArmorPiece helmet = {Head, 3, 3};
constexpr ArmorPiece chestplate = {Chest, 8, 3};
constexpr ArmorPiece leggings = {Legs, 5, 3};
constexpr ArmorPiece boots = {Feet, 3, 3};

} // namespace netherite
} // namespace armor

#endif // CUBICSERVER_ENTITIES_ARMORSTATS_HPP
