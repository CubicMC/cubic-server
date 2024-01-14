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
    inline bool operator==(const std::string &name) const override { return name == _name; }

    // Getters
public:
    inline std::string name() const { return _name; };
    inline int32_t id() const { return _id; };
    inline std::string precipitation() const { return _precipitation; };
    inline float temperature() const { return _temperature; };
    inline float downfall() const { return _downfall; };
    inline Effects effects() const { return _effects; };

    // Setters
public:
    inline BiomeElement &name(const std::string &value);
    inline BiomeElement &id(const int32_t &value);
    inline BiomeElement &precipitation(const std::string &value);
    inline BiomeElement &temperature(const float &value);
    inline BiomeElement &downfall(const float &value);
    inline BiomeElement &effects(const Effects &value);

private:
    std::string _name;
    int32_t _id;
    std::string _precipitation;
    float _temperature;
    float _downfall;
    Effects _effects;
};

DEFINE_REGISTRY_CLASS(Biome, "minecraft:worldgen/biome");

inline void setupDefaultsBiome(Biome &registry);

} // namespace registry

inline registry::BiomeElement &registry::BiomeElement::name(const std::string &value)
{
    this->_name = value;
    return *this;
}

inline registry::BiomeElement &registry::BiomeElement::id(const int32_t &value)
{
    this->_id = value;
    return *this;
}

inline registry::BiomeElement &registry::BiomeElement::precipitation(const std::string &value)
{
    this->_precipitation = value;
    return *this;
}

inline registry::BiomeElement &registry::BiomeElement::temperature(const float &value)
{
    this->_temperature = value;
    return *this;
}

inline registry::BiomeElement &registry::BiomeElement::downfall(const float &value)
{
    this->_downfall = value;
    return *this;
}

inline registry::BiomeElement &registry::BiomeElement::effects(const Effects &value)
{
    this->_effects = value;
    return *this;
}

inline void registry::setupDefaultsBiome(registry::Biome &registry)
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
        .temperature(0)
        .downfall(1)
        .effects({
            .skyColor = 0,
            .waterFogColor = 0,
            .fogColor = 0,
            .waterColor = 0,
        });

    registry.addEntry()
        .name("minecraft:nether_wastes")
        .id(2)
        .precipitation("none")
        .temperature(2.0)
        .downfall(0)
        .effects({
            .skyColor = 0,
            .waterFogColor = 3344392,
            .fogColor = 3344392,
            .waterColor = 4159204,
        });
}

#endif // CUBICSERVER_REGISTRY_BIOME_HPP
