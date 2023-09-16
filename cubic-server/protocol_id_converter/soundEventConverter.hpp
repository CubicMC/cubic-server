#ifndef CUBICSERVER_PROTOCOLIDCONVERTER_SOUNDEVENTCONVERTER_HPP
#define CUBICSERVER_PROTOCOLIDCONVERTER_SOUNDEVENTCONVERTER_HPP

#include <string>
#include <vector>

#include "types.hpp"

namespace SoundEvents {
/**
 * @brief Internal representation of a sound event (only used in the SoundEventConverter class)
 */
struct InternalSoundEvent {
    std::string name;
    SoundEventId protocolId;
};

/**
 * @brief Global palette of sound events used to convert from protocol id to sound event and vice versa
 */
class SoundEventConverter {
public:
    SoundEventConverter() {};
    ~SoundEventConverter() {};

    /**
     * @brief Convert a sound event name to a protocol id
     * @param name The name of the sound event
     * @return SoundEventId The protocol id of the sound event
     */
    SoundEventId fromSoundEventToProtocolId(const std::string &name) const;

    /**
     * @brief Convert a protocol id to a sound event name
     * @param id The protocol id to convert
     * @return std::string The name of the sound event
     */
    std::string fromProtocolIdToSoundEvent(SoundEventId id) const;

    /**
     * @brief Initialize the sound event converter with the sound events from the given json file
     * @param path The path to the json file
     * @return bool True if the initialization was successful, false otherwise
     */
    bool initialize(const std::string &path = "registries.json");

private:
    std::vector<InternalSoundEvent> _soundEvents; // The internal representation of the sound events
};
}

#endif // CUBICSERVER_PROTOCOLIDCONVERTER_SOUNDEVENTCONVERTER_HPP
