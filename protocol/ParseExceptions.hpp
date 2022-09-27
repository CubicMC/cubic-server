#ifndef A6D3BC50_B45B_4A73_A788_6FF612B06A41
#define A6D3BC50_B45B_4A73_A788_6FF612B06A41

#include <stdexcept>

namespace protocol
{

    class VarIntOverflow : public std::runtime_error
    {
    public:
        VarIntOverflow(char const *const message) throw()
            : std::runtime_error(message)
        {
        }
    };

    class PacketEOF : public std::runtime_error
    {
    public:
        PacketEOF(char const *const message) throw()
            : std::runtime_error(message)
        {
        }
    };

    class ZeroLengthString : public std::runtime_error
    {
    public:
        ZeroLengthString(char const *const message) throw()
            : std::runtime_error(message)
        {
        }
    };

}

#endif /* A6D3BC50_B45B_4A73_A788_6FF612B06A41 */
