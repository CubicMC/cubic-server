#ifndef AE9C1FA0_D3A2_4B7D_962E_4EAF72963603
#define AE9C1FA0_D3A2_4B7D_962E_4EAF72963603

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include <optional>

namespace protocol
{
    struct Handshake
    {
        int32_t prot_version;
        std::string addr;
        uint16_t port;
        int32_t next_state; // TODO: Use an enum here instead of an int32_t
    };

    std::shared_ptr<Handshake> parseHandshake(std::vector<uint8_t> &buffer);
}

#endif /* AE9C1FA0_D3A2_4B7D_962E_4EAF72963603 */
