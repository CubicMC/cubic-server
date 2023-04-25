#ifndef CUBICSERVER_PROTOCOL_PARSEEXCEPTIONS_HPP
#define CUBICSERVER_PROTOCOL_PARSEEXCEPTIONS_HPP

#include <stdexcept>

#define DEFINE_EXCEPTION_FROM(name, except)      \
    class name : public except {                 \
    public:                                      \
        name(const char *const message) throw(): \
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

#endif // CUBICSERVER_PROTOCOL_PARSEEXCEPTIONS_HPP
