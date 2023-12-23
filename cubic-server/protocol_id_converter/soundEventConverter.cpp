#include "soundEventConverter.hpp"

#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

#include "logging/logging.hpp"

bool SoundEvents::SoundEventConverter::initialize(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        LERROR("File {} not found !", path);
        return false;
    }
    nlohmann::json file = nlohmann::json::parse(std::ifstream(path));
    for (auto soundEvent : file["minecraft:sound_event"]["entries"].items()) {
        SoundEvents::InternalSoundEvent i;
        i.name = soundEvent.key();
        i.protocolId = soundEvent.value()["protocol_id"];
        this->_soundEvents.push_back(i);
    }
    return true;
}

SoundEventId SoundEvents::SoundEventConverter::fromSoundEventToProtocolId(const std::string &name) const
{
    auto soundEvent = std::find_if(this->_soundEvents.begin(), this->_soundEvents.end(), [&name](const SoundEvents::InternalSoundEvent &i) {
        return i.name == name;
    });
    if (soundEvent == this->_soundEvents.end()) {
        LERROR("Sound event not found in palette (name: {})", name);
        return 0;
    }
    return soundEvent->protocolId;
}

std::string SoundEvents::SoundEventConverter::fromProtocolIdToSoundEvent(SoundEventId id) const
{
    auto soundEvent = std::find_if(this->_soundEvents.begin(), this->_soundEvents.end(), [&id](const SoundEvents::InternalSoundEvent &i) {
        return i.protocolId == id;
    });
    if (soundEvent == this->_soundEvents.end()) {
        LERROR("Sound event not found in palette (id: {})", id);
        return "minecraft:ui.button.click";
    }
    return soundEvent->name;
}
