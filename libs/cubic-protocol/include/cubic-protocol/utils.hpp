#ifndef CUBIC_PROTOCOL_UTILS_
#define CUBIC_PROTOCOL_UTILS_

#define CUBIC_PPARSE(type, target)                                                     \
    parsed = type::parse(data + total_parsed, available_bytes - total_parsed, target); \
    if (parsed == 0)                                                                   \
        return 0;                                                                      \
    total_parsed += parsed

#define CUBIC_PPARSE_RANGE(type, target, min, max)                                               \
    parsed = type::parse(data + total_parsed, available_bytes - total_parsed, target, min, max); \
    if (parsed == 0)                                                                             \
        return 0;                                                                                \
    total_parsed += parsed

#define CUBIC_INIT_BASIC_PACKET_PARSER()         \
    using namespace cubic::protocol::primitives; \
    uint32_t parsed;                             \
    uint32_t total_parsed = 0

#define CUBIC_END_BASIC_PACKET_PARSER() return total_parsed

#endif // CUBIC_PROTOCOL_UTILS_
