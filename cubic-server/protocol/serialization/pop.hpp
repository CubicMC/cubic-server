#ifndef PROTOCOL_SERIALIZATION_POP_HPP
#define PROTOCOL_SERIALIZATION_POP_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "popPrimaryType.hpp"
#include "protocol/ParseExceptions.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/Structures.hpp"
#include "protocol/common.hpp"

namespace protocol {
constexpr Instant popInstantJavaObject(uint8_t *&at, uint8_t *eof)
{
    Instant instant;
    // Java class thingy, don't ask...
    // See the java serialization spec if you like the pain
    // https://docs.oracle.com/javase/8/docs/platform/serialization/spec/protocol.html
    if (eof - at < 35)
        throw PacketEOF("Not enough data in packet to parse an Instant");
    at += 36;
    uint8_t objectIdentifier = popByte(at, eof);
    if (objectIdentifier != 0x02)
        throw WrongObjectType("Wrong object identifier for Instant");
    instant.seconds = popVarLong(at, eof);
    instant.nanos = popVarInt(at, eof);
    return instant;
}

constexpr ArgumentSignature popArgumentSignature(uint8_t *&at, uint8_t *eof)
{
    ArgumentSignature argumentSignature;
    argumentSignature.argument = popString(at, eof);
    argumentSignature.signature = popArray<uint8_t, popByte>(at, eof);
    return argumentSignature;
}

constexpr SlotWithIndex popSlotWithIndex(uint8_t *&at, uint8_t *eof)
{
    SlotWithIndex slotWithIndex;
    slotWithIndex.slot_number = popShort(at, eof);
    slotWithIndex.slot_data = popSlot(at, eof);
    return slotWithIndex;
}
} // namespace protocol

#endif
