#ifndef CONFIGURATION_ARGUMENT_HOLDER_HPP
#define CONFIGURATION_ARGUMENT_HOLDER_HPP

#include <argparse/argparse.hpp>
#include "details.hpp"

namespace configuration {
namespace _details {

/**
 * @brief Base class for ArgumentHolder, it is used like an interface
 *
 * @tparam T
 */
template<typename T>
class _ArgumentHolder : public _Impl<T&> {
public:
    _ArgumentHolder() = default;
    _ArgumentHolder(T &impl):
        _Impl<T&>(impl) {}

    virtual ~_ArgumentHolder() = default;
    virtual _ArgumentHolder<T> &required() = 0;
    virtual _ArgumentHolder<T> &help(const std::string &help) = 0;
    virtual _ArgumentHolder<T> &implicit() = 0;
};
} // namespace _details

/**
 * @brief Implementation of the ArgumentHolder for the current parser: argparse
 */
class ArgumentHolder : public _details::_ArgumentHolder<argparse::Argument&> {
public:
    ArgumentHolder() = default;
    ArgumentHolder(argparse::Argument &impl):
        _details::_ArgumentHolder<argparse::Argument&>(impl) {}

    virtual ArgumentHolder &required() override;
    virtual ArgumentHolder &help(const std::string &help) override;
    virtual ArgumentHolder &implicit() override;
};
} // namespace configuration

#endif // CONFIGURATION_ARGUMENTS_HOLDER_HPP
