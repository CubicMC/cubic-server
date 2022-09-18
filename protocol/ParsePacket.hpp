#ifndef A0501C0F_377F_42C5_9420_0833FCD13CFF
#define A0501C0F_377F_42C5_9420_0833FCD13CFF

#include <optional>
#include <memory>
#include <vector>
#include <functional>

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
}

#endif /* A0501C0F_377F_42C5_9420_0833FCD13CFF */
