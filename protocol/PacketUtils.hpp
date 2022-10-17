#ifndef A0501C0F_377F_42C5_9420_0833FCD13CFF
#define A0501C0F_377F_42C5_9420_0833FCD13CFF

#include <optional>
#include <memory>
#include <vector>
#include <functional>
#include <typeSerialization.hpp>

namespace protocol
{

    template <typename H>
    constexpr uint8_t *parse(uint8_t *begin, uint8_t *end, H &out)
    {
        return begin;
    }

    // Thanks a lot to ralismark for helping me with the constexpr parser
    template <typename H, typename F, typename... Args>
    constexpr uint8_t *parse(
        uint8_t *begin,
        uint8_t *end,
        H &out,
        F (*parser)(uint8_t *&begin, uint8_t *end),
        F H::*field,
        Args... args)
    {
        out.*field = parser(begin, end);
        return parse(begin, end, out, args...);
    }

    template <typename H>
    constexpr uint8_t *parseExtra(uint8_t *begin, uint8_t *end, H &out)
    {
        return begin;
    }

    template <typename H, typename F, typename T, typename... Args>
    constexpr uint8_t *parseExtra(
            uint8_t *begin,
            uint8_t *end,
            H &out,
            F (*parser)(const T &data, uint8_t *&begin, uint8_t *end),
            F H::*field,
            const T &data,
            Args... args)
    {
        out.*field = parser(data, begin, end);
        return parseExtra(begin, end, out, args...);
    }

    constexpr void serialize(
        std::vector<uint8_t> &out
    )
    {}

    template <typename H, typename F, typename... Args>
    constexpr void serialize(
        std::vector<uint8_t> &out,
        const H &data,
        F (*serializer)(std::vector<uint8_t> &, const H &),
        Args... args
    )
    {
        serializer(out, data);
        return serialize(out, args...);
    }

    constexpr void finalize(
        std::vector<uint8_t> &out,
        const std::vector<uint8_t> &in,
        int32_t packet_id
    )
    {
        const size_t payload_size = in.size();
        std::vector<uint8_t> encoded_packet_id;
        addVarInt(encoded_packet_id, packet_id);
        addVarInt(out, payload_size + encoded_packet_id.size());
        out.insert(out.end(), encoded_packet_id.begin(), encoded_packet_id.end());
        out.insert(out.end(), in.begin(), in.end());
    }
}

#endif /* A0501C0F_377F_42C5_9420_0833FCD13CFF */
