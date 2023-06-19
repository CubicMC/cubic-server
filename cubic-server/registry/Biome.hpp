#ifndef CUBICSERVER_REGISTRY_BIOME_HPP
#define CUBICSERVER_REGISTRY_BIOME_HPP

#include "Registry.hpp"
#include <cstdint>

namespace registry {

class BiomeElement : public Entry {
public:
    struct Effects {
        int32_t skyColor;
        int32_t waterFogColor;
        int32_t fogColor;
        int32_t waterColor;
    };

public:
    BiomeElement() = default;
    ~BiomeElement() = default;

    std::shared_ptr<nbt::Base> toNBT() const override;
    bool operator==(const std::string &) const override;

// Getters
public:
    constexpr std::string name() const { return _name; };
    constexpr int32_t id() const { return _id; };
    constexpr std::string precipitation() const { return _precipitation; };
    constexpr float temperature() const { return _temperature; };
    constexpr float downfall() const { return _downfall; };
    constexpr Effects effects() const { return _effects; };

// Setters
public:
    constexpr BiomeElement &name(const std::string &value);
    constexpr BiomeElement &id(const int32_t &value);
    constexpr BiomeElement &precipitation(const std::string &value);
    constexpr BiomeElement &temperature(const float &value);
    constexpr BiomeElement &downfall(const float &value);
    constexpr BiomeElement &effects(const Effects &value);

private:
    std::string _name;
    int32_t _id;
    std::string _precipitation;
    float _temperature;
    float _downfall;
    Effects _effects;
};

DEFINE_REGISTRY_CLASS(Biome, "minecraft:worldgen/biome");

constexpr void setupDefaultsBiome(Biome &registry);

} // namespace registry

constexpr registry::BiomeElement &registry::BiomeElement::name(const std::string &value)
{
    this->_name = value;
    return *this;
}

constexpr registry::BiomeElement &registry::BiomeElement::id(const int32_t &value)
{
    this->_id = value;
    return *this;
}

constexpr registry::BiomeElement &registry::BiomeElement::precipitation(const std::string &value)
{
    this->_precipitation = value;
    return *this;
}

constexpr registry::BiomeElement &registry::BiomeElement::temperature(const float &value)
{
    this->_temperature = value;
    return *this;
}

constexpr registry::BiomeElement &registry::BiomeElement::downfall(const float &value)
{
    this->_downfall = value;
    return *this;
}

constexpr registry::BiomeElement &registry::BiomeElement::effects(const Effects &value)
{
    this->_effects = value;
    return *this;
}

constexpr void registry::setupDefaultsBiome(registry::Biome &registry)
{
    registry.addEntry()
        .name("minecraft:plains")
        .id(0)
        .precipitation("none")
        .temperature(0.8)
        .downfall(0.4)
        .effects({
            .skyColor = 7907327,
            .waterFogColor = 329011,
            .fogColor = 12638463,
            .waterColor = 4159204,
        });

    registry.addEntry()
        .name("cubsrv:my_super_cool_biome_lol_haha")
        .id(1)
        .precipitation("none")
        .temperature(0.8)
        .downfall(0.4)
        .effects({
            .skyColor = 7907327,
            .waterFogColor = 329011,
            .fogColor = 12638463,
            .waterColor = 4159204,
        });
}

#endif // CUBICSERVER_REGISTRY_BIOME_HPP
