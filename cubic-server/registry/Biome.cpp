#include "Biome.hpp"
#include "nbt.hpp"

std::shared_ptr<nbt::Base> registry::BiomeElement::toNBT() const
{
    // clang-format off
    return NBT_MAKE(nbt::Compound, "", {
        NBT_MAKE(nbt::String, "name", _name),
        NBT_MAKE(nbt::Int, "id", _id),
        NBT_MAKE(nbt::Compound, "element", {
            NBT_MAKE(nbt::String, "precipitation", _precipitation),
            NBT_MAKE(nbt::Float, "temperature", _temperature),
            NBT_MAKE(nbt::Float, "downfall", _downfall),
            NBT_MAKE(nbt::Compound, "effects", {
                NBT_MAKE(nbt::Int, "sky_color", _effects.skyColor),
                NBT_MAKE(nbt::Int, "water_fog_color", _effects.waterFogColor),
                NBT_MAKE(nbt::Int, "fog_color", _effects.fogColor),
                NBT_MAKE(nbt::Int, "water_color", _effects.waterColor),
            })
        }),
    });
    // clang-format on
}
