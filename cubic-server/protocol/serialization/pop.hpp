#ifndef CUBICSERVER_PROTOCOL_SERIALIZATION_POP_HPP
#define CUBICSERVER_PROTOCOL_SERIALIZATION_POP_HPP

#include <cstdint>

#include "popPrimaryType.hpp"
#include "protocol/ServerPackets.hpp"

namespace protocol {
constexpr ChatCommand::ArgumentSignature popArgumentSignature(uint8_t *&at, uint8_t *eof)
{
    ChatCommand::ArgumentSignature argumentSignature;
    argumentSignature.argument = popString(at, eof);
    argumentSignature.signature = popArray<uint8_t, popByte>(at, eof);
    return argumentSignature;
}

constexpr ClickContainer::SlotWithIndex popSlotWithIndex(uint8_t *&at, uint8_t *eof)
{
    ClickContainer::SlotWithIndex slotWithIndex;
    slotWithIndex.slotNumber = popShort(at, eof);
    slotWithIndex.slotData = popSlot(at, eof);
    return slotWithIndex;
}
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_SERIALIZATION_POP_HPP
