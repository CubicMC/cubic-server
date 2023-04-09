#ifndef A6D3BC50_B45B_4A73_A788_6FF612B06A41
#define A6D3BC50_B45B_4A73_A788_6FF612B06A41

#include <stdexcept>

#define DEFINE_EXCEPTION_FROM(name, except)      \
    class name : public except {                 \
    public:                                      \
        name(char const *const message) throw(): \
            except(message)                      \
        {                                        \
        }                                        \
    }

#define DEFINE_EXCEPTION(name) DEFINE_EXCEPTION_FROM(name, std::runtime_error)

namespace protocol {
DEFINE_EXCEPTION(VarIntOverflow);
DEFINE_EXCEPTION(PacketEOF);
DEFINE_EXCEPTION(ZeroLengthString);
DEFINE_EXCEPTION(MaxLengthString);
DEFINE_EXCEPTION(OutOfRangeEnum);
DEFINE_EXCEPTION(OutOfRangeBoolean);
DEFINE_EXCEPTION(WrongObjectType);
}

#endif /* A6D3BC50_B45B_4A73_A788_6FF612B06A41 */
