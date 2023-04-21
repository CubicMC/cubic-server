#ifndef CUBICSERVER_PLAYERATTRIBUTES_HPP
#define CUBICSERVER_PLAYERATTRIBUTES_HPP

// #include "math/Vector3.hpp"
#include <cstdint>
#include <ostream>

namespace player_attributes {
enum class Gamemode : uint8_t {
    Survival,
    Creative,
    Adventure,
    Spectator,
};
std::ostream &operator<<(std::ostream &os, const Gamemode &gm);

constexpr int32_t MAX_FOOD_LEVEL = 20;
constexpr int32_t MIN_FOOD_LEVEL = 0;
constexpr int32_t MIN_FOOD_LEVEL_FOR_REGENERATION = 18;
constexpr float DEFAULT_FOOD_SATURATION_LEVEL = 5.0f;
constexpr float FOOD_EXHAUSTION_SPRINTING_MULTIPLIER = 0.1f;
constexpr float FOOD_EXHAUSTION_JUMP = 0.05f;
constexpr float FOOD_EXHAUSTION_SPRINTING_JUMP = 0.2f;
constexpr float FOOD_EXHAUSTION_BLOCK_BREAK = 0.025f;
constexpr float FOOD_EXHAUSTION_ATTACK = 0.1f;

// The maximum amount of time (in ticks) that a player can be idle before being kicked.
constexpr uint16_t MAX_TICK_BEFORE_TIMEOUT = 6000;

// constexpr Vector3<double> DEFAULT_SPAWN_POINT = {8.5, 100, 8.5}; // TODO(trompettesib): huntears, please fix this in your pr with constexpr vectors

}

#endif // CUBICSERVER_PLAYERATTRIBUTES_HPP
