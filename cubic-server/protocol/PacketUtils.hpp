#ifndef CUBICSERVER_PROTOCOL_PACKETUTILS_HPP
#define CUBICSERVER_PROTOCOL_PACKETUTILS_HPP

#include "Server.hpp"
#include <cstdint>
#include <vector>

#include "protocol/ClientPackets.hpp"
#include "serialization/addPrimaryType.hpp"

namespace protocol {

template<typename H>
constexpr uint8_t *parse(uint8_t *&begin, UNUSED uint8_t *end, UNUSED H &out)
{
    return begin;
}

// Thanks a lot to ralismark for helping me with the constexpr parser
template<typename H, typename F, typename J, typename... Args>
constexpr uint8_t *parse(uint8_t *&begin, uint8_t *end, H &out, F (*parser)(uint8_t *&begin, uint8_t *end), J H::*field, Args... args)
{
    out.*field = (J) parser(begin, end);
    return parse(begin, end, out, args...);
}

constexpr void serialize(UNUSED std::vector<uint8_t> &out) { }

template<typename H, typename F, typename... Args>
constexpr void serialize(std::vector<uint8_t> &out, const H &data, void (*serializer)(std::vector<uint8_t> &, const F &), const Args &...args)
{
    serializer(out, (const F &) data);
    return serialize(out, args...);
}

constexpr void finalize(std::vector<uint8_t> &out, const std::vector<uint8_t> &in, ClientPacketID packetId)
{
    const size_t payloadSize = in.size();
    std::vector<uint8_t> encodedPacketId;
    addVarInt(encodedPacketId, (int32_t) packetId);
    addVarInt(out, payloadSize + encodedPacketId.size());
    out.insert(out.end(), encodedPacketId.begin(), encodedPacketId.end());
    out.insert(out.end(), in.begin(), in.end());
}
}

#endif // CUBICSERVER_PROTOCOL_PACKETUTILS_HPP
