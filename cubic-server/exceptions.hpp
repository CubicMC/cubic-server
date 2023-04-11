#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

#define DEFINE_EXCEPTION_FROM(name, except) \
    class name : public except \
    { \
    public: \
        name(char const *const message) throw() \
            : except(message) \
        { \
        } \
    }

#define DEFINE_EXCEPTION(name) \
    DEFINE_EXCEPTION_FROM(name, std::runtime_error)

#endif /* EXCEPTIONS_HPP */
