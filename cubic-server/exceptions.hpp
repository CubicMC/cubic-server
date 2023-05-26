#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

#define POPULATE_BASIC_EXCEPTION(name, exception) \
public:                                           \
    name(char const *const message) throw():      \
        exception(message)                        \
    {                                             \
    }                                             \
    name(const std::string &message) throw():     \
        exception(message)                        \
    {                                             \
    }

#define DEFINE_EXCEPTION_FROM(name, exception)    \
    class name : public exception {               \
        POPULATE_BASIC_EXCEPTION(name, exception) \
    }

#define DEFINE_EXCEPTION(name) DEFINE_EXCEPTION_FROM(name, std::runtime_error)

#endif /* EXCEPTIONS_HPP */
